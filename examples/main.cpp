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
		std::string expr = "mat2(vec2(cos(pi * t), -sin(pi * t)), vec2(sin(pi * t), cos(pi * t)))*v + vec2(0.1, 0.5)";
		double theta;
		Vector<double> v(2);
		FastMathParser aff(expr, { "t"_a = &theta, "v"_a = &v }, { "pi"_c = 3.1415926535897932});
		for (double x = 0; x < 1; x += 0.1)
		{
			for (double y = 0; y < 1; y += 0.1)
			{
				for (theta = 0; theta < 1; theta += 0.05)
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