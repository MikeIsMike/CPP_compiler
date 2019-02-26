

%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}



// Represents the value associated with any kind of
// AST node.
%union{
  const Expression *expr;
  double number;
  std::string *string;
}


// %token T_TIMES T_DIVIDE T_PLUS T_MINUS T_EXPONENT
// %token T_LBRACKET T_RBRACKET
// %token T_LOG T_EXP T_SQRT
// %token T_NUMBER T_VARIABLE
//
// %type <expr> EXPR TERM FACTOR
// %type <number> T_NUMBER
// %type <string> T_VARIABLE T_LOG T_EXP T_SQRT FUNCTION_NAME

%token

%start translation_unit

%%

/* The TODO notes a are just a guide, and are non-exhaustive.
   The expectation is that you do each one, then compile and test.
   Testing should be done using patterns that target the specific
   feature; the testbench is there to make sure that you haven't
   broken anything while you added it.
*/


/*
 ROOT : EXPR { g_root = $1; }

 SENTENCE : SOMETHING T_EOL                        { $$ = $1;}


 EXPR  : TERM                                      { $$ = $1; }
       | EXPR T_PLUS TERM                          { $$ = new AddOperator($1, $3);}
       | EXPR T_MINUS TERM                         { $$ = new SubOperator($1, $3);}


 TERM  : FACTOR                                    { $$ = $1; }
       | TERM T_TIMES FACTOR                       { $$ = new MulOperator($1, $3);}
       | TERM T_DIVIDE FACTOR                      { $$ = new DivOperator($1, $3);}
       | TERM T_EXPONENT FACTOR                    { $$ = new ExpOperator($1, $3);}



 FACTOR : T_NUMBER                                 { $$ = new Number( $1 );}
        | T_VARIABLE                               { $$ = new Variable( *$1 ); }
        | T_LBRACKET EXPR T_RBRACKET               { $$ = $2; }
        | FUNCTION_NAME T_LBRACKET EXPR T_RBRACKET { if(*$1=="log"){
                                                       $$ = new LogFunction($3);
                                                     }
                                                     else if(*$1=="exp"){
                                                       $$ = new ExpFunction($3);
                                                     }
                                                     else if(*$1=="sqrt"){
                                                       $$ = new SqrtFunction($3);
                                                     }

                                                   }


 FUNCTION_NAME : T_LOG                             { $$ = new std::string("log"); }
               | T_EXP                             { $$ = new std::string("exp"); }
               | T_SQRT                            { $$ = new std::string("sqrt");}
*/


primary_expression : IDENTIFIER///change
                | CONSTANT///change
                | STRING_LITERAL///change
                | PUN_L_BRACKET expression PUN_R_BRACKET
                ;

postfix_expression : primary_expression
                | postfix_expression PUN_SL_BRACKET expression PUN_SR_BRACKET
                | postfix_expression PUN_L_BRACKET PUN_R_BRACKET
                | postfix_expression PUN_L_BRACKET argument_expression_list PUN_R_BRACKET
                | postfix_expression OP_DOT IDENTIFIER///change
                | postfix_expression OP_POINTER IDENTIFIER///change
                | postfix_expression OP_INCREM ///may need to separate increment and decrement??
                ;

argument_expression_list : assignment_expression
                | argument_expression_list PUN_COMMA assignment_expression
                ;

unary_expression : postfix_expression
                | OP_INCREM unary_expression ///may need to separate incre and decrement
                | unary_operator cast_expression
                | sizeof unary_expression
                | sizeof PUN_L_BRACKET type_name PUN_R_BRACKET
                ;

unary_operator : OP_AND
                | OP_TIMES
                | OP_PLUS
                | OP_MINUS
                | OP_DESTRUCTOR
                | OP_NOT
                ;

cast_expression : unary_expression
                | PUN_L_BRACKET type_name PUN_R_BRACKET cast_expression
                ;

multiplicative_expression : cast_expression
            	| multiplicative_expression OP_TIMES cast_expression
            	| multiplicative_expression OP_DIV cast_expression
            	| multiplicative_expression OP_REMAINDER cast_expression
            	;

additive_expression : multiplicative_expression
            	| additive_expression OP_PLUS multiplicative_expression
            	| additive_expression OP_MINUS multiplicative_expression
            	;

shift_expression : additive_expression
            	| shift_expression OP_SHIFT additive_expression ///maybe better to split left and right shift?
            	| shift_expression OP_SHIFT additive_expression ///maybe better to split left and right
            	;

relational_expression : shift_expression
            	| relational_expression '<' shift_expression ///< and > tokens
            	| relational_expression '>' shift_expression ///< and > tokens
            	| relational_expression OP_COMPARE shift_expression ///maybe better to have token for <=
            	| relational_expression OP_COMPARE shift_expression ///maybe better to have token for >=
            	;








///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


declaration : declaration_specifiers ';'
	            | declaration_specifiers init_declarator_list ';'
	            ;

declaration_specifiers : storage_class_specifier
                | storage_class_specifier declaration_specifiers
                | type_specifier
                | type_specifier declaration_specifiers
                | type_qualifier
                | type_qualifier declaration_specifiers
                ;

blahblahblah

storage_class_specifier : TYPEDEF
                | EXTERN
                | STATIC
                | AUTO
                | REGISTER
                ;

type_specifier : TYPE_VOID
                | TYPE_CHAR
                | TYPE_SHORT
                | TYPE_INT
                | TYPE_LONG
                | TYPE_FLOAT
                | TYPE_DOUBLE
                | TYPE_SIGNED
                | TYPE_UNSIGNED
                | struct_or_union_specifier
                | enum_specifier
                | TYPE_NAME
                ;


translation_unit : external_declaration
                | translation_unit external_declaration
                ;

external_declaration : function_definition
	           | declaration
	           ;

function_definition : declaration_specifiers declarator declaration_list compound_statement
               | declaration_specifiers declarator compound_statement
               | declarator declaration_list compound_statement
               | declarator compound_statement
               ;

///IDENTIFIER

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
