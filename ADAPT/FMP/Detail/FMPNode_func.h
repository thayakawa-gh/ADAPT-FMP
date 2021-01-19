#ifndef FMPNODE_FUNC_H
#define FMPNODE_FUNC_H

#include <ADAPT/FMP/Detail/FMPNode_base.h>

namespace adapt
{

namespace fmp
{

namespace detail
{

template <class Func, class ResType = typename Func::RetType>
struct FMPMakeExpressionT;

template <class Func>
struct FMPMakeExpressionT<Func, IntType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionT(const TerminalNode& n) : mUpArg(n) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        switch (func)
        {
        case 0:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, sinInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 1:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cosInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 2:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, tanInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 6:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, lnInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 7:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, log10Int, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 8:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, expInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 9:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, squareInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 10:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cubeInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 11:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, sqrtInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 12:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cbrtInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 13:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, ceilInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 14:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, floorInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 15:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, intInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 16:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, floatInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 17:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, absInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 34:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, subInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, log2IntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, log2FltInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, maxIntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, minIntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, powIntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, powFltInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, mulIntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, mulFltInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, divIntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, divFltInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, modIntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, addIntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, addFltInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, subIntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, subFltInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, index2StrInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, index2VecInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, log2IntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, log2FltInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, maxIntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, minIntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, powIntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, powFltInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, mulIntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, mulFltInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, divIntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, divFltInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, modIntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, addIntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, addFltInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, subIntInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, subFltInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, index2StrInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, index2VecInt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, log2IntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, log2IntFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, maxIntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, minIntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, powIntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, mulIntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, mulIntFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, divIntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, divIntFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, modIntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, addIntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, addIntFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, subIntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, subIntFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, log2IntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, log2IntFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, maxIntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, minIntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, powIntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, mulIntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, mulIntFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, divIntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, divIntFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, modIntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, addIntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, addIntFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, subIntInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, subIntFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionTNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTNode<Func>>(state, mUpArg.GetIndex(state)));
    }
    TerminalNode mUpArg;
};
template <class Func>
struct FMPMakeExpressionT<Func, FltType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionT(const TerminalNode& n) : mUpArg(n) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        switch (func)
        {
        case 0:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, sinFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 1:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cosFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 2:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, tanFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 6:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, lnFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 7:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, log10Flt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 8:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, expFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 9:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, squareFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 10:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cubeFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 11:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, sqrtFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 12:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cbrtFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 13:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, ceilFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 14:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, floorFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 15:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, intFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 16:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, floatFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 17:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, absFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 34:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, subFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, log2IntFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, log2FltFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, maxFltFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, minFltFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, vec2FltFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, mulIntFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, mulFltFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, divIntFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, divFltFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, addIntFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, addFltFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, subIntFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, subFltFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, log2IntFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, log2FltFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, maxFltFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, minFltFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, vec2FltFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, mulIntFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, mulFltFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, divIntFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, divFltFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, addIntFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, addFltFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, subIntFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, subFltFlt, FMPExpressionTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, log2FltInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, log2FltFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, maxFltFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, minFltFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, vec2FltFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, powFltInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, mulFltInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, mulFltFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, divFltInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, divFltFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, addFltInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, addFltFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, subFltInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, subFltFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, log2FltInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, log2FltFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, maxFltFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, minFltFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, vec2FltFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, powFltInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, mulFltInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, mulFltFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, divFltInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, divFltFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, addFltInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, addFltFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, subFltInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, subFltFlt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionTNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTNode<Func>>(state, mUpArg.GetIndex(state)));
    }
    TerminalNode mUpArg;
};
template <class Func>
struct FMPMakeExpressionT<Func, StrType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionT(const TerminalNode& n) : mUpArg(n) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, index2StrInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, index2StrInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionTNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTNode<Func>>(state, mUpArg.GetIndex(state)));
    }
    TerminalNode mUpArg;
};
template <class Func>
struct FMPMakeExpressionT<Func, VecType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionT(const TerminalNode& n) : mUpArg(n) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, index2VecInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, index2VecInt, FMPExpressionTNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionTNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTNode<Func>>(state, mUpArg.GetIndex(state)));
    }
    TerminalNode mUpArg;
};
template <class Func>
struct FMPMakeExpressionT<Func, MatType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionT(const TerminalNode& n) : mUpArg(n) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionTNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTNode<Func>>(state, mUpArg.GetIndex(state)));
    }
    TerminalNode mUpArg;
};
template <class Func, class ResType = typename Func::RetType>
struct FMPMakeExpressionJ;

template <class Func>
struct FMPMakeExpressionJ<Func, IntType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionJ(const JunctureNode& n) : mUpArg(n) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        switch (func)
        {
        case 0:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, sinInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 1:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cosInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 2:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, tanInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 6:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, lnInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 7:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, log10Int, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 8:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, expInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 9:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, squareInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 10:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cubeInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 11:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, sqrtInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 12:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cbrtInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 13:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, ceilInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 14:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, floorInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 15:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, intInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 16:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, floatInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 17:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, absInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 34:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, subInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, log2IntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, log2FltInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, maxIntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, minIntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, powIntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, powFltInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, mulIntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, mulFltInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, divIntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, divFltInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, modIntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, addIntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, addFltInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, subIntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, subFltInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, index2StrInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, index2VecInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, log2IntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, log2FltInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, maxIntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, minIntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, powIntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, powFltInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, mulIntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, mulFltInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, divIntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, divFltInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, modIntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, addIntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, addFltInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, subIntInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, subFltInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, index2StrInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, index2VecInt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, log2IntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, log2IntFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, maxIntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, minIntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, powIntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, mulIntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, mulIntFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, divIntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, divIntFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, modIntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, addIntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, addIntFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, subIntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, subIntFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, log2IntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, log2IntFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, maxIntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, minIntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, powIntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, mulIntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, mulIntFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, divIntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, divIntFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, modIntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, addIntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, addIntFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, subIntInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, subIntFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionJNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJNode<Func>>(state, mUpArg.GetIndex(state)));
    }
    JunctureNode mUpArg;
};
template <class Func>
struct FMPMakeExpressionJ<Func, FltType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionJ(const JunctureNode& n) : mUpArg(n) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        switch (func)
        {
        case 0:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, sinFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 1:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cosFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 2:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, tanFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 6:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, lnFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 7:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, log10Flt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 8:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, expFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 9:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, squareFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 10:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cubeFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 11:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, sqrtFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 12:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cbrtFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 13:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, ceilFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 14:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, floorFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 15:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, intFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 16:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, floatFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 17:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, absFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 34:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, subFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, log2IntFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, log2FltFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, maxFltFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, minFltFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, vec2FltFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, mulIntFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, mulFltFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, divIntFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, divFltFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, addIntFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, addFltFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, subIntFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, subFltFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, log2IntFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, log2FltFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, maxFltFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, minFltFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, vec2FltFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, mulIntFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, mulFltFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, divIntFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, divFltFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, addIntFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, addFltFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, subIntFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, subFltFlt, FMPExpressionJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, log2FltInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, log2FltFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, maxFltFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, minFltFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, vec2FltFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, powFltInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, mulFltInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, mulFltFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, divFltInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, divFltFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, addFltInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, addFltFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, subFltInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, subFltFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, log2FltInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, log2FltFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, maxFltFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, minFltFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, vec2FltFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, powFltInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, mulFltInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, mulFltFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, divFltInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, divFltFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, addFltInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, addFltFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, subFltInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, subFltFlt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionJNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJNode<Func>>(state, mUpArg.GetIndex(state)));
    }
    JunctureNode mUpArg;
};
template <class Func>
struct FMPMakeExpressionJ<Func, StrType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionJ(const JunctureNode& n) : mUpArg(n) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, index2StrInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, index2StrInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionJNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJNode<Func>>(state, mUpArg.GetIndex(state)));
    }
    JunctureNode mUpArg;
};
template <class Func>
struct FMPMakeExpressionJ<Func, VecType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionJ(const JunctureNode& n) : mUpArg(n) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, index2VecInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, index2VecInt, FMPExpressionJNode_impl<Func>>(state, std::make_tuple(mUpArg.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionJNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJNode<Func>>(state, mUpArg.GetIndex(state)));
    }
    JunctureNode mUpArg;
};
template <class Func>
struct FMPMakeExpressionJ<Func, MatType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionJ(const JunctureNode& n) : mUpArg(n) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionJNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJNode<Func>>(state, mUpArg.GetIndex(state)));
    }
    JunctureNode mUpArg;
};
template <class Func, class ResType = typename Func::RetType>
struct FMPMakeExpressionTT;

