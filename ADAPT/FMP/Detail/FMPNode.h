#ifndef FMPNODE_H
#define FMPNODE_H

#include <ADAPT/FMP/Detail/FMPNode_func.h>

namespace adapt
{

namespace agr2
{

namespace detail
{

template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t, std::true_type, std::true_type, ParserState*, TerminalNode& n)
{
	mMakeFunc.Emplace<FMPMakeExpressionT<Func>>(n);
	mIsJuncture = false;
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t func, std::true_type, std::false_type, ParserState* state, TerminalNode& n)
{
	mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTNode<Func>>(state, n.GetIndex(state)));
	mIsJuncture = true;
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t func, std::false_type, std::true_type, ParserState* state, TerminalNode& n)
{
	mMakeFunc.Emplace<FMPMakeExpressionT<Func>>(n);
	mIsJuncture = false;
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t, std::false_type, std::false_type, ParserState* state, TerminalNode& n)
{
	mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTNode<Func>>(state, n.GetIndex(state)));
	mIsJuncture = true;
}

template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t func, std::true_type, std::true_type, ParserState* state, FunctionNode& n)
{
	if (n.IsJuncture())
	{
		JunctureNode j = n.GetJunctureNode();
		mMakeFunc.Emplace<FMPMakeExpressionJ<Func>>(j);
		mIsJuncture = false;
	}
	else
	{
		auto p = &n.mMakeFunc.Get<FMPMakeExpressionBase>();
		mMakeFunc.Emplace<JunctureNode>(p->MakeFunc(state, func, n));
		mIsJuncture = true;
	}
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t func, std::true_type, std::false_type, ParserState* state, FunctionNode& n)
{
	//downwardがfalseなので、自身はJunctureとしなければならない。
	if (n.IsJuncture())
	{
		JunctureNode j = n.GetJunctureNode();
		size_t i = state->mNodeBuffer.EmplaceBack<FMPExpressionJNode<Func>>(state, j.GetIndex());
		mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, i);
		mIsJuncture = true;
	}
	else
	{
		auto p = &n.mMakeFunc.Get<FMPMakeExpressionBase>();
		mMakeFunc.Emplace<JunctureNode>(p->MakeFunc(state, func, n));
		mIsJuncture = true;
	}
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t func, std::false_type, std::true_type, ParserState* state, FunctionNode& n)
{
	//upwardがfalseなので、nは強制的にJuncturizeする。
	JunctureNode j = n.IsJuncture() ? n.GetJunctureNode() : n.Juncturize(state);
	mMakeFunc.Emplace<FMPMakeExpressionJ<Func>>(j);
	mIsJuncture = false;
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t, std::false_type, std::false_type, ParserState* state, FunctionNode& n)
{
	//upwardがfalseなので、nは強制的にJuncturizeする。
	JunctureNode j = n.IsJuncture() ? n.GetJunctureNode() : n.Juncturize(state);
	//かつdownwardがfalseなので、自身もJunctureでなければならない。
	//auto p = &mMakeFunc.Get<FMPMakeExpressionBase>();
	mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJNode<Func>>(state, j.GetIndex(state)));
	//mMakeFunc.Emplace<JunctureNode>(p->MakeFunc(state, func, n));
	mIsJuncture = true;
}

template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t, std::true_type, std::true_type, ParserState*, TerminalNode& n1, TerminalNode& n2)
{
	mMakeFunc.Emplace<FMPMakeExpressionTT<Func>>(n1, n2);
	mIsJuncture = false;
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t, std::true_type, std::false_type, ParserState* state, TerminalNode& n1, TerminalNode& n2)
{
	//downwardがfalse。自身をJunctureとする。
	//JunctureNode j = n2.GetJunctureNode();
	mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTTNode<Func>>(state, n1.GetIndex(state), n2.GetIndex(state)));
	mIsJuncture = true;
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t func, std::false_type, std::true_type, ParserState* state, TerminalNode& n1, TerminalNode& n2)
{
	//upwardがfalseだがそもそも引数は両方ともterminalなので、特殊なことは必要ない。
	mMakeFunc.Emplace<FMPMakeExpressionTT<Func>>(n1, n2);
	mIsJuncture = false;
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t, std::false_type, std::false_type, ParserState* state, TerminalNode& n1, TerminalNode& n2)
{
	//downwardがfalse。自身をJunctureとする。
	//JunctureNode j = n2.GetJunctureNode();
	mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTTNode<Func>>(state, n1.GetIndex(state), n2.GetIndex(state)));
	mIsJuncture = true;
}

