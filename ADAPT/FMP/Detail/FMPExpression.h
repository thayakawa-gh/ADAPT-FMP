#ifndef FMPEXPRESSION_H
#define FMPEXPRESSION_H

#include <ADAPT/CUF/Exception.h>
#include <ADAPT/CUF/LinearAllocator.h>
#include <ADAPT/CUF/Variant.h>
#include <ADAPT/CUF/StaticAny.h>
#include <ADAPT/CUF/Any.h>
#include <Eigen/Dense>

namespace adapt
{

namespace fmp
{

enum NumericalType : size_t
{
	VALUE_INT,
	VALUE_FLT,
	VALUE_STR,
	VALUE_VEC,
	VALUE_MAT,
	VALUE_END,
};

namespace detail
{

template <class T, class U>
std::enable_if_t<std::is_integral<U>::value, double> fast_pow(T base, U exp)
{
	if (exp == 0) return 1;
	double temp = fast_pow(base, exp / 2);
	if (exp % 2 == 0)
		return temp * temp;
	else
	{
		if (exp > 0)
			return base * temp * temp;
		else
			return (temp * temp) / base;
	}
}

#define FMP_DEFINE_FUNC1(NAME, ARG, RES, PROCESS, UPWARD, DOWNWARD)\
struct NAME##ARG\
{\
	static constexpr bool Upward = UPWARD;\
	static constexpr bool Downward = DOWNWARD;\
	using ArgType = ARG##Type;\
	using RetType = RES##Type;\
	using RawRetType = typename RetType::RawType;\
	using RawArgType = typename ArgType::RawType;\
	NAME##ARG(ParserState*) {}\
	void IndexToPtr(ParserState*) const {}\
	static RawRetType process(RawArgType a) { PROCESS; }\
	static typename RetType::ValueType process_when_compile(typename ArgType::ValueType a) { return process(a); }\
};
#define FMP_DEFINE_FUNC1_WITH_BUFFER(NAME, ARG, RES, PROCESS, CPROCESS, UPWARD, DOWNWARD)\
struct NAME##ARG\
{\
	static constexpr bool Upward = UPWARD;\
	static constexpr bool Downward = DOWNWARD;\
	using ArgType = ARG##Type;\
	using RetType = RES##Type;\
	using RawRetType = typename RetType::RawType;\
	using RawArgType = typename ArgType::RawType;\
	NAME##ARG(ParserState* state) { mIndex = state->mRtrnBuffer.EmplaceBack<RetType::ValueType>(); }\
	void IndexToPtr(ParserState* state) const { mBuffer = &state->mRtrnBuffer.Get<RetType::ValueType>(mIndex); }\
	RawRetType process(RawArgType a) const { PROCESS; }\
	static typename RetType::ValueType process_when_compile(typename ArgType::ValueType a) { CPROCESS; }\
private:\
	union\
	{\
		mutable RetType::ValueType* mBuffer;\
		size_t mIndex;\
	};\
};
#define FMP_DEFINE_FUNC2(NAME, ARG1, ARG2, RES, PROCESS, UPWARD, DOWNWARD)\
struct NAME##ARG1##ARG2\
{\
	static constexpr bool Upward = UPWARD;\
	static constexpr bool Downward = DOWNWARD;\
	using ArgType1 = ARG1##Type;\
	using ArgType2 = ARG2##Type;\
	using RetType = RES##Type;\
	using RawRetType = typename RetType::RawType;\
	using RawArgType1 = typename ArgType1::RawType;\
	using RawArgType2 = typename ArgType2::RawType;\
	NAME##ARG1##ARG2(ParserState*) {}\
	void IndexToPtr(ParserState*) const {}\
	static RawRetType process(RawArgType1 a, RawArgType2 b) { PROCESS; }\
	static typename RetType::ValueType process_when_compile(typename ArgType1::ValueType a, typename ArgType2::ValueType b) { return process(a, b); }\
};
#define FMP_DEFINE_FUNC2_WITH_BUFFER(NAME, ARG1, ARG2, RES, PROCESS, CPROCESS, UPWARD, DOWNWARD)\
struct NAME##ARG1##ARG2\
{\
	static constexpr bool Upward = UPWARD;\
	static constexpr bool Downward = DOWNWARD;\
	using ArgType1 = ARG1##Type;\
	using ArgType2 = ARG2##Type;\
	using RetType = RES##Type;\
	using RawRetType = typename RetType::RawType;\
	using RawArgType1 = typename ArgType1::RawType;\
	using RawArgType2 = typename ArgType2::RawType;\
	NAME##ARG1##ARG2(ParserState* state) { mIndex = state->mRtrnBuffer.EmplaceBack<RetType::ValueType>(); }\
	void IndexToPtr(ParserState* state) const { mBuffer = &state->mRtrnBuffer.Get<RetType::ValueType>(mIndex); }\
	RawRetType process(RawArgType1 a, RawArgType2 b) const { PROCESS; }\
	static typename RetType::ValueType process_when_compile(typename ArgType1::ValueType a, typename ArgType2::ValueType b) { CPROCESS; }\
private:\
	union\
	{\
		mutable RetType::ValueType* mBuffer;\
		size_t mIndex;\
	};\
};
#define FMP_DEFINE_FUNC3(NAME, ARG1, ARG2, ARG3, RES, PROCESS, UPWARD, DOWNWARD)\
struct NAME##ARG1##ARG2##ARG3\
{\
	static constexpr bool Upward = UPWARD;\
	static constexpr bool Downward = DOWNWARD;\
	using ArgType1 = ARG1##Type;\
	using ArgType2 = ARG2##Type;\
	using ArgType3 = ARG3##Type;\
	using RetType = RES##Type;\
	using RawRetType = typename RetType::RawType;\
	using RawArgType1 = typename ArgType1::RawType;\
	using RawArgType2 = typename ArgType2::RawType;\
	using RawArgType3 = typename ArgType3::RawType;\
	NAME##ARG1##ARG2##ARG3(ParserState*) {}\
	void IndexToPtr(ParserState*) const {}\
	static RawRetType process(RawArgType1 a, RawArgType2 b, RawArgType3 c) { PROCESS; }\
	static typename RetType::ValueType process_when_compile(\
		typename ArgType1::ValueType a, typename ArgType2::ValueType b, typename ArgType2::ValueType c)\
		{ return process(a, b, c); }\
};
#define FMP_DEFINE_FUNC3_WITH_BUFFER(NAME, ARG1, ARG2, ARG3, RES, PROCESS, CPROCESS, UPWARD, DOWNWARD)\
struct NAME##ARG1##ARG2##ARG3\
{\
	static constexpr bool Upward = UPWARD;\
	static constexpr bool Downward = DOWNWARD;\
	using ArgType1 = ARG1##Type;\
	using ArgType2 = ARG2##Type;\
	using ArgType3 = ARG3##Type;\
	using RetType = RES##Type;\
	using RawRetType = typename RetType::RawType;\
	using RawArgType1 = typename ArgType1::RawType;\
	using RawArgType2 = typename ArgType2::RawType;\
	using RawArgType3 = typename ArgType3::RawType;\
	NAME##ARG1##ARG2##ARG3(ParserState* state) { mIndex = state->mRtrnBuffer.EmplaceBack<RetType::ValueType>(); }\
	void IndexToPtr(ParserState* state) const { mBuffer = &state->mRtrnBuffer.Get<RetType::ValueType>(mIndex); }\
	RawRetType process(RawArgType1 a, RawArgType2 b, RawArgType3 c) const { PROCESS; }\
	static typename RetType::ValueType process_when_compile(\
		typename ArgType1::ValueType a, typename ArgType2::ValueType b, typename ArgType2::ValueType c)\
		{ CPROCESS; }\
private:\
	union\
	{\
		mutable RetType::ValueType* mBuffer;\
		size_t mIndex;\
	};\
};

struct ParserState
{
	ParserState()
		: mError(false), mRootNode(nullptr)
	{}