template <class Func>
struct FMPMakeExpressionTT<Func, IntType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionTT(const TerminalNode& n1, const TerminalNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        switch (func)
        {
        case 0:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, sinInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 1:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cosInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 2:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, tanInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 6:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, lnInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 7:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, log10Int, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 8:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, expInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 9:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, squareInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 10:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cubeInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 11:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, sqrtInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 12:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cbrtInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 13:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, ceilInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 14:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, floorInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 15:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, intInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 16:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, floatInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 17:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, absInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 34:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, subInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, log2IntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, log2FltInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, maxIntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, minIntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, powIntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, powFltInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, mulIntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, mulFltInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, divIntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, divFltInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, modIntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, addIntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, addFltInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, subIntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, subFltInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, index2StrInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, index2VecInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, log2IntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, log2FltInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, maxIntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, minIntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, powIntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, powFltInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, mulIntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, mulFltInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, divIntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, divFltInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, modIntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, addIntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, addFltInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, subIntInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, subFltInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, index2StrInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, index2VecInt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, log2IntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, log2IntFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, maxIntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, minIntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, powIntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, mulIntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, mulIntFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, divIntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, divIntFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, modIntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, addIntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, addIntFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, subIntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, subIntFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, log2IntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, log2IntFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, maxIntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, minIntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, powIntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, mulIntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, mulIntFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, divIntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, divIntFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, modIntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, addIntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, addIntFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, subIntInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, subIntFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionTTNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTTNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    TerminalNode mUpArg1;
    TerminalNode mUpArg2;
};
template <class Func>
struct FMPMakeExpressionTT<Func, FltType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionTT(const TerminalNode& n1, const TerminalNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        switch (func)
        {
        case 0:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, sinFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 1:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cosFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 2:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, tanFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 6:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, lnFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 7:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, log10Flt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 8:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, expFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 9:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, squareFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 10:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cubeFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 11:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, sqrtFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 12:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cbrtFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 13:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, ceilFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 14:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, floorFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 15:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, intFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 16:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, floatFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 17:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, absFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 34:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, subFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, log2IntFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, log2FltFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, maxFltFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, minFltFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, vec2FltFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, mulIntFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, mulFltFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, divIntFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, divFltFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, addIntFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, addFltFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, subIntFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, subFltFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, log2IntFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, log2FltFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, maxFltFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, minFltFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, vec2FltFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, mulIntFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, mulFltFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, divIntFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, divFltFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, addIntFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, addFltFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, subIntFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, subFltFlt, FMPExpressionTTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, log2FltInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, log2FltFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, maxFltFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, minFltFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, vec2FltFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, powFltInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, mulFltInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, mulFltFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, divFltInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, divFltFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, addFltInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, addFltFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, subFltInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, subFltFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, log2FltInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, log2FltFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, maxFltFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, minFltFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, vec2FltFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, powFltInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, mulFltInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, mulFltFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, divFltInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, divFltFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, addFltInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, addFltFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, subFltInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, subFltFlt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionTTNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTTNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    TerminalNode mUpArg1;
    TerminalNode mUpArg2;
};
template <class Func>
struct FMPMakeExpressionTT<Func, StrType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionTT(const TerminalNode& n1, const TerminalNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, index2StrInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, index2StrInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionTTNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTTNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    TerminalNode mUpArg1;
    TerminalNode mUpArg2;
};
template <class Func>
struct FMPMakeExpressionTT<Func, VecType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionTT(const TerminalNode& n1, const TerminalNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, index2VecInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, index2VecInt, FMPExpressionTTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionTTNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTTNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    TerminalNode mUpArg1;
    TerminalNode mUpArg2;
};
template <class Func>
struct FMPMakeExpressionTT<Func, MatType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionTT(const TerminalNode& n1, const TerminalNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionTTNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTTNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    TerminalNode mUpArg1;
    TerminalNode mUpArg2;
};
template <class Func, class ResType = typename Func::RetType>
struct FMPMakeExpressionTJ;

template <class Func>
struct FMPMakeExpressionTJ<Func, IntType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionTJ(const TerminalNode& n1, const JunctureNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        switch (func)
        {
        case 0:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, sinInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 1:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cosInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 2:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, tanInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 6:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, lnInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 7:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, log10Int, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 8:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, expInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 9:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, squareInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 10:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cubeInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 11:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, sqrtInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 12:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cbrtInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 13:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, ceilInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 14:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, floorInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 15:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, intInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 16:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, floatInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 17:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, absInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 34:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, subInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, log2IntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, log2FltInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, maxIntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, minIntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, powIntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, powFltInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, mulIntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, mulFltInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, divIntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, divFltInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, modIntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, addIntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, addFltInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, subIntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, subFltInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, index2StrInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, index2VecInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, log2IntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, log2FltInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, maxIntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, minIntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, powIntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, powFltInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, mulIntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, mulFltInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, divIntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, divFltInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, modIntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, addIntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, addFltInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, subIntInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, subFltInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, index2StrInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, index2VecInt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, log2IntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, log2IntFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, maxIntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, minIntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, powIntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, mulIntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, mulIntFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, divIntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, divIntFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, modIntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, addIntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, addIntFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, subIntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, subIntFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, log2IntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, log2IntFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, maxIntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, minIntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, powIntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, mulIntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, mulIntFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, divIntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, divIntFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, modIntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, addIntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, addIntFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, subIntInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, subIntFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionTJNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTJNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    TerminalNode mUpArg1;
    JunctureNode mUpArg2;
};
template <class Func>
struct FMPMakeExpressionTJ<Func, FltType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionTJ(const TerminalNode& n1, const JunctureNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        switch (func)
        {
        case 0:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, sinFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 1:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cosFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 2:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, tanFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 6:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, lnFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 7:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, log10Flt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 8:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, expFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 9:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, squareFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 10:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cubeFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 11:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, sqrtFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 12:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cbrtFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 13:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, ceilFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 14:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, floorFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 15:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, intFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 16:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, floatFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 17:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, absFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 34:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, subFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, log2IntFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, log2FltFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, maxFltFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, minFltFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, vec2FltFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, mulIntFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, mulFltFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, divIntFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, divFltFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, addIntFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, addFltFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, subIntFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, subFltFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, log2IntFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, log2FltFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, maxFltFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, minFltFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, vec2FltFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, mulIntFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, mulFltFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, divIntFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, divFltFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, addIntFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, addFltFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, subIntFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, subFltFlt, FMPExpressionTJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, log2FltInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, log2FltFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, maxFltFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, minFltFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, vec2FltFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, powFltInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, mulFltInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, mulFltFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, divFltInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, divFltFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, addFltInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, addFltFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, subFltInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, subFltFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, log2FltInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, log2FltFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, maxFltFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, minFltFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, vec2FltFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, powFltInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, mulFltInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, mulFltFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, divFltInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, divFltFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, addFltInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, addFltFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, subFltInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, subFltFlt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionTJNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTJNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    TerminalNode mUpArg1;
    JunctureNode mUpArg2;
};
template <class Func>
struct FMPMakeExpressionTJ<Func, StrType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionTJ(const TerminalNode& n1, const JunctureNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, index2StrInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, index2StrInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionTJNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTJNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    TerminalNode mUpArg1;
    JunctureNode mUpArg2;
};
template <class Func>
struct FMPMakeExpressionTJ<Func, VecType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionTJ(const TerminalNode& n1, const JunctureNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, index2VecInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, index2VecInt, FMPExpressionTJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionTJNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTJNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    TerminalNode mUpArg1;
    JunctureNode mUpArg2;
};
template <class Func>
struct FMPMakeExpressionTJ<Func, MatType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionTJ(const TerminalNode& n1, const JunctureNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionTJNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTJNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    TerminalNode mUpArg1;
    JunctureNode mUpArg2;
};
template <class Func, class ResType = typename Func::RetType>
struct FMPMakeExpressionJT;

template <class Func>
struct FMPMakeExpressionJT<Func, IntType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionJT(const JunctureNode& n1, const TerminalNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        switch (func)
        {
        case 0:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, sinInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 1:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cosInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 2:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, tanInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 6:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, lnInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 7:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, log10Int, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 8:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, expInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 9:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, squareInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 10:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cubeInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 11:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, sqrtInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 12:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cbrtInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 13:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, ceilInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 14:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, floorInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 15:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, intInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 16:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, floatInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 17:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, absInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 34:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, subInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, log2IntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, log2FltInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, maxIntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, minIntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, powIntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, powFltInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, mulIntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, mulFltInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, divIntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, divFltInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, modIntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, addIntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, addFltInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, subIntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, subFltInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, index2StrInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, index2VecInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, log2IntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, log2FltInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, maxIntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, minIntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, powIntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, powFltInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, mulIntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, mulFltInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, divIntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, divFltInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, modIntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, addIntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, addFltInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, subIntInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, subFltInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, index2StrInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, index2VecInt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, log2IntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, log2IntFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, maxIntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, minIntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, powIntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, mulIntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, mulIntFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, divIntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, divIntFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, modIntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, addIntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, addIntFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, subIntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, subIntFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, log2IntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, log2IntFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, maxIntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, minIntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, powIntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, mulIntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, mulIntFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, divIntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, divIntFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, modIntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, addIntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, addIntFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, subIntInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, subIntFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionJTNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJTNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    JunctureNode mUpArg1;
    TerminalNode mUpArg2;
};
template <class Func>
struct FMPMakeExpressionJT<Func, FltType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionJT(const JunctureNode& n1, const TerminalNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        switch (func)
        {
        case 0:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, sinFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 1:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cosFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 2:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, tanFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 6:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, lnFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 7:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, log10Flt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 8:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, expFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 9:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, squareFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 10:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cubeFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 11:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, sqrtFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 12:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cbrtFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 13:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, ceilFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 14:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, floorFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 15:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, intFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 16:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, floatFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 17:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, absFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 34:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, subFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, log2IntFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, log2FltFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, maxFltFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, minFltFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, vec2FltFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, mulIntFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, mulFltFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, divIntFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, divFltFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, addIntFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, addFltFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, subIntFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, subFltFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, log2IntFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, log2FltFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, maxFltFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, minFltFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, vec2FltFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, mulIntFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, mulFltFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, divIntFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, divFltFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, addIntFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, addFltFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, subIntFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, subFltFlt, FMPExpressionJTNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, log2FltInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, log2FltFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, maxFltFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, minFltFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, vec2FltFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, powFltInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, mulFltInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, mulFltFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, divFltInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, divFltFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, addFltInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, addFltFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, subFltInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, subFltFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, log2FltInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, log2FltFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, maxFltFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, minFltFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, vec2FltFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, powFltInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, mulFltInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, mulFltFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, divFltInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, divFltFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, addFltInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, addFltFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, subFltInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, subFltFlt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionJTNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJTNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    JunctureNode mUpArg1;
    TerminalNode mUpArg2;
};
template <class Func>
struct FMPMakeExpressionJT<Func, StrType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionJT(const JunctureNode& n1, const TerminalNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, index2StrInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, index2StrInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionJTNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJTNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    JunctureNode mUpArg1;
    TerminalNode mUpArg2;
};
template <class Func>
struct FMPMakeExpressionJT<Func, VecType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionJT(const JunctureNode& n1, const TerminalNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, index2VecInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, index2VecInt, FMPExpressionJTNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionJTNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJTNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    JunctureNode mUpArg1;
    TerminalNode mUpArg2;
};
template <class Func>
struct FMPMakeExpressionJT<Func, MatType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionJT(const JunctureNode& n1, const TerminalNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionJTNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJTNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    JunctureNode mUpArg1;
    TerminalNode mUpArg2;
};
template <class Func, class ResType = typename Func::RetType>
struct FMPMakeExpressionJJ;

template <class Func>
struct FMPMakeExpressionJJ<Func, IntType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionJJ(const JunctureNode& n1, const JunctureNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        switch (func)
        {
        case 0:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, sinInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 1:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cosInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 2:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, tanInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 6:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, lnInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 7:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, log10Int, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 8:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, expInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 9:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, squareInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 10:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cubeInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 11:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, sqrtInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 12:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, cbrtInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 13:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, ceilInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 14:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, floorInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 15:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, intInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 16:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, floatInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 17:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, absInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 34:
            if (a.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFNode, subInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, log2IntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, log2FltInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, maxIntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, minIntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, powIntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, powFltInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, mulIntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, mulFltInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, divIntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, divFltInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, modIntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, addIntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, addFltInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, subIntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, subFltInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, index2StrInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionTFNode, index2VecInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, log2IntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, log2FltInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, maxIntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, minIntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, powIntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, powFltInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, mulIntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, mulFltInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, divIntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, divFltInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, modIntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, addIntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, addFltInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, subIntInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, subFltInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, index2StrInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionJFNode, index2VecInt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, log2IntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, log2IntFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, maxIntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, minIntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, powIntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, mulIntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, mulIntFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, divIntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, divIntFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, modIntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, addIntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, addIntFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, subIntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, subIntFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, log2IntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, log2IntFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, maxIntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, minIntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, powIntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, mulIntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, mulIntFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, divIntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, divIntFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 38:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, modIntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, addIntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, addIntFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, subIntInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, subIntFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionJJNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJJNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    JunctureNode mUpArg1;
    JunctureNode mUpArg2;
};
template <class Func>
struct FMPMakeExpressionJJ<Func, FltType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionJJ(const JunctureNode& n1, const JunctureNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        switch (func)
        {
        case 0:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, sinFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 1:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cosFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 2:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, tanFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 6:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, lnFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 7:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, log10Flt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 8:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, expFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 9:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, squareFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 10:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cubeFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 11:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, sqrtFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 12:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, cbrtFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 13:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, ceilFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 14:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, floorFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 15:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, intFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 16:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, floatFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 17:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, absFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 34:
            if (a.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFNode, subFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, log2IntFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, log2FltFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, maxFltFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, minFltFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, vec2FltFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, mulIntFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, mulFltFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, divIntFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, divFltFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, addIntFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, addFltFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, subIntFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionTFNode, subFltFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, log2IntFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, log2FltFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, maxFltFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, minFltFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, vec2FltFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 36:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, mulIntFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, mulFltFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 37:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, divIntFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, divFltFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 39:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, addIntFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, addFltFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        case 40:
            if (a.GetType() == VALUE_INT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, subIntFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionJFNode, subFltFlt, FMPExpressionJJNode_impl<Func>>(state, a.GetIndex(state), std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, log2FltInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, log2FltFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, maxFltFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, minFltFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, vec2FltFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, powFltInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, mulFltInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, mulFltFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, divFltInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, divFltFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, addFltInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, addFltFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, subFltInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFTNode, subFltFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 22:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, log2FltInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, log2FltFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 23:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, maxFltFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 24:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, minFltFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 25:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, vec2FltFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 35:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, powFltInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 36:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, mulFltInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, mulFltFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 37:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, divFltInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, divFltFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 39:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, addFltInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, addFltFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        case 40:
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, subFltInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            if (a.GetType() == VALUE_FLT && b.GetType() == VALUE_FLT)
                return MakeExpression<FMPExpressionFJNode, subFltFlt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionJJNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJJNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    JunctureNode mUpArg1;
    JunctureNode mUpArg2;
};
template <class Func>
struct FMPMakeExpressionJJ<Func, StrType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionJJ(const JunctureNode& n1, const JunctureNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, index2StrInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_STR && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, index2StrInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionJJNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJJNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    JunctureNode mUpArg1;
    JunctureNode mUpArg2;
};
template <class Func>
struct FMPMakeExpressionJJ<Func, VecType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionJJ(const JunctureNode& n1, const JunctureNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFTNode, index2VecInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        switch (func)
        {
        case 49:
            if (a.GetType() == VALUE_VEC && b.GetType() == VALUE_INT)
                return MakeExpression<FMPExpressionFJNode, index2VecInt, FMPExpressionJJNode_impl<Func>>(state, std::make_tuple(mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)), b.GetIndex(state));
            break;
        }
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionJJNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJJNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    JunctureNode mUpArg1;
    JunctureNode mUpArg2;
};
template <class Func>
struct FMPMakeExpressionJJ<Func, MatType> : public FMPMakeExpressionBase
{
    FMPMakeExpressionJJ(const JunctureNode& n1, const JunctureNode& n2) : mUpArg1(n1), mUpArg2(n2) {}
    virtual NumericalType GetType() const override { return Func::RetType::label; }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a) override
    {
        (void)state, (void)func, (void)a;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, TerminalNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, JunctureNode& a, FunctionNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, TerminalNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    virtual JunctureNode MakeFunc(ParserState* state, size_t func, FunctionNode& a, JunctureNode& b) override
    {
        (void)state, (void)func, (void)a, (void)b;
        throw InvalidType("");
    }
    JunctureNode Juncturize(ParserState* state)
    {
        using ExpressionNode = FMPExpressionJJNode<Func>;
        return JunctureNode(ExpressionNode::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJJNode<Func>>(state, mUpArg1.GetIndex(state), mUpArg2.GetIndex(state)));
    }
    JunctureNode mUpArg1;
    JunctureNode mUpArg2;
};
inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, TerminalNode& n)
{
    switch (func)
    {
    case 0:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<sinInt>(), func, BoolConstant<sinInt::Upward>(), BoolConstant<sinInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<sinFlt>(), func, BoolConstant<sinFlt::Upward>(), BoolConstant<sinFlt::Downward>(), state, n);
        break;
    case 1:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<cosInt>(), func, BoolConstant<cosInt::Upward>(), BoolConstant<cosInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<cosFlt>(), func, BoolConstant<cosFlt::Upward>(), BoolConstant<cosFlt::Downward>(), state, n);
        break;
    case 2:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<tanInt>(), func, BoolConstant<tanInt::Upward>(), BoolConstant<tanInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<tanFlt>(), func, BoolConstant<tanFlt::Upward>(), BoolConstant<tanFlt::Downward>(), state, n);
        break;
    case 3:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<asinInt>(), func, BoolConstant<asinInt::Upward>(), BoolConstant<asinInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<asinFlt>(), func, BoolConstant<asinFlt::Upward>(), BoolConstant<asinFlt::Downward>(), state, n);
        break;
    case 4:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<acosInt>(), func, BoolConstant<acosInt::Upward>(), BoolConstant<acosInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<acosFlt>(), func, BoolConstant<acosFlt::Upward>(), BoolConstant<acosFlt::Downward>(), state, n);
        break;
    case 5:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<atanInt>(), func, BoolConstant<atanInt::Upward>(), BoolConstant<atanInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<atanFlt>(), func, BoolConstant<atanFlt::Upward>(), BoolConstant<atanFlt::Downward>(), state, n);
        break;
    case 6:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<lnInt>(), func, BoolConstant<lnInt::Upward>(), BoolConstant<lnInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<lnFlt>(), func, BoolConstant<lnFlt::Upward>(), BoolConstant<lnFlt::Downward>(), state, n);
        break;
    case 7:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<log10Int>(), func, BoolConstant<log10Int::Upward>(), BoolConstant<log10Int::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<log10Flt>(), func, BoolConstant<log10Flt::Upward>(), BoolConstant<log10Flt::Downward>(), state, n);
        break;
    case 8:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<expInt>(), func, BoolConstant<expInt::Upward>(), BoolConstant<expInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<expFlt>(), func, BoolConstant<expFlt::Upward>(), BoolConstant<expFlt::Downward>(), state, n);
        break;
    case 9:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<squareInt>(), func, BoolConstant<squareInt::Upward>(), BoolConstant<squareInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<squareFlt>(), func, BoolConstant<squareFlt::Upward>(), BoolConstant<squareFlt::Downward>(), state, n);
        break;
    case 10:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<cubeInt>(), func, BoolConstant<cubeInt::Upward>(), BoolConstant<cubeInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<cubeFlt>(), func, BoolConstant<cubeFlt::Upward>(), BoolConstant<cubeFlt::Downward>(), state, n);
        break;
    case 11:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<sqrtInt>(), func, BoolConstant<sqrtInt::Upward>(), BoolConstant<sqrtInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<sqrtFlt>(), func, BoolConstant<sqrtFlt::Upward>(), BoolConstant<sqrtFlt::Downward>(), state, n);
        break;
    case 12:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<cbrtInt>(), func, BoolConstant<cbrtInt::Upward>(), BoolConstant<cbrtInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<cbrtFlt>(), func, BoolConstant<cbrtFlt::Upward>(), BoolConstant<cbrtFlt::Downward>(), state, n);
        break;
    case 13:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<ceilInt>(), func, BoolConstant<ceilInt::Upward>(), BoolConstant<ceilInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ceilFlt>(), func, BoolConstant<ceilFlt::Upward>(), BoolConstant<ceilFlt::Downward>(), state, n);
        break;
    case 14:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<floorInt>(), func, BoolConstant<floorInt::Upward>(), BoolConstant<floorInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<floorFlt>(), func, BoolConstant<floorFlt::Upward>(), BoolConstant<floorFlt::Downward>(), state, n);
        break;
    case 15:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<intInt>(), func, BoolConstant<intInt::Upward>(), BoolConstant<intInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<intFlt>(), func, BoolConstant<intFlt::Upward>(), BoolConstant<intFlt::Downward>(), state, n);
        break;
    case 16:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<floatInt>(), func, BoolConstant<floatInt::Upward>(), BoolConstant<floatInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<floatFlt>(), func, BoolConstant<floatFlt::Upward>(), BoolConstant<floatFlt::Downward>(), state, n);
        break;
    case 17:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<absInt>(), func, BoolConstant<absInt::Upward>(), BoolConstant<absInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<absFlt>(), func, BoolConstant<absFlt::Upward>(), BoolConstant<absFlt::Downward>(), state, n);
        break;
    case 18:
        if (n.GetType() == VALUE_STR)
            return FunctionNode(Identity<lenStr>(), func, BoolConstant<lenStr::Upward>(), BoolConstant<lenStr::Downward>(), state, n);
        if (n.GetType() == VALUE_VEC)
            return FunctionNode(Identity<lenVec>(), func, BoolConstant<lenVec::Upward>(), BoolConstant<lenVec::Downward>(), state, n);
        break;
    case 19:
        if (n.GetType() == VALUE_MAT)
            return FunctionNode(Identity<transposeMat>(), func, BoolConstant<transposeMat::Upward>(), BoolConstant<transposeMat::Downward>(), state, n);
        break;
    case 20:
        if (n.GetType() == VALUE_MAT)
            return FunctionNode(Identity<traceMat>(), func, BoolConstant<traceMat::Upward>(), BoolConstant<traceMat::Downward>(), state, n);
        break;
    case 34:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<subInt>(), func, BoolConstant<subInt::Upward>(), BoolConstant<subInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<subFlt>(), func, BoolConstant<subFlt::Upward>(), BoolConstant<subFlt::Downward>(), state, n);
        if (n.GetType() == VALUE_VEC)
            return FunctionNode(Identity<subVec>(), func, BoolConstant<subVec::Upward>(), BoolConstant<subVec::Downward>(), state, n);
        if (n.GetType() == VALUE_MAT)
            return FunctionNode(Identity<subMat>(), func, BoolConstant<subMat::Upward>(), BoolConstant<subMat::Downward>(), state, n);
        break;
    }
    throw InvalidType("");
}
inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, FunctionNode& n)
{
    switch (func)
    {
    case 0:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<sinInt>(), func, BoolConstant<sinInt::Upward>(), BoolConstant<sinInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<sinFlt>(), func, BoolConstant<sinFlt::Upward>(), BoolConstant<sinFlt::Downward>(), state, n);
        break;
    case 1:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<cosInt>(), func, BoolConstant<cosInt::Upward>(), BoolConstant<cosInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<cosFlt>(), func, BoolConstant<cosFlt::Upward>(), BoolConstant<cosFlt::Downward>(), state, n);
        break;
    case 2:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<tanInt>(), func, BoolConstant<tanInt::Upward>(), BoolConstant<tanInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<tanFlt>(), func, BoolConstant<tanFlt::Upward>(), BoolConstant<tanFlt::Downward>(), state, n);
        break;
    case 3:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<asinInt>(), func, BoolConstant<asinInt::Upward>(), BoolConstant<asinInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<asinFlt>(), func, BoolConstant<asinFlt::Upward>(), BoolConstant<asinFlt::Downward>(), state, n);
        break;
    case 4:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<acosInt>(), func, BoolConstant<acosInt::Upward>(), BoolConstant<acosInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<acosFlt>(), func, BoolConstant<acosFlt::Upward>(), BoolConstant<acosFlt::Downward>(), state, n);
        break;
    case 5:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<atanInt>(), func, BoolConstant<atanInt::Upward>(), BoolConstant<atanInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<atanFlt>(), func, BoolConstant<atanFlt::Upward>(), BoolConstant<atanFlt::Downward>(), state, n);
        break;
    case 6:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<lnInt>(), func, BoolConstant<lnInt::Upward>(), BoolConstant<lnInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<lnFlt>(), func, BoolConstant<lnFlt::Upward>(), BoolConstant<lnFlt::Downward>(), state, n);
        break;
    case 7:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<log10Int>(), func, BoolConstant<log10Int::Upward>(), BoolConstant<log10Int::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<log10Flt>(), func, BoolConstant<log10Flt::Upward>(), BoolConstant<log10Flt::Downward>(), state, n);
        break;
    case 8:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<expInt>(), func, BoolConstant<expInt::Upward>(), BoolConstant<expInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<expFlt>(), func, BoolConstant<expFlt::Upward>(), BoolConstant<expFlt::Downward>(), state, n);
        break;
    case 9:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<squareInt>(), func, BoolConstant<squareInt::Upward>(), BoolConstant<squareInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<squareFlt>(), func, BoolConstant<squareFlt::Upward>(), BoolConstant<squareFlt::Downward>(), state, n);
        break;
    case 10:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<cubeInt>(), func, BoolConstant<cubeInt::Upward>(), BoolConstant<cubeInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<cubeFlt>(), func, BoolConstant<cubeFlt::Upward>(), BoolConstant<cubeFlt::Downward>(), state, n);
        break;
    case 11:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<sqrtInt>(), func, BoolConstant<sqrtInt::Upward>(), BoolConstant<sqrtInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<sqrtFlt>(), func, BoolConstant<sqrtFlt::Upward>(), BoolConstant<sqrtFlt::Downward>(), state, n);
        break;
    case 12:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<cbrtInt>(), func, BoolConstant<cbrtInt::Upward>(), BoolConstant<cbrtInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<cbrtFlt>(), func, BoolConstant<cbrtFlt::Upward>(), BoolConstant<cbrtFlt::Downward>(), state, n);
        break;
    case 13:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<ceilInt>(), func, BoolConstant<ceilInt::Upward>(), BoolConstant<ceilInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ceilFlt>(), func, BoolConstant<ceilFlt::Upward>(), BoolConstant<ceilFlt::Downward>(), state, n);
        break;
    case 14:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<floorInt>(), func, BoolConstant<floorInt::Upward>(), BoolConstant<floorInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<floorFlt>(), func, BoolConstant<floorFlt::Upward>(), BoolConstant<floorFlt::Downward>(), state, n);
        break;
    case 15:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<intInt>(), func, BoolConstant<intInt::Upward>(), BoolConstant<intInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<intFlt>(), func, BoolConstant<intFlt::Upward>(), BoolConstant<intFlt::Downward>(), state, n);
        break;
    case 16:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<floatInt>(), func, BoolConstant<floatInt::Upward>(), BoolConstant<floatInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<floatFlt>(), func, BoolConstant<floatFlt::Upward>(), BoolConstant<floatFlt::Downward>(), state, n);
        break;
    case 17:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<absInt>(), func, BoolConstant<absInt::Upward>(), BoolConstant<absInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<absFlt>(), func, BoolConstant<absFlt::Upward>(), BoolConstant<absFlt::Downward>(), state, n);
        break;
    case 18:
        if (n.GetType() == VALUE_STR)
            return FunctionNode(Identity<lenStr>(), func, BoolConstant<lenStr::Upward>(), BoolConstant<lenStr::Downward>(), state, n);
        if (n.GetType() == VALUE_VEC)
            return FunctionNode(Identity<lenVec>(), func, BoolConstant<lenVec::Upward>(), BoolConstant<lenVec::Downward>(), state, n);
        break;
    case 19:
        if (n.GetType() == VALUE_MAT)
            return FunctionNode(Identity<transposeMat>(), func, BoolConstant<transposeMat::Upward>(), BoolConstant<transposeMat::Downward>(), state, n);
        break;
    case 20:
        if (n.GetType() == VALUE_MAT)
            return FunctionNode(Identity<traceMat>(), func, BoolConstant<traceMat::Upward>(), BoolConstant<traceMat::Downward>(), state, n);
        break;
    case 34:
        if (n.GetType() == VALUE_INT)
            return FunctionNode(Identity<subInt>(), func, BoolConstant<subInt::Upward>(), BoolConstant<subInt::Downward>(), state, n);
        if (n.GetType() == VALUE_FLT)
            return FunctionNode(Identity<subFlt>(), func, BoolConstant<subFlt::Upward>(), BoolConstant<subFlt::Downward>(), state, n);
        if (n.GetType() == VALUE_VEC)
            return FunctionNode(Identity<subVec>(), func, BoolConstant<subVec::Upward>(), BoolConstant<subVec::Downward>(), state, n);
        if (n.GetType() == VALUE_MAT)
            return FunctionNode(Identity<subMat>(), func, BoolConstant<subMat::Upward>(), BoolConstant<subMat::Downward>(), state, n);
        break;
    }
    throw InvalidType("");
}
inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, TerminalNode& n1, TerminalNode& n2)
{
    switch (func)
    {
    case 21:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<atan2IntInt>(), func, BoolConstant<atan2IntInt::Upward>(), BoolConstant<atan2IntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<atan2IntFlt>(), func, BoolConstant<atan2IntFlt::Upward>(), BoolConstant<atan2IntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<atan2FltInt>(), func, BoolConstant<atan2FltInt::Upward>(), BoolConstant<atan2FltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<atan2FltFlt>(), func, BoolConstant<atan2FltFlt::Upward>(), BoolConstant<atan2FltFlt::Downward>(), state, n1, n2);
        break;
    case 22:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<log2IntInt>(), func, BoolConstant<log2IntInt::Upward>(), BoolConstant<log2IntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<log2IntFlt>(), func, BoolConstant<log2IntFlt::Upward>(), BoolConstant<log2IntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<log2FltInt>(), func, BoolConstant<log2FltInt::Upward>(), BoolConstant<log2FltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<log2FltFlt>(), func, BoolConstant<log2FltFlt::Upward>(), BoolConstant<log2FltFlt::Downward>(), state, n1, n2);
        break;
    case 23:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<maxIntInt>(), func, BoolConstant<maxIntInt::Upward>(), BoolConstant<maxIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<maxFltFlt>(), func, BoolConstant<maxFltFlt::Upward>(), BoolConstant<maxFltFlt::Downward>(), state, n1, n2);
        break;
    case 24:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<minIntInt>(), func, BoolConstant<minIntInt::Upward>(), BoolConstant<minIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<minFltFlt>(), func, BoolConstant<minFltFlt::Upward>(), BoolConstant<minFltFlt::Downward>(), state, n1, n2);
        break;
    case 25:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<vec2FltFlt>(), func, BoolConstant<vec2FltFlt::Upward>(), BoolConstant<vec2FltFlt::Downward>(), state, n1, n2);
        break;
    case 26:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mat2VecVec>(), func, BoolConstant<mat2VecVec::Upward>(), BoolConstant<mat2VecVec::Downward>(), state, n1, n2);
        break;
    case 27:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<diag2FltFlt>(), func, BoolConstant<diag2FltFlt::Upward>(), BoolConstant<diag2FltFlt::Downward>(), state, n1, n2);
        break;
    case 28:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<dotVecVec>(), func, BoolConstant<dotVecVec::Upward>(), BoolConstant<dotVecVec::Downward>(), state, n1, n2);
        break;
    case 29:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<crossVecVec>(), func, BoolConstant<crossVecVec::Upward>(), BoolConstant<crossVecVec::Downward>(), state, n1, n2);
        break;
    case 35:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<powIntInt>(), func, BoolConstant<powIntInt::Upward>(), BoolConstant<powIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<powIntFlt>(), func, BoolConstant<powIntFlt::Upward>(), BoolConstant<powIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<powFltInt>(), func, BoolConstant<powFltInt::Upward>(), BoolConstant<powFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<powFltFlt>(), func, BoolConstant<powFltFlt::Upward>(), BoolConstant<powFltFlt::Downward>(), state, n1, n2);
        break;
    case 36:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<mulIntInt>(), func, BoolConstant<mulIntInt::Upward>(), BoolConstant<mulIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<mulIntFlt>(), func, BoolConstant<mulIntFlt::Upward>(), BoolConstant<mulIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<mulFltInt>(), func, BoolConstant<mulFltInt::Upward>(), BoolConstant<mulFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<mulFltFlt>(), func, BoolConstant<mulFltFlt::Upward>(), BoolConstant<mulFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<mulVecFlt>(), func, BoolConstant<mulVecFlt::Upward>(), BoolConstant<mulVecFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mulFltVec>(), func, BoolConstant<mulFltVec::Upward>(), BoolConstant<mulFltVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<mulMatFlt>(), func, BoolConstant<mulMatFlt::Upward>(), BoolConstant<mulMatFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<mulFltMat>(), func, BoolConstant<mulFltMat::Upward>(), BoolConstant<mulFltMat::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<mulMatMat>(), func, BoolConstant<mulMatMat::Upward>(), BoolConstant<mulMatMat::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mulMatVec>(), func, BoolConstant<mulMatVec::Upward>(), BoolConstant<mulMatVec::Downward>(), state, n1, n2);
        break;
    case 37:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<divIntInt>(), func, BoolConstant<divIntInt::Upward>(), BoolConstant<divIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<divIntFlt>(), func, BoolConstant<divIntFlt::Upward>(), BoolConstant<divIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<divFltInt>(), func, BoolConstant<divFltInt::Upward>(), BoolConstant<divFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<divFltFlt>(), func, BoolConstant<divFltFlt::Upward>(), BoolConstant<divFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<divVecFlt>(), func, BoolConstant<divVecFlt::Upward>(), BoolConstant<divVecFlt::Downward>(), state, n1, n2);
        break;
    case 38:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<modIntInt>(), func, BoolConstant<modIntInt::Upward>(), BoolConstant<modIntInt::Downward>(), state, n1, n2);
        break;
    case 39:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<addIntInt>(), func, BoolConstant<addIntInt::Upward>(), BoolConstant<addIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<addIntFlt>(), func, BoolConstant<addIntFlt::Upward>(), BoolConstant<addIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<addFltInt>(), func, BoolConstant<addFltInt::Upward>(), BoolConstant<addFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<addFltFlt>(), func, BoolConstant<addFltFlt::Upward>(), BoolConstant<addFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_STR && n2.GetType() == VALUE_STR)
            return FunctionNode(Identity<addStrStr>(), func, BoolConstant<addStrStr::Upward>(), BoolConstant<addStrStr::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<addVecVec>(), func, BoolConstant<addVecVec::Upward>(), BoolConstant<addVecVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<addMatMat>(), func, BoolConstant<addMatMat::Upward>(), BoolConstant<addMatMat::Downward>(), state, n1, n2);
        break;
    case 40:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<subIntInt>(), func, BoolConstant<subIntInt::Upward>(), BoolConstant<subIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<subIntFlt>(), func, BoolConstant<subIntFlt::Upward>(), BoolConstant<subIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<subFltInt>(), func, BoolConstant<subFltInt::Upward>(), BoolConstant<subFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<subFltFlt>(), func, BoolConstant<subFltFlt::Upward>(), BoolConstant<subFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<subVecVec>(), func, BoolConstant<subVecVec::Upward>(), BoolConstant<subVecVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<subMatMat>(), func, BoolConstant<subMatMat::Upward>(), BoolConstant<subMatMat::Downward>(), state, n1, n2);
        break;
    case 41:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<gtIntInt>(), func, BoolConstant<gtIntInt::Upward>(), BoolConstant<gtIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<gtIntFlt>(), func, BoolConstant<gtIntFlt::Upward>(), BoolConstant<gtIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<gtFltInt>(), func, BoolConstant<gtFltInt::Upward>(), BoolConstant<gtFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<gtFltFlt>(), func, BoolConstant<gtFltFlt::Upward>(), BoolConstant<gtFltFlt::Downward>(), state, n1, n2);
        break;
    case 42:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<geqIntInt>(), func, BoolConstant<geqIntInt::Upward>(), BoolConstant<geqIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<geqIntFlt>(), func, BoolConstant<geqIntFlt::Upward>(), BoolConstant<geqIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<geqFltInt>(), func, BoolConstant<geqFltInt::Upward>(), BoolConstant<geqFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<geqFltFlt>(), func, BoolConstant<geqFltFlt::Upward>(), BoolConstant<geqFltFlt::Downward>(), state, n1, n2);
        break;
    case 43:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<ltIntInt>(), func, BoolConstant<ltIntInt::Upward>(), BoolConstant<ltIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ltIntFlt>(), func, BoolConstant<ltIntFlt::Upward>(), BoolConstant<ltIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<ltFltInt>(), func, BoolConstant<ltFltInt::Upward>(), BoolConstant<ltFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ltFltFlt>(), func, BoolConstant<ltFltFlt::Upward>(), BoolConstant<ltFltFlt::Downward>(), state, n1, n2);
        break;
    case 44:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<leqIntInt>(), func, BoolConstant<leqIntInt::Upward>(), BoolConstant<leqIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<leqIntFlt>(), func, BoolConstant<leqIntFlt::Upward>(), BoolConstant<leqIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<leqFltInt>(), func, BoolConstant<leqFltInt::Upward>(), BoolConstant<leqFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<leqFltFlt>(), func, BoolConstant<leqFltFlt::Upward>(), BoolConstant<leqFltFlt::Downward>(), state, n1, n2);
        break;
    case 45:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<eqIntInt>(), func, BoolConstant<eqIntInt::Upward>(), BoolConstant<eqIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<eqFltFlt>(), func, BoolConstant<eqFltFlt::Upward>(), BoolConstant<eqFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_STR && n2.GetType() == VALUE_STR)
            return FunctionNode(Identity<eqStrStr>(), func, BoolConstant<eqStrStr::Upward>(), BoolConstant<eqStrStr::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<eqVecVec>(), func, BoolConstant<eqVecVec::Upward>(), BoolConstant<eqVecVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<eqMatMat>(), func, BoolConstant<eqMatMat::Upward>(), BoolConstant<eqMatMat::Downward>(), state, n1, n2);
        break;
    case 46:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<neqIntInt>(), func, BoolConstant<neqIntInt::Upward>(), BoolConstant<neqIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<neqFltFlt>(), func, BoolConstant<neqFltFlt::Upward>(), BoolConstant<neqFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_STR && n2.GetType() == VALUE_STR)
            return FunctionNode(Identity<neqStrStr>(), func, BoolConstant<neqStrStr::Upward>(), BoolConstant<neqStrStr::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<neqVecVec>(), func, BoolConstant<neqVecVec::Upward>(), BoolConstant<neqVecVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<neqMatMat>(), func, BoolConstant<neqMatMat::Upward>(), BoolConstant<neqMatMat::Downward>(), state, n1, n2);
        break;
    case 47:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<andIntInt>(), func, BoolConstant<andIntInt::Upward>(), BoolConstant<andIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<andIntFlt>(), func, BoolConstant<andIntFlt::Upward>(), BoolConstant<andIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<andFltInt>(), func, BoolConstant<andFltInt::Upward>(), BoolConstant<andFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<andFltFlt>(), func, BoolConstant<andFltFlt::Upward>(), BoolConstant<andFltFlt::Downward>(), state, n1, n2);
        break;
    case 48:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<orIntInt>(), func, BoolConstant<orIntInt::Upward>(), BoolConstant<orIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<orIntFlt>(), func, BoolConstant<orIntFlt::Upward>(), BoolConstant<orIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<orFltInt>(), func, BoolConstant<orFltInt::Upward>(), BoolConstant<orFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<orFltFlt>(), func, BoolConstant<orFltFlt::Upward>(), BoolConstant<orFltFlt::Downward>(), state, n1, n2);
        break;
    case 49:
        if (n1.GetType() == VALUE_STR && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<index2StrInt>(), func, BoolConstant<index2StrInt::Upward>(), BoolConstant<index2StrInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<index2VecInt>(), func, BoolConstant<index2VecInt::Upward>(), BoolConstant<index2VecInt::Downward>(), state, n1, n2);
        break;
    }
    throw InvalidType("");
}
inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, TerminalNode& n1, FunctionNode& n2)
{
    switch (func)
    {
    case 21:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<atan2IntInt>(), func, BoolConstant<atan2IntInt::Upward>(), BoolConstant<atan2IntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<atan2IntFlt>(), func, BoolConstant<atan2IntFlt::Upward>(), BoolConstant<atan2IntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<atan2FltInt>(), func, BoolConstant<atan2FltInt::Upward>(), BoolConstant<atan2FltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<atan2FltFlt>(), func, BoolConstant<atan2FltFlt::Upward>(), BoolConstant<atan2FltFlt::Downward>(), state, n1, n2);
        break;
    case 22:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<log2IntInt>(), func, BoolConstant<log2IntInt::Upward>(), BoolConstant<log2IntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<log2IntFlt>(), func, BoolConstant<log2IntFlt::Upward>(), BoolConstant<log2IntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<log2FltInt>(), func, BoolConstant<log2FltInt::Upward>(), BoolConstant<log2FltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<log2FltFlt>(), func, BoolConstant<log2FltFlt::Upward>(), BoolConstant<log2FltFlt::Downward>(), state, n1, n2);
        break;
    case 23:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<maxIntInt>(), func, BoolConstant<maxIntInt::Upward>(), BoolConstant<maxIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<maxFltFlt>(), func, BoolConstant<maxFltFlt::Upward>(), BoolConstant<maxFltFlt::Downward>(), state, n1, n2);
        break;
    case 24:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<minIntInt>(), func, BoolConstant<minIntInt::Upward>(), BoolConstant<minIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<minFltFlt>(), func, BoolConstant<minFltFlt::Upward>(), BoolConstant<minFltFlt::Downward>(), state, n1, n2);
        break;
    case 25:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<vec2FltFlt>(), func, BoolConstant<vec2FltFlt::Upward>(), BoolConstant<vec2FltFlt::Downward>(), state, n1, n2);
        break;
    case 26:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mat2VecVec>(), func, BoolConstant<mat2VecVec::Upward>(), BoolConstant<mat2VecVec::Downward>(), state, n1, n2);
        break;
    case 27:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<diag2FltFlt>(), func, BoolConstant<diag2FltFlt::Upward>(), BoolConstant<diag2FltFlt::Downward>(), state, n1, n2);
        break;
    case 28:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<dotVecVec>(), func, BoolConstant<dotVecVec::Upward>(), BoolConstant<dotVecVec::Downward>(), state, n1, n2);
        break;
    case 29:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<crossVecVec>(), func, BoolConstant<crossVecVec::Upward>(), BoolConstant<crossVecVec::Downward>(), state, n1, n2);
        break;
    case 35:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<powIntInt>(), func, BoolConstant<powIntInt::Upward>(), BoolConstant<powIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<powIntFlt>(), func, BoolConstant<powIntFlt::Upward>(), BoolConstant<powIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<powFltInt>(), func, BoolConstant<powFltInt::Upward>(), BoolConstant<powFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<powFltFlt>(), func, BoolConstant<powFltFlt::Upward>(), BoolConstant<powFltFlt::Downward>(), state, n1, n2);
        break;
    case 36:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<mulIntInt>(), func, BoolConstant<mulIntInt::Upward>(), BoolConstant<mulIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<mulIntFlt>(), func, BoolConstant<mulIntFlt::Upward>(), BoolConstant<mulIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<mulFltInt>(), func, BoolConstant<mulFltInt::Upward>(), BoolConstant<mulFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<mulFltFlt>(), func, BoolConstant<mulFltFlt::Upward>(), BoolConstant<mulFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<mulVecFlt>(), func, BoolConstant<mulVecFlt::Upward>(), BoolConstant<mulVecFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mulFltVec>(), func, BoolConstant<mulFltVec::Upward>(), BoolConstant<mulFltVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<mulMatFlt>(), func, BoolConstant<mulMatFlt::Upward>(), BoolConstant<mulMatFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<mulFltMat>(), func, BoolConstant<mulFltMat::Upward>(), BoolConstant<mulFltMat::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<mulMatMat>(), func, BoolConstant<mulMatMat::Upward>(), BoolConstant<mulMatMat::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mulMatVec>(), func, BoolConstant<mulMatVec::Upward>(), BoolConstant<mulMatVec::Downward>(), state, n1, n2);
        break;
    case 37:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<divIntInt>(), func, BoolConstant<divIntInt::Upward>(), BoolConstant<divIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<divIntFlt>(), func, BoolConstant<divIntFlt::Upward>(), BoolConstant<divIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<divFltInt>(), func, BoolConstant<divFltInt::Upward>(), BoolConstant<divFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<divFltFlt>(), func, BoolConstant<divFltFlt::Upward>(), BoolConstant<divFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<divVecFlt>(), func, BoolConstant<divVecFlt::Upward>(), BoolConstant<divVecFlt::Downward>(), state, n1, n2);
        break;
    case 38:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<modIntInt>(), func, BoolConstant<modIntInt::Upward>(), BoolConstant<modIntInt::Downward>(), state, n1, n2);
        break;
    case 39:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<addIntInt>(), func, BoolConstant<addIntInt::Upward>(), BoolConstant<addIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<addIntFlt>(), func, BoolConstant<addIntFlt::Upward>(), BoolConstant<addIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<addFltInt>(), func, BoolConstant<addFltInt::Upward>(), BoolConstant<addFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<addFltFlt>(), func, BoolConstant<addFltFlt::Upward>(), BoolConstant<addFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_STR && n2.GetType() == VALUE_STR)
            return FunctionNode(Identity<addStrStr>(), func, BoolConstant<addStrStr::Upward>(), BoolConstant<addStrStr::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<addVecVec>(), func, BoolConstant<addVecVec::Upward>(), BoolConstant<addVecVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<addMatMat>(), func, BoolConstant<addMatMat::Upward>(), BoolConstant<addMatMat::Downward>(), state, n1, n2);
        break;
    case 40:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<subIntInt>(), func, BoolConstant<subIntInt::Upward>(), BoolConstant<subIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<subIntFlt>(), func, BoolConstant<subIntFlt::Upward>(), BoolConstant<subIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<subFltInt>(), func, BoolConstant<subFltInt::Upward>(), BoolConstant<subFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<subFltFlt>(), func, BoolConstant<subFltFlt::Upward>(), BoolConstant<subFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<subVecVec>(), func, BoolConstant<subVecVec::Upward>(), BoolConstant<subVecVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<subMatMat>(), func, BoolConstant<subMatMat::Upward>(), BoolConstant<subMatMat::Downward>(), state, n1, n2);
        break;
    case 41:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<gtIntInt>(), func, BoolConstant<gtIntInt::Upward>(), BoolConstant<gtIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<gtIntFlt>(), func, BoolConstant<gtIntFlt::Upward>(), BoolConstant<gtIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<gtFltInt>(), func, BoolConstant<gtFltInt::Upward>(), BoolConstant<gtFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<gtFltFlt>(), func, BoolConstant<gtFltFlt::Upward>(), BoolConstant<gtFltFlt::Downward>(), state, n1, n2);
        break;
    case 42:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<geqIntInt>(), func, BoolConstant<geqIntInt::Upward>(), BoolConstant<geqIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<geqIntFlt>(), func, BoolConstant<geqIntFlt::Upward>(), BoolConstant<geqIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<geqFltInt>(), func, BoolConstant<geqFltInt::Upward>(), BoolConstant<geqFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<geqFltFlt>(), func, BoolConstant<geqFltFlt::Upward>(), BoolConstant<geqFltFlt::Downward>(), state, n1, n2);
        break;
    case 43:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<ltIntInt>(), func, BoolConstant<ltIntInt::Upward>(), BoolConstant<ltIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ltIntFlt>(), func, BoolConstant<ltIntFlt::Upward>(), BoolConstant<ltIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<ltFltInt>(), func, BoolConstant<ltFltInt::Upward>(), BoolConstant<ltFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ltFltFlt>(), func, BoolConstant<ltFltFlt::Upward>(), BoolConstant<ltFltFlt::Downward>(), state, n1, n2);
        break;
    case 44:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<leqIntInt>(), func, BoolConstant<leqIntInt::Upward>(), BoolConstant<leqIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<leqIntFlt>(), func, BoolConstant<leqIntFlt::Upward>(), BoolConstant<leqIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<leqFltInt>(), func, BoolConstant<leqFltInt::Upward>(), BoolConstant<leqFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<leqFltFlt>(), func, BoolConstant<leqFltFlt::Upward>(), BoolConstant<leqFltFlt::Downward>(), state, n1, n2);
        break;
    case 45:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<eqIntInt>(), func, BoolConstant<eqIntInt::Upward>(), BoolConstant<eqIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<eqFltFlt>(), func, BoolConstant<eqFltFlt::Upward>(), BoolConstant<eqFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_STR && n2.GetType() == VALUE_STR)
            return FunctionNode(Identity<eqStrStr>(), func, BoolConstant<eqStrStr::Upward>(), BoolConstant<eqStrStr::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<eqVecVec>(), func, BoolConstant<eqVecVec::Upward>(), BoolConstant<eqVecVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<eqMatMat>(), func, BoolConstant<eqMatMat::Upward>(), BoolConstant<eqMatMat::Downward>(), state, n1, n2);
        break;
    case 46:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<neqIntInt>(), func, BoolConstant<neqIntInt::Upward>(), BoolConstant<neqIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<neqFltFlt>(), func, BoolConstant<neqFltFlt::Upward>(), BoolConstant<neqFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_STR && n2.GetType() == VALUE_STR)
            return FunctionNode(Identity<neqStrStr>(), func, BoolConstant<neqStrStr::Upward>(), BoolConstant<neqStrStr::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<neqVecVec>(), func, BoolConstant<neqVecVec::Upward>(), BoolConstant<neqVecVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<neqMatMat>(), func, BoolConstant<neqMatMat::Upward>(), BoolConstant<neqMatMat::Downward>(), state, n1, n2);
        break;
    case 47:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<andIntInt>(), func, BoolConstant<andIntInt::Upward>(), BoolConstant<andIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<andIntFlt>(), func, BoolConstant<andIntFlt::Upward>(), BoolConstant<andIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<andFltInt>(), func, BoolConstant<andFltInt::Upward>(), BoolConstant<andFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<andFltFlt>(), func, BoolConstant<andFltFlt::Upward>(), BoolConstant<andFltFlt::Downward>(), state, n1, n2);
        break;
    case 48:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<orIntInt>(), func, BoolConstant<orIntInt::Upward>(), BoolConstant<orIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<orIntFlt>(), func, BoolConstant<orIntFlt::Upward>(), BoolConstant<orIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<orFltInt>(), func, BoolConstant<orFltInt::Upward>(), BoolConstant<orFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<orFltFlt>(), func, BoolConstant<orFltFlt::Upward>(), BoolConstant<orFltFlt::Downward>(), state, n1, n2);
        break;
    case 49:
        if (n1.GetType() == VALUE_STR && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<index2StrInt>(), func, BoolConstant<index2StrInt::Upward>(), BoolConstant<index2StrInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<index2VecInt>(), func, BoolConstant<index2VecInt::Upward>(), BoolConstant<index2VecInt::Downward>(), state, n1, n2);
        break;
    }
    throw InvalidType("");
}
inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, FunctionNode& n1, TerminalNode& n2)
{
    switch (func)
    {
    case 21:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<atan2IntInt>(), func, BoolConstant<atan2IntInt::Upward>(), BoolConstant<atan2IntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<atan2IntFlt>(), func, BoolConstant<atan2IntFlt::Upward>(), BoolConstant<atan2IntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<atan2FltInt>(), func, BoolConstant<atan2FltInt::Upward>(), BoolConstant<atan2FltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<atan2FltFlt>(), func, BoolConstant<atan2FltFlt::Upward>(), BoolConstant<atan2FltFlt::Downward>(), state, n1, n2);
        break;
    case 22:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<log2IntInt>(), func, BoolConstant<log2IntInt::Upward>(), BoolConstant<log2IntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<log2IntFlt>(), func, BoolConstant<log2IntFlt::Upward>(), BoolConstant<log2IntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<log2FltInt>(), func, BoolConstant<log2FltInt::Upward>(), BoolConstant<log2FltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<log2FltFlt>(), func, BoolConstant<log2FltFlt::Upward>(), BoolConstant<log2FltFlt::Downward>(), state, n1, n2);
        break;
    case 23:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<maxIntInt>(), func, BoolConstant<maxIntInt::Upward>(), BoolConstant<maxIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<maxFltFlt>(), func, BoolConstant<maxFltFlt::Upward>(), BoolConstant<maxFltFlt::Downward>(), state, n1, n2);
        break;
    case 24:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<minIntInt>(), func, BoolConstant<minIntInt::Upward>(), BoolConstant<minIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<minFltFlt>(), func, BoolConstant<minFltFlt::Upward>(), BoolConstant<minFltFlt::Downward>(), state, n1, n2);
        break;
    case 25:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<vec2FltFlt>(), func, BoolConstant<vec2FltFlt::Upward>(), BoolConstant<vec2FltFlt::Downward>(), state, n1, n2);
        break;
    case 26:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mat2VecVec>(), func, BoolConstant<mat2VecVec::Upward>(), BoolConstant<mat2VecVec::Downward>(), state, n1, n2);
        break;
    case 27:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<diag2FltFlt>(), func, BoolConstant<diag2FltFlt::Upward>(), BoolConstant<diag2FltFlt::Downward>(), state, n1, n2);
        break;
    case 28:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<dotVecVec>(), func, BoolConstant<dotVecVec::Upward>(), BoolConstant<dotVecVec::Downward>(), state, n1, n2);
        break;
    case 29:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<crossVecVec>(), func, BoolConstant<crossVecVec::Upward>(), BoolConstant<crossVecVec::Downward>(), state, n1, n2);
        break;
    case 35:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<powIntInt>(), func, BoolConstant<powIntInt::Upward>(), BoolConstant<powIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<powIntFlt>(), func, BoolConstant<powIntFlt::Upward>(), BoolConstant<powIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<powFltInt>(), func, BoolConstant<powFltInt::Upward>(), BoolConstant<powFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<powFltFlt>(), func, BoolConstant<powFltFlt::Upward>(), BoolConstant<powFltFlt::Downward>(), state, n1, n2);
        break;
    case 36:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<mulIntInt>(), func, BoolConstant<mulIntInt::Upward>(), BoolConstant<mulIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<mulIntFlt>(), func, BoolConstant<mulIntFlt::Upward>(), BoolConstant<mulIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<mulFltInt>(), func, BoolConstant<mulFltInt::Upward>(), BoolConstant<mulFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<mulFltFlt>(), func, BoolConstant<mulFltFlt::Upward>(), BoolConstant<mulFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<mulVecFlt>(), func, BoolConstant<mulVecFlt::Upward>(), BoolConstant<mulVecFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mulFltVec>(), func, BoolConstant<mulFltVec::Upward>(), BoolConstant<mulFltVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<mulMatFlt>(), func, BoolConstant<mulMatFlt::Upward>(), BoolConstant<mulMatFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<mulFltMat>(), func, BoolConstant<mulFltMat::Upward>(), BoolConstant<mulFltMat::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<mulMatMat>(), func, BoolConstant<mulMatMat::Upward>(), BoolConstant<mulMatMat::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mulMatVec>(), func, BoolConstant<mulMatVec::Upward>(), BoolConstant<mulMatVec::Downward>(), state, n1, n2);
        break;
    case 37:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<divIntInt>(), func, BoolConstant<divIntInt::Upward>(), BoolConstant<divIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<divIntFlt>(), func, BoolConstant<divIntFlt::Upward>(), BoolConstant<divIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<divFltInt>(), func, BoolConstant<divFltInt::Upward>(), BoolConstant<divFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<divFltFlt>(), func, BoolConstant<divFltFlt::Upward>(), BoolConstant<divFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<divVecFlt>(), func, BoolConstant<divVecFlt::Upward>(), BoolConstant<divVecFlt::Downward>(), state, n1, n2);
        break;
    case 38:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<modIntInt>(), func, BoolConstant<modIntInt::Upward>(), BoolConstant<modIntInt::Downward>(), state, n1, n2);
        break;
    case 39:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<addIntInt>(), func, BoolConstant<addIntInt::Upward>(), BoolConstant<addIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<addIntFlt>(), func, BoolConstant<addIntFlt::Upward>(), BoolConstant<addIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<addFltInt>(), func, BoolConstant<addFltInt::Upward>(), BoolConstant<addFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<addFltFlt>(), func, BoolConstant<addFltFlt::Upward>(), BoolConstant<addFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_STR && n2.GetType() == VALUE_STR)
            return FunctionNode(Identity<addStrStr>(), func, BoolConstant<addStrStr::Upward>(), BoolConstant<addStrStr::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<addVecVec>(), func, BoolConstant<addVecVec::Upward>(), BoolConstant<addVecVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<addMatMat>(), func, BoolConstant<addMatMat::Upward>(), BoolConstant<addMatMat::Downward>(), state, n1, n2);
        break;
    case 40:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<subIntInt>(), func, BoolConstant<subIntInt::Upward>(), BoolConstant<subIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<subIntFlt>(), func, BoolConstant<subIntFlt::Upward>(), BoolConstant<subIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<subFltInt>(), func, BoolConstant<subFltInt::Upward>(), BoolConstant<subFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<subFltFlt>(), func, BoolConstant<subFltFlt::Upward>(), BoolConstant<subFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<subVecVec>(), func, BoolConstant<subVecVec::Upward>(), BoolConstant<subVecVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<subMatMat>(), func, BoolConstant<subMatMat::Upward>(), BoolConstant<subMatMat::Downward>(), state, n1, n2);
        break;
    case 41:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<gtIntInt>(), func, BoolConstant<gtIntInt::Upward>(), BoolConstant<gtIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<gtIntFlt>(), func, BoolConstant<gtIntFlt::Upward>(), BoolConstant<gtIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<gtFltInt>(), func, BoolConstant<gtFltInt::Upward>(), BoolConstant<gtFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<gtFltFlt>(), func, BoolConstant<gtFltFlt::Upward>(), BoolConstant<gtFltFlt::Downward>(), state, n1, n2);
        break;
    case 42:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<geqIntInt>(), func, BoolConstant<geqIntInt::Upward>(), BoolConstant<geqIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<geqIntFlt>(), func, BoolConstant<geqIntFlt::Upward>(), BoolConstant<geqIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<geqFltInt>(), func, BoolConstant<geqFltInt::Upward>(), BoolConstant<geqFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<geqFltFlt>(), func, BoolConstant<geqFltFlt::Upward>(), BoolConstant<geqFltFlt::Downward>(), state, n1, n2);
        break;
    case 43:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<ltIntInt>(), func, BoolConstant<ltIntInt::Upward>(), BoolConstant<ltIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ltIntFlt>(), func, BoolConstant<ltIntFlt::Upward>(), BoolConstant<ltIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<ltFltInt>(), func, BoolConstant<ltFltInt::Upward>(), BoolConstant<ltFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ltFltFlt>(), func, BoolConstant<ltFltFlt::Upward>(), BoolConstant<ltFltFlt::Downward>(), state, n1, n2);
        break;
    case 44:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<leqIntInt>(), func, BoolConstant<leqIntInt::Upward>(), BoolConstant<leqIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<leqIntFlt>(), func, BoolConstant<leqIntFlt::Upward>(), BoolConstant<leqIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<leqFltInt>(), func, BoolConstant<leqFltInt::Upward>(), BoolConstant<leqFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<leqFltFlt>(), func, BoolConstant<leqFltFlt::Upward>(), BoolConstant<leqFltFlt::Downward>(), state, n1, n2);
        break;
    case 45:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<eqIntInt>(), func, BoolConstant<eqIntInt::Upward>(), BoolConstant<eqIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<eqFltFlt>(), func, BoolConstant<eqFltFlt::Upward>(), BoolConstant<eqFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_STR && n2.GetType() == VALUE_STR)
            return FunctionNode(Identity<eqStrStr>(), func, BoolConstant<eqStrStr::Upward>(), BoolConstant<eqStrStr::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<eqVecVec>(), func, BoolConstant<eqVecVec::Upward>(), BoolConstant<eqVecVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<eqMatMat>(), func, BoolConstant<eqMatMat::Upward>(), BoolConstant<eqMatMat::Downward>(), state, n1, n2);
        break;
    case 46:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<neqIntInt>(), func, BoolConstant<neqIntInt::Upward>(), BoolConstant<neqIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<neqFltFlt>(), func, BoolConstant<neqFltFlt::Upward>(), BoolConstant<neqFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_STR && n2.GetType() == VALUE_STR)
            return FunctionNode(Identity<neqStrStr>(), func, BoolConstant<neqStrStr::Upward>(), BoolConstant<neqStrStr::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<neqVecVec>(), func, BoolConstant<neqVecVec::Upward>(), BoolConstant<neqVecVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<neqMatMat>(), func, BoolConstant<neqMatMat::Upward>(), BoolConstant<neqMatMat::Downward>(), state, n1, n2);
        break;
    case 47:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<andIntInt>(), func, BoolConstant<andIntInt::Upward>(), BoolConstant<andIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<andIntFlt>(), func, BoolConstant<andIntFlt::Upward>(), BoolConstant<andIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<andFltInt>(), func, BoolConstant<andFltInt::Upward>(), BoolConstant<andFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<andFltFlt>(), func, BoolConstant<andFltFlt::Upward>(), BoolConstant<andFltFlt::Downward>(), state, n1, n2);
        break;
    case 48:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<orIntInt>(), func, BoolConstant<orIntInt::Upward>(), BoolConstant<orIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<orIntFlt>(), func, BoolConstant<orIntFlt::Upward>(), BoolConstant<orIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<orFltInt>(), func, BoolConstant<orFltInt::Upward>(), BoolConstant<orFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<orFltFlt>(), func, BoolConstant<orFltFlt::Upward>(), BoolConstant<orFltFlt::Downward>(), state, n1, n2);
        break;
    case 49:
        if (n1.GetType() == VALUE_STR && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<index2StrInt>(), func, BoolConstant<index2StrInt::Upward>(), BoolConstant<index2StrInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<index2VecInt>(), func, BoolConstant<index2VecInt::Upward>(), BoolConstant<index2VecInt::Downward>(), state, n1, n2);
        break;
    }
    throw InvalidType("");
}
inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, FunctionNode& n1, FunctionNode& n2)
{
    switch (func)
    {
    case 21:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<atan2IntInt>(), func, BoolConstant<atan2IntInt::Upward>(), BoolConstant<atan2IntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<atan2IntFlt>(), func, BoolConstant<atan2IntFlt::Upward>(), BoolConstant<atan2IntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<atan2FltInt>(), func, BoolConstant<atan2FltInt::Upward>(), BoolConstant<atan2FltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<atan2FltFlt>(), func, BoolConstant<atan2FltFlt::Upward>(), BoolConstant<atan2FltFlt::Downward>(), state, n1, n2);
        break;
    case 22:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<log2IntInt>(), func, BoolConstant<log2IntInt::Upward>(), BoolConstant<log2IntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<log2IntFlt>(), func, BoolConstant<log2IntFlt::Upward>(), BoolConstant<log2IntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<log2FltInt>(), func, BoolConstant<log2FltInt::Upward>(), BoolConstant<log2FltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<log2FltFlt>(), func, BoolConstant<log2FltFlt::Upward>(), BoolConstant<log2FltFlt::Downward>(), state, n1, n2);
        break;
    case 23:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<maxIntInt>(), func, BoolConstant<maxIntInt::Upward>(), BoolConstant<maxIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<maxFltFlt>(), func, BoolConstant<maxFltFlt::Upward>(), BoolConstant<maxFltFlt::Downward>(), state, n1, n2);
        break;
    case 24:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<minIntInt>(), func, BoolConstant<minIntInt::Upward>(), BoolConstant<minIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<minFltFlt>(), func, BoolConstant<minFltFlt::Upward>(), BoolConstant<minFltFlt::Downward>(), state, n1, n2);
        break;
    case 25:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<vec2FltFlt>(), func, BoolConstant<vec2FltFlt::Upward>(), BoolConstant<vec2FltFlt::Downward>(), state, n1, n2);
        break;
    case 26:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mat2VecVec>(), func, BoolConstant<mat2VecVec::Upward>(), BoolConstant<mat2VecVec::Downward>(), state, n1, n2);
        break;
    case 27:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<diag2FltFlt>(), func, BoolConstant<diag2FltFlt::Upward>(), BoolConstant<diag2FltFlt::Downward>(), state, n1, n2);
        break;
    case 28:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<dotVecVec>(), func, BoolConstant<dotVecVec::Upward>(), BoolConstant<dotVecVec::Downward>(), state, n1, n2);
        break;
    case 29:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<crossVecVec>(), func, BoolConstant<crossVecVec::Upward>(), BoolConstant<crossVecVec::Downward>(), state, n1, n2);
        break;
    case 35:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<powIntInt>(), func, BoolConstant<powIntInt::Upward>(), BoolConstant<powIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<powIntFlt>(), func, BoolConstant<powIntFlt::Upward>(), BoolConstant<powIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<powFltInt>(), func, BoolConstant<powFltInt::Upward>(), BoolConstant<powFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<powFltFlt>(), func, BoolConstant<powFltFlt::Upward>(), BoolConstant<powFltFlt::Downward>(), state, n1, n2);
        break;
    case 36:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<mulIntInt>(), func, BoolConstant<mulIntInt::Upward>(), BoolConstant<mulIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<mulIntFlt>(), func, BoolConstant<mulIntFlt::Upward>(), BoolConstant<mulIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<mulFltInt>(), func, BoolConstant<mulFltInt::Upward>(), BoolConstant<mulFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<mulFltFlt>(), func, BoolConstant<mulFltFlt::Upward>(), BoolConstant<mulFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<mulVecFlt>(), func, BoolConstant<mulVecFlt::Upward>(), BoolConstant<mulVecFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mulFltVec>(), func, BoolConstant<mulFltVec::Upward>(), BoolConstant<mulFltVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<mulMatFlt>(), func, BoolConstant<mulMatFlt::Upward>(), BoolConstant<mulMatFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<mulFltMat>(), func, BoolConstant<mulFltMat::Upward>(), BoolConstant<mulFltMat::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<mulMatMat>(), func, BoolConstant<mulMatMat::Upward>(), BoolConstant<mulMatMat::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mulMatVec>(), func, BoolConstant<mulMatVec::Upward>(), BoolConstant<mulMatVec::Downward>(), state, n1, n2);
        break;
    case 37:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<divIntInt>(), func, BoolConstant<divIntInt::Upward>(), BoolConstant<divIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<divIntFlt>(), func, BoolConstant<divIntFlt::Upward>(), BoolConstant<divIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<divFltInt>(), func, BoolConstant<divFltInt::Upward>(), BoolConstant<divFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<divFltFlt>(), func, BoolConstant<divFltFlt::Upward>(), BoolConstant<divFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<divVecFlt>(), func, BoolConstant<divVecFlt::Upward>(), BoolConstant<divVecFlt::Downward>(), state, n1, n2);
        break;
    case 38:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<modIntInt>(), func, BoolConstant<modIntInt::Upward>(), BoolConstant<modIntInt::Downward>(), state, n1, n2);
        break;
    case 39:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<addIntInt>(), func, BoolConstant<addIntInt::Upward>(), BoolConstant<addIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<addIntFlt>(), func, BoolConstant<addIntFlt::Upward>(), BoolConstant<addIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<addFltInt>(), func, BoolConstant<addFltInt::Upward>(), BoolConstant<addFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<addFltFlt>(), func, BoolConstant<addFltFlt::Upward>(), BoolConstant<addFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_STR && n2.GetType() == VALUE_STR)
            return FunctionNode(Identity<addStrStr>(), func, BoolConstant<addStrStr::Upward>(), BoolConstant<addStrStr::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<addVecVec>(), func, BoolConstant<addVecVec::Upward>(), BoolConstant<addVecVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<addMatMat>(), func, BoolConstant<addMatMat::Upward>(), BoolConstant<addMatMat::Downward>(), state, n1, n2);
        break;
    case 40:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<subIntInt>(), func, BoolConstant<subIntInt::Upward>(), BoolConstant<subIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<subIntFlt>(), func, BoolConstant<subIntFlt::Upward>(), BoolConstant<subIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<subFltInt>(), func, BoolConstant<subFltInt::Upward>(), BoolConstant<subFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<subFltFlt>(), func, BoolConstant<subFltFlt::Upward>(), BoolConstant<subFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<subVecVec>(), func, BoolConstant<subVecVec::Upward>(), BoolConstant<subVecVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<subMatMat>(), func, BoolConstant<subMatMat::Upward>(), BoolConstant<subMatMat::Downward>(), state, n1, n2);
        break;
    case 41:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<gtIntInt>(), func, BoolConstant<gtIntInt::Upward>(), BoolConstant<gtIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<gtIntFlt>(), func, BoolConstant<gtIntFlt::Upward>(), BoolConstant<gtIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<gtFltInt>(), func, BoolConstant<gtFltInt::Upward>(), BoolConstant<gtFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<gtFltFlt>(), func, BoolConstant<gtFltFlt::Upward>(), BoolConstant<gtFltFlt::Downward>(), state, n1, n2);
        break;
    case 42:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<geqIntInt>(), func, BoolConstant<geqIntInt::Upward>(), BoolConstant<geqIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<geqIntFlt>(), func, BoolConstant<geqIntFlt::Upward>(), BoolConstant<geqIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<geqFltInt>(), func, BoolConstant<geqFltInt::Upward>(), BoolConstant<geqFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<geqFltFlt>(), func, BoolConstant<geqFltFlt::Upward>(), BoolConstant<geqFltFlt::Downward>(), state, n1, n2);
        break;
    case 43:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<ltIntInt>(), func, BoolConstant<ltIntInt::Upward>(), BoolConstant<ltIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ltIntFlt>(), func, BoolConstant<ltIntFlt::Upward>(), BoolConstant<ltIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<ltFltInt>(), func, BoolConstant<ltFltInt::Upward>(), BoolConstant<ltFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ltFltFlt>(), func, BoolConstant<ltFltFlt::Upward>(), BoolConstant<ltFltFlt::Downward>(), state, n1, n2);
        break;
    case 44:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<leqIntInt>(), func, BoolConstant<leqIntInt::Upward>(), BoolConstant<leqIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<leqIntFlt>(), func, BoolConstant<leqIntFlt::Upward>(), BoolConstant<leqIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<leqFltInt>(), func, BoolConstant<leqFltInt::Upward>(), BoolConstant<leqFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<leqFltFlt>(), func, BoolConstant<leqFltFlt::Upward>(), BoolConstant<leqFltFlt::Downward>(), state, n1, n2);
        break;
    case 45:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<eqIntInt>(), func, BoolConstant<eqIntInt::Upward>(), BoolConstant<eqIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<eqFltFlt>(), func, BoolConstant<eqFltFlt::Upward>(), BoolConstant<eqFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_STR && n2.GetType() == VALUE_STR)
            return FunctionNode(Identity<eqStrStr>(), func, BoolConstant<eqStrStr::Upward>(), BoolConstant<eqStrStr::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<eqVecVec>(), func, BoolConstant<eqVecVec::Upward>(), BoolConstant<eqVecVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<eqMatMat>(), func, BoolConstant<eqMatMat::Upward>(), BoolConstant<eqMatMat::Downward>(), state, n1, n2);
        break;
    case 46:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<neqIntInt>(), func, BoolConstant<neqIntInt::Upward>(), BoolConstant<neqIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<neqFltFlt>(), func, BoolConstant<neqFltFlt::Upward>(), BoolConstant<neqFltFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_STR && n2.GetType() == VALUE_STR)
            return FunctionNode(Identity<neqStrStr>(), func, BoolConstant<neqStrStr::Upward>(), BoolConstant<neqStrStr::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC)
            return FunctionNode(Identity<neqVecVec>(), func, BoolConstant<neqVecVec::Upward>(), BoolConstant<neqVecVec::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_MAT)
            return FunctionNode(Identity<neqMatMat>(), func, BoolConstant<neqMatMat::Upward>(), BoolConstant<neqMatMat::Downward>(), state, n1, n2);
        break;
    case 47:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<andIntInt>(), func, BoolConstant<andIntInt::Upward>(), BoolConstant<andIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<andIntFlt>(), func, BoolConstant<andIntFlt::Upward>(), BoolConstant<andIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<andFltInt>(), func, BoolConstant<andFltInt::Upward>(), BoolConstant<andFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<andFltFlt>(), func, BoolConstant<andFltFlt::Upward>(), BoolConstant<andFltFlt::Downward>(), state, n1, n2);
        break;
    case 48:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<orIntInt>(), func, BoolConstant<orIntInt::Upward>(), BoolConstant<orIntInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<orIntFlt>(), func, BoolConstant<orIntFlt::Upward>(), BoolConstant<orIntFlt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<orFltInt>(), func, BoolConstant<orFltInt::Upward>(), BoolConstant<orFltInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT)
            return FunctionNode(Identity<orFltFlt>(), func, BoolConstant<orFltFlt::Upward>(), BoolConstant<orFltFlt::Downward>(), state, n1, n2);
        break;
    case 49:
        if (n1.GetType() == VALUE_STR && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<index2StrInt>(), func, BoolConstant<index2StrInt::Upward>(), BoolConstant<index2StrInt::Downward>(), state, n1, n2);
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_INT)
            return FunctionNode(Identity<index2VecInt>(), func, BoolConstant<index2VecInt::Upward>(), BoolConstant<index2VecInt::Downward>(), state, n1, n2);
        break;
    }
    throw InvalidType("");
}
inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, TerminalNode& n1, TerminalNode& n2, TerminalNode& n3)
{
    switch (func)
    {
    case 30:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT && n3.GetType() == VALUE_INT)
            return FunctionNode(Identity<ifIntIntInt>(), func, BoolConstant<ifIntIntInt::Upward>(), BoolConstant<ifIntIntInt::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ifIntFltFlt>(), func, BoolConstant<ifIntFltFlt::Upward>(), BoolConstant<ifIntFltFlt::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_STR && n3.GetType() == VALUE_STR)
            return FunctionNode(Identity<ifIntStrStr>(), func, BoolConstant<ifIntStrStr::Upward>(), BoolConstant<ifIntStrStr::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_VEC && n3.GetType() == VALUE_VEC)
            return FunctionNode(Identity<ifIntVecVec>(), func, BoolConstant<ifIntVecVec::Upward>(), BoolConstant<ifIntVecVec::Downward>(), state, n1, n2, n3);
        break;
    case 31:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<vec3FltFltFlt>(), func, BoolConstant<vec3FltFltFlt::Upward>(), BoolConstant<vec3FltFltFlt::Downward>(), state, n1, n2, n3);
        break;
    case 32:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC && n3.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mat3VecVecVec>(), func, BoolConstant<mat3VecVecVec::Upward>(), BoolConstant<mat3VecVecVec::Downward>(), state, n1, n2, n3);
        break;
    case 33:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<diag3FltFltFlt>(), func, BoolConstant<diag3FltFltFlt::Upward>(), BoolConstant<diag3FltFltFlt::Downward>(), state, n1, n2, n3);
        break;
    case 50:
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_INT && n3.GetType() == VALUE_INT)
            return FunctionNode(Identity<index3MatIntInt>(), func, BoolConstant<index3MatIntInt::Upward>(), BoolConstant<index3MatIntInt::Downward>(), state, n1, n2, n3);
        break;
    }
    throw InvalidType("");
}
inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, TerminalNode& n1, TerminalNode& n2, FunctionNode& n3)
{
    switch (func)
    {
    case 30:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT && n3.GetType() == VALUE_INT)
            return FunctionNode(Identity<ifIntIntInt>(), func, BoolConstant<ifIntIntInt::Upward>(), BoolConstant<ifIntIntInt::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ifIntFltFlt>(), func, BoolConstant<ifIntFltFlt::Upward>(), BoolConstant<ifIntFltFlt::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_STR && n3.GetType() == VALUE_STR)
            return FunctionNode(Identity<ifIntStrStr>(), func, BoolConstant<ifIntStrStr::Upward>(), BoolConstant<ifIntStrStr::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_VEC && n3.GetType() == VALUE_VEC)
            return FunctionNode(Identity<ifIntVecVec>(), func, BoolConstant<ifIntVecVec::Upward>(), BoolConstant<ifIntVecVec::Downward>(), state, n1, n2, n3);
        break;
    case 31:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<vec3FltFltFlt>(), func, BoolConstant<vec3FltFltFlt::Upward>(), BoolConstant<vec3FltFltFlt::Downward>(), state, n1, n2, n3);
        break;
    case 32:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC && n3.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mat3VecVecVec>(), func, BoolConstant<mat3VecVecVec::Upward>(), BoolConstant<mat3VecVecVec::Downward>(), state, n1, n2, n3);
        break;
    case 33:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<diag3FltFltFlt>(), func, BoolConstant<diag3FltFltFlt::Upward>(), BoolConstant<diag3FltFltFlt::Downward>(), state, n1, n2, n3);
        break;
    case 50:
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_INT && n3.GetType() == VALUE_INT)
            return FunctionNode(Identity<index3MatIntInt>(), func, BoolConstant<index3MatIntInt::Upward>(), BoolConstant<index3MatIntInt::Downward>(), state, n1, n2, n3);
        break;
    }
    throw InvalidType("");
}
inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, TerminalNode& n1, FunctionNode& n2, TerminalNode& n3)
{
    switch (func)
    {
    case 30:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT && n3.GetType() == VALUE_INT)
            return FunctionNode(Identity<ifIntIntInt>(), func, BoolConstant<ifIntIntInt::Upward>(), BoolConstant<ifIntIntInt::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ifIntFltFlt>(), func, BoolConstant<ifIntFltFlt::Upward>(), BoolConstant<ifIntFltFlt::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_STR && n3.GetType() == VALUE_STR)
            return FunctionNode(Identity<ifIntStrStr>(), func, BoolConstant<ifIntStrStr::Upward>(), BoolConstant<ifIntStrStr::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_VEC && n3.GetType() == VALUE_VEC)
            return FunctionNode(Identity<ifIntVecVec>(), func, BoolConstant<ifIntVecVec::Upward>(), BoolConstant<ifIntVecVec::Downward>(), state, n1, n2, n3);
        break;
    case 31:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<vec3FltFltFlt>(), func, BoolConstant<vec3FltFltFlt::Upward>(), BoolConstant<vec3FltFltFlt::Downward>(), state, n1, n2, n3);
        break;
    case 32:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC && n3.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mat3VecVecVec>(), func, BoolConstant<mat3VecVecVec::Upward>(), BoolConstant<mat3VecVecVec::Downward>(), state, n1, n2, n3);
        break;
    case 33:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<diag3FltFltFlt>(), func, BoolConstant<diag3FltFltFlt::Upward>(), BoolConstant<diag3FltFltFlt::Downward>(), state, n1, n2, n3);
        break;
    case 50:
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_INT && n3.GetType() == VALUE_INT)
            return FunctionNode(Identity<index3MatIntInt>(), func, BoolConstant<index3MatIntInt::Upward>(), BoolConstant<index3MatIntInt::Downward>(), state, n1, n2, n3);
        break;
    }
    throw InvalidType("");
}
inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, TerminalNode& n1, FunctionNode& n2, FunctionNode& n3)
{
    switch (func)
    {
    case 30:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT && n3.GetType() == VALUE_INT)
            return FunctionNode(Identity<ifIntIntInt>(), func, BoolConstant<ifIntIntInt::Upward>(), BoolConstant<ifIntIntInt::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ifIntFltFlt>(), func, BoolConstant<ifIntFltFlt::Upward>(), BoolConstant<ifIntFltFlt::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_STR && n3.GetType() == VALUE_STR)
            return FunctionNode(Identity<ifIntStrStr>(), func, BoolConstant<ifIntStrStr::Upward>(), BoolConstant<ifIntStrStr::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_VEC && n3.GetType() == VALUE_VEC)
            return FunctionNode(Identity<ifIntVecVec>(), func, BoolConstant<ifIntVecVec::Upward>(), BoolConstant<ifIntVecVec::Downward>(), state, n1, n2, n3);
        break;
    case 31:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<vec3FltFltFlt>(), func, BoolConstant<vec3FltFltFlt::Upward>(), BoolConstant<vec3FltFltFlt::Downward>(), state, n1, n2, n3);
        break;
    case 32:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC && n3.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mat3VecVecVec>(), func, BoolConstant<mat3VecVecVec::Upward>(), BoolConstant<mat3VecVecVec::Downward>(), state, n1, n2, n3);
        break;
    case 33:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<diag3FltFltFlt>(), func, BoolConstant<diag3FltFltFlt::Upward>(), BoolConstant<diag3FltFltFlt::Downward>(), state, n1, n2, n3);
        break;
    case 50:
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_INT && n3.GetType() == VALUE_INT)
            return FunctionNode(Identity<index3MatIntInt>(), func, BoolConstant<index3MatIntInt::Upward>(), BoolConstant<index3MatIntInt::Downward>(), state, n1, n2, n3);
        break;
    }
    throw InvalidType("");
}
inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, FunctionNode& n1, TerminalNode& n2, TerminalNode& n3)
{
    switch (func)
    {
    case 30:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT && n3.GetType() == VALUE_INT)
            return FunctionNode(Identity<ifIntIntInt>(), func, BoolConstant<ifIntIntInt::Upward>(), BoolConstant<ifIntIntInt::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ifIntFltFlt>(), func, BoolConstant<ifIntFltFlt::Upward>(), BoolConstant<ifIntFltFlt::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_STR && n3.GetType() == VALUE_STR)
            return FunctionNode(Identity<ifIntStrStr>(), func, BoolConstant<ifIntStrStr::Upward>(), BoolConstant<ifIntStrStr::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_VEC && n3.GetType() == VALUE_VEC)
            return FunctionNode(Identity<ifIntVecVec>(), func, BoolConstant<ifIntVecVec::Upward>(), BoolConstant<ifIntVecVec::Downward>(), state, n1, n2, n3);
        break;
    case 31:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<vec3FltFltFlt>(), func, BoolConstant<vec3FltFltFlt::Upward>(), BoolConstant<vec3FltFltFlt::Downward>(), state, n1, n2, n3);
        break;
    case 32:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC && n3.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mat3VecVecVec>(), func, BoolConstant<mat3VecVecVec::Upward>(), BoolConstant<mat3VecVecVec::Downward>(), state, n1, n2, n3);
        break;
    case 33:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<diag3FltFltFlt>(), func, BoolConstant<diag3FltFltFlt::Upward>(), BoolConstant<diag3FltFltFlt::Downward>(), state, n1, n2, n3);
        break;
    case 50:
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_INT && n3.GetType() == VALUE_INT)
            return FunctionNode(Identity<index3MatIntInt>(), func, BoolConstant<index3MatIntInt::Upward>(), BoolConstant<index3MatIntInt::Downward>(), state, n1, n2, n3);
        break;
    }
    throw InvalidType("");
}
inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, FunctionNode& n1, TerminalNode& n2, FunctionNode& n3)
{
    switch (func)
    {
    case 30:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT && n3.GetType() == VALUE_INT)
            return FunctionNode(Identity<ifIntIntInt>(), func, BoolConstant<ifIntIntInt::Upward>(), BoolConstant<ifIntIntInt::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ifIntFltFlt>(), func, BoolConstant<ifIntFltFlt::Upward>(), BoolConstant<ifIntFltFlt::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_STR && n3.GetType() == VALUE_STR)
            return FunctionNode(Identity<ifIntStrStr>(), func, BoolConstant<ifIntStrStr::Upward>(), BoolConstant<ifIntStrStr::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_VEC && n3.GetType() == VALUE_VEC)
            return FunctionNode(Identity<ifIntVecVec>(), func, BoolConstant<ifIntVecVec::Upward>(), BoolConstant<ifIntVecVec::Downward>(), state, n1, n2, n3);
        break;
    case 31:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<vec3FltFltFlt>(), func, BoolConstant<vec3FltFltFlt::Upward>(), BoolConstant<vec3FltFltFlt::Downward>(), state, n1, n2, n3);
        break;
    case 32:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC && n3.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mat3VecVecVec>(), func, BoolConstant<mat3VecVecVec::Upward>(), BoolConstant<mat3VecVecVec::Downward>(), state, n1, n2, n3);
        break;
    case 33:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<diag3FltFltFlt>(), func, BoolConstant<diag3FltFltFlt::Upward>(), BoolConstant<diag3FltFltFlt::Downward>(), state, n1, n2, n3);
        break;
    case 50:
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_INT && n3.GetType() == VALUE_INT)
            return FunctionNode(Identity<index3MatIntInt>(), func, BoolConstant<index3MatIntInt::Upward>(), BoolConstant<index3MatIntInt::Downward>(), state, n1, n2, n3);
        break;
    }
    throw InvalidType("");
}
inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, FunctionNode& n1, FunctionNode& n2, TerminalNode& n3)
{
    switch (func)
    {
    case 30:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT && n3.GetType() == VALUE_INT)
            return FunctionNode(Identity<ifIntIntInt>(), func, BoolConstant<ifIntIntInt::Upward>(), BoolConstant<ifIntIntInt::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ifIntFltFlt>(), func, BoolConstant<ifIntFltFlt::Upward>(), BoolConstant<ifIntFltFlt::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_STR && n3.GetType() == VALUE_STR)
            return FunctionNode(Identity<ifIntStrStr>(), func, BoolConstant<ifIntStrStr::Upward>(), BoolConstant<ifIntStrStr::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_VEC && n3.GetType() == VALUE_VEC)
            return FunctionNode(Identity<ifIntVecVec>(), func, BoolConstant<ifIntVecVec::Upward>(), BoolConstant<ifIntVecVec::Downward>(), state, n1, n2, n3);
        break;
    case 31:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<vec3FltFltFlt>(), func, BoolConstant<vec3FltFltFlt::Upward>(), BoolConstant<vec3FltFltFlt::Downward>(), state, n1, n2, n3);
        break;
    case 32:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC && n3.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mat3VecVecVec>(), func, BoolConstant<mat3VecVecVec::Upward>(), BoolConstant<mat3VecVecVec::Downward>(), state, n1, n2, n3);
        break;
    case 33:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<diag3FltFltFlt>(), func, BoolConstant<diag3FltFltFlt::Upward>(), BoolConstant<diag3FltFltFlt::Downward>(), state, n1, n2, n3);
        break;
    case 50:
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_INT && n3.GetType() == VALUE_INT)
            return FunctionNode(Identity<index3MatIntInt>(), func, BoolConstant<index3MatIntInt::Upward>(), BoolConstant<index3MatIntInt::Downward>(), state, n1, n2, n3);
        break;
    }
    throw InvalidType("");
}
inline FunctionNode MakeFunctionNode(ParserState* state, size_t func, FunctionNode& n1, FunctionNode& n2, FunctionNode& n3)
{
    switch (func)
    {
    case 30:
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_INT && n3.GetType() == VALUE_INT)
            return FunctionNode(Identity<ifIntIntInt>(), func, BoolConstant<ifIntIntInt::Upward>(), BoolConstant<ifIntIntInt::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<ifIntFltFlt>(), func, BoolConstant<ifIntFltFlt::Upward>(), BoolConstant<ifIntFltFlt::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_STR && n3.GetType() == VALUE_STR)
            return FunctionNode(Identity<ifIntStrStr>(), func, BoolConstant<ifIntStrStr::Upward>(), BoolConstant<ifIntStrStr::Downward>(), state, n1, n2, n3);
        if (n1.GetType() == VALUE_INT && n2.GetType() == VALUE_VEC && n3.GetType() == VALUE_VEC)
            return FunctionNode(Identity<ifIntVecVec>(), func, BoolConstant<ifIntVecVec::Upward>(), BoolConstant<ifIntVecVec::Downward>(), state, n1, n2, n3);
        break;
    case 31:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<vec3FltFltFlt>(), func, BoolConstant<vec3FltFltFlt::Upward>(), BoolConstant<vec3FltFltFlt::Downward>(), state, n1, n2, n3);
        break;
    case 32:
        if (n1.GetType() == VALUE_VEC && n2.GetType() == VALUE_VEC && n3.GetType() == VALUE_VEC)
            return FunctionNode(Identity<mat3VecVecVec>(), func, BoolConstant<mat3VecVecVec::Upward>(), BoolConstant<mat3VecVecVec::Downward>(), state, n1, n2, n3);
        break;
    case 33:
        if (n1.GetType() == VALUE_FLT && n2.GetType() == VALUE_FLT && n3.GetType() == VALUE_FLT)
            return FunctionNode(Identity<diag3FltFltFlt>(), func, BoolConstant<diag3FltFltFlt::Upward>(), BoolConstant<diag3FltFltFlt::Downward>(), state, n1, n2, n3);
        break;
    case 50:
        if (n1.GetType() == VALUE_MAT && n2.GetType() == VALUE_INT && n3.GetType() == VALUE_INT)
            return FunctionNode(Identity<index3MatIntInt>(), func, BoolConstant<index3MatIntInt::Upward>(), BoolConstant<index3MatIntInt::Downward>(), state, n1, n2, n3);
        break;
    }
    throw InvalidType("");
}
inline TerminalNode MakeConstantNode(ParserState*, size_t func, TerminalNode& t)
{
    switch (func)
    {
    case 0:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(sinInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(sinFlt::process_when_compile(t.GetFlt()));
        break;
    case 1:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(cosInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(cosFlt::process_when_compile(t.GetFlt()));
        break;
    case 2:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(tanInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(tanFlt::process_when_compile(t.GetFlt()));
        break;
    case 3:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(asinInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(asinFlt::process_when_compile(t.GetFlt()));
        break;
    case 4:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(acosInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(acosFlt::process_when_compile(t.GetFlt()));
        break;
    case 5:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(atanInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(atanFlt::process_when_compile(t.GetFlt()));
        break;
    case 6:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(lnInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(lnFlt::process_when_compile(t.GetFlt()));
        break;
    case 7:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(log10Int::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(log10Flt::process_when_compile(t.GetFlt()));
        break;
    case 8:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(expInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(expFlt::process_when_compile(t.GetFlt()));
        break;
    case 9:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(squareInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(squareFlt::process_when_compile(t.GetFlt()));
        break;
    case 10:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(cubeInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(cubeFlt::process_when_compile(t.GetFlt()));
        break;
    case 11:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(sqrtInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(sqrtFlt::process_when_compile(t.GetFlt()));
        break;
    case 12:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(cbrtInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(cbrtFlt::process_when_compile(t.GetFlt()));
        break;
    case 13:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(ceilInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(ceilFlt::process_when_compile(t.GetFlt()));
        break;
    case 14:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(floorInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(floorFlt::process_when_compile(t.GetFlt()));
        break;
    case 15:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(intInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(intFlt::process_when_compile(t.GetFlt()));
        break;
    case 16:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(floatInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(floatFlt::process_when_compile(t.GetFlt()));
        break;
    case 17:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(absInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(absFlt::process_when_compile(t.GetFlt()));
        break;
    case 18:
        if (t.GetType() == VALUE_STR)
            return TerminalNode(lenStr::process_when_compile(t.GetStr()));
        if (t.GetType() == VALUE_VEC)
            return TerminalNode(lenVec::process_when_compile(t.GetVec()));
        break;
    case 19:
        if (t.GetType() == VALUE_MAT)
            return TerminalNode(transposeMat::process_when_compile(t.GetMat()));
        break;
    case 20:
        if (t.GetType() == VALUE_MAT)
            return TerminalNode(traceMat::process_when_compile(t.GetMat()));
        break;
    case 34:
        if (t.GetType() == VALUE_INT)
            return TerminalNode(subInt::process_when_compile(t.GetInt()));
        if (t.GetType() == VALUE_FLT)
            return TerminalNode(subFlt::process_when_compile(t.GetFlt()));
        if (t.GetType() == VALUE_VEC)
            return TerminalNode(subVec::process_when_compile(t.GetVec()));
        if (t.GetType() == VALUE_MAT)
            return TerminalNode(subMat::process_when_compile(t.GetMat()));
        break;
    }
    throw InvalidType("");
}
inline TerminalNode MakeConstantNode(ParserState*, size_t func, TerminalNode& t1, TerminalNode& t2)
{
    switch (func)
    {
    case 21:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(atan2IntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_FLT)
            return TerminalNode(atan2IntFlt::process_when_compile(t1.GetInt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_INT)
            return TerminalNode(atan2FltInt::process_when_compile(t1.GetFlt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(atan2FltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        break;
    case 22:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(log2IntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_FLT)
            return TerminalNode(log2IntFlt::process_when_compile(t1.GetInt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_INT)
            return TerminalNode(log2FltInt::process_when_compile(t1.GetFlt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(log2FltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        break;
    case 23:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(maxIntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(maxFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        break;
    case 24:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(minIntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(minFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        break;
    case 25:
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(vec2FltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        break;
    case 26:
        if (t1.GetType() == VALUE_VEC && t2.GetType() == VALUE_VEC)
            return TerminalNode(mat2VecVec::process_when_compile(t1.GetVec(), t2.GetVec()));
        break;
    case 27:
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(diag2FltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        break;
    case 28:
        if (t1.GetType() == VALUE_VEC && t2.GetType() == VALUE_VEC)
            return TerminalNode(dotVecVec::process_when_compile(t1.GetVec(), t2.GetVec()));
        break;
    case 29:
        if (t1.GetType() == VALUE_VEC && t2.GetType() == VALUE_VEC)
            return TerminalNode(crossVecVec::process_when_compile(t1.GetVec(), t2.GetVec()));
        break;
    case 35:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(powIntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_FLT)
            return TerminalNode(powIntFlt::process_when_compile(t1.GetInt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_INT)
            return TerminalNode(powFltInt::process_when_compile(t1.GetFlt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(powFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        break;
    case 36:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(mulIntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_FLT)
            return TerminalNode(mulIntFlt::process_when_compile(t1.GetInt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_INT)
            return TerminalNode(mulFltInt::process_when_compile(t1.GetFlt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(mulFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_VEC && t2.GetType() == VALUE_FLT)
            return TerminalNode(mulVecFlt::process_when_compile(t1.GetVec(), t2.GetFlt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_VEC)
            return TerminalNode(mulFltVec::process_when_compile(t1.GetFlt(), t2.GetVec()));
        if (t1.GetType() == VALUE_MAT && t2.GetType() == VALUE_FLT)
            return TerminalNode(mulMatFlt::process_when_compile(t1.GetMat(), t2.GetFlt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_MAT)
            return TerminalNode(mulFltMat::process_when_compile(t1.GetFlt(), t2.GetMat()));
        if (t1.GetType() == VALUE_MAT && t2.GetType() == VALUE_MAT)
            return TerminalNode(mulMatMat::process_when_compile(t1.GetMat(), t2.GetMat()));
        if (t1.GetType() == VALUE_MAT && t2.GetType() == VALUE_VEC)
            return TerminalNode(mulMatVec::process_when_compile(t1.GetMat(), t2.GetVec()));
        break;
    case 37:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(divIntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_FLT)
            return TerminalNode(divIntFlt::process_when_compile(t1.GetInt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_INT)
            return TerminalNode(divFltInt::process_when_compile(t1.GetFlt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(divFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_VEC && t2.GetType() == VALUE_FLT)
            return TerminalNode(divVecFlt::process_when_compile(t1.GetVec(), t2.GetFlt()));
        break;
    case 38:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(modIntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        break;
    case 39:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(addIntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_FLT)
            return TerminalNode(addIntFlt::process_when_compile(t1.GetInt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_INT)
            return TerminalNode(addFltInt::process_when_compile(t1.GetFlt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(addFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_STR && t2.GetType() == VALUE_STR)
            return TerminalNode(addStrStr::process_when_compile(t1.GetStr(), t2.GetStr()));
        if (t1.GetType() == VALUE_VEC && t2.GetType() == VALUE_VEC)
            return TerminalNode(addVecVec::process_when_compile(t1.GetVec(), t2.GetVec()));
        if (t1.GetType() == VALUE_MAT && t2.GetType() == VALUE_MAT)
            return TerminalNode(addMatMat::process_when_compile(t1.GetMat(), t2.GetMat()));
        break;
    case 40:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(subIntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_FLT)
            return TerminalNode(subIntFlt::process_when_compile(t1.GetInt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_INT)
            return TerminalNode(subFltInt::process_when_compile(t1.GetFlt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(subFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_VEC && t2.GetType() == VALUE_VEC)
            return TerminalNode(subVecVec::process_when_compile(t1.GetVec(), t2.GetVec()));
        if (t1.GetType() == VALUE_MAT && t2.GetType() == VALUE_MAT)
            return TerminalNode(subMatMat::process_when_compile(t1.GetMat(), t2.GetMat()));
        break;
    case 41:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(gtIntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_FLT)
            return TerminalNode(gtIntFlt::process_when_compile(t1.GetInt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_INT)
            return TerminalNode(gtFltInt::process_when_compile(t1.GetFlt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(gtFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        break;
    case 42:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(geqIntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_FLT)
            return TerminalNode(geqIntFlt::process_when_compile(t1.GetInt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_INT)
            return TerminalNode(geqFltInt::process_when_compile(t1.GetFlt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(geqFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        break;
    case 43:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(ltIntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_FLT)
            return TerminalNode(ltIntFlt::process_when_compile(t1.GetInt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_INT)
            return TerminalNode(ltFltInt::process_when_compile(t1.GetFlt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(ltFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        break;
    case 44:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(leqIntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_FLT)
            return TerminalNode(leqIntFlt::process_when_compile(t1.GetInt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_INT)
            return TerminalNode(leqFltInt::process_when_compile(t1.GetFlt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(leqFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        break;
    case 45:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(eqIntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(eqFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_STR && t2.GetType() == VALUE_STR)
            return TerminalNode(eqStrStr::process_when_compile(t1.GetStr(), t2.GetStr()));
        if (t1.GetType() == VALUE_VEC && t2.GetType() == VALUE_VEC)
            return TerminalNode(eqVecVec::process_when_compile(t1.GetVec(), t2.GetVec()));
        if (t1.GetType() == VALUE_MAT && t2.GetType() == VALUE_MAT)
            return TerminalNode(eqMatMat::process_when_compile(t1.GetMat(), t2.GetMat()));
        break;
    case 46:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(neqIntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(neqFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_STR && t2.GetType() == VALUE_STR)
            return TerminalNode(neqStrStr::process_when_compile(t1.GetStr(), t2.GetStr()));
        if (t1.GetType() == VALUE_VEC && t2.GetType() == VALUE_VEC)
            return TerminalNode(neqVecVec::process_when_compile(t1.GetVec(), t2.GetVec()));
        if (t1.GetType() == VALUE_MAT && t2.GetType() == VALUE_MAT)
            return TerminalNode(neqMatMat::process_when_compile(t1.GetMat(), t2.GetMat()));
        break;
    case 47:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(andIntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_FLT)
            return TerminalNode(andIntFlt::process_when_compile(t1.GetInt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_INT)
            return TerminalNode(andFltInt::process_when_compile(t1.GetFlt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(andFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        break;
    case 48:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT)
            return TerminalNode(orIntInt::process_when_compile(t1.GetInt(), t2.GetInt()));
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_FLT)
            return TerminalNode(orIntFlt::process_when_compile(t1.GetInt(), t2.GetFlt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_INT)
            return TerminalNode(orFltInt::process_when_compile(t1.GetFlt(), t2.GetInt()));
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT)
            return TerminalNode(orFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt()));
        break;
    case 49:
        if (t1.GetType() == VALUE_STR && t2.GetType() == VALUE_INT)
            return TerminalNode(index2StrInt::process_when_compile(t1.GetStr(), t2.GetInt()));
        if (t1.GetType() == VALUE_VEC && t2.GetType() == VALUE_INT)
            return TerminalNode(index2VecInt::process_when_compile(t1.GetVec(), t2.GetInt()));
        break;
    }
    throw InvalidType("");
}
inline TerminalNode MakeConstantNode(ParserState*, size_t func, TerminalNode& t1, TerminalNode& t2, TerminalNode& t3)
{
    switch (func)
    {
    case 30:
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_INT && t3.GetType() == VALUE_INT)
            return TerminalNode(ifIntIntInt::process_when_compile(t1.GetInt(), t2.GetInt(), t3.GetInt()));
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_FLT && t3.GetType() == VALUE_FLT)
            return TerminalNode(ifIntFltFlt::process_when_compile(t1.GetInt(), t2.GetFlt(), t3.GetFlt()));
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_STR && t3.GetType() == VALUE_STR)
            return TerminalNode(ifIntStrStr::process_when_compile(t1.GetInt(), t2.GetStr(), t3.GetStr()));
        if (t1.GetType() == VALUE_INT && t2.GetType() == VALUE_VEC && t3.GetType() == VALUE_VEC)
            return TerminalNode(ifIntVecVec::process_when_compile(t1.GetInt(), t2.GetVec(), t3.GetVec()));
        break;
    case 31:
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT && t3.GetType() == VALUE_FLT)
            return TerminalNode(vec3FltFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt(), t3.GetFlt()));
        break;
    case 32:
        if (t1.GetType() == VALUE_VEC && t2.GetType() == VALUE_VEC && t3.GetType() == VALUE_VEC)
            return TerminalNode(mat3VecVecVec::process_when_compile(t1.GetVec(), t2.GetVec(), t3.GetVec()));
        break;
    case 33:
        if (t1.GetType() == VALUE_FLT && t2.GetType() == VALUE_FLT && t3.GetType() == VALUE_FLT)
            return TerminalNode(diag3FltFltFlt::process_when_compile(t1.GetFlt(), t2.GetFlt(), t3.GetFlt()));
        break;
    case 50:
        if (t1.GetType() == VALUE_MAT && t2.GetType() == VALUE_INT && t3.GetType() == VALUE_INT)
            return TerminalNode(index3MatIntInt::process_when_compile(t1.GetMat(), t2.GetInt(), t3.GetInt()));
        break;
    }
    throw InvalidType("");
}

}

}

}

#endif
