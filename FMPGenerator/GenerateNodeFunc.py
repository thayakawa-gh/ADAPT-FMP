from Definition import Signature
from Definition import Function1
from Definition import Function2
from Definition import GetFuncList
from Definition import GetModifiers
from Definition import GetNodes
from Definition import GetTypes
import itertools
import os.path

def GenerateNodeFunc(out_dir):
    func1, func2, func3, oper1, oper2, oper3, index2, index3 = GetFuncList()

    mod = GetModifiers()
    types = GetTypes()

    promod = list(itertools.product(mod, mod))

    file = open(os.path.join(out_dir, "FMPNode_func.h"), mode="w")
    file.write("#ifndef FMPNODE_FUNC_H\n"\
               "#define FMPNODE_FUNC_H\n\n"\
               "#include <ADAPT/FMP/Detail/FMPNode_base.h>\n\n"\
               "namespace adapt\n"\
               "{\n\n"\
               "namespace fmp\n"\
               "{\n\n"
               "namespace detail\n"\
               "{\n\n")

    for m in mod + promod:
        modstr = m[0] if isinstance(m, str) else "".join([ str(x[0]) for x in m ])
        file.write("template <class Func, class ResType = typename Func::RetType>\n"\
                    f"struct FMPMakeExpression{modstr};\n"\
                    "\n")
        for res in types:
            #if modstr == "C" or modstr == "CC":
            #    continue
        
            file.write("template <class Func>\n"\
                       f"struct FMPMakeExpression{modstr}<Func, {res}Type> : public FMPMakeExpressionBase\n"
                       "{\n")
            if isinstance(m, str):
                file.write(f"    FMPMakeExpression{modstr}(const {m}Node& n) : mUpArg(n) {{}}\n")
            else:
                file.write(f"    FMPMakeExpression{modstr}(const {m[0]}Node& n1, const {m[1]}Node& n2) : mUpArg1(n1), mUpArg2(n2) {{}}\n")
                
            file.write("    virtual NumericalType GetType() const override { return Func::RetType::label; }\n")
            #まず1引数関数を連結する場合。
            file.write(f"    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override\n"
                        "    {\n"
                        "        (void)state, (void)func, (void)a; ")
            i = 0
            code = str()
            for o in func1 + oper1:
                ctmp = str()
                name = o.GetName()
                ctmp += f"        case {o.GetIndex()}:\n"
                count = 0
                for s in o.GetSignatures():
                    args = s.GetArgs()
                    argsstr = "".join(args)
                    arg = str()
                    if isinstance(m, str):
                        arg = "std::make_tuple(mUpArg.GetIndex(state))"
                    else:
                        arg = "std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state))"
                    if len(args) != 1:
                        continue
                    if s.GetUpward() == False:
                        continue
                    if args[0] != res:
                        continue
                    ctmp += f"            if (a.GetType() == VALUE_{str(args[0]).upper()})\n"
                    ctmp += f"                return MakeExpression<FMPExpressionFNode, {name}{argsstr}, FMPExpression{modstr}Node_impl<Func>>(state, {arg});\n"
                    count += 1
                i += 1
                if count == 0:
                    continue
                code += ctmp
                code += "            break;\n"
            if code:
                file.write("        switch (func)\n"\
                           "        {\n")
                file.write(code)
                file.write("        }\n")
            file.write("        throw InvalidType(\"\");\n")
            file.write("    }\n")

            #2引数関数に連結する場合。
            downmod = [ (m, f) for m, f in zip(mod, ["Function", "Function", "Function"]) ] + [ (f, m) for f, m in zip(["Function", "Function", "Function"], mod) ]
            for mf1, mf2 in downmod:
                arg1 = "a.GetIndex(state)"
                arg2 = "b.GetIndex(state)"
                if mf1 == "Function":
                    if isinstance(m, str):
                        arg1 = "std::make_tuple(mUpArg.GetIndex(state))"
                    else:
                        arg1 = "std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state))"
                elif mf2 == "Function":
                    if isinstance(m, str):
                        arg2 = "std::make_tuple(mUpArg.GetIndex(state))"
                    else:
                        arg2 = "std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state))"
                file.write(f"    virtual JunctureNode MakeFunc(ParserState* state, size_t func, {mf1}Node& a, {mf2}Node& b) override\n"
                        "    {\n"
                        "        (void)state, (void)func, (void)a, (void)b; ")
                
                code = str()
                for o in func2 + oper2 + index2:
                    ctmp = str()
                    name = o.GetName()
                    ctmp += f"        case {o.GetIndex()}:\n"
                    count = 0
                    for s in o.GetSignatures():
                        args = s.GetArgs()
                        argsstr = "".join(args)
                        cmpr = str()
                        if mf1[0] == "F":
                            cmpr = args[0]
                        elif mf2[0] == "F":
                            cmpr = args[1]
                        else:
                            print("ERROR")
                        if len(args) != 2:
                            continue
                        if s.GetUpward() == False:
                            continue
                        if cmpr != res:
                            continue
                        ctmp += f"            if (a.GetType() == VALUE_{str(args[0]).upper()} && b.GetType() == VALUE_{str(args[1]).upper()})\n"
                        ctmp += f"                return MakeExpression<FMPExpression{mf1[0]}{mf2[0]}Node, {name}{argsstr}, FMPExpression{modstr}Node_impl<Func>>(state, {arg1}, {arg2});\n"
                        count += 1
                    if count == 0:
                        continue
                    code += ctmp
                    code += "            break;\n"
                if code:
                    file.write("        switch (func)\n"\
                               "        {\n")
                    file.write(code)
                    file.write("        }\n")
                file.write("        throw InvalidType(\"\");\n    }\n")

            #3引数関数は連結しない。動作が複雑になりすぎるので。

            junargs = str()
            if isinstance(m, str):
                junargs = "mUpArg.GetIndex(state)"
            else:
                junargs = "mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)"
            file.write(f"    JunctureNode Juncturize(ParserState* state)\n    {{\n")
            file.write(f"        using ExpressionNode = FMPExpression{modstr}Node<Func>;\n")
            file.write(f"        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpression{modstr}Node<Func>>(state, {junargs}));\n    }}\n")

            if isinstance(m, str):
                file.write(f"    {m}Node mUpArg;\n")
            else:
                file.write(f"    {m[0]}Node mUpArg1;\n    {m[1]}Node mUpArg2;\n")
            file.write("};\n")


    nod = GetNodes()
    pronod = list(itertools.product(nod, nod))
    pronod3 = list(itertools.product(nod, nod, nod))
    for m in nod:
        if m == "TerminalNode":
            continue
        file.write(f"inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, {m}Node& n)\n"
                   f"{{\n"
                   "    switch (func)\n"
                   "    {\n")
        for o in func1 + oper1:
            name = o.GetName()
            file.write(f"    case {o.GetIndex()}:\n")
            for s in o.GetSignatures():
                args = s.GetArgs()
                argsstr = "".join(args)
                file.write(f"        if (n.GetType() == VALUE_{args[0].upper()})\n"
                           f"            return FunctionNode(Identity<{name}{argsstr}>(), func, std::bool_constant<{name}{argsstr}::Upward>(), std::bool_constant<{name}{argsstr}::Downward>(), state, n);\n")
            file.write(f"        break;\n")
        file.write(f"    }}\n    throw InvalidType(\"\");\n}}\n")

    for m1, m2 in pronod:
        if m1 == "TerminalNode" and m2 == "TerminalNode":
            continue
        file.write(f"inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, {m1}Node& n1, {m2}Node& n2)\n"
                   f"{{\n"
                   "    switch (func)\n"
                   "    {\n")
        for o in func2 + oper2 + index2:
            name = o.GetName()
            file.write(f"    case {o.GetIndex()}:\n")
            for s in o.GetSignatures():
                args = s.GetArgs()
                argsstr = "".join(args)
                file.write(f"        if (n1.GetType() == VALUE_{args[0].upper()} && n2.GetType() == VALUE_{args[1].upper()})\n"
                           f"            return FunctionNode(Identity<{name}{argsstr}>(), func, std::bool_constant<{name}{argsstr}::Upward>(), std::bool_constant<{name}{argsstr}::Downward>(), state, n1, n2);\n")
            file.write(f"        break;\n")
        file.write(f"    }}\n    throw InvalidType(\"\");\n}}\n")
        
    for m1, m2, m3 in pronod3:
        if m1 == "TerminalNode" and m2 == "TerminalNode" and m3 == "TerminalNode":
            continue
        file.write(f"inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, {m1}Node& n1, {m2}Node& n2, {m3}Node& n3)\n"
                   f"{{\n"
                   "    switch (func)\n"
                   "    {\n")
        for o in func3 + oper3 + index3:
            name = o.GetName()
            file.write(f"    case {o.GetIndex()}:\n")
            for s in o.GetSignatures():
                args = s.GetArgs()
                argsstr = "".join(args)
                file.write(f"        if (n1.GetType() == VALUE_{args[0].upper()} && n2.GetType() == VALUE_{args[1].upper()} && n3.GetType() == VALUE_{args[2].upper()})\n"
                           f"            return FunctionNode(Identity<{name}{argsstr}>(), func, std::bool_constant<{name}{argsstr}::Upward>(), std::bool_constant<{name}{argsstr}::Downward>(), state, n1, n2, n3);\n")
            file.write(f"        break;\n")
        file.write(f"    }}\n    throw InvalidType(\"\");\n}}\n")
    
    file.write(f"inline TerminalNode MakeConstantNode(ParserState*, size_t func, TerminalNode& t)\n"
               "{\n"
               "    switch (func)\n"
               "    {\n")
    for o in func1 + oper1:
        name = o.GetName()
        file.write(f"    case {o.GetIndex()}:\n")
        for s in o.GetSignatures():
            args = s.GetArgs()
            argsstr = "".join(args)
            res = s.GetResult()
            file.write(f"        if (t.GetType() == VALUE_{args[0].upper()})\n"
                       f"            return TerminalNode({name}{argsstr}::process_when_compile(t.Get{args[0]}()));\n")
    file.write("    }\n")
    file.write("    throw InvalidType(\"\");\n")
    file.write("}\n")
    
    file.write(f"inline TerminalNode MakeConstantNode(ParserState*, size_t func, TerminalNode& t1, TerminalNode& t2)\n"
               "{\n"
               "    switch (func)\n"
               "    {\n")
    for o in func2 + oper2 + index2:
        name = o.GetName()
        file.write(f"    case {o.GetIndex()}:\n")
        for s in o.GetSignatures():
            args = s.GetArgs()
            argsstr = "".join(args)
            res = s.GetResult()
            file.write(f"        if (t1.GetType() == VALUE_{args[0].upper()} && t2.GetType() == VALUE_{args[1].upper()})\n"
                       f"            return TerminalNode({name}{argsstr}::process_when_compile(t1.Get{args[0]}(), t2.Get{args[1]}()));\n")
    file.write("    }\n")
    file.write("    throw InvalidType(\"\");\n")
    file.write("}\n")
    
    file.write(f"inline TerminalNode MakeConstantNode(ParserState*, size_t func, TerminalNode& t1, TerminalNode& t2, TerminalNode& t3)\n"
               "{\n"
               "    switch (func)\n"
               "    {\n")
    for o in func3 + oper3 + index3:
        name = o.GetName()
        file.write(f"    case {o.GetIndex()}:\n")
        for s in o.GetSignatures():
            args = s.GetArgs()
            argsstr = "".join(args)
            res = s.GetResult()
            file.write(f"        if (t1.GetType() == VALUE_{args[0].upper()} && t2.GetType() == VALUE_{args[1].upper()} && t3.GetType() == VALUE_{args[2].upper()})\n"
                       f"            return TerminalNode({name}{argsstr}::process_when_compile(t1.Get{args[0]}(), t2.Get{args[1]}(), t3.Get{args[2]}()));\n")
    file.write("    }\n")
    file.write("    throw InvalidType(\"\");\n")
    file.write("}\n")

    file.write("\n}\n\n}\n\n}\n\n#endif\n")