

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

postfix_expression : primary_expression
                | postfix_expression PUN_SL_BRACKET expression PUN_SR_BRACKET
                | postfix_expression PUN_L_BRACKET PUN_R_BRACKET
                | postfix_expression PUN_L_BRACKET argument_expression_list PUN_R_BRACKET
                | postfix_expression OP_DOT IDENTIFIER
                | postfix_expression OP_POINTER IDENTIFIER
                | postfix_expression OP_INCREM
                | postfix_expression OP_DECREM
                ;

argument_expression_list : assignment_expression
                | argument_expression_list PUN_COMMA assignment_expression
                ;

unary_expression : postfix_expression
                | OP_INCREM unary_expression
                | OP_DECREM unary_expression
                | unary_operator cast_expression
                | sizeof unary_expression
                | sizeof PUN_L_BRACKET type_name PUN_R_BRACKET
                ;

unary_operator : OP_AND
                | OP_ASTERISK
                | OP_PLUS
                | OP_MINUS
                | OP_DESTRUCTOR
                | OP_NOT
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

conditional_expression : logical_or_expression
            	| logical_or_expression OP_CONDITIONAL expression PUN_COLON conditional_expression
            	;

assignment_expression : conditional_expression
            	| unary_expression assignment_operator assignment_expression
            	;

assignment_operator : PUN_EQUALS
            	| OP_MUL_ASSIGN
            	| OP_DIV_ASSIGN
            	| OP_MOD_ASSIGN
            	| OP_PLUS_ASSIGN
            	| OP_MINUS_ASSIGN
            	| OP_LEFT_ASSIGN
            	| OP_RIGHT_ASSIGN
            	| OP_AND_ASSIGN
            	| OP_XOR_ASSIGN
            	| OP_OR_ASSIGN
            	;

expression : assignment_expression
            	| expression PUN_COMMA assignment_expression
            	;

constant_expression : conditional_expression
            	;

declaration : declaration_specifiers PUN_SEMIC
	            | declaration_specifiers init_declarator_list PUN_SEMIC {


                }
	            ;

declaration_specifiers : storage_class_specifier
                | storage_class_specifier declaration_specifiers
                | type_specifier
                | type_specifier declaration_specifiers
                | type_qualifier
                | type_qualifier declaration_specifiers
                ;

init_declarator_list : init_declarator
            	| init_declarator_list PUN_COMMA init_declarator
            	;

init_declarator: declarator
            	| declarator PUN_EQUALS initializer
            	;

storage_class_specifier : KEYW_TYPEDEF
                | KEYW_EXTERN
                | KEYW_STATIC
                | KEYW_AUTO
                | KEYW_REGISTER
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
                | typedef_name
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

type_qualifier : KEYW_CONST
            	| KEYW_VOLATILE
            	;

declarator : pointer direct_declarator
            	| direct_declarator
            	;

direct_declarator : IDENTIFIER
            	| PUN_L_BRACKET declarator PUN_R_BRACKET
            	| direct_declarator PUN_SL_BRACKET constant_expression PUN_SR_BRACKET
            	| direct_declarator PUN_SL_BRACKET PUN_SR_BRACKET
            	| direct_declarator PUN_L_BRACKET parameter_type_list PUN_R_BRACKET
            	| direct_declarator PUN_L_BRACKET identifier_list PUN_R_BRACKET
            	| direct_declarator PUN_L_BRACKET PUN_R_BRACKET
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

typedef_name: IDENTIFIER
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

translation_unit : external_declaration { $$ = new Translation_Unit($1); }
                | translation_unit external_declaration
                    { $$ -> add_declaration($2); }
                ;

external_declaration : function_definition
                | declaration { $$ = $1; }
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
