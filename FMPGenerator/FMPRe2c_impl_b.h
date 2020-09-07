#ifndef FMPRE2C_IMPL_H
#define FMPRE2C_IMPL_H

#include <ADAPT/FMP/Detail/FMPRe2c.h>

namespace adapt
{

namespace fmp
{

namespace detail
{

int FMPRe2c::Scan(Trivializer<NodeValue>& yylval)
{
std:
	mToken = mCursor;

	/*!re2c
		re2c:define:YYCTYPE = "char";
		re2c:define:YYCURSOR = mCursor;
		re2c:define:YYMARKER = mMarker;
		re2c:define:YYLIMIT = mLimit;
		re2c:yyfill:enable = 0;
		re2c:indent:top = 2;
		re2c:indent:string="	";

		STRING			= ['][^']*['];
		SIGNATURE		= [a-zA-Z_][a-zA-Z0-9_]*;
		FLOAT			= [0-9]*[.][0-9]*;
		INTEGER			= [1-9][0-9]*|[0];
		WS				= [ \r\n\t\f];
		END				= [\000];//終端文字は何故か\000らしい。
		ANY_CHARACTER	= [^];

		"^" {
			return FMP_TOKEN_POW;
		}
		"+" {
			return FMP_TOKEN_ADD;
		}
		"-" {
			return FMP_TOKEN_SUB;
		}
		"*" {
			return FMP_TOKEN_MUL;
		}
		"/" {
			return FMP_TOKEN_DIV;
		}
		"%" {
			return FMP_TOKEN_MOD;
		}
		">" {
			return FMP_TOKEN_GT;
		}
		">=" {
			return FMP_TOKEN_GEQ;
		}
		"<" {
			return FMP_TOKEN_LT;
		}
		"<=" {
			return FMP_TOKEN_LEQ;
		}
		"==" {
			return FMP_TOKEN_EQ;
		}
		"!=" {
			return FMP_TOKEN_NEQ;
		}
		"&&" {
			return FMP_TOKEN_AND;
		}
		"||" {
			return FMP_TOKEN_OR;
		}
		"(" { return FMP_TOKEN_LPAR; }
		")" { return FMP_TOKEN_RPAR; }
		"[" { return FMP_TOKEN_BRA; }
		"]" { return FMP_TOKEN_KET; }
		"," { return FMP_TOKEN_COM; }
		STRING {
			std::string str = this->String();
			yylval.Reset(adapt::String(str.c_str()));
			return FMP_TOKEN_STR;
		}
		SIGNATURE {
			std::string str = this->Text();
			const auto& m = gFuncNames;
			{
				//
				auto it = m.find(str);
				if (it != m.end())
				{
					yylval.Reset((int64_t)it->second);
					return FMP_TOKEN_FUNC;
				}
			}
			{
				auto ptr_type = FindArg(str);

				if (ptr_type.second != VALUE_END)
				{
					//yylval.arg_value = ptr_type.first;
					switch (ptr_type.second)
					{
					case VALUE_INT:
					{
						yylval.Reset(static_cast<const int64_t*>(ptr_type.first));
						return FMP_TOKEN_INTARG;
					}
					case VALUE_FLT:
					{
						yylval.Reset(static_cast<const double*>(ptr_type.first));
						return FMP_TOKEN_FLTARG;
					}
					case VALUE_STR:
					{
						yylval.Reset(static_cast<const adapt::String*>(ptr_type.first));
						return FMP_TOKEN_STRARG;
					}
					case VALUE_VEC:
					{
						yylval.Reset(static_cast<const adapt::Vector<double>*>(ptr_type.first));
						return FMP_TOKEN_VECARG;
					}
					case VALUE_MAT:
					{
						yylval.Reset(static_cast<const adapt::Matrix<double, 2>*>(ptr_type.first));
						return FMP_TOKEN_MATARG;
					}
					default: break;
					}
				}
			}
			{
				try
				{
					auto c = FindConst(str);
					auto t = c.GetType();
					yylval.Reset(std::move(c));
					switch (t)
					{
					case VALUE_INT: return FMP_TOKEN_INT;
					case VALUE_FLT: return FMP_TOKEN_FLT;
					case VALUE_STR: return FMP_TOKEN_STR;
					case VALUE_VEC: return FMP_TOKEN_VEC;
					case VALUE_MAT: return FMP_TOKEN_MAT;
					default: break;
					}
				}
				catch (const OutOfRange&) {}
			}
			return -1;
		}
		INTEGER {
			yylval.Reset(stoll(this->Text()));
			return FMP_TOKEN_INT;
		}
		FLOAT {
			yylval.Reset(stod(this->Text()));
			return FMP_TOKEN_FLT;
		}
		WS {
			goto std;
		}
		END {
			return 0;
		}
		ANY_CHARACTER {
			char buf[9];
			strncpy(buf, mToken, 8);
			buf[8] = '\0';
			printf("unexpected character: '%s'...\n", buf);
			return -1;
		}

	*/

}

}

}

}

#endif