template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t func, std::true_type, std::true_type, ParserState* state, TerminalNode& n1, FunctionNode& n2)
{
	if (n2.IsJuncture())
	{
		JunctureNode j = n2.GetJunctureNode();
		mMakeFunc.Emplace<FMPMakeExpressionTJ<Func>>(n1, j);
		mIsJuncture = false;
	}
	else
	{
		auto p = &n2.mMakeFunc.Get<FMPMakeExpressionBase>();
		mMakeFunc.Emplace<JunctureNode>(p->MakeFunc(state, func, n1, n2));
		mIsJuncture = true;
	}
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t func, std::true_type, std::false_type, ParserState* state, TerminalNode& n1, FunctionNode& n2)
{
	//downwardがfalseなので自身をJunctureとする。
	if (n2.IsJuncture())
	{
		JunctureNode j = n2.GetJunctureNode();
		mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTJNode<Func>>(state, n1.GetIndex(state), j.GetIndex()));
		mIsJuncture = true;
	}
	else
	{
		auto p = &n2.mMakeFunc.Get<FMPMakeExpressionBase>();
		mMakeFunc.Emplace<JunctureNode>(p->MakeFunc(state, func, n1, n2));
		mIsJuncture = true;
	}
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t func, std::false_type, std::true_type, ParserState* state, TerminalNode& n1, FunctionNode& n2)
{
	//upwardがfalseなので、n2を強制的にJuncturizeする。
	JunctureNode j = n2.IsJuncture() ? n2.GetJunctureNode() : n2.Juncturize(state);
	mMakeFunc.Emplace<FMPMakeExpressionTJ<Func>>(n1, j);
	mIsJuncture = false;
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t, std::false_type, std::false_type, ParserState* state, TerminalNode& n1, FunctionNode& n2)
{
	//upwardがfalseなので、n2を強制的にJuncturizeする。
	JunctureNode j = n2.IsJuncture() ? n2.GetJunctureNode() : n2.Juncturize(state);
	//downwardがfalseなので自身をJunctureとする。
	mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTJNode<Func>>(state, n1.GetIndex(state), j.GetIndex()));
	mIsJuncture = true;
}

template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t func, std::true_type, std::true_type, ParserState* state, FunctionNode& n1, TerminalNode& n2)
{
	if (n1.IsJuncture())
	{
		JunctureNode j = n1.GetJunctureNode();
		mMakeFunc.Emplace<FMPMakeExpressionJT<Func>>(j, n2);
		mIsJuncture = false;
	}
	else
	{
		auto p = &n1.mMakeFunc.Get<FMPMakeExpressionBase>();
		mMakeFunc.Emplace<JunctureNode>(p->MakeFunc(state, func, n1, n2));
		mIsJuncture = true;
	}
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t func, std::true_type, std::false_type, ParserState* state, FunctionNode& n1, TerminalNode& n2)
{
	//downwardがfalseなので自身をJunctureとする。
	if (n1.IsJuncture())
	{
		JunctureNode j = n1.GetJunctureNode();
		mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJTNode<Func>>(state, j.GetIndex(), n2.GetIndex(state)));
		mIsJuncture = true;
	}
	else
	{
		auto p = &n1.mMakeFunc.Get<FMPMakeExpressionBase>();
		mMakeFunc.Emplace<JunctureNode>(p->MakeFunc(state, func, n1, n2));
		mIsJuncture = true;
	}
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t func, std::false_type, std::true_type, ParserState* state, FunctionNode& n1, TerminalNode& n2)
{
	//upwardがfalseなので、n1を強制的にJuncturizeする。
	JunctureNode j = n1.IsJuncture() ? n1.GetJunctureNode() : n1.Juncturize(state);
	mMakeFunc.Emplace<FMPMakeExpressionJT<Func>>(j, n2);
	mIsJuncture = false;
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t, std::false_type, std::false_type, ParserState* state, FunctionNode& n1, TerminalNode& n2)
{
	//upwardがfalseなので、n1を強制的にJuncturizeする。
	JunctureNode j = n1.IsJuncture() ? n1.GetJunctureNode() : n1.Juncturize(state);
	//downwardがfalseなので自身をJunctureとする。
	mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJTNode<Func>>(state, j.GetIndex(), n2.GetIndex(state)));
	mIsJuncture = true;
}

