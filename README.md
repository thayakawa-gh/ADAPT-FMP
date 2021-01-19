#  ADAPT-FMP

FMP is fast mathematical expression parser/evaluator for C++. 
FMP can operate not only floating point and integer but also string, vector and matrix in a single expression, but its performance is comparable to the other parser libraries.

[benchmarks(Japanese)](https://kenkyu-note.hatenablog.com/entry/2021/01/19/191218)

ADAPT-FMP requires Eigen linear algebra library and C++17.

```cpp
#include <ADAPT/FMP/FastMathParser.h>

using namespace adapt;
using namespace adapt::fmp;
using namespace adapt::fmp::lit;

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
		Eigen::VectorXd xy(2); xy << 1., 1.;
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
		std::string expr = "mat2(vec2(cos(pi * t), -sin(pi * t)), vec2(sin(pi * t), cos(pi * t)))*v + vec2(0.1, 0.5)";
		double theta;
		Eigen::VectorXd v(2);
		FastMathParser aff(expr, { "t"_a = &theta, "v"_a = &v }, { "pi"_c = 3.1415926535897932});
		for (double x = 0; x < 1; x += 0.1)
		{
			for (double y = 0; y < 1; y += 0.1)
			{
				for (theta = 0; theta < 1; theta += 0.05)
				{
					v[0] = x, v[1] = y;
					const Eigen::VectorXd& res = aff.Vec();
					printf("(%8.5lf, %8.5lf) -> (%8.5lf, %8.5lf)\n", x, y, res[0], res[1]);
				}
			}
		}
	}
	return 0;
}
```

## Types
*  signed 64bit integer(int64_t)
*  64bit floating point(double)
*  floating point vector(Eigen::VectorXd)
*  floating point matrix(Eigen::MatrixXd)
*  std::string

## Functions
### 1 argument
#### for arithmetic types
sin, cos, tan, asin, acos, atan, exp, square, cube, sqrt, cbrt, ceil, floor, int, float, abs,
ln, log10, abs
#### for string
len ... returns length of string.
#### for matrix
transpose ... returns transpose of a matrix.

### 2 arguments
#### for arithmetic types
atan2 ... atan2(a, b) returns arc tangent of a / b [-pi, pi].  
log2 ... log2(a, b) returns log of a to base b.  
min, max  
vec2 ... vec2(a, b) returns a 2 dimensional vector with components [a, b].
#### for vector
mat2 ... requires 2 vectors with same dimension. If N dimensional vectors [a0, a1, ..., aN] [b0, b1, ..., bN] are given to this function, it returns N x 2 matrix with components [ [a0, b0], [a1, b1], ..., [aN, bN] ].  
dot ... returns inner product.  
cross ... returns outer product.  


### 3 arguments
if ... if(a, b, c) returns b if a != 0, otherwise c. "a" must be an integer.  
vec3 ... 3 dimensionnal version of vec2.  
mat3 ... N x 3 version of mat2.  

## Unary operators
\- !

## Binary operators
^ ... a ^ b returns a to the power of b.  
\* / %  
\+ \-   
< <= > >=  
== !=  
&& ||  

## Index operator
a[b] ... returns the b-th element from vector/string a.  
a[b, c] ... returns the element of b-th row of column c from matrix a.  

Lemon/re2c are used as parser/lexer generator, and python to generate C++ code not including too many templates which make compiling heavy.
