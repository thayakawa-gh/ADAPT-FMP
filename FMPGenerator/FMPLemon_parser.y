%token_prefix FMP_TOKEN_

%left AND OR.
%left EQ NEQ.
%left GT GEQ LT LEQ.
%left ADD SUB.
%left MUL DIV MOD.
%left POW.
%right NOT.
%nonassoc BRA KET.

%token_type { Trivializer<NodeValue> }
%type constant_node { Trivializer<TerminalNode> }
%type variable_node { Trivializer<TerminalNode> }
%type function_node { Trivializer<FunctionNode> }

%destructor constant_node { $$.Destroy(); }

%destructor variable_node { $$.Destroy(); }

%destructor function_node { $$.Destroy(); }

%extra_argument { ParserState *state }

%include {
#include <iostream>
#include <array>
#include <ADAPT/CUF/Trivializer.h>
#include "FMPExpression.h"
#include "FMPNode_func.h"
BEGIN_LEMON_NAMESPACE
}
%code { END_LEMON_NAMESPACE }
%syntax_error {
	fprintf(stderr, "Syntax error");
}
%parse_failure {
	fprintf(stderr,"Giving up.  Parser is hopelessly lost...");
}
%start_symbol equation

equation ::= constant_node(A). { try { state->mRootNode = A->Juncturize(state); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
equation ::= variable_node(A). { try { state->mRootNode = A->Juncturize(state); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
equation ::= function_node(A). { try { if (!A->IsJuncture()) A->Juncturize(state); state->mRootNode = A->GetJunctureNode(); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= INT(B).    { try { A.Construct(B->GetInt()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
constant_node(A) ::= FLT(B).    { try { A.Construct(B->GetFlt()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
constant_node(A) ::= STR(B).    { try { A.Construct(B->GetStr()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
constant_node(A) ::= VEC(B).    { try { A.Construct(B->GetVec()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
constant_node(A) ::= MAT(B).    { try { A.Construct(B->GetMat()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
variable_node(A) ::= INTARG(B). { try { A.Construct(B->GetIntPtr()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
variable_node(A) ::= FLTARG(B). { try { A.Construct(B->GetFltPtr()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
variable_node(A) ::= STRARG(B). { try { A.Construct(B->GetStrPtr()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
variable_node(A) ::= VECARG(B). { try { A.Construct(B->GetVecPtr()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
variable_node(A) ::= MATARG(B). { try { A.Construct(B->GetMatPtr()); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node       (A) ::= SUB constant_node(B). [NOT] { try { A.Construct(MakeConstantNode(state, 34, *B)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node       (A) ::= SUB variable_node(B). [NOT] { try { A.Construct(MakeFunctionNode(state, 34, *B));  } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node       (A) ::= SUB function_node(B). [NOT] { try { A.Construct(MakeFunctionNode(state, 34, *B));  } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= constant_node(B) POW constant_node(C). { try { A.Construct(MakeConstantNode(state, 35, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) POW variable_node(C). { try { A.Construct(MakeFunctionNode(state, 35, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) POW function_node(C). { try { A.Construct(MakeFunctionNode(state, 35, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) POW constant_node(C). { try { A.Construct(MakeFunctionNode(state, 35, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) POW variable_node(C). { try { A.Construct(MakeFunctionNode(state, 35, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) POW function_node(C). { try { A.Construct(MakeFunctionNode(state, 35, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) POW constant_node(C). { try { A.Construct(MakeFunctionNode(state, 35, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) POW variable_node(C). { try { A.Construct(MakeFunctionNode(state, 35, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) POW function_node(C). { try { A.Construct(MakeFunctionNode(state, 35, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= constant_node(B) MUL constant_node(C). { try { A.Construct(MakeConstantNode(state, 36, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) MUL variable_node(C). { try { A.Construct(MakeFunctionNode(state, 36, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) MUL function_node(C). { try { A.Construct(MakeFunctionNode(state, 36, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) MUL constant_node(C). { try { A.Construct(MakeFunctionNode(state, 36, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) MUL variable_node(C). { try { A.Construct(MakeFunctionNode(state, 36, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) MUL function_node(C). { try { A.Construct(MakeFunctionNode(state, 36, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) MUL constant_node(C). { try { A.Construct(MakeFunctionNode(state, 36, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) MUL variable_node(C). { try { A.Construct(MakeFunctionNode(state, 36, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) MUL function_node(C). { try { A.Construct(MakeFunctionNode(state, 36, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= constant_node(B) DIV constant_node(C). { try { A.Construct(MakeConstantNode(state, 37, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) DIV variable_node(C). { try { A.Construct(MakeFunctionNode(state, 37, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) DIV function_node(C). { try { A.Construct(MakeFunctionNode(state, 37, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) DIV constant_node(C). { try { A.Construct(MakeFunctionNode(state, 37, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) DIV variable_node(C). { try { A.Construct(MakeFunctionNode(state, 37, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) DIV function_node(C). { try { A.Construct(MakeFunctionNode(state, 37, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) DIV constant_node(C). { try { A.Construct(MakeFunctionNode(state, 37, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) DIV variable_node(C). { try { A.Construct(MakeFunctionNode(state, 37, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) DIV function_node(C). { try { A.Construct(MakeFunctionNode(state, 37, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= constant_node(B) MOD constant_node(C). { try { A.Construct(MakeConstantNode(state, 38, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) MOD variable_node(C). { try { A.Construct(MakeFunctionNode(state, 38, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) MOD function_node(C). { try { A.Construct(MakeFunctionNode(state, 38, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) MOD constant_node(C). { try { A.Construct(MakeFunctionNode(state, 38, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) MOD variable_node(C). { try { A.Construct(MakeFunctionNode(state, 38, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) MOD function_node(C). { try { A.Construct(MakeFunctionNode(state, 38, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) MOD constant_node(C). { try { A.Construct(MakeFunctionNode(state, 38, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) MOD variable_node(C). { try { A.Construct(MakeFunctionNode(state, 38, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) MOD function_node(C). { try { A.Construct(MakeFunctionNode(state, 38, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= constant_node(B) ADD constant_node(C). { try { A.Construct(MakeConstantNode(state, 39, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) ADD variable_node(C). { try { A.Construct(MakeFunctionNode(state, 39, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) ADD function_node(C). { try { A.Construct(MakeFunctionNode(state, 39, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) ADD constant_node(C). { try { A.Construct(MakeFunctionNode(state, 39, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) ADD variable_node(C). { try { A.Construct(MakeFunctionNode(state, 39, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) ADD function_node(C). { try { A.Construct(MakeFunctionNode(state, 39, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) ADD constant_node(C). { try { A.Construct(MakeFunctionNode(state, 39, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) ADD variable_node(C). { try { A.Construct(MakeFunctionNode(state, 39, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) ADD function_node(C). { try { A.Construct(MakeFunctionNode(state, 39, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= constant_node(B) SUB constant_node(C). { try { A.Construct(MakeConstantNode(state, 40, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) SUB variable_node(C). { try { A.Construct(MakeFunctionNode(state, 40, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) SUB function_node(C). { try { A.Construct(MakeFunctionNode(state, 40, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) SUB constant_node(C). { try { A.Construct(MakeFunctionNode(state, 40, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) SUB variable_node(C). { try { A.Construct(MakeFunctionNode(state, 40, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) SUB function_node(C). { try { A.Construct(MakeFunctionNode(state, 40, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) SUB constant_node(C). { try { A.Construct(MakeFunctionNode(state, 40, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) SUB variable_node(C). { try { A.Construct(MakeFunctionNode(state, 40, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) SUB function_node(C). { try { A.Construct(MakeFunctionNode(state, 40, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= constant_node(B) GT  constant_node(C). { try { A.Construct(MakeConstantNode(state, 41, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) GT  variable_node(C). { try { A.Construct(MakeFunctionNode(state, 41, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) GT  function_node(C). { try { A.Construct(MakeFunctionNode(state, 41, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) GT  constant_node(C). { try { A.Construct(MakeFunctionNode(state, 41, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) GT  variable_node(C). { try { A.Construct(MakeFunctionNode(state, 41, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) GT  function_node(C). { try { A.Construct(MakeFunctionNode(state, 41, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) GT  constant_node(C). { try { A.Construct(MakeFunctionNode(state, 41, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) GT  variable_node(C). { try { A.Construct(MakeFunctionNode(state, 41, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) GT  function_node(C). { try { A.Construct(MakeFunctionNode(state, 41, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= constant_node(B) GEQ constant_node(C). { try { A.Construct(MakeConstantNode(state, 42, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) GEQ variable_node(C). { try { A.Construct(MakeFunctionNode(state, 42, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) GEQ function_node(C). { try { A.Construct(MakeFunctionNode(state, 42, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) GEQ constant_node(C). { try { A.Construct(MakeFunctionNode(state, 42, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) GEQ variable_node(C). { try { A.Construct(MakeFunctionNode(state, 42, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) GEQ function_node(C). { try { A.Construct(MakeFunctionNode(state, 42, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) GEQ constant_node(C). { try { A.Construct(MakeFunctionNode(state, 42, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) GEQ variable_node(C). { try { A.Construct(MakeFunctionNode(state, 42, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) GEQ function_node(C). { try { A.Construct(MakeFunctionNode(state, 42, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= constant_node(B) LT  constant_node(C). { try { A.Construct(MakeConstantNode(state, 43, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) LT  variable_node(C). { try { A.Construct(MakeFunctionNode(state, 43, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) LT  function_node(C). { try { A.Construct(MakeFunctionNode(state, 43, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) LT  constant_node(C). { try { A.Construct(MakeFunctionNode(state, 43, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) LT  variable_node(C). { try { A.Construct(MakeFunctionNode(state, 43, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) LT  function_node(C). { try { A.Construct(MakeFunctionNode(state, 43, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) LT  constant_node(C). { try { A.Construct(MakeFunctionNode(state, 43, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) LT  variable_node(C). { try { A.Construct(MakeFunctionNode(state, 43, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) LT  function_node(C). { try { A.Construct(MakeFunctionNode(state, 43, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= constant_node(B) LEQ constant_node(C). { try { A.Construct(MakeConstantNode(state, 44, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) LEQ variable_node(C). { try { A.Construct(MakeFunctionNode(state, 44, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) LEQ function_node(C). { try { A.Construct(MakeFunctionNode(state, 44, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) LEQ constant_node(C). { try { A.Construct(MakeFunctionNode(state, 44, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) LEQ variable_node(C). { try { A.Construct(MakeFunctionNode(state, 44, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) LEQ function_node(C). { try { A.Construct(MakeFunctionNode(state, 44, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) LEQ constant_node(C). { try { A.Construct(MakeFunctionNode(state, 44, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) LEQ variable_node(C). { try { A.Construct(MakeFunctionNode(state, 44, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) LEQ function_node(C). { try { A.Construct(MakeFunctionNode(state, 44, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= constant_node(B) EQ  constant_node(C). { try { A.Construct(MakeConstantNode(state, 45, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) EQ  variable_node(C). { try { A.Construct(MakeFunctionNode(state, 45, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) EQ  function_node(C). { try { A.Construct(MakeFunctionNode(state, 45, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) EQ  constant_node(C). { try { A.Construct(MakeFunctionNode(state, 45, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) EQ  variable_node(C). { try { A.Construct(MakeFunctionNode(state, 45, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) EQ  function_node(C). { try { A.Construct(MakeFunctionNode(state, 45, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) EQ  constant_node(C). { try { A.Construct(MakeFunctionNode(state, 45, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) EQ  variable_node(C). { try { A.Construct(MakeFunctionNode(state, 45, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) EQ  function_node(C). { try { A.Construct(MakeFunctionNode(state, 45, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= constant_node(B) NEQ constant_node(C). { try { A.Construct(MakeConstantNode(state, 46, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) NEQ variable_node(C). { try { A.Construct(MakeFunctionNode(state, 46, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) NEQ function_node(C). { try { A.Construct(MakeFunctionNode(state, 46, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) NEQ constant_node(C). { try { A.Construct(MakeFunctionNode(state, 46, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) NEQ variable_node(C). { try { A.Construct(MakeFunctionNode(state, 46, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) NEQ function_node(C). { try { A.Construct(MakeFunctionNode(state, 46, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) NEQ constant_node(C). { try { A.Construct(MakeFunctionNode(state, 46, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) NEQ variable_node(C). { try { A.Construct(MakeFunctionNode(state, 46, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) NEQ function_node(C). { try { A.Construct(MakeFunctionNode(state, 46, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= constant_node(B) AND constant_node(C). { try { A.Construct(MakeConstantNode(state, 47, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) AND variable_node(C). { try { A.Construct(MakeFunctionNode(state, 47, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) AND function_node(C). { try { A.Construct(MakeFunctionNode(state, 47, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) AND constant_node(C). { try { A.Construct(MakeFunctionNode(state, 47, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) AND variable_node(C). { try { A.Construct(MakeFunctionNode(state, 47, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) AND function_node(C). { try { A.Construct(MakeFunctionNode(state, 47, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) AND constant_node(C). { try { A.Construct(MakeFunctionNode(state, 47, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) AND variable_node(C). { try { A.Construct(MakeFunctionNode(state, 47, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) AND function_node(C). { try { A.Construct(MakeFunctionNode(state, 47, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= constant_node(B) OR  constant_node(C). { try { A.Construct(MakeConstantNode(state, 48, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) OR  variable_node(C). { try { A.Construct(MakeFunctionNode(state, 48, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) OR  function_node(C). { try { A.Construct(MakeFunctionNode(state, 48, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) OR  constant_node(C). { try { A.Construct(MakeFunctionNode(state, 48, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) OR  variable_node(C). { try { A.Construct(MakeFunctionNode(state, 48, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) OR  function_node(C). { try { A.Construct(MakeFunctionNode(state, 48, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) OR  constant_node(C). { try { A.Construct(MakeFunctionNode(state, 48, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) OR  variable_node(C). { try { A.Construct(MakeFunctionNode(state, 48, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) OR  function_node(C). { try { A.Construct(MakeFunctionNode(state, 48, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node       (A) ::= LPAR constant_node(B) RPAR. { A.Construct(*B); }
variable_node       (A) ::= LPAR variable_node(B) RPAR. { A.Construct(*B); }
function_node       (A) ::= LPAR function_node(B) RPAR. { A.Construct(*B); }

function_node       (A) ::= FUNC(B) LPAR constant_node(C) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node       (A) ::= FUNC(B) LPAR variable_node(C) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node       (A) ::= FUNC(B) LPAR function_node(C) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= FUNC(B) LPAR constant_node(C) COM constant_node(D) RPAR. { try { A.Construct(MakeConstantNode(state, B->GetInt(), *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR constant_node(C) COM variable_node(D) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR constant_node(C) COM function_node(D) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR variable_node(C) COM constant_node(D) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR variable_node(C) COM variable_node(D) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR variable_node(C) COM function_node(D) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR function_node(C) COM constant_node(D) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR function_node(C) COM variable_node(D) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR function_node(C) COM function_node(D) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= FUNC(B) LPAR constant_node(C) COM constant_node(D) COM constant_node(E) RPAR. { try { A.Construct(MakeConstantNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR constant_node(C) COM constant_node(D) COM variable_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR constant_node(C) COM constant_node(D) COM function_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR constant_node(C) COM variable_node(D) COM constant_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR constant_node(C) COM variable_node(D) COM variable_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR constant_node(C) COM variable_node(D) COM function_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR constant_node(C) COM function_node(D) COM constant_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR constant_node(C) COM function_node(D) COM variable_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR constant_node(C) COM function_node(D) COM function_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR variable_node(C) COM constant_node(D) COM constant_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR variable_node(C) COM constant_node(D) COM variable_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR variable_node(C) COM constant_node(D) COM function_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR variable_node(C) COM variable_node(D) COM constant_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR variable_node(C) COM variable_node(D) COM variable_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR variable_node(C) COM variable_node(D) COM function_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR variable_node(C) COM function_node(D) COM constant_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR variable_node(C) COM function_node(D) COM variable_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR variable_node(C) COM function_node(D) COM function_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR function_node(C) COM constant_node(D) COM constant_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR function_node(C) COM constant_node(D) COM variable_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR function_node(C) COM constant_node(D) COM function_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR function_node(C) COM variable_node(D) COM constant_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR function_node(C) COM variable_node(D) COM variable_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR function_node(C) COM variable_node(D) COM function_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR function_node(C) COM function_node(D) COM constant_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR function_node(C) COM function_node(D) COM variable_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= FUNC(B) LPAR function_node(C) COM function_node(D) COM function_node(E) RPAR. { try { A.Construct(MakeFunctionNode(state, B->GetInt(), *C, *D, *E)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= constant_node(B) BRA constant_node(C) KET. { try { A.Construct(MakeConstantNode(state, 49, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) BRA variable_node(C) KET. { try { A.Construct(MakeFunctionNode(state, 49, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) BRA function_node(C) KET. { try { A.Construct(MakeFunctionNode(state, 49, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) BRA constant_node(C) KET. { try { A.Construct(MakeFunctionNode(state, 49, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) BRA variable_node(C) KET. { try { A.Construct(MakeFunctionNode(state, 49, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) BRA function_node(C) KET. { try { A.Construct(MakeFunctionNode(state, 49, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) BRA constant_node(C) KET. { try { A.Construct(MakeFunctionNode(state, 49, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) BRA variable_node(C) KET. { try { A.Construct(MakeFunctionNode(state, 49, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) BRA function_node(C) KET. { try { A.Construct(MakeFunctionNode(state, 49, *B, *C)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

constant_node(A) ::= constant_node(B) BRA constant_node(C) COM constant_node(D) KET. { try { A.Construct(MakeConstantNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) BRA constant_node(C) COM variable_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) BRA constant_node(C) COM function_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) BRA variable_node(C) COM constant_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) BRA variable_node(C) COM variable_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) BRA variable_node(C) COM function_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) BRA function_node(C) COM constant_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) BRA function_node(C) COM variable_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= constant_node(B) BRA function_node(C) COM function_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) BRA constant_node(C) COM constant_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) BRA constant_node(C) COM variable_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) BRA constant_node(C) COM function_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) BRA variable_node(C) COM constant_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) BRA variable_node(C) COM variable_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) BRA variable_node(C) COM function_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) BRA function_node(C) COM constant_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) BRA function_node(C) COM variable_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= variable_node(B) BRA function_node(C) COM function_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) BRA constant_node(C) COM constant_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) BRA constant_node(C) COM variable_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) BRA constant_node(C) COM function_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) BRA variable_node(C) COM constant_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) BRA variable_node(C) COM variable_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) BRA variable_node(C) COM function_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) BRA function_node(C) COM constant_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) BRA function_node(C) COM variable_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }
function_node(A) ::= function_node(B) BRA function_node(C) COM function_node(D) KET. { try { A.Construct(MakeFunctionNode(state, 50, *B, *C, *D)); } catch (const Exception& e) { state->Error(e.GetErrorMessage()); } }

