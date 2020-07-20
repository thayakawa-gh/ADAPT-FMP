#ifndef AGR2_RE2C_H
#define AGR2_RE2C_H

#include <ADAPT/FMP/Detail/FMPExpression.h>
#include <ADAPT/FMP/Detail/FMPFunction.h>
#include <ADAPT/FMP/Detail/FMPLemon_parser.h>
#include <ADAPT/CUF/Template.h>
#include <ADAPT/CUF/Trivializer.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>

namespace adapt
{

namespace agr2
{

struct FMPArgument
{
	struct ArgName
	{
		ArgName(const char* c, size_t len)
			: mName(c, len)
		{}
		template <class Type>
		FMPArgument operator=(const Type* arg)
		{
			return FMPArgument(mName, arg);
		}
		std::string mName;
	};
	template <class Type>
	FMPArgument(const std::string& name, const Type* ptr)
		: mName(name), mPtr(ptr), mType(detail::ConvertToType<Type>::Type::label) {}
	NumericalType mType;
	std::string mName;
	const void* mPtr;
};

namespace lit
{
inline FMPArgument::ArgName operator""_a(const char* c, size_t len)
{
	return FMPArgument::ArgName(c, len);
}
}

namespace detail
{

class FMPRe2c
{
public:

	template <class ...Args>
	FMPRe2c(const std::string& str, std::vector<FMPArgument>&& args);
	~FMPRe2c();

	std::string Text();
	std::string String();
	std::pair<const void*, NumericalType> FindArg(const std::string& text) const;
	int64_t Length();

	int Scan(Trivializer<NodeValue>& yylval);

private:

	std::string mExpression;
	std::vector<FMPArgument> mArgs;
	const char* mCursor;
	const char* mLimit;
	const char* mToken;
	const char* mMarker;
};

template <class ...Args>
inline FMPRe2c::FMPRe2c(const std::string& str, std::vector<FMPArgument>&& args)
	: mExpression(str), mArgs(std::move(args)), mCursor(str.c_str()), mLimit(0), mToken(0), mMarker(0)
{}
inline FMPRe2c::~FMPRe2c()
{}

inline std::string FMPRe2c::Text()
{
	return std::string(mToken, mToken + Length());
}
inline std::string FMPRe2c::String()
{
	return std::string(mToken + 1, mToken + Length() - 1);
}
inline std::pair<const void*, NumericalType> FMPRe2c::FindArg(const std::string& text) const
{
	for (auto& a : mArgs)
	{
		if (a.mName == text) return { a.mPtr, a.mType };
	}
	return { nullptr, VALUE_END };
}
inline int64_t FMPRe2c::Length()
{
	return (mCursor - mToken);
}

}

}

}

#endif // CALC_SCANNER_H_