/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <bits/stdc++.h>
#include "Node.h"
#include "SymTable.h"
using namespace std;
extern int yylex();
extern int yylineno;
extern FILE *yyin;
extern map<unsigned long long int, symtab> symTables; 


vector<string> enum_types = {"BIN", "OCT", "HEX_FLOAT", "STRING", "HEX", "BOOL", "VOID", "FUNCTION", "CLASS", "INTERFACE", "ENUM", "UNION", "TYPEDEF", "VOID", "VAR", "_NULL", "BYTE", "SHORT", "CHAR", "INT", "LONG", "FLOAT", "DOUBLE"};

set<TYPE>add_set = {INT, BIN, FLOAT, OCT, HEX_FLOAT, HEX, /*CHAR,*/ LONG, DOUBLE};

int currentSymTableId = -1;
int symTablescount = 0;
bool isDot = false;
vector<TYPE>vt;
TYPE t = VOID;
int size = 0;
vector<int>vs;
bool isarr=false;
int ArrayArgumentDepth = 0;

bool flag_verbose=false;
void yyerror(const char* s){
    if(flag_verbose){
        printf("Error %s in line %d\n",s,yylineno);
    }
    else{
        printf("Syntax error in line %d\n",yylineno);
    }
}

void initializeSymTable(){
    symtab*a = new symtab(symTablescount, currentSymTableId);
    cout<<"Symbol Table Created with Parent ID "<<currentSymTableId<<" and current ID "<<symTablescount<<endl;
    currentSymTableId = symTablescount;
    symTablescount++;
    symTables[currentSymTableId] = *a;
}

Node* root=NULL;

TYPE widen(TYPE a, TYPE b);

#line 118 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 51 "parser.y"

    #include "Node.h"

#line 165 "parser.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    k_abstract = 258,
    k_assert = 259,
    k_boolean = 260,
    k_break = 261,
    k_byte = 262,
    k_case = 263,
    k_catch = 264,
    k_char = 265,
    k_class = 266,
    k_const = 267,
    k_continue = 268,
    k_default = 269,
    k_do = 270,
    k_double = 271,
    k_else = 272,
    k_enum = 273,
    k_extends = 274,
    k_final = 275,
    k_finally = 276,
    k_float = 277,
    k_for = 278,
    k_goto = 279,
    k_if = 280,
    k_implements = 281,
    k_import = 282,
    k_instanceof = 283,
    k_int = 284,
    k_interface = 285,
    k_long = 286,
    k_native = 287,
    k_new = 288,
    k_package = 289,
    k_private = 290,
    k_protected = 291,
    k_public = 292,
    k_return = 293,
    k_short = 294,
    k_static = 295,
    k_strictfp = 296,
    k_super = 297,
    k_switch = 298,
    k_synchronized = 299,
    k_this = 300,
    k_throw = 301,
    k_throws = 302,
    k_transient = 303,
    k_try = 304,
    k_void = 305,
    k_volatile = 306,
    k_while = 307,
    k_underscore = 308,
    k_exports = 309,
    k_module = 310,
    k_non_sealed = 311,
    k_open = 312,
    k_opens = 313,
    k_permits = 314,
    k_provide = 315,
    k_record = 316,
    k_requires = 317,
    k_sealed = 318,
    k_to = 319,
    k_transitive = 320,
    k_uses = 321,
    k_var = 322,
    k_with = 323,
    k_yield = 324,
    o_assign = 325,
    o_add_assign = 326,
    o_subtract_assign = 327,
    o_multiply_assign = 328,
    o_divide_assign = 329,
    o_modulo_assign = 330,
    o_bitwise_and_assign = 331,
    o_bitwise_or_assign = 332,
    o_bitwise_xor_assign = 333,
    o_left_shift_assign = 334,
    o_right_shift_assign = 335,
    o_unsigned_right_shift_assign = 336,
    o_bitwise_and = 337,
    o_bitwise_or = 338,
    o_bitwise_xor = 339,
    o_left_shift = 340,
    o_right_shift = 341,
    o_unsigned_right_shift = 342,
    o_add = 343,
    o_subtract = 344,
    o_multiply = 345,
    o_divide = 346,
    o_modulo = 347,
    o_less_than = 348,
    o_less_than_or_equal = 349,
    o_greater_than = 350,
    o_greater_than_or_equal = 351,
    o_equals = 352,
    o_not_equals = 353,
    o_logical_and = 354,
    o_logical_not = 355,
    o_logical_or = 356,
    o_increment = 357,
    o_decrement = 358,
    o_bitwise_complement = 359,
    o_question_mark = 360,
    o_colon = 361,
    o_arrow = 362,
    Identifier = 363,
    int_Literal = 364,
    bin_Literal = 365,
    deci_flo_Literal = 366,
    oct_Literal = 367,
    hex_flo_Literal = 368,
    string_Literal = 369,
    hex_Literal = 370,
    Text_Block_Literal = 371,
    char_Literal = 372,
    true_Literal = 373,
    false_Literal = 374,
    null_Literal = 375,
    s_open_paren = 376,
    s_close_paren = 377,
    s_open_curly_bracket = 378,
    s_close_curly_bracket = 379,
    s_open_square_bracket = 380,
    s_close_square_bracket = 381,
    s_semicolon = 382,
    s_comma = 383,
    s_dot = 384,
    s_varargs = 385,
    s_double_colon = 386
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 55 "parser.y"

    char* str;
    Node* node;

#line 313 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3873

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  132
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  143
/* YYNRULES -- Number of rules.  */
#define YYNRULES  380
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  662

#define YYUNDEFTOK  2
#define YYMAXUTOK   386


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    79,    79,    83,    94,    98,   103,   107,   116,   120,
     125,   129,   133,   137,   141,   146,   150,   156,   160,   165,
     169,   173,   177,   190,   210,   227,   231,   236,   253,   271,
     278,   284,   290,   294,   300,   305,   310,   314,   321,   325,
     332,   340,   344,   349,   358,   368,   372,   376,   382,   386,
     393,   397,   401,   405,   409,   413,   417,   421,   425,   429,
     434,   438,   444,   464,   483,   502,   520,   539,   557,   575,
     593,   599,   606,   613,   617,   625,   634,   642,   646,   653,
     657,   661,   666,   670,   675,   693,   708,   712,   727,   731,
     760,   776,   792,   796,   801,   818,   826,   833,   840,   846,
     854,   861,   868,   874,   881,   895,   908,   922,   926,   934,
     942,   952,   959,   963,   971,   976,   981,   991,   998,  1004,
    1010,  1018,  1026,  1035,  1040,  1047,  1053,  1064,  1072,  1079,
    1086,  1095,  1103,  1110,  1117,  1124,  1130,  1139,  1146,  1154,
    1161,  1169,  1176,  1183,  1190,  1193,  1199,  1200,  1208,  1216,
    1223,  1230,  1236,  1241,  1247,  1254,  1260,  1268,  1278,  1284,
    1294,  1302,  1310,  1312,  1316,  1321,  1328,  1335,  1355,  1378,
    1395,  1406,  1411,  1424,  1430,  1440,  1444,  1453,  1457,  1463,
    1475,  1482,  1491,  1495,  1501,  1503,  1505,  1507,  1509,  1511,
    1516,  1518,  1520,  1522,  1524,  1529,  1531,  1533,  1535,  1537,
    1539,  1541,  1543,  1545,  1550,  1556,  1567,  1577,  1587,  1589,
    1591,  1593,  1595,  1597,  1599,  1604,  1621,  1636,  1650,  1656,
    1671,  1686,  1686,  1687,  1687,  1690,  1704,  1719,  1734,  1750,
    1765,  1781,  1797,  1818,  1832,  1847,  1862,  1878,  1893,  1909,
    1925,  1944,  1961,  1965,  1972,  1978,  1991,  1992,  2000,  2005,
    2012,  2018,  2026,  2032,  2040,  2045,  2055,  2065,  2072,  2079,
    2087,  2092,  2099,  2109,  2120,  2124,  2131,  2132,  2133,  2134,
    2135,  2136,  2137,  2138,  2139,  2140,  2141,  2142,  2143,  2144,
    2151,  2155,  2159,  2163,  2167,  2175,  2188,  2190,  2200,  2214,
    2228,  2242,  2248,  2255,  2266,  2268,  2276,  2297,  2306,  2317,
    2323,  2332,  2339,  2347,  2356,  2366,  2375,  2388,  2403,  2421,
    2423,  2425,  2427,  2432,  2448,  2462,  2464,  2466,  2471,  2476,
    2481,  2496,  2511,  2513,  2525,  2537,  2542,  2550,  2560,  2568,
    2580,  2584,  2592,  2600,  2611,  2615,  2623,  2634,  2638,  2652,
    2666,  2683,  2687,  2702,  2716,  2730,  2744,  2754,  2758,  2772,
    2789,  2793,  2810,  2814,  2831,  2835,  2852,  2856,  2873,  2877,
    2894,  2898,  2922,  2926,  2933,  2950,  2954,  2958,  2965,  2969,
    2973,  2977,  2981,  2985,  2989,  2993,  2997,  3001,  3005,  3009,
    3016
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "k_abstract", "k_assert", "k_boolean",
  "k_break", "k_byte", "k_case", "k_catch", "k_char", "k_class", "k_const",
  "k_continue", "k_default", "k_do", "k_double", "k_else", "k_enum",
  "k_extends", "k_final", "k_finally", "k_float", "k_for", "k_goto",
  "k_if", "k_implements", "k_import", "k_instanceof", "k_int",
  "k_interface", "k_long", "k_native", "k_new", "k_package", "k_private",
  "k_protected", "k_public", "k_return", "k_short", "k_static",
  "k_strictfp", "k_super", "k_switch", "k_synchronized", "k_this",
  "k_throw", "k_throws", "k_transient", "k_try", "k_void", "k_volatile",
  "k_while", "k_underscore", "k_exports", "k_module", "k_non_sealed",
  "k_open", "k_opens", "k_permits", "k_provide", "k_record", "k_requires",
  "k_sealed", "k_to", "k_transitive", "k_uses", "k_var", "k_with",
  "k_yield", "o_assign", "o_add_assign", "o_subtract_assign",
  "o_multiply_assign", "o_divide_assign", "o_modulo_assign",
  "o_bitwise_and_assign", "o_bitwise_or_assign", "o_bitwise_xor_assign",
  "o_left_shift_assign", "o_right_shift_assign",
  "o_unsigned_right_shift_assign", "o_bitwise_and", "o_bitwise_or",
  "o_bitwise_xor", "o_left_shift", "o_right_shift",
  "o_unsigned_right_shift", "o_add", "o_subtract", "o_multiply",
  "o_divide", "o_modulo", "o_less_than", "o_less_than_or_equal",
  "o_greater_than", "o_greater_than_or_equal", "o_equals", "o_not_equals",
  "o_logical_and", "o_logical_not", "o_logical_or", "o_increment",
  "o_decrement", "o_bitwise_complement", "o_question_mark", "o_colon",
  "o_arrow", "Identifier", "int_Literal", "bin_Literal",
  "deci_flo_Literal", "oct_Literal", "hex_flo_Literal", "string_Literal",
  "hex_Literal", "Text_Block_Literal", "char_Literal", "true_Literal",
  "false_Literal", "null_Literal", "s_open_paren", "s_close_paren",
  "s_open_curly_bracket", "s_close_curly_bracket", "s_open_square_bracket",
  "s_close_square_bracket", "s_semicolon", "s_comma", "s_dot", "s_varargs",
  "s_double_colon", "$accept", "Program", "Type", "PrimitiveType",
  "NumericType", "IntegralType", "FloatingPointType", "ReferenceType",
  "ClassOrInterfaceType", "ClassType", "InterfaceType", "ArrayType",
  "Name", "SimpleName", "QualifiedName", "CompilationUnit",
  "ImportDeclarations", "TypeDeclarations", "PackageDeclaration",
  "ImportDeclaration", "SingleTypeImportDeclaration",
  "TypeImportOnDemandDeclaration", "TypeDeclaration", "Modifiers",
  "Modifier", "ClassDeclaration", "NormalClassDeclaration",
  "S_open_curly_bracket", "Super", "Interfaces", "InterfaceTypeList",
  "ClassBody", "ClassBodyDeclarations", "ClassBodyDeclaration",
  "ClassMemberDeclaration", "FieldDeclaration", "VariableDeclaratorList",
  "VariableDeclarator", "VariableDeclaratorId", "VariableInitializer",
  "MethodDeclaration", "MethodHeader", "S_open_paren", "MethodDeclarator",
  "FormalParameterList", "FormalParameter", "Throws", "ClassTypeList",
  "MethodBody", "StaticInitializer", "ConstructorDeclaration",
  "ConstructorDeclarator", "ConstructorBody",
  "ExplicitConstructorInvocation", "EnumDeclaration", "ClassImplements",
  "EnumBody", "EnumBodyDeclarations", "EnumConstantList", "EnumConstant",
  "InterfaceDeclaration", "ExtendsInterfaces", "InterfaceBody",
  "InterfaceMemberDeclarations", "InterfaceMemberDeclaration",
  "ConstantDeclaration", "AbstractMethodDeclaration", "ArrayInitializer",
  "array_s_open_curly_bracket", "VariableInitializerList", "Block",
  "BlockStatements", "BlockStatement", "LocalVariableDeclarationStatement",
  "LocalVariableDeclaration", "LocalVariableType", "Statement",
  "StatementNoShortIf", "StatementWithoutTrailingSubstatement",
  "EmptyStatement", "LabeledStatement", "LabeledStatementNoShortIf",
  "ExpressionStatement", "StatementExpression", "IfThenStatement",
  "IfThenElseStatement", "IfThenElseStatementNoShortIf", "invoke_paren",
  "WhileStatement", "WhileStatementNoShortIf", "ForStatement",
  "ForStatementNoShortIf", "BasicForStatement",
  "BasicForStatementNoShortIf", "EnhancedForStatementNoShortIf", "ForInit",
  "ForUpdate", "EnhancedForStatement", "StatementExpressionList",
  "BreakStatement", "ContinueStatement", "ReturnStatement",
  "ThrowStatement", "SynchronizedStatement", "TryStatement", "Catches",
  "CatchClause", "Finally", "Primary", "PrimaryNoNewArray",
  "ClassInstanceCreationExpression", "ArgumentList",
  "ArrayCreationExpression", "DimExprs", "DimExpr", "Dims", "FieldAccess",
  "MethodInvocation", "ArrayAccess", "PostFixExpression",
  "PostIncrementExpression", "PostDecrementExpression", "UnaryExpression",
  "PreIncrementExpression", "PreDecrementExpression",
  "UnaryExpressionNotPlusMinus", "CastExpression",
  "MultiplicativeExpression", "AdditiveExpression", "ShiftExpression",
  "RelationalExpression", "EqualityExpression", "AndExpression",
  "ExclusiveOrExpression", "InclusiveOrExpression",
  "ConditionalAndExpression", "ConditionalOrExpression",
  "ConditionalExpression", "AssignmentExpression", "Assignment",
  "LeftHandSide", "AssignmentOperator", "Expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386
};
# endif

