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

vector<TYPE>vt;

vector<string> enum_types = {"BIN", "OCT", "HEX_FLOAT", "STRING", "HEX", "BOOL", "VOID", "FUNCTION", "CLASS", "INTERFACE", "ENUM", "UNION", "TYPEDEF", "VOID", "VAR", "_NULL", "BYTE", "SHORT", "CHAR", "INT", "LONG", "FLOAT", "DOUBLE"};

set<TYPE>add_set = {INT, BIN, FLOAT, OCT, HEX_FLOAT, HEX, CHAR, LONG, DOUBLE};

int currentSymTableId = -1;
int symTablescount = 0;
bool isDot = false;
TYPE t = VOID;

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

#line 114 "parser.tab.c"

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
#line 47 "parser.y"

    #include "Node.h"

#line 161 "parser.tab.c"

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
#line 51 "parser.y"

    char* str;
    Node* node;

#line 309 "parser.tab.c"

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
#define YYLAST   3814

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  132
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  142
/* YYNRULES -- Number of rules.  */
#define YYNRULES  379
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  661

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
       0,    75,    75,    79,    90,    94,    99,   103,   112,   116,
     121,   125,   129,   133,   137,   142,   146,   152,   156,   161,
     165,   169,   173,   182,   198,   211,   215,   220,   237,   255,
     262,   268,   274,   278,   284,   289,   294,   298,   305,   309,
     316,   324,   328,   333,   342,   352,   356,   360,   366,   370,
     377,   381,   385,   389,   393,   397,   401,   405,   409,   413,
     418,   422,   428,   448,   467,   486,   504,   523,   541,   559,
     577,   583,   590,   597,   601,   609,   618,   626,   630,   637,
     641,   645,   650,   654,   659,   677,   692,   696,   711,   715,
     729,   742,   758,   762,   767,   784,   792,   799,   806,   812,
     820,   827,   834,   840,   847,   861,   874,   888,   892,   900,
     908,   918,   925,   929,   937,   942,   947,   957,   964,   970,
     976,   984,   992,  1001,  1006,  1013,  1019,  1030,  1038,  1045,
    1052,  1061,  1069,  1076,  1083,  1090,  1096,  1105,  1112,  1120,
    1127,  1135,  1142,  1149,  1156,  1159,  1165,  1166,  1174,  1182,
    1189,  1196,  1202,  1207,  1213,  1220,  1226,  1234,  1244,  1250,
    1260,  1268,  1276,  1278,  1282,  1287,  1294,  1301,  1321,  1336,
    1346,  1351,  1363,  1369,  1379,  1383,  1392,  1396,  1402,  1411,
    1418,  1427,  1431,  1437,  1439,  1441,  1443,  1445,  1447,  1452,
    1454,  1456,  1458,  1460,  1465,  1467,  1469,  1471,  1473,  1475,
    1477,  1479,  1481,  1486,  1492,  1503,  1513,  1523,  1525,  1527,
    1529,  1531,  1533,  1535,  1540,  1557,  1572,  1586,  1592,  1607,
    1622,  1622,  1623,  1623,  1626,  1640,  1655,  1670,  1686,  1701,
    1717,  1733,  1754,  1768,  1783,  1798,  1814,  1829,  1845,  1861,
    1880,  1897,  1901,  1908,  1914,  1927,  1928,  1936,  1941,  1948,
    1954,  1962,  1968,  1976,  1981,  1991,  2001,  2008,  2015,  2023,
    2028,  2035,  2045,  2056,  2060,  2067,  2068,  2069,  2070,  2071,
    2072,  2073,  2074,  2075,  2076,  2077,  2078,  2079,  2080,  2087,
    2091,  2095,  2099,  2103,  2111,  2124,  2126,  2136,  2144,  2151,
    2158,  2164,  2171,  2182,  2184,  2192,  2210,  2216,  2223,  2229,
    2238,  2245,  2253,  2262,  2272,  2281,  2294,  2309,  2327,  2329,
    2331,  2333,  2338,  2354,  2368,  2370,  2372,  2377,  2382,  2387,
    2402,  2417,  2419,  2431,  2443,  2448,  2456,  2466,  2474,  2486,
    2490,  2498,  2506,  2517,  2521,  2529,  2540,  2544,  2558,  2572,
    2589,  2593,  2608,  2622,  2636,  2650,  2660,  2664,  2678,  2695,
    2699,  2716,  2720,  2737,  2741,  2758,  2762,  2779,  2783,  2800,
    2804,  2828,  2832,  2839,  2856,  2860,  2864,  2871,  2875,  2879,
    2883,  2887,  2891,  2895,  2899,  2903,  2907,  2911,  2915,  2922
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
  "VariableInitializerList", "Block", "BlockStatements", "BlockStatement",
  "LocalVariableDeclarationStatement", "LocalVariableDeclaration",
  "LocalVariableType", "Statement", "StatementNoShortIf",
  "StatementWithoutTrailingSubstatement", "EmptyStatement",
  "LabeledStatement", "LabeledStatementNoShortIf", "ExpressionStatement",
  "StatementExpression", "IfThenStatement", "IfThenElseStatement",
  "IfThenElseStatementNoShortIf", "invoke_paren", "WhileStatement",
  "WhileStatementNoShortIf", "ForStatement", "ForStatementNoShortIf",
  "BasicForStatement", "BasicForStatementNoShortIf",
  "EnhancedForStatementNoShortIf", "ForInit", "ForUpdate",
  "EnhancedForStatement", "StatementExpressionList", "BreakStatement",
  "ContinueStatement", "ReturnStatement", "ThrowStatement",
  "SynchronizedStatement", "TryStatement", "Catches", "CatchClause",
  "Finally", "Primary", "PrimaryNoNewArray",
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