	void Error(const std::string& m)
	{
		mMessage = m;
		mError = true;
	}
	bool IsError() const { return mError; }

	bool mError;
	StaticAny<16> mRootNode;
	std::string mMessage;
	std::vector<Any> mTermBuffer;//定数ノードの値を一時格納しておく。
	LinearAllocator mNodeBuffer;//ノードそれ自体を格納。
	LinearAllocator mRtrnBuffer;//戻り値用バッファ。
};

struct IntType
{
	static constexpr NumericalType label = VALUE_INT;
	using ValueType = int64_t;
	using RawType = int64_t;
};
struct FltType
{
	static constexpr NumericalType label = VALUE_FLT;
	using ValueType = double;
	using RawType = double;
};
struct StrType
{
	static constexpr NumericalType label = VALUE_STR;
	using ValueType = std::string;
	using RawType = const std::string&;
};
struct VecType
{
	static constexpr NumericalType label = VALUE_VEC;
	using ValueType = Eigen::VectorXd;
	using RawType = const Eigen::VectorXd&;
};
struct MatType
{
	static constexpr NumericalType label = VALUE_MAT;
	using ValueType = Eigen::MatrixXd;
	using RawType = const Eigen::MatrixXd&;
};
struct NonType
{
	static constexpr NumericalType label = VALUE_END;
	using ValueType = void;
	using RawType = void;
};

template <class RawType>
struct ConvertToType;
template <>
struct ConvertToType<int64_t> { using Type = IntType; };
template <>
struct ConvertToType<double> { using Type = FltType; };
template <>
struct ConvertToType<std::string> { using Type = StrType; };
template <>
struct ConvertToType<Eigen::VectorXd> { using Type = VecType; };
template <>
struct ConvertToType<Eigen::MatrixXd> { using Type = MatType; };

struct NodeValue
{
	//constant node用
	explicit NodeValue(int64_t i) : mValue(i) {}
	explicit NodeValue(double i) : mValue(i) {}
	explicit NodeValue(const std::string& i) : mValue(i) {}
	explicit NodeValue(const Eigen::VectorXd& i) : mValue(i) {}
	explicit NodeValue(const Eigen::MatrixXd& i) : mValue(i) {}

