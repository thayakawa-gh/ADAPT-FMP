#ifndef FMPNODE_BASE_H
#define FMPNODE_BASE_H

#include <ADAPT/CUF/Any.h>
#include <ADAPT/CUF/StaticAny.h>
#include <ADAPT/CUF/Variant.h>
#include <ADAPT/CUF/Template.h>
#include <ADAPT/FMP/Detail/FMPExpression.h>
#include <ADAPT/FMP/Detail/FMPFunction.h>
#include <ADAPT/CUF/Trivializer.h>

namespace adapt
{

namespace fmp
{

namespace detail
{

struct TerminalNode;
struct JunctureNode;
struct FunctionNode;

struct FMPMakeExpressionBase
{
	virtual NumericalType GetType() const = 0;
	virtual JunctureNode Juncturize(ParserState* state) = 0;
	virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) = 0;
	virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) = 0;
	virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) = 0;
	virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) = 0;
	virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) = 0;
};

struct JunctureNode
{
	JunctureNode(NumericalType type, size_t index)
		: mType(type), mIndex(index)
	{}
	NumericalType GetType() const { return mType; }
	//別にParserStateを受け取る必要はないのだが、TerminalNode側が必要としているので一応受け取る。
	size_t GetIndex(ParserState* = nullptr) const { return mIndex; }
private:
	NumericalType mType;
	size_t mIndex;
};

struct TerminalNode : public NodeValue
{
	using NodeValue::NodeValue;

	JunctureNode Juncturize(ParserState* state)
	{
		size_t i = GetIndex(state);
		NumericalType t = GetType();
		mValue.Destroy();
		return JunctureNode(t, i);
	}
	std::size_t GetIndex(ParserState* state)
	{
		std::size_t res = 0;
		std::intptr_t i = 0;
		switch (mValue.GetIndex())
		{
		case VALUE_INT:
			state->mTermBuffer.push_back(mValue.Get<VALUE_INT>());
			i = (std::intptr_t)(&state->mTermBuffer.back().Get<int64_t>()); break;
		case VALUE_FLT:
			state->mTermBuffer.push_back(mValue.Get<VALUE_FLT>());
			i = (std::intptr_t)(&state->mTermBuffer.back().Get<double>()); break;
		case VALUE_STR:
			state->mTermBuffer.push_back(std::move(mValue.Get<VALUE_STR>()));
			i = (std::intptr_t)(&state->mTermBuffer.back().Get<std::string>()); break;
		case VALUE_VEC:
			state->mTermBuffer.push_back(std::move(mValue.Get<VALUE_VEC>()));
			i = (std::intptr_t)(&state->mTermBuffer.back().Get<Eigen::VectorXd>()); break;
		case VALUE_MAT:
			state->mTermBuffer.push_back(std::move(mValue.Get<VALUE_MAT>()));
			i = (std::intptr_t)(&state->mTermBuffer.back().Get<Eigen::MatrixXd>()); break;
		case VALUE_INT + VALUE_END: i = (std::intptr_t)mValue.Get<VALUE_INT + VALUE_END>(); break;
		case VALUE_FLT + VALUE_END: i = (std::intptr_t)mValue.Get<VALUE_FLT + VALUE_END>(); break;
		case VALUE_STR + VALUE_END: i = (std::intptr_t)mValue.Get<VALUE_STR + VALUE_END>(); break;
		case VALUE_VEC + VALUE_END: i = (std::intptr_t)mValue.Get<VALUE_VEC + VALUE_END>(); break;
		case VALUE_MAT + VALUE_END: i = (std::intptr_t)mValue.Get<VALUE_MAT + VALUE_END>(); break;
		default: throw InvalidType("");
		}
		mValue.Destroy();
		memcpy(&res, &i, sizeof(size_t));
		return res;
	}
};

struct FunctionNode
{
	//FunctionNodeは特殊な振る舞いをする。
	//mIsJunctureがfalseのとき、
	//FunctionNodeのmMakeFuncは実際にFMPMakeExpressionのインスタンスを保持している。
	//mIsJunctureがtrueのとき、
	//mMakeFuncはJunctureNodeを格納している。