template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t func, std::true_type, std::true_type, ParserState* state, FunctionNode& n1, FunctionNode& n2)
{
	if (n1.IsJuncture())
	{
		JunctureNode j1 = n1.GetJunctureNode();
		if (n2.IsJuncture())
		{
			JunctureNode j2 = n2.GetJunctureNode();
			mMakeFunc.Emplace<FMPMakeExpressionJJ<Func>>(j1, j2);
			mIsJuncture = false;
		}
		else
		{
			auto p = &n2.mMakeFunc.Get<FMPMakeExpressionBase>();
			mMakeFunc.Emplace<JunctureNode>(p->MakeFunc(state, func, j1, n2));
			mIsJuncture = true;
		}
	}
	else
	{
		//n1がJunctureではないので、n2は強制的にJuncturizeする。
		JunctureNode j2 = n2.IsJuncture() ? n2.GetJunctureNode() : n2.Juncturize(state);
		auto p = &n1.mMakeFunc.Get<FMPMakeExpressionBase>();
		mMakeFunc.Emplace<JunctureNode>(p->MakeFunc(state, func, n1, j2));
		mIsJuncture = true;
	}
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t func, std::true_type, std::false_type, ParserState* state, FunctionNode& n1, FunctionNode& n2)
{
	//downwardがfalseなので、自身はJunctureでなければならない。
	if (n1.IsJuncture())
	{
		JunctureNode j1 = n1.GetJunctureNode();
		if (n2.IsJuncture())
		{
			//両者Juncture。
			JunctureNode j2 = n2.GetJunctureNode();
			mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJJNode<Func>>(state, j1.GetIndex(), j2.GetIndex()));
			mIsJuncture = true;
		}
		else
		{
			auto p = &n2.mMakeFunc.Get<FMPMakeExpressionBase>();
			mMakeFunc.Emplace<JunctureNode>(p->MakeFunc(state, func, j1, n2));
			mIsJuncture = true;
		}
	}
	else
	{
		//n1がJunctureでないのでこちらを基準にJuncturizeする。n2は強制的にJuncturize。
		JunctureNode j2 = n2.IsJuncture() ? n2.GetJunctureNode() : n2.Juncturize(state);
		auto p = &n1.mMakeFunc.Get<FMPMakeExpressionBase>();
		mMakeFunc.Emplace<JunctureNode>(p->MakeFunc(state, func, n1, j2));
		mIsJuncture = true;
	}
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t func, std::false_type, std::true_type, ParserState* state, FunctionNode& n1, FunctionNode& n2)
{
	//upwardがfalseなので、n1、n2双方を強制的にJuncturizeする。
	JunctureNode j1 = n1.IsJuncture() ? n1.GetJunctureNode() : n1.Juncturize();
	JunctureNode j2 = n2.IsJuncture() ? n2.GetJunctureNode() : n2.Juncturize();
	mMakeFunc.Emplace<FMPMakeExpressionJJ<Func>>(j1, j2);
	mIsJuncture = false;
}
template <class Func>
FunctionNode::FunctionNode(Identity<Func>, size_t, std::false_type, std::false_type, ParserState* state, FunctionNode& n1, FunctionNode& n2)
{
	//upwardがfalseなので、n1、n2双方を強制的にJuncturizeする。
	JunctureNode j1 = n1.IsJuncture() ? n1.GetJunctureNode() : n1.Juncturize(state);
	JunctureNode j2 = n2.IsJuncture() ? n2.GetJunctureNode() : n2.Juncturize(state);
	mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJJNode<Func>>(state, j1.GetIndex(state), j2.GetIndex(state)));
	mIsJuncture = true;
}
template <class Func, bool BU, bool BD>
FunctionNode::FunctionNode(Identity<Func>, size_t /*func*/, std::bool_constant<BU>, std::bool_constant<BD>, ParserState* state, TerminalNode& n1, TerminalNode& n2, TerminalNode& n3)
{
	mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTTTNode<Func>>(state, n1.GetIndex(state), n2.GetIndex(state), n3.GetIndex(state)));
	mIsJuncture = true;
}
template <class Func, bool BU, bool BD>
FunctionNode::FunctionNode(Identity<Func>, size_t /*func*/, std::bool_constant<BU>, std::bool_constant<BD>, ParserState* state, TerminalNode& n1, FunctionNode& n2, TerminalNode& n3)
{
	JunctureNode j2 = n2.IsJuncture() ? n2.GetJunctureNode() : n2.Juncturize(state);
	mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTJTNode<Func>>(state, n1.GetIndex(state), j2.GetIndex(state), n3.GetIndex(state)));
	mIsJuncture = true;
}
template <class Func, bool BU, bool BD>
FunctionNode::FunctionNode(Identity<Func>, size_t /*func*/, std::bool_constant<BU>, std::bool_constant<BD>, ParserState* state, FunctionNode& n1, TerminalNode& n2, TerminalNode& n3)
{
	JunctureNode j1 = n1.IsJuncture() ? n1.GetJunctureNode() : n1.Juncturize(state);
	mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJTTNode<Func>>(state, j1.GetIndex(state), n2.GetIndex(state), n3.GetIndex(state)));
	mIsJuncture = true;
}
template <class Func, bool BU, bool BD>
FunctionNode::FunctionNode(Identity<Func>, size_t /*func*/, std::bool_constant<BU>, std::bool_constant<BD>, ParserState* state, FunctionNode& n1, FunctionNode& n2, TerminalNode& n3)
{
	JunctureNode j1 = n1.IsJuncture() ? n1.GetJunctureNode() : n1.Juncturize(state);
	JunctureNode j2 = n2.IsJuncture() ? n2.GetJunctureNode() : n2.Juncturize(state);
	mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJJTNode<Func>>(state, j1.GetIndex(state), j2.GetIndex(state), n3.GetIndex(state)));
	mIsJuncture = true;
}
template <class Func, bool BU, bool BD>
FunctionNode::FunctionNode(Identity<Func>, size_t /*func*/, std::bool_constant<BU>, std::bool_constant<BD>, ParserState* state, TerminalNode& n1, TerminalNode& n2, FunctionNode& n3)
{
	JunctureNode j3 = n3.IsJuncture() ? n3.GetJunctureNode() : n3.Juncturize(state);
	mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTTJNode<Func>>(state, n1.GetIndex(state), n2.GetIndex(state), j3.GetIndex(state)));
	mIsJuncture = true;
}
template <class Func, bool BU, bool BD>
FunctionNode::FunctionNode(Identity<Func>, size_t /*func*/, std::bool_constant<BU>, std::bool_constant<BD>, ParserState* state, TerminalNode& n1, FunctionNode& n2, FunctionNode& n3)
{
	JunctureNode j2 = n2.IsJuncture() ? n2.GetJunctureNode() : n2.Juncturize(state);
	JunctureNode j3 = n3.IsJuncture() ? n3.GetJunctureNode() : n3.Juncturize(state);
	mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionTJJNode<Func>>(state, n1.GetIndex(state), j2.GetIndex(state), j3.GetIndex(state)));
	mIsJuncture = true;
}
template <class Func, bool BU, bool BD>
FunctionNode::FunctionNode(Identity<Func>, size_t /*func*/, std::bool_constant<BU>, std::bool_constant<BD>, ParserState* state, FunctionNode& n1, TerminalNode& n2, FunctionNode& n3)
{
	JunctureNode j1 = n1.IsJuncture() ? n1.GetJunctureNode() : n1.Juncturize(state);
	JunctureNode j3 = n3.IsJuncture() ? n3.GetJunctureNode() : n3.Juncturize(state);
	mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJTJNode<Func>>(state, j1.GetIndex(state), n2.GetIndex(state), j3.GetIndex(state)));
	mIsJuncture = true;
}
template <class Func, bool BU, bool BD>
FunctionNode::FunctionNode(Identity<Func>, size_t /*func*/, std::bool_constant<BU>, std::bool_constant<BD>, ParserState* state, FunctionNode& n1, FunctionNode& n2, FunctionNode& n3)
{
	JunctureNode j1 = n1.IsJuncture() ? n1.GetJunctureNode() : n1.Juncturize(state);
	JunctureNode j2 = n2.IsJuncture() ? n2.GetJunctureNode() : n2.Juncturize(state);
	JunctureNode j3 = n3.IsJuncture() ? n3.GetJunctureNode() : n3.Juncturize(state);
	mMakeFunc.Emplace<JunctureNode>(Func::RetType::label, state->mNodeBuffer.EmplaceBack<FMPExpressionJTJNode<Func>>(state, j1.GetIndex(state), j2.GetIndex(state), j3.GetIndex(state)));
	mIsJuncture = true;
}

}

}

}

#endif
