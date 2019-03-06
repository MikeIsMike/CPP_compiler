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

%token KEYW_AUTO KEYW_BREAK KEYW_CASE KEYW_CONST KEYW_CONTINUE
       KEYW_DEFAULT KEYW_DO KEYW_ELSE KEYW_EXTERN KEYW_FOR KEYW_IF
       KEYW_REGISTER KEYW_RETURN KEYW_SIZEOF KEYW_STATIC KEYW_STRUCT
       KEYW_SWITCH KEYW_TYPEDEF KEYW_VOLATILE KEYW_WHILE
%token TYPE_CHAR TYPE_DOUBLE TYPE_FLOAT TYPE_INT TYPE_LONG TYPE_SHORT
       TYPE_SIGNED TYPE_UNSIGNED TYPE_VOID
%token IDENTIFIER T_NUMBER
%token OP_ASTERISK OP_DIV OP_REMAINDER OP_PLUS OP_MINUS OP_EXP OP_ANDAND
       OP_OROR OP_AND OP_OR OP_EQ_CONST OP_NE_CONST OP_LT_EQ OP_GT_EQ
       OP_LT OP_GT OP_CONDITIONAL OP_RIGHT_SHIFT OP_LEFT_SHIFT OP_INCREM
       OP_DECREM OP_POINTER OP_MUL_ASSIGN OP_DIV_ASSIGN OP_PLUS_ASSIGN
       OP_MOD_ASSIGN OP_MINUS_ASSIGN OP_LEFT_ASSIGN OP_RIGHT_ASSIGN
       OP_AND_ASSIGN OP_XOR_ASSIGN OP_OR_ASSIGN OP_NOT OP_DOT OP_DESTRUCTOR
%token PUN_L_BRACKET PUN_R_BRACKET PUN_CL_BRACKET PUN_CR_BRACKET PUN_SL_BRACKET
       PUN_SR_BRACKET PUN_SEMIC PUN_COMMA PUN_COLON PUN_EQUALS PUN_ELLIPSIS
       HASHTAG DOUBLE_HASHTAG

%start root

%%

root: translation_unit { g_root = $1;}

enumeration_constant : IDENTIFIER                                  {$$ = new Enumeration_constant($1);}
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

cast_expression : unary_expression                                                                      {$$ = new Cast_expression($1, NULL, NULL);}
                | PUN_L_BRACKET type_name PUN_R_BRACKET cast_expression                                 {$$ = new Cast_expression(NULL, $2, $4);}
                ;

multiplicative_expression : cast_expression                                                             {$$ = new Multiplicative_expression($1, NULL, NULL);}
            	| multiplicative_expression OP_ASTERISK cast_expression                                 {$$ = new Multiplicative_expression($3, $1, $2);}
            	| multiplicative_expression OP_DIV cast_expression                                      {$$ = new Multiplicative_expression($3, $1, $2);}
            	| multiplicative_expression OP_REMAINDER cast_expression                                {$$ = new Multiplicative_expression($3, $1, $2);}
            	;

additive_expression : multiplicative_expression                                                         {$$ = new Additive_expression($1, NULL, NULL);}
            	| additive_expression OP_PLUS multiplicative_expression                                 {$$ = new Additive_expression($3, $1, $2);}
            	| additive_expression OP_MINUS multiplicative_expression                                {$$ = new Additive_expression($3, $1, $2);}
            	;

shift_expression : additive_expression                                                                  {$$ = new Shift_expression($1, NULL, NULL);}
            	| shift_expression OP_LEFT_SHIFT additive_expression                                    {$$ = new Relational_expression($3, $1, $2);}
            	| shift_expression OP_RIGHT_SHIFT additive_expression                                   {$$ = new Relational_expression($3, $1, $2);}
            	;

relational_expression : shift_expression                                                                {$$ = new Relational_expression($1, NULL, NULL);}
            	| relational_expression '<' shift_expression                                            {$$ = new Relational_expression($3, $1, $2);} ///TODO: < and > tokens?
            	| relational_expression '>' shift_expression                                            {$$ = new Relational_expression($3, $1, $2);} ///TODO: < and > tokens?
            	| relational_expression OP_LT_EQ shift_expression                                       {$$ = new Relational_expression($3, $1, $2);}
            	| relational_expression OP_GT_EQ shift_expression                                       {$$ = new Relational_expression($3, $1, $2);}
            	;

equality_expression : relational_expression                                                             {$$ = new Equality_expression($1, NULL, NULL);}
            	| equality_expression OP_EQ_CONST relational_expression                                 {$$ = new Equality_expression($3, $1, $2);}
            	| equality_expression OP_NE_CONST relational_expression                                 {$$ = new Equality_expression($3, $1, $2);}
            	;

