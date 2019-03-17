%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
%}

H			      [a-fA-F0-9]
IS                (([uU][lL]?)|([lL][uU]?))
FS                [fFlL]


%%
"auto"			  { yylval.string = new std::string("auto");
                    return KEYW_AUTO; }
"break"			  { yylval.string = new std::string("break");
                    return KEYW_BREAK; }

"case"			  { yylval.string = new std::string("case");
                    return KEYW_CASE; }
"char"            { yylval.string = new std::string("char");
                    return TYPE_CHAR; }
"const"			  { yylval.string = new std::string("const");
                    return KEYW_CONST; }
"continue"		  { yylval.string = new std::string("continue");
                    return KEYW_CONTINUE; }


"default"		  { yylval.string = new std::string("default");
                    return KEYW_DEFAULT; }
"do"			  { yylval.string = new std::string("do");
                    return KEYW_DO; }
"double"		  { yylval.string = new std::string("double");
                    return TYPE_DOUBLE; }
"else"            { yylval.string = new std::string("else");
                    return KEYW_ELSE; }
"enum"			  { yylval.string = new std::string("enum");
                    return KEYW_ENUM; }
"extern"		  { yylval.string = new std::string("extern");
                    return KEYW_EXTERN; }
"float"			  { yylval.string = new std::string("float");
                    return TYPE_FLOAT; }
"for"			  { yylval.string = new std::string("for");
                    return KEYW_FOR; }
"if"              { yylval.string = new std::string("if");
                    return KEYW_IF; }
"int"             { yylval.string = new std::string("int");
                    return TYPE_INT; }
"long"			  { yylval.string = new std::string("long");
                    return TYPE_LONG; }


"register"		  { yylval.string = new std::string("register");
                    return KEYW_REGISTER; }
"return"		  { yylval.string = new std::string("return");
                    return KEYW_RETURN; }
"short"			  { yylval.string = new std::string("short");
                    return TYPE_SHORT; }
"signed"	      { yylval.string = new std::string("signed");
                    return TYPE_SIGNED; }
"sizeof"          { yylval.string = new std::string("sizeof");
                    return KEYW_SIZEOF; }
"static"		  { yylval.string = new std::string("static");
                    return KEYW_STATIC; }
"struct"		  { yylval.string = new std::string("struct");
                    return KEYW_STRUCT; }
"switch"		  { yylval.string = new std::string("switch");
                    return KEYW_SWITCH; }
"typedef"		  { yylval.string = new std::string("typedef");
                    return KEYW_TYPEDEF; }
"unsigned"	      { yylval.string = new std::string("unsigned");
                    return TYPE_UNSIGNED; }
"void"			  { yylval.string = new std::string("void");
                    return TYPE_VOID; }
"volatile"		  { yylval.string = new std::string("volatile");
                    return KEYW_VOLATILE; }
"while"			  { yylval.string = new std::string("while");
                    return KEYW_WHILE; }

[a-zA-Z_][a-zA-Z_0-9]*              { yylval.string=new std::string(yytext); return IDENTIFIER; }

[0-9]+([Ee][+-]?[0-9]+){FS}?              { yylval.number=strtod(yytext, 0); return CONSTANT; }
[0-9]*"."[0-9]+([Ee][+-]?[0-9]+)?{FS}?	    { yylval.number=strtod(yytext, 0); return CONSTANT; }
[0-9]+"."([Ee][+-]?[0-9]+)?{FS}?	    { yylval.number=strtod(yytext, 0); return CONSTANT; }

0[xX]{H}+{IS}?      { yylval.number = strtod(yytext, 0); return CONSTANT; }
0[0-7]+{IS}?		{ yylval.number = strtod(yytext, 0); return CONSTANT; }
[0-9]+{IS}?		{ yylval.number = strtod(yytext, 0); return CONSTANT; }





L?\'(\\.|[^\\'])+\'	{ yylval.string = new std::string(yytext); return CONSTANT; }  /*char constant*/
L?\"(\\.|[^\\"])*\"	{ yylval.string = new std::string(yytext); return STRING_LITERAL; }  /*string literal*/






[*]             { return OP_ASTERISK; }
[\/]            { return OP_DIV; }
[%]             { return OP_REMAINDER; }
[+]             { return OP_PLUS; }
[-]             { return OP_MINUS; }
[\^]              { return OP_EXP;}


&&              { return OP_ANDAND; }
(\|\|)              { return OP_OROR; }
&               { return OP_AND; }
\|              { return OP_OR; }

(==)            { return OP_EQ_CONST; }
(!=)	        { return OP_NE_CONST; }
(<=)            { return OP_LT_EQ; }
(>=)            { return OP_GT_EQ; }
(<)             { return OP_LT; }
(>)             { return OP_GT; }

[?]             { return OP_CONDITIONAL;}

(>>)		    { return OP_RIGHT_SHIFT; }
(<<)            { return OP_LEFT_SHIFT; }

"++"		    { return OP_INCREM; }
"--"            { return OP_DECREM; }
(->)			{ return OP_POINTER; }

"*="            { return OP_MUL_ASSIGN; }
"/="            { return OP_DIV_ASSIGN; }
"+="            { return OP_PLUS_ASSIGN; }
"%="            { return OP_MOD_ASSIGN; }
"-="            { return OP_MINUS_ASSIGN; }
"<<="           { return OP_LEFT_ASSIGN; }
">>="           { return OP_RIGHT_ASSIGN; }
"&="            { return OP_AND_ASSIGN; }
"^="            { return OP_XOR_ASSIGN; }
"|="            { return OP_OR_ASSIGN; }

[!]             { return OP_NOT; }

[.]             { return OP_DOT;}

[~]             { return OP_DESTRUCTOR; }



[(]             { return PUN_L_BRACKET; }
[)]             { return PUN_R_BRACKET; }
[{]             { return PUN_CL_BRACKET; }
[}]             { return PUN_CR_BRACKET; }
[\[]            { return PUN_SL_BRACKET; }
[\]]            { return PUN_SR_BRACKET; }

[\;]            { return PUN_SEMIC;}
[,]             { return PUN_COMMA;}
[:]             { return PUN_COLON;}
[=]             { return PUN_EQUALS;}
"..."           { return PUN_ELLIPSIS;}
(\#)            { return HASHTAG;}
(\#\#)          { return DOUBLE_HASHTAG;}



[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}

/* int check_type()
{
	if (yytext == type_name)
		return TYPE_NAME;

	return IDENTIFIER;


	return IDENTIFIER;
} */