	//1引数関数用
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, TrueType, TrueType, ParserState* state, TerminalNode& n);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, TrueType, FalseType, ParserState* state, TerminalNode& n);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, FalseType, TrueType, ParserState* state, TerminalNode& n);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, FalseType, FalseType, ParserState* state, TerminalNode& n);

	template <class Func>
	FunctionNode(Identity<Func>, size_t func, TrueType, TrueType, ParserState* state, FunctionNode& n);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, TrueType, FalseType, ParserState* state, FunctionNode& n);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, FalseType, TrueType, ParserState* state, FunctionNode& n);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, FalseType, FalseType, ParserState* state, FunctionNode& n);


	//2引数関数用
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, TrueType, TrueType, ParserState* state, TerminalNode& n1, TerminalNode& n2);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, TrueType, FalseType, ParserState* state, TerminalNode& n1, TerminalNode& n2);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, FalseType, TrueType, ParserState* state, TerminalNode& n1, TerminalNode& n2);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, FalseType, FalseType, ParserState* state, TerminalNode& n1, TerminalNode& n2);

	template <class Func>
	FunctionNode(Identity<Func>, size_t func, TrueType, TrueType, ParserState* state, TerminalNode& n1, FunctionNode& n2);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, TrueType, FalseType, ParserState* state, TerminalNode& n1, FunctionNode& n2);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, FalseType, TrueType, ParserState* state, TerminalNode& n1, FunctionNode& n2);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, FalseType, FalseType, ParserState* state, TerminalNode& n1, FunctionNode& n2);

	template <class Func>
	FunctionNode(Identity<Func>, size_t func, TrueType, TrueType, ParserState* state, FunctionNode& n1, TerminalNode& n2);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, TrueType, FalseType, ParserState* state, FunctionNode& n1, TerminalNode& n2);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, FalseType, TrueType, ParserState* state, FunctionNode& n1, TerminalNode& n2);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, FalseType, FalseType, ParserState* state, FunctionNode& n1, TerminalNode& n2);

	template <class Func>
	FunctionNode(Identity<Func>, size_t func, TrueType, TrueType, ParserState* state, FunctionNode& n1, FunctionNode& n2);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, TrueType, FalseType, ParserState* state, FunctionNode& n1, FunctionNode& n2);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, FalseType, TrueType, ParserState* state, FunctionNode& n1, FunctionNode& n2);
	template <class Func>
	FunctionNode(Identity<Func>, size_t func, FalseType, FalseType, ParserState* state, FunctionNode& n1, FunctionNode& n2);


	//3引数関数用
	//3引数関数は連結しないので、upwardもdownwardも無視する。
	template <class Func, bool BU, bool BD>
	FunctionNode(Identity<Func>, size_t func, BoolConstant<BU>, BoolConstant<BD>, ParserState* state, TerminalNode& n1, TerminalNode& n2, TerminalNode& n3);
	template <class Func, bool BU, bool BD>
	FunctionNode(Identity<Func>, size_t func, BoolConstant<BU>, BoolConstant<BD>, ParserState* state, TerminalNode& n1, FunctionNode& n2, TerminalNode& n3);
	template <class Func, bool BU, bool BD>
	FunctionNode(Identity<Func>, size_t func, BoolConstant<BU>, BoolConstant<BD>, ParserState* state, FunctionNode& n1, TerminalNode& n2, TerminalNode& n3);
	template <class Func, bool BU, bool BD>
	FunctionNode(Identity<Func>, size_t func, BoolConstant<BU>, BoolConstant<BD>, ParserState* state, FunctionNode& n1, FunctionNode& n2, TerminalNode& n3);
	template <class Func, bool BU, bool BD>
	FunctionNode(Identity<Func>, size_t func, BoolConstant<BU>, BoolConstant<BD>, ParserState* state, TerminalNode& n1, TerminalNode& n2, FunctionNode& n3);
	template <class Func, bool BU, bool BD>
	FunctionNode(Identity<Func>, size_t func, BoolConstant<BU>, BoolConstant<BD>, ParserState* state, TerminalNode& n1, FunctionNode& n2, FunctionNode& n3);
	template <class Func, bool BU, bool BD>
	FunctionNode(Identity<Func>, size_t func, BoolConstant<BU>, BoolConstant<BD>, ParserState* state, FunctionNode& n1, TerminalNode& n2, FunctionNode& n3);
	template <class Func, bool BU, bool BD>
	FunctionNode(Identity<Func>, size_t func, BoolConstant<BU>, BoolConstant<BD>, ParserState* state, FunctionNode& n1, FunctionNode& n2, FunctionNode& n3);

	NumericalType GetType() const
	{
		//return mType;
		if (IsJuncture()) return mMakeFunc.Get<JunctureNode>().GetType();
		else return mMakeFunc.Get<FMPMakeExpressionBase>().GetType();
	}
	bool IsJuncture() const { return mIsJuncture; }
	JunctureNode Juncturize(ParserState* state)
	{
		if (mIsJuncture) throw InvalidValue("This node has been already a Juncture node.");
		auto ptr = &mMakeFunc.Get<FMPMakeExpressionBase>();
		mMakeFunc.Emplace<JunctureNode>(ptr->Juncturize(state));
		mIsJuncture = true;
		return GetJunctureNode();
	}
	JunctureNode GetJunctureNode() const { if (!mIsJuncture) throw InvalidValue(""); return mMakeFunc.Get<JunctureNode>(); }
	//FMPMakeExpressionBase& GetMakeExpression() { return mMakeFunc.Get<FMPMakeExpressionBase>(); }

