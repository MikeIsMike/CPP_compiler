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



/* // Represents the value associated with any kind of
// AST node. */
%union{
  /* const Expression *expr; */
  const translation_unit *t_u;
  double number;
  std::string *string;
}


/* // %token T_TIMES T_DIVIDE T_PLUS T_MINUS T_EXPONENT
// %token T_LBRACKET T_RBRACKET
// %token T_LOG T_EXP T_SQRT
// %token T_NUMBER T_VARIABLE
//
// %type <expr> EXPR TERM FACTOR
// %type <number> T_NUMBER
// %type <string> T_VARIABLE T_LOG T_EXP T_SQRT FUNCTION_NAME */

%token

%start translation_unit

%%

enumeration_constant : IDENTIFIER
                ;

primary_expression : IDENTIFIER
                | CONSTANT///change
                | STRING_LITERAL///change
                | PUN_L_BRACKET expression PUN_R_BRACKET
                ;

postfix_expression : primary_expression                                                     {$$ = new Postfix_expression($1, NULL, NULL, NULL, NULL, NULL);}
                | postfix_expression PUN_SL_BRACKET expression PUN_SR_BRACKET               {$$ = new Postfix_expression(NULL, $1, $3, NULL, NULL, NULL);}
                | postfix_expression PUN_L_BRACKET PUN_R_BRACKET                            {$$ = new Postfix_expression(NULL, $1, NULL, NULL, NULL, NULL);}
                | postfix_expression PUN_L_BRACKET argument_expression_list PUN_R_BRACKET   {$$ = new Postfix_expression(NULL, $1, NULL, $3, NULL, NULL);}
                | postfix_expression OP_DOT IDENTIFIER                                      {$$ = new Postfix_expression(NULL, $1, NULL, NULL, $2, $3);}
                | postfix_expression OP_POINTER IDENTIFIER                                  {$$ = new Postfix_expression(NULL, $1, NULL, NULL, $2, $3);}
                | postfix_expression OP_INCREM                                              {$$ = new Postfix_expression(NULL, $1, NULL, NULL, $2, NULL);}
                | postfix_expression OP_DECREM                                              {$$ = new Postfix_expression(NULL, $1, NULL, NULL, $2, NULL);}
                ;

argument_expression_list : assignment_expression                                {$$ = new Argument_expression_list($1, NULL);}
                | argument_expression_list PUN_COMMA assignment_expression      {$$ = new Argument_expression_list($1, $3);}
                ;

unary_expression : postfix_expression                           {$$ = new Unary_expression($1, NULL, NULL, NULL, NULL, NULL);}
                | OP_INCREM unary_expression                    {$$ = new Unary_expression(NULL, $1, $2, NULL, NULL, NULL);}
                | OP_DECREM unary_expression                    {$$ = new Unary_expression(NULL, $1, $2, NULL, NULL, NULL);}
                | unary_operator cast_expression                {$$ = new Unary_expression(NULL, NULL, NULL, $1, $2, NULL);}
                | sizeof unary_expression                       {$$ = new Unary_expression(NULL, $1, $2, NULL, NULL, NULL);}
                | sizeof PUN_L_BRACKET type_name PUN_R_BRACKET  {$$ = new Unary_expression(NULL, $1, NULL, NULL, NULL, $3);}
                ;

unary_operator : OP_AND             {$$ = $1;}
                | OP_ASTERISK       {$$ = $1;}
                | OP_PLUS           {$$ = $1;}
                | OP_MINUS          {$$ = $1;}
                | OP_DESTRUCTOR     {$$ = $1;}
                | OP_NOT            {$$ = $1;}
                ;

cast_expression : unary_expression
                | PUN_L_BRACKET type_name PUN_R_BRACKET cast_expression
                ;

multiplicative_expression : cast_expression
            	| multiplicative_expression OP_ASTERISK cast_expression
            	| multiplicative_expression OP_DIV cast_expression
            	| multiplicative_expression OP_REMAINDER cast_expression
            	;

additive_expression : multiplicative_expression
            	| additive_expression OP_PLUS multiplicative_expression
            	| additive_expression OP_MINUS multiplicative_expression
            	;

shift_expression : additive_expression
            	| shift_expression OP_LEFT_SHIFT additive_expression
            	| shift_expression OP_RIGHT_SHIFT additive_expression
            	;

relational_expression : shift_expression
            	| relational_expression '<' shift_expression ///< and > tokens
            	| relational_expression '>' shift_expression ///< and > tokens
            	| relational_expression OP_LT_EQ shift_expression
            	| relational_expression OP_GT_EQ shift_expression
            	;

