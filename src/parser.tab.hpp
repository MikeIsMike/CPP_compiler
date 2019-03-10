/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y" /* yacc.c:1909  */

  #include "../include/ast.hpp"

  #include <cassert>

  extern const Translation_unit *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 58 "src/parser.tab.hpp" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    KEYW_AUTO = 258,
    KEYW_BREAK = 259,
    KEYW_CASE = 260,
    KEYW_CONST = 261,
    KEYW_CONTINUE = 262,
    KEYW_DEFAULT = 263,
    KEYW_DO = 264,
    KEYW_ELSE = 265,
    KEYW_ENUM = 266,
    KEYW_EXTERN = 267,
    KEYW_FOR = 268,
    KEYW_IF = 269,
    KEYW_REGISTER = 270,
    KEYW_RETURN = 271,
    KEYW_SIZEOF = 272,
    KEYW_STATIC = 273,
    KEYW_STRUCT = 274,
    KEYW_SWITCH = 275,
    KEYW_TYPEDEF = 276,
    KEYW_VOLATILE = 277,
    KEYW_WHILE = 278,
    TYPE_CHAR = 279,
    TYPE_DOUBLE = 280,
    TYPE_FLOAT = 281,
    TYPE_INT = 282,
    TYPE_LONG = 283,
    TYPE_SHORT = 284,
    TYPE_SIGNED = 285,
    TYPE_UNSIGNED = 286,
    TYPE_VOID = 287,
    IDENTIFIER = 288,
    T_NUMBER = 289,
    CONSTANT = 290,
    STRING_LITERAL = 291,
    OP_ASTERISK = 292,
    OP_DIV = 293,
    OP_REMAINDER = 294,
    OP_PLUS = 295,
    OP_MINUS = 296,
    OP_EXP = 297,
    OP_ANDAND = 298,
    OP_OROR = 299,
    OP_AND = 300,
    OP_OR = 301,
    OP_EQ_CONST = 302,
    OP_NE_CONST = 303,
    OP_LT_EQ = 304,
    OP_GT_EQ = 305,
    OP_LT = 306,
    OP_GT = 307,
    OP_CONDITIONAL = 308,
    OP_RIGHT_SHIFT = 309,
    OP_LEFT_SHIFT = 310,
    OP_INCREM = 311,
    OP_DECREM = 312,
    OP_POINTER = 313,
    OP_MUL_ASSIGN = 314,
    OP_DIV_ASSIGN = 315,
    OP_PLUS_ASSIGN = 316,
    OP_MOD_ASSIGN = 317,
    OP_MINUS_ASSIGN = 318,
    OP_LEFT_ASSIGN = 319,
    OP_RIGHT_ASSIGN = 320,
    OP_AND_ASSIGN = 321,
    OP_XOR_ASSIGN = 322,
    OP_OR_ASSIGN = 323,
    OP_NOT = 324,
    OP_DOT = 325,
    OP_DESTRUCTOR = 326,
    PUN_L_BRACKET = 327,
    PUN_R_BRACKET = 328,
    PUN_CL_BRACKET = 329,
    PUN_CR_BRACKET = 330,
    PUN_SL_BRACKET = 331,
    PUN_SR_BRACKET = 332,
    PUN_SEMIC = 333,
    PUN_COMMA = 334,
    PUN_COLON = 335,
    PUN_EQUALS = 336,
    PUN_ELLIPSIS = 337,
    HASHTAG = 338,
    DOUBLE_HASHTAG = 339
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "src/parser.y" /* yacc.c:1909  */

  Translation_unit *t_u;
  double number;
  std::string *string;

  Postfix_expression *postfix_expression_ptr;
  Primary_expression *primary_expression_ptr;
  Expression *expression_ptr;
  Argument_expression_list *argument_expression_list_ptr;
  Assignment_expression *assignment_expression_ptr;
  Unary_expression *unary_expression_ptr;
  Cast_expression *cast_expression_ptr;
  Type_name *type_name_ptr;
  Conditional_expression *conditional_expression_ptr;
  Logical_or_expression *logical_or_expression_ptr;
  Constant_expression *constant_expression_ptr;
  Declaration *declaration_ptr;
  Declaration_specifiers *declaration_specifiers_ptr;
  Init_declarator_list *init_declarator_list_ptr;
  Storage_class_specifier *storage_class_specifier_ptr;
  Enumeration_constant *enumeration_constant_ptr;
  Multiplicative_expression *multiplicative_expression_ptr;
  Additive_expression *additive_expression_ptr;
  Shift_expression *shift_expression_ptr;
  Relational_expression *relational_expression_ptr;
  Equality_expression *equality_expression_ptr;
  And_expression *and_expression_ptr;
  Exclusive_or_expression *exclusive_or_expression_ptr;
  Inclusive_or_expression *inclusive_or_expression_ptr;
  Logical_and_expression *logical_and_expression_ptr;
  Type_specifier *type_specifier_ptr;
  Type_qualifier *type_qualifier_ptr;
  Init_declarator *init_declarator_ptr;
  Declarator *declarator_ptr;
  Initializer *initializer_ptr;
  Initializer_list *initializer_list_ptr;
  Struct_or_union_specifier *struct_or_union_specifier_ptr;
  Enum_specifier *enum_specifier_ptr;
  /* Typedef_name *typedef_name_ptr; */
  Struct_declaration_list *struct_declaration_list_ptr;
  Struct_declaration *struct_declaration_ptr;
  Specifier_qualifier_list *specifier_qualifier_list_ptr;
  Struct_declarator_list *struct_declarator_list_ptr;
  Struct_declarator *struct_declarator_ptr;
  Enumerator_list *enumerator_list_ptr;
  Enumerator *enumerator_ptr;
  Pointer *pointer_ptr;
  Direct_declarator *direct_declarator_ptr;
  Parameter_type_list *parameter_type_list_ptr;
  Identifier_list *identifier_list_ptr;
  Type_qualifier_list *type_qualifier_list_ptr;
  Parameter_list *parameter_list_ptr;
  Parameter_declaration *parameter_declaration_ptr;
  Abstract_declarator *abstract_declarator_ptr;
  Direct_abstract_declarator *direct_abstract_declarator_ptr;
  Statement *statement_ptr;
  Labeled_statement *labeled_statement_ptr;
  Compound_statement *compound_statement_ptr;
  Expression_statement *expression_statement_ptr;
  Selection_statement *selection_statement_ptr;
  Iteration_statement *iteration_statement_ptr;
  Jump_statement *jump_statement_ptr;
  Statement_list *statement_list_ptr;
  Declaration_list *declaration_list_ptr;
  External_declaration *external_declaration_ptr;
  Function_definition *function_definition_ptr;

#line 223 "src/parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */
