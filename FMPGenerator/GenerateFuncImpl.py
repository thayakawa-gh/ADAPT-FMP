from Definition import Signature
from Definition import Function1
from Definition import Function2
from Definition import GetFuncList
import itertools
import os.path

def GenerateFuncImpl(out_dir):
    func1, func2, func3, oper1, oper2, oper3, index2, index3 = GetFuncList()
    f = open(os.path.join(out_dir, "FMPFunction.h"), mode = "w")
    f.write(
"#ifndef FMPFUNCTION_H\n\
#define FMPFUNCTION_H\n\
\n\
#include <cmath>\n\
#include <map>\n\
#include <algorithm>\n\
#include <ADAPT/FMP/Detail/FMPExpression.h>\n\
#include <ADAPT/CUF/Macro.h>\n\n\
namespace adapt\n\
{\n\
\n\
namespace agr2\n\
{\n\
\n\
namespace detail\n\
{\n\
\n\
")

    for o in oper1 + func1:
        name = o.GetName()
        for s in o.GetSignatures():
            arg = s.GetArgs()[0]
            res = s.GetResult()
            prc = s.GetProcess()
            cprc = s.GetCProcess()
            up = str(s.GetUpward()).lower()
            down = str(s.GetDownward()).lower()
            if not s.HasBuffer():
                f.write(f"FMP_DEFINE_FUNC1({name}, {arg}, {res}, CUF_TIE_ARGS({prc}), {up}, {down})\n")
            else:
                f.write(f"FMP_DEFINE_FUNC1_WITH_BUFFER({name}, {arg}, {res}, CUF_TIE_ARGS({prc}), CUF_TIE_ARGS({cprc}), {up}, {down})\n")
        #f.write("\n")
        
    for o in oper2 + func2 + index2:
        name = o.GetName()
        for s in o.GetSignatures():
            arg1 = s.GetArgs()[0]
            arg2 = s.GetArgs()[1]
            res = s.GetResult()
            prc = s.GetProcess()
            cprc = s.GetCProcess()
            up = str(s.GetUpward()).lower()
            down = str(s.GetDownward()).lower()
            if not s.HasBuffer():
                f.write(f"FMP_DEFINE_FUNC2({name}, {arg1}, {arg2}, {res}, CUF_TIE_ARGS({prc}), {up}, {down})\n")
            else:
                f.write(f"FMP_DEFINE_FUNC2_WITH_BUFFER({name}, {arg1}, {arg2}, {res}, CUF_TIE_ARGS({prc}), CUF_TIE_ARGS({cprc}), {up}, {down})\n")
                
    for o in oper3 + func3 + index3:
        name = o.GetName()
        for s in o.GetSignatures():
            arg1 = s.GetArgs()[0]
            arg2 = s.GetArgs()[1]
            arg3 = s.GetArgs()[2]
            res = s.GetResult()
            prc = s.GetProcess()
            cprc = s.GetCProcess()
            up = str(s.GetUpward()).lower()
            down = str(s.GetDownward()).lower()
            if not s.HasBuffer():
                f.write(f"FMP_DEFINE_FUNC3({name}, {arg1}, {arg2}, {arg3}, {res}, CUF_TIE_ARGS({prc}), {up}, {down})\n")
            else:
                f.write(f"FMP_DEFINE_FUNC3_WITH_BUFFER({name}, {arg1}, {arg2}, {arg3}, {res}, CUF_TIE_ARGS({prc}), CUF_TIE_ARGS({cprc}), {up}, {down})\n")

    f.write("std::map<std::string, size_t> gFuncNames = {\n")
    funcnames = ",\n".join([ f"{{ \"{o.GetName()}\", {o.GetIndex()} }}" for o in func1 + func2 + func3 ])
    f.write(funcnames)
    f.write("\n};\n")


    f.write("\n}\n\n}\n\n}\n\n#endif\n")