#define YYPACT_NINF (-439)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-367)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     585,  -439,   -65,   -30,  -439,   -25,    -8,  -439,   -25,  -439,
    -439,  -439,  -439,  -439,  -439,  -439,  -439,   120,  -439,   762,
     354,   762,  -439,  -439,  -439,  -439,   940,  -439,  -439,  -439,
    -439,  -439,    16,    13,  -439,   190,  -439,  -439,    17,   219,
    -439,   354,  -439,  -439,   762,   354,    27,    33,    70,  -439,
     -25,   -25,    67,  2637,    25,   113,  -439,   -25,    80,   128,
    -439,  -439,    74,   -25,  1257,   172,  -439,  -439,   183,   354,
      16,    13,    17,  -439,  -439,   178,  -439,  -439,   200,  -439,
    -439,  -439,  -439,  -439,  -439,  -439,  -439,  -439,   257,   277,
     280,   268,  -439,  -439,  -439,  -439,  -439,   270,   179,   276,
    2739,  2497,  -439,  -439,  -439,  -439,   204,  -439,  -439,    22,
     113,  -439,  -439,   200,   248,  -439,  2637,    98,   284,   147,
    -439,  -439,   306,  -439,  -439,  -439,  2739,  -439,   309,  2572,
    -439,  -439,  -439,   -25,  -439,    25,   113,  -439,   128,  -439,
     172,  -439,   -25,  1746,  -439,   283,    18,   283,    82,  -439,
      37,    18,   312,   315,   320,   174,   277,   280,    22,  -439,
    -439,  -439,  -439,  -439,   -25,  1801,   332,  -439,  -439,  3105,
    -439,  2637,  -439,   337,  -439,  -439,   126,   339,  -439,  -439,
    -439,  -439,  -439,   113,  -439,  -439,  -439,  -439,  -439,   -36,
     -21,   213,   343,   343,   427,  1411,   336,   346,  -439,  2708,
     257,   343,  -439,  3645,  3645,   362,  -439,  -439,  -439,  -439,
    -439,  -439,  -439,  -439,  -439,  -439,  -439,  -439,  3645,  -439,
    -439,  -439,   212,  -439,  1924,  -439,  -439,   348,   361,  -439,
    -439,  -439,  -439,  -439,   352,  -439,  -439,  -439,  -439,  -439,
    -439,  -439,  -439,  -439,  -439,  -439,  -439,   341,   355,   133,
    -439,   744,   150,   946,   161,   199,   252,  -439,  -439,  -439,
    1328,  -439,   630,   363,  -439,  -439,   361,  3064,   365,  -439,
    -439,  -439,  -439,   427,  -439,   361,   -55,  -439,    18,   279,
      18,   332,  -439,  -439,   360,    64,   371,  -439,  1979,  2102,
    -439,  3645,  3645,  3645,  3645,  2619,   113,   857,  -439,    48,
    -439,   161,  -439,  -439,  -439,  -439,  -439,  -439,  -439,   287,
     342,   314,   137,   347,   412,   414,   416,   401,   233,  -439,
    -439,  -439,  -439,  -439,  -439,   377,  -439,  -439,  -439,   375,
    -439,   378,  -439,   361,  -439,  2278,  3645,   379,   385,   214,
    -439,   380,   400,  3645,  -439,   382,   193,  3645,    42,  -439,
    -439,  -439,  -439,  2333,   388,  3153,  2927,  -439,  -439,  -439,
    -439,   391,  -439,   405,  3645,  -439,  -439,  -439,  -439,  -439,
    -439,  -439,  -439,  -439,  -439,  -439,  -439,  -439,  -439,  3645,
    -439,    52,  -439,  -439,  3016,  -439,  -439,  -439,  -439,   361,
     398,  -439,   648,  -439,  -439,  -439,  -439,   -25,  3195,  3243,
    -439,  2157,  -439,  -439,  -439,  -439,  -439,   187,  1561,   394,
    -439,  3645,   113,  3645,  3645,  3645,  3645,  3645,  3645,  3645,
    3645,  3645,   427,  3645,  3645,  3645,  3645,  3645,  3645,  3645,
    3645,  3645,  3645,  3645,  3645,  -439,  -439,  -439,   391,  2749,
     418,  -439,   402,   408,   411,  2975,   379,  -439,   250,  3285,
     379,   250,  -439,   409,   415,  -439,   413,   257,   193,  -439,
    -439,   417,  -439,  -439,  -439,    73,   421,   419,   422,  -439,
    -439,  -439,  -439,   216,   398,  -439,  -439,   425,    99,   429,
     121,  -439,  3645,   428,   234,  2975,   239,  3693,  -439,  -439,
    -439,  -439,  -439,   287,   287,   342,   342,   342,   268,  -439,
     314,   314,   314,   314,   137,   137,   347,   412,   414,   416,
     401,   432,  1777,   431,  3645,  2797,  3665,  2449,  -439,   433,
    -439,   435,   438,  -439,  -439,   157,   435,  -439,  3333,   257,
     648,  -439,  -439,  -439,  2333,  -439,  -439,  3375,  -439,  -439,
    3064,  -439,   434,  -439,   440,  -439,  3645,  3693,  -439,  3645,
    2333,   448,   408,  1955,   452,  2133,   450,  -439,   343,   343,
     343,   437,  -439,   561,   562,  -439,  -439,  -439,  -439,  -439,
    -439,  -439,  -439,  -439,  -439,   170,  -439,   458,  -439,  -439,
     171,  -439,  -439,  -439,  -439,  -439,  -439,  -439,  2333,  2333,
     459,  2333,  2333,   461,  3423,  2305,  3645,  3645,  2449,  2333,
    -439,   257,  -439,  -439,  -439,  2333,  -439,  -439,  2333,  2333,
     462,  2838,   479,   460,   464,   467,  -439,  -439,  -439,  -439,
    -439,  -439,  2333,  3465,   465,  3645,  2886,  2449,  2449,  -439,
    2449,   471,  3513,   472,  3555,   468,   580,  -439,  -439,  2449,
    2449,   476,  2449,  2449,   477,  3603,  2449,  -439,  -439,  2449,
    -439,  -439,  2449,  2449,   478,  -439,  -439,  -439,  -439,  2449,
    -439
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
       0,     0,     0,     0,     0,     0,     0,     0,   272,     0,
       0,     0,   182,     0,     0,    27,   265,   266,   267,   268,
     269,   270,   271,   273,   274,   275,   276,   277,     0,   172,
     203,   181,   364,   194,     0,   174,   176,     0,     0,   177,
     183,   195,   184,   196,     0,   185,   186,   187,   188,   220,
     221,   197,   198,   199,   201,   200,   202,   308,   263,   279,
     264,   280,   281,   282,     0,   210,   211,   208,   209,   207,
       0,   103,     0,     0,   101,    85,     0,     0,     0,    97,
      22,    24,    23,     0,   122,     0,     0,   107,   100,     0,
      96,     0,   118,   112,   111,     0,   272,   123,     0,     0,
     119,     0,     0,     0,     0,     0,   151,   309,   279,     0,
     281,   321,   310,   311,   329,   314,   315,   318,   324,   333,
     336,   340,   346,   349,   351,   353,   355,   357,   359,   361,
     379,   362,   285,   140,   137,     0,   147,   138,    62,     0,
     247,     0,   249,     0,   217,     0,     0,     0,     0,    19,
     251,     0,     0,     0,   253,     0,     0,     0,   309,   280,
     282,   319,   320,     0,     0,     0,     0,   173,   175,   178,
      90,   180,   206,     0,     0,   312,   313,   367,   368,   369,
     370,   371,   372,   376,   377,   378,   373,   374,   375,     0,
     105,     0,   106,    87,     0,    89,    93,    92,    91,     0,
     109,   121,     0,    99,    84,    95,   117,     0,     0,     0,
     125,     0,   124,   316,   317,   323,   322,     0,   309,     0,
     149,     0,   150,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   136,   248,   250,   179,     0,
     242,   245,     0,   241,     0,     0,   287,   293,     0,     0,
     290,     0,   252,   299,     0,   254,     0,     0,   256,   259,
     257,     0,   204,   278,   300,     0,     0,   298,     0,   363,
     104,   169,   170,     0,   110,   108,   113,     0,     0,     0,
       0,   126,     0,     0,     0,     0,     0,   278,   148,   286,
     330,   331,   332,   334,   335,   337,   338,   339,     0,   345,
     341,   343,   342,   344,   347,   348,   350,   352,   354,   356,
     358,     0,     0,     0,     0,     0,     0,     0,   296,     0,
     294,   289,     0,   288,   283,     0,   291,   292,     0,     0,
       0,   262,   260,   258,     0,   301,   306,     0,   307,   168,
       0,   130,     0,   128,     0,   325,     0,     0,   327,     0,
       0,     0,   243,     0,     0,     0,     0,   246,     0,     0,
       0,    27,   214,     0,   183,   190,   191,   192,   193,   222,
     223,   295,   297,   284,   304,     0,   255,     0,   218,   302,
       0,   171,   129,   127,   326,   328,   360,   224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     305,     0,   303,   225,   226,     0,   244,   228,     0,     0,
       0,     0,   242,     0,     0,     0,   205,   215,   261,   227,
     229,   230,     0,     0,     0,     0,     0,     0,     0,   231,
       0,     0,     0,     0,     0,     0,     0,   219,   232,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   234,     0,
     240,   236,     0,     0,     0,   216,   235,   237,   238,     0,
     239
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -439,  -439,   -45,  -181,  -439,  -439,  -439,   180,   -39,  -150,
     -10,  -439,    -5,    -3,  -439,  -439,   583,    49,  -439,    60,
    -439,  -439,   228,   -27,     8,  -439,  -439,  -439,   531,   -13,
     550,   -50,   492,   -19,  -439,   -24,  -136,   350,  -243,  -368,
    -439,   -17,  -439,     0,   351,  -369,  -129,  -439,  -439,  -439,
    -439,   509,  -128,  -439,  -439,   543,     4,   -18,  -439,   442,
    -439,   551,   -11,  -439,   495,  -439,  -439,   -88,  -439,   -81,
    -134,  -209,  -439,  -333,   436,  1096,  -156,  -317,  -439,  -439,
    -439,  -439,  -329,  -439,  -439,  -439,  -192,  -439,  -439,  -439,
    -439,  -439,  -439,  -439,    39,  -378,  -439,  -325,  -439,  -439,
    -439,  -439,  -439,  -439,  -439,   168,   173,  -439,  -439,   -77,
    -322,  -439,   293,  -101,  -277,  1134,    94,  1168,   238,   406,
     566,  -176,   721,   842,  -438,  -439,    36,    31,   -73,    32,
     209,   211,   217,   210,   218,  -439,    96,  -439,   707,  -439,
    -439,  1032
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
      31,    65,    66,   129,   130,   131,   132,   386,   473,   223,
     224,   225,   226,   227,   228,   229,   563,   230,   231,   232,
     565,   233,   234,   235,   236,   566,   335,   237,   567,   238,
     568,   239,   569,   570,   442,   551,   240,   552,   241,   242,
     243,   244,   245,   246,   458,   459,   460,   247,   248,   298,
     299,   250,   446,   447,   448,   251,   300,   253,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   259,   260,
     379,   322
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,   336,   440,    39,   111,   112,   441,   144,    90,   347,
     443,    73,    76,   337,   283,   358,   472,   264,    76,    90,
     137,   279,   269,   475,    76,   163,   100,   351,   352,   281,
     282,   289,   390,   465,    49,    50,    63,   126,   290,    57,
     127,   110,    51,    32,   338,    75,    75,   128,    98,   548,
      99,    51,    75,   124,   134,   157,    90,   136,    75,    98,
     168,   141,   451,   121,   170,   164,   249,   391,    41,   164,
      45,    90,   329,   392,   100,   139,   478,   480,    33,    42,
     358,   157,   160,    34,    90,   184,   185,   331,   249,   100,
     151,   330,   361,    69,    76,    98,    98,    99,    99,   173,
      38,   177,   126,    76,    42,   127,   332,   267,    49,   585,
     275,    98,   128,    99,   407,   403,   404,   405,   406,   346,
      40,    98,   183,   182,    98,    73,    90,   525,    75,   187,
     484,   486,   188,   328,    49,    70,    58,    75,   222,    52,
      64,    71,   186,   263,   100,   165,   474,   249,    52,   393,
      98,   395,   160,   396,   401,    73,   278,   280,   325,    75,
     222,   577,   268,   355,   122,   422,    98,   411,    99,   521,
     412,    68,   581,   526,   470,   590,   413,   593,    72,    80,
     392,    81,   123,   441,    82,   398,    98,   557,   114,   339,
      83,    79,   358,   342,   273,   535,    84,   438,   348,   348,
     564,   413,   456,    85,   115,    86,   575,   116,   117,   265,
     266,   249,   249,    87,   457,   580,   610,   275,    80,   222,
      81,   542,   172,    82,   441,   116,   441,   413,   389,    83,
     423,   424,   425,   426,   114,    84,    52,   252,   490,   491,
     492,   498,    85,   544,    86,   631,   410,   476,    43,   413,
     324,    58,    87,   116,   641,  -213,   644,    98,   249,   252,
    -213,  -213,   612,   365,   366,   441,   441,   654,    98,    43,
     443,   175,  -212,    43,   116,   176,   249,  -212,  -212,   573,
     202,   564,    34,   222,   222,   413,   348,   348,   348,   348,
     408,   123,   600,   602,   441,    64,   274,    43,   413,   413,
     133,  -310,  -310,   441,   154,   441,   545,    68,    68,   482,
     564,   564,   483,   564,  -309,  -309,   441,    61,   252,    62,
     -19,    34,   564,   564,   249,   564,   564,   143,   142,   564,
     222,   161,   564,   355,   433,   564,   564,   356,   434,   445,
     539,    68,   564,    68,   540,   520,    67,   275,    68,   520,
     500,   501,   502,   503,  -311,  -311,   546,     1,    73,   522,
     523,   547,   488,   527,   522,     2,   595,   596,   597,   169,
     584,    52,     3,   384,     4,   522,   531,   414,   415,   416,
     143,   254,   252,   252,     6,   145,     7,    98,   147,     9,
      10,    11,    75,   152,    12,   153,   222,   155,    13,   419,
     420,   421,    14,   254,   261,    15,   394,   266,   174,   348,
     348,   348,   348,   348,   348,   348,   348,    98,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   252,
     417,   418,    80,   178,    81,   249,   179,    82,   270,   249,
     249,   271,   616,    83,   427,   428,   272,   252,   576,    84,
     495,   496,   497,   493,   494,   165,    85,   249,    86,   504,
     505,   323,   254,   327,   334,   342,    87,   343,   353,   360,
     363,   636,   637,   249,   638,   359,   249,   348,   249,   362,
     364,    16,   348,   647,   648,   275,   650,   651,   397,   382,
     655,   388,   399,   656,   429,   252,   657,   658,   430,   431,
     432,   435,   436,   660,   445,   437,   449,   452,   453,   455,
     463,   249,   249,   467,   249,   249,   487,   249,   249,   266,
     618,   249,   249,   268,   514,    98,   254,   254,   249,   515,
     528,   249,   249,   517,   530,    34,   516,   529,   549,   534,
     537,   348,   348,   598,   348,   249,   249,   536,   538,   255,
     249,   249,   541,   249,   518,   249,   543,   249,   553,   571,
     522,   582,   249,   249,   572,   249,   249,   583,   249,   249,
     588,   255,   249,   254,   591,   249,   249,   594,   599,  -189,
     601,   605,   249,   608,   622,   625,   627,   626,     1,   628,
     222,   254,   632,   639,   642,   645,     2,   646,   649,   652,
     659,   135,   499,     3,    44,     4,   252,   113,   171,   158,
     252,   252,     5,   381,   138,     6,   383,     7,   326,     8,
       9,    10,    11,   140,   181,    12,   532,   333,   252,    13,
     255,   533,   450,    14,   613,    80,    15,    81,   506,   254,
      82,   507,   509,     0,   252,   586,    83,   252,   508,   252,
     273,   510,    84,    80,     0,    81,     0,     0,    82,    85,
       0,    86,     0,     0,    83,     0,     0,     0,   273,    87,
      84,     0,     0,     0,     0,     0,     0,    85,     0,    86,
       0,     0,   252,   252,     0,   252,   252,    87,   252,   252,
       0,     0,   252,   252,   255,   255,     0,     0,     0,   252,
       0,     0,   252,   252,     0,     0,     0,     0,     0,   256,
       0,     0,    16,     0,     0,     0,   252,   252,     0,     0,
       0,   252,   252,     0,   252,     0,   252,     0,   252,     0,
       0,   256,     0,   252,   252,     0,   252,   252,    34,   252,
     252,   255,     0,   252,     0,     0,   252,   252,     0,     0,
     254,     0,   380,   252,   254,   254,    34,     0,     0,   255,
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,   254,     2,     0,     0,     0,     0,     0,     0,
       3,     0,     4,     0,     0,     0,     0,     0,   254,     5,
     256,   254,     6,   254,     7,     0,     0,     9,    10,    11,
       0,     0,    12,     0,     0,     0,    13,   255,     0,     0,
      14,     0,     0,    15,  -365,  -365,  -365,  -365,  -365,  -365,
    -365,  -365,  -365,  -365,  -365,  -365,   254,   254,     0,   254,
     254,     0,   254,   254,     0,     0,   254,   254,     0,     0,
       0,     0,     0,   254,     0,     0,   254,   254,     0,     0,
       0,     0,     0,     0,   256,   256,     0,     0,     0,     0,
     254,   254,     0,     0,   257,   254,   254,     0,   254,     0,
     254,     0,   254,     0,     0,     0,   321,   254,   254,     0,
     254,   254,     0,   254,   254,     0,   257,   254,     0,    16,
     254,   254,     0,     0,     0,     0,     0,   254,     0,     0,
       0,   256,   321,     0,     0,     0,   321,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,   256,
       0,     0,   255,   255,     0,   321,     0,  -364,  -364,  -364,
    -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,     0,
     255,     0,     0,     1,     0,   257,     0,     0,     0,     0,
       0,    46,     0,     0,     0,     0,   255,     0,    47,   255,
       4,   255,     0,     0,     0,     0,     0,   256,     0,     0,
      48,     0,     7,     0,   321,     9,    10,    11,   355,     0,
      12,     0,   411,     0,    13,   258,    68,     0,    14,     0,
       0,    15,     0,     0,   255,   255,     0,   255,   255,     0,
     255,   255,   321,     0,   255,   255,     0,   258,     0,   257,
     257,   255,     0,     0,   255,   255,  -366,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,   255,   255,
       0,     0,     0,   255,   255,     0,   255,     0,   255,     0,
     255,     0,     0,   321,     0,   255,   255,     0,   255,   255,
     321,   255,   255,     0,   321,   255,   257,     0,   255,   255,
       0,     0,   321,   321,     0,   255,   258,     0,     0,     0,
       0,   321,     0,     0,   257,     0,     0,     0,   256,     0,
       0,     0,   256,   256,     0,     0,   321,     0,     0,     0,
       0,   321,     0,     0,     0,     0,     0,     0,     0,     0,
     256,     0,     0,     0,     0,   321,   321,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   256,     0,   321,   256,
     321,   256,   257,     0,     0,     0,     0,     0,     0,     0,
     258,   258,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   321,     0,     0,     0,     0,   321,     0,     0,     0,
       0,     0,   321,     0,   256,   256,   321,   256,   256,     0,
     256,   256,     0,     0,   256,   256,     0,     0,     0,     0,
       0,   256,     0,     0,   256,   256,     0,   258,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,   256,
       0,     0,   321,   256,   256,   258,   256,     0,   256,     0,
     256,     0,     0,     0,     0,   256,   256,     0,   256,   256,
       0,   256,   256,     0,     0,   256,     0,     0,   256,   256,
       0,   321,   321,     0,     0,   256,     0,   341,     0,     0,
       0,   345,     0,   257,     0,   321,     0,   257,   257,     0,
       0,     0,     0,   258,   321,     0,     0,   321,     0,     0,
     354,     0,     0,     0,     0,   257,     0,     0,     0,     0,
       1,     0,    80,     0,    81,     0,     0,    82,     0,     0,
       0,   257,     0,    83,   257,     0,   257,     4,     0,    84,
       0,     0,     0,     0,     0,     0,    85,     0,    86,     7,
       0,     0,     9,    10,    11,     0,    87,    12,     0,   387,
       0,    13,     0,   321,   321,    14,     0,    89,    15,   257,
     257,     0,   257,   257,     0,   257,   257,     0,   321,   257,
     257,     0,     0,     0,     0,     0,   257,   409,     0,   257,
     257,     0,   321,   321,     0,     0,     0,   349,   349,     0,
       0,     0,     0,   257,   257,     0,     0,     0,   257,   257,
       0,   257,     0,   257,   258,   257,     0,     0,   258,   258,
     257,   257,     0,   257,   257,    34,   257,   257,   444,     0,
     257,   350,   350,   257,   257,   454,   258,     0,     0,   461,
     257,   125,     0,     0,     0,     0,     0,     0,   466,     0,
       0,     0,   258,     0,     0,   258,   468,   258,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
       0,   469,     0,     0,     0,     0,   387,     0,     0,     0,
       0,     0,     0,     0,     0,   349,   349,   349,   349,     0,
     258,   258,     0,   258,   258,     0,   258,   258,     0,     0,
     258,   258,     0,   466,   194,   489,     0,   258,     0,   462,
     258,   258,     0,   196,     0,     0,   198,     0,     0,   350,
     350,   350,   350,     0,   258,   258,   511,     0,     0,   258,
     258,   513,   258,     0,   258,     0,   258,   519,     0,     0,
       0,   258,   258,     0,   258,   258,     0,   258,   258,     0,
       0,   258,     0,     0,   258,   258,     0,     0,     0,   291,
     292,   258,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   293,     0,   203,   204,   294,     0,   466,     0,    34,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   295,     0,     0,     0,     0,     0,   340,     0,
       0,     0,     0,     0,     0,     0,   554,   556,   349,   349,
     349,   349,   349,   349,   349,   349,     0,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,     0,     0,
       0,     0,   387,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   350,   350,   350,   350,   350,   350,   350,   350,
       0,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   562,     0,     0,   349,     0,     0,     0,
       0,   349,     0,     0,     0,     0,     0,     0,   614,   615,
     578,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,  -364,
    -364,  -364,  -364,   624,     0,     0,   587,     0,     0,     0,
     350,     0,     0,     0,     0,   350,     0,   633,   635,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     349,   349,   355,   349,   603,   604,   485,   606,   607,     0,
      68,     0,     0,     0,   462,   617,     0,     0,     0,     0,
       0,   619,     0,     0,   620,   621,     0,     0,     0,     0,
       0,     0,     0,     0,   350,   350,     0,   350,   629,     0,
       0,     0,     0,   562,   578,     0,   587,     0,     0,     0,
       0,     0,     0,     0,     0,   603,   604,     0,   606,   607,
       0,     0,   617,     0,     0,   619,     0,     0,   620,   621,
       0,    80,   189,    81,     0,   629,    82,     0,     0,   190,
       0,     0,    83,     0,     0,     0,   191,     0,    84,   192,
       0,   193,     0,     0,     0,    85,     0,    86,     0,   194,
       0,     0,     0,     0,   195,    87,     0,     0,   196,     0,
     197,   198,   199,     0,     0,   200,     0,     0,   201,     0,
       0,     0,     0,     0,     0,     0,    80,   189,    81,     0,
     194,    82,     0,   202,   190,     0,     0,    83,     0,   196,
       0,   191,   198,    84,   192,     0,   193,     0,     0,     0,
      85,     0,    86,     0,   194,     0,     0,     0,     0,   195,
      87,     0,     0,   285,     0,   197,   286,   199,   203,   204,
     200,     0,     0,   201,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   202,   143,
     219,     0,     0,   220,     0,     0,     0,     0,     0,   203,
     204,     0,     0,     0,     0,    34,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   550,
       0,     0,     0,   203,   204,     0,     0,     0,     0,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,     0,   143,   287,     0,     0,   220,    80,
     189,    81,     0,     0,    82,     0,     0,   190,     0,     0,
      83,     0,     0,     0,   191,     0,    84,   192,     0,   193,
       0,     0,     0,    85,     0,    86,     0,   194,     0,     0,
       0,     0,   195,    87,     0,     0,   196,     0,   197,   198,
     199,     0,     0,   200,     0,     0,   201,     0,     0,     0,
       0,     0,     0,     0,    80,   189,    81,     0,   194,    82,
       0,   202,   190,     0,     0,    83,     0,   196,     0,   191,
     198,    84,   192,     0,   193,     0,     0,     0,    85,     0,
      86,     0,   194,     0,     0,     0,     0,   195,    87,     0,
       0,   196,     0,   197,   198,   199,   203,   204,   200,     0,
       0,   201,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   202,   143,   357,     0,
       0,   220,     0,     0,     0,     0,     0,   203,   204,     0,
       0,     0,     0,    34,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   589,     0,     0,
       0,   203,   204,     0,     0,     0,     0,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,     0,   143,   400,     0,     0,   220,    80,   189,    81,
       0,     0,    82,     0,     0,   190,     0,     0,    83,     0,
       0,     0,   191,     0,    84,   192,     0,   193,     0,     0,
       0,    85,     0,    86,     0,   194,     0,     0,     0,     0,
     195,    87,     0,     0,   196,     0,   197,   198,   199,     0,
       0,   200,     0,     0,   201,     0,     0,     0,     0,     0,
       0,     0,    80,   189,    81,     0,   194,    82,     0,   202,
     190,     0,     0,    83,     0,   196,     0,   191,   198,    84,
     192,     0,   193,     0,     0,     0,    85,     0,    86,     0,
     194,     0,     0,     0,     0,   195,    87,     0,     0,   196,
       0,   197,   198,   199,   203,   204,   200,     0,     0,   201,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   202,   143,   402,     0,     0,   220,
       0,     0,     0,     0,     0,   203,   204,     0,     0,     0,
       0,    34,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   592,     0,     0,     0,   203,
     204,     0,     0,     0,     0,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,     0,
     143,   481,     0,    80,   220,    81,     0,     0,    82,     0,
       0,     0,     0,     0,    83,     0,     0,     0,   191,     0,
      84,     0,     0,     0,     0,     0,     0,    85,     0,    86,
      80,   194,    81,     0,     0,    82,     0,    87,     0,     0,
     196,    83,     0,   198,     0,   191,     0,    84,     0,     0,
       0,     0,     0,     0,    85,     0,    86,     0,   194,   189,
       0,     0,     0,     0,    87,   202,   190,   196,     0,     0,
     198,     0,     0,     0,     0,     0,   192,     0,   193,     0,
       0,     0,     0,     0,     0,     0,   194,     0,     0,     0,
       0,   195,   202,     0,     0,   196,     0,   197,   198,   199,
     203,   204,   200,     0,     0,   201,    34,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
       0,     0,     0,     0,     0,   439,     0,   203,   204,     0,
       0,     0,     0,    34,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,     0,     0,     0,
       0,     0,   611,     0,     0,   203,   204,     0,     0,     0,
       0,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   189,   143,     0,     0,     0,
     220,     0,   190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   558,     0,   559,     0,     0,     0,     0,     0,
       0,     0,   194,     0,     0,     0,     0,   195,     0,     0,
       0,   196,     0,   197,   198,   199,     0,     0,   200,     0,
       1,   560,    80,     0,    81,     0,     0,    82,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     4,     0,    84,
       0,     0,     0,     0,     0,     0,    85,     0,    86,     7,
       0,     0,     9,    10,    11,     0,    87,    88,     0,     0,
       0,    13,     0,     0,     0,    14,     0,    89,    15,     0,
       0,   203,   204,     0,     0,     0,     0,   561,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,     0,   143,     0,     0,     1,   220,    80,     0,    81,
       0,     0,    82,     0,     0,     0,     0,     0,    83,     0,
       0,     0,     4,     0,    84,     0,     0,     0,     0,     0,
       0,    85,     0,    86,     7,    34,     0,     9,    10,    11,
       0,    87,    12,     0,     0,     0,    13,     0,     0,     0,
      14,   159,    89,    15,    80,     0,    81,     0,     0,    82,
       0,     0,     0,     0,     0,    83,     0,     0,     0,     0,
       1,    84,    80,     0,    81,     0,     0,    82,    85,     0,
      86,     0,   194,    83,     0,     0,     0,     4,    87,    84,
       0,   196,     0,     0,   198,     0,    85,     0,    86,     7,
       0,     0,     9,    10,    11,     0,    87,    88,     0,     0,
      34,    13,     0,     0,     0,    14,     0,    89,    15,     0,
       0,     0,     0,     0,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   291,   292,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   293,
       0,   203,   204,   294,     0,     0,     0,    34,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     295,   194,     1,     0,    80,    34,    81,     0,     0,    82,
     196,     0,     0,   198,     0,    83,     0,     0,     0,     4,
       0,    84,     0,     0,     0,     0,     0,     0,    85,     0,
      86,     7,     0,     0,     9,    10,    11,     0,    87,    12,
       0,     0,   194,    13,     0,     0,     0,    14,     0,   156,
      15,   196,     0,     0,   198,     0,   291,   292,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   293,     0,
     203,   204,   294,     0,     0,     0,    34,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   295,
     194,     0,     0,     0,     0,   344,     0,   291,   292,   196,
       0,     0,   198,     0,     0,     0,     0,    34,     0,   293,
       0,   203,   204,   294,     0,     0,     0,    34,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     295,   194,     0,     0,     0,     0,   512,     0,     0,     0,
     196,     0,     0,   198,     0,   291,   292,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,     0,   203,
     204,   294,     0,     0,     0,    34,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   295,   194,
       0,     0,     0,     0,   555,     0,   291,   292,   196,     0,
       0,   198,     0,     0,     0,     0,     0,     0,   293,     0,
     203,   204,   294,     0,     0,     0,    34,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   295,
     194,     0,     0,     0,     0,   623,     0,     0,     0,   196,
       0,     0,   198,     0,   291,   292,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   293,     0,   203,   204,
     294,     0,     0,     0,    34,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   295,   194,     0,
       0,     0,     0,   634,     0,   291,   292,   196,     0,     0,
     198,     0,     0,     0,     0,     0,     0,   293,     0,   203,
     204,   294,     0,     0,     0,    34,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   295,   194,
       0,     0,     0,   272,     0,     0,     0,     0,   196,     0,
       0,   198,     0,   291,   292,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   293,     0,   203,   204,   294,
       0,     0,     0,    34,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   295,   194,     0,     0,
       0,   518,     0,     0,   291,   292,   196,     0,     0,   198,
       0,     0,     0,     0,     0,     0,   293,     0,   203,   204,
     294,     0,     0,     0,    34,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   295,   194,   384,
     471,     0,     0,     0,     0,     0,     0,   196,     0,     0,
     198,     0,   291,   292,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   293,     0,   203,   204,   294,     0,
       0,     0,    34,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   295,   194,   384,     0,     0,
       0,     0,     0,   291,   292,   196,     0,     0,   198,     0,
       0,     0,     0,     0,     0,   293,     0,   203,   204,   294,
       0,     0,     0,    34,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   295,   296,   194,     0,
       0,     0,     0,     0,     0,     0,     0,   196,     0,     0,
     198,   291,   292,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   293,     0,   203,   204,   294,     0,     0,
       0,    34,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   295,   464,   194,     0,     0,     0,
       0,     0,     0,   291,   292,   196,     0,     0,   198,     0,
       0,     0,     0,     0,     0,   293,     0,   203,   204,   294,
       0,     0,     0,    34,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   295,   477,   194,     0,
       0,     0,     0,     0,     0,     0,     0,   196,     0,     0,
     198,   291,   292,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   293,     0,   203,   204,   294,     0,     0,
       0,    34,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   295,   479,   194,     0,     0,     0,
       0,     0,     0,   291,   292,   196,     0,     0,   198,     0,
       0,     0,     0,     0,     0,   293,     0,   203,   204,   294,
       0,     0,     0,    34,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   295,   524,   194,     0,
       0,     0,     0,     0,     0,     0,     0,   196,     0,     0,
     198,   291,   292,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   293,     0,   203,   204,   294,     0,     0,
       0,    34,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   295,   574,   194,     0,     0,     0,
       0,     0,     0,   291,   292,   196,     0,     0,   198,     0,
       0,     0,     0,     0,     0,   293,     0,   203,   204,   294,
       0,     0,     0,    34,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   295,   579,   194,     0,
       0,     0,     0,     0,     0,     0,     0,   196,     0,     0,
     198,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   203,   204,     0,     0,     0,
       0,    34,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   609,   194,     0,     0,     0,
       0,     0,     0,     0,     0,   196,     0,     0,   198,     0,
       0,     0,     0,     0,     0,     0,     0,   203,   204,     0,
       0,     0,     0,    34,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   630,   194,     0,
       0,     0,     0,     0,     0,     0,     0,   196,     0,     0,
     198,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   203,   204,     0,     0,     0,
       0,    34,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   640,   194,     0,     0,     0,
       0,     0,     0,     0,     0,   196,     0,     0,   198,     0,
       0,     0,     0,     0,     0,     0,     0,   203,   204,     0,
       0,     0,     0,    34,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   643,   194,     0,
       0,     0,     0,     0,     0,     0,     0,   196,     0,     0,
     198,     0,     0,     0,     0,     0,     0,     0,   194,     0,
       0,     0,     0,     0,     0,   203,   204,   196,     0,     0,
     198,    34,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   653,   194,     0,     0,     0,
       0,     0,     0,   291,   292,   196,     0,     0,   198,     0,
       0,     0,     0,     0,     0,   293,     0,   203,   204,   294,
       0,     0,     0,    34,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   295,   203,   204,     0,
       0,     0,     0,    34,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,     0,     0,     0,
       0,     0,     0,   293,     0,     0,     0,   294,     0,     0,
       0,    34,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   295
};

