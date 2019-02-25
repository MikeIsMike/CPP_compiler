%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "parser.tab.hpp"
%}


%%
"int"             { return TYPE_INT;}
"else"            { return KEYW_ELSE;}
"if"              { return KEYW_IF;}
"while"           { return KEYW_WHILE;}
"sizeof"          { return KEYW_SIZEOF; }

[a-zA-Z_][a-zA-Z_0-9]*              { yylval.string=new std::string(yytext); return IDENTIFIER; }

[0-9]+([Ee][+-]?[0-9]+)               { yylval.number=strtod(yytext, 0); return T_NUMBER; }
[0-9]*"."[0-9]+([Ee][+-]?[0-9]+)?	    { yylval.number=strtod(yytext, 0); return T_NUMBER; }
[0-9]+"."[0-9]*([Ee][+-]?[0-9]+)?	    { yylval.number=strtod(yytext, 0); return T_NUMBER; }


[*]             { return OP_TIMES; }
[\/]            { return OP_DIV; }
[%]             { return OP_REMAINDER; }
[+]             { return OP_PLUS; }
[-]             { return OP_MINUS; }
[\^]              { return OP_EXP;}


&&              { return OP_ANDAND; }
(\|\|)              { return OP_OROR; }
&               { return OP_AND; }
\|              { return OP_OR; }

(==)|(!=)	    { return OP_EQ_CONST; }
(<=)|(>=)|(<)|(>)   { return OP_COMPARE; }
[?]             { return OP_CONDITIONAL;}

(>>)|(<<)		{ return OP_SHIFT; }

"++"|"--"		{ return OP_INCREM; }
(->)			{ return OP_POINT; }

"*=" | "/=" | "+=" | "%=" | ">>=" | "-=" | "<<=" | "&=" | "^=" | "|="		{ return OP_ASSIGNS; }
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
