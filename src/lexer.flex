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
"auto"			  { return KEYW_AUTO; }
"break"			  { return KEYW_BREAK; }

"case"			  { return KEYW_CASE; }
"char"            { return TYPE_CHAR; }
"const"			  { return KEYW_CONST; }
"continue"		  { return KEYW_CONTINUE; }


"default"		  { return KEYW_DEFAULT; }
"do"			  { return KEYW_DO; }

"double"		  { return TYPE_DOUBLE; }
"else"            { return KEYW_ELSE; }
"extern"		  { return KEYW_EXTERN; }
"float"			  { return TYPE_FLOAT; }
"for"			  { return KEYW_FOR; }

"if"              { return KEYW_IF; }
"int"             { return TYPE_INT; }
"long"			  { return TYPE_LONG; }


"register"		  { return KEYW_REGISTER; }
"return"		  { return KEYW_RETURN; }
"short"			  { return TYPE_SHORT; }
"signed"	      { return TYPE_SIGNED; }
"sizeof"          { return KEYW_SIZEOF; }
"static"		  { return KEYW_STATIC; }
"struct"		  { return KEYW_STRUCT; }
"switch"		  { return KEYW_SWITCH; }
"typedef"		  { return KEYW_TYPEDEF; }
"unsigned"	      { return TYPE_UNSIGNED; }
"void"			  { return TYPE_VOID; }
"volatile"		  { return KEYW_VOLATILE; }
"while"			  { return KEYW_WHILE; }

[a-zA-Z_][a-zA-Z_0-9]*              { yylval.string=new std::string(yytext); return IDENTIFIER; }

[0-9]+([Ee][+-]?[0-9]+){FS}?              { yylval.number=strtod(yytext, 0); return T_NUMBER; }
[0-9]*"."[0-9]+([Ee][+-]?[0-9]+)?{FS}?	    { yylval.number=strtod(yytext, 0); return T_NUMBER; }
[0-9]+"."([Ee][+-]?[0-9]+)?{FS}?	    { yylval.number=strtod(yytext, 0); return T_NUMBER; }

0[xX]{H}+{IS}?      { yylval.number = strtod(yytext, 0); return CONSTANT; }
0[0-7]+{IS}?		{ yylval.number = strtod(yytext, 0); return CONSTANT; }
[0-9]+{IS}?		{ yylval.number = strtod(yytext, 0); return CONSTANT; }





L?\'(\\.|[^\\'])+\'	{ yylval.string = new std::string(yytext); return CONSTANT; }  /*char constant*/
L?\"(\\.|[^\\"])*\"	{ yylval.string = new std::string(yytext); return CONSTANT; }  /*string literal*/






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

(==)|           { return OP_EQ_CONST; }
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