equality_expression : relational_expression
            	| equality_expression OP_EQ_CONST relational_expression
            	| equality_expression OP_NE_CONST relational_expression
            	;

and_expression : equality_expression
            	| and_expression OP_AND equality_expression
            	;

exclusive_or_expression : and_expression
            	| exclusive_or_expression OP_EXP and_expression
            	;

inclusive_or_expression : exclusive_or_expression
            	| inclusive_or_expression OP_OR exclusive_or_expression
            	;

logical_and_expression : inclusive_or_expression
            	| logical_and_expression OP_ANDAND inclusive_or_expression
            	;

logical_or_expression : logical_and_expression
            	| logical_or_expression OP_OROR logical_and_expression
            	;

conditional_expression : logical_or_expression                                                          {$$ = new Conditional_expression($1, NULL, NULL);}
            	| logical_or_expression OP_CONDITIONAL expression PUN_COLON conditional_expression      {$$ = new Conditional_expression($1, $3, $5);}
            	;

assignment_expression : conditional_expression                                                          {$$ = new Assignment_expression($1, NULL, NULL, NULL);}
            	| unary_expression assignment_operator assignment_expression                            {$$ = new Assignment_expression(NULL, $1, $2, $3);}
            	;

assignment_operator : PUN_EQUALS           {$$ = $1;}
            	| OP_MUL_ASSIGN            {$$ = $1;}
            	| OP_DIV_ASSIGN            {$$ = $1;}
            	| OP_MOD_ASSIGN            {$$ = $1;}
            	| OP_PLUS_ASSIGN           {$$ = $1;}
            	| OP_MINUS_ASSIGN          {$$ = $1;}
            	| OP_LEFT_ASSIGN           {$$ = $1;}
            	| OP_RIGHT_ASSIGN          {$$ = $1;}
            	| OP_AND_ASSIGN            {$$ = $1;}
            	| OP_XOR_ASSIGN            {$$ = $1;}
            	| OP_OR_ASSIGN             {$$ = $1;}
            	;

expression :      assignment_expression                                     {$$ = new Expression($1, NULL);}
            	| expression PUN_COMMA assignment_expression                {$$ = new Expression($1, $3);}
            	;

constant_expression : conditional_expression                                {$$ = new Constant_expression($1);}
            	;

declaration :     declaration_specifiers PUN_SEMIC                          {$$ = new Declaration($1, NULL);}
	            | declaration_specifiers init_declarator_list PUN_SEMIC     {$$ = new Declaration($1, $2);}
	            ;

