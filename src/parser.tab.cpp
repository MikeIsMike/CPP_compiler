/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

#line 67 "src/parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
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
#line 1 "src/parser.y" /* yacc.c:355  */

  #include "../include/ast.hpp"

  #include <cassert>

  extern const Translation_unit *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);

#line 111 "src/parser.tab.cpp" /* yacc.c:355  */

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
#line 19 "src/parser.y" /* yacc.c:355  */

  const Translation_unit *t_u;
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

#line 276 "src/parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 293 "src/parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  210
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  346

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   339

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      85,     2,    86,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   203,   203,   205,   208,   209,   210,   211,   214,   215,
     216,   217,   218,   219,   220,   221,   224,   225,   228,   229,
     230,   231,   232,   233,   236,   237,   238,   239,   240,   241,
     244,   245,   248,   249,   250,   251,   254,   255,   256,   259,
     260,   261,   264,   265,   266,   267,   268,   271,   272,   273,
     276,   277,   280,   281,   284,   285,   288,   289,   292,   293,
     296,   297,   300,   301,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   317,   318,   321,   324,   325,
     328,   329,   330,   331,   332,   333,   336,   337,   340,   341,
     344,   345,   346,   347,   348,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   365,   366,   367,   370,
     371,   374,   377,   378,   379,   380,   383,   384,   387,   388,
     389,   392,   393,   394,   397,   398,   401,   402,   405,   406,
     409,   410,   413,   414,   415,   416,   417,   418,   419,   422,
     423,   424,   425,   428,   429,   433,   434,   437,   438,   441,
     442,   443,   446,   447,   450,   451,   454,   455,   456,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   473,   474,
     475,   478,   479,   482,   483,   484,   485,   486,   487,   490,
     491,   492,   495,   496,   497,   498,   501,   502,   505,   506,
     509,   510,   513,   514,   515,   518,   519,   520,   521,   524,
     525,   526,   527,   530,   531,   534,   535,   538,   539,   540,
     541
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KEYW_AUTO", "KEYW_BREAK", "KEYW_CASE",
  "KEYW_CONST", "KEYW_CONTINUE", "KEYW_DEFAULT", "KEYW_DO", "KEYW_ELSE",
  "KEYW_ENUM", "KEYW_EXTERN", "KEYW_FOR", "KEYW_IF", "KEYW_REGISTER",
  "KEYW_RETURN", "KEYW_SIZEOF", "KEYW_STATIC", "KEYW_STRUCT",
  "KEYW_SWITCH", "KEYW_TYPEDEF", "KEYW_VOLATILE", "KEYW_WHILE",
  "TYPE_CHAR", "TYPE_DOUBLE", "TYPE_FLOAT", "TYPE_INT", "TYPE_LONG",
  "TYPE_SHORT", "TYPE_SIGNED", "TYPE_UNSIGNED", "TYPE_VOID", "IDENTIFIER",
  "T_NUMBER", "CONSTANT", "STRING_LITERAL", "OP_ASTERISK", "OP_DIV",
  "OP_REMAINDER", "OP_PLUS", "OP_MINUS", "OP_EXP", "OP_ANDAND", "OP_OROR",
  "OP_AND", "OP_OR", "OP_EQ_CONST", "OP_NE_CONST", "OP_LT_EQ", "OP_GT_EQ",
  "OP_LT", "OP_GT", "OP_CONDITIONAL", "OP_RIGHT_SHIFT", "OP_LEFT_SHIFT",
  "OP_INCREM", "OP_DECREM", "OP_POINTER", "OP_MUL_ASSIGN", "OP_DIV_ASSIGN",
  "OP_PLUS_ASSIGN", "OP_MOD_ASSIGN", "OP_MINUS_ASSIGN", "OP_LEFT_ASSIGN",
  "OP_RIGHT_ASSIGN", "OP_AND_ASSIGN", "OP_XOR_ASSIGN", "OP_OR_ASSIGN",
  "OP_NOT", "OP_DOT", "OP_DESTRUCTOR", "PUN_L_BRACKET", "PUN_R_BRACKET",
  "PUN_CL_BRACKET", "PUN_CR_BRACKET", "PUN_SL_BRACKET", "PUN_SR_BRACKET",
  "PUN_SEMIC", "PUN_COMMA", "PUN_COLON", "PUN_EQUALS", "PUN_ELLIPSIS",
  "HASHTAG", "DOUBLE_HASHTAG", "'<'", "'>'", "$accept", "root",
  "enumeration_constant", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,    60,    62
};
# endif

