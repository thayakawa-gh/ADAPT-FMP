#ifndef FAST_MATH_PARSER_H
#define FAST_MATH_PARSER_H

#include <string>
#include <vector>
#include <ADAPT/FMP/Detail/FMPRe2c.h>
#include <ADAPT/FMP/Detail/FMPRe2c_impl.h>
#include <ADAPT/FMP/Detail/FMPExpression.h>
#include <ADAPT/FMP/Detail/FMPLemon.h>
#include <ADAPT/FMP/Detail/FMPNode.h>

namespace adapt
{

namespace fmp
{

class FastMathParser
{
public:

	FastMathParser(const std::string& eq, std::vector<FMPArgument> args)
		: mValid(true)
	{
		detail::ParserState state;
		detail::FMPRe2c re2c(eq, std::move(args));
		Trivializer<detail::NodeValue> v;
		v.NotConstruct();
		std::vector<std::tuple<int, Trivializer<detail::NodeValue>>> tokens;
		while (int token = re2c.Scan(v))
		{
			if (token == -1)
			{
				mValid = false;
				break;
			}
			tokens.emplace_back();
			auto& t = tokens.back();
			std::get<0>(t) = token;
			if (v.IsInitialized()) std::get<1>(t).Construct(*v);
			else std::get<1>(t).NotConstruct();
		}
		if (mValid)
		{
			void* parser = detail::ParseAlloc(malloc);
			for (auto t : tokens)
			{
				int token = std::get<0>(t);
				Trivializer<detail::NodeValue> tv;
				//tv.Construct(*std::get<1>(t));
				if (std::get<1>(t).IsInitialized()) tv.Construct(*std::get<1>(t));
				else tv.NotConstruct();
				detail::Parse(parser, token, tv, &state);
				if (state.IsError())
				{
					mValid = false;
					std::cout << state.mError << std::endl;
					break;
				}
			}
			detail::Parse(parser, 0, v, &state);
			detail::ParseFree(parser, free);
		}
		if (mValid)
		{
			detail::JunctureNode j = state.mRootNode.Get<detail::JunctureNode>();
			//const auto& x = state.mNodeBuffer.Get<detail::FMPExpressionNodeBase<detail::FltType>>(j.GetIndex());
			switch (j.GetType())
			{
			case VALUE_INT:
			{
				auto root = &state.mNodeBuffer.Get<detail::FMPExpressionNodeBase<detail::IntType>>(j.GetIndex());
				root->IndexToPtr(&state);
				mRootNode = root;
				break;
			}
			case VALUE_FLT:
			{
				auto root = &state.mNodeBuffer.Get<detail::FMPExpressionNodeBase<detail::FltType>>(j.GetIndex());
				root->IndexToPtr(&state);
				mRootNode = root;
				break;
			}
			case VALUE_STR:
			{
				auto root = &state.mNodeBuffer.Get<detail::FMPExpressionNodeBase<detail::StrType>>(j.GetIndex());
				root->IndexToPtr(&state);
				mRootNode = root;
				break;
			}
			case VALUE_VEC:
			{
				auto root = &state.mNodeBuffer.Get<detail::FMPExpressionNodeBase<detail::VecType>>(j.GetIndex());
				root->IndexToPtr(&state);
				mRootNode = root;
				break;
			}
			case VALUE_MAT:
			{
				auto root = &state.mNodeBuffer.Get<detail::FMPExpressionNodeBase<detail::MatType>>(j.GetIndex());
				root->IndexToPtr(&state);
				mRootNode = root;
				break;
			}
			}
			mTermBuffer = std::move(state.mTermBuffer);
			mNodeBuffer = std::move(state.mNodeBuffer);
			mRtrnBuffer = std::move(state.mRtrnBuffer);
			mValid = true;
		}
	}

	bool IsValid() const { return mValid; }

	int64_t Int() const { return mRootNode.Get_unsafe<0>()->value(); }
	double Flt() const { return mRootNode.Get_unsafe<1>()->value(); }
	const String& Str() const { return mRootNode.Get_unsafe<2>()->value(); }
	const Vector<double>& Vec() const { return mRootNode.Get_unsafe<3>()->value(); }
	const Matrix<double, 2>& Mat() const { return mRootNode.Get_unsafe<4>()->value(); }

	template <class Type>
	typename Type::RawType value() const { return mRootNode.Get_unsafe<Type::label>(); }

	NumericalType GetResultType() const { return (NumericalType)mRootNode.GetIndex(); }

private:

	Variant<
		detail::FMPExpressionNodeBase<detail::IntType>*,
		detail::FMPExpressionNodeBase<detail::FltType>*,
		detail::FMPExpressionNodeBase<detail::StrType>*,
		detail::FMPExpressionNodeBase<detail::VecType>*,
		detail::FMPExpressionNodeBase<detail::MatType>*> mRootNode;
	std::vector<Any> mTermBuffer;
	LinearAllocator mNodeBuffer;
	LinearAllocator mRtrnBuffer;
	bool mValid;
};

}

}

#endif