declaration_specifiers : storage_class_specifier                            {$$ = new Declaration_specifiers($1, NULL, NULL, NULL);}
                | storage_class_specifier declaration_specifiers            {$$ = new Declaration_specifiers($1, NULL, NULL, $2);
                | type_specifier                                            {$$ = new Declaration_specifiers(NULL, $1, NULL, NULL);
                | type_specifier declaration_specifiers                     {$$ = new Declaration_specifiers(NULL, $1, NULL, $2);
                | type_qualifier                                            {$$ = new Declaration_specifiers(NULL, NULL, $1, NULL);
                | type_qualifier declaration_specifiers                     {$$ = new Declaration_specifiers(NULL, NULL, $1, $2);
                ;

init_declarator_list : init_declarator                                      {$$ = new Init_declarator_list($1, NULL);
            	| init_declarator_list PUN_COMMA init_declarator            {$$ = new Init_declarator_list($1, $3);
            	;

init_declarator: declarator                                                 {$$ = new Init_declarator($1, NULL);
            	| declarator PUN_EQUALS initializer                         {$$ = new Init_declarator($1, $3);
            	;

storage_class_specifier : KEYW_TYPEDEF                                      {$$ = new Storage_class_specifier($1);}
                | KEYW_EXTERN                                               {$$ = new Storage_class_specifier($1);}
                | KEYW_STATIC                                               {$$ = new Storage_class_specifier($1);}
                | KEYW_AUTO                                                 {$$ = new Storage_class_specifier($1);}
                | KEYW_REGISTER                                             {$$ = new Storage_class_specifier($1);}
                ;

type_specifier : TYPE_VOID                                                  {$$ = new Type_specifier($1, NULL, NULL, NULL);}
                | TYPE_CHAR                                                 {$$ = new Type_specifier($1, NULL, NULL, NULL);}
                | TYPE_SHORT                                                {$$ = new Type_specifier($1, NULL, NULL, NULL);}
                | TYPE_INT                                                  {$$ = new Type_specifier($1, NULL, NULL, NULL);}
                | TYPE_LONG                                                 {$$ = new Type_specifier($1, NULL, NULL, NULL);}
                | TYPE_FLOAT                                                {$$ = new Type_specifier($1, NULL, NULL, NULL);}
                | TYPE_DOUBLE                                               {$$ = new Type_specifier($1, NULL, NULL, NULL);}
                | TYPE_SIGNED                                               {$$ = new Type_specifier($1, NULL, NULL, NULL);}
                | TYPE_UNSIGNED                                             {$$ = new Type_specifier($1, NULL, NULL, NULL);}
                | struct_or_union_specifier                                 {$$ = new Type_specifier(NULL, $1, NULL, NULL);}
                | enum_specifier                                            {$$ = new Type_specifier(NULL, NULL, $1, NULL);}
                | typedef_name                                              {$$ = new Type_specifier(NULL, NULL, NULL, $1);}
                ;

struct_or_union_specifier : struct_or_union IDENTIFIER PUN_CL_BRACKET struct_declaration_list PUN_CR_BRACKET
            	| struct_or_union PUN_CL_BRACKET struct_declaration_list PUN_CR_BRACKET
            	| struct_or_union IDENTIFIER
            	;

struct_or_union : KEYW_STRUCT
            	;

struct_declaration_list : struct_declaration
            	| struct_declaration_list struct_declaration
            	;

struct_declaration : specifier_qualifier_list struct_declarator_list PUN_SEMIC
            	;

specifier_qualifier_list : type_specifier specifier_qualifier_list
            	| type_specifier
            	| type_qualifier specifier_qualifier_list
            	| type_qualifier
            	;

struct_declarator_list : struct_declarator
            	| struct_declarator_list PUN_COMMA struct_declarator
            	;

struct_declarator : declarator
        	    | PUN_COLON constant_expression
            	| declarator PUN_COLON constant_expression
            	;

enum_specifier : ENUM PUN_CL_BRACKET enumerator_list PUN_CR_BRACKET
            	| ENUM IDENTIFIER PUN_CL_BRACKET enumerator_list PUN_CR_BRACKET
            	| ENUM IDENTIFIER
            	;

enumerator_list : enumerator
            	| enumerator_list PUN_COMMA enumerator
            	;

enumerator : enumeration_constant
            	| enumeration_constant PUN_EQUALS constant_expression
            	;

type_qualifier : KEYW_CONST                                                 {$$ = new Type_qualifier($1);}
            	| KEYW_VOLATILE                                             {$$ = new Type_qualifier($1);}
            	;

declarator : pointer direct_declarator                                      {$$ = new Declarator($1, $2);}
            	| direct_declarator                                         {$$ = new Declarator(NULL, $2);}
            	;

direct_declarator : IDENTIFIER                                                             {$$ = new Direct_declarator($1, NULL, NULL, NULL, NULL, NULL, 1)}
            	| PUN_L_BRACKET declarator PUN_R_BRACKET                                   {$$ = new Direct_declarator(NULL, $2, NULL, NULL, NULL, NULL, 2)}
            	| direct_declarator PUN_SL_BRACKET constant_expression PUN_SR_BRACKET      {$$ = new Direct_declarator(NULL, NULL, $1, $3, NULL, NULL, 3)}
            	| direct_declarator PUN_SL_BRACKET PUN_SR_BRACKET                          {$$ = new Direct_declarator(NULL, NULL, $1, NULL, NULL, NULL, 4)}
            	| direct_declarator PUN_L_BRACKET parameter_type_list PUN_R_BRACKET        {$$ = new Direct_declarator(NULL, NULL, $1, NULL, $3, NULL, 5)}
            	| direct_declarator PUN_L_BRACKET identifier_list PUN_R_BRACKET            {$$ = new Direct_declarator(NULL, NULL, $1, NULL, NULL, $3, 6)}
            	| direct_declarator PUN_L_BRACKET PUN_R_BRACKET                            {$$ = new Direct_declarator(NULL, NULL, $1, NULL, NULL, NULL, 7)}
            	;

pointer : OP_ASTERISK
            	| OP_ASTERISK type_qualifier_list
            	| OP_ASTERISK pointer
            	| OP_ASTERISK type_qualifier_list pointer
            	;

type_qualifier_list : type_qualifier
            	| type_qualifier_list type_qualifier
            	;


parameter_type_list : parameter_list
            	| parameter_list PUN_COMMA PUN_ELLIPSIS
            	;

parameter_list : parameter_declaration
            	| parameter_list PUN_COMMA parameter_declaration
            	;

parameter_declaration : declaration_specifiers declarator
            	| declaration_specifiers abstract_declarator
            	| declaration_specifiers
            	;

identifier_list : IDENTIFIER
            	| identifier_list PUN_COMMA IDENTIFIER
            	;

type_name : specifier_qualifier_list
            	| specifier_qualifier_list abstract_declarator
            	;

abstract_declarator : pointer
            	| direct_abstract_declarator
            	| pointer direct_abstract_declarator
            	;

direct_abstract_declarator : PUN_L_BRACKET abstract_declarator PUN_R_BRACKET
            	| PUN_SL_BRACKET PUN_SR_BRACKET
            	| PUN_SL_BRACKET constant_expression PUN_SR_BRACKET
            	| direct_abstract_declarator PUN_SL_BRACKET PUN_SR_BRACKET
            	| direct_abstract_declarator PUN_SL_BRACKET constant_expression PUN_SR_BRACKET
            	| PUN_L_BRACKET PUN_R_BRACKET
            	| PUN_L_BRACKET parameter_type_list PUN_R_BRACKET
            	| direct_abstract_declarator PUN_L_BRACKET PUN_R_BRACKET
            	| direct_abstract_declarator PUN_L_BRACKET parameter_type_list PUN_R_BRACKET
            	;

typedef_name: IDENTIFIER                                                    { $$ = new Typedef_name($1); }
                ;

initializer : assignment_expression
            	| PUN_CL_BRACKET initializer_list PUN_CR_BRACKET
            	| PUN_CL_BRACKET initializer_list PUN_COMMA PUN_CR_BRACKET
            	;

initializer_list : initializer
            	| initializer_list PUN_COMMA initializer
            	;

statement : labeled_statement
            	| compound_statement
            	| expression_statement
            	| selection_statement
            	| iteration_statement
            	| jump_statement
            	;

labeled_statement : IDENTIFIER PUN_COLON statement
            	| KEYW_CASE constant_expression PUN_COLON statement
            	| DEFAULT PUN_COLON statement
            	;

compound_statement : PUN_CL_BRACKET PUN_CR_BRACKET
            	| PUN_CL_BRACKET statement_list PUN_CR_BRACKET
            	| PUN_CL_BRACKET declaration_list PUN_CR_BRACKET
            	| PUN_CL_BRACKET declaration_list statement_list PUN_CR_BRACKET
            	;

declaration_list : declaration
            	| declaration_list declaration
            	;

statement_list : statement
            	| statement_list statement
            	;

expression_statement : PUN_SEMIC
            	| expression PUN_SEMIC
            	;

selection_statement : KEYW_IF PUN_L_BRACKET expression PUN_R_BRACKET statement
            	| KEYW_IF PUN_L_BRACKET expression PUN_R_BRACKET statement ELSE statement
                | KEYW_SWITCH PUN_L_BRACKET expression PUN_R_BRACKET statement
            	;

iteration_statement : KEYW_WHILE PUN_L_BRACKET expression PUN_R_BRACKET statement
            	| KEYW_DO statement KEYW_WHILE PUN_L_BRACKET expression PUN_R_BRACKET PUN_SEMIC
            	| KEYW_FOR PUN_L_BRACKET expression_statement expression_statement PUN_R_BRACKET statement
            	| KEYW_FOR PUN_L_BRACKET expression_statement expression_statement expression PUN_R_BRACKET statement
            	;

jump_statement : KEYW_CONTINUE PUN_SEMIC
            	| KEYW_BREAK PUN_SEMIC
            	| KEYW_RETURN PUN_SEMIC
            	| KEYW_RETURN expression PUN_SEMIC
            	;

translation_unit : external_declaration                     { $$ = new Translation_unit($1, NULL); }
                | translation_unit external_declaration     { $$ = new Translation_unit($2, $1); }
                ;

external_declaration : function_definition                  { $$ = new External_declaration($1, NULL); }
                | declaration                               { $$ = new External_declaration(NULL, $1); }
                ;

function_definition : declarator
                | declaration_specifiers declarator
                | compound_statement
                | declaration_list compound_statement
                ;






/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */




/* function_definition : declaration_specifiers declarator declaration_list compound_statement
               | declaration_specifiers declarator compound_statement
               | declarator declaration_list compound_statement
               | declarator compound_statement
               ; */

/* ///IDENTIFIER, floating_constant, integer_constant, character_constant, STRING_LITERAL */

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