	//variable node用
	explicit NodeValue(const int64_t* i)
	{
		mValue.Emplace<VALUE_INT + VALUE_END>(i);
	}
	explicit NodeValue(const double* i)
	{
		mValue.Emplace<VALUE_FLT + VALUE_END>(i);
	}
	explicit NodeValue(const std::string* i)
	{
		mValue.Emplace<VALUE_STR + VALUE_END>(i);
	}
	explicit NodeValue(const Eigen::VectorXd* i)
	{
		mValue.Emplace<VALUE_VEC + VALUE_END>(i);
	}
	explicit NodeValue(const Eigen::MatrixXd* i)
	{
		mValue.Emplace<VALUE_MAT + VALUE_END>(i);
	}

	const int64_t& GetInt() const { return mValue.Get<VALUE_INT>(); }
	const double&  GetFlt() const { return mValue.Get<VALUE_FLT>(); }
	const std::string&  GetStr() const { return mValue.Get<VALUE_STR>(); }
	const Eigen::VectorXd&  GetVec() const { return mValue.Get<VALUE_VEC>(); }
	const Eigen::MatrixXd&  GetMat() const { return mValue.Get<VALUE_MAT>(); }
	size_t GetIntIndex() const { return (size_t)mValue.Get<VALUE_INT + VALUE_END>(); }
	size_t GetFltIndex() const { return (size_t)mValue.Get<VALUE_FLT + VALUE_END>(); }
	size_t GetStrIndex() const { return (size_t)mValue.Get<VALUE_STR + VALUE_END>(); }
	size_t GetVecIndex() const { return (size_t)mValue.Get<VALUE_VEC + VALUE_END>(); }
	size_t GetMatIndex() const { return (size_t)mValue.Get<VALUE_MAT + VALUE_END>(); }
	const int64_t* GetIntPtr() const { return mValue.Get<VALUE_INT + VALUE_END>(); }
	const double*  GetFltPtr() const { return mValue.Get<VALUE_FLT + VALUE_END>(); }
	const std::string*  GetStrPtr() const { return mValue.Get<VALUE_STR + VALUE_END>(); }
	const Eigen::VectorXd* GetVecPtr() const { return mValue.Get<VALUE_VEC + VALUE_END>(); }
	const Eigen::MatrixXd*  GetMatPtr() const { return mValue.Get<VALUE_MAT + VALUE_END>(); }