and_expression : equality_expression                                                                    {$$ = new And_expression($1, NULL);}
            	| and_expression OP_AND equality_expression                                             {$$ = new And_expression($3, $1);}
            	;

exclusive_or_expression : and_expression                                                                {$$ = new Exclusive_or_expression($1, NULL);}
            	| exclusive_or_expression OP_EXP and_expression                                         {$$ = new Exclusive_or_expression($3, $1);}
            	;

inclusive_or_expression : exclusive_or_expression                                                       {$$ = new Inclusive_or_expression($1, NULL);}
            	| inclusive_or_expression OP_OR exclusive_or_expression                                 {$$ = new Inclusive_or_expression($3, $1);}
            	;

logical_and_expression : inclusive_or_expression                                                        {$$ = new Logical_and_expression($1, NULL);}
            	| logical_and_expression OP_ANDAND inclusive_or_expression                              {$$ = new Logical_or_expression($3, $1);}
            	;

logical_or_expression : logical_and_expression                                                          {$$ = new Logical_or_expression($1, NULL);}
            	| logical_or_expression OP_OROR logical_and_expression                                  {$$ = new Logical_or_expression($3, $1);}
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

struct_or_union_specifier : KEYW_STRUCT IDENTIFIER PUN_CL_BRACKET struct_declaration_list PUN_CR_BRACKET        {$$ = new Struct_or_union_specifier($2, $4);}
            	| KEYW_STRUCT PUN_CL_BRACKET struct_declaration_list PUN_CR_BRACKET                             {$$ = new Struct_or_union_specifier(NULL, $3);}
            	| KEYW_STRUCT IDENTIFIER                                                                        {$$ = new Struct_or_union_specifier($2, NULL);}
            	;

struct_declaration_list : struct_declaration                                                                    {$$ = new Struct_declaration_list($1, NULL);}
            	| struct_declaration_list struct_declaration                                                    {$$ = new Struct_declaration_list($2, $1);}
            	;

struct_declaration : specifier_qualifier_list struct_declarator_list PUN_SEMIC                                  {$$ = new Struct_declaration($1, $2);}
            	;

specifier_qualifier_list : type_specifier specifier_qualifier_list         {$$ = new Specifier_qualifier_list($1, $2, NULL);}
            	| type_specifier                                           {$$ = new Specifier_qualifier_list($1, NULL, NULL);}
            	| type_qualifier specifier_qualifier_list                  {$$ = new Specifier_qualifier_list(NULL, $2, $1);}
            	| type_qualifier                                           {$$ = new Specifier_qualifier_list(NULL, NULL, $1);}
            	;

struct_declarator_list : struct_declarator                                 {$$ = new Struct_declarator_list($1, NULL);}
            	| struct_declarator_list PUN_COMMA struct_declarator       {$$ = new Struct_declarator_list($3, $1);}
            	;

struct_declarator : declarator                                             {$$ = new Struct_declarator($1, NULL);}
        	    | PUN_COLON constant_expression                            {$$ = new Struct_declarator(NULL, $2);}
            	| declarator PUN_COLON constant_expression                 {$$ = new Struct_declarator($1, $3);}
            	;

enum_specifier : ENUM PUN_CL_BRACKET enumerator_list PUN_CR_BRACKET                 {$$ = new Enum_specifier($3, NULL);}
            	| ENUM IDENTIFIER PUN_CL_BRACKET enumerator_list PUN_CR_BRACKET     {$$ = new Enum_specifier($4, $2);}
            	| ENUM IDENTIFIER                                                   {$$ = new Enum_specifier(NULL, $2);}
            	;

enumerator_list : enumerator                                                        {$$ = new Enumerator_list($1, NULL);}
            	| enumerator_list PUN_COMMA enumerator                              {$$ = new Enumerator_list($3, $1);}
            	;

enumerator : enumeration_constant                                                   {$$ = new Enumerator($1, NULL);}
            	| enumeration_constant PUN_EQUALS constant_expression               {$$ = new Enumerator($1, $3);}
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

pointer : OP_ASTERISK                                                          {$$ = new Pointer(NULL, NULL);}
            	| OP_ASTERISK type_qualifier_list                              {$$ = new Pointer($2, NULL);}
            	| OP_ASTERISK pointer                                          {$$ = new Pointer(NULL, $2);}
            	| OP_ASTERISK type_qualifier_list pointer                      {$$ = new Pointer($2, $3);}
            	;

