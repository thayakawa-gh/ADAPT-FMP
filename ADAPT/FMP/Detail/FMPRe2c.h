#ifndef FMPRE2C_H
#define FMPRE2C_H

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

namespace fmp
{

struct FMPArgument
{
	template <class Type>
	FMPArgument(const std::string& name, const Type* ptr)
		: mType(detail::ConvertToType<Type>::Type::label), mName(name), mPtr(ptr)  {}
	NumericalType mType;
	std::string mName;
	const void* mPtr;
};
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

struct FMPConstant
{
	template <class Type>
	FMPConstant(const std::string& name, Type&& ptr)
		: mName(name), mValue(std::forward<Type>(ptr)) {}
	std::string mName;
	detail::NodeValue mValue;
};
struct ConstName
{
	ConstName(const char* c, size_t len)
		: mName(c, len)
	{}
	template <class Type>
	FMPConstant operator=(Type&& cnst)
	{
		return FMPConstant(mName, std::forward<Type>(cnst));
	}
	std::string mName;
};

namespace lit
{
inline ArgName operator""_a(const char* c, size_t len)
{
	return ArgName(c, len);
}
inline ConstName operator""_c(const char* c, size_t len)
{
	return ConstName(c, len);
}
}

namespace detail
{

class FMPRe2c
{
public:

	FMPRe2c(const std::string& str, std::vector<FMPArgument>&& args, std::vector<FMPConstant>&& cnsts);
	~FMPRe2c();

	std::string Text();
	std::string String();
	std::pair<const void*, NumericalType> FindArg(const std::string& text) const;
	NodeValue FindConst(const std::string& text) const;
	int64_t Length();

	int Scan(Trivializer<NodeValue>& yylval);

private:

	std::string mExpression;
	std::vector<FMPArgument> mArgs;
	std::vector<FMPConstant> mConsts;
	const char* mCursor;
	const char* mLimit;
	const char* mToken;
	const char* mMarker;
};

inline FMPRe2c::FMPRe2c(const std::string& str, std::vector<FMPArgument>&& args, std::vector<FMPConstant>&& cnsts)
	: mExpression(str), mArgs(std::move(args)), mConsts(std::move(cnsts)), mCursor(str.c_str()), mLimit(0), mToken(0), mMarker(0)
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
inline NodeValue FMPRe2c::FindConst(const std::string& text) const
{
	for (auto& c : mConsts)
	{
		if (c.mName == text) return c.mValue;
	}
	throw OutOfRange("");
}
inline int64_t FMPRe2c::Length()
{
	return (mCursor - mToken);
}

}

}

}

#endif // CALC_SCANNER_H_