#ifndef FMPFUNCTION_H
#define FMPFUNCTION_H

#include <cmath>
#include <map>
#include <algorithm>
#include <ADAPT/FMP/Detail/FMPExpression.h>
#include <ADAPT/CUF/Macro.h>

namespace adapt
{

namespace fmp
{

namespace detail
{

FMP_DEFINE_FUNC1(sub, Int, Int, CUF_TIE_ARGS(return -a;), true, true)
FMP_DEFINE_FUNC1(sub, Flt, Flt, CUF_TIE_ARGS(return -a;), true, true)
FMP_DEFINE_FUNC1_WITH_BUFFER(sub, Vec, Vec, CUF_TIE_ARGS(*mBuffer = a; *mBuffer *= -1; return *mBuffer;), CUF_TIE_ARGS(return a *= -1;), false, false)
FMP_DEFINE_FUNC1_WITH_BUFFER(sub, Mat, Mat, CUF_TIE_ARGS(*mBuffer = a; *mBuffer *= -1; return *mBuffer;), CUF_TIE_ARGS(return a *= -1;), false, false)
FMP_DEFINE_FUNC1(sin, Int, Flt, CUF_TIE_ARGS(return std::sin(a)), true, true)
FMP_DEFINE_FUNC1(sin, Flt, Flt, CUF_TIE_ARGS(return std::sin(a)), true, true)
FMP_DEFINE_FUNC1(cos, Int, Flt, CUF_TIE_ARGS(return std::cos(a)), true, true)
FMP_DEFINE_FUNC1(cos, Flt, Flt, CUF_TIE_ARGS(return std::cos(a)), true, true)
FMP_DEFINE_FUNC1(tan, Int, Flt, CUF_TIE_ARGS(return std::tan(a)), true, true)
FMP_DEFINE_FUNC1(tan, Flt, Flt, CUF_TIE_ARGS(return std::tan(a)), true, true)
FMP_DEFINE_FUNC1(asin, Int, Flt, CUF_TIE_ARGS(return std::asin(a)), false, false)
FMP_DEFINE_FUNC1(asin, Flt, Flt, CUF_TIE_ARGS(return std::asin(a)), false, false)
FMP_DEFINE_FUNC1(acos, Int, Flt, CUF_TIE_ARGS(return std::acos(a)), false, false)
FMP_DEFINE_FUNC1(acos, Flt, Flt, CUF_TIE_ARGS(return std::acos(a)), false, false)
FMP_DEFINE_FUNC1(atan, Int, Flt, CUF_TIE_ARGS(return std::atan(a)), false, false)
FMP_DEFINE_FUNC1(atan, Flt, Flt, CUF_TIE_ARGS(return std::atan(a)), false, false)
FMP_DEFINE_FUNC1(ln, Int, Flt, CUF_TIE_ARGS(return std::log(a)), false, false)
FMP_DEFINE_FUNC1(ln, Flt, Flt, CUF_TIE_ARGS(return std::log(a)), false, false)
FMP_DEFINE_FUNC1(log10, Int, Flt, CUF_TIE_ARGS(return std::log10(a)), false, false)
FMP_DEFINE_FUNC1(log10, Flt, Flt, CUF_TIE_ARGS(return std::log10(a)), false, false)
FMP_DEFINE_FUNC1(exp, Int, Flt, CUF_TIE_ARGS(return std::exp(a)), false, false)
FMP_DEFINE_FUNC1(exp, Flt, Flt, CUF_TIE_ARGS(return std::exp(a)), false, false)
FMP_DEFINE_FUNC1(square, Int, Int, CUF_TIE_ARGS(return a * a), true, true)
FMP_DEFINE_FUNC1(square, Flt, Flt, CUF_TIE_ARGS(return a * a), true, true)
FMP_DEFINE_FUNC1(cube, Int, Int, CUF_TIE_ARGS(return a * a * a), true, true)
FMP_DEFINE_FUNC1(cube, Flt, Flt, CUF_TIE_ARGS(return a * a * a), true, true)
FMP_DEFINE_FUNC1(sqrt, Int, Flt, CUF_TIE_ARGS(return std::sqrt(a)), false, false)
FMP_DEFINE_FUNC1(sqrt, Flt, Flt, CUF_TIE_ARGS(return std::sqrt(a)), false, false)
FMP_DEFINE_FUNC1(cbrt, Int, Flt, CUF_TIE_ARGS(return std::cbrt(a)), false, false)
FMP_DEFINE_FUNC1(cbrt, Flt, Flt, CUF_TIE_ARGS(return std::cbrt(a)), false, false)
FMP_DEFINE_FUNC1(ceil, Int, Int, CUF_TIE_ARGS(return (int64_t)std::ceil(a)), true, true)
FMP_DEFINE_FUNC1(ceil, Flt, Int, CUF_TIE_ARGS(return (int64_t)std::ceil(a)), true, true)
FMP_DEFINE_FUNC1(floor, Int, Int, CUF_TIE_ARGS(return (int64_t)std::floor(a)), true, true)
FMP_DEFINE_FUNC1(floor, Flt, Int, CUF_TIE_ARGS(return (int64_t)std::floor(a)), true, true)
FMP_DEFINE_FUNC1(int, Int, Int, CUF_TIE_ARGS(return (int64_t)a), true, true)
FMP_DEFINE_FUNC1(int, Flt, Int, CUF_TIE_ARGS(return (int64_t)a), true, true)
FMP_DEFINE_FUNC1(float, Int, Flt, CUF_TIE_ARGS(return (double)a), true, true)
FMP_DEFINE_FUNC1(float, Flt, Flt, CUF_TIE_ARGS(return (double)a), true, true)
FMP_DEFINE_FUNC1(abs, Int, Int, CUF_TIE_ARGS(return a < 0 ? -a : a), true, true)
FMP_DEFINE_FUNC1(abs, Flt, Flt, CUF_TIE_ARGS(return std::abs(a)), true, true)
FMP_DEFINE_FUNC1(len, Str, Int, CUF_TIE_ARGS(return a.GetSize()), false, false)
FMP_DEFINE_FUNC1(len, Vec, Int, CUF_TIE_ARGS(return a.GetSize(0)), false, false)
FMP_DEFINE_FUNC1_WITH_BUFFER(transpose, Mat, Mat, CUF_TIE_ARGS(Transpose(*mBuffer, a); return *mBuffer;), CUF_TIE_ARGS(return Transpose(a);), false, false)
FMP_DEFINE_FUNC2(pow, Int, Int, Int, CUF_TIE_ARGS(return fast_pow(a, b)), true, true)
FMP_DEFINE_FUNC2(pow, Int, Flt, Flt, CUF_TIE_ARGS(return std::pow(a, b)), false, false)
FMP_DEFINE_FUNC2(pow, Flt, Int, Flt, CUF_TIE_ARGS(return fast_pow(a, b)), true, true)
FMP_DEFINE_FUNC2(pow, Flt, Flt, Flt, CUF_TIE_ARGS(return std::pow(a, b)), false, false)
FMP_DEFINE_FUNC2(mul, Int, Int, Int, CUF_TIE_ARGS(return a * b), true, true)
FMP_DEFINE_FUNC2(mul, Int, Flt, Flt, CUF_TIE_ARGS(return a * b), true, true)
FMP_DEFINE_FUNC2(mul, Flt, Int, Flt, CUF_TIE_ARGS(return a * b), true, true)
FMP_DEFINE_FUNC2(mul, Flt, Flt, Flt, CUF_TIE_ARGS(return a * b), true, true)
FMP_DEFINE_FUNC2_WITH_BUFFER(mul, Vec, Flt, Vec, CUF_TIE_ARGS(*mBuffer = a; *mBuffer *= b; return *mBuffer), CUF_TIE_ARGS(return a * b), false, false)
FMP_DEFINE_FUNC2_WITH_BUFFER(mul, Flt, Vec, Vec, CUF_TIE_ARGS(*mBuffer = b; *mBuffer *= a; return *mBuffer), CUF_TIE_ARGS(return a * b), false, false)
FMP_DEFINE_FUNC2_WITH_BUFFER(mul, Mat, Flt, Mat, CUF_TIE_ARGS(*mBuffer = a; *mBuffer *= b; return *mBuffer), CUF_TIE_ARGS(return a * b), false, false)
FMP_DEFINE_FUNC2_WITH_BUFFER(mul, Flt, Mat, Mat, CUF_TIE_ARGS(*mBuffer = b; *mBuffer *= a; return *mBuffer), CUF_TIE_ARGS(return a * b), false, false)
FMP_DEFINE_FUNC2_WITH_BUFFER(mul, Mat, Mat, Mat, CUF_TIE_ARGS(Multiply(*mBuffer, a, b); return *mBuffer), CUF_TIE_ARGS(return a * b), false, false)
FMP_DEFINE_FUNC2_WITH_BUFFER(mul, Mat, Vec, Vec, CUF_TIE_ARGS(Multiply(*mBuffer, a, b); return *mBuffer), CUF_TIE_ARGS(return a * b), false, false)
FMP_DEFINE_FUNC2(div, Int, Int, Int, CUF_TIE_ARGS(return a / b), true, true)
FMP_DEFINE_FUNC2(div, Int, Flt, Flt, CUF_TIE_ARGS(return a / b), true, true)
FMP_DEFINE_FUNC2(div, Flt, Int, Flt, CUF_TIE_ARGS(return a / b), true, true)
FMP_DEFINE_FUNC2(div, Flt, Flt, Flt, CUF_TIE_ARGS(return a / b), true, true)
FMP_DEFINE_FUNC2_WITH_BUFFER(div, Vec, Flt, Vec, CUF_TIE_ARGS(*mBuffer = a; *mBuffer /= b; return *mBuffer), CUF_TIE_ARGS(return a / b), false, false)
FMP_DEFINE_FUNC2(mod, Int, Int, Int, CUF_TIE_ARGS(return a % b), true, true)
FMP_DEFINE_FUNC2(add, Int, Int, Int, CUF_TIE_ARGS(return a + b), true, true)
FMP_DEFINE_FUNC2(add, Int, Flt, Flt, CUF_TIE_ARGS(return a + b), true, true)
FMP_DEFINE_FUNC2(add, Flt, Int, Flt, CUF_TIE_ARGS(return a + b), true, true)
FMP_DEFINE_FUNC2(add, Flt, Flt, Flt, CUF_TIE_ARGS(return a + b), true, true)
FMP_DEFINE_FUNC2_WITH_BUFFER(add, Str, Str, Str, CUF_TIE_ARGS(*mBuffer = a; *mBuffer += b; return *mBuffer), CUF_TIE_ARGS(return a + b), false, false)
FMP_DEFINE_FUNC2_WITH_BUFFER(add, Vec, Vec, Vec, CUF_TIE_ARGS(*mBuffer = a; *mBuffer += b; return *mBuffer), CUF_TIE_ARGS(return a + b), false, false)
FMP_DEFINE_FUNC2_WITH_BUFFER(add, Mat, Mat, Mat, CUF_TIE_ARGS(*mBuffer = a; *mBuffer += b; return *mBuffer), CUF_TIE_ARGS(return a + b), false, false)
FMP_DEFINE_FUNC2(sub, Int, Int, Int, CUF_TIE_ARGS(return a - b), true, true)
FMP_DEFINE_FUNC2(sub, Int, Flt, Flt, CUF_TIE_ARGS(return a - b), true, true)
FMP_DEFINE_FUNC2(sub, Flt, Int, Flt, CUF_TIE_ARGS(return a - b), true, true)
FMP_DEFINE_FUNC2(sub, Flt, Flt, Flt, CUF_TIE_ARGS(return a - b), true, true)
FMP_DEFINE_FUNC2_WITH_BUFFER(sub, Vec, Vec, Vec, CUF_TIE_ARGS(*mBuffer = a; *mBuffer -= b; return *mBuffer), CUF_TIE_ARGS(return a - b), false, false)
FMP_DEFINE_FUNC2_WITH_BUFFER(sub, Mat, Mat, Mat, CUF_TIE_ARGS(*mBuffer = a; *mBuffer -= b; return *mBuffer), CUF_TIE_ARGS(return a - b), false, false)
FMP_DEFINE_FUNC2(gt, Int, Int, Int, CUF_TIE_ARGS(return (int64_t)(a > b)), false, false)
FMP_DEFINE_FUNC2(gt, Int, Flt, Int, CUF_TIE_ARGS(return (int64_t)(a > b)), false, false)
FMP_DEFINE_FUNC2(gt, Flt, Int, Int, CUF_TIE_ARGS(return (int64_t)(a > b)), false, false)
FMP_DEFINE_FUNC2(gt, Flt, Flt, Int, CUF_TIE_ARGS(return (int64_t)(a > b)), false, false)
FMP_DEFINE_FUNC2(geq, Int, Int, Int, CUF_TIE_ARGS(return (int64_t)(a >= b)), false, false)
FMP_DEFINE_FUNC2(geq, Int, Flt, Int, CUF_TIE_ARGS(return (int64_t)(a >= b)), false, false)
FMP_DEFINE_FUNC2(geq, Flt, Int, Int, CUF_TIE_ARGS(return (int64_t)(a >= b)), false, false)
FMP_DEFINE_FUNC2(geq, Flt, Flt, Int, CUF_TIE_ARGS(return (int64_t)(a >= b)), false, false)
FMP_DEFINE_FUNC2(lt, Int, Int, Int, CUF_TIE_ARGS(return (int64_t)(a < b)), false, false)
FMP_DEFINE_FUNC2(lt, Int, Flt, Int, CUF_TIE_ARGS(return (int64_t)(a < b)), false, false)
FMP_DEFINE_FUNC2(lt, Flt, Int, Int, CUF_TIE_ARGS(return (int64_t)(a < b)), false, false)
FMP_DEFINE_FUNC2(lt, Flt, Flt, Int, CUF_TIE_ARGS(return (int64_t)(a < b)), false, false)
FMP_DEFINE_FUNC2(leq, Int, Int, Int, CUF_TIE_ARGS(return (int64_t)(a <= b)), false, false)
FMP_DEFINE_FUNC2(leq, Int, Flt, Int, CUF_TIE_ARGS(return (int64_t)(a <= b)), false, false)
FMP_DEFINE_FUNC2(leq, Flt, Int, Int, CUF_TIE_ARGS(return (int64_t)(a <= b)), false, false)
FMP_DEFINE_FUNC2(leq, Flt, Flt, Int, CUF_TIE_ARGS(return (int64_t)(a <= b)), false, false)
FMP_DEFINE_FUNC2(eq, Int, Int, Int, CUF_TIE_ARGS(return (int64_t)(a == b)), false, false)
FMP_DEFINE_FUNC2(eq, Flt, Flt, Int, CUF_TIE_ARGS(return (int64_t)(a == b)), false, false)
FMP_DEFINE_FUNC2(eq, Str, Str, Int, CUF_TIE_ARGS(return (int64_t)(a == b)), false, false)
FMP_DEFINE_FUNC2(eq, Vec, Vec, Int, CUF_TIE_ARGS(return (int64_t)(a == b)), false, false)
FMP_DEFINE_FUNC2(eq, Mat, Mat, Int, CUF_TIE_ARGS(return (int64_t)(a == b)), false, false)
FMP_DEFINE_FUNC2(neq, Int, Int, Int, CUF_TIE_ARGS(return (int64_t)(a != b)), false, false)
FMP_DEFINE_FUNC2(neq, Flt, Flt, Int, CUF_TIE_ARGS(return (int64_t)(a != b)), false, false)
FMP_DEFINE_FUNC2(neq, Str, Str, Int, CUF_TIE_ARGS(return (int64_t)(a != b)), false, false)
FMP_DEFINE_FUNC2(neq, Vec, Vec, Int, CUF_TIE_ARGS(return (int64_t)(a != b)), false, false)
FMP_DEFINE_FUNC2(neq, Mat, Mat, Int, CUF_TIE_ARGS(return (int64_t)(a != b)), false, false)
FMP_DEFINE_FUNC2(and, Int, Int, Int, CUF_TIE_ARGS(return (int64_t)(a && b)), false, false)
FMP_DEFINE_FUNC2(and, Int, Flt, Int, CUF_TIE_ARGS(return (int64_t)(a && b)), false, false)
FMP_DEFINE_FUNC2(and, Flt, Int, Int, CUF_TIE_ARGS(return (int64_t)(a && b)), false, false)
FMP_DEFINE_FUNC2(and, Flt, Flt, Int, CUF_TIE_ARGS(return (int64_t)(a && b)), false, false)
FMP_DEFINE_FUNC2(or, Int, Int, Int, CUF_TIE_ARGS(return (int64_t)(a || b)), false, false)
FMP_DEFINE_FUNC2(or, Int, Flt, Int, CUF_TIE_ARGS(return (int64_t)(a || b)), false, false)
FMP_DEFINE_FUNC2(or, Flt, Int, Int, CUF_TIE_ARGS(return (int64_t)(a || b)), false, false)
FMP_DEFINE_FUNC2(or, Flt, Flt, Int, CUF_TIE_ARGS(return (int64_t)(a || b)), false, false)
FMP_DEFINE_FUNC2(atan2, Int, Int, Flt, CUF_TIE_ARGS(return std::atan2(a, b)), false, false)
FMP_DEFINE_FUNC2(atan2, Int, Flt, Flt, CUF_TIE_ARGS(return std::atan2(a, b)), false, false)
FMP_DEFINE_FUNC2(atan2, Flt, Int, Flt, CUF_TIE_ARGS(return std::atan2(a, b)), false, false)
FMP_DEFINE_FUNC2(atan2, Flt, Flt, Flt, CUF_TIE_ARGS(return std::atan2(a, b)), false, false)
FMP_DEFINE_FUNC2(log2, Int, Int, Flt, CUF_TIE_ARGS(return std::log2(a) / std::log2(b)), false, false)
FMP_DEFINE_FUNC2(log2, Int, Flt, Flt, CUF_TIE_ARGS(return std::log2(a) / std::log2(b)), false, false)
FMP_DEFINE_FUNC2(log2, Flt, Int, Flt, CUF_TIE_ARGS(return std::log2(a) / std::log2(b)), false, false)
FMP_DEFINE_FUNC2(log2, Flt, Flt, Flt, CUF_TIE_ARGS(return std::log2(a) / std::log2(b)), false, false)
FMP_DEFINE_FUNC2(max, Int, Int, Int, CUF_TIE_ARGS(return std::max(a, b)), true, false)
FMP_DEFINE_FUNC2(max, Flt, Flt, Flt, CUF_TIE_ARGS(return std::max(a, b)), true, false)
FMP_DEFINE_FUNC2(min, Int, Int, Int, CUF_TIE_ARGS(return std::min(a, b)), true, false)
FMP_DEFINE_FUNC2(min, Flt, Flt, Flt, CUF_TIE_ARGS(return std::min(a, b)), true, false)
FMP_DEFINE_FUNC2_WITH_BUFFER(vec2, Flt, Flt, Vec, CUF_TIE_ARGS(*mBuffer = { a, b }; return *mBuffer;), CUF_TIE_ARGS(return { a, b };), true, false)
FMP_DEFINE_FUNC2_WITH_BUFFER(mat2, Vec, Vec, Mat, CUF_TIE_ARGS(MakeMatrix(*mBuffer, a, b); return *mBuffer;), CUF_TIE_ARGS(return MakeMatrix(a, b)), false, false)
FMP_DEFINE_FUNC2(dot, Vec, Vec, Flt, CUF_TIE_ARGS(return Dot(a, b)), false, false)
FMP_DEFINE_FUNC2_WITH_BUFFER(cross, Vec, Vec, Vec, CUF_TIE_ARGS(Cross(*mBuffer, a, b); return *mBuffer;), CUF_TIE_ARGS(return Cross(a, b);), false, false)
FMP_DEFINE_FUNC2_WITH_BUFFER(index2, Str, Int, Str, CUF_TIE_ARGS(*mBuffer = a[b]; return *mBuffer;), CUF_TIE_ARGS(return a[b];), true, true)
FMP_DEFINE_FUNC2(index2, Vec, Int, Flt, CUF_TIE_ARGS(return a[(uint32_t)b];), true, true)
FMP_DEFINE_FUNC3(if, Int, Int, Int, Int, CUF_TIE_ARGS(return a ? b : c), false, false)
FMP_DEFINE_FUNC3(if, Int, Flt, Flt, Flt, CUF_TIE_ARGS(return a ? b : c), false, false)
FMP_DEFINE_FUNC3(if, Int, Str, Str, Str, CUF_TIE_ARGS(return a ? b : c), false, false)
FMP_DEFINE_FUNC3(if, Int, Vec, Vec, Vec, CUF_TIE_ARGS(return a ? b : c), false, false)
FMP_DEFINE_FUNC3_WITH_BUFFER(vec3, Flt, Flt, Flt, Vec, CUF_TIE_ARGS(*mBuffer = { a, b, c }; return *mBuffer;), CUF_TIE_ARGS(return { a, b, c };), true, false)
FMP_DEFINE_FUNC3_WITH_BUFFER(mat3, Vec, Vec, Vec, Mat, CUF_TIE_ARGS(MakeMatrix(*mBuffer, a, b, c); return *mBuffer;), CUF_TIE_ARGS(return MakeMatrix(a, b, c);), false, false)
FMP_DEFINE_FUNC3(index3, Mat, Int, Int, Flt, CUF_TIE_ARGS(return a[(uint32_t)b][(uint32_t)c];), true, true)
std::map<std::string, size_t> gFuncNames = {
{ "sin", 0 },
{ "cos", 1 },
{ "tan", 2 },
{ "asin", 3 },
{ "acos", 4 },
{ "atan", 5 },
{ "ln", 6 },
{ "log10", 7 },
{ "exp", 8 },
{ "square", 9 },
{ "cube", 10 },
{ "sqrt", 11 },
{ "cbrt", 12 },
{ "ceil", 13 },
{ "floor", 14 },
{ "int", 15 },
{ "float", 16 },
{ "abs", 17 },
{ "len", 18 },
{ "transpose", 19 },
{ "atan2", 20 },
{ "log2", 21 },
{ "max", 22 },
{ "min", 23 },
{ "vec2", 24 },
{ "mat2", 25 },
{ "dot", 26 },
{ "cross", 27 },
{ "if", 28 },
{ "vec3", 29 },
{ "mat3", 30 }
};

}

}

}

#endif
