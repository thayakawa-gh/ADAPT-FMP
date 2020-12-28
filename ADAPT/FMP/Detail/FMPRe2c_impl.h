/* Generated by re2c */
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

	
		{
			char yych;
			yych = *mCursor;
			switch (yych) {
			case 0x00:	goto yy2;
			case '\t':
			case '\n':
			case '\f':
			case '\r':
			case ' ':	goto yy6;
			case '!':	goto yy8;
			case '%':	goto yy9;
			case '&':	goto yy11;
			case '\'':	goto yy12;
			case '(':	goto yy14;
			case ')':	goto yy16;
			case '*':	goto yy18;
			case '+':	goto yy20;
			case ',':	goto yy22;
			case '-':	goto yy24;
			case '.':	goto yy26;
			case '/':	goto yy29;
			case '0':	goto yy31;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy33;
			case '<':	goto yy35;
			case '=':	goto yy37;
			case '>':	goto yy38;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy40;
			case '[':	goto yy43;
			case ']':	goto yy45;
			case '^':	goto yy47;
			case '|':	goto yy49;
			default:	goto yy4;
			}
yy2:
			++mCursor;
			{
			return 0;
		}
yy4:
			++mCursor;
yy5:
			{
			char buf[9];
			strncpy(buf, mToken, 8);
			buf[8] = '\0';
			printf("unexpected character: '%s'...\n", buf);
			return -1;
		}
yy6:
			++mCursor;
			{
			goto std;
		}
yy8:
			yych = *++mCursor;
			switch (yych) {
			case '=':	goto yy50;
			default:	goto yy5;
			}
yy9:
			++mCursor;
			{
			return FMP_TOKEN_MOD;
		}
yy11:
			yych = *++mCursor;
			switch (yych) {
			case '&':	goto yy52;
			default:	goto yy5;
			}
yy12:
			yych = *++mCursor;
			switch (yych) {
			case '\'':	goto yy54;
			default:	goto yy12;
			}
yy14:
			++mCursor;
			{ return FMP_TOKEN_LPAR; }
yy16:
			++mCursor;
			{ return FMP_TOKEN_RPAR; }
yy18:
			++mCursor;
			{
			return FMP_TOKEN_MUL;
		}
yy20:
			++mCursor;
			{
			return FMP_TOKEN_ADD;
		}
yy22:
			++mCursor;
			{ return FMP_TOKEN_COM; }
yy24:
			++mCursor;
			{
			return FMP_TOKEN_SUB;
		}
yy26:
			yych = *++mCursor;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy26;
			default:	goto yy28;
			}
yy28:
			{
			yylval.Reset(stod(this->Text()));
			return FMP_TOKEN_FLT;
		}
yy29:
			++mCursor;
			{
			return FMP_TOKEN_DIV;
		}
yy31:
			yych = *(mMarker = ++mCursor);
			switch (yych) {
			case '.':	goto yy26;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy56;
			default:	goto yy32;
			}
yy32:
			{
			yylval.Reset(stoll(this->Text()));
			return FMP_TOKEN_INT;
		}
yy33:
			yych = *++mCursor;
			switch (yych) {
			case '.':	goto yy26;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy33;
			default:	goto yy32;
			}
yy35:
			yych = *++mCursor;
			switch (yych) {
			case '=':	goto yy59;
			default:	goto yy36;
			}
yy36:
			{
			return FMP_TOKEN_LT;
		}
yy37:
			yych = *++mCursor;
			switch (yych) {
			case '=':	goto yy61;
			default:	goto yy5;
			}
yy38:
			yych = *++mCursor;
			switch (yych) {
			case '=':	goto yy63;
			default:	goto yy39;
			}
yy39:
			{
			return FMP_TOKEN_GT;
		}
yy40:
			yych = *++mCursor;
			switch (yych) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto yy40;
			default:	goto yy42;
			}
yy42:
			{
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
						yylval.Reset(static_cast<const std::string*>(ptr_type.first));
						return FMP_TOKEN_STRARG;
					}
					case VALUE_VEC:
					{
						yylval.Reset(static_cast<const Eigen::VectorXd*>(ptr_type.first));
						return FMP_TOKEN_VECARG;
					}
					case VALUE_MAT:
					{
						yylval.Reset(static_cast<const Eigen::MatrixXd*>(ptr_type.first));
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
yy43:
			++mCursor;
			{ return FMP_TOKEN_BRA; }
yy45:
			++mCursor;
			{ return FMP_TOKEN_KET; }
yy47:
			++mCursor;
			{
			return FMP_TOKEN_POW;
		}
yy49:
			yych = *++mCursor;
			switch (yych) {
			case '|':	goto yy65;
			default:	goto yy5;
			}
yy50:
			++mCursor;
			{
			return FMP_TOKEN_NEQ;
		}
yy52:
			++mCursor;
			{
			return FMP_TOKEN_AND;
		}
yy54:
			++mCursor;
			{
			std::string str = this->String();
			yylval.Reset(str);
			return FMP_TOKEN_STR;
		}
yy56:
			yych = *++mCursor;
			switch (yych) {
			case '.':	goto yy26;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto yy56;
			default:	goto yy58;
			}
yy58:
			mCursor = mMarker;
			goto yy32;
yy59:
			++mCursor;
			{
			return FMP_TOKEN_LEQ;
		}
yy61:
			++mCursor;
			{
			return FMP_TOKEN_EQ;
		}
yy63:
			++mCursor;
			{
			return FMP_TOKEN_GEQ;
		}
yy65:
			++mCursor;
			{
			return FMP_TOKEN_OR;
		}
		}


}

}

}

}

#endif