#define YYPACT_NINF (-406)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-368)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     587,  -406,   -54,   -10,  -406,    26,    41,  -406,    26,  -406,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,    93,  -406,  1186,
     884,  1186,  -406,  -406,  -406,  -406,  2782,  -406,  -406,  -406,
    -406,  -406,    13,   -11,  -406,   122,  -406,  -406,    17,   137,
    -406,   884,  -406,  -406,  1186,   884,    50,   119,   202,  -406,
      26,    26,    69,  2605,    12,    83,  -406,    26,    68,   159,
    -406,  -406,    80,    26,  1352,   -31,  -406,  -406,   214,   884,
      13,   -11,    17,  -406,  -406,   213,  -406,  -406,   227,  -406,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,   241,   264,
     295,   245,  -406,  -406,  -406,  -406,  -406,   271,   192,   310,
    2647,  1513,  -406,  -406,  -406,  -406,   109,  -406,  -406,     0,
      83,  -406,  -406,   227,   208,  -406,  2605,   -62,   308,   150,
    -406,  -406,   307,  -406,  -406,  -406,  2647,  -406,   318,  1697,
    -406,  -406,  -406,    26,  -406,    12,    83,  -406,   159,  -406,
     -31,  -406,    26,  1647,  -406,   316,    14,   316,   224,  -406,
      85,    14,   313,   325,   326,   632,   264,   295,     0,  -406,
    -406,  -406,  -406,  -406,    26,  1770,   330,  -406,  -406,  3207,
    -406,  2605,  -406,   336,  -406,  -406,    73,   337,  -406,  -406,
    -406,  -406,  -406,    83,  -406,  -406,  -406,  -406,  -406,    -7,
      56,   287,   333,   333,   428,  2626,   335,   341,  -406,  2660,
     241,   333,  -406,  3663,  3663,   359,  -406,  -406,  -406,  -406,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  3663,  -406,
    -406,  -406,   273,  -406,  1825,  -406,  -406,   339,   360,  -406,
    -406,  -406,  -406,  -406,   342,  -406,  -406,  -406,  -406,  -406,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,   343,   346,    98,
    -406,   429,   107,  1035,   255,   259,   289,  -406,  -406,  -406,
    1527,  -406,   753,   347,  -406,  -406,   360,  3155,   349,  -406,
    -406,  -406,  -406,   428,  -406,   360,   -59,  -406,    14,   262,
      14,   330,  -406,  -406,   348,   -30,   361,  -406,  1948,  2003,
    -406,  3663,  3663,  3663,  3663,  2486,    83,  1356,  -406,   -20,
    -406,   255,  -406,  -406,  -406,  -406,  -406,  -406,  -406,   288,
     312,   300,    79,   311,   398,   397,   404,   389,   210,  -406,
    -406,  -406,  -406,  -406,  -406,   365,  -406,  -406,  -406,   363,
    -406,   364,  -406,   360,  -406,  2181,  3663,   367,   372,   195,
    -406,   368,   386,  3663,  -406,   369,   182,  3663,   140,  -406,
    -406,  -406,  -406,  2327,   376,  3244,  2995,  -406,  -406,  -406,
    -406,   392,  -406,   403,  3663,  -406,  -406,  -406,  -406,  -406,
    -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  3663,
    -406,   126,  -406,  -406,  -406,  -406,  -406,  3118,  -406,  -406,
     360,   399,  -406,  1052,  -406,  -406,  -406,  -406,    26,  3297,
    3334,  -406,  2126,  -406,  -406,  -406,  -406,  -406,    60,  1422,
     395,  -406,  3663,    83,  3663,  3663,  3663,  3663,  3663,  3663,
    3663,  3663,  3663,   428,  3663,  3663,  3663,  3663,  3663,  3663,
    3663,  3663,  3663,  3663,  3663,  3663,  -406,  -406,  -406,   392,
    2749,   408,  -406,   407,   402,   409,  3029,   367,  -406,   220,
    3387,   367,   220,  -406,   414,   416,  -406,   418,   241,   182,
    -406,  -406,   419,  -406,  -406,  -406,   131,   422,   423,   424,
    -406,  -406,  -406,  -406,   199,   399,  -406,  -406,   413,   151,
     426,   153,  -406,  3663,   431,    91,  3029,   174,  3716,  -406,
    -406,  -406,  -406,  -406,   288,   288,   312,   312,   312,   245,
    -406,   300,   300,   300,   300,    79,    79,   311,   398,   397,
     404,   389,   443,  1801,   433,  3663,  2783,  3752,  2443,  -406,
     435,  -406,   400,   436,  -406,  -406,   173,   400,  -406,  3424,
     241,  1052,  -406,  -406,  -406,  2327,  -406,  -406,  3477,  -406,
    -406,  3155,  -406,   438,  -406,   441,  -406,  3663,  3716,  -406,
    3663,  2327,   449,   402,  1979,   450,  2154,   448,  -406,   333,
     333,   333,   472,  -406,   562,   563,  -406,  -406,  -406,  -406,
    -406,  -406,  -406,  -406,  -406,  -406,   184,  -406,   459,  -406,
    -406,   186,  -406,  -406,  -406,  -406,  -406,  -406,  -406,  2327,
    2327,   460,  2327,  2327,   462,  2272,  2299,  3663,  3663,  2443,
    2327,  -406,   241,  -406,  -406,  -406,  2327,  -406,  -406,  2327,
    2327,   463,  2872,   482,   466,   467,   473,  -406,  -406,  -406,
    -406,  -406,  -406,  2327,  3514,   469,  3663,  2906,  2443,  2443,
    -406,  2443,   475,  3567,   477,  3604,   474,   577,  -406,  -406,
    2443,  2443,   478,  2443,  2443,   480,  3626,  2443,  -406,  -406,
    2443,  -406,  -406,  2443,  2443,   481,  -406,  -406,  -406,  -406,
    2443,  -406
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,    54,     0,     0,    55,     0,     0,    56,     0,    52,
      51,    50,    53,    57,    58,    59,    47,     0,     3,    35,
      34,    32,    36,    41,    42,    38,     0,    48,    45,    60,
      61,    46,     0,     0,    27,     0,    25,    26,     0,     0,
       1,    33,    37,    39,    30,    31,     0,     0,     0,    49,
       0,     0,    70,     0,     0,     0,    69,     0,     0,     0,
     134,    43,     0,     0,     0,     0,   157,    40,     0,    29,
       0,     0,     0,    20,    71,    19,    21,    73,    72,    76,
       7,    10,    14,    16,    15,    12,    13,    11,    53,     0,
       0,     4,     6,     8,     9,     5,    17,    18,    19,    25,
       0,     0,    77,    79,    82,    83,     0,    80,    81,     0,
       0,    67,    68,   135,   153,   143,   144,     0,     0,     0,
     146,   133,     0,    28,   158,   161,     0,   166,     0,     0,
     162,   164,   165,     0,   156,     0,     0,    65,     0,   132,
       0,   155,     0,     0,   116,     0,   102,    90,     0,    86,
      88,    98,     0,     0,     0,     0,     0,     0,     0,    75,
      78,   115,    94,   114,     0,     0,     0,   120,    66,     0,
     152,   145,   141,     0,   142,   139,     0,     0,    44,   167,
     160,   163,   159,     0,    63,    64,   131,   154,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,     0,
       0,     0,   183,     0,     0,    27,   266,   267,   268,   269,
     270,   271,   272,   274,   275,   276,   277,   278,     0,   173,
     204,   182,   365,   195,     0,   175,   177,     0,     0,   178,
     184,   196,   185,   197,     0,   186,   187,   188,   189,   221,
     222,   198,   199,   200,   202,   201,   203,   309,   264,   280,
     265,   281,   282,   283,     0,   211,   212,   209,   210,   208,
       0,   103,     0,     0,   101,    85,     0,     0,     0,    97,
      22,    24,    23,     0,   122,     0,     0,   107,   100,     0,
      96,     0,   118,   112,   111,     0,   273,   123,     0,     0,
     119,     0,     0,     0,     0,     0,   151,   310,   280,     0,
     282,   322,   311,   312,   330,   315,   316,   319,   325,   334,
     337,   341,   347,   350,   352,   354,   356,   358,   360,   362,
     380,   363,   286,   140,   137,     0,   147,   138,    62,     0,
     248,     0,   250,     0,   218,     0,     0,     0,     0,    19,
     252,     0,     0,     0,   254,     0,     0,     0,   310,   281,
     283,   320,   321,     0,     0,     0,     0,   174,   176,   179,
      90,   181,   207,     0,     0,   313,   314,   368,   369,   370,
     371,   372,   373,   377,   378,   379,   374,   375,   376,     0,
     105,     0,   106,    87,   170,    89,    93,     0,    92,    91,
       0,   109,   121,     0,    99,    84,    95,   117,     0,     0,
       0,   125,     0,   124,   317,   318,   324,   323,     0,   310,
       0,   149,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,   249,   251,   180,
       0,   243,   246,     0,   242,     0,     0,   288,   294,     0,
       0,   291,     0,   253,   300,     0,   255,     0,     0,   257,
     260,   258,     0,   205,   279,   301,     0,     0,   299,     0,
     364,   104,   169,   171,     0,   110,   108,   113,     0,     0,
       0,     0,   126,     0,     0,     0,     0,     0,   279,   148,
     287,   331,   332,   333,   335,   336,   338,   339,   340,     0,
     346,   342,   344,   343,   345,   348,   349,   351,   353,   355,
     357,   359,     0,     0,     0,     0,     0,     0,     0,   297,
       0,   295,   290,     0,   289,   284,     0,   292,   293,     0,
       0,     0,   263,   261,   259,     0,   302,   307,     0,   308,
     168,     0,   130,     0,   128,     0,   326,     0,     0,   328,
       0,     0,     0,   244,     0,     0,     0,     0,   247,     0,
       0,     0,    27,   215,     0,   184,   191,   192,   193,   194,
     223,   224,   296,   298,   285,   305,     0,   256,     0,   219,
     303,     0,   172,   129,   127,   327,   329,   361,   225,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   306,     0,   304,   226,   227,     0,   245,   229,     0,
       0,     0,     0,   243,     0,     0,     0,   206,   216,   262,
     228,   230,   231,     0,     0,     0,     0,     0,     0,     0,
     232,     0,     0,     0,     0,     0,     0,     0,   220,   233,
       0,     0,     0,     0,     0,     0,     0,     0,   234,   235,
       0,   241,   237,     0,     0,     0,   217,   236,   238,   239,
       0,   240
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -406,  -406,   -45,  -173,  -406,  -406,  -406,   132,   -33,  -151,
       9,  -406,    -5,   -27,  -406,  -406,   583,   158,  -406,    31,
    -406,  -406,   211,   114,     3,  -406,  -406,  -406,   536,    -3,
     552,   -50,   494,   -67,  -406,   -24,  -146,   345,  -242,  -373,
    -406,   -23,  -406,    51,   353,  -377,  -109,  -406,  -406,  -406,
    -406,   516,  -135,  -406,  -406,   549,    19,   -49,  -406,   452,
    -406,   553,    22,  -406,   497,  -406,  -406,  -116,  -406,  -406,
     -81,  -143,  -212,  -406,  -329,   442,   986,   328,  -294,  -406,
    -406,  -406,  -406,  -333,  -406,  -406,  -406,  -192,  -406,  -406,
    -406,  -406,  -406,  -406,  -406,    33,  -391,  -406,  -325,  -406,
    -406,  -406,  -406,  -406,  -406,  -406,   175,   177,  -406,  -406,
     -77,  -320,  -406,   293,  -119,  -295,   383,    95,   828,   239,
     394,   538,  -176,   677,   815,  -405,  -406,    24,   -15,   -86,
      18,   215,   209,   212,   217,   219,  -406,    97,  -406,  1127,
    -406,  -406,  -142
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,   221,    91,    92,    93,    94,    95,    96,    74,
      77,    97,   297,    36,    37,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    53,    54,    55,
      78,    56,   101,   102,   103,   104,   148,   149,   150,   385,
     105,   106,   262,   146,   276,   277,   166,   284,   162,   107,
     108,   109,   167,   288,    30,    59,    60,   118,   119,   120,
      31,    65,    66,   129,   130,   131,   132,   386,   387,   474,
     223,   224,   225,   226,   227,   228,   229,   564,   230,   231,
     232,   566,   233,   234,   235,   236,   567,   335,   237,   568,
     238,   569,   239,   570,   571,   443,   552,   240,   553,   241,
     242,   243,   244,   245,   246,   459,   460,   461,   247,   248,
     298,   299,   250,   447,   448,   449,   251,   300,   253,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   259,
     260,   379,   322
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,   336,   442,    39,   111,   112,   441,   144,    90,   347,
     444,   279,   358,   283,   473,    57,   476,    73,    76,    90,
     137,   337,   289,   282,    76,   163,    99,   351,   352,    49,
      76,   290,    50,   391,   160,   466,    63,   264,    51,    51,
     127,   128,   269,   338,   452,    75,    75,   164,    98,   281,
      42,   110,    75,   341,    32,   157,    90,   345,    75,    98,
     168,   164,   172,   392,   170,   116,   249,   136,   173,   393,
     177,    90,   124,    99,    99,    42,   354,   358,   121,   479,
     481,   157,   361,   549,    90,   184,   185,   134,   249,    99,
     139,   399,    64,    40,   141,    98,    98,   133,    33,   342,
      76,   329,   413,    49,   160,   127,   128,   423,   414,    76,
     275,    98,    58,   485,   487,   404,   405,   406,   407,   346,
     330,    98,   408,   165,    98,   388,    90,   325,    75,    49,
     526,    73,   183,   328,    34,    52,    52,    75,   222,   263,
      64,   151,   182,   586,    99,   402,   397,   249,   475,    38,
      98,   188,   522,   410,   578,   267,   527,   186,    70,    75,
     222,    73,   187,   591,   331,   594,    98,   100,   582,   394,
     122,   396,   424,   425,   426,   427,   114,    41,   126,    45,
     442,   114,   483,   332,   558,   484,    98,   439,   123,   339,
     358,   457,   115,    79,   445,   116,   117,   324,   348,   348,
     116,   455,    69,   458,   611,   462,    52,   278,   280,   576,
     268,   249,   249,   547,   467,   100,   523,   275,   581,   222,
    -214,   442,   469,   442,   565,  -214,  -214,    71,   390,  -213,
     100,    43,   143,   632,  -213,  -213,   161,   470,   252,   491,
     492,   493,   642,   126,   645,   388,   411,   477,   471,    61,
     499,    62,    43,   536,   393,   655,    43,    98,   249,   414,
     252,   355,   442,   442,    67,   412,    68,   613,    98,    68,
     467,   444,   490,   543,   175,   545,   249,   116,   176,   414,
      43,   414,    58,   222,   222,   100,   348,   348,   348,   348,
     409,   442,    80,   512,    81,   574,   548,    82,   514,   523,
     442,   414,   442,    83,   520,   565,   601,   546,   603,    84,
      72,   434,   414,   442,   414,   435,    85,   154,    86,   252,
     446,    68,   123,   540,    68,   249,    87,   541,   521,   169,
     222,    52,   521,   524,   565,   565,   528,   565,   501,   502,
     503,   504,    68,   384,   467,   523,   565,   565,   275,   565,
     565,   265,   266,   565,   202,   142,   565,   365,   366,   565,
     565,  -311,  -311,   489,   143,    73,   565,   596,   597,   598,
     152,   585,   145,   555,   557,  -310,  -310,   532,   415,   416,
     417,   -19,   254,   252,   252,   420,   421,   422,    98,   395,
     266,  -312,  -312,    75,   355,    34,   153,   222,   356,   388,
     418,   419,    68,   147,   254,   496,   497,   498,   428,   429,
     348,   348,   348,   348,   348,   348,   348,   348,    98,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     252,   155,   174,    80,   178,    81,   249,   261,    82,   270,
     249,   249,   494,   495,    83,   179,   505,   506,   252,   577,
      84,   271,   272,   165,   334,   615,   616,    85,   249,    86,
     323,   327,   343,   254,   342,   353,   359,    87,   360,   362,
     625,   364,   363,   382,   249,   389,   398,   249,   348,   249,
     430,   431,   400,   348,   634,   636,   275,   432,   433,   436,
     437,   438,   446,   450,   454,   453,   456,   252,   464,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,   468,   249,   249,   515,   249,   249,   488,   249,   249,
     266,   619,   249,   249,   268,   523,    98,   254,   254,   249,
     517,   518,   249,   249,   516,   529,    34,   255,   530,   531,
     542,   535,   348,   348,   538,   348,   249,   249,   537,   550,
     539,   249,   249,   544,   249,   500,   249,   519,   249,   255,
     554,   572,   573,   249,   249,   583,   249,   249,   584,   249,
     249,   589,   592,   249,   254,   595,   249,   249,   599,   600,
    -190,   602,   606,   249,   609,   623,   349,   349,   626,   628,
       1,   222,   254,   627,   647,   629,   633,   640,     2,   643,
     650,   646,   653,   660,    44,     3,   135,     4,   252,   113,
     171,   383,   252,   252,     5,   381,   158,     6,   255,     7,
     138,     8,     9,    10,    11,   140,   181,    12,   326,   614,
     252,    13,   451,   333,   533,    14,   534,    80,    15,    81,
     508,   254,    82,     0,   509,   507,   252,   587,    83,   252,
     510,   252,   273,   511,    84,     0,     0,     0,     0,     0,
       0,    85,     0,    86,     0,     0,     0,     0,     0,     0,
       0,    87,     0,     0,   349,   349,   349,   349,     0,     0,
       0,   256,   255,   255,   252,   252,     0,   252,   252,     0,
     252,   252,     0,     0,   252,   252,     0,     0,     0,     0,
       0,   252,     0,   256,   252,   252,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,     0,     0,   252,   252,
       0,     0,     0,   252,   252,     0,   252,     0,   252,   255,
     252,     0,     0,     0,     0,   252,   252,     0,   252,   252,
      34,   252,   252,     0,     0,   252,     0,   255,   252,   252,
       0,     0,   254,     0,   274,   252,   254,   254,    80,     0,
      81,     0,   256,    82,     0,     0,     0,     0,     0,    83,
       0,     0,     0,   273,   254,    84,     0,     0,     0,     0,
       0,     0,    85,     0,    86,     0,     0,     0,     0,     0,
     254,     0,    87,   254,     0,   254,   255,     0,   349,   349,
     349,   349,   349,   349,   349,   349,     0,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,     0,     0,
     257,     0,     0,     0,     0,     0,   256,   256,   254,   254,
       0,   254,   254,     0,   254,   254,     0,     0,   254,   254,
       0,     0,   257,     0,     0,   254,     0,     0,   254,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,   254,   254,     0,     0,   349,   254,   254,     0,
     254,   349,   254,   256,   254,   380,     0,     0,     0,   254,
     254,     0,   254,   254,     0,   254,   254,     1,     0,   254,
       0,   256,   254,   254,     0,     2,     0,     0,     0,   254,
       0,   257,     3,     0,     4,     0,     0,   255,     0,     0,
       0,   255,   255,     0,     6,     0,     7,     0,     0,     9,
      10,    11,     0,     0,    12,     0,     0,   617,    13,   255,
     349,   349,    14,   349,     0,    15,     0,     0,     0,     0,
     256,     0,     0,     0,     0,   255,     0,     0,   255,     0,
     255,     0,     0,     0,     0,     0,   637,   638,   258,   639,
       0,     0,     0,     0,     0,   257,   257,     0,   648,   649,
       0,   651,   652,     0,     0,   656,     0,     0,   657,     0,
     258,   658,   659,   255,   255,     0,   255,   255,   661,   255,
     255,     0,     0,   255,   255,     0,     0,     0,     0,     0,
     255,     0,     0,   255,   255,     0,     0,     0,     0,     0,
       0,    16,   257,     0,     0,     0,     0,   255,   255,     0,
       0,     0,   255,   255,     0,   255,     0,   255,     0,   255,
     257,   350,   350,     0,   255,   255,     0,   255,   255,   258,
     255,   255,     0,     0,   255,     0,     0,   255,   255,     0,
       0,   256,     0,     0,   255,   256,   256,    80,     0,    81,
       0,     0,    82,     0,     0,     0,     0,     0,    83,     0,
       0,     0,   273,   256,    84,     0,     0,     0,     0,   257,
       0,    85,     0,    86,     0,     0,     0,     0,     0,   256,
       0,    87,   256,     0,   256,     0,     0,     0,     0,     0,
       0,     0,     0,   258,   258,  -367,  -367,  -367,  -367,  -367,
    -367,  -367,  -367,  -367,  -367,  -367,  -367,     0,     0,   350,
     350,   350,   350,     0,     0,     0,     0,   256,   256,     0,
     256,   256,     0,   256,   256,     0,     0,   256,   256,     0,
       0,     0,     0,     0,   256,     0,     0,   256,   256,     0,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,   256,   256,     0,     0,     0,   256,   256,   258,   256,
       0,   256,     0,   256,     0,     0,     0,     0,   256,   256,
       0,   256,   256,     0,   256,   256,     0,     0,   256,     1,
     257,   256,   256,     0,   257,   257,     0,     2,   256,     0,
       0,     0,     0,     0,     3,     0,     4,     0,     0,     0,
       0,     0,   257,     5,     0,     0,     6,   258,     7,     0,
       0,     9,    10,    11,     0,     0,    12,     0,   257,     0,
      13,   257,     0,   257,    14,     0,     0,    15,     0,     0,
       0,     0,     0,   350,   350,   350,   350,   350,   350,   350,
     350,     0,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,     0,     0,     0,   257,   257,     0,   257,
     257,     0,   257,   257,     0,     0,   257,   257,     0,     0,
       0,     0,     0,   257,     0,     0,   257,   257,     0,     0,
       0,     0,     0,     0,     0,     0,   321,     0,     0,     0,
     257,   257,     0,     0,     0,   257,   257,     0,   257,     0,
     257,   350,   257,    16,     0,     0,   350,   257,   257,     0,
     257,   257,   321,   257,   257,     0,   321,   257,   258,     0,
     257,   257,   258,   258,     0,     0,     0,   257,     0,   463,
       0,     0,     0,     0,     0,   321,     0,     0,     0,     0,
     258,     0,     0,     0,     0,     1,     0,    80,     0,    81,
       0,     0,    82,     0,     0,     0,   258,     0,    83,   258,
       0,   258,     4,     0,    84,   350,   350,     0,   350,     0,
       0,    85,     0,    86,     7,     0,     0,     9,    10,    11,
       0,    87,    12,     0,   321,     0,    13,     0,     0,     0,
      14,     0,    89,    15,   258,   258,     0,   258,   258,     0,
     258,   258,     0,     0,   258,   258,     0,     0,     0,     0,
       0,   258,   321,     0,   258,   258,  -365,  -365,  -365,  -365,
    -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,   258,   258,
       0,     0,     0,   258,   258,     0,   258,     0,   258,     0,
     258,     0,     0,     0,     0,   258,   258,     0,   258,   258,
      34,   258,   258,   321,     0,   258,     0,     0,   258,   258,
     321,     0,     0,     0,   321,   258,   125,   355,     0,     0,
       0,   412,   321,   321,     0,    68,     0,     0,     0,     0,
       0,   321,  -365,  -365,  -365,  -365,  -365,  -365,  -365,  -365,
    -365,  -365,  -365,  -365,   563,     0,   321,     0,     0,     0,
       0,     0,     0,     0,   321,     0,     1,     0,    80,     0,
      81,   579,     0,    82,     0,     0,   321,   321,     0,    83,
       0,     0,     0,     4,     0,    84,     0,   588,     0,   321,
       0,   321,    85,   355,    86,     7,     0,   486,     9,    10,
      11,    68,    87,    88,     0,     0,     0,    13,     0,     0,
       0,    14,   321,    89,    15,     0,     0,   321,     0,     0,
       0,     0,     0,   321,     0,   604,   605,   321,   607,   608,
       0,     0,     0,     0,     0,   463,   618,     0,     0,     0,
       0,     0,   620,     0,     0,   621,   622,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   630,
       0,     0,     0,   321,   563,   579,     0,   588,     0,     0,
       0,    34,     0,     0,     0,     0,   604,   605,     0,   607,
     608,     0,     0,   618,     0,     0,   620,   159,     0,   621,
     622,     0,   321,   321,     0,     0,   630,     0,     0,     0,
       0,     0,    80,   189,    81,     0,   321,    82,     0,     0,
     190,     0,     0,    83,     0,   321,     0,   191,   321,    84,
     192,     0,   193,     0,     0,     0,    85,     0,    86,     0,
     194,     0,     0,     0,     0,   195,    87,     0,     0,   196,
       0,   197,   198,   199,     0,     0,   200,     0,     0,   201,
       1,     0,    80,     0,    81,     0,     0,    82,     0,     0,
       0,     0,     0,    83,   202,     0,     0,     4,     0,    84,
       0,     0,     0,     0,   321,   321,    85,     0,    86,     7,
       0,     0,     9,    10,    11,     0,    87,    12,     0,   321,
       0,    13,     0,     0,     0,    14,     0,    89,    15,   203,
     204,     0,     0,   321,   321,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,     0,
     143,   219,     0,     0,   220,    80,   189,    81,     0,     0,
      82,     0,     0,   190,     0,     0,    83,     0,     0,     0,
     191,     0,    84,   192,     0,   193,     0,     0,     0,    85,
       0,    86,     0,   194,     0,    34,     0,     0,   195,    87,
       0,     0,   285,     0,   197,   286,   199,     0,     0,   200,
       0,   180,   201,     0,     0,     0,     0,     0,     0,     0,
      80,   189,    81,     0,   194,    82,     0,   202,   190,     0,
       0,    83,     0,   196,     0,   191,   198,    84,   192,     0,
     193,     0,     0,     0,    85,     0,    86,     0,   194,     0,
       0,     0,     0,   195,    87,     0,     0,   196,     0,   197,
     198,   199,   203,   204,   200,     0,     0,   201,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   202,   143,   287,     0,     0,   220,     0,     0,
       0,     0,     0,   203,   204,     0,     0,     0,     0,    34,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   551,     0,     0,     0,   203,   204,     0,
       0,     0,     0,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,     0,   143,   357,
       0,     0,   220,    80,   189,    81,     0,     0,    82,     0,
       0,   190,     0,     0,    83,     0,     0,     0,   191,     0,
      84,   192,     0,   193,     0,     0,     0,    85,     0,    86,
       0,   194,     0,     0,     0,     0,   195,    87,     0,     0,
     196,     0,   197,   198,   199,     0,     0,   200,     0,     0,
     201,     0,     0,     0,     0,     0,     0,     0,    80,   189,
      81,     0,   194,    82,     0,   202,   190,     0,     0,    83,
       0,   196,     0,   191,   198,    84,   192,     0,   193,     0,
       0,     0,    85,     0,    86,     0,   194,     0,     0,     0,
       0,   195,    87,     0,     0,   196,     0,   197,   198,   199,
     203,   204,   200,     0,     0,   201,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     202,   143,   401,     0,     0,   220,     0,     0,     0,     0,
       0,   203,   204,     0,     0,     0,     0,    34,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   590,     0,     0,     0,   203,   204,     0,     0,     0,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,     0,   143,   403,     0,     0,
     220,    80,   189,    81,     0,     0,    82,     0,     0,   190,
       0,     0,    83,     0,     0,     0,   191,     0,    84,   192,
       0,   193,     0,     0,     0,    85,     0,    86,     0,   194,
       0,     0,     0,     0,   195,    87,     0,     0,   196,     0,
     197,   198,   199,     0,     0,   200,     0,     0,   201,     0,
       0,     0,     0,     0,     0,     0,    80,   194,    81,     0,
       0,    82,     0,   202,     0,     0,   196,    83,     0,   198,
       0,   191,     0,    84,     0,     0,     0,     0,     0,     0,
      85,     0,    86,     0,   194,     0,     0,     0,     0,     0,
      87,     0,     0,   196,     0,     0,   198,     0,   203,   204,
       0,     0,     0,     0,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   202,   143,
     482,     0,     0,   220,     0,     0,   203,   204,     0,     0,
       0,     0,    34,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   593,     0,     0,     0,
       0,     0,     0,   203,   204,     0,     0,     0,     0,    34,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,     0,    80,   194,    81,     0,   440,    82,
       0,     0,     0,     0,   196,    83,     0,   198,     0,   191,
       0,    84,     0,     0,     0,     0,     0,     0,    85,     0,
      86,     0,   194,   189,     0,     0,     0,     0,    87,     0,
     190,   196,     0,     0,   198,     0,     0,     0,     0,     0,
     192,     0,   193,     0,     0,     0,     0,     0,     0,     0,
     194,     0,     0,     0,     0,   195,   202,     0,     0,   196,
       0,   197,   198,   199,   203,   204,   200,     0,     0,   201,
      34,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   610,     0,     0,     0,     0,     0,
       0,   203,   204,     0,     0,     0,     0,    34,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,     0,     0,     0,     0,     0,   612,     0,     0,   203,
     204,     0,     0,     0,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   189,
     143,     0,     0,     0,   220,     0,   190,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   559,     0,   560,     0,
       0,     0,     0,     0,     0,     0,   194,     0,     0,     0,
       0,   195,     0,     0,     0,   196,     0,   197,   198,   199,
       0,    80,   200,    81,     0,   561,    82,     0,     0,     0,
       0,     0,    83,     0,     0,     0,     0,     0,    84,     0,
       0,     0,     0,     0,     0,    85,     0,    86,     0,   194,
       0,     0,     0,     0,     0,    87,     0,     0,   196,     0,
       0,   198,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   203,   204,     0,     0,     0,
       0,   562,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,     0,   143,     0,     0,     0,
     220,     0,     0,     0,   291,   292,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,     0,   203,   204,
     294,     0,     0,     0,    34,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   295,     1,     0,
      80,     0,    81,     0,     0,    82,     0,     0,     0,     0,
       0,    83,     0,     0,     0,     4,     0,    84,     0,     0,
       0,     0,     0,     0,    85,     0,    86,     7,     0,     0,
       9,    10,    11,     0,    87,    88,     0,     0,     0,    13,
       1,     0,    80,    14,    81,    89,    15,    82,     0,   194,
       0,     0,     0,    83,     0,     0,     0,     4,   196,    84,
       0,   198,     0,     0,     0,     0,    85,     0,    86,     7,
       0,     0,     9,    10,    11,     0,    87,    12,     0,     0,
       0,    13,     0,   194,     0,    14,     0,   156,    15,     0,
       0,     0,   196,     0,     0,   198,     0,     0,     0,     0,
       0,     0,     0,    34,   291,   292,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,     0,   203,   204,
     294,     0,     0,     0,    34,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   295,   291,   292,
       0,     0,     0,   340,     0,    34,     0,     0,     0,     0,
     293,     0,   203,   204,   294,     0,     0,     0,    34,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   295,   194,     0,     0,     1,     0,   344,     0,     0,
       0,   196,     0,    46,   198,     0,     0,     0,     0,     0,
      47,     0,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     7,     0,   194,     9,    10,    11,
       0,     0,    12,     0,     0,   196,    13,     0,   198,     0,
      14,     0,     0,    15,     0,     0,     0,   291,   292,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   293,
       0,   203,   204,   294,     0,     0,     0,    34,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     295,   291,   292,     0,     0,     0,   513,     0,     0,     0,
       0,     0,     0,   293,     0,   203,   204,   294,     0,     0,
       0,    34,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   295,   194,     0,     0,     0,     0,
     556,     0,     0,     0,   196,     0,     0,   198,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,   196,     0,
       0,   198,     0,     0,     0,     0,     0,     0,     0,     0,
     291,   292,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   293,     0,   203,   204,   294,     0,     0,     0,
      34,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   295,   291,   292,     0,     0,     0,   624,
       0,     0,     0,     0,     0,     0,   293,     0,   203,   204,
     294,     0,     0,     0,    34,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   295,   194,     0,
       0,     0,     0,   635,     0,     0,     0,   196,     0,     0,
     198,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   194,     0,     0,     0,     0,     0,     0,     0,
       0,   196,     0,     0,   198,     0,     0,     0,     0,     0,
       0,     0,     0,   291,   292,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   293,     0,   203,   204,   294,
       0,     0,     0,    34,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   295,   291,   292,     0,
       0,   272,     0,     0,     0,     0,     0,     0,     0,   293,
       0,   203,   204,   294,     0,     0,     0,    34,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     295,   194,     0,     0,     0,   519,     0,     0,     0,     0,
     196,     0,     0,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   194,     0,
       0,     0,     0,     0,     0,     0,     0,   196,     0,     0,
     198,     0,     0,     0,     0,     0,   291,   292,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   293,     0,
     203,   204,   294,     0,     0,     0,    34,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   295,
     194,   384,   472,   291,   292,     0,     0,     0,     0,   196,
       0,     0,   198,     0,     0,   293,     0,   203,   204,   294,
       0,     0,     0,    34,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   295,   194,   384,     0,
       0,     0,     0,     0,     0,     0,   196,     0,     0,   198,
       0,     0,     0,     0,     0,   291,   292,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,     0,   203,
     204,   294,     0,     0,     0,    34,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   295,   296,
     194,     0,   291,   292,     0,     0,     0,     0,     0,   196,
       0,     0,   198,     0,   293,     0,   203,   204,   294,     0,
       0,     0,    34,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   295,   465,   194,     0,     0,
       0,     0,     0,     0,     0,     0,   196,     0,     0,   198,
       0,     0,     0,     0,     0,   291,   292,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,     0,   203,
     204,   294,     0,     0,     0,    34,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   295,   478,
     194,     0,   291,   292,     0,     0,     0,     0,     0,   196,
       0,     0,   198,     0,   293,     0,   203,   204,   294,     0,
       0,     0,    34,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   295,   480,   194,     0,     0,
       0,     0,     0,     0,     0,     0,   196,     0,     0,   198,
       0,     0,     0,     0,     0,   291,   292,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,     0,   203,
     204,   294,     0,     0,     0,    34,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   295,   525,
     194,     0,   291,   292,     0,     0,     0,     0,     0,   196,
       0,     0,   198,     0,   293,     0,   203,   204,   294,     0,
       0,     0,    34,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   295,   575,   194,     0,     0,
       0,     0,     0,     0,     0,     0,   196,     0,     0,   198,
       0,     0,     0,     0,     0,   291,   292,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,     0,   203,
     204,   294,     0,     0,     0,    34,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   295,   580,
     194,     0,     0,     0,     0,     0,     0,     0,     0,   196,
       0,     0,   198,     0,     0,     0,   203,   204,     0,     0,
       0,     0,    34,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   631,   194,     0,     0,
       0,     0,     0,     0,     0,     0,   196,     0,     0,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,   196,   203,
     204,   198,     0,     0,     0,    34,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   641,
       0,     0,     0,     0,     0,     0,   194,     0,     0,     0,
       0,     0,     0,     0,     0,   196,   203,   204,   198,     0,
       0,     0,    34,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   644,     0,   203,   204,
       0,     0,     0,     0,    34,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   654,   194,
       0,   291,   292,     0,     0,     0,     0,     0,   196,     0,
       0,   198,     0,   293,     0,   203,   204,   294,     0,     0,
       0,    34,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   295,   194,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,   198,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,     0,     0,     0,
     294,     0,     0,     0,    34,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   295,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   203,   204,     0,     0,     0,     0,
      34,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218
};