#define YYPACT_NINF -157

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-157)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     830,  -157,  -157,    14,  -157,  -157,  -157,    28,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
     190,   144,    32,  -157,   108,  1213,  1213,  -157,  -157,  1213,
     303,    98,   -20,   830,  -157,  -157,   -34,    10,   -26,   379,
    -157,  -157,   190,   -15,  -157,  -157,   154,  -157,   264,  -157,
    -157,  -157,   343,  -157,   108,  -157,   303,   767,   933,    98,
    -157,    10,  -157,    24,    50,  -157,   379,   379,   173,  -157,
     103,   379,  -157,  -157,  -157,  -157,   144,  1033,  -157,   303,
     -11,  1108,    37,    57,   635,   113,   115,   883,  1133,   168,
     191,   165,  -157,  -157,  -157,  -157,  -157,  -157,  1158,  1158,
    -157,  -157,   858,  -157,  -157,  -157,    56,   478,  1108,  -157,
     263,   237,   243,   172,   257,   179,   226,   238,   244,    67,
    -157,  -157,   229,  -157,  -157,  -157,   419,   491,  -157,  -157,
    -157,  -157,   242,  -157,  -157,  -157,  -157,   106,   268,   265,
    -157,   -29,  -157,  -157,  -157,  -157,   266,   131,  1108,  -157,
      10,   455,  -157,  -157,  -157,  1108,   232,  -157,   262,  -157,
    -157,  1033,  -157,  -157,  -157,  -157,   273,  -157,   635,   358,
     908,  1108,  -157,   234,   858,  -157,  1108,  1108,   635,  1108,
    -157,  -157,    43,   -27,   309,  -157,  -157,   353,   354,  1058,
    1108,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  1108,  -157,  1108,  1108,  1108,  1108,  1108,  1108,
    1108,  1108,  1108,  1108,  1108,  1108,  1108,  1108,  1108,  1108,
    1108,  1108,  1108,  -157,  1108,  -157,   563,  -157,  -157,   699,
     958,  -157,    -3,  -157,   163,  -157,    53,  -157,   356,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,   103,  1108,  -157,   176,
     635,  -157,   319,   908,    51,  -157,   320,    54,   135,  -157,
    -157,   731,   166,  -157,  1108,  -157,  -157,  -157,   138,  -157,
     187,  -157,  -157,  -157,  -157,   263,   263,   237,   237,   243,
     243,   243,   243,   172,   172,   257,   179,   226,   238,   244,
     240,  -157,  -157,  -157,   321,   322,  -157,   315,   163,   799,
     983,  -157,  -157,  -157,  -157,  -157,  -157,  1008,  -157,  1108,
    1083,   635,  -157,   635,   635,  -157,  -157,  1108,  -157,  1108,
    -157,  -157,  -157,  -157,   323,  -157,   325,  -157,  -157,   155,
     635,   158,   387,  -157,  -157,  -157,  -157,  -157,  -157,   335,
    -157,   635,   635,  -157,  -157,  -157
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    93,   128,     0,    91,    94,    92,     0,    90,   129,
      96,   101,   100,    98,    99,    97,   102,   103,    95,   132,
     139,     0,     0,   206,     0,    80,    82,   104,   105,    84,
       0,   131,     0,     2,   203,   205,   123,     0,   108,     0,
     143,   141,   140,     0,     1,    78,     0,    86,    88,    81,
      83,    85,     0,   186,     0,   210,     0,     0,     0,   130,
     204,     0,     3,   126,     0,   124,     0,   113,     0,   109,
       0,   115,   144,   142,   133,    79,     0,     0,   208,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     5,     6,    25,    26,    27,    24,     0,     0,
      29,    28,     0,   182,   190,     8,    18,    30,     0,    32,
      36,    39,    42,    47,    50,    52,    54,    56,    58,    60,
      62,    75,     0,   188,   173,   174,     0,     0,   175,   176,
     177,   178,    88,   187,   209,   152,   138,   151,     0,   145,
     147,     0,     4,   135,    30,    77,     0,     0,     0,   121,
       0,     0,   112,   107,   110,     0,     0,   116,   118,   114,
      87,     0,   168,    89,   207,   200,     0,   199,     0,     0,
       0,     0,   201,     0,     0,    22,     0,     0,     0,     0,
      19,    20,     0,   154,     0,    14,    15,     0,     0,     0,
       0,    65,    66,    68,    67,    69,    70,    71,    72,    73,
      74,    64,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,     0,   184,     0,   183,   189,     0,
       0,   149,   156,   150,   157,   136,     0,   137,     0,   134,
     122,   127,   125,   106,   119,   111,     0,     0,   171,     0,
       0,   181,     0,     0,     0,   202,     0,     0,     0,   179,
       7,     0,   156,   155,     0,    13,    12,    10,     0,    16,
       0,    63,    33,    34,    35,    37,    38,    41,    40,    45,
      46,    43,    44,    48,    49,    51,    53,    55,    57,    59,
       0,    76,   185,   164,     0,     0,   160,     0,   158,     0,
       0,   146,   148,   153,   117,   120,   169,     0,   180,     0,
       0,     0,    23,     0,     0,    31,    11,     0,     9,     0,
     165,   159,   161,   166,     0,   162,     0,   170,   172,     0,
       0,     0,   192,   194,   195,    17,    61,   167,   163,     0,
     197,     0,     0,   196,   198,   193
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,  -157,  -157,  -157,  -157,   -57,  -157,   -96,   109,
     127,    60,   124,   199,   201,   210,   200,   236,  -157,   -54,
     -58,  -157,   -84,   -59,    20,     0,  -157,   377,  -157,   -32,
    -157,   392,   -51,   -56,  -157,   216,  -157,   402,   317,   152,
     -16,   -23,   -14,  -157,   -55,  -157,   233,  -157,   291,  -121,
    -128,  -140,  -157,   -61,  -157,     7,   208,   342,  -156,  -157,
    -157,  -157,  -157,   437,  -157
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    63,   105,   106,   268,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   202,   122,   146,    53,    54,    46,    47,    25,    26,
      27,    68,    69,    70,   156,   157,    28,    64,    65,    29,
      30,    31,    32,    42,   294,   139,   140,   141,   184,   295,
     234,   163,   249,   123,   124,   125,    56,   127,   128,   129,
     130,   131,    33,    34,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      24,   144,   138,   173,   145,    43,    41,    67,    48,    59,
      20,   152,   203,    19,   253,   159,   233,   154,   182,   162,
      23,   248,   166,   169,   144,    49,    50,   145,    73,    51,
      19,   175,    44,    24,    67,    67,    67,    55,   132,    67,
      61,   180,   181,    62,   237,   261,   183,    36,    66,   230,
     238,   144,    21,    23,   158,    78,     1,   137,    74,     2,
     132,    38,   263,   134,     3,     4,   228,   165,     5,   229,
      67,     6,     7,   230,     8,     9,   133,    10,    11,    12,
      13,    14,    15,    16,    17,    18,   164,   254,    37,   241,
     182,   144,   257,   258,   145,   182,   244,   310,   144,   133,
     154,   145,    39,   162,   298,   148,   270,   251,   272,   273,
     274,   221,   185,   186,   187,   167,   260,   259,   183,    67,
     222,   231,   224,   232,   311,   149,   188,   313,   189,   150,
     224,   269,   190,   224,   298,   301,    19,   168,   290,    19,
      20,    19,    67,    20,   271,    20,   133,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   228,   291,   328,   315,   262,
      57,   297,    40,   144,    58,    21,   145,    19,   229,     2,
      21,    20,   230,   155,     3,   170,    45,   171,   305,   308,
     144,    71,     7,   145,    72,     9,     2,    10,    11,    12,
      13,    14,    15,    16,    17,    18,   240,   144,   314,    59,
     150,   316,     9,    43,   224,   232,    21,   317,    71,    71,
      71,   211,   212,    71,   217,   329,   331,    20,   339,   137,
     158,   341,    75,    76,   224,   299,   137,   224,   261,   300,
     176,   326,   230,   144,   324,   178,   145,   262,   153,   162,
     332,   306,   333,   334,    71,   307,    79,   213,   214,   335,
     126,   137,   144,   177,   318,   336,   224,     1,   218,   340,
       2,   279,   280,   281,   282,     3,     4,   207,   208,     5,
     344,   345,     6,     7,   219,     8,     9,   220,    10,    11,
      12,    13,    14,    15,    16,    17,    18,   209,   210,   137,
     204,   205,   206,    71,   215,   216,     1,   223,   224,     2,
     245,   246,   255,   224,     3,     4,   275,   276,     5,   224,
     319,     6,     7,    77,     8,     9,    71,    10,    11,    12,
      13,    14,    15,    16,    17,    18,   277,   278,    52,   283,
     284,   235,   247,   239,   236,    77,     1,    80,    81,     2,
      82,    83,    84,   250,     3,     4,    85,    86,     5,    87,
      88,     6,     7,    89,     8,     9,    90,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    91,    52,    92,    93,
      94,   252,   264,    95,    96,     2,   265,   266,    97,   303,
       3,   309,   322,   312,   320,   321,   337,   342,     7,    98,
      99,     9,   338,    10,    11,    12,    13,    14,    15,    16,
      17,    18,   100,   343,   101,   102,   285,    52,   103,   286,
     288,   104,     1,    80,    81,     2,    82,    83,    84,   287,
       3,     4,    85,    86,     5,    87,    88,     6,     7,    89,
       8,     9,    90,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    91,   160,    92,    93,    94,   289,   151,    95,
      96,     2,   304,   147,    97,   256,     3,   242,   226,   302,
      60,     0,     0,     0,     7,    98,    99,     9,     0,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   100,     0,
     101,   102,     0,    52,   225,    80,    81,   104,    82,    83,
      84,     0,     0,     0,    85,    86,     0,    87,    88,     0,
       0,    89,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,    92,    93,    94,     0,
     243,    95,    96,     0,     0,     0,    97,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    98,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   201,
     100,     0,   101,   102,     0,    52,   227,    80,    81,   104,
      82,    83,    84,     0,     0,     0,    85,    86,     0,    87,
      88,     0,     0,    89,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,    92,    93,
      94,     0,     0,    95,    96,     0,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,   101,   102,     0,    52,   292,    80,
      81,   104,    82,    83,    84,     0,     0,     0,    85,    86,
       0,    87,    88,     0,     0,    89,     0,     0,    90,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,     0,
      92,    93,    94,     0,     0,    95,    96,     0,     0,     0,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,   100,     2,   101,   102,     0,    52,
       3,     4,     0,   104,     5,     0,     0,     6,     7,     0,
       8,     9,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,     1,     0,    20,     2,     0,     0,
       0,     0,     3,     4,     0,     0,     5,     0,     0,     6,
       7,     0,     8,     9,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     0,     0,     0,     0,    20,     0,
       1,   229,   293,     2,     0,   230,     0,     0,     3,     4,
       0,     0,     5,     0,     0,     6,     7,     0,     8,     9,
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
     135,     0,     1,   261,   293,     2,     0,   230,     0,     0,
       3,     4,     0,     0,     5,     0,     0,     6,     7,     0,
       8,     9,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     1,     0,     0,     2,     0,     0,     0,
     136,     3,     4,     0,     0,     5,     0,     0,     6,     7,
       0,     8,     9,     0,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     2,     0,     0,    20,     0,     3,
       0,     0,   323,     0,     0,    88,     0,     7,     0,     0,
       9,     0,    10,    11,    12,    13,    14,    15,    16,    17,
      18,   142,     0,    92,    93,    94,     0,     0,    95,    96,
      88,     0,    21,    97,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,    99,   142,     0,    92,    93,
      94,     0,     0,    95,    96,    88,     0,   100,    97,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,    98,
      99,   142,     0,    92,    93,    94,     0,     0,    95,    96,
      88,     0,   100,    97,   101,   102,     0,     0,     0,     0,
       0,   172,     0,     0,    98,    99,   142,     0,    92,    93,
      94,     0,     0,    95,    96,    88,     0,   100,    97,   101,
     102,     0,     0,     0,     0,     0,   104,     0,     0,    98,
      99,   142,     0,    92,    93,    94,     0,     0,    95,    96,
      88,     0,   100,    97,   101,   102,     0,     0,     0,     0,
     143,     0,     0,     0,    98,    99,   142,     0,    92,    93,
      94,     0,     0,    95,    96,    88,     0,   100,    97,   101,
     102,     0,     0,     0,     0,   296,     0,     0,     0,    98,
      99,   142,     0,    92,    93,    94,     0,     0,    95,    96,
      88,     0,   100,    97,   101,   102,     0,     0,     0,     0,
     325,     0,     0,     0,    98,    99,   142,     0,    92,    93,
      94,     0,     0,    95,    96,    88,     0,   100,    97,   101,
     102,     0,   161,   327,     0,     0,     0,     0,     0,    98,
      99,   142,     0,    92,    93,    94,     0,     0,    95,    96,
      88,     0,   100,    97,   101,   102,     0,   161,     0,     0,
       0,     0,     0,     0,    98,    99,   142,     0,    92,    93,
      94,     0,     0,    95,    96,    88,     0,   100,    97,   101,
     102,   267,     0,     0,     0,     0,     0,     0,     0,    98,
      99,   142,     0,    92,    93,    94,     0,     0,    95,    96,
      88,     0,   100,    97,   101,   102,   330,     0,     0,     0,
       0,     0,     0,     0,    98,    99,   142,     0,    92,    93,
      94,     0,     0,    95,    96,    88,     0,   100,    97,   101,
     102,     0,     0,     0,     0,     0,     0,     0,     0,    98,
      99,   142,     0,    92,    93,    94,     0,     0,    95,    96,
       0,     0,   100,    97,   101,   174,     0,     0,     0,     0,
       0,     0,     0,     0,    98,    99,     1,     0,     0,     2,
       0,     0,     0,     0,     3,     4,     0,   100,     5,   101,
     179,     6,     7,     0,     8,     9,     0,    10,    11,    12,
      13,    14,    15,    16,    17,    18
};

