import os
import subprocess
from Definition import Signature
from Definition import Function1
from Definition import Function2
from Definition import GetFuncList
from Definition import GetModifiers
from Definition import GetTypes
import os.path

def GenerateLemonCode(out_dir):
    f = open(os.path.join(out_dir, "FMPLemon_parser.y"), mode="w")
    f.write("%token_prefix FMP_TOKEN_\n\n"
            "%left AND OR.\n"
            "%left EQ NEQ.\n"
            "%left GT GEQ LT LEQ.\n"
            "%left ADD SUB.\n"
            "%left MUL DIV MOD.\n"
            "%left POW.\n"
            "%right NOT.\n"
            "%nonassoc BRA KET.\n"
            "\n")
    f.write("%token_type { Trivializer<NodeValue> }\n"
            "%type constant_node { Trivializer<TerminalNode> }\n"
            "%type variable_node { Trivializer<TerminalNode> }\n"
            "%type function_node { Trivializer<FunctionNode> }\n\n"
            "%destructor constant_node { $$.Destroy(); }\n\n"
            "%destructor variable_node { $$.Destroy(); }\n\n"
            "%destructor function_node { $$.Destroy(); }\n\n")

    nodetype = [ "constant_node", "variable_node", "function_node" ]

    #3引数関数まで含めるとややこしくなるから省こう。

    f.write(
        "%extra_argument { ParserState *state }\n\n"
        "%include {\n"
        "#include <iostream>\n"
        "#include <array>\n"
        "#include <ADAPT/CUF/Trivializer.h>\n"
        "#include \"FMPExpression.h\"\n"
        "#include \"FMPNode_func.h\"\n"
        "BEGIN_LEMON_NAMESPACE\n"
        "}\n"
        "%code { END_LEMON_NAMESPACE }\n"
        "%syntax_error {\n"
        "	fprintf(stderr, \"Syntax error\");\n"
        "}\n"
        "%parse_failure {\n"
        "	fprintf(stderr,\"Giving up.  Parser is hopelessly lost...\");\n"
        "}\n"
        "%start_symbol equation\n\n")

    f.write(
        "equation ::= constant_node(A). { try { state->mRootNode = A->Juncturize(state); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }\n"
        "equation ::= variable_node(A). { try { state->mRootNode = A->Juncturize(state); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }\n"
        "equation ::= function_node(A). { try { if (!A->IsJuncture()) A->Juncturize(state); state->mRootNode = A->GetJunctureNode(); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }\n\n")


    #terminal nodeの動作
    f.write(
        "constant_node(A) ::= INT(B).    { try { A.Construct(B->GetInt()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }\n"
        "constant_node(A) ::= FLT(B).    { try { A.Construct(B->GetFlt()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }\n"
        "constant_node(A) ::= STR(B).    { try { A.Construct(B->GetStr()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }\n"
        "constant_node(A) ::= VEC(B).    { try { A.Construct(B->GetVec()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }\n"
        "constant_node(A) ::= MAT(B).    { try { A.Construct(B->GetMat()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }\n"
        "variable_node(A) ::= INTARG(B). { try { A.Construct(B->GetIntPtr()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }\n"
        "variable_node(A) ::= FLTARG(B). { try { A.Construct(B->GetFltPtr()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }\n"
        "variable_node(A) ::= STRARG(B). { try { A.Construct(B->GetStrPtr()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }\n"
        "variable_node(A) ::= VECARG(B). { try { A.Construct(B->GetVecPtr()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }\n"
        "variable_node(A) ::= MATARG(B). { try { A.Construct(B->GetMatPtr()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }\n"
        "\n")
    
    func1, func2, func3, oper1, oper2, oper3, index2, index3 = GetFuncList()

    #1引数演算子の動作
    #現在の1引数演算子は、いずれも優先度が等しいので、全て[NOT]のルールを適用する。
    for o in oper1:
        n = o.GetName()
        for ix, x in enumerate(nodetype):
            #unode = unified_type1[ix]
            unode = "function_node"
            if x == "constant_node":
                unode = "constant_node"
            if unode == "constant_node":
                f.write(f"{unode:<20}(A) ::= {n.upper():<3} {x:<13}(B). [NOT] {{ try {{ A.Construct(MakeConstantNode(state, {o.GetIndex()}, *B)); }} catch (const Exception& e) {{ state->Error(e.GetErrorMessage()); }} }}\n")
            else:
                f.write(f"{unode:<20}(A) ::= {n.upper():<3} {x:<13}(B). [NOT] {{ try {{ A.Construct(MakeFunctionNode(state, {o.GetIndex()}, *B));  }} catch (const Exception& e) {{ state->Error(e.GetErrorMessage()); }} }}\n")
    f.write("\n")

    #2引数演算子の動作
    for o in oper2:
        n = o.GetName()
        for ix, x in enumerate(nodetype):
            for iy, y in enumerate(nodetype):
                unode = "function_node"
                if x == "constant_node" and y == "constant_node":
                    unode = "constant_node"
                if unode == "constant_node":
                    f.write(f"{unode:<13}(A) ::= {x:<13}(B) {n.upper():<3} {y:<13}(C). {{ try {{ A.Construct(MakeConstantNode(state, {o.GetIndex()}, *B, *C)); }} catch (const Exception& e) {{ state->Error(e.GetErrorMessage()); }} }}\n")
                else:
                    f.write(f"{unode:<13}(A) ::= {x:<13}(B) {n.upper():<3} {y:<13}(C). {{ try {{ A.Construct(MakeFunctionNode(state, {o.GetIndex()}, *B, *C)); }} catch (const Exception& e) {{ state->Error(e.GetErrorMessage()); }} }}\n")
        f.write("\n")
        
    for x in nodetype:
        f.write(f"{x:<20}(A) ::= LPAR {x:<13}(B) RPAR. {{ A.Construct(*B); }}\n")

    f.write("\n")

    #1引数関数の動作
    for x in range(len(nodetype)):
        unode = "function_node"
        if x == "constant_node":
            unode = "constant_node"
        if unode == "constant_node":
            f.write(f"{unode:<20}(A) ::= FUNC(B) LPAR {nodetype[x]:<13}(C) RPAR. {{ try {{ A.Construct(MakeConstantNode(state, B->GetInt(), *C)); }} catch (const Exception& e) {{ state->Error(e.GetErrorMessage()); }} }}\n")
        else:
            f.write(f"{unode:<20}(A) ::= FUNC(B) LPAR {nodetype[x]:<13}(C) RPAR. {{ try {{ A.Construct(MakeFunctionNode(state, B->GetInt(), *C)); }} catch (const Exception& e) {{ state->Error(e.GetErrorMessage()); }} }}\n")
    f.write("\n")

    #2引数関数の動作
    for ix, x in enumerate(nodetype):
        for iy, y in enumerate(nodetype):
            unode = "function_node"
            if x == "constant_node" and y == "constant_node":
                unode = "constant_node"
            if unode == "constant_node":
                f.write(f"{unode:<13}(A) ::= FUNC(B) LPAR {x:<13}(C) COM {y:<13}(D) RPAR. {{ try {{ A.Construct(MakeConstantNode(state, B->GetInt(), *C, *D)); }} catch (const Exception& e) {{ state->Error(e.GetErrorMessage()); }} }}\n")
            else:
                f.write(f"{unode:<13}(A) ::= FUNC(B) LPAR {x:<13}(C) COM {y:<13}(D) RPAR. {{ try {{ A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D)); }} catch (const Exception& e) {{ state->Error(e.GetErrorMessage()); }} }}\n")
    f.write("\n")

    #3引数関数の動作
    for ix, x in enumerate(nodetype):
        for iy, y in enumerate(nodetype):
            for iz, z in enumerate(nodetype):
                unode = "function_node"
                if x == "constant_node" and y == "constant_node" and z == "constant_node":
                    unode = "constant_node"
                if unode == "constant_node":
                    f.write(f"{unode:<13}(A) ::= FUNC(B) LPAR {x:<13}(C) COM {y:<13}(D) COM {z:<13}(E) RPAR. {{ try {{ A.Construct(MakeConstantNode(state, B->GetInt(), *C, *D, *E)); }} catch (const Exception& e) {{ state->Error(e.GetErrorMessage()); }} }}\n")
                else:
                    f.write(f"{unode:<13}(A) ::= FUNC(B) LPAR {x:<13}(C) COM {y:<13}(D) COM {z:<13}(E) RPAR. {{ try {{ A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); }} catch (const Exception& e) {{ state->Error(e.GetErrorMessage()); }} }}\n")
    f.write("\n")

    #添字演算子の動作
    for ix, x in enumerate(nodetype):
        for iy, y in enumerate(nodetype):
            #vec[index]という記述はterminal nodeに対してのみ許す。function nodeには(vec)[index]のように括弧を付与しなければならない。
            #o = oper2[oper2.index("index")]
            o = index2[0]
            unode = "function_node"
            if x == "constant_node" and y == "constant_node":
                unode = "constant_node"
            if unode == "constant_node":
                f.write(f"{unode:<13}(A) ::= {x:<13}(B) BRA {y:<13}(C) KET. {{ try {{ A.Construct(MakeConstantNode(state, {o.GetIndex()}, *B, *C)); }} catch (const Exception& e) {{ state->Error(e.GetErrorMessage()); }} }}\n")
            else:
                f.write(f"{unode:<13}(A) ::= {x:<13}(B) BRA {y:<13}(C) KET. {{ try {{ A.Construct(MakeFunctionNode(state, {o.GetIndex()}, *B, *C)); }} catch (const Exception& e) {{ state->Error(e.GetErrorMessage()); }} }}\n")
    f.write("\n")
    
    #2引数添字演算子の動作
    #現在はMatrixのみが対応する。
    for ix, x in enumerate(nodetype):
        for iy, y in enumerate(nodetype):
            for iz, z in enumerate(nodetype):
                o = index3[0]
                unode = "function_node"
                if x == "constant_node" and y == "constant_node" and z == "constant_node":
                    unode = "constant_node"
                if unode == "constant_node":
                    f.write(f"{unode:<13}(A) ::= {x:<13}(B) BRA {y:<13}(C) COM {z:<13}(D) KET. {{ try {{ A.Construct(MakeConstantNode(state, {o.GetIndex()}, *B, *C, *D)); }} catch (const Exception& e) {{ state->Error(e.GetErrorMessage()); }} }}\n")
                else:
                    f.write(f"{unode:<13}(A) ::= {x:<13}(B) BRA {y:<13}(C) COM {z:<13}(D) KET. {{ try {{ A.Construct(MakeFunctionNode(state, {o.GetIndex()}, *B, *C, *D)); }} catch (const Exception& e) {{ state->Error(e.GetErrorMessage()); }} }}\n")
    f.write("\n")

    f.close()