static const yytype_int16 yycheck[] =
{
       5,   193,   335,     8,    54,    55,   335,    88,    53,   201,
     335,   157,   224,   164,   387,    26,   393,    50,    51,    64,
      70,   194,   165,   158,    57,   106,    53,   203,   204,    26,
      63,   166,    19,   275,   101,   355,    19,   146,    26,    26,
      64,    64,   151,   194,   339,    50,    51,    47,    53,   158,
      19,    54,    57,   195,   108,   100,   101,   199,    63,    64,
     110,    47,   124,   122,   114,   127,   143,    70,   117,   128,
     119,   116,    63,   100,   101,    44,   218,   289,    59,   399,
     400,   126,   228,   488,   129,   135,   136,    65,   165,   116,
      71,   121,   123,     0,    72,   100,   101,   128,   108,   129,
     133,   108,   122,   100,   171,   129,   129,    28,   128,   142,
     155,   116,   123,   408,   409,   291,   292,   293,   294,   200,
     127,   126,   295,   123,   129,   267,   171,   176,   133,   126,
     450,   164,   135,   183,   108,   123,   123,   142,   143,   125,
     123,    90,   133,   548,   171,   288,   281,   224,   390,   108,
     155,   142,   447,   295,   531,    70,   451,   138,   108,   164,
     165,   194,   140,   554,   108,   556,   171,    53,   541,   278,
      90,   280,    93,    94,    95,    96,   108,    19,    64,    21,
     513,   108,   122,   127,   517,   125,   191,   333,   108,   194,
     402,     9,   124,   124,   336,   127,   128,   124,   203,   204,
     127,   343,    44,    21,   595,   347,   123,   156,   157,   529,
     125,   288,   289,   122,   356,   101,   125,   262,   538,   224,
     122,   554,   364,   556,   518,   127,   128,   108,   273,   122,
     116,    20,   123,   624,   127,   128,   127,   379,   143,   415,
     416,   417,   633,   129,   635,   387,   296,   398,   122,   127,
     423,   129,    41,   122,   128,   646,    45,   262,   335,   128,
     165,   121,   595,   596,   127,   125,   129,   596,   273,   129,
     412,   596,   414,   122,   124,   122,   353,   127,   128,   128,
      69,   128,   123,   288,   289,   171,   291,   292,   293,   294,
     295,   624,     5,   435,     7,   122,   122,    10,   440,   125,
     633,   128,   635,    16,   446,   599,   122,   483,   122,    22,
     108,   101,   128,   646,   128,   105,    29,   125,    31,   224,
     125,   129,   108,   124,   129,   402,    39,   128,   447,   121,
     335,   123,   451,   449,   628,   629,   452,   631,   424,   425,
     426,   427,   129,   123,   486,   125,   640,   641,   393,   643,
     644,   127,   128,   647,    67,   128,   650,   102,   103,   653,
     654,   102,   103,   413,   123,   398,   660,   559,   560,   561,
     125,   547,   108,   515,   516,   102,   103,   458,    90,    91,
      92,   108,   143,   288,   289,    85,    86,    87,   393,   127,
     128,   102,   103,   398,   121,   108,   125,   402,   125,   541,
      88,    89,   129,   108,   165,   420,   421,   422,    97,    98,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     335,   121,   124,     5,   127,     7,   513,   121,    10,   126,
     517,   518,   418,   419,    16,   127,   428,   429,   353,   530,
      22,   126,   126,   123,   121,   597,   598,    29,   535,    31,
     124,   124,   121,   224,   129,   106,   127,    39,   108,   127,
     612,   125,   129,   126,   551,   126,   128,   554,   483,   556,
      82,    84,   121,   488,   626,   627,   531,    83,    99,   124,
     127,   127,   125,   121,   108,   127,   127,   402,   122,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,   108,   589,   590,   106,   592,   593,   122,   595,   596,
     128,   602,   599,   600,   125,   125,   531,   288,   289,   606,
     128,   122,   609,   610,   127,   121,   108,   143,   122,   121,
     127,   122,   547,   548,   121,   550,   623,   624,   126,   106,
     126,   628,   629,   127,   631,   423,   633,   126,   635,   165,
     127,   126,   126,   640,   641,   127,   643,   644,   127,   646,
     647,   122,   122,   650,   335,   127,   653,   654,   106,    17,
      17,   122,   122,   660,   122,   122,   203,   204,   106,   122,
       3,   596,   353,   127,    17,   122,   127,   122,    11,   122,
     122,   127,   122,   122,    21,    18,    70,    20,   513,    57,
     116,   266,   517,   518,    27,   262,   100,    30,   224,    32,
      71,    34,    35,    36,    37,    72,   129,    40,   176,   596,
     535,    44,   339,   191,   459,    48,   459,     5,    51,     7,
     431,   402,    10,    -1,   432,   430,   551,   550,    16,   554,
     433,   556,    20,   434,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,   291,   292,   293,   294,    -1,    -1,
      -1,   143,   288,   289,   589,   590,    -1,   592,   593,    -1,
     595,   596,    -1,    -1,   599,   600,    -1,    -1,    -1,    -1,
      -1,   606,    -1,   165,   609,   610,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,   623,   624,
      -1,    -1,    -1,   628,   629,    -1,   631,    -1,   633,   335,
     635,    -1,    -1,    -1,    -1,   640,   641,    -1,   643,   644,
     108,   646,   647,    -1,    -1,   650,    -1,   353,   653,   654,
      -1,    -1,   513,    -1,   122,   660,   517,   518,     5,    -1,
       7,    -1,   224,    10,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    20,   535,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,
     551,    -1,    39,   554,    -1,   556,   402,    -1,   415,   416,
     417,   418,   419,   420,   421,   422,    -1,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    -1,   288,   289,   589,   590,
      -1,   592,   593,    -1,   595,   596,    -1,    -1,   599,   600,
      -1,    -1,   165,    -1,    -1,   606,    -1,    -1,   609,   610,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   623,   624,    -1,    -1,   483,   628,   629,    -1,
     631,   488,   633,   335,   635,   122,    -1,    -1,    -1,   640,
     641,    -1,   643,   644,    -1,   646,   647,     3,    -1,   650,
      -1,   353,   653,   654,    -1,    11,    -1,    -1,    -1,   660,
      -1,   224,    18,    -1,    20,    -1,    -1,   513,    -1,    -1,
      -1,   517,   518,    -1,    30,    -1,    32,    -1,    -1,    35,
      36,    37,    -1,    -1,    40,    -1,    -1,   599,    44,   535,
     547,   548,    48,   550,    -1,    51,    -1,    -1,    -1,    -1,
     402,    -1,    -1,    -1,    -1,   551,    -1,    -1,   554,    -1,
     556,    -1,    -1,    -1,    -1,    -1,   628,   629,   143,   631,
      -1,    -1,    -1,    -1,    -1,   288,   289,    -1,   640,   641,
      -1,   643,   644,    -1,    -1,   647,    -1,    -1,   650,    -1,
     165,   653,   654,   589,   590,    -1,   592,   593,   660,   595,
     596,    -1,    -1,   599,   600,    -1,    -1,    -1,    -1,    -1,
     606,    -1,    -1,   609,   610,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   335,    -1,    -1,    -1,    -1,   623,   624,    -1,
      -1,    -1,   628,   629,    -1,   631,    -1,   633,    -1,   635,
     353,   203,   204,    -1,   640,   641,    -1,   643,   644,   224,
     646,   647,    -1,    -1,   650,    -1,    -1,   653,   654,    -1,
      -1,   513,    -1,    -1,   660,   517,   518,     5,    -1,     7,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,   535,    22,    -1,    -1,    -1,    -1,   402,
      -1,    29,    -1,    31,    -1,    -1,    -1,    -1,    -1,   551,
      -1,    39,   554,    -1,   556,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   288,   289,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    -1,    -1,   291,
     292,   293,   294,    -1,    -1,    -1,    -1,   589,   590,    -1,
     592,   593,    -1,   595,   596,    -1,    -1,   599,   600,    -1,
      -1,    -1,    -1,    -1,   606,    -1,    -1,   609,   610,    -1,
     335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   623,   624,    -1,    -1,    -1,   628,   629,   353,   631,
      -1,   633,    -1,   635,    -1,    -1,    -1,    -1,   640,   641,
      -1,   643,   644,    -1,   646,   647,    -1,    -1,   650,     3,
     513,   653,   654,    -1,   517,   518,    -1,    11,   660,    -1,
      -1,    -1,    -1,    -1,    18,    -1,    20,    -1,    -1,    -1,
      -1,    -1,   535,    27,    -1,    -1,    30,   402,    32,    -1,
      -1,    35,    36,    37,    -1,    -1,    40,    -1,   551,    -1,
      44,   554,    -1,   556,    48,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,   415,   416,   417,   418,   419,   420,   421,
     422,    -1,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,    -1,    -1,    -1,   589,   590,    -1,   592,
     593,    -1,   595,   596,    -1,    -1,   599,   600,    -1,    -1,
      -1,    -1,    -1,   606,    -1,    -1,   609,   610,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,    -1,
     623,   624,    -1,    -1,    -1,   628,   629,    -1,   631,    -1,
     633,   483,   635,   127,    -1,    -1,   488,   640,   641,    -1,
     643,   644,   195,   646,   647,    -1,   199,   650,   513,    -1,
     653,   654,   517,   518,    -1,    -1,    -1,   660,    -1,   353,
      -1,    -1,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
     535,    -1,    -1,    -1,    -1,     3,    -1,     5,    -1,     7,
      -1,    -1,    10,    -1,    -1,    -1,   551,    -1,    16,   554,
      -1,   556,    20,    -1,    22,   547,   548,    -1,   550,    -1,
      -1,    29,    -1,    31,    32,    -1,    -1,    35,    36,    37,
      -1,    39,    40,    -1,   267,    -1,    44,    -1,    -1,    -1,
      48,    -1,    50,    51,   589,   590,    -1,   592,   593,    -1,
     595,   596,    -1,    -1,   599,   600,    -1,    -1,    -1,    -1,
      -1,   606,   295,    -1,   609,   610,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,   623,   624,
      -1,    -1,    -1,   628,   629,    -1,   631,    -1,   633,    -1,
     635,    -1,    -1,    -1,    -1,   640,   641,    -1,   643,   644,
     108,   646,   647,   336,    -1,   650,    -1,    -1,   653,   654,
     343,    -1,    -1,    -1,   347,   660,   124,   121,    -1,    -1,
      -1,   125,   355,   356,    -1,   129,    -1,    -1,    -1,    -1,
      -1,   364,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,   518,    -1,   379,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   387,    -1,     3,    -1,     5,    -1,
       7,   535,    -1,    10,    -1,    -1,   399,   400,    -1,    16,
      -1,    -1,    -1,    20,    -1,    22,    -1,   551,    -1,   412,
      -1,   414,    29,   121,    31,    32,    -1,   125,    35,    36,
      37,   129,    39,    40,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    48,   435,    50,    51,    -1,    -1,   440,    -1,    -1,
      -1,    -1,    -1,   446,    -1,   589,   590,   450,   592,   593,
      -1,    -1,    -1,    -1,    -1,   599,   600,    -1,    -1,    -1,
      -1,    -1,   606,    -1,    -1,   609,   610,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   623,
      -1,    -1,    -1,   486,   628,   629,    -1,   631,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,   640,   641,    -1,   643,
     644,    -1,    -1,   647,    -1,    -1,   650,   124,    -1,   653,
     654,    -1,   515,   516,    -1,    -1,   660,    -1,    -1,    -1,
      -1,    -1,     5,     6,     7,    -1,   529,    10,    -1,    -1,
      13,    -1,    -1,    16,    -1,   538,    -1,    20,   541,    22,
      23,    -1,    25,    -1,    -1,    -1,    29,    -1,    31,    -1,
      33,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    42,
      -1,    44,    45,    46,    -1,    -1,    49,    -1,    -1,    52,
       3,    -1,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    16,    67,    -1,    -1,    20,    -1,    22,
      -1,    -1,    -1,    -1,   597,   598,    29,    -1,    31,    32,
      -1,    -1,    35,    36,    37,    -1,    39,    40,    -1,   612,
      -1,    44,    -1,    -1,    -1,    48,    -1,    50,    51,   102,
     103,    -1,    -1,   626,   627,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
     123,   124,    -1,    -1,   127,     5,     6,     7,    -1,    -1,
      10,    -1,    -1,    13,    -1,    -1,    16,    -1,    -1,    -1,
      20,    -1,    22,    23,    -1,    25,    -1,    -1,    -1,    29,
      -1,    31,    -1,    33,    -1,   108,    -1,    -1,    38,    39,
      -1,    -1,    42,    -1,    44,    45,    46,    -1,    -1,    49,
      -1,   124,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     6,     7,    -1,    33,    10,    -1,    67,    13,    -1,
      -1,    16,    -1,    42,    -1,    20,    45,    22,    23,    -1,
      25,    -1,    -1,    -1,    29,    -1,    31,    -1,    33,    -1,
      -1,    -1,    -1,    38,    39,    -1,    -1,    42,    -1,    44,
      45,    46,   102,   103,    49,    -1,    -1,    52,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    67,   123,   124,    -1,    -1,   127,    -1,    -1,
      -1,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    -1,    -1,    -1,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,   123,   124,
      -1,    -1,   127,     5,     6,     7,    -1,    -1,    10,    -1,
      -1,    13,    -1,    -1,    16,    -1,    -1,    -1,    20,    -1,
      22,    23,    -1,    25,    -1,    -1,    -1,    29,    -1,    31,
      -1,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,
      42,    -1,    44,    45,    46,    -1,    -1,    49,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,
       7,    -1,    33,    10,    -1,    67,    13,    -1,    -1,    16,
      -1,    42,    -1,    20,    45,    22,    23,    -1,    25,    -1,
      -1,    -1,    29,    -1,    31,    -1,    33,    -1,    -1,    -1,
      -1,    38,    39,    -1,    -1,    42,    -1,    44,    45,    46,
     102,   103,    49,    -1,    -1,    52,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      67,   123,   124,    -1,    -1,   127,    -1,    -1,    -1,    -1,
      -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,   123,   124,    -1,    -1,
     127,     5,     6,     7,    -1,    -1,    10,    -1,    -1,    13,
      -1,    -1,    16,    -1,    -1,    -1,    20,    -1,    22,    23,
      -1,    25,    -1,    -1,    -1,    29,    -1,    31,    -1,    33,
      -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    42,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,    33,     7,    -1,
      -1,    10,    -1,    67,    -1,    -1,    42,    16,    -1,    45,
      -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    -1,    31,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    42,    -1,    -1,    45,    -1,   102,   103,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    67,   123,
     124,    -1,    -1,   127,    -1,    -1,   102,   103,    -1,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,     5,    33,     7,    -1,   127,    10,
      -1,    -1,    -1,    -1,    42,    16,    -1,    45,    -1,    20,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      31,    -1,    33,     6,    -1,    -1,    -1,    -1,    39,    -1,
      13,    42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    38,    67,    -1,    -1,    42,
      -1,    44,    45,    46,   102,   103,    49,    -1,    -1,    52,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,    -1,
      -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,    -1,   127,    -1,    -1,   102,
     103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,     6,
     123,    -1,    -1,    -1,   127,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    42,    -1,    44,    45,    46,
      -1,     5,    49,     7,    -1,    52,    10,    -1,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    31,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    42,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    -1,   123,    -1,    -1,    -1,
     127,    -1,    -1,    -1,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,   103,
     104,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,     3,    -1,
       5,    -1,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    20,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    31,    32,    -1,    -1,
      35,    36,    37,    -1,    39,    40,    -1,    -1,    -1,    44,
       3,    -1,     5,    48,     7,    50,    51,    10,    -1,    33,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    42,    22,
      -1,    45,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,
      -1,    -1,    35,    36,    37,    -1,    39,    40,    -1,    -1,
      -1,    44,    -1,    33,    -1,    48,    -1,    50,    51,    -1,
      -1,    -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,   103,
     104,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    88,    89,
      -1,    -1,    -1,   127,    -1,   108,    -1,    -1,    -1,    -1,
     100,    -1,   102,   103,   104,    -1,    -1,    -1,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    33,    -1,    -1,     3,    -1,   127,    -1,    -1,
      -1,    42,    -1,    11,    45,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    32,    -1,    33,    35,    36,    37,
      -1,    -1,    40,    -1,    -1,    42,    44,    -1,    45,    -1,
      48,    -1,    -1,    51,    -1,    -1,    -1,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
      -1,   102,   103,   104,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    88,    89,    -1,    -1,    -1,   127,    -1,    -1,    -1,
      -1,    -1,    -1,   100,    -1,   102,   103,   104,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    33,    -1,    -1,    -1,    -1,
     127,    -1,    -1,    -1,    42,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   100,    -1,   102,   103,   104,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    88,    89,    -1,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,   103,
     104,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    33,    -1,
      -1,    -1,    -1,   127,    -1,    -1,    -1,    42,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   100,    -1,   102,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    88,    89,    -1,
      -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
      -1,   102,   103,   104,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    33,    -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,
     102,   103,   104,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      33,   123,   124,    88,    89,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    45,    -1,    -1,   100,    -1,   102,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    33,   123,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      33,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    45,    -1,   100,    -1,   102,   103,   104,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      33,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    45,    -1,   100,    -1,   102,   103,   104,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      33,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    45,    -1,   100,    -1,   102,   103,   104,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    45,    -1,    -1,    -1,   102,   103,    -1,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,   102,
     103,    45,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,   102,   103,    45,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,   102,   103,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    33,
      -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    45,    -1,   100,    -1,   102,   103,   104,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,
     104,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,    11,    18,    20,    27,    30,    32,    34,    35,
      36,    37,    40,    44,    48,    51,   127,   133,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     186,   192,   108,   108,   108,   144,   145,   146,   108,   144,
       0,   149,   151,   154,   148,   149,    11,    18,    30,   156,
      19,    26,   123,   159,   160,   161,   163,    26,   123,   187,
     188,   127,   129,    19,   123,   193,   194,   127,   129,   149,
     108,   108,   108,   140,   141,   144,   140,   142,   162,   124,
       5,     7,    10,    16,    22,    29,    31,    39,    40,    50,
     134,   135,   136,   137,   138,   139,   140,   143,   144,   145,
     155,   164,   165,   166,   167,   172,   173,   181,   182,   183,
     161,   163,   163,   162,   108,   124,   127,   128,   189,   190,
     191,   188,    90,   108,   142,   124,   155,   167,   173,   195,
     196,   197,   198,   128,   194,   160,   161,   163,   187,   188,
     193,   194,   128,   123,   202,   108,   175,   108,   168,   169,
     170,   175,   125,   125,   125,   121,    50,   134,   183,   124,
     165,   127,   180,   202,    47,   123,   178,   184,   163,   121,
     163,   164,   124,   189,   124,   124,   128,   189,   127,   127,
     124,   196,   142,   161,   163,   163,   188,   194,   142,     6,
      13,    20,    23,    25,    33,    38,    42,    44,    45,    46,
      49,    52,    67,   102,   103,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   124,
     127,   134,   144,   202,   203,   204,   205,   206,   207,   208,
     210,   211,   212,   214,   215,   216,   217,   220,   222,   224,
     229,   231,   232,   233,   234,   235,   236,   240,   241,   242,
     244,   248,   249,   250,   251,   252,   253,   255,   256,   271,
     272,   121,   174,   125,   178,   127,   128,    70,   125,   178,
     126,   126,   126,    20,   122,   134,   176,   177,   175,   168,
     175,   178,   184,   141,   179,    42,    45,   124,   185,   203,
     184,    88,    89,   100,   104,   121,   122,   144,   242,   243,
     249,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   274,   124,   124,   189,   191,   124,   163,   108,
     127,   108,   127,   207,   121,   219,   219,   135,   141,   144,
     127,   274,   129,   121,   127,   274,   202,   219,   144,   248,
     250,   254,   254,   106,   274,   121,   125,   124,   204,   127,
     108,   168,   127,   129,   125,   102,   103,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   273,
     122,   176,   126,   169,   123,   171,   199,   200,   274,   126,
     134,   170,   122,   128,   178,   127,   178,   184,   128,   121,
     121,   124,   203,   124,   254,   254,   254,   254,   135,   144,
     274,   163,   125,   122,   128,    90,    91,    92,    88,    89,
      85,    86,    87,    28,    93,    94,    95,    96,    97,    98,
      82,    84,    83,    99,   101,   105,   124,   127,   127,   168,
     127,   206,   215,   227,   230,   274,   125,   245,   246,   247,
     121,   245,   247,   127,   108,   274,   127,     9,    21,   237,
     238,   239,   274,   208,   122,   122,   243,   274,   108,   274,
     274,   122,   124,   171,   201,   170,   177,   141,   122,   243,
     122,   243,   124,   122,   125,   247,   125,   247,   122,   163,
     274,   254,   254,   254,   259,   259,   260,   260,   260,   135,
     139,   261,   261,   261,   261,   262,   262,   263,   264,   265,
     266,   267,   274,   127,   274,   106,   127,   128,   122,   126,
     274,   246,   247,   125,   199,   122,   243,   247,   199,   121,
     122,   121,   202,   238,   239,   122,   122,   126,   121,   126,
     124,   128,   127,   122,   127,   122,   254,   122,   122,   257,
     106,   122,   228,   230,   127,   274,   127,   274,   215,    23,
      25,    52,   108,   208,   209,   210,   213,   218,   221,   223,
     225,   226,   126,   126,   122,   122,   243,   202,   177,   208,
     122,   243,   171,   127,   127,   254,   257,   269,   208,   122,
     122,   228,   122,   122,   228,   127,   219,   219,   219,   106,
      17,   122,   122,   122,   208,   208,   122,   208,   208,   122,
     122,   228,   127,   206,   227,   274,   274,   209,   208,   202,
     208,   208,   208,   122,   127,   274,   106,   127,   122,   122,
     208,   122,   228,   127,   274,   127,   274,   209,   209,   209,
     122,   122,   228,   122,   122,   228,   127,    17,   209,   209,
     122,   209,   209,   122,   122,   228,   209,   209,   209,   209,
     122,   209
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   132,   133,   133,   134,   134,   135,   135,   136,   136,
     137,   137,   137,   137,   137,   138,   138,   139,   139,   140,
     141,   142,   143,   143,   143,   144,   144,   145,   146,   147,
     147,   147,   147,   147,   147,   147,   148,   148,   149,   149,
     150,   151,   151,   152,   153,   154,   154,   154,   155,   155,
     156,   156,   156,   156,   156,   156,   156,   156,   156,   156,
     157,   157,   158,   158,   158,   158,   158,   158,   158,   158,
     159,   160,   161,   162,   162,   163,   163,   164,   164,   165,
     165,   165,   166,   166,   167,   167,   168,   168,   169,   169,
     170,   170,   171,   171,   172,   173,   173,   173,   173,   173,
     173,   173,   173,   174,   175,   175,   175,   176,   176,   177,
     177,   178,   179,   179,   180,   180,   181,   182,   182,   182,
     182,   183,   183,   184,   184,   184,   184,   185,   185,   185,
     185,   186,   186,   186,   186,   187,   188,   188,   188,   188,
     188,   188,   188,   188,   189,   189,   190,   190,   191,   191,
     191,   191,   191,   191,   192,   192,   192,   192,   193,   193,
     194,   194,   195,   195,   196,   196,   197,   198,   199,   199,
     200,   201,   201,   202,   202,   203,   203,   204,   204,   205,
     206,   206,   207,   207,   208,   208,   208,   208,   208,   208,
     209,   209,   209,   209,   209,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   211,   212,   213,   214,   215,   215,
     215,   215,   215,   215,   215,   216,   217,   218,   219,   220,
     221,   222,   222,   223,   223,   224,   224,   224,   224,   224,
     224,   224,   224,   225,   225,   225,   225,   225,   225,   225,
     225,   226,   227,   227,   228,   229,   230,   230,   231,   231,
     232,   232,   233,   233,   234,   234,   235,   236,   236,   236,
     237,   237,   238,   239,   240,   240,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   242,   242,   243,   243,   244,   244,
     244,   244,   244,   244,   245,   245,   246,   247,   247,   248,
     248,   249,   249,   249,   249,   249,   249,   250,   250,   251,
     251,   251,   251,   252,   253,   254,   254,   254,   254,   254,
     255,   256,   257,   257,   257,   257,   258,   258,   258,   258,
     259,   259,   259,   259,   260,   260,   260,   261,   261,   261,
     261,   262,   262,   262,   262,   262,   262,   263,   263,   263,
     264,   264,   265,   265,   266,   266,   267,   267,   268,   268,
     269,   269,   270,   270,   271,   272,   272,   272,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     274
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     1,     1,     1,     3,     3,
       2,     2,     1,     2,     1,     1,     1,     2,     1,     2,
       3,     1,     1,     3,     5,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     6,     5,     5,     4,     5,     4,     4,     3,
       1,     2,     2,     1,     3,     3,     2,     1,     2,     1,
       1,     1,     1,     1,     4,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     2,     4,     3,     3,     2,     4,
       3,     3,     2,     1,     4,     3,     3,     1,     3,     2,
       3,     2,     1,     3,     1,     1,     2,     4,     3,     3,
       2,     4,     3,     2,     3,     3,     4,     5,     4,     5,
       4,     5,     4,     4,     3,     2,     5,     4,     4,     3,
       4,     3,     3,     2,     1,     2,     1,     3,     5,     4,
       4,     3,     2,     1,     5,     4,     4,     3,     2,     3,
       3,     2,     1,     2,     1,     1,     1,     2,     3,     2,
       1,     1,     3,     2,     3,     1,     2,     1,     1,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     5,     7,     7,     1,     5,
       5,     1,     1,     1,     1,     6,     7,     7,     8,     7,
       8,     8,     9,     6,     7,     7,     8,     7,     8,     8,
       9,     7,     1,     1,     1,     7,     1,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     5,     3,     3,     4,
       1,     2,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     4,     5,     1,     3,     3,     4,
       4,     3,     4,     4,     1,     2,     3,     2,     3,     3,
       3,     3,     4,     5,     6,     5,     6,     4,     4,     1,
       1,     1,     1,     2,     2,     1,     1,     2,     2,     1,
       2,     2,     1,     2,     2,     1,     4,     5,     4,     5,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 79 "parser.y"
    {   
        root=new Node("Program");
        root->children.push_back(new Node("EOF","EOF",-1));
    }
#line 2692 "parser.tab.c"
    break;

  case 3:
#line 84 "parser.y"
    {
        root=new Node("Program");
        root->isBlock=true; 
        root->children.push_back((yyvsp[0].node));
        root->children.push_back(new Node("EOF","EOF",-1));
    }
#line 2703 "parser.tab.c"
    break;

  case 4:
#line 95 "parser.y"
    {
        (yyval.node)=(yyvsp[0].node);
    }
#line 2711 "parser.tab.c"
    break;

  case 5:
#line 99 "parser.y"
    {
        (yyval.node)=(yyvsp[0].node);
    }
#line 2719 "parser.tab.c"
    break;

  case 6:
#line 104 "parser.y"
               {
                (yyval.node)=(yyvsp[0].node);
               }
#line 2727 "parser.tab.c"
    break;

  case 7:
#line 108 "parser.y"
             {
                (yyval.node) = new Node("boolean","Keyword",yylineno);
                if(!isDot){
                (yyval.node)->type = BOOL;
                t = BOOL;
                }
             }
#line 2739 "parser.tab.c"
    break;

  case 8:
#line 117 "parser.y"
            {
                (yyval.node)=(yyvsp[0].node);
            }
#line 2747 "parser.tab.c"
    break;

  case 9:
#line 121 "parser.y"
            {
                (yyval.node)=(yyvsp[0].node);
            }
#line 2755 "parser.tab.c"
    break;

  case 10:
#line 125 "parser.y"
                    {
                (yyval.node) = new Node("byte","Keyword", INT, yylineno);
                t = INT;
            }
#line 2764 "parser.tab.c"
    break;

  case 11:
#line 129 "parser.y"
                    {
                (yyval.node) = new Node("short","Keyword", INT, yylineno);
                t = INT;
            }
#line 2773 "parser.tab.c"
    break;

  case 12:
#line 133 "parser.y"
                   {
                (yyval.node) = new Node("int","Keyword", INT, yylineno);
                t = INT;
            }
#line 2782 "parser.tab.c"
    break;

  case 13:
#line 137 "parser.y"
                    {
                (yyval.node) = new Node("long","Keyword", LONG, yylineno);
                t = LONG;
            }
#line 2791 "parser.tab.c"
    break;

  case 14:
#line 141 "parser.y"
                    {
                (yyval.node) = new Node("char","Keyword", CHAR, yylineno );
                t = CHAR;
            }
#line 2800 "parser.tab.c"
    break;

  case 15:
#line 146 "parser.y"
                           {
                        (yyval.node) = new Node("float","Keyword", FLOAT, yylineno);
                        t = FLOAT;
                   }
#line 2809 "parser.tab.c"
    break;

  case 16:
#line 151 "parser.y"
                   {
                        (yyval.node) = new Node("double","Keyword", DOUBLE, yylineno);
                        t = DOUBLE;
                   }
#line 2818 "parser.tab.c"
    break;

  case 17:
#line 157 "parser.y"
              {
                (yyval.node)=(yyvsp[0].node);
              }
#line 2826 "parser.tab.c"
    break;

  case 18:
#line 161 "parser.y"
             {
                (yyval.node)=(yyvsp[0].node);
             }
#line 2834 "parser.tab.c"
    break;

  case 19:
#line 165 "parser.y"
                          {
                            (yyval.node)=(yyvsp[0].node);
                          }
#line 2842 "parser.tab.c"
    break;

  case 20:
#line 169 "parser.y"
                               {
                                 (yyval.node)=(yyvsp[0].node);
                               }
#line 2850 "parser.tab.c"
    break;

  case 21:
#line 173 "parser.y"
                                   {
                                    (yyval.node)=(yyvsp[0].node);
                                   }
#line 2858 "parser.tab.c"
    break;

  case 22:
#line 178 "parser.y"
                {
                    (yyval.node)=new Node("ArrayType"); 
                    (yyval.node)->type = (yyvsp[-2].node)->type;
                    (yyval.node)->isArray = true;
                    (yyval.node)->children.push_back((yyvsp[-2].node));
                    (yyval.node)->children.push_back(new Node("[","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node("]","Separator", yylineno));
                    (yyval.node)->isArray = true;
                    (yyval.node)->size++;
                    isarr = true;
                    ++size;
                }
#line 2875 "parser.tab.c"
    break;

  case 23:
#line 191 "parser.y"
                {
                    (yyval.node)=new Node("ArrayType"); 
                    (yyval.node)->isArray = true;
                    if(!isDot){
                        if(!symTables[currentSymTableId].lookup((yyvsp[-2].node)->id)){
                            string s1 = "Undeclared type " + (yyvsp[-2].node)->id;
                            yyerror(s1.c_str());
                            exit(0);
                        }
                    (yyval.node)->type = (*symTables[currentSymTableId].getSymEntry((yyvsp[-2].node)->id))[0].type;
                    }
                    (yyval.node)->children.push_back((yyvsp[-2].node));
                    (yyval.node)->children.push_back(new Node("[","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node("]","Separator", yylineno));
                    (yyval.node)->isArray = true;
                    (yyval.node)->size++;
                    isarr = true;
                    ++size;
                }
#line 2899 "parser.tab.c"
    break;

  case 24:
#line 211 "parser.y"
                {
                    (yyval.node)=new Node("ArrayType"); 
                    (yyval.node)->isArray = true;
                    (yyval.node)->type = (yyvsp[-2].node)->type;
                    (yyval.node)->children.push_back((yyvsp[-2].node));
                    (yyval.node)->children.push_back(new Node("[","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node("]","Separator", yylineno));
                    (yyval.node)->isArray = true;
                    (yyval.node)->size=(yyvsp[-2].node)->size+1;
                    ++size;
                    isarr = true;
                }
#line 2916 "parser.tab.c"
    break;

  case 25:
#line 228 "parser.y"
     {
        (yyval.node)=(yyvsp[0].node);
     }
#line 2924 "parser.tab.c"
    break;

  case 26:
#line 232 "parser.y"
      {
        (yyval.node)=(yyvsp[0].node);
      }
#line 2932 "parser.tab.c"
    break;

  case 27:
#line 237 "parser.y"
            {   
                string lex((yyvsp[0].str));
                if(!isDot){
                    int t1=symTables[currentSymTableId].grand_lookup(lex);
                    if(!t1){
                        string s1 = "Undeclared variable " + lex;
                        yyerror(s1.c_str());
                        exit(0);
                    }
                    (yyval.node) = new Node((yyvsp[0].str),"Identifier",symTables[t1].entries[lex][0].type,yylineno);
                }
                else {
                    (yyval.node) = new Node((yyvsp[0].str),"Identifier",yylineno);
                }
            }
#line 2952 "parser.tab.c"
    break;

  case 28:
#line 254 "parser.y"
                {
                    if(isDot){
                        (yyval.node)=new Node("QualifiedName"); 
                        (yyval.node)->children.push_back((yyvsp[-2].node));
                        (yyval.node)->children.push_back(new Node(".","Separator", yylineno));
                        (yyval.node)->children.push_back(new Node((yyvsp[0].str),"Identifier",yylineno));
                    }
                    else{
                        string s((yyvsp[0].str));
                        s = (yyvsp[-2].node)->id +"."+ s;
                        (yyval.node)=new Node(s.c_str(), "QualifiedName", yylineno);
                    }

                }
#line 2971 "parser.tab.c"
    break;

  case 29:
#line 272 "parser.y"
                {
                    (yyval.node)=new Node("CompilationUnit"); 
                    (yyval.node)->children.push_back((yyvsp[-2].node));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                }
#line 2982 "parser.tab.c"
    break;

  case 30:
#line 279 "parser.y"
                {
                    (yyval.node)=new Node("CompilationUnit"); 
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                }
#line 2992 "parser.tab.c"
    break;

  case 31:
#line 285 "parser.y"
                {
                    (yyval.node)=new Node("CompilationUnit"); 
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                }
#line 3002 "parser.tab.c"
    break;

  case 32:
#line 291 "parser.y"
                {
                    (yyval.node)=(yyvsp[0].node);
                }
#line 3010 "parser.tab.c"
    break;

  case 33:
#line 295 "parser.y"
                {
                    (yyval.node)=new Node("CompilationUnit"); 
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                }
#line 3020 "parser.tab.c"
    break;

  case 34:
#line 301 "parser.y"
                {
                    (yyval.node)=(yyvsp[0].node);
                }
#line 3028 "parser.tab.c"
    break;

  case 35:
#line 306 "parser.y"
                {
                    (yyval.node)=(yyvsp[0].node);
                }
#line 3036 "parser.tab.c"
    break;

  case 36:
#line 311 "parser.y"
                {
                    (yyval.node)=(yyvsp[0].node);
                }
#line 3044 "parser.tab.c"
    break;

  case 37:
#line 315 "parser.y"
                {
                    (yyval.node)=new Node("ImportDeclarations"); 
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                }
#line 3054 "parser.tab.c"
    break;

  case 38:
#line 322 "parser.y"
                {
                    (yyval.node)=(yyvsp[0].node);
                }
#line 3062 "parser.tab.c"
    break;

  case 39:
#line 326 "parser.y"
                {
                    (yyval.node)=new Node("TypeDeclarations"); 
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                }
#line 3072 "parser.tab.c"
    break;

  case 40:
#line 333 "parser.y"
                    {
                        (yyval.node)=new Node("PackageDeclaration"); 
                        (yyval.node)->children.push_back(new Node("package","Keyword", yylineno));
                        (yyval.node)->children.push_back((yyvsp[-1].node));
                        (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
                    }
#line 3083 "parser.tab.c"
    break;

  case 41:
#line 341 "parser.y"
                   {
                    (yyval.node)=(yyvsp[0].node);
                   }
#line 3091 "parser.tab.c"
    break;

  case 42:
#line 345 "parser.y"
                  {
                    (yyval.node)=(yyvsp[0].node);
                  }
#line 3099 "parser.tab.c"
    break;

  case 43:
#line 350 "parser.y"
                             {
                                (yyval.node)=new Node("SingleImportTypeDeclaration"); 
                                (yyval.node)->children.push_back(new Node("import","Keyword", yylineno));
                                (yyval.node)->children.push_back((yyvsp[-1].node));
                                (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
                             }
#line 3110 "parser.tab.c"
    break;

  case 44:
#line 359 "parser.y"
                               {
                                (yyval.node)=new Node("PackageDeclaration"); 
                                (yyval.node)->children.push_back(new Node("import","Keyword", yylineno));
                                (yyval.node)->children.push_back((yyvsp[-3].node));
                                (yyval.node)->children.push_back(new Node(".","Separator", yylineno));
                                (yyval.node)->children.push_back(new Node("*","Operator", yylineno));
                                (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
                               }
#line 3123 "parser.tab.c"
    break;

  case 45:
#line 369 "parser.y"
                {
                    (yyval.node)=(yyvsp[0].node);
                }
#line 3131 "parser.tab.c"
    break;

  case 46:
#line 373 "parser.y"
                {
                    (yyval.node)=(yyvsp[0].node);
                }
#line 3139 "parser.tab.c"
    break;

  case 47:
#line 377 "parser.y"
                {
                (yyval.node) = new Node(";","Separator", yylineno);
                }
#line 3147 "parser.tab.c"
    break;

  case 48:
#line 383 "parser.y"
          {
            (yyval.node) = (yyvsp[0].node);
          }
#line 3155 "parser.tab.c"
    break;

  case 49:
#line 387 "parser.y"
         {
            (yyval.node)=new Node("Modifiers"); 
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
         }
#line 3165 "parser.tab.c"
    break;

  case 50:
#line 394 "parser.y"
          {
            (yyval.node) = new Node("public","Keyword", yylineno);
          }
#line 3173 "parser.tab.c"
    break;

  case 51:
#line 398 "parser.y"
          {
            (yyval.node) = new Node("protected","Keyword", yylineno);
          }
#line 3181 "parser.tab.c"
    break;

  case 52:
#line 402 "parser.y"
          {
            (yyval.node) = new Node("private","Keyword", yylineno);
          }
#line 3189 "parser.tab.c"
    break;

  case 53:
#line 406 "parser.y"
          {
            (yyval.node) = new Node("static","Keyword", yylineno);
          }
#line 3197 "parser.tab.c"
    break;

  case 54:
#line 410 "parser.y"
          {
            (yyval.node) = new Node("abstract","Keyword", yylineno);
          }
#line 3205 "parser.tab.c"
    break;

  case 55:
#line 414 "parser.y"
          {
            (yyval.node) = new Node("final","Keyword", yylineno);
          }
#line 3213 "parser.tab.c"
    break;

  case 56:
#line 418 "parser.y"
          {
            (yyval.node) = new Node("native","Keyword", yylineno);
          }
#line 3221 "parser.tab.c"
    break;

  case 57:
#line 422 "parser.y"
          {
            (yyval.node) = new Node("synchronized","Keyword", yylineno);
          }
#line 3229 "parser.tab.c"
    break;

  case 58:
#line 426 "parser.y"
          {
            (yyval.node) = new Node("transient","Keyword", yylineno);
          }
#line 3237 "parser.tab.c"
    break;

  case 59:
#line 430 "parser.y"
          {
            (yyval.node) = new Node("volatile","Keyword", yylineno);
          }
#line 3245 "parser.tab.c"
    break;

  case 60:
#line 435 "parser.y"
                   {
                    (yyval.node)=(yyvsp[0].node);
                   }
#line 3253 "parser.tab.c"
    break;

  case 61:
#line 439 "parser.y"
                   {
                    (yyval.node)=(yyvsp[0].node);
                   }
#line 3261 "parser.tab.c"
    break;

  case 62:
#line 445 "parser.y"
    {   
        (yyval.node)=new Node("NormalClassDeclaration"); 
        (yyval.node)->children.push_back((yyvsp[-5].node));
        (yyval.node)->children.push_back(new Node("class","Keyword", yylineno));
        (yyval.node)->children.push_back(new Node((yyvsp[-3].str),"Identifier",yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
            string s((yyvsp[-3].str));
            if(symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end()){
                yyerror("Class already declared");
                exit(0);
            }
            else{
                symTables[currentSymTableId].insertSymEntry(s, CLASS, yylineno);
            } 
        }
    }
#line 3285 "parser.tab.c"
    break;

  case 63:
#line 465 "parser.y"
      {   
        (yyval.node)=new Node("NormalClassDeclaration"); 
        string s((yyvsp[-2].str));
        if(!isDot){
            if(symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end()){
                yyerror("Class already declared");
                exit(0);
            }
            else{
                symTables[currentSymTableId].insertSymEntry(s, CLASS, yylineno);
            } 
        }
        (yyval.node)->children.push_back((yyvsp[-4].node));
        (yyval.node)->children.push_back(new Node("class","Keyword", yylineno));
        (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back((yyvsp[0].node));
      }
#line 3308 "parser.tab.c"
    break;

  case 64:
#line 484 "parser.y"
      {   
        (yyval.node)=new Node("NormalClassDeclaration"); 
        string s((yyvsp[-2].str));
        if(!isDot){
            if(symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end()){
                yyerror("Class already declared");
                exit(0);
            }
            else{
                symTables[currentSymTableId].insertSymEntry(s, CLASS, yylineno);
            } 
        }
        (yyval.node)->children.push_back((yyvsp[-4].node));
        (yyval.node)->children.push_back(new Node("class","Keyword", yylineno));
        (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back((yyvsp[0].node));
      }
#line 3331 "parser.tab.c"
    break;

  case 65:
#line 503 "parser.y"
      {   
        (yyval.node)=new Node("NormalClassDeclaration"); 
        string s((yyvsp[-1].str));
        if(!isDot){
            if(symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end()){
                yyerror("Class already declared");
                exit(0);
            }
            else{
                symTables[currentSymTableId].insertSymEntry(s, CLASS, yylineno);
            } 
        }
        (yyval.node)->children.push_back((yyvsp[-3].node));
        (yyval.node)->children.push_back(new Node("class","Keyword", yylineno));
        (yyval.node)->children.push_back(new Node((yyvsp[-1].str),"Identifier",yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
      }
#line 3353 "parser.tab.c"
    break;

  case 66:
#line 521 "parser.y"
      {   
        (yyval.node)=new Node("NormalClassDeclaration"); 
        if(!isDot){
                string s((yyvsp[-3].str));
            if(symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end()){
                yyerror("Class already declared");
                exit(0);
            }
            else{
                symTables[currentSymTableId].insertSymEntry(s, CLASS, yylineno);
            } 
        }
        (yyval.node)->children.push_back(new Node("class","Keyword", yylineno));
        (yyval.node)->children.push_back(new Node((yyvsp[-3].str),"Identifier",yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back((yyvsp[0].node));
      }
#line 3376 "parser.tab.c"
    break;

  case 67:
#line 540 "parser.y"
        {   
            (yyval.node)=new Node("NormalClassDeclaration"); 
            if(!isDot){
            string s((yyvsp[-2].str));
            if(symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end()){
                yyerror("Class already declared");
                exit(0);
            }
            else{
                symTables[currentSymTableId].insertSymEntry(s, CLASS, yylineno);
            } 
        }
            (yyval.node)->children.push_back(new Node("class","Keyword", yylineno));
            (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
        }
#line 3398 "parser.tab.c"
    break;

  case 68:
#line 558 "parser.y"
        {   
            (yyval.node)=new Node("NormalClassDeclaration"); 
            if(!isDot){
            string s((yyvsp[-2].str));
            if(symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end()){
                yyerror("Class already declared");
                exit(0);
            }
            else{
                symTables[currentSymTableId].insertSymEntry(s, CLASS, yylineno);
            } 
        }
            (yyval.node)->children.push_back(new Node("class","Keyword", yylineno));
            (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
        }
#line 3420 "parser.tab.c"
    break;

  case 69:
#line 576 "parser.y"
       {
            (yyval.node)=new Node("NormalClassDeclaration"); 
            if(!isDot){
            string s((yyvsp[-1].str));
            if(symTables[currentSymTableId].entries.find(s) != symTables[currentSymTableId].entries.end()){
                yyerror("Class already declared");
                exit(0);
            }
            else{
                symTables[currentSymTableId].insertSymEntry(s, CLASS, yylineno);
            } 
        }
            (yyval.node)->children.push_back(new Node("class","Keyword", yylineno));
            (yyval.node)->children.push_back(new Node((yyvsp[-1].str),"Identifier",yylineno));
            (yyval.node)->children.push_back((yyvsp[0].node));
       }
#line 3441 "parser.tab.c"
    break;

  case 70:
#line 593 "parser.y"
                                           { 
                    if(!isDot){
                        initializeSymTable();
                    }
                }
#line 3451 "parser.tab.c"
    break;

  case 71:
#line 600 "parser.y"
        {
            (yyval.node)=new Node("Super");
            (yyval.node)->children.push_back(new Node("extends","Keyword", yylineno));
            (yyval.node)->children.push_back((yyvsp[0].node));
        }
#line 3461 "parser.tab.c"
    break;

  case 72:
#line 607 "parser.y"
            {
                (yyval.node)=new Node("Interfaces");
                (yyval.node)->children.push_back(new Node("implements","Keyword", yylineno));
                (yyval.node)->children.push_back((yyvsp[0].node));
            }
#line 3471 "parser.tab.c"
    break;

  case 73:
#line 614 "parser.y"
                    {
                        (yyval.node)=(yyvsp[0].node);
                    }
#line 3479 "parser.tab.c"
    break;

  case 74:
#line 618 "parser.y"
                    {
                        (yyval.node)=new Node("InterfaceTypeList");
                        (yyval.node)->children.push_back((yyvsp[-2].node));
                        (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
                        (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 3490 "parser.tab.c"
    break;

  case 75:
#line 626 "parser.y"
{
    (yyval.node)=new Node("ClassBody");
    (yyval.node)->isBlock=true;
    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
    currentSymTableId = symTables[currentSymTableId].parentID;
}
#line 3503 "parser.tab.c"
    break;

  case 76:
#line 635 "parser.y"
{
    (yyval.node)=new Node("ClassBody");
    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
    //currentSymTableId = symTables[currentSymTableId].parentID;
}
#line 3514 "parser.tab.c"
    break;

  case 77:
#line 643 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3522 "parser.tab.c"
    break;

  case 78:
#line 647 "parser.y"
                        {
                            (yyval.node)=new Node("ClassBodyDeclarations");
                            (yyval.node)->children.push_back((yyvsp[-1].node));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                        }
#line 3532 "parser.tab.c"
    break;

  case 79:
#line 654 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3540 "parser.tab.c"
    break;

  case 80:
#line 658 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3548 "parser.tab.c"
    break;

  case 81:
#line 662 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3556 "parser.tab.c"
    break;

  case 82:
#line 667 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3564 "parser.tab.c"
    break;

  case 83:
#line 671 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3572 "parser.tab.c"
    break;

  case 84:
#line 676 "parser.y"
                        {
                            (yyval.node)=new Node("FieldDeclaration");
                            (yyval.node)->children.push_back((yyvsp[-3].node));
                            (yyval.node)->children.push_back((yyvsp[-2].node));
                            (yyval.node)->children.push_back((yyvsp[-1].node));
                            (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
                            // if(!isDot){
                            //     if($2->type != $3->type){
                            //         if($3->type == VAR){
                            //             symTables[currentSymTableId].insertSymEntry($3->id, $2->type, yylineno);
                            //         }
                            //         cout<<"Type Mismatch in Field Declaration"<<endl;
                            //         exit(0);
                            //     }
                            // }
                            t = VOID;
                        }
#line 3594 "parser.tab.c"
    break;

  case 85:
#line 694 "parser.y"
                        {
                            (yyval.node)=new Node("FieldDeclaration");
                            (yyval.node)->children.push_back((yyvsp[-2].node));
                            (yyval.node)->children.push_back((yyvsp[-1].node));
                            (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
                            // if(!isDot){
                            //     if($1->type != $2->type){
                            //         cout<<"Type Mismatch in Field Declaration"<<endl;
                            //         exit(0);
                            //     }
                            // }
                            t = VOID;
                        }
#line 3612 "parser.tab.c"
    break;

  case 86:
#line 709 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3620 "parser.tab.c"
    break;

  case 87:
#line 713 "parser.y"
                        {
                            (yyval.node)=new Node("VariableDeclaratorList");
                            (yyval.node)->children.push_back((yyvsp[-2].node));
                            (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                            // if(!isDot){
                            //     if($1->type != $3->type){
                            //         cout<<"Type Mismatch in Variable Declarator List"<<endl;
                            //         exit(0);
                            //     }
                            //     $$->type = $1->type;
                            // }
                        }
#line 3638 "parser.tab.c"
    break;

  case 88:
#line 728 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3646 "parser.tab.c"
    break;

  case 89:
#line 732 "parser.y"
                        {
                            if(!isDot){
                                // if(t != $3->type){
                                //     cout<<enum_types[t]<<" "<<enum_types[$3->type]<<endl;
                                //     cout<<"Type Mismatch in Variable Declarator"<<endl;
                                //     exit(0);
                                // }
                                if(isarr){
                                    vector<struct symEntry> *s = symTables[currentSymTableId].getSymEntry((yyvsp[-2].node)->id);
                                    if(!s){
                                        yyerror("Random");
                                        exit(0);
                                    }
                                    for(int i = 0; i < vs.size(); i++){
                                        (*s)[i+1].size = vs[i];
                                    }
                                    vs.clear();
                                }
                                (yyval.node)=new Node((yyvsp[-2].node)->id.c_str(), "VariableDeclarator", yylineno);
                            }
                            else{
                                (yyval.node)=new Node("VariableDeclarator");
                            }
                            (yyval.node)->children.push_back((yyvsp[-2].node));
                            (yyval.node)->children.push_back(new Node("=","Operator", yylineno));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                        }
#line 3678 "parser.tab.c"
    break;

  case 90:
#line 761 "parser.y"
                      {
                        (yyval.node) = new Node((yyvsp[0].str),"Identifier",yylineno);
                        if(!isDot){
                            string s((yyvsp[0].str));
                            if(symTables[currentSymTableId].lookup(s)){
                                cout<<"Variable "<<s<<" already declared in this scope"<<endl;
                                exit(0);
                            }
                            symTables[currentSymTableId].insertSymEntry(s, t, yylineno);
                            for(int i=0;i<size;i++){
                                symTables[currentSymTableId].insertSymEntry(s, t, yylineno);
                            }
                            //cout<<enum_types[t]<<endl;
                        }
                      }
#line 3698 "parser.tab.c"
    break;

  case 91:
#line 777 "parser.y"
                        {
                            (yyval.node)=new Node("VariableDeclaratorId");
                            (yyval.node)->children.push_back((yyvsp[-2].node));
                            (yyval.node)->children.push_back(new Node("[","Separator", yylineno));
                            (yyval.node)->children.push_back(new Node("]","Separator", yylineno));
                            if(!isDot){
                                string s((yyvsp[-2].node)->id);
                                if(!symTables[currentSymTableId].lookup(s)){
                                    cout<<"Variable "<<s<<" already declared in this scope"<<endl;
                                    exit(0);
                                }
                                symTables[currentSymTableId].insertSymEntry(s, t, yylineno);
                            }
                        }
#line 3717 "parser.tab.c"
    break;

  case 92:
#line 793 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3725 "parser.tab.c"
    break;

  case 93:
#line 797 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3733 "parser.tab.c"
    break;

  case 94:
#line 802 "parser.y"
                        {
                            (yyval.node)=new Node("MethodDeclaration");
                            (yyval.node)->isBlock = true;
                            (yyval.node)->children.push_back((yyvsp[-1].node));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                            if(!isDot){
                                currentSymTableId = symTables[currentSymTableId].parentID;
                                //symTables[currentSymTableId].insertSymEntry($1->id.c_str(), $1->type, yylineno);
                                for(int i=0;i<vt.size();i++){
                                    symTables[currentSymTableId].insertSymEntry((yyvsp[-1].node)->id.c_str(), vt[i], yylineno);
                                }
                                vt.clear();
                            }
                        }
#line 3752 "parser.tab.c"
    break;

  case 95:
#line 818 "parser.y"
                                                  {   
            (yyval.node)=new Node((yyvsp[-1].node)->id.c_str(),"MethodHeader",yylineno); 
            (yyval.node)->children.push_back((yyvsp[-3].node));
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            t = (yyvsp[-2].node)->type;
        }
#line 3765 "parser.tab.c"
    break;

  case 96:
#line 826 "parser.y"
                                      {   
            (yyval.node)=new Node((yyvsp[0].node)->id.c_str(),"MethodHeader",yylineno); 
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            t = (yyvsp[-1].node)->type;
        }
#line 3777 "parser.tab.c"
    break;

  case 97:
#line 833 "parser.y"
                                    {   
            (yyval.node)=new Node((yyvsp[-1].node)->id.c_str(),"MethodHeader",yylineno); 
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            t = (yyvsp[-2].node)->type;
        }
#line 3789 "parser.tab.c"
    break;

  case 98:
#line 840 "parser.y"
                                {   
            (yyval.node)=new Node((yyvsp[0].node)->id.c_str(),"MethodHeader",yylineno); 
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            t = (yyvsp[-1].node)->type;
        }
#line 3800 "parser.tab.c"
    break;

  case 99:
#line 846 "parser.y"
                                                    {   
            (yyval.node)=new Node((yyvsp[-1].node)->id.c_str(),"MethodHeader",yylineno);
            (yyval.node)->children.push_back((yyvsp[-3].node));
            (yyval.node)->children.push_back(new Node("void","Keyword", yylineno));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            t=VOID;
        }
#line 3813 "parser.tab.c"
    break;

  case 100:
#line 854 "parser.y"
                                        {   
            (yyval.node)=new Node((yyvsp[0].node)->id.c_str(),"MethodHeader",yylineno); 
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back(new Node("void","Keyword", yylineno));
            (yyval.node)->children.push_back((yyvsp[0].node));
            t=VOID;
        }
#line 3825 "parser.tab.c"
    break;

  case 101:
#line 861 "parser.y"
                                      {   
            (yyval.node)=new Node((yyvsp[-1].node)->id.c_str(),"MethodHeader",yylineno);
            (yyval.node)->children.push_back(new Node("void","Keyword", yylineno));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            t=VOID;
        }
#line 3837 "parser.tab.c"
    break;

  case 102:
#line 868 "parser.y"
                               {   
            (yyval.node)=new Node((yyvsp[0].node)->id.c_str(),"MethodHeader",yylineno);
            (yyval.node)->children.push_back(new Node("void","Keyword", yylineno));
            (yyval.node)->children.push_back((yyvsp[0].node));
            t=VOID;
        }
#line 3848 "parser.tab.c"
    break;

  case 103:
#line 874 "parser.y"
                            {
        if(!isDot){
            vt.push_back(t);
            initializeSymTable();
        }
}
#line 3859 "parser.tab.c"
    break;

  case 104:
#line 881 "parser.y"
                                                                  {   
            (yyval.node)=new Node((yyvsp[-3].str),"MethodDeclarator",yylineno); 
            (yyval.node)->children.push_back(new Node((yyvsp[-3].str),"Identifier",yylineno));
            (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
            if(!isDot){
                //currentSymTableId = symTables[currentSymTableId].parentID;
                //symTables[currentSymTableId].insertSymEntry($1->id.c_str(), vt[0], yylineno);
                for(int i=0;i<vt.size();i++){
                    symTables[currentSymTableId].insertSymEntry((yyvsp[-3].str), vt[i], yylineno);
                }
            }
        }
#line 3878 "parser.tab.c"
    break;

  case 105:
#line 895 "parser.y"
                                            {   
            (yyval.node)=new Node((yyvsp[-2].str),"MethodDeclarator",yylineno); 
            (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
            (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
            (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
            if(!isDot){
                //currentSymTableId = symTables[currentSymTableId].parentID;
                //symTables[currentSymTableId].insertSymEntry($1->id.c_str(), $1->type, yylineno);
                for(int i=0;i<vt.size();i++){
                    symTables[currentSymTableId].insertSymEntry((yyvsp[-2].str), vt[i], yylineno);
                }
            }
        }
#line 3896 "parser.tab.c"
    break;

  case 106:
#line 908 "parser.y"
                                                                        {   
            (yyval.node)=new Node((yyvsp[-2].node)->id.c_str(),"MethodDeclarator",yylineno); 
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back(new Node("[","Separator", yylineno));
            (yyval.node)->children.push_back(new Node("]","Separator", yylineno));
            if(!isDot){
                //currentSymTableId = symTables[currentSymTableId].parentID;
                //symTables[currentSymTableId].insertSymEntry($1->id.c_str(), $1->type, yylineno);
                for(int i=0;i<vt.size();i++){
                    symTables[currentSymTableId].insertSymEntry((yyvsp[-2].node)->id.c_str(), vt[i], yylineno);
                }
            }
        }
#line 3914 "parser.tab.c"
    break;

  case 107:
#line 923 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3922 "parser.tab.c"
    break;

  case 108:
#line 927 "parser.y"
                        {
                            (yyval.node)=new Node("FormalParameterList");
                            (yyval.node)->children.push_back((yyvsp[-2].node));
                            (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                        }
#line 3933 "parser.tab.c"
    break;

  case 109:
#line 935 "parser.y"
                        {
                            (yyval.node)=new Node("FormalParameter");
                            (yyval.node)->children.push_back((yyvsp[-1].node));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                            vt.push_back(t);
                            t=VOID;
                        }
#line 3945 "parser.tab.c"
    break;

  case 110:
#line 943 "parser.y"
                        {
                            (yyval.node)=new Node("FormalParameter");
                            (yyval.node)->children.push_back(new Node("final","Keyword", yylineno));
                            (yyval.node)->children.push_back((yyvsp[-1].node));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                            vt.push_back(t);
                            t=VOID;
                        }
#line 3958 "parser.tab.c"
    break;

  case 111:
#line 953 "parser.y"
                        {
                            (yyval.node)=new Node("Throws");
                            (yyval.node)->children.push_back(new Node("throws","Keyword", yylineno));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                        }
#line 3968 "parser.tab.c"
    break;

  case 112:
#line 960 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3976 "parser.tab.c"
    break;

  case 113:
#line 964 "parser.y"
                        {
                            (yyval.node)=new Node("ClassTypeList");
                            (yyval.node)->children.push_back((yyvsp[-2].node));
                            (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                        }
#line 3987 "parser.tab.c"
    break;

  case 114:
#line 972 "parser.y"
                {
                    (yyval.node)=(yyvsp[0].node);
                }
#line 3995 "parser.tab.c"
    break;

  case 115:
#line 977 "parser.y"
    {
        (yyval.node) = new Node(";","Separator", yylineno);
    }
#line 4003 "parser.tab.c"
    break;

  case 116:
#line 982 "parser.y"
                        {
                            (yyval.node)=new Node("StaticInitializer");
                            (yyval.node)->children.push_back(new Node("static","Keyword", yylineno));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                        }
#line 4013 "parser.tab.c"
    break;

  case 117:
#line 991 "parser.y"
                                                               {  
            (yyval.node)=new Node("ConstructorDeclaration"); 
            (yyval.node)->children.push_back((yyvsp[-3].node));
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            }
#line 4025 "parser.tab.c"
    break;

  case 118:
#line 998 "parser.y"
                                                          {  
            (yyval.node)=new Node("ConstructorDeclaration"); 
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            }
#line 4036 "parser.tab.c"
    break;

  case 119:
#line 1004 "parser.y"
                                                       {  
            (yyval.node)=new Node("ConstructorDeclaration"); 
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            }
#line 4047 "parser.tab.c"
    break;

  case 120:
#line 1010 "parser.y"
                                                {  
            (yyval.node)=new Node("ConstructorDeclaration"); 
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            }
#line 4057 "parser.tab.c"
    break;

  case 121:
#line 1019 "parser.y"
            {  
            (yyval.node)=new Node("ConstructorDeclarator"); 
            (yyval.node)->children.push_back((yyvsp[-3].node));
            (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
            }
#line 4069 "parser.tab.c"
    break;

  case 122:
#line 1026 "parser.y"
                                               {  
            (yyval.node)=new Node("ConstructorDeclarator"); 
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
            (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
            }
#line 4080 "parser.tab.c"
    break;

  case 123:
#line 1035 "parser.y"
                                                   {  
            (yyval.node)=new Node("ConstructorBody"); 
            (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
            (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
            }
#line 4090 "parser.tab.c"
    break;

  case 124:
#line 1040 "parser.y"
                                                                     {  
            (yyval.node)=new Node("ConstructorBody"); 
            (yyval.node)->isBlock = true;
            (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
            }
#line 4102 "parser.tab.c"
    break;

  case 125:
#line 1047 "parser.y"
                                                                                   {  
            (yyval.node)=new Node("ConstructorBody"); 
            (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
            }
#line 4113 "parser.tab.c"
    break;

  case 126:
#line 1053 "parser.y"
                                                                                                   {  
            (yyval.node)=new Node("ConstructorBody"); 
            (yyval.node)->isBlock = true;
            (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
            }
#line 4126 "parser.tab.c"
    break;

  case 127:
#line 1064 "parser.y"
                                                                   {  
            (yyval.node)=new Node("ExplicitConstructorInvocation"); 
            (yyval.node)->children.push_back(new Node("this","Keyword", yylineno));
            (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
            (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
            }
#line 4139 "parser.tab.c"
    break;

  case 128:
#line 1072 "parser.y"
                                                        {  
            (yyval.node)=new Node("ExplicitConstructorInvocation"); 
            (yyval.node)->children.push_back(new Node("this","Keyword", yylineno));
            (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
            (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
            (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
            }
#line 4151 "parser.tab.c"
    break;

  case 129:
#line 1079 "parser.y"
                                                                      {  
            (yyval.node)=new Node("ExplicitConstructorInvocation"); 
            (yyval.node)->children.push_back(new Node("super","Keyword", yylineno));
            (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
            (yyval.node)->children.push_back(new Node(";","Separator", yylineno));}
#line 4163 "parser.tab.c"
    break;

  case 130:
#line 1086 "parser.y"
                                                         {  
            (yyval.node)=new Node("ExplicitConstructorInvocation"); 
            (yyval.node)->children.push_back(new Node("super","Keyword", yylineno));
            (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
            (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
            (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
            }
#line 4175 "parser.tab.c"
    break;

  case 131:
#line 1095 "parser.y"
                                                                       {  
                    (yyval.node)=new Node("EnumDeclaration"); 
                    (yyval.node)->children.push_back((yyvsp[-4].node));
                    (yyval.node)->children.push_back(new Node("enum","Keyword", yylineno));
                    (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4188 "parser.tab.c"
    break;

  case 132:
#line 1103 "parser.y"
                                                       {  
                    (yyval.node)=new Node("EnumDeclaration"); 
                    (yyval.node)->children.push_back((yyvsp[-3].node));
                    (yyval.node)->children.push_back(new Node("enum","Keyword", yylineno));
                    (yyval.node)->children.push_back(new Node((yyvsp[-1].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4200 "parser.tab.c"
    break;

  case 133:
#line 1110 "parser.y"
                                                             {  
                    (yyval.node)=new Node("EnumDeclaration"); 
                    (yyval.node)->children.push_back(new Node("enum","Keyword", yylineno));
                    (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4212 "parser.tab.c"
    break;

  case 134:
#line 1117 "parser.y"
                                             {  
                    (yyval.node)=new Node("EnumDeclaration"); 
                    (yyval.node)->children.push_back(new Node("enum","Keyword", yylineno));
                    (yyval.node)->children.push_back(new Node((yyvsp[-1].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4223 "parser.tab.c"
    break;

  case 135:
#line 1124 "parser.y"
                                                 {  
                    (yyval.node)=new Node("ClassImplements"); 
                    (yyval.node)->children.push_back(new Node("implements","Keyword", yylineno));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4233 "parser.tab.c"
    break;

  case 136:
#line 1130 "parser.y"
                                                                                                    {  
                    (yyval.node)=new Node("EnumBody"); 
                    (yyval.node)->isBlock = true;
                    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-3].node));
                    (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
                    }
#line 4247 "parser.tab.c"
    break;

  case 137:
#line 1139 "parser.y"
                                                                                {  
                    (yyval.node)=new Node("EnumBody"); 
                    (yyval.node)->isBlock = true;
                    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-2].node));
                    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
                    }
#line 4259 "parser.tab.c"
    break;

  case 138:
#line 1146 "parser.y"
                                                                                            {  
                    (yyval.node)=new Node("EnumBody");
                    (yyval.node)->isBlock=true; 
                    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-2].node));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
                    }
#line 4272 "parser.tab.c"
    break;

  case 139:
#line 1154 "parser.y"
                                                                       {  
                    (yyval.node)=new Node("EnumBody");
                    (yyval.node)->isBlock=true; 
                    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
                    }
#line 4284 "parser.tab.c"
    break;

  case 140:
#line 1161 "parser.y"
                                                                                   {  
                    (yyval.node)=new Node("EnumBody");
                    (yyval.node)->isBlock=true; 
                    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
                    }
#line 4297 "parser.tab.c"
    break;

  case 141:
#line 1169 "parser.y"
                                                              {  
                    (yyval.node)=new Node("EnumBody");
                    (yyval.node)->isBlock=true; 
                    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
                    }
#line 4309 "parser.tab.c"
    break;

  case 142:
#line 1176 "parser.y"
                                                                           {  
                    (yyval.node)=new Node("EnumBody");
                    (yyval.node)->isBlock=true; 
                    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
                    }
#line 4321 "parser.tab.c"
    break;

  case 143:
#line 1183 "parser.y"
                                                      {  
                    (yyval.node)=new Node("EnumBody");
                    (yyval.node)->isBlock=true; 
                    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
                    }
#line 4332 "parser.tab.c"
    break;

  case 144:
#line 1190 "parser.y"
                                    {  
                    (yyval.node)=new Node(";","Separator", yylineno);
                    }
#line 4340 "parser.tab.c"
    break;

  case 145:
#line 1193 "parser.y"
                                                        {  
                    (yyval.node)=new Node("EnumBodyDeclarations"); 
                    (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4350 "parser.tab.c"
    break;

  case 146:
#line 1199 "parser.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 4356 "parser.tab.c"
    break;

  case 147:
#line 1201 "parser.y"
                    {
                    (yyval.node)=new Node("EnumConstantList");
                    (yyval.node)->children.push_back((yyvsp[-2].node));
                    (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4367 "parser.tab.c"
    break;

  case 148:
#line 1208 "parser.y"
                                                                            {  
                    (yyval.node)=new Node("EnumConstant"); 
                    (yyval.node)->children.push_back(new Node((yyvsp[-4].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-2].node));
                    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4380 "parser.tab.c"
    break;

  case 149:
#line 1216 "parser.y"
                                                                   {  
                    (yyval.node)=new Node("EnumConstant"); 
                    (yyval.node)->children.push_back(new Node((yyvsp[-3].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4392 "parser.tab.c"
    break;

  case 150:
#line 1223 "parser.y"
                                                                      {  
                    (yyval.node)=new Node("EnumConstant"); 
                    (yyval.node)->children.push_back(new Node((yyvsp[-3].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
                    }
#line 4404 "parser.tab.c"
    break;

  case 151:
#line 1230 "parser.y"
                                                         {  
                    (yyval.node)=new Node("EnumConstant"); 
                    (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
                    }
#line 4415 "parser.tab.c"
    break;

  case 152:
#line 1236 "parser.y"
                                        {  
                    (yyval.node)=new Node("EnumConstant"); 
                    (yyval.node)->children.push_back(new Node((yyvsp[-1].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4425 "parser.tab.c"
    break;

  case 153:
#line 1241 "parser.y"
                              {  
                    (yyval.node)=new Node((yyvsp[0].str),"Identifier",yylineno);
                    }
#line 4433 "parser.tab.c"
    break;

  case 154:
#line 1248 "parser.y"
    { (yyval.node)=new Node("InterfaceDeclaration"); 
      (yyval.node)->children.push_back((yyvsp[-4].node));
      (yyval.node)->children.push_back(new Node("interface","Keyword", yylineno));
      (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
      (yyval.node)->children.push_back((yyvsp[-1].node));
      (yyval.node)->children.push_back((yyvsp[0].node));}
#line 4444 "parser.tab.c"
    break;

  case 155:
#line 1255 "parser.y"
    { (yyval.node)=new Node("InterfaceDeclaration"); 
      (yyval.node)->children.push_back((yyvsp[-3].node));
      (yyval.node)->children.push_back(new Node("interface","Keyword", yylineno));
      (yyval.node)->children.push_back(new Node((yyvsp[-1].str),"Identifier",yylineno));
      (yyval.node)->children.push_back((yyvsp[0].node));}
#line 4454 "parser.tab.c"
    break;

  case 156:
#line 1261 "parser.y"
    {
        (yyval.node)=new Node("InterfaceDeclaration"); 
        (yyval.node)->children.push_back(new Node("interface","Keyword", yylineno));
        (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4466 "parser.tab.c"
    break;

  case 157:
#line 1269 "parser.y"
    {
        (yyval.node)=new Node("InterfaceDeclaration"); 
        (yyval.node)->children.push_back(new Node("interface","Keyword", yylineno));
        (yyval.node)->children.push_back(new Node((yyvsp[-1].str),"Identifier",yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4477 "parser.tab.c"
    break;

  case 158:
#line 1279 "parser.y"
    {
        (yyval.node)=new Node("ExtendsInterfaces");
        (yyval.node)->children.push_back(new Node("extends","Keyword", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4487 "parser.tab.c"
    break;

  case 159:
#line 1285 "parser.y"
    {
        (yyval.node)=new Node("ExtendsInterfaces");
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node("comma","Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4498 "parser.tab.c"
    break;

  case 160:
#line 1295 "parser.y"
    {
        (yyval.node)=new Node("InterfaceBody");
        (yyval.node)->isBlock=true;
        (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
    }
#line 4510 "parser.tab.c"
    break;

  case 161:
#line 1303 "parser.y"
    {
        (yyval.node)=new Node("InterfaceBody");
        (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
        (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
    }
#line 4520 "parser.tab.c"
    break;

  case 162:
#line 1311 "parser.y"
{ (yyval.node)=new Node("InterfaceMemberDeclarations"); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 4526 "parser.tab.c"
    break;

  case 163:
#line 1313 "parser.y"
    { (yyval.node)=new Node("InterfaceMemberDeclarations"); (yyval.node)->children.push_back((yyvsp[-1].node)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 4532 "parser.tab.c"
    break;

  case 164:
#line 1317 "parser.y"
{
    (yyval.node)=new Node("InterfaceMemberDeclaration");
    (yyval.node)->children.push_back((yyvsp[0].node));
}
#line 4541 "parser.tab.c"
    break;

  case 165:
#line 1322 "parser.y"
    {
        (yyval.node)=new Node("InterfaceMemberDeclaration");
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4550 "parser.tab.c"
    break;

  case 166:
#line 1329 "parser.y"
{
    (yyval.node)=new Node("ConstantDeclaration");
    (yyval.node)->children.push_back((yyvsp[0].node));
}
#line 4559 "parser.tab.c"
    break;

  case 167:
#line 1336 "parser.y"
{
    (yyval.node)=new Node("AbstractMethodDeclaration");
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
}
#line 4569 "parser.tab.c"
    break;

  case 168:
#line 1356 "parser.y"
    {
        (yyval.node)=new Node("ArrayInitializer");
        (yyval.node)->isBlock=true;
        (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
        if(!isDot){
            if(vs[ArrayArgumentDepth-1] && vs[ArrayArgumentDepth-1] != (yyvsp[-1].node)->size){
                yyerror("Error in number of arguments for array");
                exit(0);
            }
            vs[ArrayArgumentDepth-1] = (yyvsp[-1].node)->size;
            ArrayArgumentDepth--;
        }
    }
#line 4589 "parser.tab.c"
    break;

  case 169:
#line 1379 "parser.y"
    {
        (yyval.node)=new Node("ArrayInitializer");
        (yyval.node)->isBlock=true;
        (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
        (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
        (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
        if(!isDot){
            if(vs[ArrayArgumentDepth-1]){
                yyerror("Error in number of arguments for array");
                exit(0);
            }
            vs[ArrayArgumentDepth-1] = 0;
            ArrayArgumentDepth--;
        }
    }
#line 4609 "parser.tab.c"
    break;

  case 170:
#line 1395 "parser.y"
                                                 {
    if(!isDot){
        ArrayArgumentDepth++;
        if(ArrayArgumentDepth > size){
            yyerror("Excess Dimensions used");
            exit(0);
        }
        if(ArrayArgumentDepth > vs.size())
            vs.push_back(0);
    }
}
#line 4625 "parser.tab.c"
    break;

  case 171:
#line 1407 "parser.y"
{
    (yyval.node) = (yyvsp[0].node);
    (yyval.node)->size = 1;
}
#line 4634 "parser.tab.c"
    break;

  case 172:
#line 1412 "parser.y"
    {
        (yyval.node)=new Node("VariableInitializerList");
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        (yyval.node)->size = (yyvsp[-2].node)->size + 1;
    }
#line 4646 "parser.tab.c"
    break;

  case 173:
#line 1425 "parser.y"
    {
        (yyval.node)=new Node("Block");
        (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
        (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
    }
#line 4656 "parser.tab.c"
    break;

  case 174:
#line 1431 "parser.y"
    {
        (yyval.node)=new Node("Block");
        (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
    }
#line 4667 "parser.tab.c"
    break;

  case 175:
#line 1441 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 4675 "parser.tab.c"
    break;

  case 176:
#line 1445 "parser.y"
    {
        (yyval.node)=new Node("BlockStatements");
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4685 "parser.tab.c"
    break;

  case 177:
#line 1454 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 4693 "parser.tab.c"
    break;

  case 178:
#line 1458 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 4701 "parser.tab.c"
    break;

  case 179:
#line 1464 "parser.y"
    {
        (yyval.node) = new Node("LocalVariableDeclarationStatement");
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        isarr=false;
        size=0;
        ArrayArgumentDepth = 0;
    }
#line 4714 "parser.tab.c"
    break;

  case 180:
#line 1476 "parser.y"
    {
        (yyval.node)=new Node("LocalVariableDeclaration");
        (yyval.node)->children.push_back(new Node("final","Keyword", yylineno));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4725 "parser.tab.c"
    break;

  case 181:
#line 1483 "parser.y"
    {
        (yyval.node)=new Node("LocalVariableDeclaration");
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4735 "parser.tab.c"
    break;

  case 182:
#line 1492 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 4743 "parser.tab.c"
    break;

  case 183:
#line 1496 "parser.y"
    {
        (yyval.node) = new Node("var", "Keyword", VAR);
    }
#line 4751 "parser.tab.c"
    break;

  case 184:
#line 1502 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4757 "parser.tab.c"
    break;

  case 185:
#line 1504 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4763 "parser.tab.c"
    break;

  case 186:
#line 1506 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4769 "parser.tab.c"
    break;

  case 187:
#line 1508 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4775 "parser.tab.c"
    break;

  case 188:
#line 1510 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4781 "parser.tab.c"
    break;

  case 189:
#line 1512 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4787 "parser.tab.c"
    break;

  case 190:
#line 1517 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4793 "parser.tab.c"
    break;

  case 191:
#line 1519 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4799 "parser.tab.c"
    break;

  case 192:
#line 1521 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4805 "parser.tab.c"
    break;

  case 193:
#line 1523 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4811 "parser.tab.c"
    break;

  case 194:
#line 1525 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4817 "parser.tab.c"
    break;

  case 195:
#line 1530 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4823 "parser.tab.c"
    break;

  case 196:
#line 1532 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4829 "parser.tab.c"
    break;

  case 197:
#line 1534 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4835 "parser.tab.c"
    break;

  case 198:
#line 1536 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4841 "parser.tab.c"
    break;

  case 199:
#line 1538 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4847 "parser.tab.c"
    break;

  case 200:
#line 1540 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4853 "parser.tab.c"
    break;

  case 201:
#line 1542 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4859 "parser.tab.c"
    break;

  case 202:
#line 1544 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4865 "parser.tab.c"
    break;

  case 203:
#line 1546 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4871 "parser.tab.c"
    break;

  case 204:
#line 1551 "parser.y"
    {(yyval.node) = new Node(";", "Separator", yylineno);}
#line 4877 "parser.tab.c"
    break;

  case 205:
#line 1557 "parser.y"
    {
        (yyval.node) = new Node("LabeledStatement");
        (yyval.node)->children.push_back(new Node((yyvsp[-2].str), "Identifier",yylineno));
        (yyval.node)->children.push_back(new Node(":", "Operator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4888 "parser.tab.c"
    break;

  case 206:
#line 1568 "parser.y"
    {
        (yyval.node) = new Node("LabeledStatementNoShortIf");
        (yyval.node)->children.push_back(new Node((yyvsp[-2].str), "Identifier",yylineno));
        (yyval.node)->children.push_back(new Node(":", "Operator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4899 "parser.tab.c"
    break;

  case 207:
#line 1578 "parser.y"
    {
        (yyval.node) = new Node("ExpressionStatement");
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
    }
#line 4909 "parser.tab.c"
    break;

  case 208:
#line 1588 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 4915 "parser.tab.c"
    break;

  case 209:
#line 1590 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 4921 "parser.tab.c"
    break;

  case 210:
#line 1592 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 4927 "parser.tab.c"
    break;

  case 211:
#line 1594 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 4933 "parser.tab.c"
    break;

  case 212:
#line 1596 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 4939 "parser.tab.c"
    break;

  case 213:
#line 1598 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 4945 "parser.tab.c"
    break;

  case 214:
#line 1600 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 4951 "parser.tab.c"
    break;

  case 215:
#line 1605 "parser.y"
    {
        (yyval.node) = new Node("IfThenStatement");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("if", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
            currentSymTableId=symTables[currentSymTableId].parentID;  
        }
    }
#line 4968 "parser.tab.c"
    break;

  case 216:
#line 1622 "parser.y"
    {
        (yyval.node) = new Node("IfThenElseStatement");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("if", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-4].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node("else", "Keyword", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4984 "parser.tab.c"
    break;

  case 217:
#line 1637 "parser.y"
    {
        (yyval.node) = new Node("IfThenElseStatementNoShortIf");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("if", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-4].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node("else", "Keyword", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 5000 "parser.tab.c"
    break;

  case 218:
#line 1650 "parser.y"
                            {
    if(!isDot)
    initializeSymTable();
}
#line 5009 "parser.tab.c"
    break;

  case 219:
#line 1657 "parser.y"
    {
        (yyval.node) = new Node("WhileStatement");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("while", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot)
        currentSymTableId = symTables[currentSymTableId].parentID;
    }
#line 5025 "parser.tab.c"
    break;

  case 220:
#line 1672 "parser.y"
    {
        (yyval.node) = new Node("WhileStatementNoShortIf");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("while", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot)
        currentSymTableId = symTables[currentSymTableId].parentID;
    }
#line 5041 "parser.tab.c"
    break;

  case 221:
#line 1686 "parser.y"
                                 {(yyval.node)=(yyvsp[0].node);}
#line 5047 "parser.tab.c"
    break;

  case 222:
#line 1686 "parser.y"
                                                                {(yyval.node)=(yyvsp[0].node);}
#line 5053 "parser.tab.c"
    break;

  case 223:
#line 1687 "parser.y"
                                                   {(yyval.node)=(yyvsp[0].node);}
#line 5059 "parser.tab.c"
    break;

  case 224:
#line 1687 "parser.y"
                                                                                           {(yyval.node)=(yyvsp[0].node);}
#line 5065 "parser.tab.c"
    break;

  case 225:
#line 1691 "parser.y"
    {
        (yyval.node) = new Node("BasicForStatement");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
#line 5083 "parser.tab.c"
    break;

  case 226:
#line 1705 "parser.y"
    {
        (yyval.node) = new Node("BasicForStatement");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
#line 5102 "parser.tab.c"
    break;

  case 227:
#line 1720 "parser.y"
    {
        (yyval.node) = new Node("BasicForStatement");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-3].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
#line 5121 "parser.tab.c"
    break;

  case 228:
#line 1735 "parser.y"
    {
        (yyval.node) = new Node("BasicForStatement");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-4].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
#line 5141 "parser.tab.c"
    break;

  case 229:
#line 1751 "parser.y"
    {
        (yyval.node) = new Node("BasicForStatement");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-4].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
#line 5160 "parser.tab.c"
    break;

  case 230:
#line 1766 "parser.y"
    {
        (yyval.node) = new Node("BasicForStatement");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-5].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
#line 5180 "parser.tab.c"
    break;

  case 231:
#line 1782 "parser.y"
    {
        (yyval.node) = new Node("BasicForStatement");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-5].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-3].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
#line 5200 "parser.tab.c"
    break;

  case 232:
#line 1798 "parser.y"
    {
        (yyval.node) = new Node("BasicForStatement");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-6].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-4].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
#line 5221 "parser.tab.c"
    break;

  case 233:
#line 1819 "parser.y"
     {
        (yyval.node) = new Node("BasicForStatementNoShortIf");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
     }
#line 5239 "parser.tab.c"
    break;

  case 234:
#line 1833 "parser.y"
    {
        (yyval.node) = new Node("BasicForStatementNoShortIf");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
#line 5258 "parser.tab.c"
    break;

  case 235:
#line 1848 "parser.y"
    {
        (yyval.node) = new Node("BasicForStatementNoShortIf");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-3].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
#line 5277 "parser.tab.c"
    break;

  case 236:
#line 1863 "parser.y"
    {
        (yyval.node) = new Node("BasicForStatementNoShortIf");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-4].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
#line 5297 "parser.tab.c"
    break;

  case 237:
#line 1879 "parser.y"
    {
        (yyval.node) = new Node("BasicForStatementNoShortIf");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-4].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
            currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
#line 5316 "parser.tab.c"
    break;

  case 238:
#line 1894 "parser.y"
    {
        (yyval.node) = new Node("BasicForStatementNoShortIf");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-5].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
#line 5336 "parser.tab.c"
    break;

  case 239:
#line 1910 "parser.y"
    {
        (yyval.node) = new Node("BasicForStatementNoShortIf");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-5].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-3].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
#line 5356 "parser.tab.c"
    break;

  case 240:
#line 1926 "parser.y"
    {
        (yyval.node) = new Node("BasicForStatementNoShortIf");
        (yyval.node)->isBlock = true;
        (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-6].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-4].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
        if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
    }
#line 5377 "parser.tab.c"
    break;

  case 241:
#line 1945 "parser.y"
{
    (yyval.node) = new Node("EnhancedForStatementNoShortIf");
    (yyval.node)->isBlock = true;
    (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
    (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-4].node));
    (yyval.node)->children.push_back(new Node(":", "Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    if(!isDot){
        currentSymTableId = symTables[currentSymTableId].parentID;
        }
}
#line 5396 "parser.tab.c"
    break;

  case 242:
#line 1962 "parser.y"
    {
       (yyval.node) = (yyvsp[0].node);
    }
#line 5404 "parser.tab.c"
    break;

  case 243:
#line 1966 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 5412 "parser.tab.c"
    break;

  case 244:
#line 1973 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 5420 "parser.tab.c"
    break;

  case 245:
#line 1979 "parser.y"
{
    (yyval.node) = new Node("EnhancedForStatement");
    (yyval.node)->isBlock = true;
    (yyval.node)->children.push_back(new Node("for", "Keyword", yylineno));
    (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-4].node));
    (yyval.node)->children.push_back(new Node(":", "Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
}
#line 5436 "parser.tab.c"
    break;

  case 246:
#line 1991 "parser.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 5442 "parser.tab.c"
    break;

  case 247:
#line 1993 "parser.y"
                       {
                            (yyval.node) = new Node("StatementExpressionList");
                            (yyval.node)->children.push_back((yyvsp[-2].node));
                            (yyval.node)->children.push_back(new Node(",", "Separator", yylineno));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                       }
#line 5453 "parser.tab.c"
    break;

  case 248:
#line 2001 "parser.y"
{ 
    (yyval.node) = new Node("BreakStatement");
    (yyval.node)->children.push_back(new Node("break", "Keyword", yylineno));
    (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));}
#line 5462 "parser.tab.c"
    break;

  case 249:
#line 2006 "parser.y"
 {
    (yyval.node) = new Node("BreakStatement");
    (yyval.node)->children.push_back(new Node("break", "Keyword", yylineno));
    (yyval.node)->children.push_back(new Node((yyvsp[0].str), "Identifier",yylineno));
    (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));}
#line 5472 "parser.tab.c"
    break;

  case 250:
#line 2013 "parser.y"
    {
        (yyval.node) = new Node("ContinueStatement");
        (yyval.node)->children.push_back(new Node("continue", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
    }
#line 5482 "parser.tab.c"
    break;

  case 251:
#line 2019 "parser.y"
 {
    (yyval.node) = new Node("ContinueStatement");
    (yyval.node)->children.push_back(new Node("continue", "Keyword", yylineno));
    (yyval.node)->children.push_back(new Node((yyvsp[-1].str), "Identifier",yylineno));
    (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
 }
#line 5493 "parser.tab.c"
    break;

  case 252:
#line 2027 "parser.y"
{
    (yyval.node) = new Node("ReturnStatement");
    (yyval.node)->children.push_back(new Node("return", "Keyword", yylineno));
    (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
}
#line 5503 "parser.tab.c"
    break;

  case 253:
#line 2033 "parser.y"
{
    (yyval.node) = new Node("ReturnStatement");
    (yyval.node)->children.push_back(new Node("return", "Keyword", yylineno));
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
}
#line 5514 "parser.tab.c"
    break;

  case 254:
#line 2041 "parser.y"
{
    (yyval.node) = new Node("ThrowStatement");
    (yyval.node)->children.push_back(new Node("throw", "Keyword", yylineno));
    (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));}
#line 5523 "parser.tab.c"
    break;

  case 255:
#line 2046 "parser.y"
 {
    (yyval.node) = new Node("ThrowStatement");
    (yyval.node)->children.push_back(new Node("throw", "Keyword", yylineno));
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
 }
#line 5534 "parser.tab.c"
    break;

  case 256:
#line 2056 "parser.y"
    {
        (yyval.node) = new Node("SynchronizedStatement");
        (yyval.node)->children.push_back(new Node("synchronized", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 5547 "parser.tab.c"
    break;

  case 257:
#line 2066 "parser.y"
    {
    (yyval.node) = new Node("TryStatement");
    (yyval.node)->children.push_back(new Node("try", "Keyword", yylineno));
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 5558 "parser.tab.c"
    break;

  case 258:
#line 2073 "parser.y"
            {
                (yyval.node) = new Node("TryStatement");
                (yyval.node)->children.push_back(new Node("try", "Keyword", yylineno));
                (yyval.node)->children.push_back((yyvsp[-1].node));
                (yyval.node)->children.push_back((yyvsp[0].node));
            }
#line 5569 "parser.tab.c"
    break;

  case 259:
#line 2080 "parser.y"
            {
                (yyval.node) = new Node("TryStatement");
                (yyval.node)->children.push_back(new Node("try", "Keyword", yylineno));
                (yyval.node)->children.push_back((yyvsp[-2].node));
                (yyval.node)->children.push_back((yyvsp[-1].node));
                (yyval.node)->children.push_back((yyvsp[0].node));}
#line 5580 "parser.tab.c"
    break;

  case 260:
#line 2088 "parser.y"
    {
        (yyval.node) = new Node("Catches");
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 5589 "parser.tab.c"
    break;

  case 261:
#line 2093 "parser.y"
        {
            (yyval.node) = new Node("Catches");
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
        }
#line 5599 "parser.tab.c"
    break;

  case 262:
#line 2100 "parser.y"
    {
        (yyval.node) = new Node("CatchClause");
        (yyval.node)->children.push_back(new Node("catch", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 5612 "parser.tab.c"
    break;

  case 263:
#line 2110 "parser.y"
    {
        (yyval.node) = new Node("Finally");
        (yyval.node)->children.push_back(new Node("finally", "Keyword", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 5622 "parser.tab.c"
    break;

  case 264:
#line 2121 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 5630 "parser.tab.c"
    break;

  case 265:
#line 2125 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 5638 "parser.tab.c"
    break;

  case 266:
#line 2131 "parser.y"
                {(yyval.node) = new Node((yyvsp[0].str),"Literal", INT,yylineno);}
#line 5644 "parser.tab.c"
    break;

  case 267:
#line 2132 "parser.y"
                  {(yyval.node) = new Node((yyvsp[0].str),"Literal" , BIN, yylineno);}
#line 5650 "parser.tab.c"
    break;

  case 268:
#line 2133 "parser.y"
                       {(yyval.node) = new Node((yyvsp[0].str),"Literal", FLOAT ,yylineno);}
#line 5656 "parser.tab.c"
    break;

  case 269:
#line 2134 "parser.y"
                  {(yyval.node) = new Node((yyvsp[0].str),"Literal", OCT, yylineno);}
#line 5662 "parser.tab.c"
    break;

  case 270:
#line 2135 "parser.y"
                      {(yyval.node) = new Node((yyvsp[0].str),"Literal", HEX_FLOAT, yylineno);}
#line 5668 "parser.tab.c"
    break;

  case 271:
#line 2136 "parser.y"
                     {(yyval.node) = new Node((yyvsp[0].str),"Literal", STRING, yylineno);}
#line 5674 "parser.tab.c"
    break;

  case 272:
#line 2137 "parser.y"
                  {(yyval.node) = new Node((yyvsp[0].str),"Literal", HEX, yylineno);}
#line 5680 "parser.tab.c"
    break;

  case 273:
#line 2138 "parser.y"
             {(yyval.node) = new Node("this","Keyword", yylineno);}
#line 5686 "parser.tab.c"
    break;

  case 274:
#line 2139 "parser.y"
                         {(yyval.node) = new Node("TextBlock","Literal",STRING, yylineno);}
#line 5692 "parser.tab.c"
    break;

  case 275:
#line 2140 "parser.y"
                   {(yyval.node) = new Node((yyvsp[0].str),"Literal", CHAR, yylineno);}
#line 5698 "parser.tab.c"
    break;

  case 276:
#line 2141 "parser.y"
                   {(yyval.node) = new Node("true","Keyword", BOOL);}
#line 5704 "parser.tab.c"
    break;

  case 277:
#line 2142 "parser.y"
                    {(yyval.node) = new Node("false","Keyword", BOOL);}
#line 5710 "parser.tab.c"
    break;

  case 278:
#line 2143 "parser.y"
                   {(yyval.node) = new Node("null","Keyword", _NULL);}
#line 5716 "parser.tab.c"
    break;

  case 279:
#line 2144 "parser.y"
                                            {
        (yyval.node) = new Node("PrimaryNoNewArray");
        (yyval.node)->type = (yyvsp[-1].node)->type;
        (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    }
#line 5728 "parser.tab.c"
    break;

  case 280:
#line 2152 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 5736 "parser.tab.c"
    break;

  case 281:
#line 2156 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 5744 "parser.tab.c"
    break;

  case 282:
#line 2160 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 5752 "parser.tab.c"
    break;

  case 283:
#line 2163 "parser.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 5758 "parser.tab.c"
    break;

  case 284:
#line 2168 "parser.y"
    { (yyval.node) = new Node("ClassInstanceCreationExpression");
       (yyval.node)->type = (yyvsp[-2].node)->type;
       (yyval.node)->children.push_back(new Node("new","Keyword", yylineno));
       (yyval.node)->children.push_back((yyvsp[-2].node));
       (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
       (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    }
#line 5770 "parser.tab.c"
    break;

  case 285:
#line 2176 "parser.y"
        { 
        (yyval.node) = new Node("ClassInstanceCreationExpression");
        (yyval.node)->type = (yyvsp[-3].node)->type;
        (yyval.node)->children.push_back(new Node("new","Keyword", yylineno));
        (yyval.node)->children.push_back((yyvsp[-3].node));
        (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
        }
#line 5784 "parser.tab.c"
    break;

  case 286:
#line 2189 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 5790 "parser.tab.c"
    break;

  case 287:
#line 2191 "parser.y"
    {
        (yyval.node) = new Node("ArgumentList");
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 5801 "parser.tab.c"
    break;

  case 288:
#line 2201 "parser.y"
     { 
       (yyval.node) = new Node("ArrayCreationExpression");
       (yyval.node)->type= (yyvsp[-1].node)->type;
       (yyval.node)->children.push_back(new Node("new","Keyword", yylineno));
       (yyval.node)->children.push_back((yyvsp[-1].node));
       (yyval.node)->children.push_back((yyvsp[0].node));
       if(!isDot){
        if(t != (yyvsp[-1].node)->type){
                yyerror("Type mismatch in arrayCreationExpression rhs");
                exit(0);
        }
       }
     }
#line 5819 "parser.tab.c"
    break;

  case 289:
#line 2215 "parser.y"
    { (yyval.node) = new Node("ArrayCreationExpression");
         (yyval.node)->type= (yyvsp[-2].node)->type;
       (yyval.node)->children.push_back(new Node("new","Keyword", yylineno));
       (yyval.node)->children.push_back((yyvsp[-2].node));
       (yyval.node)->children.push_back((yyvsp[-1].node));
       (yyval.node)->children.push_back((yyvsp[0].node));
       if(!isDot){
            if(t != (yyvsp[-2].node)->type){
                    yyerror("Type mismatch in arrayCreationExpression rhs");
                    exit(0);
            }
       }
    }
#line 5837 "parser.tab.c"
    break;

  case 290:
#line 2229 "parser.y"
        { (yyval.node) = new Node("ArrayCreationExpression");
         (yyval.node)->type= (yyvsp[-2].node)->type;
       (yyval.node)->children.push_back(new Node("new","Keyword", yylineno));
       (yyval.node)->children.push_back((yyvsp[-2].node));
       (yyval.node)->children.push_back((yyvsp[-1].node));
       (yyval.node)->children.push_back((yyvsp[0].node));
       if(!isDot){
        if(t != (yyvsp[-2].node)->type){
                yyerror("Type mismatch in arrayCreationExpression rhs");
                exit(0);
        }
       }
    }
#line 5855 "parser.tab.c"
    break;

  case 291:
#line 2243 "parser.y"
        { (yyval.node) = new Node("ArrayCreationExpression");
          (yyval.node)->type= (yyvsp[-1].node)->type;
       (yyval.node)->children.push_back(new Node("new","Keyword", yylineno));
       (yyval.node)->children.push_back((yyvsp[-1].node));
       (yyval.node)->children.push_back((yyvsp[0].node));}
#line 5865 "parser.tab.c"
    break;

  case 292:
#line 2249 "parser.y"
        { (yyval.node) = new Node("ArrayCreationExpression");
            (yyval.node)->type= (yyvsp[-2].node)->type;
       (yyval.node)->children.push_back(new Node("new","Keyword", yylineno));
       (yyval.node)->children.push_back((yyvsp[-2].node));
       (yyval.node)->children.push_back((yyvsp[-1].node));
       (yyval.node)->children.push_back((yyvsp[0].node));}
#line 5876 "parser.tab.c"
    break;

  case 293:
#line 2256 "parser.y"
        { (yyval.node) = new Node("ArrayCreationExpression");
            (yyval.node)->type= (yyvsp[-2].node)->type;
       (yyval.node)->children.push_back(new Node("new","Keyword", yylineno));
       (yyval.node)->children.push_back((yyvsp[-2].node));
       (yyval.node)->children.push_back((yyvsp[-1].node));
       (yyval.node)->children.push_back((yyvsp[0].node));}
#line 5887 "parser.tab.c"
    break;

  case 294:
#line 2267 "parser.y"
     {(yyval.node) = (yyvsp[0].node);}
#line 5893 "parser.tab.c"
    break;

  case 295:
#line 2269 "parser.y"
    {(yyval.node) = new Node("DimExprs");
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 5902 "parser.tab.c"
    break;

  case 296:
#line 2277 "parser.y"
     {
        (yyval.node) = new Node("DimExpr");
        if(!isDot){
            if((yyvsp[-1].node)->type != INT)
            {
                yyerror("Array index must be of type int");
                exit(0);
            }
            if(isarr){
                vs.push_back(vs.size());
            }
        }
     (yyval.node)->children.push_back(new Node("[","Separator", yylineno));
     (yyval.node)->children.push_back((yyvsp[-1].node));
     (yyval.node)->children.push_back(new Node("]","Separator", yylineno));
     }
#line 5923 "parser.tab.c"
    break;

  case 297:
#line 2298 "parser.y"
    {
        (yyval.node) = new Node("Dims");
    (yyval.node)->children.push_back(new Node("[","Separator", yylineno));
    (yyval.node)->children.push_back(new Node("]","Separator", yylineno));
    if(isarr){
        vs.push_back(vs.size());
    }
    }
#line 5936 "parser.tab.c"
    break;

  case 298:
#line 2307 "parser.y"
    {(yyval.node) = new Node("Dims");
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("[","Separator", yylineno));
    if(isarr){
        vs.push_back(vs.size());
    }
    }
#line 5948 "parser.tab.c"
    break;

  case 299:
#line 2318 "parser.y"
    {(yyval.node) = new Node("FieldAccess");
        //$$->type= $3->type;
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(".","Separator", yylineno));
    (yyval.node)->children.push_back(new Node((yyvsp[0].str),"Identifier",yylineno));}
#line 5958 "parser.tab.c"
    break;

  case 300:
#line 2324 "parser.y"
    {(yyval.node) = new Node("FieldAccess");
    //$$->type= $3->type;
    (yyval.node)->children.push_back(new Node("super","Keyword", yylineno));
    (yyval.node)->children.push_back(new Node(".","Separator", yylineno));
    (yyval.node)->children.push_back(new Node((yyvsp[0].str),"Identifier",yylineno));}
#line 5968 "parser.tab.c"
    break;

  case 301:
#line 2333 "parser.y"
    {(yyval.node) = new Node("MethodInvocation");
     //$$->type= $1->type;
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    }
#line 5979 "parser.tab.c"
    break;

  case 302:
#line 2340 "parser.y"
     {(yyval.node) = new Node("MethodInvocation");
       // $$->type= $1->type;
     (yyval.node)->children.push_back((yyvsp[-3].node));
     (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
     (yyval.node)->children.push_back((yyvsp[-1].node));
     (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
     }
#line 5991 "parser.tab.c"
    break;

  case 303:
#line 2348 "parser.y"
    {(yyval.node) = new Node("MethodInvocation");
    //$$->type= $3->type;
    (yyval.node)->children.push_back((yyvsp[-4].node));
    (yyval.node)->children.push_back(new Node(".","Separator", yylineno));
    (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    }
#line 6004 "parser.tab.c"
    break;

  case 304:
#line 2357 "parser.y"
    {(yyval.node) = new Node("MethodInvocation");
   // $$->type= $3->type;
    (yyval.node)->children.push_back((yyvsp[-5].node));
    (yyval.node)->children.push_back(new Node(".","Separator", yylineno));
    (yyval.node)->children.push_back(new Node((yyvsp[-3].str),"Identifier",yylineno));
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    }
#line 6018 "parser.tab.c"
    break;

  case 305:
#line 2367 "parser.y"
    {(yyval.node) = new Node("MethodInvocation");
    //$$->type= $3->type;
    (yyval.node)->children.push_back(new Node("super","Keyword", yylineno));
    (yyval.node)->children.push_back(new Node(".","Separator", yylineno));
    (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    }
#line 6031 "parser.tab.c"
    break;

  case 306:
#line 2376 "parser.y"
    {(yyval.node) = new Node("MethodInvocation");
    //$$->type= $3->type;
    (yyval.node)->children.push_back(new Node("super","Keyword", yylineno));
    (yyval.node)->children.push_back(new Node(".","Separator", yylineno));
    (yyval.node)->children.push_back(new Node((yyvsp[-3].str),"Identifier",yylineno));
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    }
#line 6045 "parser.tab.c"
    break;

  case 307:
#line 2389 "parser.y"
    {(yyval.node) = new Node("ArrayAccess");
     (yyval.node)->type= (yyvsp[-3].node)->type;
     if(!isDot){
        if((yyvsp[-1].node)->type != INT)
        {
            yyerror("Array index must be of type int");
            exit(0);
        }
     }
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back(new Node("[","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back(new Node("]","Separator", yylineno));
    }
#line 6064 "parser.tab.c"
    break;

  case 308:
#line 2404 "parser.y"
    {(yyval.node) = new Node("ArrayAccess");
        (yyval.node)->type= (yyvsp[-3].node)->type;
        if(!isDot){
            if((yyvsp[-1].node)->type != INT)
            {
                yyerror("Array index must be of type int");
                exit(0);
            }
        }
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back(new Node("[","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back(new Node("]","Separator", yylineno));
    }
#line 6083 "parser.tab.c"
    break;

  case 309:
#line 2422 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 6089 "parser.tab.c"
    break;

  case 310:
#line 2424 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 6095 "parser.tab.c"
    break;

  case 311:
#line 2426 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 6101 "parser.tab.c"
    break;

  case 312:
#line 2428 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 6107 "parser.tab.c"
    break;

  case 313:
#line 2433 "parser.y"
    {(yyval.node) = new Node("PostIncrementExpression");
     (yyval.node)->type= (yyvsp[-1].node)->type;
     if(!isDot){
        if ((yyvsp[-1].node)->type != INT)
        {
            yyerror("Post increment can only be applied to int");
            exit(0);
        }
     }
    
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back(new Node("++","Separator", yylineno));}
#line 6124 "parser.tab.c"
    break;

  case 314:
#line 2449 "parser.y"
    {(yyval.node) = new Node("PostDecrementExpression");
        (yyval.node)->type= (yyvsp[-1].node)->type;
        if(!isDot){
            if ((yyvsp[-1].node)->type != INT)
            {
                yyerror("Post decrement can only be applied to int");
                exit(0);
            }
        }
    (yyval.node)->children.push_back((yyvsp[-1].node));}
#line 6139 "parser.tab.c"
    break;

  case 315:
#line 2463 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 6145 "parser.tab.c"
    break;

  case 316:
#line 2465 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 6151 "parser.tab.c"
    break;

  case 317:
#line 2467 "parser.y"
    {(yyval.node) = new Node("UnaryExpression");
     (yyval.node)->type= (yyvsp[0].node)->type;
    (yyval.node)->children.push_back(new Node("+","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));}
#line 6160 "parser.tab.c"
    break;

  case 318:
#line 2472 "parser.y"
    {(yyval.node) = new Node("UnaryExpression");
        (yyval.node)->type= (yyvsp[0].node)->type;
    (yyval.node)->children.push_back(new Node("-","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));}
#line 6169 "parser.tab.c"
    break;

  case 319:
#line 2477 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 6175 "parser.tab.c"
    break;

  case 320:
#line 2482 "parser.y"
    {(yyval.node) = new Node("PreIncrementExpression");
     (yyval.node)->type= (yyvsp[0].node)->type;
     if(!isDot){
     if ((yyvsp[0].node)->type != INT)
     {
        yyerror("Pre increment can only be applied to int");
        exit(0);
     }
     }
    (yyval.node)->children.push_back(new Node("++","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));}
#line 6191 "parser.tab.c"
    break;

  case 321:
#line 2497 "parser.y"
    {(yyval.node) = new Node("PreDecrementExpression");
        (yyval.node)->type= (yyvsp[0].node)->type;
        if(!isDot){
        if ((yyvsp[0].node)->type != INT)
        {
            yyerror("Pre decrement can only be applied to int");
            exit(0);
        }
        }
    (yyval.node)->children.push_back(new Node("--","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));}
#line 6207 "parser.tab.c"
    break;

  case 322:
#line 2512 "parser.y"
   {(yyval.node) = (yyvsp[0].node);}
#line 6213 "parser.tab.c"
    break;

  case 323:
#line 2514 "parser.y"
    {(yyval.node) = new Node("UnaryExpressionNotPlusMinus");
     (yyval.node)->type= (yyvsp[0].node)->type;
     if(!isDot){
     if ((yyvsp[0].node)->type != INT)
     {
        yyerror("Bitwise complement can only be applied to int");
        exit(0);
     }
     }
    (yyval.node)->children.push_back(new Node("~","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));}
#line 6229 "parser.tab.c"
    break;

  case 324:
#line 2526 "parser.y"
    {(yyval.node) = new Node("UnaryExpressionNotPlusMinus");
        (yyval.node)->type= (yyvsp[0].node)->type;
        if(!isDot){
        if ((yyvsp[0].node)->type != BOOL)
        {
            yyerror("Logical not can only be applied to boolean");
            exit(0);
        }
        }
    (yyval.node)->children.push_back(new Node("!","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));}
#line 6245 "parser.tab.c"
    break;

  case 325:
#line 2538 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 6251 "parser.tab.c"
    break;

  case 326:
#line 2543 "parser.y"
    {(yyval.node) = new Node("CastExpression");
     (yyval.node)->type= (yyvsp[-2].node)->type;
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6263 "parser.tab.c"
    break;

  case 327:
#line 2551 "parser.y"
    {
    (yyval.node) = new Node("CastExpression");
    (yyval.node)->type= (yyvsp[-3].node)->type;
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6277 "parser.tab.c"
    break;

  case 328:
#line 2561 "parser.y"
    {
    (yyval.node) = new Node("CastExpression");
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6289 "parser.tab.c"
    break;

  case 329:
#line 2569 "parser.y"
    {
    (yyval.node) = new Node("CastExpression");
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6302 "parser.tab.c"
    break;

  case 330:
#line 2581 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6310 "parser.tab.c"
    break;

  case 331:
#line 2585 "parser.y"
    {
    (yyval.node) = new Node("MultiplicativeExpression");
    (yyval.node)->type=widen((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("*","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6322 "parser.tab.c"
    break;

  case 332:
#line 2593 "parser.y"
    {
    (yyval.node) = new Node("MultiplicativeExpression");
    (yyval.node)->type=widen((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("/","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6334 "parser.tab.c"
    break;

  case 333:
#line 2601 "parser.y"
    {
    (yyval.node) = new Node("MultiplicativeExpression");
    (yyval.node)->type=widen((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("%","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6346 "parser.tab.c"
    break;

  case 334:
#line 2612 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6354 "parser.tab.c"
    break;

  case 335:
#line 2616 "parser.y"
    {
    (yyval.node) = new Node("AdditiveExpression");
    (yyval.node)->type=widen((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("+","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6366 "parser.tab.c"
    break;

  case 336:
#line 2624 "parser.y"
    {
    (yyval.node) = new Node("AdditiveExpression");
    (yyval.node)->type=widen((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("-","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6378 "parser.tab.c"
    break;

  case 337:
#line 2635 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6386 "parser.tab.c"
    break;

  case 338:
#line 2639 "parser.y"
    {
    (yyval.node) = new Node("ShiftExpression");
    if(!isDot){
    if((yyvsp[-2].node)->type != INT || (yyvsp[0].node)->type != INT)
    {
        yyerror("Shift Operation can only be applied to int");
        exit(0);
    }
    }
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("<<","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6404 "parser.tab.c"
    break;

  case 339:
#line 2653 "parser.y"
    {
    (yyval.node) = new Node("ShiftExpression");
    if(!isDot){
    if((yyvsp[-2].node)->type != INT || (yyvsp[0].node)->type != INT)
    {
        yyerror("Shift Operation can only be applied to int");
        exit(0);
    }
    }
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(">>","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6422 "parser.tab.c"
    break;

  case 340:
#line 2667 "parser.y"
    {
    (yyval.node) = new Node("ShiftExpression");
    if(!isDot){
    if((yyvsp[-2].node)->type != INT || (yyvsp[0].node)->type != INT)
    {
        yyerror("Shift Operation can only be applied to int");
        exit(0);
    }
    }
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(">>>","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6440 "parser.tab.c"
    break;

  case 341:
#line 2684 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6448 "parser.tab.c"
    break;

  case 342:
#line 2688 "parser.y"
    {
    (yyval.node) = new Node("RelationalExpression");
    (yyval.node)->children.push_back((yyvsp[-2].node));
    if(!isDot){
    if(add_set.find((yyvsp[-2].node)->type)==add_set.end() || add_set.find((yyvsp[0].node)->type)==add_set.end())
    {   
        yyerror("Relational Operation cannot be applied to this type");
        cout<<(yyvsp[-2].node)->type<<" "<<(yyvsp[0].node)->type<<endl;
        exit(0);
    }
    }
    (yyval.node)->children.push_back(new Node("<","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6467 "parser.tab.c"
    break;

  case 343:
#line 2703 "parser.y"
    {
    (yyval.node) = new Node("RelationalExpression");
    if(!isDot){
    if(add_set.find((yyvsp[-2].node)->type)==add_set.end() || add_set.find((yyvsp[0].node)->type)==add_set.end())
    {
        yyerror("Relational Operation cannot be applied to this type");
        exit(0);
    }
    }
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(">","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6485 "parser.tab.c"
    break;

  case 344:
#line 2717 "parser.y"
    {
    (yyval.node) = new Node("RelationalExpression");
    if(!isDot){
    if(add_set.find((yyvsp[-2].node)->type)==add_set.end() || add_set.find((yyvsp[0].node)->type)==add_set.end())
    {
        yyerror("Relational Operation cannot be applied to this type");
        exit(0);
    }
    }
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("<=","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6503 "parser.tab.c"
    break;

  case 345:
#line 2731 "parser.y"
    {
    (yyval.node) = new Node("RelationalExpression");
    if(!isDot){
    if(add_set.find((yyvsp[-2].node)->type)==add_set.end() || add_set.find((yyvsp[0].node)->type)==add_set.end())
    {
        yyerror("Relational Operation cannot be applied to this type");
        exit(0);
    }
    }
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(">=","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6521 "parser.tab.c"
    break;

  case 346:
#line 2745 "parser.y"
    {
    (yyval.node) = new Node("RelationalExpression");
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("instanceof","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6532 "parser.tab.c"
    break;

  case 347:
#line 2755 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6540 "parser.tab.c"
    break;

  case 348:
#line 2759 "parser.y"
    {
    (yyval.node) = new Node("EqualityExpression");
    if(!isDot){
    if(!((add_set.find((yyvsp[-2].node)->type)!=add_set.end() && add_set.find((yyvsp[0].node)->type)!=add_set.end()) || ((yyvsp[-2].node)->type == (yyvsp[0].node)->type)))
    {
        yyerror("Equality Operation cannot be applied to this type");
        exit(0);
    }
    }
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("==","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6558 "parser.tab.c"
    break;

  case 349:
#line 2773 "parser.y"
    {
    (yyval.node) = new Node("EqualityExpression");
    if(!isDot){
    if(!((add_set.find((yyvsp[-2].node)->type)!=add_set.end() && add_set.find((yyvsp[0].node)->type)!=add_set.end()) || ((yyvsp[-2].node)->type == (yyvsp[0].node)->type)))
    {
        yyerror("Equality Operation cannot be applied to this type");
        exit(0);
    }
    }
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("!=","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6576 "parser.tab.c"
    break;

  case 350:
#line 2790 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6584 "parser.tab.c"
    break;

  case 351:
#line 2794 "parser.y"
    {
    (yyval.node) = new Node("AndExpression");
    if(!isDot){
    if((yyvsp[-2].node)->type != INT || (yyvsp[0].node)->type != INT)
    {
        yyerror("Bitwise Operation can only be applied to int");
        exit(0);
    }
    }
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("&","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6602 "parser.tab.c"
    break;

  case 352:
#line 2811 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 6610 "parser.tab.c"
    break;

  case 353:
#line 2815 "parser.y"
    {
    (yyval.node) = new Node("ExclusiveOrExpression");
    if(!isDot){
    if((yyvsp[-2].node)->type != INT || (yyvsp[0].node)->type != INT)
    {
        yyerror("Bitwise Operation can only be applied to int");
        exit(0);
    }
    }
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("^","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6628 "parser.tab.c"
    break;

  case 354:
#line 2832 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6636 "parser.tab.c"
    break;

  case 355:
#line 2836 "parser.y"
    {
    (yyval.node) = new Node("InclusiveOrExpression");
    if(!isDot){
    if((yyvsp[-2].node)->type != INT || (yyvsp[0].node)->type != INT)
    {
        yyerror("Bitwise Operation can only be applied to int");
        exit(0);
    }
    }
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("|","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6654 "parser.tab.c"
    break;

  case 356:
#line 2853 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6662 "parser.tab.c"
    break;

  case 357:
#line 2857 "parser.y"
    {
    (yyval.node) = new Node("ConditionalAndExpression");
    if(!isDot){
    if((yyvsp[-2].node)->type != BOOL || (yyvsp[0].node)->type != BOOL)
    {
        yyerror("Bitwise Operation can only be applied to int");
        exit(0);
    }
    }
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("&&","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6680 "parser.tab.c"
    break;

  case 358:
#line 2874 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6688 "parser.tab.c"
    break;

  case 359:
#line 2878 "parser.y"
    {
    (yyval.node) = new Node("ConditionalOrExpression");
    if(!isDot){
    if((yyvsp[-2].node)->type != BOOL || (yyvsp[0].node)->type != BOOL)
    {
        yyerror("Bitwise Operation can only be applied to int");
        exit(0);
    }
    }
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("||","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6706 "parser.tab.c"
    break;

  case 360:
#line 2895 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6714 "parser.tab.c"
    break;

  case 361:
#line 2899 "parser.y"
    {
    (yyval.node) = new Node("ConditionalExpression");
    if(!isDot){
    if((yyvsp[-4].node)->type != BOOL)
    {
        yyerror("Conditional Operation can only be applied to boolean");
        exit(0);
    }
    if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
    {
        yyerror("Conditional Operation can only be applied to same type");
        exit(0);
    }
    }
    (yyval.node)->children.push_back((yyvsp[-4].node));
    (yyval.node)->children.push_back(new Node("?","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(":","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6739 "parser.tab.c"
    break;

  case 362:
#line 2923 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6747 "parser.tab.c"
    break;

  case 363:
#line 2927 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6755 "parser.tab.c"
    break;

  case 364:
#line 2934 "parser.y"
    {
    (yyval.node) = new Node("Assignment");
    if(!isDot){
    if(add_set.find((yyvsp[-2].node)->type)==add_set.end() || add_set.find((yyvsp[0].node)->type)==add_set.end())
    {
        yyerror("Assignment Operation can only be applied to same type");
        exit(0);
    }
    }
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6773 "parser.tab.c"
    break;

  case 365:
#line 2951 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6781 "parser.tab.c"
    break;

  case 366:
#line 2955 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6789 "parser.tab.c"
    break;

  case 367:
#line 2959 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6797 "parser.tab.c"
    break;

  case 368:
#line 2966 "parser.y"
    {
    (yyval.node) = new Node("=","Separator", yylineno);
    }
#line 6805 "parser.tab.c"
    break;

  case 369:
#line 2970 "parser.y"
    {
    (yyval.node) = new Node("+=","Separator", yylineno);
    }
#line 6813 "parser.tab.c"
    break;

  case 370:
#line 2974 "parser.y"
    {
    (yyval.node) = new Node("-=","Separator", yylineno);
    }
#line 6821 "parser.tab.c"
    break;

  case 371:
#line 2978 "parser.y"
    {
    (yyval.node) = new Node("*=","Separator", yylineno);
    }
#line 6829 "parser.tab.c"
    break;

  case 372:
#line 2982 "parser.y"
    {
    (yyval.node) = new Node("/=","Separator", yylineno);
    }
#line 6837 "parser.tab.c"
    break;

  case 373:
#line 2986 "parser.y"
    {
    (yyval.node) = new Node("%=","Separator", yylineno);
    }
#line 6845 "parser.tab.c"
    break;

  case 374:
#line 2990 "parser.y"
    {
    (yyval.node) = new Node("<<=","Separator", yylineno);
    }
#line 6853 "parser.tab.c"
    break;

  case 375:
#line 2994 "parser.y"
    {
    (yyval.node) = new Node(">>=","Separator", yylineno);
    }
#line 6861 "parser.tab.c"
    break;

  case 376:
#line 2998 "parser.y"
    {
    (yyval.node) = new Node(">>>=","Separator", yylineno);
    }
#line 6869 "parser.tab.c"
    break;

  case 377:
#line 3002 "parser.y"
    {
    (yyval.node) = new Node("&=","Separator", yylineno);
    }
#line 6877 "parser.tab.c"
    break;

  case 378:
#line 3006 "parser.y"
    {
    (yyval.node) = new Node("|=","Separator", yylineno);
    }
#line 6885 "parser.tab.c"
    break;

  case 379:
#line 3010 "parser.y"
    {
    (yyval.node) = new Node("^=","Separator", yylineno);
    }
#line 6893 "parser.tab.c"
    break;

  case 380:
#line 3017 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6901 "parser.tab.c"
    break;


#line 6905 "parser.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 3021 "parser.y"



TYPE widen(TYPE a, TYPE b){
    return (a > b)?a:b;
}

void traverse(Node* node, int &counter, ofstream &dotfile) {
  node->count = counter++;
  dotfile << "  node" << node->count << " [label=\"" << node->token << "\\n" << node->id << "\"];" << endl;
  for (int i=0;i<node->children.size();i++) {
    int child_id = counter;
    dotfile << "  node" << node->count << " -> node" << child_id << ";" << endl;
    traverse(node->children[i], counter, dotfile);
  }
}

void print_dot(const char* filename) {
  ofstream dotfile(filename);
  dotfile << "digraph PARSE_TREE {" << endl;
  int counter = 0;
  traverse(root, counter, dotfile);
  dotfile << "}" << endl;
  dotfile.close();
}

bool check_semantic_expression(Node* node, TYPE t){
    if(node->token == "Identifier"){
        int t1 = symTables[currentSymTableId].lookup(node->id);
        cout<<"T-------------------"<<t1<<endl;
        if(!t1){
            cout<<"Symbol not Declared"<<node->id<<" at line "<<node->lineno<<". First declared at line "<<t1<<"."<<endl;
            exit(0);
        }
        vector<struct symEntry>* a = symTables[currentSymTableId].getSymEntry(node->children[0]->id);
        if(!a){
            cout<<"Symbol not found in Symbol Table "<<node->id<<" at line "<<node->lineno<<". First declared at line "<<t1<<"."<<endl;
            exit(0);
        }
        if((*a)[0].type != t && t !=VAR){
            cout<<"Type mismatch at line "<<node->lineno<<". Expected "<<enum_types[t]<<" but found "<<enum_types[(*a)[0].type]<<endl;
            exit(0);
        }
        return true;
    }
    if(node->token == "Literal"){
        if(node->type != t){
            cout<<"Type mismatch at line "<<node->lineno<<". Expected "<<t<<" but found "<<node->type<<endl;
            exit(0);
        }
        return true;
    }
    if(node->id.find("Pre") == 0)
        return check_semantic_expression(node->children[1], t);
    if(node->id.find("Unary") == 0)
        return check_semantic_expression(node->children[1], t);

    for(auto i = node->children.begin(); i != node->children.end(); i += 2){
        if(!check_semantic_expression(*i, t)){
            cout<<"Error in evaluating expression"<<endl;
            exit(0);
        }
    }
    return true;
}

bool check_semantic_VariableAssignment(Node*node, TYPE t){
    if(node->id == "Assignment"){
        int t1 = symTables[currentSymTableId].lookup(node->children[0]->id);
        cout<<"T-------------------"<<t1<<endl;
        if(!t1){
            cout<<"Symbol not Declared"<<node->children[0]->id<<" at line "<<node->lineno<<". First declared at line "<<t1<<"."<<endl;
            exit(0);
        }
        vector<struct symEntry>* a = symTables[currentSymTableId].getSymEntry(node->children[0]->id);
        if(!a){
            cout<<"Symbol not found in Symbol Table "<<node->id<<" at line "<<node->lineno<<". First declared at line "<<t1<<"."<<endl;
            exit(0);
        }
        if((*a)[0].type != t && t !=VAR){
            cout<<"Type mismatch at line "<<node->lineno<<". Expected "<<enum_types[t]<<" but found "<<enum_types[(*a)[0].type]<<endl;
            exit(0);
        }
        if(node->children[2]->id == "Assignment")
            return check_semantic_VariableAssignment(node->children[2], (*a)[0].type);
        return check_semantic_expression(node->children[2], (*a)[0].type);
    }
    if(node->token=="Literal"){
        if(node->type != t){
            cout<<"Type mismatch at line "<<node->lineno<<". Expected "<<t<<" but found "<<node->type<<endl;
            exit(0);
        }
        return true;
    }
    return true;
}

bool check_semantic_LocalVariableDeclaration(Node*node, TYPE t){

    if(node->id == "VariableDeclaratorList"){
        cout<<"Entering VariableDeclaratorList"<<endl;
        return check_semantic_LocalVariableDeclaration(node->children[0], t) && check_semantic_LocalVariableDeclaration(node->children[2], t);
    }
    if(node->id == "VariableDeclarator"){
        cout<<"Entering VariableDeclarator or Assignment"<<endl;
        if(check_semantic_VariableAssignment(node->children[2], t)){
            return check_semantic_LocalVariableDeclaration(node->children[0], t);
        }
        else 
            return false;
    }
    if(node->id == "Assignment"){
        return check_semantic_VariableAssignment(node, t);
    }
    if(node->token == "Identifier"){
        cout<<"Entering Identifier"<<endl;
        int t1 = symTables[currentSymTableId].lookup(node->id);
        if(t1){
            cout<<"Redeclaration of symbol "<<node->id<<" at line "<<node->lineno<<". First declared at line "<<t1<<"."<<endl;
            exit(0);
        }
        else{
            symTables[currentSymTableId].insertSymEntry(node->id,t,node->lineno);
            return true;
        }
    }
    if(node->token == "Literal"){
        cout<<"Entering Literal for type: "<<enum_types[t]<<endl;
        return node->type == t;
    }
    return true;
}

void LocalVariableDeclaration(Node* node){
    cout<<"entering LocalVariableDeclaration"<<endl;
    TYPE t = VOID;
    Node*temp = node;
    while(temp->children.size()){
        if(temp->children[0]->id == "final")
            temp = temp->children[1];
        else    
            temp = temp->children[0];
    }
    t = temp->type;
    cout<<"-------------------Local VariableDeclaration type passed = "<<enum_types[t]<<endl;
    check_semantic_LocalVariableDeclaration(node->children[node->children.size()-1], t);
}

void symTab_csv(symtab* a){
    ofstream fout;
    string s= "symtab"+to_string(a->ID)+".csv";
    fout.open(s);
    fout<<"Lexeme,Tokens,Type,ArrayDimSize,LineNo"<<endl;
    for(auto i = a->entries.begin(); i != a->entries.end(); i++){
        for(auto j = i->second.begin(); j != i->second.end(); j++)
            fout<<i->first<<","<<"Identifier"<<","<<enum_types[j->type]<<","<<j->size<<","<<j->lineno<<endl;
    }
    fout.close();
}

void FieldDeclaration(Node* node){
    cout<<"Entering FieldDeclaration"<<endl;
    TYPE t = VOID;
    Node*temp = node;
    while(temp->children.size()){
        if(temp->children.size() == 4)
            temp = temp->children[1];
        else    
            temp = temp->children[0];
    }
    t = temp->type;
    cout<<enum_types[t]<<endl;
    check_semantic_LocalVariableDeclaration(node->children[node->children.size()-2], t);
}

void traverse_semantics(Node*node, int &counter){

    if(node->id == "LocalVariableDeclaration"){
        LocalVariableDeclaration(node);
        return;
    }
    if(node->id == "FieldDeclaration"){
        FieldDeclaration(node);
        return;
    }
    if(node->id == "Assignment"){
        check_semantic_VariableAssignment(node, VAR);
        return;
    }
    if(node->id == "LocalVariableDeclaration"){
        LocalVariableDeclaration(node);
        return;
    }
    if(node->id == "FieldDeclaration"){
        FieldDeclaration(node);
        return;
    }
    if(node->id == "Assignment"){
        check_semantic_VariableAssignment(node, VAR);
        return;
    }

    // ----------------Expression----------------------

    // if(node->id == "ConditionalExpression"){
    //     return check_semantic_expression(node->children[0], t) && check_semantic_expression(node->children[2], t) && check_semantic_expression(node->children[4], t);
    // }
    // if(node->id == "ConditionalOrExpression"){
    //     return check_semantic_expression(node->children[0], t) && check_semantic_expression(node->children[2], t);
    // }
    // if(node->id == "ConditionalAndExpression"){
    //     return check_semantic_expression(node->children[0], t) && check_semantic_expression(node->children[2], t);
    // }
    // if(node->id == "InclusiveOrExpression"){
    //     return check_semantic_expression(node->children[0], t) && check_semantic_expression(node->children[2], t);
    // }
    // if(node->id == "ExclusiveOrExpression"){
    //     return check_semantic_expression(node->children[0], t) && check_semantic_expression(node->children[2], t);
    // }
    // if(node->id == "AndExpression"){
    //     return check_semantic_expression(node->children[0], t) && check_semantic_expression(node->children[2], t);
    // }
    // if(node->id == "EqualityExpression"){
    //     return check_semantic_expression(node->children[0], t) && check_semantic_expression(node->children[2], t);
    // }
    // if(node->id == "RelationalExpression"){
    //     return check_semantic_expression(node->children[0], t) && check_semantic_expression(node->children[2], t);
    // }
    // if(node->id == "ShiftExpression"){
    //     return check_semantic_expression(node->children[0], t) && check_semantic_expression(node->children[2], t);
    // }
    // if(node->id == "AdditiveExpression"){
    //     return check_semantic_expression(node->children[0], t) && check_semantic_expression(node->children[2], t);
    // }
    // if(node->id == "MultiplicativeExpression"){
    //     return check_semantic_expression(node->children[0], t) && check_semantic_expression(node->children[2], t);
    // }
    // if(node->id == "UnaryExpression"){
    //     return check_semantic_expression(node->children[1], t);
    // }
    // if(node->id == "PreIncrementExpression"){
    //     return check_semantic_expression(node->children[1], t);
    // }
    // if(node->id == "PreDecrementExpression"){
    //     return check_semantic_expression(node->children[1], t);
    // }
    // if(node->id == "UnaryExpressionNotPlusMinus"){
    //     return check_semantic_expression(node->children[1], t);
    // }
    // if(node->id == "PostIncrementExpression"){
    //     return check_semantic_expression(node->children[0], t);
    // }
    // if(node->id == "PostDecrementExpression"){
    //     return check_semantic_expression(node->children[0], t);
    // }
    node->count = counter++;
    symtab *a = NULL;
    if(node->isBlock){
        a = new symtab(node->count, currentSymTableId);
        cout<<"Symbol Table Created with Parent ID "<<currentSymTableId<<" and ID "<<node->count<<" and nodeID "<<node->id<<" "<<node->isBlock<<endl;
        currentSymTableId = node->count;
        symTables[currentSymTableId] = *a;
    }
    for(int i=0;i<node->children.size();i++) {
        traverse_semantics(node->children[i], counter);
    }
    if(a){
        if(node->id != "MethodHeader")
            currentSymTableId = a->parentID; 
    }

}

void check_semantics(){
    //int counter = 0;
    //traverse_semantics(root, counter);
    for(auto i = symTables.begin(); i != symTables.end(); i++){
        symTab_csv(&i->second);
    }
}

int main(int argc, char**argv){
    if(argc==1){
        cout<<"No input file specified"<<endl;
        return 0;
    }
    
    int input_index = 0;
    int output_index = 0;
    bool flag_help=false;
    int t = 1;

    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg.find("--output=") == 0) {
            argv[i] = argv[i]+9;
            output_index = i;
            t++;
            continue;
        }
        else if(arg.find("--input=") == 0){
            argv[i] = argv[i]+8;
            input_index = i;
            t++;
            continue;
        }
        else if(arg.find("--help") == 0){
            flag_help = true;
            t++;
            continue;
        }
        else if(arg.find("--verbose")==0){
            flag_verbose=true;
            t++;
            continue;
        }
        else if(arg.find("--dot") == 0){
            isDot = true;
            t++;
            continue;
        }
        if(i == t && !input_index)
            input_index = i;
        if(i == t+1 && !output_index)
            output_index = i;
    }

    if(flag_help){
        cout<<endl<<"Usage: ./myASTGenerator [options] [input_file]}"<<endl;
        cout<<"Generates a Dot file for the AST representation for an input JAVA file"<<endl<<endl;
        cout<<"Debugging : "<<endl;
        cout<<"\t--verbose\tsupports debugging of the input file"<<endl<<endl;
        cout<<"Files : "<<endl;
        cout<<"\t--output=FILE\tspecify output filename"<<endl;
        cout<<"\t--input=FILE\tspecify input filename"<<endl<<endl;
        cout<<"Miscellaneous : "<<endl;
        cout<<"\t--help\t\tproduces this help message"<<endl<<endl;
        cout<<"By default the first argument will be treated as the input file and the second argument as the output file unless specified otherwise.\nIf there is only one argument, then it will be taken as the input file and the default name of the output file will be parse_tree.dot."<<endl<<endl;
        return 0;
    }

    if (argc > 1) {
        if(input_index)
            yyin = fopen(argv[input_index], "r");
        if (!yyin) {
            fprintf(stderr, "error: could not open file %s\n", argv[input_index]);
            return 1;
        }
    }
    else {
        yyin = stdin;
    }
    if(!isDot){
        initializeSymTable();
    }
    yyparse();
    if(root){
        if(isDot){
            if(output_index)
                print_dot(argv[output_index]);
            else 
                print_dot("parse_tree.dot");
        }
        else{
            check_semantics();
        }
    }
    else printf("Error in generating the parse tree\nAborting...\n");
    return 0;
}
