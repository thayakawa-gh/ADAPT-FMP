#ifndef CUF_MATH_H
#define CUF_MATH_H

#include <array>
#include <utility>
#include <cmath>
#include <random>

namespace adapt
{

inline namespace cuf
{

namespace math_const
{

static constexpr double pi = 3.1415926535897932;
static constexpr double e  = 2.7182818284590452;

}

template <class Iterator>
typename Iterator::value_type GetMean(Iterator begin, Iterator end)
{
	typename Iterator::value_type mean = 0.;
	size_t count = 0;
	for (; begin != end; ++begin)
	{
		mean += *begin;
		++count;
	}
	return mean / count;
}
template <class Iterator>
typename Iterator::value_type GetDeviation(Iterator begin, Iterator end)
{
	typename Iterator::value_type sum = 0., mean = 0.;
	size_t count = 0;
	for (; begin != end; ++begin)
	{
		sum += (*begin) * (*begin);
		mean += *begin;
		++count;
	}
	mean /= count;
	return std::sqrt(sum / count - mean * mean);
}
template <class Iterator>
std::array<typename Iterator::value_type, 2> GetMeanDev(Iterator begin, Iterator end)
{
	typename Iterator::value_type sum = 0., mean = 0.;
	size_t count = 0;
	for (; begin != end; ++begin)
	{
		sum += (*begin) * (*begin);
		mean += *begin;
		++count;
	}
	mean /= count;
	return { mean, std::sqrt(sum / count - mean * mean) };
}

double Gaussian(double mean, double dev, double x)
{
	double dx = x - mean;
	return std::exp(-(dx * dx) / (2 * dev * dev)) / (std::sqrt(2 * 3.1415926535897932) * dev);
}
//mx、myは平均値、corrは相関係数。
double Gaussian2D(double mx, double my, double devx, double devy, double corr, double x, double y)
{
	double one_rho2 = 1 - corr * corr;
	double dx = (x - mx);
	double dy = (y - my);
	return std::exp(-((dx * dx) / (devx * devx) + (dy * dy) / (devy * devy) - (2 * corr * dx * dy) / (devx * devy)) / (2 * one_rho2)) /
		(2 * 3.1415926535897932 * devx * devy * std::sqrt(one_rho2));
}
//devはsigma_x、sigma_y、相関係数を与える。
double Gaussian2D(std::array<double, 2> mean, std::array<double, 3> dev, std::array<double, 2> xy)
{
	return Gaussian2D(mean[0], mean[1], dev[0], dev[1], dev[2], xy[0], xy[1]);
}

struct GaussianObject
{
	GaussianObject(double mean, double dev) : mMean(mean), mDev(dev) {}
	GaussianObject() : GaussianObject(0, 1.) {}

	double operator()(double x) const { return Gaussian(mMean, mDev, x); }
	//double operator()(std::array<double, 1> x) const { return Gaussian(mMean, mDev, x[0]); }

private:
	const double mMean;
	const double mDev;
};

struct Gaussian2DObject
{
	Gaussian2DObject(double meanx, double meany, double devx, double devy, double corr = 0.)
		: mMeanX(meanx), mMeanY(meany), mDevX(devx), mDevY(devy), mCorr(corr) {}
	Gaussian2DObject(std::array<double, 2> mean, std::array<double, 3> dev)
		: Gaussian2DObject(mean[0], mean[1], dev[0], dev[1], dev[2]) {}
	Gaussian2DObject()
		: Gaussian2DObject(0, 0, 1, 1, 0)
	{}

	double operator()(double x, double y) const { return Gaussian2D(mMeanX, mMeanY, mDevX, mDevY, mCorr, x, y); }
	//double operator()(std::array<double, 2> xy) const { return Gaussian2D(mMeanX, mMeanY, mDevX, mDevY, mCorr, xy[0], xy[1]); }

private:
	const double mMeanX, mMeanY;
	const double mDevX, mDevY, mCorr;
};


std::pair<double, std::array<double, 3>> GetMinimumDistance(std::array<double, 3> pos1, std::array<double, 3> ang1,
															std::array<double, 3> pos2, std::array<double, 3> ang2)
{
	auto dot = [](const std::array<double, 3>& a, const std::array<double, 3>& b)
	{
		return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
	};
	auto norm_2 = [](const std::array<double, 3>& a)
	{
		return a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
	};
	auto add = [](const std::array<double, 3>& a, const std::array<double, 3>& b)
	{
		return std::array<double, 3>{ a[0] + b[0], a[1] + b[1], a[2] + b[2] };
	};
	auto sub = [](const std::array<double, 3>& a, const std::array<double, 3>& b)
	{
		return std::array<double, 3>{ a[0] - b[0], a[1] - b[1], a[2] - b[2] };
	};
	auto mul = [](double a, const std::array<double, 3>& b)
	{
		return std::array<double, 3>{ a* b[0], a* b[1], a* b[2] };
	};
	auto div = [](const std::array<double, 3>& b, double a)
	{
		return std::array<double, 3>{ b[0] / a, b[1] / a, b[2] / a };
	};
	std::array<double, 3> PA = sub(pos2, pos1);
	double ap = dot(ang1, ang2);
	double na_2 = norm_2(ang1);
	double na = std::sqrt(na_2);
	double np_2 = norm_2(ang2);
	double np = std::sqrt(np_2);
	double x = (na * np - ap) * (na * np + ap);
	double s = dot(PA, sub(mul(np_2, ang1), mul(ap, ang2))) / x;
	double t = dot(PA, sub(mul(ap, ang1), mul(na_2, ang2))) / x;
	std::array<double, 3> B = add(pos1, mul(s, ang1));
	std::array<double, 3> Q = add(pos2, mul(t, ang2));
	return { std::sqrt(norm_2(sub(Q, B))), div(add(B, Q), 2) };
}


class RandomWithAnyProbFunc
{
	struct InvIntegFuncElement
	{
		double intercept;
		double slope;
		double border;
	};
	struct InvIntegFunc
	{
		InvIntegFunc() {}
		//[0, 1]の一様分布乱数を与えられた分布の乱数に変換する。
		double operator()(double x) const
		{
			for (const auto& e : table)
			{
				if (x > e.border) continue;
				return x * e.slope + e.intercept;
			}
			throw std::exception();
		}
		std::vector<InvIntegFuncElement> table;
	};

public:

	//fは
	RandomWithAnyProbFunc(const std::vector<double>& f, double min, double max)
		: mUniform(0, 1)
	{
		size_t size = f.size();
		double integ = 0;
		double step = (max - min) / size;
		double norm = std::accumulate(f.begin(), f.end(), 0.);
		mFunc.table.resize(size);
		size_t i = 0;
		for (auto x : BundleRange(mFunc.table, f))
		{
			auto t = std::get<0>(x);
			auto d = std::get<1>(x);
			double inv_intercept = integ / norm;
			double inv_slope = d / (norm * step);
			//y = inv_slope * (x - i * step - min) + inv_intercept;
			//x - i * step - min = (y - inv_intercept) / inv_slope
			//x = (y - inv_intercept) / inv_slope + i * step + min;
			//x = y / inv_slope - inv_intercept / inv_slope + i * step + min
			t.intercept = -inv_intercept / inv_slope + i * step + min;
			t.slope = 1. / inv_slope;
			integ += d;
			t.border = integ / norm;
			++i;
		}
	}

	//引数にはmt19937などのエンジンを与える。
	//コンストラクタに与えた確率密度関数に従う乱数を生成する。
	template <class URBG>
	double operator()(URBG& g) const
	{
		return mFunc(mUniform(g));
	}

private:

	InvIntegFunc mFunc;
	std::uniform_real_distribution<> mUniform;
};

}

}

#endif