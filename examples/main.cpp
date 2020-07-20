#include <ADAPT/FMP/FastMathParser.h>

using namespace adapt;
using namespace adapt::agr2;
using namespace adapt::agr2::lit;

/*
基本的にヘッダーオンリー。
内部でassertを使っているので、パフォーマンスを気にする場合はreleaseビルド時にはNDEBUGを定義しておくこと。

現在扱えるのは、int64_t、double、adapt::String、adapt::Vector<double>、adapt::Matrix<double, 2>の5つの型。
それぞれInt、Flt、Str、Vec、Matと表現する。
このMathParserは基本的に静的型付けで、数式中ではint64_tとdoubleの自動キャストなども行われない。キャストしたい場合はint、float関数を使うこと。

FastMathParserというクラスが本体。
## コンストラクタ
FastMathParser(const std::string& expression, const std::vector<FMPArgument>& args);
第1引数には計算させたい式を、第2引数には式の中で用いる引数を与える。

## メンバ関数
NumericalType GetResultType() const; ... 結果の型を取得する。
double Flt() const; ... 結果がFlt(double)型であるときに、与えた数式を計算するのに使う関数。
int64_t Int() const; ... 結果がInt(int64_t)型以下略。
const String& Str() const; ... 結果がStr(adapt::String)型以下略。
const Vector<double>& Vec() const; ... 結果がVec(adapt::Vector<double>)型以下略。
const Matrix<double, 2>& Mat() const; ... 結果がMat(adapt::Matrix<double, 2>)型以下略。
bool IsValid() const; ... 与えた式に問題ない場合、trueが返る。文法的な異常や関数引数の誤りなどがあるとfalseが返る。


使用可能な関数は以下の通り。

1引数関数
sin
cos
tan
asin
acos
atan
ln : 自然対数
log10 : 常用対数
exp
square : 2乗 x^2とするよりこちらのほうがやや速い。
cube : 3乗 x^3とするよりこちらのほうがやや速い。
sqrt : 平方根
cbrt : 立方根
ceil
floor
int
float
abs
len : Str、Vecに対して、その長さを返す。

2引数関数
atan2
log2 : log2(a, b)はbを底とするaの対数。
max
min
vec2 : 2次元のベクトルを作る。
dot : 内積を求める。引数のVec2つの大きさが等しくなければならない。
cross : 外積を求める。引数のVec2つがともに3次元ベクトルでなければならない。
mat2 : 2行の行列を作る。mat2(vec2(1, 2), vec2(3, 4))のように引数に次元の等しい2つのVecを与えることで、
       1 2
       3 4
       という行列が作られる。

3引数関数
if : if(a, b, c)としたとき、aがtrueならbを、falseならcを返す。bとcは必ず同じ型でなければならない。
vec3 : 3次元のベクトルを作る。
mat3 : 3行の行列を作る。mat2と同じように、次元の等しいVecを3つ与える。

単項演算子
- : 負号      正号は要らんだろう。
二項演算子
^ : 冪乗
* / % + -
> < >= <= == != && ||

添字演算子
[] : Vec、Str、Matに対してのみ使える。Vec、Strに対してはa[b]とすることでaのb番目の要素を返す。Matについてはa[b, c]とすることでaのb行c列の要素を返す。

より詳細な定義はFMPFunction.hを参照。
FMP_DEFINE_FUNC1(名前, 引数の型, 戻り値の型, 動作, ...)1引数関数用
FMP_DEFINE_FUNC2(名前, 引数の型1, 引数の型2, 戻り値の型, 動作, ...)2引数関数用
みたいに定義されている。
*/

int main()
{
	{
		std::string expr = "25*x^5 - 35*x^4 - 15*x^3 + 40*x^2 - 15*x + 1";
		double x;
		double r0 = 0;
		double r1 = 1;
		double delta = 1 / 100.0;
		FastMathParser f(expr, { "x"_a = &x });
		for (x = r0; x <= r1; x += delta)
		{
			printf("%19.15f\t%19.15f\n", x, f.Flt());
		}
	}
	{
		std::string expr1 = "sqrt(dot(xy, xy))";
		std::string expr2 = "atan2(xy[1], xy[0])";
		Vector<double> xy({ 1., 1. });
		FastMathParser r(expr1, { "xy"_a = &xy });
		FastMathParser t(expr2, { "xy"_a = &xy });
		for (double theta = 0; theta < 1.; theta += 0.01)
		{
			xy[0] = cos(theta);
			xy[1] = sin(theta);
			printf("r = %lf, t = %lf\n", r.Flt(), t.Flt());
		}
	}
	{
		std::string expr = "mat2(vec2(cos(t), -sin(t)), vec2(sin(t), cos(t)))*v + vec2(0.1, 0.5)";
		double theta;
		Vector<double> v(2);
		FastMathParser aff(expr, { "t"_a = &theta, "v"_a = &v });
		for (double x = 0; x < 1; x += 0.1)
		{
			for (double y = 0; y < 1; y += 0.1)
			{
				for (theta = 0; theta < 0.1; theta += 0.005)
				{
					v[0] = x, v[1] = y;
					const Vector<double>& res = aff.Vec();
					printf("(%8.5lf, %8.5lf) -> (%8.5lf, %8.5lf)\n", x, y, res[0], res[1]);
				}
			}
		}
	}
	return 0;
}