static const yytype_int16 yycheck[] =
{
       5,   193,   335,     8,    54,    55,   335,    88,    53,   201,
     335,    50,    51,   194,   164,   224,   384,   146,    57,    64,
      70,   157,   151,   392,    63,   106,    53,   203,   204,   158,
     158,   165,   275,   355,    26,    19,    19,    64,   166,    26,
      64,    54,    26,   108,   194,    50,    51,    64,    53,   487,
      53,    26,    57,    63,    65,   100,   101,    70,    63,    64,
     110,    72,   339,    59,   114,    47,   143,   122,    19,    47,
      21,   116,   108,   128,   101,    71,   398,   399,   108,    19,
     289,   126,   101,   108,   129,   135,   136,   108,   165,   116,
      90,   127,   228,    44,   133,   100,   101,   100,   101,   117,
     108,   119,   129,   142,    44,   129,   127,    70,   100,   547,
     155,   116,   129,   116,   295,   291,   292,   293,   294,   200,
       0,   126,   135,   133,   129,   164,   171,   449,   133,   140,
     407,   408,   142,   183,   126,   108,   123,   142,   143,   123,
     123,   108,   138,   125,   171,   123,   389,   224,   123,   278,
     155,   280,   171,   281,   288,   194,   156,   157,   176,   164,
     165,   530,   125,   121,    90,    28,   171,   125,   171,   446,
     122,   129,   540,   450,   122,   553,   128,   555,   108,     5,
     128,     7,   108,   512,    10,   121,   191,   516,   108,   194,
      16,   124,   401,   129,    20,   122,    22,   333,   203,   204,
     517,   128,     9,    29,   124,    31,   528,   127,   128,   127,
     128,   288,   289,    39,    21,   537,   594,   262,     5,   224,
       7,   122,   124,    10,   553,   127,   555,   128,   273,    16,
      93,    94,    95,    96,   108,    22,   123,   143,   414,   415,
     416,   422,    29,   122,    31,   623,   296,   397,    20,   128,
     124,   123,    39,   127,   632,   122,   634,   262,   335,   165,
     127,   128,   595,   102,   103,   594,   595,   645,   273,    41,
     595,   124,   122,    45,   127,   128,   353,   127,   128,   122,
      67,   598,   108,   288,   289,   128,   291,   292,   293,   294,
     295,   108,   122,   122,   623,   123,   122,    69,   128,   128,
     128,   102,   103,   632,   125,   634,   482,   129,   129,   122,
     627,   628,   125,   630,   102,   103,   645,   127,   224,   129,
     108,   108,   639,   640,   401,   642,   643,   123,   128,   646,
     335,   127,   649,   121,   101,   652,   653,   125,   105,   125,
     124,   129,   659,   129,   128,   446,   127,   392,   129,   450,
     423,   424,   425,   426,   102,   103,   122,     3,   397,   125,
     448,   122,   412,   451,   125,    11,   558,   559,   560,   121,
     546,   123,    18,   123,    20,   125,   457,    90,    91,    92,
     123,   143,   288,   289,    30,   108,    32,   392,   108,    35,
      36,    37,   397,   125,    40,   125,   401,   121,    44,    85,
      86,    87,    48,   165,   121,    51,   127,   128,   124,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   335,
      88,    89,     5,   127,     7,   512,   127,    10,   126,   516,
     517,   126,   598,    16,    97,    98,   126,   353,   529,    22,
     419,   420,   421,   417,   418,   123,    29,   534,    31,   427,
     428,   124,   224,   124,   121,   129,    39,   121,   106,   108,
     129,   627,   628,   550,   630,   127,   553,   482,   555,   127,
     125,   127,   487,   639,   640,   530,   642,   643,   128,   126,
     646,   126,   121,   649,    82,   401,   652,   653,    84,    83,
      99,   124,   127,   659,   125,   127,   121,   127,   108,   127,
     122,   588,   589,   108,   591,   592,   122,   594,   595,   128,
     601,   598,   599,   125,   106,   530,   288,   289,   605,   127,
     121,   608,   609,   122,   121,   108,   128,   122,   106,   122,
     121,   546,   547,   106,   549,   622,   623,   126,   126,   143,
     627,   628,   127,   630,   126,   632,   127,   634,   127,   126,
     125,   127,   639,   640,   126,   642,   643,   127,   645,   646,
     122,   165,   649,   335,   122,   652,   653,   127,    17,    17,
     122,   122,   659,   122,   122,   106,   122,   127,     3,   122,
     595,   353,   127,   122,   122,   127,    11,    17,   122,   122,
     122,    70,   422,    18,    21,    20,   512,    57,   116,   100,
     516,   517,    27,   262,    71,    30,   266,    32,   176,    34,
      35,    36,    37,    72,   129,    40,   458,   191,   534,    44,
     224,   458,   339,    48,   595,     5,    51,     7,   429,   401,
      10,   430,   432,    -1,   550,   549,    16,   553,   431,   555,
      20,   433,    22,     5,    -1,     7,    -1,    -1,    10,    29,
      -1,    31,    -1,    -1,    16,    -1,    -1,    -1,    20,    39,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31,
      -1,    -1,   588,   589,    -1,   591,   592,    39,   594,   595,
      -1,    -1,   598,   599,   288,   289,    -1,    -1,    -1,   605,
      -1,    -1,   608,   609,    -1,    -1,    -1,    -1,    -1,   143,
      -1,    -1,   127,    -1,    -1,    -1,   622,   623,    -1,    -1,
      -1,   627,   628,    -1,   630,    -1,   632,    -1,   634,    -1,
      -1,   165,    -1,   639,   640,    -1,   642,   643,   108,   645,
     646,   335,    -1,   649,    -1,    -1,   652,   653,    -1,    -1,
     512,    -1,   122,   659,   516,   517,   108,    -1,    -1,   353,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,   534,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    20,    -1,    -1,    -1,    -1,    -1,   550,    27,
     224,   553,    30,   555,    32,    -1,    -1,    35,    36,    37,
      -1,    -1,    40,    -1,    -1,    -1,    44,   401,    -1,    -1,
      48,    -1,    -1,    51,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,   588,   589,    -1,   591,
     592,    -1,   594,   595,    -1,    -1,   598,   599,    -1,    -1,
      -1,    -1,    -1,   605,    -1,    -1,   608,   609,    -1,    -1,
      -1,    -1,    -1,    -1,   288,   289,    -1,    -1,    -1,    -1,
     622,   623,    -1,    -1,   143,   627,   628,    -1,   630,    -1,
     632,    -1,   634,    -1,    -1,    -1,   169,   639,   640,    -1,
     642,   643,    -1,   645,   646,    -1,   165,   649,    -1,   127,
     652,   653,    -1,    -1,    -1,    -1,    -1,   659,    -1,    -1,
      -1,   335,   195,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   512,   353,
      -1,    -1,   516,   517,    -1,   218,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
     534,    -1,    -1,     3,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    11,    -1,    -1,    -1,    -1,   550,    -1,    18,   553,
      20,   555,    -1,    -1,    -1,    -1,    -1,   401,    -1,    -1,
      30,    -1,    32,    -1,   267,    35,    36,    37,   121,    -1,
      40,    -1,   125,    -1,    44,   143,   129,    -1,    48,    -1,
      -1,    51,    -1,    -1,   588,   589,    -1,   591,   592,    -1,
     594,   595,   295,    -1,   598,   599,    -1,   165,    -1,   288,
     289,   605,    -1,    -1,   608,   609,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,   622,   623,
      -1,    -1,    -1,   627,   628,    -1,   630,    -1,   632,    -1,
     634,    -1,    -1,   336,    -1,   639,   640,    -1,   642,   643,
     343,   645,   646,    -1,   347,   649,   335,    -1,   652,   653,
      -1,    -1,   355,   356,    -1,   659,   224,    -1,    -1,    -1,
      -1,   364,    -1,    -1,   353,    -1,    -1,    -1,   512,    -1,
      -1,    -1,   516,   517,    -1,    -1,   379,    -1,    -1,    -1,
      -1,   384,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     534,    -1,    -1,    -1,    -1,   398,   399,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   550,    -1,   411,   553,
     413,   555,   401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     288,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   434,    -1,    -1,    -1,    -1,   439,    -1,    -1,    -1,
      -1,    -1,   445,    -1,   588,   589,   449,   591,   592,    -1,
     594,   595,    -1,    -1,   598,   599,    -1,    -1,    -1,    -1,
      -1,   605,    -1,    -1,   608,   609,    -1,   335,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,   623,
      -1,    -1,   485,   627,   628,   353,   630,    -1,   632,    -1,
     634,    -1,    -1,    -1,    -1,   639,   640,    -1,   642,   643,
      -1,   645,   646,    -1,    -1,   649,    -1,    -1,   652,   653,
      -1,   514,   515,    -1,    -1,   659,    -1,   195,    -1,    -1,
      -1,   199,    -1,   512,    -1,   528,    -1,   516,   517,    -1,
      -1,    -1,    -1,   401,   537,    -1,    -1,   540,    -1,    -1,
     218,    -1,    -1,    -1,    -1,   534,    -1,    -1,    -1,    -1,
       3,    -1,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,   550,    -1,    16,   553,    -1,   555,    20,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,
      -1,    -1,    35,    36,    37,    -1,    39,    40,    -1,   267,
      -1,    44,    -1,   596,   597,    48,    -1,    50,    51,   588,
     589,    -1,   591,   592,    -1,   594,   595,    -1,   611,   598,
     599,    -1,    -1,    -1,    -1,    -1,   605,   295,    -1,   608,
     609,    -1,   625,   626,    -1,    -1,    -1,   203,   204,    -1,
      -1,    -1,    -1,   622,   623,    -1,    -1,    -1,   627,   628,
      -1,   630,    -1,   632,   512,   634,    -1,    -1,   516,   517,
     639,   640,    -1,   642,   643,   108,   645,   646,   336,    -1,
     649,   203,   204,   652,   653,   343,   534,    -1,    -1,   347,
     659,   124,    -1,    -1,    -1,    -1,    -1,    -1,   356,    -1,
      -1,    -1,   550,    -1,    -1,   553,   364,   555,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,   379,    -1,    -1,    -1,    -1,   384,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   291,   292,   293,   294,    -1,
     588,   589,    -1,   591,   592,    -1,   594,   595,    -1,    -1,
     598,   599,    -1,   411,    33,   413,    -1,   605,    -1,   353,
     608,   609,    -1,    42,    -1,    -1,    45,    -1,    -1,   291,
     292,   293,   294,    -1,   622,   623,   434,    -1,    -1,   627,
     628,   439,   630,    -1,   632,    -1,   634,   445,    -1,    -1,
      -1,   639,   640,    -1,   642,   643,    -1,   645,   646,    -1,
      -1,   649,    -1,    -1,   652,   653,    -1,    -1,    -1,    88,
      89,   659,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   100,    -1,   102,   103,   104,    -1,   485,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,    -1,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   514,   515,   414,   415,
     416,   417,   418,   419,   420,   421,    -1,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,    -1,    -1,
      -1,    -1,   540,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   414,   415,   416,   417,   418,   419,   420,   421,
      -1,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   517,    -1,    -1,   482,    -1,    -1,    -1,
      -1,   487,    -1,    -1,    -1,    -1,    -1,    -1,   596,   597,
     534,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,   611,    -1,    -1,   550,    -1,    -1,    -1,
     482,    -1,    -1,    -1,    -1,   487,    -1,   625,   626,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     546,   547,   121,   549,   588,   589,   125,   591,   592,    -1,
     129,    -1,    -1,    -1,   598,   599,    -1,    -1,    -1,    -1,
      -1,   605,    -1,    -1,   608,   609,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   546,   547,    -1,   549,   622,    -1,
      -1,    -1,    -1,   627,   628,    -1,   630,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   639,   640,    -1,   642,   643,
      -1,    -1,   646,    -1,    -1,   649,    -1,    -1,   652,   653,
      -1,     5,     6,     7,    -1,   659,    10,    -1,    -1,    13,
      -1,    -1,    16,    -1,    -1,    -1,    20,    -1,    22,    23,
      -1,    25,    -1,    -1,    -1,    29,    -1,    31,    -1,    33,
      -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    42,    -1,
      44,    45,    46,    -1,    -1,    49,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,    -1,
      33,    10,    -1,    67,    13,    -1,    -1,    16,    -1,    42,
      -1,    20,    45,    22,    23,    -1,    25,    -1,    -1,    -1,
      29,    -1,    31,    -1,    33,    -1,    -1,    -1,    -1,    38,
      39,    -1,    -1,    42,    -1,    44,    45,    46,   102,   103,
      49,    -1,    -1,    52,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    67,   123,
     124,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,   102,
     103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,    -1,    -1,   102,   103,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    -1,   123,   124,    -1,    -1,   127,     5,
       6,     7,    -1,    -1,    10,    -1,    -1,    13,    -1,    -1,
      16,    -1,    -1,    -1,    20,    -1,    22,    23,    -1,    25,
      -1,    -1,    -1,    29,    -1,    31,    -1,    33,    -1,    -1,
      -1,    -1,    38,    39,    -1,    -1,    42,    -1,    44,    45,
      46,    -1,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,     7,    -1,    33,    10,
      -1,    67,    13,    -1,    -1,    16,    -1,    42,    -1,    20,
      45,    22,    23,    -1,    25,    -1,    -1,    -1,    29,    -1,
      31,    -1,    33,    -1,    -1,    -1,    -1,    38,    39,    -1,
      -1,    42,    -1,    44,    45,    46,   102,   103,    49,    -1,
      -1,    52,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    67,   123,   124,    -1,
      -1,   127,    -1,    -1,    -1,    -1,    -1,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    -1,    -1,
      -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,   123,   124,    -1,    -1,   127,     5,     6,     7,
      -1,    -1,    10,    -1,    -1,    13,    -1,    -1,    16,    -1,
      -1,    -1,    20,    -1,    22,    23,    -1,    25,    -1,    -1,
      -1,    29,    -1,    31,    -1,    33,    -1,    -1,    -1,    -1,
      38,    39,    -1,    -1,    42,    -1,    44,    45,    46,    -1,
      -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,     7,    -1,    33,    10,    -1,    67,
      13,    -1,    -1,    16,    -1,    42,    -1,    20,    45,    22,
      23,    -1,    25,    -1,    -1,    -1,    29,    -1,    31,    -1,
      33,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    42,
      -1,    44,    45,    46,   102,   103,    49,    -1,    -1,    52,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,    67,   123,   124,    -1,    -1,   127,
      -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    -1,    -1,    -1,   102,
     103,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    -1,
     123,   124,    -1,     5,   127,     7,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31,
       5,    33,     7,    -1,    -1,    10,    -1,    39,    -1,    -1,
      42,    16,    -1,    45,    -1,    20,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    31,    -1,    33,     6,
      -1,    -1,    -1,    -1,    39,    67,    13,    42,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    38,    67,    -1,    -1,    42,    -1,    44,    45,    46,
     102,   103,    49,    -1,    -1,    52,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,    -1,   127,    -1,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,    -1,   127,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,     6,   123,    -1,    -1,    -1,
     127,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    42,    -1,    44,    45,    46,    -1,    -1,    49,    -1,
       3,    52,     5,    -1,     7,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,
      -1,    -1,    35,    36,    37,    -1,    39,    40,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    48,    -1,    50,    51,    -1,
      -1,   102,   103,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    -1,   123,    -1,    -1,     3,   127,     5,    -1,     7,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    -1,    31,    32,   108,    -1,    35,    36,    37,
      -1,    39,    40,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      48,   124,    50,    51,     5,    -1,     7,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,
       3,    22,     5,    -1,     7,    -1,    -1,    10,    29,    -1,
      31,    -1,    33,    16,    -1,    -1,    -1,    20,    39,    22,
      -1,    42,    -1,    -1,    45,    -1,    29,    -1,    31,    32,
      -1,    -1,    35,    36,    37,    -1,    39,    40,    -1,    -1,
     108,    44,    -1,    -1,    -1,    48,    -1,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,
      -1,   102,   103,   104,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    33,     3,    -1,     5,   108,     7,    -1,    -1,    10,
      42,    -1,    -1,    45,    -1,    16,    -1,    -1,    -1,    20,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      31,    32,    -1,    -1,    35,    36,    37,    -1,    39,    40,
      -1,    -1,    33,    44,    -1,    -1,    -1,    48,    -1,    50,
      51,    42,    -1,    -1,    45,    -1,    88,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,
     102,   103,   104,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      33,    -1,    -1,    -1,    -1,   127,    -1,    88,    89,    42,
      -1,    -1,    45,    -1,    -1,    -1,    -1,   108,    -1,   100,
      -1,   102,   103,   104,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,    33,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,
      42,    -1,    -1,    45,    -1,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    33,
      -1,    -1,    -1,    -1,   127,    -1,    88,    89,    42,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,
     102,   103,   104,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
      33,    -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    42,
      -1,    -1,    45,    -1,    88,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,   103,
     104,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    33,    -1,
      -1,    -1,    -1,   127,    -1,    88,    89,    42,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,    33,
      -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    45,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   100,    -1,   102,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    33,    -1,    -1,
      -1,   126,    -1,    -1,    88,    89,    42,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,   103,
     104,    -1,    -1,    -1,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    33,   123,
     124,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      45,    -1,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   100,    -1,   102,   103,   104,    -1,
      -1,    -1,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    33,   123,    -1,    -1,
      -1,    -1,    -1,    88,    89,    42,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,   100,    -1,   102,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      45,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,    -1,   102,   103,   104,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    42,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,   100,    -1,   102,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      45,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,    -1,   102,   103,   104,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    42,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,   100,    -1,   102,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      45,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,    -1,   102,   103,   104,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    42,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,   100,    -1,   102,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,   102,   103,    42,    -1,    -1,
      45,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    42,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,   100,    -1,   102,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   102,   103,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,    -1,    -1,   100,    -1,    -1,    -1,   104,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121
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
     193,   194,   128,   123,   201,   108,   175,   108,   168,   169,
     170,   175,   125,   125,   125,   121,    50,   134,   183,   124,
     165,   127,   180,   201,    47,   123,   178,   184,   163,   121,
     163,   164,   124,   189,   124,   124,   128,   189,   127,   127,
     124,   196,   142,   161,   163,   163,   188,   194,   142,     6,
      13,    20,    23,    25,    33,    38,    42,    44,    45,    46,
      49,    52,    67,   102,   103,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   124,
     127,   134,   144,   201,   202,   203,   204,   205,   206,   207,
     209,   210,   211,   213,   214,   215,   216,   219,   221,   223,
     228,   230,   231,   232,   233,   234,   235,   239,   240,   241,
     243,   247,   248,   249,   250,   251,   252,   254,   255,   270,
     271,   121,   174,   125,   178,   127,   128,    70,   125,   178,
     126,   126,   126,    20,   122,   134,   176,   177,   175,   168,
     175,   178,   184,   141,   179,    42,    45,   124,   185,   202,
     184,    88,    89,   100,   104,   121,   122,   144,   241,   242,
     248,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   273,   124,   124,   189,   191,   124,   163,   108,
     127,   108,   127,   206,   121,   218,   218,   135,   141,   144,
     127,   273,   129,   121,   127,   273,   201,   218,   144,   247,
     249,   253,   253,   106,   273,   121,   125,   124,   203,   127,
     108,   168,   127,   129,   125,   102,   103,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   272,
     122,   176,   126,   169,   123,   171,   199,   273,   126,   134,
     170,   122,   128,   178,   127,   178,   184,   128,   121,   121,
     124,   202,   124,   253,   253,   253,   253,   135,   144,   273,
     163,   125,   122,   128,    90,    91,    92,    88,    89,    85,
      86,    87,    28,    93,    94,    95,    96,    97,    98,    82,
      84,    83,    99,   101,   105,   124,   127,   127,   168,   127,
     205,   214,   226,   229,   273,   125,   244,   245,   246,   121,
     244,   246,   127,   108,   273,   127,     9,    21,   236,   237,
     238,   273,   207,   122,   122,   242,   273,   108,   273,   273,
     122,   124,   171,   200,   170,   177,   141,   122,   242,   122,
     242,   124,   122,   125,   246,   125,   246,   122,   163,   273,
     253,   253,   253,   258,   258,   259,   259,   259,   135,   139,
     260,   260,   260,   260,   261,   261,   262,   263,   264,   265,
     266,   273,   127,   273,   106,   127,   128,   122,   126,   273,
     245,   246,   125,   199,   122,   242,   246,   199,   121,   122,
     121,   201,   237,   238,   122,   122,   126,   121,   126,   124,
     128,   127,   122,   127,   122,   253,   122,   122,   256,   106,
     122,   227,   229,   127,   273,   127,   273,   214,    23,    25,
      52,   108,   207,   208,   209,   212,   217,   220,   222,   224,
     225,   126,   126,   122,   122,   242,   201,   177,   207,   122,
     242,   171,   127,   127,   253,   256,   268,   207,   122,   122,
     227,   122,   122,   227,   127,   218,   218,   218,   106,    17,
     122,   122,   122,   207,   207,   122,   207,   207,   122,   122,
     227,   127,   205,   226,   273,   273,   208,   207,   201,   207,
     207,   207,   122,   127,   273,   106,   127,   122,   122,   207,
     122,   227,   127,   273,   127,   273,   208,   208,   208,   122,
     122,   227,   122,   122,   227,   127,    17,   208,   208,   122,
     208,   208,   122,   122,   227,   208,   208,   208,   208,   122,
     208
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
     200,   200,   201,   201,   202,   202,   203,   203,   204,   205,
     205,   206,   206,   207,   207,   207,   207,   207,   207,   208,
     208,   208,   208,   208,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   210,   211,   212,   213,   214,   214,   214,
     214,   214,   214,   214,   215,   216,   217,   218,   219,   220,
     221,   221,   222,   222,   223,   223,   223,   223,   223,   223,
     223,   223,   224,   224,   224,   224,   224,   224,   224,   224,
     225,   226,   226,   227,   228,   229,   229,   230,   230,   231,
     231,   232,   232,   233,   233,   234,   235,   235,   235,   236,
     236,   237,   238,   239,   239,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   241,   241,   242,   242,   243,   243,   243,
     243,   243,   243,   244,   244,   245,   246,   246,   247,   247,
     248,   248,   248,   248,   248,   248,   249,   249,   250,   250,
     250,   250,   251,   252,   253,   253,   253,   253,   253,   254,
     255,   256,   256,   256,   256,   257,   257,   257,   257,   258,
     258,   258,   258,   259,   259,   259,   260,   260,   260,   260,
     261,   261,   261,   261,   261,   261,   262,   262,   262,   263,
     263,   264,   264,   265,   265,   266,   266,   267,   267,   268,
     268,   269,   269,   270,   271,   271,   271,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   273
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
       1,     3,     2,     3,     1,     2,     1,     1,     2,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     5,     7,     7,     1,     5,     5,
       1,     1,     1,     1,     6,     7,     7,     8,     7,     8,
       8,     9,     6,     7,     7,     8,     7,     8,     8,     9,
       7,     1,     1,     1,     7,     1,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     5,     3,     3,     4,     1,
       2,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     4,     5,     1,     3,     3,     4,     4,
       3,     4,     4,     1,     2,     3,     2,     3,     3,     3,
       3,     4,     5,     6,     5,     6,     4,     4,     1,     1,
       1,     1,     2,     2,     1,     1,     2,     2,     1,     2,
       2,     1,     2,     2,     1,     4,     5,     4,     5,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       5,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 75 "parser.y"
    {   
        root=new Node("Program");
        root->children.push_back(new Node("EOF","EOF",-1));
    }
#line 2673 "parser.tab.c"
    break;

  case 3:
#line 80 "parser.y"
    {
        root=new Node("Program");
        root->isBlock=true; 
        root->children.push_back((yyvsp[0].node));
        root->children.push_back(new Node("EOF","EOF",-1));
    }
#line 2684 "parser.tab.c"
    break;

  case 4:
#line 91 "parser.y"
    {
        (yyval.node)=(yyvsp[0].node);
    }
#line 2692 "parser.tab.c"
    break;

  case 5:
#line 95 "parser.y"
    {
        (yyval.node)=(yyvsp[0].node);
    }
#line 2700 "parser.tab.c"
    break;

  case 6:
#line 100 "parser.y"
               {
                (yyval.node)=(yyvsp[0].node);
               }
#line 2708 "parser.tab.c"
    break;

  case 7:
#line 104 "parser.y"
             {
                (yyval.node) = new Node("boolean","Keyword",yylineno);
                if(!isDot){
                (yyval.node)->type = BOOL;
                t = BOOL;
                }
             }
#line 2720 "parser.tab.c"
    break;

  case 8:
#line 113 "parser.y"
            {
                (yyval.node)=(yyvsp[0].node);
            }
#line 2728 "parser.tab.c"
    break;

  case 9:
#line 117 "parser.y"
            {
                (yyval.node)=(yyvsp[0].node);
            }
#line 2736 "parser.tab.c"
    break;

  case 10:
#line 121 "parser.y"
                    {
                (yyval.node) = new Node("byte","Keyword", INT, yylineno);
                t = INT;
            }
#line 2745 "parser.tab.c"
    break;

  case 11:
#line 125 "parser.y"
                    {
                (yyval.node) = new Node("short","Keyword", INT, yylineno);
                t = INT;
            }
#line 2754 "parser.tab.c"
    break;

  case 12:
#line 129 "parser.y"
                   {
                (yyval.node) = new Node("int","Keyword", INT, yylineno);
                t = INT;
            }
#line 2763 "parser.tab.c"
    break;

  case 13:
#line 133 "parser.y"
                    {
                (yyval.node) = new Node("long","Keyword", LONG, yylineno);
                t = LONG;
            }
#line 2772 "parser.tab.c"
    break;

  case 14:
#line 137 "parser.y"
                    {
                (yyval.node) = new Node("char","Keyword", CHAR, yylineno );
                t = CHAR;
            }
#line 2781 "parser.tab.c"
    break;

  case 15:
#line 142 "parser.y"
                           {
                        (yyval.node) = new Node("float","Keyword", FLOAT, yylineno);
                        t = FLOAT;
                   }
#line 2790 "parser.tab.c"
    break;

  case 16:
#line 147 "parser.y"
                   {
                        (yyval.node) = new Node("double","Keyword", DOUBLE, yylineno);
                        t = DOUBLE;
                   }
#line 2799 "parser.tab.c"
    break;

  case 17:
#line 153 "parser.y"
              {
                (yyval.node)=(yyvsp[0].node);
              }
#line 2807 "parser.tab.c"
    break;

  case 18:
#line 157 "parser.y"
             {
                (yyval.node)=(yyvsp[0].node);
             }
#line 2815 "parser.tab.c"
    break;

  case 19:
#line 161 "parser.y"
                          {
                            (yyval.node)=(yyvsp[0].node);
                          }
#line 2823 "parser.tab.c"
    break;

  case 20:
#line 165 "parser.y"
                               {
                                 (yyval.node)=(yyvsp[0].node);
                               }
#line 2831 "parser.tab.c"
    break;

  case 21:
#line 169 "parser.y"
                                   {
                                    (yyval.node)=(yyvsp[0].node);
                                   }
#line 2839 "parser.tab.c"
    break;

  case 22:
#line 174 "parser.y"
                {
                    (yyval.node)=new Node("ArrayType"); 
                    (yyval.node)->type = (yyvsp[-2].node)->type;
                    (yyval.node)->isArray = true;
                    (yyval.node)->children.push_back((yyvsp[-2].node));
                    (yyval.node)->children.push_back(new Node("[","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node("]","Separator", yylineno));
                }
#line 2852 "parser.tab.c"
    break;

  case 23:
#line 183 "parser.y"
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
                }
#line 2872 "parser.tab.c"
    break;

  case 24:
#line 199 "parser.y"
                {
                    (yyval.node)=new Node("ArrayType"); 
                    (yyval.node)->isArray = true;
                    (yyval.node)->type = (yyvsp[-2].node)->type;
                    (yyval.node)->children.push_back((yyvsp[-2].node));
                    (yyval.node)->children.push_back(new Node("[","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node("]","Separator", yylineno));
                }
#line 2885 "parser.tab.c"
    break;

  case 25:
#line 212 "parser.y"
     {
        (yyval.node)=(yyvsp[0].node);
     }
#line 2893 "parser.tab.c"
    break;

  case 26:
#line 216 "parser.y"
      {
        (yyval.node)=(yyvsp[0].node);
      }
#line 2901 "parser.tab.c"
    break;

  case 27:
#line 221 "parser.y"
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
#line 2921 "parser.tab.c"
    break;

  case 28:
#line 238 "parser.y"
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
#line 2940 "parser.tab.c"
    break;

  case 29:
#line 256 "parser.y"
                {
                    (yyval.node)=new Node("CompilationUnit"); 
                    (yyval.node)->children.push_back((yyvsp[-2].node));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                }
#line 2951 "parser.tab.c"
    break;

  case 30:
#line 263 "parser.y"
                {
                    (yyval.node)=new Node("CompilationUnit"); 
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                }
#line 2961 "parser.tab.c"
    break;

  case 31:
#line 269 "parser.y"
                {
                    (yyval.node)=new Node("CompilationUnit"); 
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                }
#line 2971 "parser.tab.c"
    break;

  case 32:
#line 275 "parser.y"
                {
                    (yyval.node)=(yyvsp[0].node);
                }
#line 2979 "parser.tab.c"
    break;

  case 33:
#line 279 "parser.y"
                {
                    (yyval.node)=new Node("CompilationUnit"); 
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                }
#line 2989 "parser.tab.c"
    break;

  case 34:
#line 285 "parser.y"
                {
                    (yyval.node)=(yyvsp[0].node);
                }
#line 2997 "parser.tab.c"
    break;

  case 35:
#line 290 "parser.y"
                {
                    (yyval.node)=(yyvsp[0].node);
                }
#line 3005 "parser.tab.c"
    break;

  case 36:
#line 295 "parser.y"
                {
                    (yyval.node)=(yyvsp[0].node);
                }
#line 3013 "parser.tab.c"
    break;

  case 37:
#line 299 "parser.y"
                {
                    (yyval.node)=new Node("ImportDeclarations"); 
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                }
#line 3023 "parser.tab.c"
    break;

  case 38:
#line 306 "parser.y"
                {
                    (yyval.node)=(yyvsp[0].node);
                }
#line 3031 "parser.tab.c"
    break;

  case 39:
#line 310 "parser.y"
                {
                    (yyval.node)=new Node("TypeDeclarations"); 
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                }
#line 3041 "parser.tab.c"
    break;

  case 40:
#line 317 "parser.y"
                    {
                        (yyval.node)=new Node("PackageDeclaration"); 
                        (yyval.node)->children.push_back(new Node("package","Keyword", yylineno));
                        (yyval.node)->children.push_back((yyvsp[-1].node));
                        (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
                    }
#line 3052 "parser.tab.c"
    break;

  case 41:
#line 325 "parser.y"
                   {
                    (yyval.node)=(yyvsp[0].node);
                   }
#line 3060 "parser.tab.c"
    break;

  case 42:
#line 329 "parser.y"
                  {
                    (yyval.node)=(yyvsp[0].node);
                  }
#line 3068 "parser.tab.c"
    break;

  case 43:
#line 334 "parser.y"
                             {
                                (yyval.node)=new Node("SingleImportTypeDeclaration"); 
                                (yyval.node)->children.push_back(new Node("import","Keyword", yylineno));
                                (yyval.node)->children.push_back((yyvsp[-1].node));
                                (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
                             }
#line 3079 "parser.tab.c"
    break;

  case 44:
#line 343 "parser.y"
                               {
                                (yyval.node)=new Node("PackageDeclaration"); 
                                (yyval.node)->children.push_back(new Node("import","Keyword", yylineno));
                                (yyval.node)->children.push_back((yyvsp[-3].node));
                                (yyval.node)->children.push_back(new Node(".","Separator", yylineno));
                                (yyval.node)->children.push_back(new Node("*","Operator", yylineno));
                                (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
                               }
#line 3092 "parser.tab.c"
    break;

  case 45:
#line 353 "parser.y"
                {
                    (yyval.node)=(yyvsp[0].node);
                }
#line 3100 "parser.tab.c"
    break;

  case 46:
#line 357 "parser.y"
                {
                    (yyval.node)=(yyvsp[0].node);
                }
#line 3108 "parser.tab.c"
    break;

  case 47:
#line 361 "parser.y"
                {
                (yyval.node) = new Node(";","Separator", yylineno);
                }
#line 3116 "parser.tab.c"
    break;

  case 48:
#line 367 "parser.y"
          {
            (yyval.node) = (yyvsp[0].node);
          }
#line 3124 "parser.tab.c"
    break;

  case 49:
#line 371 "parser.y"
         {
            (yyval.node)=new Node("Modifiers"); 
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
         }
#line 3134 "parser.tab.c"
    break;

  case 50:
#line 378 "parser.y"
          {
            (yyval.node) = new Node("public","Keyword", yylineno);
          }
#line 3142 "parser.tab.c"
    break;

  case 51:
#line 382 "parser.y"
          {
            (yyval.node) = new Node("protected","Keyword", yylineno);
          }
#line 3150 "parser.tab.c"
    break;

  case 52:
#line 386 "parser.y"
          {
            (yyval.node) = new Node("private","Keyword", yylineno);
          }
#line 3158 "parser.tab.c"
    break;

  case 53:
#line 390 "parser.y"
          {
            (yyval.node) = new Node("static","Keyword", yylineno);
          }
#line 3166 "parser.tab.c"
    break;

  case 54:
#line 394 "parser.y"
          {
            (yyval.node) = new Node("abstract","Keyword", yylineno);
          }
#line 3174 "parser.tab.c"
    break;

  case 55:
#line 398 "parser.y"
          {
            (yyval.node) = new Node("final","Keyword", yylineno);
          }
#line 3182 "parser.tab.c"
    break;

  case 56:
#line 402 "parser.y"
          {
            (yyval.node) = new Node("native","Keyword", yylineno);
          }
#line 3190 "parser.tab.c"
    break;

  case 57:
#line 406 "parser.y"
          {
            (yyval.node) = new Node("synchronized","Keyword", yylineno);
          }
#line 3198 "parser.tab.c"
    break;

  case 58:
#line 410 "parser.y"
          {
            (yyval.node) = new Node("transient","Keyword", yylineno);
          }
#line 3206 "parser.tab.c"
    break;

  case 59:
#line 414 "parser.y"
          {
            (yyval.node) = new Node("volatile","Keyword", yylineno);
          }
#line 3214 "parser.tab.c"
    break;

  case 60:
#line 419 "parser.y"
                   {
                    (yyval.node)=(yyvsp[0].node);
                   }
#line 3222 "parser.tab.c"
    break;

  case 61:
#line 423 "parser.y"
                   {
                    (yyval.node)=(yyvsp[0].node);
                   }
#line 3230 "parser.tab.c"
    break;

  case 62:
#line 429 "parser.y"
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
#line 3254 "parser.tab.c"
    break;

  case 63:
#line 449 "parser.y"
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
#line 3277 "parser.tab.c"
    break;

  case 64:
#line 468 "parser.y"
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
#line 3300 "parser.tab.c"
    break;

  case 65:
#line 487 "parser.y"
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
#line 3322 "parser.tab.c"
    break;

  case 66:
#line 505 "parser.y"
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
#line 3345 "parser.tab.c"
    break;

  case 67:
#line 524 "parser.y"
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
#line 3367 "parser.tab.c"
    break;

  case 68:
#line 542 "parser.y"
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
#line 3389 "parser.tab.c"
    break;

  case 69:
#line 560 "parser.y"
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
#line 3410 "parser.tab.c"
    break;

  case 70:
#line 577 "parser.y"
                                           { 
                    if(!isDot){
                        initializeSymTable();
                    }
                }
#line 3420 "parser.tab.c"
    break;

  case 71:
#line 584 "parser.y"
        {
            (yyval.node)=new Node("Super");
            (yyval.node)->children.push_back(new Node("extends","Keyword", yylineno));
            (yyval.node)->children.push_back((yyvsp[0].node));
        }
#line 3430 "parser.tab.c"
    break;

  case 72:
#line 591 "parser.y"
            {
                (yyval.node)=new Node("Interfaces");
                (yyval.node)->children.push_back(new Node("implements","Keyword", yylineno));
                (yyval.node)->children.push_back((yyvsp[0].node));
            }
#line 3440 "parser.tab.c"
    break;

  case 73:
#line 598 "parser.y"
                    {
                        (yyval.node)=(yyvsp[0].node);
                    }
#line 3448 "parser.tab.c"
    break;

  case 74:
#line 602 "parser.y"
                    {
                        (yyval.node)=new Node("InterfaceTypeList");
                        (yyval.node)->children.push_back((yyvsp[-2].node));
                        (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
                        (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 3459 "parser.tab.c"
    break;

  case 75:
#line 610 "parser.y"
{
    (yyval.node)=new Node("ClassBody");
    (yyval.node)->isBlock=true;
    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
    currentSymTableId = symTables[currentSymTableId].parentID;
}
#line 3472 "parser.tab.c"
    break;

  case 76:
#line 619 "parser.y"
{
    (yyval.node)=new Node("ClassBody");
    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
    //currentSymTableId = symTables[currentSymTableId].parentID;
}
#line 3483 "parser.tab.c"
    break;

  case 77:
#line 627 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3491 "parser.tab.c"
    break;

  case 78:
#line 631 "parser.y"
                        {
                            (yyval.node)=new Node("ClassBodyDeclarations");
                            (yyval.node)->children.push_back((yyvsp[-1].node));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                        }
#line 3501 "parser.tab.c"
    break;

  case 79:
#line 638 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3509 "parser.tab.c"
    break;

  case 80:
#line 642 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3517 "parser.tab.c"
    break;

  case 81:
#line 646 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3525 "parser.tab.c"
    break;

  case 82:
#line 651 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3533 "parser.tab.c"
    break;

  case 83:
#line 655 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3541 "parser.tab.c"
    break;

  case 84:
#line 660 "parser.y"
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
#line 3563 "parser.tab.c"
    break;

  case 85:
#line 678 "parser.y"
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
#line 3581 "parser.tab.c"
    break;

  case 86:
#line 693 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3589 "parser.tab.c"
    break;

  case 87:
#line 697 "parser.y"
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
#line 3607 "parser.tab.c"
    break;

  case 88:
#line 712 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3615 "parser.tab.c"
    break;

  case 89:
#line 716 "parser.y"
                        {
                            (yyval.node)=new Node("VariableDeclarator");
                            (yyval.node)->children.push_back((yyvsp[-2].node));
                            (yyval.node)->children.push_back(new Node("=","Operator", yylineno));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                            if(!isDot){
                                if(t != (yyvsp[0].node)->type){
                                    cout<<"Type Mismatch in Variable Declarator"<<endl;
                                    exit(0);
                                }
                            }
                        }
#line 3632 "parser.tab.c"
    break;

  case 90:
#line 730 "parser.y"
                      {
                        (yyval.node) = new Node((yyvsp[0].str),"Identifier",yylineno);
                        if(!isDot){
                            string s((yyvsp[0].str));
                            if(symTables[currentSymTableId].lookup(s)){
                                cout<<"Variable "<<s<<" already declared in this scope"<<endl;
                                exit(0);
                            }
                            symTables[currentSymTableId].insertSymEntry(s, t, yylineno);
                            cout<<enum_types[t]<<endl;
                        }
                      }
#line 3649 "parser.tab.c"
    break;

  case 91:
#line 743 "parser.y"
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
#line 3668 "parser.tab.c"
    break;

  case 92:
#line 759 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3676 "parser.tab.c"
    break;

  case 93:
#line 763 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3684 "parser.tab.c"
    break;

  case 94:
#line 768 "parser.y"
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
#line 3703 "parser.tab.c"
    break;

  case 95:
#line 784 "parser.y"
                                                  {   
            (yyval.node)=new Node((yyvsp[-1].node)->id.c_str(),"MethodHeader",yylineno); 
            (yyval.node)->children.push_back((yyvsp[-3].node));
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            t = (yyvsp[-2].node)->type;
        }
#line 3716 "parser.tab.c"
    break;

  case 96:
#line 792 "parser.y"
                                      {   
            (yyval.node)=new Node((yyvsp[0].node)->id.c_str(),"MethodHeader",yylineno); 
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            t = (yyvsp[-1].node)->type;
        }
#line 3728 "parser.tab.c"
    break;

  case 97:
#line 799 "parser.y"
                                    {   
            (yyval.node)=new Node((yyvsp[-1].node)->id.c_str(),"MethodHeader",yylineno); 
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            t = (yyvsp[-2].node)->type;
        }
#line 3740 "parser.tab.c"
    break;

  case 98:
#line 806 "parser.y"
                                {   
            (yyval.node)=new Node((yyvsp[0].node)->id.c_str(),"MethodHeader",yylineno); 
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            t = (yyvsp[-1].node)->type;
        }
#line 3751 "parser.tab.c"
    break;

  case 99:
#line 812 "parser.y"
                                                    {   
            (yyval.node)=new Node((yyvsp[-1].node)->id.c_str(),"MethodHeader",yylineno);
            (yyval.node)->children.push_back((yyvsp[-3].node));
            (yyval.node)->children.push_back(new Node("void","Keyword", yylineno));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            t=VOID;
        }
#line 3764 "parser.tab.c"
    break;

  case 100:
#line 820 "parser.y"
                                        {   
            (yyval.node)=new Node((yyvsp[0].node)->id.c_str(),"MethodHeader",yylineno); 
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back(new Node("void","Keyword", yylineno));
            (yyval.node)->children.push_back((yyvsp[0].node));
            t=VOID;
        }
#line 3776 "parser.tab.c"
    break;

  case 101:
#line 827 "parser.y"
                                      {   
            (yyval.node)=new Node((yyvsp[-1].node)->id.c_str(),"MethodHeader",yylineno);
            (yyval.node)->children.push_back(new Node("void","Keyword", yylineno));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            t=VOID;
        }
#line 3788 "parser.tab.c"
    break;

  case 102:
#line 834 "parser.y"
                               {   
            (yyval.node)=new Node((yyvsp[0].node)->id.c_str(),"MethodHeader",yylineno);
            (yyval.node)->children.push_back(new Node("void","Keyword", yylineno));
            (yyval.node)->children.push_back((yyvsp[0].node));
            t=VOID;
        }
#line 3799 "parser.tab.c"
    break;

  case 103:
#line 840 "parser.y"
                            {
        if(!isDot){
            vt.push_back(t);
            initializeSymTable();
        }
}
#line 3810 "parser.tab.c"
    break;

  case 104:
#line 847 "parser.y"
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
#line 3829 "parser.tab.c"
    break;

  case 105:
#line 861 "parser.y"
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
#line 3847 "parser.tab.c"
    break;

  case 106:
#line 874 "parser.y"
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
#line 3865 "parser.tab.c"
    break;

  case 107:
#line 889 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3873 "parser.tab.c"
    break;

  case 108:
#line 893 "parser.y"
                        {
                            (yyval.node)=new Node("FormalParameterList");
                            (yyval.node)->children.push_back((yyvsp[-2].node));
                            (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                        }
#line 3884 "parser.tab.c"
    break;

  case 109:
#line 901 "parser.y"
                        {
                            (yyval.node)=new Node("FormalParameter");
                            (yyval.node)->children.push_back((yyvsp[-1].node));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                            vt.push_back(t);
                            t=VOID;
                        }
#line 3896 "parser.tab.c"
    break;

  case 110:
#line 909 "parser.y"
                        {
                            (yyval.node)=new Node("FormalParameter");
                            (yyval.node)->children.push_back(new Node("final","Keyword", yylineno));
                            (yyval.node)->children.push_back((yyvsp[-1].node));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                            vt.push_back(t);
                            t=VOID;
                        }
#line 3909 "parser.tab.c"
    break;

  case 111:
#line 919 "parser.y"
                        {
                            (yyval.node)=new Node("Throws");
                            (yyval.node)->children.push_back(new Node("throws","Keyword", yylineno));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                        }
#line 3919 "parser.tab.c"
    break;

  case 112:
#line 926 "parser.y"
                        {
                            (yyval.node)=(yyvsp[0].node);
                        }
#line 3927 "parser.tab.c"
    break;

  case 113:
#line 930 "parser.y"
                        {
                            (yyval.node)=new Node("ClassTypeList");
                            (yyval.node)->children.push_back((yyvsp[-2].node));
                            (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                        }
#line 3938 "parser.tab.c"
    break;

  case 114:
#line 938 "parser.y"
                {
                    (yyval.node)=(yyvsp[0].node);
                }
#line 3946 "parser.tab.c"
    break;

  case 115:
#line 943 "parser.y"
    {
        (yyval.node) = new Node(";","Separator", yylineno);
    }
#line 3954 "parser.tab.c"
    break;

  case 116:
#line 948 "parser.y"
                        {
                            (yyval.node)=new Node("StaticInitializer");
                            (yyval.node)->children.push_back(new Node("static","Keyword", yylineno));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                        }
#line 3964 "parser.tab.c"
    break;

  case 117:
#line 957 "parser.y"
                                                               {  
            (yyval.node)=new Node("ConstructorDeclaration"); 
            (yyval.node)->children.push_back((yyvsp[-3].node));
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            }
#line 3976 "parser.tab.c"
    break;

  case 118:
#line 964 "parser.y"
                                                          {  
            (yyval.node)=new Node("ConstructorDeclaration"); 
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            }
#line 3987 "parser.tab.c"
    break;

  case 119:
#line 970 "parser.y"
                                                       {  
            (yyval.node)=new Node("ConstructorDeclaration"); 
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            }
#line 3998 "parser.tab.c"
    break;

  case 120:
#line 976 "parser.y"
                                                {  
            (yyval.node)=new Node("ConstructorDeclaration"); 
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
            }
#line 4008 "parser.tab.c"
    break;

  case 121:
#line 985 "parser.y"
            {  
            (yyval.node)=new Node("ConstructorDeclarator"); 
            (yyval.node)->children.push_back((yyvsp[-3].node));
            (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
            }
#line 4020 "parser.tab.c"
    break;

  case 122:
#line 992 "parser.y"
                                               {  
            (yyval.node)=new Node("ConstructorDeclarator"); 
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
            (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
            }
#line 4031 "parser.tab.c"
    break;

  case 123:
#line 1001 "parser.y"
                                                   {  
            (yyval.node)=new Node("ConstructorBody"); 
            (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
            (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
            }
#line 4041 "parser.tab.c"
    break;

  case 124:
#line 1006 "parser.y"
                                                                     {  
            (yyval.node)=new Node("ConstructorBody"); 
            (yyval.node)->isBlock = true;
            (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
            }
#line 4053 "parser.tab.c"
    break;

  case 125:
#line 1013 "parser.y"
                                                                                   {  
            (yyval.node)=new Node("ConstructorBody"); 
            (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
            }
#line 4064 "parser.tab.c"
    break;

  case 126:
#line 1019 "parser.y"
                                                                                                   {  
            (yyval.node)=new Node("ConstructorBody"); 
            (yyval.node)->isBlock = true;
            (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
            }
#line 4077 "parser.tab.c"
    break;

  case 127:
#line 1030 "parser.y"
                                                                   {  
            (yyval.node)=new Node("ExplicitConstructorInvocation"); 
            (yyval.node)->children.push_back(new Node("this","Keyword", yylineno));
            (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
            (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
            }
#line 4090 "parser.tab.c"
    break;

  case 128:
#line 1038 "parser.y"
                                                        {  
            (yyval.node)=new Node("ExplicitConstructorInvocation"); 
            (yyval.node)->children.push_back(new Node("this","Keyword", yylineno));
            (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
            (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
            (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
            }
#line 4102 "parser.tab.c"
    break;

  case 129:
#line 1045 "parser.y"
                                                                      {  
            (yyval.node)=new Node("ExplicitConstructorInvocation"); 
            (yyval.node)->children.push_back(new Node("super","Keyword", yylineno));
            (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
            (yyval.node)->children.push_back((yyvsp[-2].node));
            (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
            (yyval.node)->children.push_back(new Node(";","Separator", yylineno));}
#line 4114 "parser.tab.c"
    break;

  case 130:
#line 1052 "parser.y"
                                                         {  
            (yyval.node)=new Node("ExplicitConstructorInvocation"); 
            (yyval.node)->children.push_back(new Node("super","Keyword", yylineno));
            (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
            (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
            (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
            }
#line 4126 "parser.tab.c"
    break;

  case 131:
#line 1061 "parser.y"
                                                                       {  
                    (yyval.node)=new Node("EnumDeclaration"); 
                    (yyval.node)->children.push_back((yyvsp[-4].node));
                    (yyval.node)->children.push_back(new Node("enum","Keyword", yylineno));
                    (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4139 "parser.tab.c"
    break;

  case 132:
#line 1069 "parser.y"
                                                       {  
                    (yyval.node)=new Node("EnumDeclaration"); 
                    (yyval.node)->children.push_back((yyvsp[-3].node));
                    (yyval.node)->children.push_back(new Node("enum","Keyword", yylineno));
                    (yyval.node)->children.push_back(new Node((yyvsp[-1].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4151 "parser.tab.c"
    break;

  case 133:
#line 1076 "parser.y"
                                                             {  
                    (yyval.node)=new Node("EnumDeclaration"); 
                    (yyval.node)->children.push_back(new Node("enum","Keyword", yylineno));
                    (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4163 "parser.tab.c"
    break;

  case 134:
#line 1083 "parser.y"
                                             {  
                    (yyval.node)=new Node("EnumDeclaration"); 
                    (yyval.node)->children.push_back(new Node("enum","Keyword", yylineno));
                    (yyval.node)->children.push_back(new Node((yyvsp[-1].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4174 "parser.tab.c"
    break;

  case 135:
#line 1090 "parser.y"
                                                 {  
                    (yyval.node)=new Node("ClassImplements"); 
                    (yyval.node)->children.push_back(new Node("implements","Keyword", yylineno));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4184 "parser.tab.c"
    break;

  case 136:
#line 1096 "parser.y"
                                                                                                    {  
                    (yyval.node)=new Node("EnumBody"); 
                    (yyval.node)->isBlock = true;
                    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-3].node));
                    (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
                    }
#line 4198 "parser.tab.c"
    break;

  case 137:
#line 1105 "parser.y"
                                                                                {  
                    (yyval.node)=new Node("EnumBody"); 
                    (yyval.node)->isBlock = true;
                    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-2].node));
                    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
                    }
#line 4210 "parser.tab.c"
    break;

  case 138:
#line 1112 "parser.y"
                                                                                            {  
                    (yyval.node)=new Node("EnumBody");
                    (yyval.node)->isBlock=true; 
                    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-2].node));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
                    }
#line 4223 "parser.tab.c"
    break;

  case 139:
#line 1120 "parser.y"
                                                                       {  
                    (yyval.node)=new Node("EnumBody");
                    (yyval.node)->isBlock=true; 
                    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
                    }
#line 4235 "parser.tab.c"
    break;

  case 140:
#line 1127 "parser.y"
                                                                                   {  
                    (yyval.node)=new Node("EnumBody");
                    (yyval.node)->isBlock=true; 
                    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
                    }
#line 4248 "parser.tab.c"
    break;

  case 141:
#line 1135 "parser.y"
                                                              {  
                    (yyval.node)=new Node("EnumBody");
                    (yyval.node)->isBlock=true; 
                    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
                    }
#line 4260 "parser.tab.c"
    break;

  case 142:
#line 1142 "parser.y"
                                                                           {  
                    (yyval.node)=new Node("EnumBody");
                    (yyval.node)->isBlock=true; 
                    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
                    }
#line 4272 "parser.tab.c"
    break;

  case 143:
#line 1149 "parser.y"
                                                      {  
                    (yyval.node)=new Node("EnumBody");
                    (yyval.node)->isBlock=true; 
                    (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
                    }
#line 4283 "parser.tab.c"
    break;

  case 144:
#line 1156 "parser.y"
                                    {  
                    (yyval.node)=new Node(";","Separator", yylineno);
                    }
#line 4291 "parser.tab.c"
    break;

  case 145:
#line 1159 "parser.y"
                                                        {  
                    (yyval.node)=new Node("EnumBodyDeclarations"); 
                    (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4301 "parser.tab.c"
    break;

  case 146:
#line 1165 "parser.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 4307 "parser.tab.c"
    break;

  case 147:
#line 1167 "parser.y"
                    {
                    (yyval.node)=new Node("EnumConstantList");
                    (yyval.node)->children.push_back((yyvsp[-2].node));
                    (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4318 "parser.tab.c"
    break;

  case 148:
#line 1174 "parser.y"
                                                                            {  
                    (yyval.node)=new Node("EnumConstant"); 
                    (yyval.node)->children.push_back(new Node((yyvsp[-4].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-2].node));
                    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4331 "parser.tab.c"
    break;

  case 149:
#line 1182 "parser.y"
                                                                   {  
                    (yyval.node)=new Node("EnumConstant"); 
                    (yyval.node)->children.push_back(new Node((yyvsp[-3].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4343 "parser.tab.c"
    break;

  case 150:
#line 1189 "parser.y"
                                                                      {  
                    (yyval.node)=new Node("EnumConstant"); 
                    (yyval.node)->children.push_back(new Node((yyvsp[-3].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
                    (yyval.node)->children.push_back((yyvsp[-1].node));
                    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
                    }
#line 4355 "parser.tab.c"
    break;

  case 151:
#line 1196 "parser.y"
                                                         {  
                    (yyval.node)=new Node("EnumConstant"); 
                    (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
                    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
                    }
#line 4366 "parser.tab.c"
    break;

  case 152:
#line 1202 "parser.y"
                                        {  
                    (yyval.node)=new Node("EnumConstant"); 
                    (yyval.node)->children.push_back(new Node((yyvsp[-1].str),"Identifier",yylineno));
                    (yyval.node)->children.push_back((yyvsp[0].node));
                    }
#line 4376 "parser.tab.c"
    break;

  case 153:
#line 1207 "parser.y"
                              {  
                    (yyval.node)=new Node((yyvsp[0].str),"Identifier",yylineno);
                    }
#line 4384 "parser.tab.c"
    break;

  case 154:
#line 1214 "parser.y"
    { (yyval.node)=new Node("InterfaceDeclaration"); 
      (yyval.node)->children.push_back((yyvsp[-4].node));
      (yyval.node)->children.push_back(new Node("interface","Keyword", yylineno));
      (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
      (yyval.node)->children.push_back((yyvsp[-1].node));
      (yyval.node)->children.push_back((yyvsp[0].node));}
#line 4395 "parser.tab.c"
    break;

  case 155:
#line 1221 "parser.y"
    { (yyval.node)=new Node("InterfaceDeclaration"); 
      (yyval.node)->children.push_back((yyvsp[-3].node));
      (yyval.node)->children.push_back(new Node("interface","Keyword", yylineno));
      (yyval.node)->children.push_back(new Node((yyvsp[-1].str),"Identifier",yylineno));
      (yyval.node)->children.push_back((yyvsp[0].node));}
#line 4405 "parser.tab.c"
    break;

  case 156:
#line 1227 "parser.y"
    {
        (yyval.node)=new Node("InterfaceDeclaration"); 
        (yyval.node)->children.push_back(new Node("interface","Keyword", yylineno));
        (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4417 "parser.tab.c"
    break;

  case 157:
#line 1235 "parser.y"
    {
        (yyval.node)=new Node("InterfaceDeclaration"); 
        (yyval.node)->children.push_back(new Node("interface","Keyword", yylineno));
        (yyval.node)->children.push_back(new Node((yyvsp[-1].str),"Identifier",yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4428 "parser.tab.c"
    break;

  case 158:
#line 1245 "parser.y"
    {
        (yyval.node)=new Node("ExtendsInterfaces");
        (yyval.node)->children.push_back(new Node("extends","Keyword", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4438 "parser.tab.c"
    break;

  case 159:
#line 1251 "parser.y"
    {
        (yyval.node)=new Node("ExtendsInterfaces");
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node("comma","Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4449 "parser.tab.c"
    break;

  case 160:
#line 1261 "parser.y"
    {
        (yyval.node)=new Node("InterfaceBody");
        (yyval.node)->isBlock=true;
        (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
    }
#line 4461 "parser.tab.c"
    break;

  case 161:
#line 1269 "parser.y"
    {
        (yyval.node)=new Node("InterfaceBody");
        (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
        (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
    }
#line 4471 "parser.tab.c"
    break;

  case 162:
#line 1277 "parser.y"
{ (yyval.node)=new Node("InterfaceMemberDeclarations"); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 4477 "parser.tab.c"
    break;

  case 163:
#line 1279 "parser.y"
    { (yyval.node)=new Node("InterfaceMemberDeclarations"); (yyval.node)->children.push_back((yyvsp[-1].node)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 4483 "parser.tab.c"
    break;

  case 164:
#line 1283 "parser.y"
{
    (yyval.node)=new Node("InterfaceMemberDeclaration");
    (yyval.node)->children.push_back((yyvsp[0].node));
}
#line 4492 "parser.tab.c"
    break;

  case 165:
#line 1288 "parser.y"
    {
        (yyval.node)=new Node("InterfaceMemberDeclaration");
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4501 "parser.tab.c"
    break;

  case 166:
#line 1295 "parser.y"
{
    (yyval.node)=new Node("ConstantDeclaration");
    (yyval.node)->children.push_back((yyvsp[0].node));
}
#line 4510 "parser.tab.c"
    break;

  case 167:
#line 1302 "parser.y"
{
    (yyval.node)=new Node("AbstractMethodDeclaration");
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back(new Node(";","Separator", yylineno));
}
#line 4520 "parser.tab.c"
    break;

  case 168:
#line 1322 "parser.y"
    {
        (yyval.node)=new Node("ArrayInitializer");
        (yyval.node)->isBlock=true;
        (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
    }
#line 4532 "parser.tab.c"
    break;

  case 169:
#line 1337 "parser.y"
    {
        (yyval.node)=new Node("ArrayInitializer");
        (yyval.node)->isBlock=true;
        (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
        (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
        (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
    }
#line 4544 "parser.tab.c"
    break;

  case 170:
#line 1347 "parser.y"
{
    (yyval.node)=new Node("VariableInitializerList");
    (yyval.node)->children.push_back((yyvsp[0].node));
}
#line 4553 "parser.tab.c"
    break;

  case 171:
#line 1352 "parser.y"
    {
        (yyval.node)=new Node("VariableInitializerList");
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4564 "parser.tab.c"
    break;

  case 172:
#line 1364 "parser.y"
    {
        (yyval.node)=new Node("Block");
        (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
        (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
    }
#line 4574 "parser.tab.c"
    break;

  case 173:
#line 1370 "parser.y"
    {
        (yyval.node)=new Node("Block");
        (yyval.node)->children.push_back(new Node("{","Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back(new Node("}","Separator", yylineno));
    }
#line 4585 "parser.tab.c"
    break;

  case 174:
#line 1380 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 4593 "parser.tab.c"
    break;

  case 175:
#line 1384 "parser.y"
    {
        (yyval.node)=new Node("BlockStatements");
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4603 "parser.tab.c"
    break;

  case 176:
#line 1393 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 4611 "parser.tab.c"
    break;

  case 177:
#line 1397 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 4619 "parser.tab.c"
    break;

  case 178:
#line 1403 "parser.y"
    {
        (yyval.node) = new Node("LocalVariableDeclarationStatement");
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
    }
#line 4629 "parser.tab.c"
    break;

  case 179:
#line 1412 "parser.y"
    {
        (yyval.node)=new Node("LocalVariableDeclaration");
        (yyval.node)->children.push_back(new Node("final","Keyword", yylineno));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4640 "parser.tab.c"
    break;

  case 180:
#line 1419 "parser.y"
    {
        (yyval.node)=new Node("LocalVariableDeclaration");
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4650 "parser.tab.c"
    break;

  case 181:
#line 1428 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 4658 "parser.tab.c"
    break;

  case 182:
#line 1432 "parser.y"
    {
        (yyval.node) = new Node("var", "Keyword", VAR);
    }
#line 4666 "parser.tab.c"
    break;

  case 183:
#line 1438 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4672 "parser.tab.c"
    break;

  case 184:
#line 1440 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4678 "parser.tab.c"
    break;

  case 185:
#line 1442 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4684 "parser.tab.c"
    break;

  case 186:
#line 1444 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4690 "parser.tab.c"
    break;

  case 187:
#line 1446 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4696 "parser.tab.c"
    break;

  case 188:
#line 1448 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4702 "parser.tab.c"
    break;

  case 189:
#line 1453 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4708 "parser.tab.c"
    break;

  case 190:
#line 1455 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4714 "parser.tab.c"
    break;

  case 191:
#line 1457 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4720 "parser.tab.c"
    break;

  case 192:
#line 1459 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4726 "parser.tab.c"
    break;

  case 193:
#line 1461 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4732 "parser.tab.c"
    break;

  case 194:
#line 1466 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4738 "parser.tab.c"
    break;

  case 195:
#line 1468 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4744 "parser.tab.c"
    break;

  case 196:
#line 1470 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4750 "parser.tab.c"
    break;

  case 197:
#line 1472 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4756 "parser.tab.c"
    break;

  case 198:
#line 1474 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4762 "parser.tab.c"
    break;

  case 199:
#line 1476 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4768 "parser.tab.c"
    break;

  case 200:
#line 1478 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4774 "parser.tab.c"
    break;

  case 201:
#line 1480 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4780 "parser.tab.c"
    break;

  case 202:
#line 1482 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 4786 "parser.tab.c"
    break;

  case 203:
#line 1487 "parser.y"
    {(yyval.node) = new Node(";", "Separator", yylineno);}
#line 4792 "parser.tab.c"
    break;

  case 204:
#line 1493 "parser.y"
    {
        (yyval.node) = new Node("LabeledStatement");
        (yyval.node)->children.push_back(new Node((yyvsp[-2].str), "Identifier",yylineno));
        (yyval.node)->children.push_back(new Node(":", "Operator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4803 "parser.tab.c"
    break;

  case 205:
#line 1504 "parser.y"
    {
        (yyval.node) = new Node("LabeledStatementNoShortIf");
        (yyval.node)->children.push_back(new Node((yyvsp[-2].str), "Identifier",yylineno));
        (yyval.node)->children.push_back(new Node(":", "Operator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 4814 "parser.tab.c"
    break;

  case 206:
#line 1514 "parser.y"
    {
        (yyval.node) = new Node("ExpressionStatement");
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
    }
#line 4824 "parser.tab.c"
    break;

  case 207:
#line 1524 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 4830 "parser.tab.c"
    break;

  case 208:
#line 1526 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 4836 "parser.tab.c"
    break;

  case 209:
#line 1528 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 4842 "parser.tab.c"
    break;

  case 210:
#line 1530 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 4848 "parser.tab.c"
    break;

  case 211:
#line 1532 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 4854 "parser.tab.c"
    break;

  case 212:
#line 1534 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 4860 "parser.tab.c"
    break;

  case 213:
#line 1536 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 4866 "parser.tab.c"
    break;

  case 214:
#line 1541 "parser.y"
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
#line 4883 "parser.tab.c"
    break;

  case 215:
#line 1558 "parser.y"
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
#line 4899 "parser.tab.c"
    break;

  case 216:
#line 1573 "parser.y"
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
#line 4915 "parser.tab.c"
    break;

  case 217:
#line 1586 "parser.y"
                            {
    if(!isDot)
    initializeSymTable();
}
#line 4924 "parser.tab.c"
    break;

  case 218:
#line 1593 "parser.y"
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
#line 4940 "parser.tab.c"
    break;

  case 219:
#line 1608 "parser.y"
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
#line 4956 "parser.tab.c"
    break;

  case 220:
#line 1622 "parser.y"
                                 {(yyval.node)=(yyvsp[0].node);}
#line 4962 "parser.tab.c"
    break;

  case 221:
#line 1622 "parser.y"
                                                                {(yyval.node)=(yyvsp[0].node);}
#line 4968 "parser.tab.c"
    break;

  case 222:
#line 1623 "parser.y"
                                                   {(yyval.node)=(yyvsp[0].node);}
#line 4974 "parser.tab.c"
    break;

  case 223:
#line 1623 "parser.y"
                                                                                           {(yyval.node)=(yyvsp[0].node);}
#line 4980 "parser.tab.c"
    break;

  case 224:
#line 1627 "parser.y"
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
#line 4998 "parser.tab.c"
    break;

  case 225:
#line 1641 "parser.y"
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
#line 5017 "parser.tab.c"
    break;

  case 226:
#line 1656 "parser.y"
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
#line 5036 "parser.tab.c"
    break;

  case 227:
#line 1671 "parser.y"
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
#line 5056 "parser.tab.c"
    break;

  case 228:
#line 1687 "parser.y"
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
#line 5075 "parser.tab.c"
    break;

  case 229:
#line 1702 "parser.y"
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
#line 5095 "parser.tab.c"
    break;

  case 230:
#line 1718 "parser.y"
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
#line 5115 "parser.tab.c"
    break;

  case 231:
#line 1734 "parser.y"
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
#line 5136 "parser.tab.c"
    break;

  case 232:
#line 1755 "parser.y"
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
#line 5154 "parser.tab.c"
    break;

  case 233:
#line 1769 "parser.y"
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
#line 5173 "parser.tab.c"
    break;

  case 234:
#line 1784 "parser.y"
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
#line 5192 "parser.tab.c"
    break;

  case 235:
#line 1799 "parser.y"
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
#line 5212 "parser.tab.c"
    break;

  case 236:
#line 1815 "parser.y"
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
#line 5231 "parser.tab.c"
    break;

  case 237:
#line 1830 "parser.y"
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
#line 5251 "parser.tab.c"
    break;

  case 238:
#line 1846 "parser.y"
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
#line 5271 "parser.tab.c"
    break;

  case 239:
#line 1862 "parser.y"
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
#line 5292 "parser.tab.c"
    break;

  case 240:
#line 1881 "parser.y"
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
#line 5311 "parser.tab.c"
    break;

  case 241:
#line 1898 "parser.y"
    {
       (yyval.node) = (yyvsp[0].node);
    }
#line 5319 "parser.tab.c"
    break;

  case 242:
#line 1902 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 5327 "parser.tab.c"
    break;

  case 243:
#line 1909 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 5335 "parser.tab.c"
    break;

  case 244:
#line 1915 "parser.y"
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
#line 5351 "parser.tab.c"
    break;

  case 245:
#line 1927 "parser.y"
                                            {(yyval.node) = (yyvsp[0].node);}
#line 5357 "parser.tab.c"
    break;

  case 246:
#line 1929 "parser.y"
                       {
                            (yyval.node) = new Node("StatementExpressionList");
                            (yyval.node)->children.push_back((yyvsp[-2].node));
                            (yyval.node)->children.push_back(new Node(",", "Separator", yylineno));
                            (yyval.node)->children.push_back((yyvsp[0].node));
                       }
#line 5368 "parser.tab.c"
    break;

  case 247:
#line 1937 "parser.y"
{ 
    (yyval.node) = new Node("BreakStatement");
    (yyval.node)->children.push_back(new Node("break", "Keyword", yylineno));
    (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));}
#line 5377 "parser.tab.c"
    break;

  case 248:
#line 1942 "parser.y"
 {
    (yyval.node) = new Node("BreakStatement");
    (yyval.node)->children.push_back(new Node("break", "Keyword", yylineno));
    (yyval.node)->children.push_back(new Node((yyvsp[0].str), "Identifier",yylineno));
    (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));}
#line 5387 "parser.tab.c"
    break;

  case 249:
#line 1949 "parser.y"
    {
        (yyval.node) = new Node("ContinueStatement");
        (yyval.node)->children.push_back(new Node("continue", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
    }
#line 5397 "parser.tab.c"
    break;

  case 250:
#line 1955 "parser.y"
 {
    (yyval.node) = new Node("ContinueStatement");
    (yyval.node)->children.push_back(new Node("continue", "Keyword", yylineno));
    (yyval.node)->children.push_back(new Node((yyvsp[-1].str), "Identifier",yylineno));
    (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
 }
#line 5408 "parser.tab.c"
    break;

  case 251:
#line 1963 "parser.y"
{
    (yyval.node) = new Node("ReturnStatement");
    (yyval.node)->children.push_back(new Node("return", "Keyword", yylineno));
    (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
}
#line 5418 "parser.tab.c"
    break;

  case 252:
#line 1969 "parser.y"
{
    (yyval.node) = new Node("ReturnStatement");
    (yyval.node)->children.push_back(new Node("return", "Keyword", yylineno));
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
}
#line 5429 "parser.tab.c"
    break;

  case 253:
#line 1977 "parser.y"
{
    (yyval.node) = new Node("ThrowStatement");
    (yyval.node)->children.push_back(new Node("throw", "Keyword", yylineno));
    (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));}
#line 5438 "parser.tab.c"
    break;

  case 254:
#line 1982 "parser.y"
 {
    (yyval.node) = new Node("ThrowStatement");
    (yyval.node)->children.push_back(new Node("throw", "Keyword", yylineno));
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back(new Node(";", "Separator", yylineno));
 }
#line 5449 "parser.tab.c"
    break;

  case 255:
#line 1992 "parser.y"
    {
        (yyval.node) = new Node("SynchronizedStatement");
        (yyval.node)->children.push_back(new Node("synchronized", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 5462 "parser.tab.c"
    break;

  case 256:
#line 2002 "parser.y"
    {
    (yyval.node) = new Node("TryStatement");
    (yyval.node)->children.push_back(new Node("try", "Keyword", yylineno));
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 5473 "parser.tab.c"
    break;

  case 257:
#line 2009 "parser.y"
            {
                (yyval.node) = new Node("TryStatement");
                (yyval.node)->children.push_back(new Node("try", "Keyword", yylineno));
                (yyval.node)->children.push_back((yyvsp[-1].node));
                (yyval.node)->children.push_back((yyvsp[0].node));
            }
#line 5484 "parser.tab.c"
    break;

  case 258:
#line 2016 "parser.y"
            {
                (yyval.node) = new Node("TryStatement");
                (yyval.node)->children.push_back(new Node("try", "Keyword", yylineno));
                (yyval.node)->children.push_back((yyvsp[-2].node));
                (yyval.node)->children.push_back((yyvsp[-1].node));
                (yyval.node)->children.push_back((yyvsp[0].node));}
#line 5495 "parser.tab.c"
    break;

  case 259:
#line 2024 "parser.y"
    {
        (yyval.node) = new Node("Catches");
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 5504 "parser.tab.c"
    break;

  case 260:
#line 2029 "parser.y"
        {
            (yyval.node) = new Node("Catches");
            (yyval.node)->children.push_back((yyvsp[-1].node));
            (yyval.node)->children.push_back((yyvsp[0].node));
        }
#line 5514 "parser.tab.c"
    break;

  case 261:
#line 2036 "parser.y"
    {
        (yyval.node) = new Node("CatchClause");
        (yyval.node)->children.push_back(new Node("catch", "Keyword", yylineno));
        (yyval.node)->children.push_back(new Node("(", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(")", "Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 5527 "parser.tab.c"
    break;

  case 262:
#line 2046 "parser.y"
    {
        (yyval.node) = new Node("Finally");
        (yyval.node)->children.push_back(new Node("finally", "Keyword", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 5537 "parser.tab.c"
    break;

  case 263:
#line 2057 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 5545 "parser.tab.c"
    break;

  case 264:
#line 2061 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 5553 "parser.tab.c"
    break;

  case 265:
#line 2067 "parser.y"
                {(yyval.node) = new Node((yyvsp[0].str),"Literal", INT,yylineno);}
#line 5559 "parser.tab.c"
    break;

  case 266:
#line 2068 "parser.y"
                  {(yyval.node) = new Node((yyvsp[0].str),"Literal" , BIN, yylineno);}
#line 5565 "parser.tab.c"
    break;

  case 267:
#line 2069 "parser.y"
                       {(yyval.node) = new Node((yyvsp[0].str),"Literal", FLOAT ,yylineno);}
#line 5571 "parser.tab.c"
    break;

  case 268:
#line 2070 "parser.y"
                  {(yyval.node) = new Node((yyvsp[0].str),"Literal", OCT, yylineno);}
#line 5577 "parser.tab.c"
    break;

  case 269:
#line 2071 "parser.y"
                      {(yyval.node) = new Node((yyvsp[0].str),"Literal", HEX_FLOAT, yylineno);}
#line 5583 "parser.tab.c"
    break;

  case 270:
#line 2072 "parser.y"
                     {(yyval.node) = new Node((yyvsp[0].str),"Literal", STRING, yylineno);}
#line 5589 "parser.tab.c"
    break;

  case 271:
#line 2073 "parser.y"
                  {(yyval.node) = new Node((yyvsp[0].str),"Literal", HEX, yylineno);}
#line 5595 "parser.tab.c"
    break;

  case 272:
#line 2074 "parser.y"
             {(yyval.node) = new Node("this","Keyword", yylineno);}
#line 5601 "parser.tab.c"
    break;

  case 273:
#line 2075 "parser.y"
                         {(yyval.node) = new Node("TextBlock","Literal",STRING, yylineno);}
#line 5607 "parser.tab.c"
    break;

  case 274:
#line 2076 "parser.y"
                   {(yyval.node) = new Node((yyvsp[0].str),"Literal", CHAR, yylineno);}
#line 5613 "parser.tab.c"
    break;

  case 275:
#line 2077 "parser.y"
                   {(yyval.node) = new Node("true","Keyword", BOOL);}
#line 5619 "parser.tab.c"
    break;

  case 276:
#line 2078 "parser.y"
                    {(yyval.node) = new Node("false","Keyword", BOOL);}
#line 5625 "parser.tab.c"
    break;

  case 277:
#line 2079 "parser.y"
                   {(yyval.node) = new Node("null","Keyword", _NULL);}
#line 5631 "parser.tab.c"
    break;

  case 278:
#line 2080 "parser.y"
                                            {
        (yyval.node) = new Node("PrimaryNoNewArray");
        (yyval.node)->type = (yyvsp[-1].node)->type;
        (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    }
#line 5643 "parser.tab.c"
    break;

  case 279:
#line 2088 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 5651 "parser.tab.c"
    break;

  case 280:
#line 2092 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 5659 "parser.tab.c"
    break;

  case 281:
#line 2096 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 5667 "parser.tab.c"
    break;

  case 282:
#line 2099 "parser.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 5673 "parser.tab.c"
    break;

  case 283:
#line 2104 "parser.y"
    { (yyval.node) = new Node("ClassInstanceCreationExpression");
       (yyval.node)->type = (yyvsp[-2].node)->type;
       (yyval.node)->children.push_back(new Node("new","Keyword", yylineno));
       (yyval.node)->children.push_back((yyvsp[-2].node));
       (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
       (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    }
#line 5685 "parser.tab.c"
    break;

  case 284:
#line 2112 "parser.y"
        { 
        (yyval.node) = new Node("ClassInstanceCreationExpression");
        (yyval.node)->type = (yyvsp[-3].node)->type;
        (yyval.node)->children.push_back(new Node("new","Keyword", yylineno));
        (yyval.node)->children.push_back((yyvsp[-3].node));
        (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[-1].node));
        (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
        }
#line 5699 "parser.tab.c"
    break;

  case 285:
#line 2125 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 5705 "parser.tab.c"
    break;

  case 286:
#line 2127 "parser.y"
    {
        (yyval.node) = new Node("ArgumentList");
        (yyval.node)->children.push_back((yyvsp[-2].node));
        (yyval.node)->children.push_back(new Node(",","Separator", yylineno));
        (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 5716 "parser.tab.c"
    break;

  case 287:
#line 2137 "parser.y"
     { 
       (yyval.node) = new Node("ArrayCreationExpression");
       (yyval.node)->type= (yyvsp[-1].node)->type;
       (yyval.node)->children.push_back(new Node("new","Keyword", yylineno));
       (yyval.node)->children.push_back((yyvsp[-1].node));
       (yyval.node)->children.push_back((yyvsp[0].node));
     }
#line 5728 "parser.tab.c"
    break;

  case 288:
#line 2145 "parser.y"
        { (yyval.node) = new Node("ArrayCreationExpression");
         (yyval.node)->type= (yyvsp[-2].node)->type;
       (yyval.node)->children.push_back(new Node("new","Keyword", yylineno));
       (yyval.node)->children.push_back((yyvsp[-2].node));
       (yyval.node)->children.push_back((yyvsp[-1].node));
       (yyval.node)->children.push_back((yyvsp[0].node));}
#line 5739 "parser.tab.c"
    break;

  case 289:
#line 2152 "parser.y"
        { (yyval.node) = new Node("ArrayCreationExpression");
         (yyval.node)->type= (yyvsp[-2].node)->type;
       (yyval.node)->children.push_back(new Node("new","Keyword", yylineno));
       (yyval.node)->children.push_back((yyvsp[-2].node));
       (yyval.node)->children.push_back((yyvsp[-1].node));
       (yyval.node)->children.push_back((yyvsp[0].node));}
#line 5750 "parser.tab.c"
    break;

  case 290:
#line 2159 "parser.y"
        { (yyval.node) = new Node("ArrayCreationExpression");
          (yyval.node)->type= (yyvsp[-1].node)->type;
       (yyval.node)->children.push_back(new Node("new","Keyword", yylineno));
       (yyval.node)->children.push_back((yyvsp[-1].node));
       (yyval.node)->children.push_back((yyvsp[0].node));}
#line 5760 "parser.tab.c"
    break;

  case 291:
#line 2165 "parser.y"
        { (yyval.node) = new Node("ArrayCreationExpression");
            (yyval.node)->type= (yyvsp[-2].node)->type;
       (yyval.node)->children.push_back(new Node("new","Keyword", yylineno));
       (yyval.node)->children.push_back((yyvsp[-2].node));
       (yyval.node)->children.push_back((yyvsp[-1].node));
       (yyval.node)->children.push_back((yyvsp[0].node));}
#line 5771 "parser.tab.c"
    break;

  case 292:
#line 2172 "parser.y"
        { (yyval.node) = new Node("ArrayCreationExpression");
            (yyval.node)->type= (yyvsp[-2].node)->type;
       (yyval.node)->children.push_back(new Node("new","Keyword", yylineno));
       (yyval.node)->children.push_back((yyvsp[-2].node));
       (yyval.node)->children.push_back((yyvsp[-1].node));
       (yyval.node)->children.push_back((yyvsp[0].node));}
#line 5782 "parser.tab.c"
    break;

  case 293:
#line 2183 "parser.y"
     {(yyval.node) = (yyvsp[0].node);}
#line 5788 "parser.tab.c"
    break;

  case 294:
#line 2185 "parser.y"
    {(yyval.node) = new Node("DimExprs");
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 5797 "parser.tab.c"
    break;

  case 295:
#line 2193 "parser.y"
     {
        (yyval.node) = new Node("DimExpr");
        if(!isDot){
            if((yyvsp[-1].node)->type != INT)
            {
                yyerror("Array index must be of type int");
                exit(0);
            }
        }
     (yyval.node)->children.push_back(new Node("[","Separator", yylineno));
     (yyval.node)->children.push_back((yyvsp[-1].node));
     (yyval.node)->children.push_back(new Node("]","Separator", yylineno));
     }
#line 5815 "parser.tab.c"
    break;

  case 296:
#line 2211 "parser.y"
    {
        (yyval.node) = new Node("Dims");
    (yyval.node)->children.push_back(new Node("[","Separator", yylineno));
    (yyval.node)->children.push_back(new Node("]","Separator", yylineno));
    }
#line 5825 "parser.tab.c"
    break;

  case 297:
#line 2217 "parser.y"
    {(yyval.node) = new Node("Dims");
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("[","Separator", yylineno));}
#line 5833 "parser.tab.c"
    break;

  case 298:
#line 2224 "parser.y"
    {(yyval.node) = new Node("FieldAccess");
        //$$->type= $3->type;
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(".","Separator", yylineno));
    (yyval.node)->children.push_back(new Node((yyvsp[0].str),"Identifier",yylineno));}
#line 5843 "parser.tab.c"
    break;

  case 299:
#line 2230 "parser.y"
    {(yyval.node) = new Node("FieldAccess");
    //$$->type= $3->type;
    (yyval.node)->children.push_back(new Node("super","Keyword", yylineno));
    (yyval.node)->children.push_back(new Node(".","Separator", yylineno));
    (yyval.node)->children.push_back(new Node((yyvsp[0].str),"Identifier",yylineno));}
#line 5853 "parser.tab.c"
    break;

  case 300:
#line 2239 "parser.y"
    {(yyval.node) = new Node("MethodInvocation");
     //$$->type= $1->type;
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    }
#line 5864 "parser.tab.c"
    break;

  case 301:
#line 2246 "parser.y"
     {(yyval.node) = new Node("MethodInvocation");
       // $$->type= $1->type;
     (yyval.node)->children.push_back((yyvsp[-3].node));
     (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
     (yyval.node)->children.push_back((yyvsp[-1].node));
     (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
     }
#line 5876 "parser.tab.c"
    break;

  case 302:
#line 2254 "parser.y"
    {(yyval.node) = new Node("MethodInvocation");
    //$$->type= $3->type;
    (yyval.node)->children.push_back((yyvsp[-4].node));
    (yyval.node)->children.push_back(new Node(".","Separator", yylineno));
    (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    }
#line 5889 "parser.tab.c"
    break;

  case 303:
#line 2263 "parser.y"
    {(yyval.node) = new Node("MethodInvocation");
   // $$->type= $3->type;
    (yyval.node)->children.push_back((yyvsp[-5].node));
    (yyval.node)->children.push_back(new Node(".","Separator", yylineno));
    (yyval.node)->children.push_back(new Node((yyvsp[-3].str),"Identifier",yylineno));
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    }
#line 5903 "parser.tab.c"
    break;

  case 304:
#line 2273 "parser.y"
    {(yyval.node) = new Node("MethodInvocation");
    //$$->type= $3->type;
    (yyval.node)->children.push_back(new Node("super","Keyword", yylineno));
    (yyval.node)->children.push_back(new Node(".","Separator", yylineno));
    (yyval.node)->children.push_back(new Node((yyvsp[-2].str),"Identifier",yylineno));
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    }
#line 5916 "parser.tab.c"
    break;

  case 305:
#line 2282 "parser.y"
    {(yyval.node) = new Node("MethodInvocation");
    //$$->type= $3->type;
    (yyval.node)->children.push_back(new Node("super","Keyword", yylineno));
    (yyval.node)->children.push_back(new Node(".","Separator", yylineno));
    (yyval.node)->children.push_back(new Node((yyvsp[-3].str),"Identifier",yylineno));
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    }
#line 5930 "parser.tab.c"
    break;

  case 306:
#line 2295 "parser.y"
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
#line 5949 "parser.tab.c"
    break;

  case 307:
#line 2310 "parser.y"
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
#line 5968 "parser.tab.c"
    break;

  case 308:
#line 2328 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 5974 "parser.tab.c"
    break;

  case 309:
#line 2330 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 5980 "parser.tab.c"
    break;

  case 310:
#line 2332 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 5986 "parser.tab.c"
    break;

  case 311:
#line 2334 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 5992 "parser.tab.c"
    break;

  case 312:
#line 2339 "parser.y"
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
#line 6009 "parser.tab.c"
    break;

  case 313:
#line 2355 "parser.y"
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
#line 6024 "parser.tab.c"
    break;

  case 314:
#line 2369 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 6030 "parser.tab.c"
    break;

  case 315:
#line 2371 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 6036 "parser.tab.c"
    break;

  case 316:
#line 2373 "parser.y"
    {(yyval.node) = new Node("UnaryExpression");
     (yyval.node)->type= (yyvsp[0].node)->type;
    (yyval.node)->children.push_back(new Node("+","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));}
#line 6045 "parser.tab.c"
    break;

  case 317:
#line 2378 "parser.y"
    {(yyval.node) = new Node("UnaryExpression");
        (yyval.node)->type= (yyvsp[0].node)->type;
    (yyval.node)->children.push_back(new Node("-","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));}
#line 6054 "parser.tab.c"
    break;

  case 318:
#line 2383 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 6060 "parser.tab.c"
    break;

  case 319:
#line 2388 "parser.y"
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
#line 6076 "parser.tab.c"
    break;

  case 320:
#line 2403 "parser.y"
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
#line 6092 "parser.tab.c"
    break;

  case 321:
#line 2418 "parser.y"
   {(yyval.node) = (yyvsp[0].node);}
#line 6098 "parser.tab.c"
    break;

  case 322:
#line 2420 "parser.y"
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
#line 6114 "parser.tab.c"
    break;

  case 323:
#line 2432 "parser.y"
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
#line 6130 "parser.tab.c"
    break;

  case 324:
#line 2444 "parser.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 6136 "parser.tab.c"
    break;

  case 325:
#line 2449 "parser.y"
    {(yyval.node) = new Node("CastExpression");
     (yyval.node)->type= (yyvsp[-2].node)->type;
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6148 "parser.tab.c"
    break;

  case 326:
#line 2457 "parser.y"
    {
    (yyval.node) = new Node("CastExpression");
    (yyval.node)->type= (yyvsp[-3].node)->type;
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6162 "parser.tab.c"
    break;

  case 327:
#line 2467 "parser.y"
    {
    (yyval.node) = new Node("CastExpression");
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6174 "parser.tab.c"
    break;

  case 328:
#line 2475 "parser.y"
    {
    (yyval.node) = new Node("CastExpression");
    (yyval.node)->children.push_back(new Node("(","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node(")","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6187 "parser.tab.c"
    break;

  case 329:
#line 2487 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6195 "parser.tab.c"
    break;

  case 330:
#line 2491 "parser.y"
    {
    (yyval.node) = new Node("MultiplicativeExpression");
    (yyval.node)->type=widen((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("*","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6207 "parser.tab.c"
    break;

  case 331:
#line 2499 "parser.y"
    {
    (yyval.node) = new Node("MultiplicativeExpression");
    (yyval.node)->type=widen((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("/","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6219 "parser.tab.c"
    break;

  case 332:
#line 2507 "parser.y"
    {
    (yyval.node) = new Node("MultiplicativeExpression");
    (yyval.node)->type=widen((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("%","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6231 "parser.tab.c"
    break;

  case 333:
#line 2518 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6239 "parser.tab.c"
    break;

  case 334:
#line 2522 "parser.y"
    {
    (yyval.node) = new Node("AdditiveExpression");
    (yyval.node)->type=widen((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("+","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6251 "parser.tab.c"
    break;

  case 335:
#line 2530 "parser.y"
    {
    (yyval.node) = new Node("AdditiveExpression");
    (yyval.node)->type=widen((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("-","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6263 "parser.tab.c"
    break;

  case 336:
#line 2541 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6271 "parser.tab.c"
    break;

  case 337:
#line 2545 "parser.y"
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
#line 6289 "parser.tab.c"
    break;

  case 338:
#line 2559 "parser.y"
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
#line 6307 "parser.tab.c"
    break;

  case 339:
#line 2573 "parser.y"
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
#line 6325 "parser.tab.c"
    break;

  case 340:
#line 2590 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6333 "parser.tab.c"
    break;

  case 341:
#line 2594 "parser.y"
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
#line 6352 "parser.tab.c"
    break;

  case 342:
#line 2609 "parser.y"
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
#line 6370 "parser.tab.c"
    break;

  case 343:
#line 2623 "parser.y"
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
#line 6388 "parser.tab.c"
    break;

  case 344:
#line 2637 "parser.y"
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
#line 6406 "parser.tab.c"
    break;

  case 345:
#line 2651 "parser.y"
    {
    (yyval.node) = new Node("RelationalExpression");
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back(new Node("instanceof","Separator", yylineno));
    (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 6417 "parser.tab.c"
    break;

  case 346:
#line 2661 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6425 "parser.tab.c"
    break;

  case 347:
#line 2665 "parser.y"
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
#line 6443 "parser.tab.c"
    break;

  case 348:
#line 2679 "parser.y"
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
#line 6461 "parser.tab.c"
    break;

  case 349:
#line 2696 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6469 "parser.tab.c"
    break;

  case 350:
#line 2700 "parser.y"
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
#line 6487 "parser.tab.c"
    break;

  case 351:
#line 2717 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 6495 "parser.tab.c"
    break;

  case 352:
#line 2721 "parser.y"
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
#line 6513 "parser.tab.c"
    break;

  case 353:
#line 2738 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6521 "parser.tab.c"
    break;

  case 354:
#line 2742 "parser.y"
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
#line 6539 "parser.tab.c"
    break;

  case 355:
#line 2759 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6547 "parser.tab.c"
    break;

  case 356:
#line 2763 "parser.y"
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
#line 6565 "parser.tab.c"
    break;

  case 357:
#line 2780 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6573 "parser.tab.c"
    break;

  case 358:
#line 2784 "parser.y"
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
#line 6591 "parser.tab.c"
    break;

  case 359:
#line 2801 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6599 "parser.tab.c"
    break;

  case 360:
#line 2805 "parser.y"
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
#line 6624 "parser.tab.c"
    break;

  case 361:
#line 2829 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6632 "parser.tab.c"
    break;

  case 362:
#line 2833 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6640 "parser.tab.c"
    break;

  case 363:
#line 2840 "parser.y"
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
#line 6658 "parser.tab.c"
    break;

  case 364:
#line 2857 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6666 "parser.tab.c"
    break;

  case 365:
#line 2861 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6674 "parser.tab.c"
    break;

  case 366:
#line 2865 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6682 "parser.tab.c"
    break;

  case 367:
#line 2872 "parser.y"
    {
    (yyval.node) = new Node("=","Separator", yylineno);
    }
#line 6690 "parser.tab.c"
    break;

  case 368:
#line 2876 "parser.y"
    {
    (yyval.node) = new Node("+=","Separator", yylineno);
    }
#line 6698 "parser.tab.c"
    break;

  case 369:
#line 2880 "parser.y"
    {
    (yyval.node) = new Node("-=","Separator", yylineno);
    }
#line 6706 "parser.tab.c"
    break;

  case 370:
#line 2884 "parser.y"
    {
    (yyval.node) = new Node("*=","Separator", yylineno);
    }
#line 6714 "parser.tab.c"
    break;

  case 371:
#line 2888 "parser.y"
    {
    (yyval.node) = new Node("/=","Separator", yylineno);
    }
#line 6722 "parser.tab.c"
    break;

  case 372:
#line 2892 "parser.y"
    {
    (yyval.node) = new Node("%=","Separator", yylineno);
    }
#line 6730 "parser.tab.c"
    break;

  case 373:
#line 2896 "parser.y"
    {
    (yyval.node) = new Node("<<=","Separator", yylineno);
    }
#line 6738 "parser.tab.c"
    break;

  case 374:
#line 2900 "parser.y"
    {
    (yyval.node) = new Node(">>=","Separator", yylineno);
    }
#line 6746 "parser.tab.c"
    break;

  case 375:
#line 2904 "parser.y"
    {
    (yyval.node) = new Node(">>>=","Separator", yylineno);
    }
#line 6754 "parser.tab.c"
    break;

  case 376:
#line 2908 "parser.y"
    {
    (yyval.node) = new Node("&=","Separator", yylineno);
    }
#line 6762 "parser.tab.c"
    break;

  case 377:
#line 2912 "parser.y"
    {
    (yyval.node) = new Node("|=","Separator", yylineno);
    }
#line 6770 "parser.tab.c"
    break;

  case 378:
#line 2916 "parser.y"
    {
    (yyval.node) = new Node("^=","Separator", yylineno);
    }
#line 6778 "parser.tab.c"
    break;

  case 379:
#line 2923 "parser.y"
    {
    (yyval.node) = (yyvsp[0].node);
    }
#line 6786 "parser.tab.c"
    break;


#line 6790 "parser.tab.c"

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
#line 2927 "parser.y"



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
    fout<<"Lexeme,Tokens,Type,LineNo"<<endl;
    for(auto i = a->entries.begin(); i != a->entries.end(); i++){
        for(auto j = i->second.begin(); j != i->second.end(); j++)
            fout<<i->first<<","<<"Identifier"<<","<<enum_types[j->type]<<","<<j->lineno<<endl;
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
    cout<<isDot<<endl;
    if(!isDot){
        cout<<"Voilla"<<endl;
    initializeSymTable();
    }
    yyparse();
    cout<<"Exit yyparse()"<<endl;
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