	bool IsConstant() const { return mValue.GetIndex() < VALUE_END; }
	NumericalType GetType() const
	{
		size_t t = mValue.GetIndex();
		return (NumericalType)(t < VALUE_END ? t : t - VALUE_END);
	}
	size_t GetTypeIndex() const { return mValue.GetIndex(); }

protected:
	Variant<
		int64_t, double, std::string, Eigen::VectorXd, Eigen::MatrixXd,
		const int64_t*, const double*, const std::string*, const Eigen::VectorXd*, const Eigen::MatrixXd*> mValue;
};

template <class Type>
class FMPExpressionNodeBase
{
public:
	using RawType = typename Type::RawType;
	virtual RawType value() const { throw InvalidType(""); };
	//virtual RawType operator*() { throw InvalidType(""); }
	virtual void IndexToPtr(ParserState*) { throw InvalidType(""); }
};

//終端ノード。
template <class Type>
class FMPExpressionTerminalNode : public FMPExpressionNodeBase<Type>
{
public:
	using RetType = typename Type::ValueType;
	using RawRetType = typename Type::RawType;
	using ArgType = RetType;
	FMPExpressionTerminalNode(ParserState*, size_t p)
		: mArg(*reinterpret_cast<const ArgType**>(&p))
	{}
	inline virtual RawRetType value() const override { return *mArg; };
	virtual void IndexToPtr(ParserState*) const {}
	//virtual RawRetType operator*() const override { return Type::process(mArg); }
private:
	const ArgType* mArg;
};

//#define ARGTYPE_T Terminal
//#define AGRTYPE_J Juncture

#define ARGTYPE_T(TYPE) const typename TYPE::ValueType*
#define ARGTYPE_J(TYPE) FMPExpressionNodeBase<TYPE>*

#define PROCESS_T(ARG) *ARG
#define PROCESS_J(ARG) ARG->value()

//
#define INDEX_TO_PTR_T(ARG, IND, TYPE)\
{ size_t tmp = IND; memcpy(&ARG, &tmp, sizeof(size_t)); }
//ARG = &(state->mTermBuffer.Get<TYPE::ValueType>(IND));
#define INDEX_TO_PTR_J(ARG, IND, TYPE)\
ARG = &(state->mNodeBuffer.Get<FMPExpressionNodeBase<TYPE>>(IND));\
ARG->IndexToPtr(state);

//関数単体ノード。
//mArgとmIndexには、TerminalかJunctureのどちらかが格納される。
//junctureの場合は、それ自体へのポインタかまたはLinearAllocatorのindexが収まる。
//terminalの場合、現在のTerminalNodeは必ず変数をポインタで持つので、
#define EXPRESSION_NODE1(MOD)\
template <class Func>\
class FMPExpression##MOD##Node_impl : public Func\
{\
public:\
	using RetType = typename Func::RetType;\
	using RawRetType = typename RetType::RawType;\
	using ArgType = typename Func::ArgType;\
	using RawArgType = ARGTYPE_##MOD(ArgType);\
	FMPExpression##MOD##Node_impl(ParserState* state, size_t i) : Func(state), mIndex(i) {}\
	FMPExpression##MOD##Node_impl(ParserState* state, std::tuple<size_t> t) : Func(state), mIndex(std::get<0>(t)) {}\
	RawRetType value() const { return Func::process(PROCESS_##MOD(mArg)); };\
	void IndexToPtr(ParserState* state) { Func::IndexToPtr(state); INDEX_TO_PTR_##MOD(mArg, mIndex, typename Func::ArgType); }\
private:\
	union\
	{\
		RawArgType mArg;\
		size_t mIndex;\
	};\
};
#define EXPRESSION_NODE2(MOD1, MOD2)\
template <class Func>\
class FMPExpression##MOD1##MOD2##Node_impl : public Func\
{\
public:\
	using RetType = typename Func::RetType;\
	using RawRetType = typename RetType::RawType;\
	using ArgType1 = typename Func::ArgType1;\
	using ArgType2 = typename Func::ArgType2;\
	using RawArgType1 = ARGTYPE_##MOD1(ArgType1);\
	using RawArgType2 = ARGTYPE_##MOD2(ArgType2);\
	FMPExpression##MOD1##MOD2##Node_impl(ParserState* state, size_t i, size_t j)\
		: Func(state), mIndex1(i), mIndex2(j) {}\
	FMPExpression##MOD1##MOD2##Node_impl(ParserState* state, std::tuple<size_t, size_t> t)\
		: Func(state), mIndex1(std::get<0>(t)), mIndex2(std::get<1>(t)) {}\
	RawRetType value() const\
	{\
		decltype(auto) a1 = PROCESS_##MOD1(mArg1); decltype(auto) a2 = PROCESS_##MOD2(mArg2);\
		return Func::process(a1, a2);\
	};\
	void IndexToPtr(ParserState* state)\
	{\
		Func::IndexToPtr(state);\
		INDEX_TO_PTR_##MOD1(mArg1, mIndex1, typename Func::ArgType1);\
		INDEX_TO_PTR_##MOD2(mArg2, mIndex2, typename Func::ArgType2);\
	}\
private:\
	union\
	{\
		RawArgType1 mArg1; \
		size_t mIndex1; \
	};\
	union\
	{\
		RawArgType2 mArg2; \
		size_t mIndex2; \
	};\
};
#define EXPRESSION_NODE3(MOD1, MOD2, MOD3)\
template <class Func>\
class FMPExpression##MOD1##MOD2##MOD3##Node_impl : public Func\
{\
public:\
	using RetType = typename Func::RetType;\
	using RawRetType = typename RetType::RawType;\
	using ArgType1 = typename Func::ArgType1;\
	using ArgType2 = typename Func::ArgType2;\
	using ArgType3 = typename Func::ArgType3;\
	using RawArgType1 = ARGTYPE_##MOD1(ArgType1);\
	using RawArgType2 = ARGTYPE_##MOD2(ArgType2);\
	using RawArgType3 = ARGTYPE_##MOD3(ArgType2);\
	FMPExpression##MOD1##MOD2##MOD3##Node_impl(ParserState* state, size_t i, size_t j, size_t k)\
		: Func(state), mIndex1(i), mIndex2(j), mIndex3(k) {}\
	FMPExpression##MOD1##MOD2##MOD3##Node_impl(ParserState* state, std::tuple<size_t, size_t, size_t> t)\
		: Func(state), mIndex1(std::get<0>(t)), mIndex2(std::get<1>(t)), mIndex3(std::get<2>(t)) {}\
	RawRetType value() const\
	{\
		decltype(auto) a1 = PROCESS_##MOD1(mArg1);\
		decltype(auto) a2 = PROCESS_##MOD2(mArg2);\
		decltype(auto) a3 = PROCESS_##MOD3(mArg3);\
		return Func::process(a1, a2, a3);\
	};\
	void IndexToPtr(ParserState* state)\
	{\
		Func::IndexToPtr(state);\
		INDEX_TO_PTR_##MOD1(mArg1, mIndex1, typename Func::ArgType1);\
		INDEX_TO_PTR_##MOD2(mArg2, mIndex2, typename Func::ArgType2);\
		INDEX_TO_PTR_##MOD3(mArg3, mIndex3, typename Func::ArgType3);\
	}\
private:\
	union\
	{\
		RawArgType1 mArg1; \
		size_t mIndex1; \
	};\
	union\
	{\
		RawArgType2 mArg2; \
		size_t mIndex2; \
	};\
	union\
	{\
		RawArgType3 mArg3; \
		size_t mIndex3; \
	};\
};

//結合ノード。
template <class Func, class Expr>
class FMPExpressionFNode_impl : public Func
{
public:
	using RetType = typename Func::RetType;
	using RawRetType = typename RetType::RawType;
	template <class ...ExprArgs>
	FMPExpressionFNode_impl(ParserState* state, std::tuple<ExprArgs...> t) : Func(state), mArg(state, t) {}
	RawRetType value() const { return Func::process(mArg.value()); };
	void IndexToPtr(ParserState* state)
	{
		Func::IndexToPtr(state);
		mArg.IndexToPtr(state);
	}
private:
	Expr mArg;
};
#define EXPRESSION_FXNODE2(MOD)\
template <class Func, class Expr>\
class FMPExpressionF##MOD##Node_impl : public Func\
{\
public:\
	using RetType = typename Func::RetType;\
	using ArgType2 = typename Func::ArgType2;\
	using RawArgType2 = ARGTYPE_##MOD(ArgType2);\
	using RawRetType = typename RetType::RawType;\
	template <class ...ExprArgs>\
	FMPExpressionF##MOD##Node_impl(ParserState* state, std::tuple<ExprArgs...> t, size_t i)\
		: Func(state), mArg1(state, t), mIndex2(i) {}\
	RawRetType value() const\
	{\
		decltype(auto) a1 = mArg1.value(); decltype(auto) a2 = PROCESS_##MOD(mArg2);\
		return Func::process(a1, a2);\
	}\
	void IndexToPtr(ParserState* state)\
	{\
		Func::IndexToPtr(state);\
		mArg1.IndexToPtr(state);\
		INDEX_TO_PTR_##MOD(mArg2, mIndex2, typename Func::ArgType2);\
	}\
private:\
	Expr mArg1;\
	union\
	{\
		RawArgType2 mArg2;\
		size_t mIndex2;\
	};\
};
#define EXPRESSION_XFNODE2(MOD)\
template <class Func, class Expr>\
class FMPExpression##MOD##FNode_impl : public Func\
{\
public:\
	using RetType = typename Func::RetType;\
	using ArgType1 = typename Func::ArgType1;\
	using RawArgType1 = ARGTYPE_##MOD(ArgType1);\
	using RawRetType = typename RetType::RawType;\
	template <class ...ExprArgs>\
	FMPExpression##MOD##FNode_impl(ParserState* state, size_t i, std::tuple<ExprArgs...> t)\
		: Func(state), mIndex1(i), mArg2(state, t) {}\
	inline RawRetType value() const\
	{\
		decltype(auto) a1 = PROCESS_##MOD(mArg1); decltype(auto) a2 = mArg2.value();\
		return Func::process(a1, a2);\
	};\
	void IndexToPtr(ParserState* state)\
	{\
		Func::IndexToPtr(state);\
		INDEX_TO_PTR_##MOD(mArg1, mIndex1, typename Func::ArgType1);\
		mArg2.IndexToPtr(state);\
	}\
private:\
	union\
	{\
		RawArgType1 mArg1;\
		size_t mIndex1;\
	};\
	Expr mArg2;\
};

EXPRESSION_NODE1(T)
EXPRESSION_NODE1(J)
EXPRESSION_NODE2(T, T)
EXPRESSION_NODE2(T, J)
EXPRESSION_NODE2(J, T)
EXPRESSION_NODE2(J, J)
EXPRESSION_NODE3(T, T, T)
EXPRESSION_NODE3(T, T, J)
EXPRESSION_NODE3(T, J, T)
EXPRESSION_NODE3(T, J, J)
EXPRESSION_NODE3(J, T, T)
EXPRESSION_NODE3(J, T, J)
EXPRESSION_NODE3(J, J, T)
EXPRESSION_NODE3(J, J, J)


//3引数関数、演算子は結合させない。動作が複雑になりすぎるので。
EXPRESSION_FXNODE2(T)
EXPRESSION_FXNODE2(J)
EXPRESSION_XFNODE2(T)
EXPRESSION_XFNODE2(J)

#define EXPRESSION_NODE_DERIVED(MOD)\
template <class Func>\
class FMPExpression##MOD##Node\
	: public FMPExpressionNodeBase<typename Func::RetType>, public FMPExpression##MOD##Node_impl<Func>\
{\
public:\
	using Impl = FMPExpression##MOD##Node_impl<Func>;\
	using Impl::Impl;\
	using RetType = typename Func::RetType;\
	using RawRetType = typename Func::RawRetType;\
	virtual inline RawRetType value() const override { return Impl::value(); }\
	virtual inline void IndexToPtr(ParserState* state) override { Impl::IndexToPtr(state); }\
};
#define EXPRESSION_FNODE_DERIVED(MOD)\
template <class Func, class Expr>\
class FMPExpression##MOD##Node\
	: public FMPExpressionNodeBase<typename Func::RetType>, public FMPExpression##MOD##Node_impl<Func, Expr>\
{\
public:\
	using Impl = FMPExpression##MOD##Node_impl<Func, Expr>;\
	using Impl::Impl;\
	using RetType = typename Func::RetType;\
	using RawRetType = typename Func::RawRetType;\
	virtual inline RawRetType value() const override { return Impl::value(); }\
	virtual inline void IndexToPtr(ParserState* state) override { Impl::IndexToPtr(state); }\
};

EXPRESSION_NODE_DERIVED(T)
EXPRESSION_NODE_DERIVED(J)
EXPRESSION_NODE_DERIVED(TT)
EXPRESSION_NODE_DERIVED(TJ)
EXPRESSION_NODE_DERIVED(JT)
EXPRESSION_NODE_DERIVED(JJ)
EXPRESSION_NODE_DERIVED(TTT)
EXPRESSION_NODE_DERIVED(TTJ)
EXPRESSION_NODE_DERIVED(TJT)
EXPRESSION_NODE_DERIVED(TJJ)
EXPRESSION_NODE_DERIVED(JTT)
EXPRESSION_NODE_DERIVED(JTJ)
EXPRESSION_NODE_DERIVED(JJT)
EXPRESSION_NODE_DERIVED(JJJ)

EXPRESSION_FNODE_DERIVED(F)
EXPRESSION_FNODE_DERIVED(FT)
EXPRESSION_FNODE_DERIVED(FJ)
EXPRESSION_FNODE_DERIVED(TF)
EXPRESSION_FNODE_DERIVED(JF)

}

}

}

#endif