static const yytype_int16 yycheck[] =
{
       0,    58,    57,    87,    58,    21,    20,    39,    24,    32,
      37,    67,   108,    33,   170,    71,   137,    68,   102,    77,
       0,   161,    81,    84,    81,    25,    26,    81,    42,    29,
      33,    88,     0,    33,    66,    67,    68,    30,    54,    71,
      74,    98,    99,    33,    73,    72,   102,    33,    74,    76,
      79,   108,    72,    33,    70,    48,     3,    57,    73,     6,
      76,    33,   183,    56,    11,    12,   127,    78,    15,    72,
     102,    18,    19,    76,    21,    22,    56,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    79,   171,    74,   148,
     174,   148,   176,   177,   148,   179,   155,   253,   155,    79,
     151,   155,    74,   161,   232,    81,   190,   168,   204,   205,
     206,    44,    56,    57,    58,    78,    73,   178,   174,   151,
      53,   137,    79,   137,    73,    75,    70,    73,    72,    79,
      79,   189,    76,    79,   262,    82,    33,    80,   222,    33,
      37,    33,   174,    37,   202,    37,   126,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   226,   224,   307,   264,   183,
      72,   230,    20,   230,    76,    72,   230,    33,    72,     6,
      72,    37,    76,    80,    11,    72,    78,    72,   247,   250,
     247,    39,    19,   247,    42,    22,     6,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    75,   264,    73,   232,
      79,    73,    22,   229,    79,   229,    72,    79,    66,    67,
      68,    49,    50,    71,    45,   309,   310,    37,    73,   229,
     246,    73,    78,    79,    79,    72,   236,    79,    72,    76,
      72,   300,    76,   300,   299,    80,   300,   261,    75,   307,
     311,    75,   313,   314,   102,    79,    48,    85,    86,   317,
      52,   261,   319,    72,    77,   319,    79,     3,    42,   330,
       6,   211,   212,   213,   214,    11,    12,    40,    41,    15,
     341,   342,    18,    19,    46,    21,    22,    43,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    54,    55,   299,
      37,    38,    39,   151,    47,    48,     3,    78,    79,     6,
      78,    79,    78,    79,    11,    12,   207,   208,    15,    79,
      80,    18,    19,    81,    21,    22,   174,    24,    25,    26,
      27,    28,    29,    30,    31,    32,   209,   210,    74,   215,
     216,    73,    80,    77,    79,    81,     3,     4,     5,     6,
       7,     8,     9,    80,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    74,    35,    36,
      37,    23,    73,    40,    41,     6,    33,    33,    45,    33,
      11,    72,    77,    73,    73,    73,    73,    10,    19,    56,
      57,    22,    77,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    69,    78,    71,    72,   217,    74,    75,   218,
     220,    78,     3,     4,     5,     6,     7,     8,     9,   219,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    76,    35,    36,    37,   221,    66,    40,
      41,     6,   246,    61,    45,   174,    11,   150,   126,   236,
      33,    -1,    -1,    -1,    19,    56,    57,    22,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    69,    -1,
      71,    72,    -1,    74,    75,     4,     5,    78,     7,     8,
       9,    -1,    -1,    -1,    13,    14,    -1,    16,    17,    -1,
      -1,    20,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    35,    36,    37,    -1,
      75,    40,    41,    -1,    -1,    -1,    45,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    56,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      69,    -1,    71,    72,    -1,    74,    75,     4,     5,    78,
       7,     8,     9,    -1,    -1,    -1,    13,    14,    -1,    16,
      17,    -1,    -1,    20,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,    36,
      37,    -1,    -1,    40,    41,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    72,    -1,    74,    75,     4,
       5,    78,     7,     8,     9,    -1,    -1,    -1,    13,    14,
      -1,    16,    17,    -1,    -1,    20,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      35,    36,    37,    -1,    -1,    40,    41,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    69,     6,    71,    72,    -1,    74,
      11,    12,    -1,    78,    15,    -1,    -1,    18,    19,    -1,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,     3,    -1,    37,     6,    -1,    -1,
      -1,    -1,    11,    12,    -1,    -1,    15,    -1,    -1,    18,
      19,    -1,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,    -1,
       3,    72,    73,     6,    -1,    76,    -1,    -1,    11,    12,
      -1,    -1,    15,    -1,    -1,    18,    19,    -1,    21,    22,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,     3,    72,    73,     6,    -1,    76,    -1,    -1,
      11,    12,    -1,    -1,    15,    -1,    -1,    18,    19,    -1,
      21,    22,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,     3,    -1,    -1,     6,    -1,    -1,    -1,
      73,    11,    12,    -1,    -1,    15,    -1,    -1,    18,    19,
      -1,    21,    22,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     6,    -1,    -1,    37,    -1,    11,
      -1,    -1,    73,    -1,    -1,    17,    -1,    19,    -1,    -1,
      22,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    -1,    -1,    40,    41,
      17,    -1,    72,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    33,    -1,    35,    36,
      37,    -1,    -1,    40,    41,    17,    -1,    69,    45,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    33,    -1,    35,    36,    37,    -1,    -1,    40,    41,
      17,    -1,    69,    45,    71,    72,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    -1,    56,    57,    33,    -1,    35,    36,
      37,    -1,    -1,    40,    41,    17,    -1,    69,    45,    71,
      72,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    56,
      57,    33,    -1,    35,    36,    37,    -1,    -1,    40,    41,
      17,    -1,    69,    45,    71,    72,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    56,    57,    33,    -1,    35,    36,
      37,    -1,    -1,    40,    41,    17,    -1,    69,    45,    71,
      72,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,    56,
      57,    33,    -1,    35,    36,    37,    -1,    -1,    40,    41,
      17,    -1,    69,    45,    71,    72,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    56,    57,    33,    -1,    35,    36,
      37,    -1,    -1,    40,    41,    17,    -1,    69,    45,    71,
      72,    -1,    74,    75,    -1,    -1,    -1,    -1,    -1,    56,
      57,    33,    -1,    35,    36,    37,    -1,    -1,    40,    41,
      17,    -1,    69,    45,    71,    72,    -1,    74,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    33,    -1,    35,    36,
      37,    -1,    -1,    40,    41,    17,    -1,    69,    45,    71,
      72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    33,    -1,    35,    36,    37,    -1,    -1,    40,    41,
      17,    -1,    69,    45,    71,    72,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    33,    -1,    35,    36,
      37,    -1,    -1,    40,    41,    17,    -1,    69,    45,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    33,    -1,    35,    36,    37,    -1,    -1,    40,    41,
      -1,    -1,    69,    45,    71,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,     3,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    11,    12,    -1,    69,    15,    71,
      72,    18,    19,    -1,    21,    22,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,    11,    12,    15,    18,    19,    21,    22,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      37,    72,    88,   111,   112,   115,   116,   117,   123,   126,
     127,   128,   129,   149,   150,   151,    33,    74,    33,    74,
     126,   129,   130,   127,     0,    78,   113,   114,   127,   112,
     112,   112,    74,   111,   112,   142,   143,    72,    76,   128,
     150,    74,    33,    89,   124,   125,    74,   116,   118,   119,
     120,   126,   126,   129,    73,    78,    79,    81,   142,   143,
       4,     5,     7,     8,     9,    13,    14,    16,    17,    20,
      23,    33,    35,    36,    37,    40,    41,    45,    56,    57,
      69,    71,    72,    75,    78,    90,    91,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   109,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   127,   111,   142,    33,    73,   112,   131,   132,
     133,   134,    33,    77,    93,   106,   110,   124,    81,    75,
      79,   118,   120,    75,   119,    80,   121,   122,   127,   120,
     114,    74,   107,   138,   142,    78,   110,    78,    80,   140,
      72,    72,    78,   109,    72,    93,    72,    72,    80,    72,
      93,    93,   109,   120,   135,    56,    57,    58,    70,    72,
      76,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    81,   108,    95,    37,    38,    39,    40,    41,    54,
      55,    49,    50,    85,    86,    47,    48,    45,    42,    46,
      43,    44,    53,    78,    79,    75,   144,    75,   140,    72,
      76,   127,   129,   136,   137,    73,    79,    73,    79,    77,
      75,   110,   125,    75,   110,    78,    79,    80,   138,   139,
      80,   140,    23,   145,   109,    78,   135,   109,   109,   140,
      73,    72,   129,   136,    73,    33,    33,    73,    92,   107,
     109,   107,    95,    95,    95,    96,    96,    97,    97,    98,
      98,    98,    98,    99,    99,   100,   101,   102,   103,   104,
     109,   107,    75,    73,   131,   136,    77,   110,   137,    72,
      76,    82,   133,    33,   122,   110,    75,    79,   140,    72,
     145,    73,    73,    73,    73,    95,    73,    79,    77,    80,
      73,    73,    77,    73,   131,    77,   110,    75,   138,   109,
      73,   109,   140,   140,   140,   107,   106,    73,    77,    73,
     140,    73,    10,    78,   140,   140
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    89,    90,    90,    90,    90,    91,    91,
      91,    91,    91,    91,    91,    91,    92,    92,    93,    93,
      93,    93,    93,    93,    94,    94,    94,    94,    94,    94,
      95,    95,    96,    96,    96,    96,    97,    97,    97,    98,
      98,    98,    99,    99,    99,    99,    99,   100,   100,   100,
     101,   101,   102,   102,   103,   103,   104,   104,   105,   105,
     106,   106,   107,   107,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   109,   109,   110,   111,   111,
     112,   112,   112,   112,   112,   112,   113,   113,   114,   114,
     115,   115,   115,   115,   115,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   117,   117,   117,   118,
     118,   119,   120,   120,   120,   120,   121,   121,   122,   122,
     122,   123,   123,   123,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   128,   128,   128,   128,   128,   128,   129,
     129,   129,   129,   130,   130,   131,   131,   132,   132,   133,
     133,   133,   134,   134,   135,   135,   136,   136,   136,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   138,   138,
     138,   139,   139,   140,   140,   140,   140,   140,   140,   141,
     141,   141,   142,   142,   142,   142,   143,   143,   144,   144,
     145,   145,   146,   146,   146,   147,   147,   147,   147,   148,
     148,   148,   148,   149,   149,   150,   150,   151,   151,   151,
     151
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     4,
       3,     4,     3,     3,     2,     2,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     1,
       2,     3,     2,     1,     2,     1,     1,     3,     1,     2,
       3,     4,     5,     2,     1,     3,     1,     3,     1,     1,
       2,     1,     1,     3,     4,     3,     4,     4,     3,     1,
       2,     2,     3,     1,     2,     1,     3,     1,     3,     2,
       2,     1,     1,     3,     1,     2,     1,     1,     2,     3,
       2,     3,     3,     4,     2,     3,     3,     4,     1,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     3,     4,     1,     2,     1,     2,
       1,     2,     5,     7,     5,     5,     7,     6,     7,     2,
       2,     2,     3,     1,     2,     1,     1,     4,     3,     3,
       2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 203 "src/parser.y" /* yacc.c:1646  */
    { g_root = (yyvsp[0].t_u);}
#line 1837 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 205 "src/parser.y" /* yacc.c:1646  */
    {(yyval.enumeration_constant_ptr) = new Enumeration_constant((yyvsp[0].string));}
#line 1843 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 208 "src/parser.y" /* yacc.c:1646  */
    { (yyval.primary_expression_ptr) = new Primary_expression((yyvsp[0].string), NULL, NULL, NULL);}
#line 1849 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 209 "src/parser.y" /* yacc.c:1646  */
    { (yyval.primary_expression_ptr) = new Primary_expression(NULL, (yyvsp[0].string), NULL, NULL);}
#line 1855 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 210 "src/parser.y" /* yacc.c:1646  */
    { (yyval.primary_expression_ptr) = new Primary_expression(NULL, NULL, (yyvsp[0].string), NULL);}
#line 1861 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 211 "src/parser.y" /* yacc.c:1646  */
    { (yyval.primary_expression_ptr) = new Primary_expression(NULL, NULL, NULL, (yyvsp[-1].expression_ptr));}
#line 1867 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 214 "src/parser.y" /* yacc.c:1646  */
    {(yyval.postfix_expression_ptr) = new Postfix_expression((yyvsp[0].primary_expression_ptr), NULL, NULL, NULL, NULL, NULL);}
#line 1873 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 215 "src/parser.y" /* yacc.c:1646  */
    {(yyval.postfix_expression_ptr) = new Postfix_expression(NULL, (yyvsp[-3].postfix_expression_ptr), (yyvsp[-1].expression_ptr), NULL, NULL, NULL);}
#line 1879 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 216 "src/parser.y" /* yacc.c:1646  */
    {(yyval.postfix_expression_ptr) = new Postfix_expression(NULL, (yyvsp[-2].postfix_expression_ptr), NULL, NULL, NULL, NULL);}
#line 1885 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 217 "src/parser.y" /* yacc.c:1646  */
    {(yyval.postfix_expression_ptr) = new Postfix_expression(NULL, (yyvsp[-3].postfix_expression_ptr), NULL, (yyvsp[-1].argument_expression_list_ptr), NULL, NULL);}
#line 1891 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 218 "src/parser.y" /* yacc.c:1646  */
    {(yyval.postfix_expression_ptr) = new Postfix_expression(NULL, (yyvsp[-2].postfix_expression_ptr), NULL, NULL, (yyvsp[-1].string), (yyvsp[0].string));}
#line 1897 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 219 "src/parser.y" /* yacc.c:1646  */
    {(yyval.postfix_expression_ptr) = new Postfix_expression(NULL, (yyvsp[-2].postfix_expression_ptr), NULL, NULL, (yyvsp[-1].string), (yyvsp[0].string));}
#line 1903 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 220 "src/parser.y" /* yacc.c:1646  */
    {(yyval.postfix_expression_ptr) = new Postfix_expression(NULL, (yyvsp[-1].postfix_expression_ptr), NULL, NULL, (yyvsp[0].string), NULL);}
#line 1909 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 221 "src/parser.y" /* yacc.c:1646  */
    {(yyval.postfix_expression_ptr) = new Postfix_expression(NULL, (yyvsp[-1].postfix_expression_ptr), NULL, NULL, (yyvsp[0].string), NULL);}
#line 1915 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 224 "src/parser.y" /* yacc.c:1646  */
    {(yyval.argument_expression_list_ptr) = new Argument_expression_list((yyvsp[0].assignment_expression_ptr), NULL);}
#line 1921 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 225 "src/parser.y" /* yacc.c:1646  */
    {(yyval.argument_expression_list_ptr) = new Argument_expression_list((yyvsp[-2].argument_expression_list_ptr), (yyvsp[0].assignment_expression_ptr));}
#line 1927 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 228 "src/parser.y" /* yacc.c:1646  */
    {(yyval.unary_expression_ptr) = new Unary_expression((yyvsp[0].postfix_expression_ptr), NULL, NULL, NULL, NULL, NULL);}
#line 1933 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 229 "src/parser.y" /* yacc.c:1646  */
    {(yyval.unary_expression_ptr) = new Unary_expression(NULL, (yyvsp[-1].string), (yyvsp[0].unary_expression_ptr), NULL, NULL, NULL);}
#line 1939 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 230 "src/parser.y" /* yacc.c:1646  */
    {(yyval.unary_expression_ptr) = new Unary_expression(NULL, (yyvsp[-1].string), (yyvsp[0].unary_expression_ptr), NULL, NULL, NULL);}
#line 1945 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 231 "src/parser.y" /* yacc.c:1646  */
    {(yyval.unary_expression_ptr) = new Unary_expression(NULL, NULL, NULL, (yyvsp[-1].string), (yyvsp[0].cast_expression_ptr), NULL);}
#line 1951 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 232 "src/parser.y" /* yacc.c:1646  */
    {(yyval.unary_expression_ptr) = new Unary_expression(NULL, (yyvsp[-1].string), (yyvsp[0].unary_expression_ptr), NULL, NULL, NULL);}
#line 1957 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 233 "src/parser.y" /* yacc.c:1646  */
    {(yyval.unary_expression_ptr) = new Unary_expression(NULL, (yyvsp[-3].string), NULL, NULL, NULL, (yyvsp[-1].type_name_ptr));}
#line 1963 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 236 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1969 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 237 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1975 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 238 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1981 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 239 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1987 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 240 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1993 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 241 "src/parser.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 1999 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 244 "src/parser.y" /* yacc.c:1646  */
    {(yyval.cast_expression_ptr) = new Cast_expression((yyvsp[0].unary_expression_ptr), NULL, NULL);}
#line 2005 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 245 "src/parser.y" /* yacc.c:1646  */
    {(yyval.cast_expression_ptr) = new Cast_expression(NULL, (yyvsp[-2].type_name_ptr), (yyvsp[0].cast_expression_ptr));}
#line 2011 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 248 "src/parser.y" /* yacc.c:1646  */
    {(yyval.multiplicative_expression_ptr) = new Multiplicative_expression((yyvsp[0].cast_expression_ptr), NULL, NULL);}
#line 2017 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 249 "src/parser.y" /* yacc.c:1646  */
    {(yyval.multiplicative_expression_ptr) = new Multiplicative_expression((yyvsp[0].cast_expression_ptr), (yyvsp[-2].multiplicative_expression_ptr), (yyvsp[-1].string));}
#line 2023 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 250 "src/parser.y" /* yacc.c:1646  */
    {(yyval.multiplicative_expression_ptr) = new Multiplicative_expression((yyvsp[0].cast_expression_ptr), (yyvsp[-2].multiplicative_expression_ptr), (yyvsp[-1].string));}
#line 2029 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 251 "src/parser.y" /* yacc.c:1646  */
    {(yyval.multiplicative_expression_ptr) = new Multiplicative_expression((yyvsp[0].cast_expression_ptr), (yyvsp[-2].multiplicative_expression_ptr), (yyvsp[-1].string));}
#line 2035 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 254 "src/parser.y" /* yacc.c:1646  */
    {(yyval.additive_expression_ptr) = new Additive_expression((yyvsp[0].multiplicative_expression_ptr), NULL, NULL);}
#line 2041 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 255 "src/parser.y" /* yacc.c:1646  */
    {(yyval.additive_expression_ptr) = new Additive_expression((yyvsp[0].multiplicative_expression_ptr), (yyvsp[-2].additive_expression_ptr), (yyvsp[-1].string));}
#line 2047 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 256 "src/parser.y" /* yacc.c:1646  */
    {(yyval.additive_expression_ptr) = new Additive_expression((yyvsp[0].multiplicative_expression_ptr), (yyvsp[-2].additive_expression_ptr), (yyvsp[-1].string));}
#line 2053 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 259 "src/parser.y" /* yacc.c:1646  */
    {(yyval.shift_expression_ptr) = new Shift_expression((yyvsp[0].additive_expression_ptr), NULL, NULL);}
#line 2059 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 260 "src/parser.y" /* yacc.c:1646  */
    {(yyval.shift_expression_ptr) = new Relational_expression((yyvsp[0].additive_expression_ptr), (yyvsp[-2].shift_expression_ptr), (yyvsp[-1].string));}
#line 2065 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 261 "src/parser.y" /* yacc.c:1646  */
    {(yyval.shift_expression_ptr) = new Relational_expression((yyvsp[0].additive_expression_ptr), (yyvsp[-2].shift_expression_ptr), (yyvsp[-1].string));}
#line 2071 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 264 "src/parser.y" /* yacc.c:1646  */
    {(yyval.relational_expression_ptr) = new Relational_expression((yyvsp[0].shift_expression_ptr), NULL, NULL);}
#line 2077 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 265 "src/parser.y" /* yacc.c:1646  */
    {(yyval.relational_expression_ptr) = new Relational_expression((yyvsp[0].shift_expression_ptr), (yyvsp[-2].relational_expression_ptr), (yyvsp[-1].string));}
#line 2083 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 266 "src/parser.y" /* yacc.c:1646  */
    {(yyval.relational_expression_ptr) = new Relational_expression((yyvsp[0].shift_expression_ptr), (yyvsp[-2].relational_expression_ptr), (yyvsp[-1].string));}
#line 2089 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 267 "src/parser.y" /* yacc.c:1646  */
    {(yyval.relational_expression_ptr) = new Relational_expression((yyvsp[0].shift_expression_ptr), (yyvsp[-2].relational_expression_ptr), (yyvsp[-1].string));}
#line 2095 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 268 "src/parser.y" /* yacc.c:1646  */
    {(yyval.relational_expression_ptr) = new Relational_expression((yyvsp[0].shift_expression_ptr), (yyvsp[-2].relational_expression_ptr), (yyvsp[-1].string));}
#line 2101 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 271 "src/parser.y" /* yacc.c:1646  */
    {(yyval.equality_expression_ptr) = new Equality_expression((yyvsp[0].relational_expression_ptr), NULL, NULL);}
#line 2107 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 272 "src/parser.y" /* yacc.c:1646  */
    {(yyval.equality_expression_ptr) = new Equality_expression((yyvsp[0].relational_expression_ptr), (yyvsp[-2].equality_expression_ptr), (yyvsp[-1].string));}
#line 2113 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 273 "src/parser.y" /* yacc.c:1646  */
    {(yyval.equality_expression_ptr) = new Equality_expression((yyvsp[0].relational_expression_ptr), (yyvsp[-2].equality_expression_ptr), (yyvsp[-1].string));}
#line 2119 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 276 "src/parser.y" /* yacc.c:1646  */
    {(yyval.and_expression_ptr) = new And_expression((yyvsp[0].equality_expression_ptr), NULL);}
#line 2125 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 277 "src/parser.y" /* yacc.c:1646  */
    {(yyval.and_expression_ptr) = new And_expression((yyvsp[0].equality_expression_ptr), (yyvsp[-2].and_expression_ptr));}
#line 2131 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 280 "src/parser.y" /* yacc.c:1646  */
    {(yyval.exclusive_or_expression_ptr) = new Exclusive_or_expression((yyvsp[0].and_expression_ptr), NULL);}
#line 2137 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 281 "src/parser.y" /* yacc.c:1646  */
    {(yyval.exclusive_or_expression_ptr) = new Exclusive_or_expression((yyvsp[0].and_expression_ptr), (yyvsp[-2].exclusive_or_expression_ptr));}
#line 2143 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 284 "src/parser.y" /* yacc.c:1646  */
    {(yyval.inclusive_or_expression_ptr) = new Inclusive_or_expression((yyvsp[0].exclusive_or_expression_ptr), NULL);}
#line 2149 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 285 "src/parser.y" /* yacc.c:1646  */
    {(yyval.inclusive_or_expression_ptr) = new Inclusive_or_expression((yyvsp[0].exclusive_or_expression_ptr), (yyvsp[-2].inclusive_or_expression_ptr));}
#line 2155 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 288 "src/parser.y" /* yacc.c:1646  */
    {(yyval.logical_and_expression_ptr) = new Logical_and_expression((yyvsp[0].inclusive_or_expression_ptr), NULL);}
#line 2161 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 289 "src/parser.y" /* yacc.c:1646  */
    {(yyval.logical_and_expression_ptr) = new Logical_or_expression((yyvsp[0].inclusive_or_expression_ptr), (yyvsp[-2].logical_and_expression_ptr));}
#line 2167 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 292 "src/parser.y" /* yacc.c:1646  */
    {(yyval.logical_or_expression_ptr) = new Logical_or_expression((yyvsp[0].logical_and_expression_ptr), NULL);}
#line 2173 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 293 "src/parser.y" /* yacc.c:1646  */
    {(yyval.logical_or_expression_ptr) = new Logical_or_expression((yyvsp[0].logical_and_expression_ptr), (yyvsp[-2].logical_or_expression_ptr));}
#line 2179 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 296 "src/parser.y" /* yacc.c:1646  */
    {(yyval.conditional_expression_ptr) = new Conditional_expression((yyvsp[0].logical_or_expression_ptr), NULL, NULL);}
#line 2185 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 297 "src/parser.y" /* yacc.c:1646  */
    {(yyval.conditional_expression_ptr) = new Conditional_expression((yyvsp[-4].logical_or_expression_ptr), (yyvsp[-2].expression_ptr), (yyvsp[0].conditional_expression_ptr));}
#line 2191 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 300 "src/parser.y" /* yacc.c:1646  */
    {(yyval.assignment_expression_ptr) = new Assignment_expression((yyvsp[0].conditional_expression_ptr), NULL, NULL, NULL);}
#line 2197 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 301 "src/parser.y" /* yacc.c:1646  */
    {(yyval.assignment_expression_ptr) = new Assignment_expression(NULL, (yyvsp[-2].unary_expression_ptr), (yyvsp[-1].assignment_operator_ptr), (yyvsp[0].assignment_expression_ptr));}
#line 2203 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 304 "src/parser.y" /* yacc.c:1646  */
    {(yyval.assignment_operator_ptr) = (yyvsp[0].string);}
#line 2209 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 305 "src/parser.y" /* yacc.c:1646  */
    {(yyval.assignment_operator_ptr) = (yyvsp[0].string);}
#line 2215 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 306 "src/parser.y" /* yacc.c:1646  */
    {(yyval.assignment_operator_ptr) = (yyvsp[0].string);}
#line 2221 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 307 "src/parser.y" /* yacc.c:1646  */
    {(yyval.assignment_operator_ptr) = (yyvsp[0].string);}
#line 2227 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 308 "src/parser.y" /* yacc.c:1646  */
    {(yyval.assignment_operator_ptr) = (yyvsp[0].string);}
#line 2233 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 309 "src/parser.y" /* yacc.c:1646  */
    {(yyval.assignment_operator_ptr) = (yyvsp[0].string);}
#line 2239 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 310 "src/parser.y" /* yacc.c:1646  */
    {(yyval.assignment_operator_ptr) = (yyvsp[0].string);}
#line 2245 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 311 "src/parser.y" /* yacc.c:1646  */
    {(yyval.assignment_operator_ptr) = (yyvsp[0].string);}
#line 2251 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 312 "src/parser.y" /* yacc.c:1646  */
    {(yyval.assignment_operator_ptr) = (yyvsp[0].string);}
#line 2257 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 313 "src/parser.y" /* yacc.c:1646  */
    {(yyval.assignment_operator_ptr) = (yyvsp[0].string);}
#line 2263 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 314 "src/parser.y" /* yacc.c:1646  */
    {(yyval.assignment_operator_ptr) = (yyvsp[0].string);}
#line 2269 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 317 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expression_ptr) = new Expression((yyvsp[0].assignment_expression_ptr), NULL);}
#line 2275 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 318 "src/parser.y" /* yacc.c:1646  */
    {(yyval.expression_ptr) = new Expression((yyvsp[-2].expression_ptr), (yyvsp[0].assignment_expression_ptr));}
#line 2281 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 321 "src/parser.y" /* yacc.c:1646  */
    {(yyval.constant_expression_ptr) = new Constant_expression((yyvsp[0].conditional_expression_ptr));}
#line 2287 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 324 "src/parser.y" /* yacc.c:1646  */
    {(yyval.declaration_ptr) = new Declaration((yyvsp[-1].declaration_specifiers_ptr), NULL);}
#line 2293 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 325 "src/parser.y" /* yacc.c:1646  */
    {(yyval.declaration_ptr) = new Declaration((yyvsp[-2].declaration_specifiers_ptr), (yyvsp[-1].init_declarator_list_ptr));}
#line 2299 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 328 "src/parser.y" /* yacc.c:1646  */
    {(yyval.declaration_specifiers_ptr) = new Declaration_specifiers((yyvsp[0].storage_class_specifier_ptr), NULL, NULL, NULL); }
#line 2305 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 329 "src/parser.y" /* yacc.c:1646  */
    {(yyval.declaration_specifiers_ptr) = new Declaration_specifiers((yyvsp[-1].storage_class_specifier_ptr), NULL, NULL, (yyvsp[0].declaration_specifiers_ptr)); }
#line 2311 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 330 "src/parser.y" /* yacc.c:1646  */
    {(yyval.declaration_specifiers_ptr) = new Declaration_specifiers(NULL, (yyvsp[0].type_specifier_ptr), NULL, NULL); }
#line 2317 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 331 "src/parser.y" /* yacc.c:1646  */
    {(yyval.declaration_specifiers_ptr) = new Declaration_specifiers(NULL, (yyvsp[-1].type_specifier_ptr), NULL, (yyvsp[0].declaration_specifiers_ptr)); }
#line 2323 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 332 "src/parser.y" /* yacc.c:1646  */
    {(yyval.declaration_specifiers_ptr) = new Declaration_specifiers(NULL, NULL, (yyvsp[0].type_qualifier_ptr), NULL); }
#line 2329 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 333 "src/parser.y" /* yacc.c:1646  */
    {(yyval.declaration_specifiers_ptr) = new Declaration_specifiers(NULL, NULL, (yyvsp[-1].type_qualifier_ptr), (yyvsp[0].declaration_specifiers_ptr)); }
#line 2335 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 336 "src/parser.y" /* yacc.c:1646  */
    {(yyval.init_declarator_list_ptr) = new Init_declarator_list((yyvsp[0].init_declarator_ptr), NULL); }
#line 2341 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 337 "src/parser.y" /* yacc.c:1646  */
    {(yyval.init_declarator_list_ptr) = new Init_declarator_list((yyvsp[-2].init_declarator_list_ptr), (yyvsp[0].init_declarator_ptr)); }
#line 2347 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 340 "src/parser.y" /* yacc.c:1646  */
    {(yyval.init_declarator_ptr) = new Init_declarator((yyvsp[0].declarator_ptr), NULL); }
#line 2353 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 341 "src/parser.y" /* yacc.c:1646  */
    {(yyval.init_declarator_ptr) = new Init_declarator((yyvsp[-2].declarator_ptr), (yyvsp[0].initializer_ptr)); }
#line 2359 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 344 "src/parser.y" /* yacc.c:1646  */
    {(yyval.storage_class_specifier_ptr) = new Storage_class_specifier((yyvsp[0].string));}
#line 2365 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 345 "src/parser.y" /* yacc.c:1646  */
    {(yyval.storage_class_specifier_ptr) = new Storage_class_specifier((yyvsp[0].string));}
#line 2371 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 346 "src/parser.y" /* yacc.c:1646  */
    {(yyval.storage_class_specifier_ptr) = new Storage_class_specifier((yyvsp[0].string));}
#line 2377 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 347 "src/parser.y" /* yacc.c:1646  */
    {(yyval.storage_class_specifier_ptr) = new Storage_class_specifier((yyvsp[0].string));}
#line 2383 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 348 "src/parser.y" /* yacc.c:1646  */
    {(yyval.storage_class_specifier_ptr) = new Storage_class_specifier((yyvsp[0].string));}
#line 2389 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 351 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier_ptr) = new Type_specifier((yyvsp[0].string), NULL, NULL, NULL);}
#line 2395 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 352 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier_ptr) = new Type_specifier((yyvsp[0].string), NULL, NULL, NULL);}
#line 2401 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 353 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier_ptr) = new Type_specifier((yyvsp[0].string), NULL, NULL, NULL);}
#line 2407 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 354 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier_ptr) = new Type_specifier((yyvsp[0].string), NULL, NULL, NULL);}
#line 2413 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 355 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier_ptr) = new Type_specifier((yyvsp[0].string), NULL, NULL, NULL);}
#line 2419 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 356 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier_ptr) = new Type_specifier((yyvsp[0].string), NULL, NULL, NULL);}
#line 2425 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 357 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier_ptr) = new Type_specifier((yyvsp[0].string), NULL, NULL, NULL);}
#line 2431 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 358 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier_ptr) = new Type_specifier((yyvsp[0].string), NULL, NULL, NULL);}
#line 2437 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 359 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier_ptr) = new Type_specifier((yyvsp[0].string), NULL, NULL, NULL);}
#line 2443 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 360 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier_ptr) = new Type_specifier(NULL, (yyvsp[0].struct_or_union_specifier_ptr), NULL, NULL);}
#line 2449 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 361 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier_ptr) = new Type_specifier(NULL, NULL, (yyvsp[0].enum_specifier_ptr), NULL);}
#line 2455 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 365 "src/parser.y" /* yacc.c:1646  */
    {(yyval.struct_or_union_specifier_ptr) = new Struct_or_union_specifier((yyvsp[-3].string), (yyvsp[-1].struct_declaration_list_ptr));}
#line 2461 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 366 "src/parser.y" /* yacc.c:1646  */
    {(yyval.struct_or_union_specifier_ptr) = new Struct_or_union_specifier(NULL, (yyvsp[-1].struct_declaration_list_ptr));}
#line 2467 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 367 "src/parser.y" /* yacc.c:1646  */
    {(yyval.struct_or_union_specifier_ptr) = new Struct_or_union_specifier((yyvsp[0].string), NULL);}
#line 2473 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 370 "src/parser.y" /* yacc.c:1646  */
    {(yyval.struct_declaration_list_ptr) = new Struct_declaration_list((yyvsp[0].struct_declaration_ptr), NULL);}
#line 2479 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 371 "src/parser.y" /* yacc.c:1646  */
    {(yyval.struct_declaration_list_ptr) = new Struct_declaration_list((yyvsp[0].struct_declaration_ptr), (yyvsp[-1].struct_declaration_list_ptr));}
#line 2485 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 374 "src/parser.y" /* yacc.c:1646  */
    {(yyval.struct_declaration_ptr) = new Struct_declaration((yyvsp[-2].specifier_qualifier_list_ptr), (yyvsp[-1].struct_declarator_list_ptr));}
#line 2491 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 377 "src/parser.y" /* yacc.c:1646  */
    {(yyval.specifier_qualifier_list_ptr) = new Specifier_qualifier_list((yyvsp[-1].type_specifier_ptr), (yyvsp[0].specifier_qualifier_list_ptr), NULL);}
#line 2497 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 378 "src/parser.y" /* yacc.c:1646  */
    {(yyval.specifier_qualifier_list_ptr) = new Specifier_qualifier_list((yyvsp[0].type_specifier_ptr), NULL, NULL);}
#line 2503 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 379 "src/parser.y" /* yacc.c:1646  */
    {(yyval.specifier_qualifier_list_ptr) = new Specifier_qualifier_list(NULL, (yyvsp[0].specifier_qualifier_list_ptr), (yyvsp[-1].type_qualifier_ptr));}
#line 2509 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 380 "src/parser.y" /* yacc.c:1646  */
    {(yyval.specifier_qualifier_list_ptr) = new Specifier_qualifier_list(NULL, NULL, (yyvsp[0].type_qualifier_ptr));}
#line 2515 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 383 "src/parser.y" /* yacc.c:1646  */
    {(yyval.struct_declarator_list_ptr) = new Struct_declarator_list((yyvsp[0].struct_declarator_ptr), NULL);}
#line 2521 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 384 "src/parser.y" /* yacc.c:1646  */
    {(yyval.struct_declarator_list_ptr) = new Struct_declarator_list((yyvsp[0].struct_declarator_ptr), (yyvsp[-2].struct_declarator_list_ptr));}
#line 2527 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 387 "src/parser.y" /* yacc.c:1646  */
    {(yyval.struct_declarator_ptr) = new Struct_declarator((yyvsp[0].declarator_ptr), NULL);}
#line 2533 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 388 "src/parser.y" /* yacc.c:1646  */
    {(yyval.struct_declarator_ptr) = new Struct_declarator(NULL, (yyvsp[0].constant_expression_ptr));}
#line 2539 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 389 "src/parser.y" /* yacc.c:1646  */
    {(yyval.struct_declarator_ptr) = new Struct_declarator((yyvsp[-2].declarator_ptr), (yyvsp[0].constant_expression_ptr));}
#line 2545 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 392 "src/parser.y" /* yacc.c:1646  */
    {(yyval.enum_specifier_ptr) = new Enum_specifier((yyvsp[-1].enumerator_list_ptr), NULL);}
#line 2551 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 393 "src/parser.y" /* yacc.c:1646  */
    {(yyval.enum_specifier_ptr) = new Enum_specifier((yyvsp[-1].enumerator_list_ptr), (yyvsp[-3].string));}
#line 2557 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 394 "src/parser.y" /* yacc.c:1646  */
    {(yyval.enum_specifier_ptr) = new Enum_specifier(NULL, (yyvsp[0].string));}
#line 2563 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 397 "src/parser.y" /* yacc.c:1646  */
    {(yyval.enumerator_list_ptr) = new Enumerator_list((yyvsp[0].enumerator_ptr), NULL);}
#line 2569 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 398 "src/parser.y" /* yacc.c:1646  */
    {(yyval.enumerator_list_ptr) = new Enumerator_list((yyvsp[0].enumerator_ptr), (yyvsp[-2].enumerator_list_ptr));}
#line 2575 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 401 "src/parser.y" /* yacc.c:1646  */
    {(yyval.enumerator_ptr) = new Enumerator((yyvsp[0].enumeration_constant_ptr), NULL);}
#line 2581 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 402 "src/parser.y" /* yacc.c:1646  */
    {(yyval.enumerator_ptr) = new Enumerator((yyvsp[-2].enumeration_constant_ptr), (yyvsp[0].constant_expression_ptr));}
#line 2587 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 405 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_qualifier_ptr) = new Type_qualifier((yyvsp[0].string));}
#line 2593 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 406 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_qualifier_ptr) = new Type_qualifier((yyvsp[0].string));}
#line 2599 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 409 "src/parser.y" /* yacc.c:1646  */
    {(yyval.declarator_ptr) = new Declarator((yyvsp[-1].pointer_ptr), (yyvsp[0].direct_declarator_ptr));}
#line 2605 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 410 "src/parser.y" /* yacc.c:1646  */
    {(yyval.declarator_ptr) = new Declarator(NULL, (yyvsp[0].direct_declarator_ptr));}
#line 2611 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 413 "src/parser.y" /* yacc.c:1646  */
    {(yyval.direct_declarator_ptr) = new Direct_declarator((yyvsp[0].string), NULL, NULL, NULL, NULL, NULL, 1)}
#line 2617 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 414 "src/parser.y" /* yacc.c:1646  */
    {(yyval.direct_declarator_ptr) = new Direct_declarator(NULL, (yyvsp[-1].declarator_ptr), NULL, NULL, NULL, NULL, 2)}
#line 2623 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 415 "src/parser.y" /* yacc.c:1646  */
    {(yyval.direct_declarator_ptr) = new Direct_declarator(NULL, NULL, (yyvsp[-3].direct_declarator_ptr), (yyvsp[-1].constant_expression_ptr), NULL, NULL, 3)}
#line 2629 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 416 "src/parser.y" /* yacc.c:1646  */
    {(yyval.direct_declarator_ptr) = new Direct_declarator(NULL, NULL, (yyvsp[-2].direct_declarator_ptr), NULL, NULL, NULL, 4)}
#line 2635 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 417 "src/parser.y" /* yacc.c:1646  */
    {(yyval.direct_declarator_ptr) = new Direct_declarator(NULL, NULL, (yyvsp[-3].direct_declarator_ptr), NULL, (yyvsp[-1].parameter_type_list_ptr), NULL, 5)}
#line 2641 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 418 "src/parser.y" /* yacc.c:1646  */
    {(yyval.direct_declarator_ptr) = new Direct_declarator(NULL, NULL, (yyvsp[-3].direct_declarator_ptr), NULL, NULL, (yyvsp[-1].identifier_list_ptr), 6)}
#line 2647 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 419 "src/parser.y" /* yacc.c:1646  */
    {(yyval.direct_declarator_ptr) = new Direct_declarator(NULL, NULL, (yyvsp[-2].direct_declarator_ptr), NULL, NULL, NULL, 7)}
#line 2653 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 422 "src/parser.y" /* yacc.c:1646  */
    {(yyval.pointer_ptr) = new Pointer(NULL, NULL);}
#line 2659 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 423 "src/parser.y" /* yacc.c:1646  */
    {(yyval.pointer_ptr) = new Pointer((yyvsp[0].type_qualifier_list_ptr), NULL);}
#line 2665 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 424 "src/parser.y" /* yacc.c:1646  */
    {(yyval.pointer_ptr) = new Pointer(NULL, (yyvsp[0].pointer_ptr));}
#line 2671 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 425 "src/parser.y" /* yacc.c:1646  */
    {(yyval.pointer_ptr) = new Pointer((yyvsp[-1].type_qualifier_list_ptr), (yyvsp[0].pointer_ptr));}
#line 2677 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 428 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_qualifier_list_ptr) = new Type_qualifier_list((yyvsp[0].type_qualifier_ptr), NULL);}
#line 2683 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 429 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_qualifier_list_ptr) = new Type_qualifier_list((yyvsp[0].type_qualifier_ptr), (yyvsp[-1].type_qualifier_list_ptr));}
#line 2689 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 433 "src/parser.y" /* yacc.c:1646  */
    {(yyval.parameter_type_list_ptr) = new Parameter_type_list((yyvsp[0].parameter_list_ptr), false);}
#line 2695 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 434 "src/parser.y" /* yacc.c:1646  */
    {(yyval.parameter_type_list_ptr) = new Parameter_type_list((yyvsp[-2].parameter_list_ptr), true);}
#line 2701 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 437 "src/parser.y" /* yacc.c:1646  */
    {(yyval.parameter_list_ptr) = new Parameter_list((yyvsp[0].parameter_declaration_ptr), NULL);}
#line 2707 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 438 "src/parser.y" /* yacc.c:1646  */
    {(yyval.parameter_list_ptr) = new Parameter_list((yyvsp[0].parameter_declaration_ptr), (yyvsp[-2].parameter_list_ptr));}
#line 2713 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 441 "src/parser.y" /* yacc.c:1646  */
    {(yyval.parameter_declaration_ptr) = new Parameter_declaration((yyvsp[-1].declaration_specifiers_ptr), (yyvsp[0].declarator_ptr), NULL);}
#line 2719 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 442 "src/parser.y" /* yacc.c:1646  */
    {(yyval.parameter_declaration_ptr) = new Parameter_declaration((yyvsp[-1].declaration_specifiers_ptr), NULL, (yyvsp[0].abstract_declarator_ptr));}
#line 2725 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 443 "src/parser.y" /* yacc.c:1646  */
    {(yyval.parameter_declaration_ptr) = new Parameter_declaration((yyvsp[0].declaration_specifiers_ptr), NULL, NULL);}
#line 2731 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 446 "src/parser.y" /* yacc.c:1646  */
    {(yyval.identifier_list_ptr) = new Identifier_list((yyvsp[0].string), NULL);}
#line 2737 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 447 "src/parser.y" /* yacc.c:1646  */
    {(yyval.identifier_list_ptr) = new Identifier_list((yyvsp[0].string), (yyvsp[-2].identifier_list_ptr));}
#line 2743 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 450 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_name_ptr) = new Type_name((yyvsp[0].specifier_qualifier_list_ptr), NULL);}
#line 2749 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 451 "src/parser.y" /* yacc.c:1646  */
    {(yyval.type_name_ptr) = new Type_name((yyvsp[-1].specifier_qualifier_list_ptr), (yyvsp[0].abstract_declarator_ptr));}
#line 2755 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 454 "src/parser.y" /* yacc.c:1646  */
    {(yyval.abstract_declarator_ptr) = new Abstract_declarator((yyvsp[0].pointer_ptr), NULL);}
#line 2761 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 455 "src/parser.y" /* yacc.c:1646  */
    {(yyval.abstract_declarator_ptr) = new Abstract_declarator(NULL, (yyvsp[0].direct_abstract_declarator_ptr));}
#line 2767 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 456 "src/parser.y" /* yacc.c:1646  */
    {(yyval.abstract_declarator_ptr) = new Abstract_declarator((yyvsp[-1].pointer_ptr), (yyvsp[0].direct_abstract_declarator_ptr));}
#line 2773 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 459 "src/parser.y" /* yacc.c:1646  */
    {(yyval.direct_abstract_declarator_ptr) = new Direct_abstract_declarator(1, (yyvsp[-1].abstract_declarator_ptr), NULL, NULL, NULL);}
#line 2779 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 460 "src/parser.y" /* yacc.c:1646  */
    {(yyval.direct_abstract_declarator_ptr) = new Direct_abstract_declarator(2, NULL, NULL, NULL, NULL);}
#line 2785 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 461 "src/parser.y" /* yacc.c:1646  */
    {(yyval.direct_abstract_declarator_ptr) = new Direct_abstract_declarator(3, NULL, (yyvsp[-1].constant_expression_ptr), NULL, NULL);}
#line 2791 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 462 "src/parser.y" /* yacc.c:1646  */
    {(yyval.direct_abstract_declarator_ptr) = new Direct_abstract_declarator(4, NULL, NULL, (yyvsp[-2].direct_abstract_declarator_ptr), NULL);}
#line 2797 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 463 "src/parser.y" /* yacc.c:1646  */
    {(yyval.direct_abstract_declarator_ptr) = new Direct_abstract_declarator(5, NULL, (yyvsp[-1].constant_expression_ptr), (yyvsp[-3].direct_abstract_declarator_ptr), NULL);}
#line 2803 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 164:
#line 464 "src/parser.y" /* yacc.c:1646  */
    {(yyval.direct_abstract_declarator_ptr) = new Direct_abstract_declarator(6, NULL, NULL, NULL, NULL);}
#line 2809 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 165:
#line 465 "src/parser.y" /* yacc.c:1646  */
    {(yyval.direct_abstract_declarator_ptr) = new Direct_abstract_declarator(7, NULL, NULL, NULL, (yyvsp[-1].parameter_type_list_ptr));}
#line 2815 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 166:
#line 466 "src/parser.y" /* yacc.c:1646  */
    {(yyval.direct_abstract_declarator_ptr) = new Direct_abstract_declarator(8, NULL, NULL, (yyvsp[-2].direct_abstract_declarator_ptr), NULL);}
#line 2821 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 167:
#line 467 "src/parser.y" /* yacc.c:1646  */
    {(yyval.direct_abstract_declarator_ptr) = new Direct_abstract_declarator(9, NULL, NULL, (yyvsp[-3].direct_abstract_declarator_ptr), (yyvsp[-1].parameter_type_list_ptr));}
#line 2827 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 168:
#line 473 "src/parser.y" /* yacc.c:1646  */
    { (yyval.initializer_ptr) = new Initializer((yyvsp[0].assignment_expression_ptr), NULL, false);}
#line 2833 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 169:
#line 474 "src/parser.y" /* yacc.c:1646  */
    { (yyval.initializer_ptr) = new Initializer(NULL, (yyvsp[-1].initializer_list_ptr), false);}
#line 2839 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 170:
#line 475 "src/parser.y" /* yacc.c:1646  */
    { (yyval.initializer_ptr) = new Initializer(NULL, (yyvsp[-2].initializer_list_ptr), true);}
#line 2845 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 171:
#line 478 "src/parser.y" /* yacc.c:1646  */
    { (yyval.initializer_list_ptr) = new Initializer_list((yyvsp[0].initializer_ptr), NULL);}
#line 2851 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 172:
#line 479 "src/parser.y" /* yacc.c:1646  */
    { (yyval.initializer_list_ptr) = new Initializer_list((yyvsp[0].initializer_ptr), (yyvsp[-2].initializer_list_ptr));}
#line 2857 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 173:
#line 482 "src/parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Statement((yyvsp[0].labeled_statement_ptr), NULL, NULL, NULL, NULL, NULL); }
#line 2863 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 174:
#line 483 "src/parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Statement(NULL, (yyvsp[0].compound_statement_ptr), NULL, NULL, NULL, NULL); }
#line 2869 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 175:
#line 484 "src/parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Statement(NULL, NULL, (yyvsp[0].expression_statement_ptr), NULL, NULL, NULL); }
#line 2875 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 176:
#line 485 "src/parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Statement(NULL, NULL, NULL, (yyvsp[0].selection_statement_ptr), NULL, NULL); }
#line 2881 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 177:
#line 486 "src/parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Statement(NULL, NULL, NULL, NULL, (yyvsp[0].iteration_statement_ptr), NULL); }
#line 2887 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 178:
#line 487 "src/parser.y" /* yacc.c:1646  */
    { (yyval.statement_ptr) = new Statement(NULL, NULL, NULL, NULL, NULL, (yyvsp[0].jump_statement_ptr)); }
#line 2893 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 179:
#line 490 "src/parser.y" /* yacc.c:1646  */
    { (yyval.labeled_statement_ptr) = new Labeled_statement((yyvsp[-2].string), (yyvsp[0].statement_ptr), NULL);}
#line 2899 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 180:
#line 491 "src/parser.y" /* yacc.c:1646  */
    { (yyval.labeled_statement_ptr) = new Labeled_statement(NULL, (yyvsp[0].statement_ptr), (yyvsp[-2].constant_expression_ptr));}
#line 2905 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 181:
#line 492 "src/parser.y" /* yacc.c:1646  */
    { (yyval.labeled_statement_ptr) = new Labeled_statement(NULL, (yyvsp[0].statement_ptr), NULL);}
#line 2911 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 182:
#line 495 "src/parser.y" /* yacc.c:1646  */
    { (yyval.compound_statement_ptr) = new Compound_statement(NULL, NULL);}
#line 2917 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 183:
#line 496 "src/parser.y" /* yacc.c:1646  */
    { (yyval.compound_statement_ptr) = new Compound_statement((yyvsp[-1].statement_list_ptr), NULL);}
#line 2923 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 184:
#line 497 "src/parser.y" /* yacc.c:1646  */
    { (yyval.compound_statement_ptr) = new Compound_statement(NULL, (yyvsp[-1].declaration_list_ptr));}
#line 2929 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 185:
#line 498 "src/parser.y" /* yacc.c:1646  */
    { (yyval.compound_statement_ptr) = new Compound_statement((yyvsp[-1].statement_list_ptr), (yyvsp[-2].declaration_list_ptr));}
#line 2935 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 186:
#line 501 "src/parser.y" /* yacc.c:1646  */
    { (yyval.declaration_list_ptr) = new Declaration_list((yyvsp[0].declaration_ptr), NULL);}
#line 2941 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 187:
#line 502 "src/parser.y" /* yacc.c:1646  */
    { (yyval.declaration_list_ptr) = new Declaration_list((yyvsp[0].declaration_ptr), (yyvsp[-1].declaration_list_ptr));}
#line 2947 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 188:
#line 505 "src/parser.y" /* yacc.c:1646  */
    { (yyval.statement_list_ptr) = new Statement_list(NULL, (yyvsp[0].statement_ptr));}
#line 2953 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 189:
#line 506 "src/parser.y" /* yacc.c:1646  */
    { (yyval.statement_list_ptr) = new Statement_list((yyvsp[-1].statement_list_ptr), (yyvsp[0].statement_ptr));}
#line 2959 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 190:
#line 509 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression_statement_ptr) = new Expression_statement(NULL);}
#line 2965 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 191:
#line 510 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expression_statement_ptr) = new Expression_statement((yyvsp[-1].expression_ptr));}
#line 2971 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 192:
#line 513 "src/parser.y" /* yacc.c:1646  */
    { (yyval.selection_statement_ptr) = new Selection_statement((yyvsp[-2].expression_ptr), (yyvsp[0].statement_ptr), NULL, false);}
#line 2977 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 193:
#line 514 "src/parser.y" /* yacc.c:1646  */
    { (yyval.selection_statement_ptr) = new Selection_statement((yyvsp[-4].expression_ptr), (yyvsp[-2].statement_ptr), (yyvsp[0].statement_ptr), false);}
#line 2983 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 194:
#line 515 "src/parser.y" /* yacc.c:1646  */
    { (yyval.selection_statement_ptr) = new Selection_statement((yyvsp[-2].expression_ptr), (yyvsp[0].statement_ptr), NULL, true);}
#line 2989 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 195:
#line 518 "src/parser.y" /* yacc.c:1646  */
    { (yyval.iteration_statement_ptr) = new Iteration_statement((yyvsp[-2].expression_ptr), (yyvsp[0].statement_ptr), NULL, NULL, (yyvsp[-4].string));}
#line 2995 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 196:
#line 519 "src/parser.y" /* yacc.c:1646  */
    { (yyval.iteration_statement_ptr) = new Iteration_statement((yyvsp[-2].expression_ptr), (yyvsp[-5].statement_ptr), NULL, NULL, (yyvsp[-6].string));}
#line 3001 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 197:
#line 520 "src/parser.y" /* yacc.c:1646  */
    { (yyval.iteration_statement_ptr) = new Iteration_statement(NULL, (yyvsp[0].statement_ptr), (yyvsp[-3].expression_statement_ptr), (yyvsp[-2].expression_statement_ptr), (yyvsp[-5].string));}
#line 3007 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 198:
#line 521 "src/parser.y" /* yacc.c:1646  */
    { (yyval.iteration_statement_ptr) = new Iteration_statement((yyvsp[-2].expression_ptr), (yyvsp[0].statement_ptr), (yyvsp[-4].expression_statement_ptr), (yyvsp[-3].expression_statement_ptr), (yyvsp[-6].string));}
#line 3013 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 199:
#line 524 "src/parser.y" /* yacc.c:1646  */
    { (yyval.jump_statement_ptr) = new Jump_statement(NULL, (yyvsp[-1].string));}
#line 3019 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 200:
#line 525 "src/parser.y" /* yacc.c:1646  */
    { (yyval.jump_statement_ptr) = new Jump_statement(NULL, (yyvsp[-1].string));}
#line 3025 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 201:
#line 526 "src/parser.y" /* yacc.c:1646  */
    { (yyval.jump_statement_ptr) = new Jump_statement(NULL, (yyvsp[-1].string));}
#line 3031 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 202:
#line 527 "src/parser.y" /* yacc.c:1646  */
    { (yyval.jump_statement_ptr) = new Jump_statement((yyvsp[-1].expression_ptr), (yyvsp[-2].string));}
#line 3037 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 203:
#line 530 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_u) = new Translation_unit((yyvsp[0].external_declaration_ptr), NULL); }
#line 3043 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 204:
#line 531 "src/parser.y" /* yacc.c:1646  */
    { (yyval.t_u) = new Translation_unit((yyvsp[0].external_declaration_ptr), (yyvsp[-1].t_u)); }
#line 3049 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 205:
#line 534 "src/parser.y" /* yacc.c:1646  */
    { (yyval.external_declaration_ptr) = new External_declaration((yyvsp[0].function_definition_ptr), NULL); }
#line 3055 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 206:
#line 535 "src/parser.y" /* yacc.c:1646  */
    { (yyval.external_declaration_ptr) = new External_declaration(NULL, (yyvsp[0].declaration_ptr)); }
#line 3061 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 207:
#line 538 "src/parser.y" /* yacc.c:1646  */
    { (yyval.function_definition_ptr) = new Function_definition((yyvsp[-3].declaration_specifiers_ptr), (yyvsp[-2].declarator_ptr), (yyvsp[0].compound_statement_ptr), (yyvsp[-1].declaration_list_ptr));}
#line 3067 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 208:
#line 539 "src/parser.y" /* yacc.c:1646  */
    { (yyval.function_definition_ptr) = new Function_definition((yyvsp[-2].declaration_specifiers_ptr), (yyvsp[-1].declarator_ptr), (yyvsp[0].compound_statement_ptr), NULL);}
#line 3073 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 209:
#line 540 "src/parser.y" /* yacc.c:1646  */
    { (yyval.function_definition_ptr) = new Function_definition(NULL, (yyvsp[-2].declarator_ptr), (yyvsp[0].compound_statement_ptr), (yyvsp[-1].declaration_list_ptr));}
#line 3079 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 210:
#line 541 "src/parser.y" /* yacc.c:1646  */
    { (yyval.function_definition_ptr) = new Function_definition(NULL, (yyvsp[-1].declarator_ptr), (yyvsp[0].compound_statement_ptr), NULL);}
#line 3085 "src/parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 3089 "src/parser.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 562 "src/parser.y" /* yacc.c:1906  */


const Translation_unit *g_root; // Definition of variable (to match declaration earlier)

const Translation_unit *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