type_qualifier_list : type_qualifier                                           {$$ = new Type_qualifier_list($1, NULL);}
            	| type_qualifier_list type_qualifier                           {$$ = new Type_qualifier_list($2, $1);}
            	;


parameter_type_list : parameter_list                                           {$$ = new Parameter_type_list($1, false);}
            	| parameter_list PUN_COMMA PUN_ELLIPSIS                        {$$ = new Parameter_type_list($1, true);}
            	;

parameter_list : parameter_declaration                                         {$$ = new Parameter_list($1, NULL);}
            	| parameter_list PUN_COMMA parameter_declaration               {$$ = new Parameter_list($3, $1);}
            	;

parameter_declaration : declaration_specifiers declarator                      {$$ = new Parameter_declaration($1, $2, NULL);}
            	| declaration_specifiers abstract_declarator                   {$$ = new Parameter_declaration($1, NULL, $2);}
            	| declaration_specifiers                                       {$$ = new Parameter_declaration($1, NULL, NULL);}
            	;

identifier_list : IDENTIFIER                                            {$$ = new Identifier_list($1, NULL);}
            	| identifier_list PUN_COMMA IDENTIFIER                  {$$ = new Identifier_list($3, $1);}
            	;

type_name : specifier_qualifier_list                                    {$$ = new Type_name($1, NULL);}
            	| specifier_qualifier_list abstract_declarator          {$$ = new Type_name($1, $2);}
            	;

abstract_declarator : pointer                                           {$$ = new Abstract_declarator($1, NULL);}
            	| direct_abstract_declarator                            {$$ = new Abstract_declarator(NULL, $1);}
            	| pointer direct_abstract_declarator                    {$$ = new Abstract_declarator($1, $2);}
            	;

direct_abstract_declarator : PUN_L_BRACKET abstract_declarator PUN_R_BRACKET                           {$$ = new Direct_abstract_declarator(1, $2, NULL, NULL, NULL);}
            	| PUN_SL_BRACKET PUN_SR_BRACKET                                                        {$$ = new Direct_abstract_declarator(2, NULL, NULL, NULL, NULL);}
            	| PUN_SL_BRACKET constant_expression PUN_SR_BRACKET                                    {$$ = new Direct_abstract_declarator(3, NULL, $2, NULL, NULL);}
            	| direct_abstract_declarator PUN_SL_BRACKET PUN_SR_BRACKET                             {$$ = new Direct_abstract_declarator(4, NULL, NULL, $1, NULL);}
            	| direct_abstract_declarator PUN_SL_BRACKET constant_expression PUN_SR_BRACKET         {$$ = new Direct_abstract_declarator(5, NULL, $3, $1, NULL);}
            	| PUN_L_BRACKET PUN_R_BRACKET                                                          {$$ = new Direct_abstract_declarator(6, NULL, NULL, NULL, NULL);}
            	| PUN_L_BRACKET parameter_type_list PUN_R_BRACKET                                      {$$ = new Direct_abstract_declarator(7, NULL, NULL, NULL, $2);}
            	| direct_abstract_declarator PUN_L_BRACKET PUN_R_BRACKET                               {$$ = new Direct_abstract_declarator(8, NULL, NULL, $1, NULL);}
            	| direct_abstract_declarator PUN_L_BRACKET parameter_type_list PUN_R_BRACKET           {$$ = new Direct_abstract_declarator(9, NULL, NULL, $1, $3);}
            	;

typedef_name: IDENTIFIER                                                    { $$ = new Typedef_name($1); }
                ;

initializer : assignment_expression                                             { $$ = new Initializer($1, NULL, false);}
            	| PUN_CL_BRACKET initializer_list PUN_CR_BRACKET                { $$ = new Initializer(NULL, $2, false);}
            	| PUN_CL_BRACKET initializer_list PUN_COMMA PUN_CR_BRACKET      { $$ = new Initializer(NULL, $2, true);}
            	;

initializer_list : initializer                                                  { $$ = new Initializer_list($1, NULL);}
            	| initializer_list PUN_COMMA initializer                        { $$ = new Initializer_list($3, $1);}
            	;

statement : labeled_statement                   { $$ = new Statement($1, NULL, NULL, NULL, NULL, NULL); }
            	| compound_statement            { $$ = new Statement(NULL, $1, NULL, NULL, NULL, NULL); }
            	| expression_statement          { $$ = new Statement(NULL, NULL, $1, NULL, NULL, NULL); }
            	| selection_statement           { $$ = new Statement(NULL, NULL, NULL, $1, NULL, NULL); }
            	| iteration_statement           { $$ = new Statement(NULL, NULL, NULL, NULL, $1, NULL); }
            	| jump_statement                { $$ = new Statement(NULL, NULL, NULL, NULL, NULL, $1); }
            	;

labeled_statement : IDENTIFIER PUN_COLON statement                                  { $$ = new Labeled_statement($1, $3, NULL);}
            	| KEYW_CASE constant_expression PUN_COLON statement                 { $$ = new Labeled_statement(NULL, $4, $2);}
            	| DEFAULT PUN_COLON statement                                       { $$ = new Labeled_statement(NULL, $3, NULL);}
            	;

compound_statement : PUN_CL_BRACKET PUN_CR_BRACKET                                  { $$ = new Compound_statement(NULL, NULL);}
            	| PUN_CL_BRACKET statement_list PUN_CR_BRACKET                      { $$ = new Compound_statement($2, NULL);}
            	| PUN_CL_BRACKET declaration_list PUN_CR_BRACKET                    { $$ = new Compound_statement(NULL, $2);}
            	| PUN_CL_BRACKET declaration_list statement_list PUN_CR_BRACKET     { $$ = new Compound_statement($3, $2);}
            	;

declaration_list : declaration                                                      { $$ = new Declaration_list($1, NULL);}
            	| declaration_list declaration                                      { $$ = new Declaration_list($2, $1);}  
            	;

statement_list : statement                                                          { $$ = new Statement_list(NULL, $1);}
            	| statement_list statement                                          { $$ = new Statement_list($1, $2);}
            	;

expression_statement : PUN_SEMIC                                                    { $$ = new Expression_statement(NULL);}
            	| expression PUN_SEMIC                                              { $$ = new Expression_statement($1);}
            	;

selection_statement : KEYW_IF PUN_L_BRACKET expression PUN_R_BRACKET statement                  { $$ = new Selection_statement($3, $5, NULL, false);}
            	| KEYW_IF PUN_L_BRACKET expression PUN_R_BRACKET statement ELSE statement       { $$ = new Selection_statement($3, $5, $7, false);}
                | KEYW_SWITCH PUN_L_BRACKET expression PUN_R_BRACKET statement                  { $$ = new Selection_statement($3, $5, NULL, true);}
            	;

iteration_statement : KEYW_WHILE PUN_L_BRACKET expression PUN_R_BRACKET statement                                           { $$ = new Iteration_statement($3, $5, NULL, NULL, $1);}
            	| KEYW_DO statement KEYW_WHILE PUN_L_BRACKET expression PUN_R_BRACKET PUN_SEMIC                             { $$ = new Iteration_statement($5, $2, NULL, NULL, $1);}
            	| KEYW_FOR PUN_L_BRACKET expression_statement expression_statement PUN_R_BRACKET statement                  { $$ = new Iteration_statement(NULL, $6, $3, $4, $1);}
            	| KEYW_FOR PUN_L_BRACKET expression_statement expression_statement expression PUN_R_BRACKET statement       { $$ = new Iteration_statement($5, $7, $3, $4, $1);}
            	;

jump_statement : KEYW_CONTINUE PUN_SEMIC                    { $$ = new Jump_statement(NULL, $1);}
            	| KEYW_BREAK PUN_SEMIC                      { $$ = new Jump_statement(NULL, $1);}
            	| KEYW_RETURN PUN_SEMIC                     { $$ = new Jump_statement(NULL, $1);}
            	| KEYW_RETURN expression PUN_SEMIC          { $$ = new Jump_statement($2, $1);}
            	;

translation_unit : external_declaration                     { $$ = new Translation_unit($1, NULL); }
                | translation_unit external_declaration     { $$ = new Translation_unit($2, $1); }
                ;

external_declaration : function_definition                  { $$ = new External_declaration($1, NULL); }
                | declaration                               { $$ = new External_declaration(NULL, $1); }
                ;

function_definition : declaration_specifiers declarator declaration_list compound_statement     { $$ = new Function_definition($1, $2, $4, $3);}
                | declaration_specifiers declarator compound_statement                          { $$ = new Function_definition($1, $2, $3, NULL);}
                | declarator declaration_list compound_statement                                { $$ = new Function_definition(NULL, $1, $3, $2);}
                | declarator compound_statement                                                 { $$ = new Function_definition(NULL, $1, $2, NULL);}
                ;






/* /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */




/* function_definition : declaration_specifiers declarator declaration_list compound_statement
               | declaration_specifiers declarator compound_statement
               | declarator declaration_list compound_statement
               | declarator compound_statement
               ; */

/* ///IDENTIFIER, floating_constant, integer_constant, character_constant, STRING_LITERAL */

%%

const Translation_unit *g_root; // Definition of variable (to match declaration earlier)

const Translation_unit *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