private:
	StaticAny<sizeof(TerminalNode) * 2 + 8> mMakeFunc;//sizeof(TerminalNode) + 8(vtable pointer)
	bool mIsJuncture;
	//NumericalType mType;
};
/*template <class Func>
struct FMPMakeExpressionCV : public FMPMakeExpressionBase
{
	using ArgType1 = typename Func::ArgType1;
	using ArgType2 = typename Func::ArgType2;
	virtual void* add(const ConstantNode& c, const FunctionNode& self) const override
	{
		if (c.GetType() == VALUE_INT && self.GetType() == VALUE_INT)
			FMPExpressionCFNode<addIntInt, FMPExpressionCVNode<Func>>();
	}
	virtual void* add(const VariableNode& c, const FunctionNode& self) const override
	{
		if (c.GetType() == VALUE_INT && self.GetType() == VALUE_INT)
			FMPExpressionCFNode<addIntInt, FMPExpressionCVNode<Func>>();
	}
	virtual void* Instanciate() override
	{
		return new FMPExpressionCVNode<Func>();
	}
};*/

template <template <class, class> class FMPExpression, class DnFunc, class UpFunc, class ...TArgs,
	bool B = std::is_same<typename UpFunc::RetType, typename DnFunc::ArgType>::value>
std::enable_if_t<B, JunctureNode>
MakeExpression(ParserState* state, const std::tuple<TArgs...>& a)
{
	size_t i = state->mNodeBuffer.EmplaceBack<FMPExpression<DnFunc, UpFunc>>(state, a);
	return { DnFunc::RetType::label, i };
}
template <template <class, class> class FMPExpression, class DnFunc, class UpFunc, class ...TArgs,
	bool B = std::is_same<typename UpFunc::RetType, typename DnFunc::ArgType2>::value>
std::enable_if_t<B, JunctureNode>
MakeExpression(ParserState* state, size_t a, const std::tuple<TArgs...>& b)
{
	size_t i = state->mNodeBuffer.EmplaceBack<FMPExpression<DnFunc, UpFunc>>(state, a, b);
	//const auto& x = state->mNodeBuffer.Get<FMPExpression<DnFunc, UpFunc>>();
	return { DnFunc::RetType::label, i };
}
template <template <class, class> class FMPExpression, class DnFunc, class UpFunc, class ...TArgs,
	bool B = std::is_same<typename UpFunc::RetType, typename DnFunc::ArgType1>::value>
std::enable_if_t<B, JunctureNode>
MakeExpression(ParserState* state, const std::tuple<TArgs...>& a, size_t b)
{
	size_t i = state->mNodeBuffer.EmplaceBack<FMPExpression<DnFunc, UpFunc>>(state, a, b);
	return { DnFunc::RetType::label, i };
}
template <template <class, class> class FMPExpression, class DnFunc, class UpFunc, class ...TArgs,
	bool B = std::is_same<typename UpFunc::RetType, typename DnFunc::ArgType>::value>
	std::enable_if_t<!B, JunctureNode>
	MakeExpression(ParserState* state, const std::tuple<TArgs...>& a)
{
	throw InvalidType("");
}
template <template <class, class> class FMPExpression, class DnFunc, class UpFunc, class ...TArgs,
	bool B = std::is_same<typename UpFunc::RetType, typename DnFunc::ArgType2>::value>
	std::enable_if_t<!B, JunctureNode>
	MakeExpression(ParserState* state, size_t a, const std::tuple<TArgs...>& b)
{
	throw InvalidType("");
}
template <template <class, class> class FMPExpression, class DnFunc, class UpFunc, class ...TArgs,
	bool B = std::is_same<typename UpFunc::RetType, typename DnFunc::ArgType1>::value>
std::enable_if_t<!B, JunctureNode>
MakeExpression(ParserState* state, const std::tuple<TArgs...>& a, size_t b)
{
	throw InvalidType("");
}
/*JunctureNode MakeExpression(...) 
{
	throw InvalidType("");
}*/

}

}

}

#endif