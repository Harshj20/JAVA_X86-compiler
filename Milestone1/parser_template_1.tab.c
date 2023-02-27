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
#line 1 "parser_template_1.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int node_count = 0;

void print_node(char* label) {
    printf("node%d[label=\"%s\"];\n", node_count++, label);
}

void print_edge(int from, int to) {
    printf("node%d -> node%d;\n", from, to);
}

void print_token(char* token_type, char* token_value) {
    print_node(token_value);
    print_edge(node_count - 1, node_count);
    print_node(token_type);
    print_edge(node_count - 1, node_count);
}

#line 95 "parser_template_1.tab.c"

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
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TEMPLATE_1_TAB_H_INCLUDED
# define YY_YY_PARSER_TEMPLATE_1_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

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
    Literal = 364,
    s_open_paren = 365,
    s_close_paren = 366,
    s_open_curly_bracket = 367,
    s_close_curly_bracket = 368,
    s_open_square_bracket = 369,
    s_close_square_bracket = 370,
    s_semicolon = 371,
    s_comma = 372,
    s_dot = 373,
    s_varargs = 374,
    s_double_colon = 375
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "parser_template_1.y"

    char* string;
    int integer;
    double floating_point;
    bool boolean;

#line 275 "parser_template_1.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TEMPLATE_1_TAB_H_INCLUDED  */



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
#define YYFINAL  83
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1574

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  121
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  176
/* YYNRULES -- Number of rules.  */
#define YYNRULES  389
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  608

#define YYUNDEFTOK  2
#define YYMAXUTOK   375


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
     115,   116,   117,   118,   119,   120
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,    94,   101,   102,   106,   107,   116,   120,
     121,   127,   144,   145,   149,   150,   154,   155,   159,   160,
     161,   162,   163,   167,   168,   172,   173,   186,   187,   192,
     193,   222,   223,   228,   231,   233,   236,   238,   242,   243,
     269,   328,   331,   333,   337,   338,   342,   343,   344,   348,
     352,   356,   357,   361,   365,   366,   367,   371,   374,   376,
     380,   381,   384,   386,   389,   391,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   407,   411,   412,   417,   420,
     422,   426,   427,   431,   432,   433,   434,   438,   439,   440,
     441,   445,   448,   449,   453,   454,   458,   459,   460,   461,
     462,   463,   464,   468,   471,   472,   476,   477,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   493,   494,   498,
     499,   503,   506,   508,   511,   513,   517,   518,   522,   525,
     526,   530,   531,   535,   536,   540,   544,   545,   548,   549,
     553,   557,   561,   562,   566,   570,   571,   575,   579,   583,
     586,   587,   590,   591,   595,   596,   600,   601,   602,   606,
     610,   614,   617,   618,   622,   623,   624,   625,   629,   630,
     633,   634,   638,   642,   645,   646,   649,   650,   653,   654,
     658,   659,   663,   664,   667,   668,   672,   676,   680,   683,
     684,   687,   688,   692,   693,   697,   701,   704,   705,   709,
     710,   714,   715,   719,   723,   723,   723,   723,   723,   727,
     727,   727,   727,   727,   727,   727,   727,   727,   727,   729,
     731,   735,   737,   737,   737,   737,   737,   737,   737,   739,
     745,   749,   749,   752,   753,   753,   754,   754,   756,   756,
     757,   758,   759,   759,   760,   762,   763,   763,   765,   766,
     769,   770,   771,   771,   771,   772,   772,   773,   773,   774,
     775,   776,   776,   777,   778,   779,   779,   780,   781,   781,
     782,   782,   783,   783,   784,   784,   867,   868,   872,   873,
     874,   875,   876,   877,   878,   879,   880,   881,   885,   886,
     887,   888,   892,   893,   894,   898,   898,   902,   903,   907,
     908,   909,   913,   914,   918,   919,   920,   921,   922,   923,
     927,   928,   929,   930,   931,   932,   933,   937,   938,   939,
     940,   944,   945,   949,   994,   995,   999,  1003,  1004,  1005,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,
    1019,  1020,  1024,  1025,  1026,  1029,  1030,  1034,  1035,  1039,
    1040,  1044,  1045,  1049,  1050,  1054,  1055,  1056,  1060,  1061,
    1062,  1063,  1064,  1065,  1074,  1075,  1076,  1077,  1081,  1082,
    1083,  1087,  1088,  1089,  1090,  1094,  1095,  1096,  1100,  1104,
    1108,  1109,  1110,  1111,  1115,  1116,  1117,  1121,  1125,  1129
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "o_arrow", "Identifier", "Literal", "s_open_paren", "s_close_paren",
  "s_open_curly_bracket", "s_close_curly_bracket", "s_open_square_bracket",
  "s_close_square_bracket", "s_semicolon", "s_comma", "s_dot", "s_varargs",
  "s_double_colon", "$accept", "op_Expression", "VariableDeclaratorList",
  "VariableDeclarator", "VariableDeclaratorId", "VariableInitializer",
  "TypeIdentifier", "Type", "PrimitiveType", "NumericType", "IntegralType",
  "FloatingPointType", "ReferenceType", "ArrayType", "Dims", "ClassType",
  "ArrayInitializer", "op_s_comma", "op_VariableInitializerList",
  "VariableInitializerList", "Expression", "Block", "op_BlockStatements",
  "BlockStatements", "BlockStatement", "LocalVariableDeclarationStatement",
  "LocalVariableDeclaration", "LocalVariableType", "LocalClassDeclaration",
  "ClassDeclaration", "NormalClassDeclaration", "op_ClassModifiers",
  "ClassModifiers", "op_classextends", "op_classpermits", "ClassModifier",
  "ClassExtends", "ClassPermits", "ClassBody", "op_ClassBodyDeclarations",
  "ClassBodyDeclarations", "ClassBodyDeclaration",
  "ClassMemberDeclaration", "FieldDeclaration", "op_field_modifiers",
  "FieldModifiers", "FieldModifier", "MethodDeclaration",
  "op_MethodModifiers", "MethodModifiers", "MethodModifier",
  "MethodHeader", "Result", "MethodDeclarator", "op_Dims",
  "op_FormalParameterList", "op_ReceiverParameter", "ReceiverParameter",
  "op_IdentifierDot", "FormalParameterList", "FormalParameter",
  "VariableArityParameter", "VariableModifiers", "op_VariableModifiers",
  "VariableModifier", "Throws", "ExceptionTypeList", "ExceptionType",
  "MethodBody", "InstanceInitializer", "StaticInitializer",
  "ConstructorDeclaration", "op_Throws", "op_ConstructorModifiers",
  "ConstructorModifiers", "ConstructorModifier", "ConstructorDeclarator",
  "SimpleClassType", "ConstructorBody", "op_ExplicitConstructorInvocation",
  "ExplicitConstructorInvocation", "ArgumentList", "op_ArgumentList",
  "EnumDeclaration", "EnumBody", "op_enum_constant_list", "op_comma",
  "op_enum_body_declarations", "EnumConstantList", "EnumConstant",
  "op_enum_constant", "EnumBodyDeclarations", "RecordDeclaration",
  "RecordBody", "RecordBodyDeclarations", "op_RecordBodyDeclarations",
  "RecordBodyDeclaration", "CompactConstructorDeclaration", "RecordHeader",
  "op_RecordComponentList", "RecordComponentList", "RecordComponent",
  "VariableArityRecordComponent", "Statement",
  "StatementWithoutTrailingSubstatement", "EmptyStatement",
  "LabeledStatement", "ExpressionStatement", "StatementExpression",
  "IfThenStatement", "WhileStatement", "ForStatement", "BasicForStatement",
  "op_ForInit", "op_ForUpdate", "ForInit", "ForUpdate",
  "StatementExpressionList", "op_StatementExpression",
  "EnhancedForStatement", "BreakStatement", "op_Identifier",
  "ContinueStatement", "ReturnStatement", "ThrowStatement",
  "SynchronizedStatement", "TryStatement", "op_Catches", "Catches",
  "CatchClause", "CatchFormalParameter", "CatchType", "Finally",
  "TryWithResourcesStatement", "op_Finally", "ResourceSpecification",
  "op_o_colon", "ResourceList", "Resource", "VariableAccess", "Primary",
  "PrimaryNoNewArray", "ClassLiteral", "ClassInstanceCreationExpression",
  "UnqualifiedClassInstanceCreationExpression", "ClassTypeToInstantiate",
  "FieldAccess", "ArrayAccess", "MethodInvocation", "MethodReference",
  "ArrayCreationExpression", "DimExprs", "DimExpr", "AssignmentExpression",
  "Assignment", "LeftHandSide", "AssignmentOperator",
  "ConditionalExpression", "ConditionalOrExpression",
  "ConditionalAndExpression", "InclusiveOrExpression",
  "ExclusiveOrExpression", "AndExpression", "EqualityExpression",
  "RelationalExpression", "ShiftExpression", "AdditiveExpression",
  "MultiplicativeExpression", "UnaryExpression", "PreIncrementExpression",
  "PreDecrementExpression", "UnaryExpressionNotPlusMinus",
  "PostfixExpression", "PostIncrementExpression",
  "PostDecrementExpression", "CastExpression", YY_NULLPTR
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
     375
};
# endif

#define YYPACT_NINF (-485)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-387)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1262,   -36,  -485,  -485,  -485,  -485,  -485,  -485,   120,  -485,
     -71,  -485,   -60,  1262,  1262,  1262,  1262,  -485,  -485,  1262,
      77,  -485,   -10,   -36,  -485,  -485,    35,    56,    53,  -485,
     135,    17,  -485,  -485,  -485,   629,  1457,  -485,  -485,  -485,
    -485,  -485,  1446,  -485,    52,    83,   102,   123,   110,    41,
     272,   201,   183,   206,  -485,  -485,  -485,  -485,   209,  -485,
    -485,  -485,    97,  -485,   112,  -485,   -53,   153,  -485,    46,
     127,   149,   182,   283,    53,  -485,  -485,  -485,  -485,  -485,
    -485,   -48,   190,  -485,  -485,   203,   216,   300,  1262,  1146,
      50,    -9,   221,   223,    -8,   235,  1262,  -485,  -485,  -485,
    -485,  -485,  -485,  -485,  -485,  -485,  -485,  -485,  -485,  1262,
    1262,  1262,  1262,  1262,  1262,  1262,  1262,  1262,  1235,  1262,
    1262,  1262,  1262,  1262,  1262,  1262,  1262,  1262,  1262,  1262,
    1262,  -485,  -485,   -10,   335,   246,  1146,   244,   -10,   256,
     250,   244,   -10,  1262,   252,  -485,  -485,  1262,  -485,   361,
    -485,  -485,   257,  -485,   264,   263,   246,   143,  -485,   282,
    -485,  -485,  -485,  -485,   389,   294,  -485,  -485,   295,  -485,
      83,   303,   102,   123,   110,    41,   272,   272,  -485,  -485,
      48,   201,   201,   201,   201,   183,   183,   183,   206,   206,
    -485,  -485,  -485,  -485,  -485,   288,  -485,   299,  1177,  -485,
    -485,  1262,  -485,  -485,  -485,   315,  1262,  -485,  -485,  1262,
    -485,  -485,   319,   321,  1262,  -485,  1262,  -485,  1262,  -485,
    -485,   322,  -485,   326,  -485,  -485,   318,   327,  -485,   334,
    -485,   343,   344,  -485,  1177,  -485,   347,   877,  -485,  -485,
    1262,  -485,  -485,  -485,  -485,   776,   565,  -485,   624,  1400,
    1436,   313,  1466,  -485,  -485,  -485,  -485,  -485,   721,  -485,
    -485,  -485,  -485,     9,  -485,   630,   348,  -485,   919,  -485,
    -485,  1235,  -485,   383,  -485,   309,  -485,   524,  -485,  -485,
    -485,   250,  -485,   291,  -485,  -485,   346,  -485,  -485,   358,
     358,   796,   365,   366,  -485,  -485,  -485,  1262,  -485,  -485,
     370,  1262,   205,   371,   376,  1262,  -485,  -485,   373,  -485,
     833,  -485,   377,  -485,  -485,  -485,  1231,   469,  -485,  -485,
    -485,  -485,  -485,   381,  -485,  -485,  -485,  -485,  -485,  -485,
    -485,  -485,  -485,  -485,  -485,  -485,   108,   163,  -485,  -485,
    -485,   209,   248,   281,   250,   250,   250,  -485,  -485,  -485,
    -485,   -34,   -10,  -485,  -485,  -485,  -485,  -485,  -485,  -485,
    -485,  -485,    93,   384,  -485,  -485,  -485,  -485,  -485,  -485,
    -485,  -485,  -485,   451,   390,  -485,  -485,  -485,  -485,  -485,
     358,  -485,  -485,  1115,  1262,  -485,  1262,  -485,  1318,   490,
     394,  1262,  1064,  -485,  -485,  -485,  -485,  -485,   -34,  -485,
    -485,  -485,   482,   396,   401,  1177,   -10,   397,   398,  -485,
    -485,  -485,  -485,   407,   451,   250,  -485,   406,  1235,  -485,
     413,   403,   410,  -485,  -485,   411,   417,    53,  -485,   423,
     430,  -485,   135,   -52,   427,   518,   520,   490,   490,   431,
    -485,  -485,   250,   488,  -485,   440,  -485,  1235,   438,  -485,
    -485,  -485,   -34,  1235,  -485,   -78,  -485,   434,  1369,  -485,
     445,    15,   437,  1262,  1287,  -485,  1262,  1064,   394,  -485,
     446,  1318,   250,   394,  -485,  -485,   518,  -485,  1064,   444,
     250,   318,   449,   453,   454,  -485,   457,   -64,   467,  -485,
     462,  -485,   963,  -485,  -485,    15,  -485,   250,   -68,   473,
     142,   721,  -485,   173,   466,   540,   477,  -485,   474,  -485,
    1235,  -485,   484,   403,   483,  -485,  -485,  -485,  -485,   -57,
     495,   485,  -485,  -485,  -485,  -485,   444,  -485,   250,   487,
     318,  -485,   492,   440,  -485,   498,  -485,  1235,  -485,   250,
    -485,   497,  1005,  -485,   500,  -485,  1262,  1262,   181,   499,
     -14,  -485,  -485,  -485,   469,   -63,  1064,  -485,  1287,   250,
     394,  -485,   444,  -485,  -485,   877,   501,  -485,  -485,  -485,
    -485,   220,  -485,  -485,   -10,   506,   507,    59,  -485,   509,
    -485,   512,  -485,  -485,   514,  -485,  -485,  -485,  -485,  -485,
    -485,  -485,  -485,   511,   516,  1262,  1262,  -485,  1064,  -485,
    -485,   517,   519,  -485,   521,   522,  -485,  -485
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,    15,    18,    22,    24,    23,    20,    21,     0,    19,
       0,   280,     0,     0,     0,     0,     0,    11,   278,     0,
       0,    31,     0,    14,    16,    17,     0,     0,   327,     3,
     384,   276,   279,   283,   292,   284,   285,   286,   287,   277,
      40,   325,     0,   324,   342,   345,   347,   349,   351,   353,
     355,   358,   364,   368,   371,   375,   376,   377,   380,   385,
     386,   383,     0,   123,     0,    15,    11,     0,    14,     0,
       0,     0,     0,     0,     0,   284,   285,   381,   378,   379,
     382,     0,     0,     1,    27,     0,     0,     0,   170,     0,
       0,     0,    28,     0,     0,     0,     0,   334,   335,   331,
     332,   333,   339,   341,   340,   336,   337,   338,   330,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   387,   388,    29,     0,     0,     0,     0,   122,   321,
       0,     0,   122,   170,   300,   313,   291,     0,   282,     0,
     312,   316,   168,   171,     0,     0,     0,     0,   281,    11,
      32,   293,   315,   310,     0,   299,   294,   311,     0,   326,
     346,     0,   348,   350,   352,   354,   356,   357,   363,    26,
      25,   359,   361,   360,   362,   365,   366,   367,   369,   370,
     372,   373,   374,    30,   290,   297,   298,     0,    36,   319,
     317,     0,   322,   320,   318,     0,   170,   389,   289,     0,
     304,   302,     0,     0,   170,   288,   170,   303,   344,    28,
     323,    38,    10,    34,    37,     9,   295,     0,   169,   301,
     314,     0,     0,   343,     0,    35,     0,    92,   296,   308,
     170,   305,   307,    39,    33,    69,    71,   115,    68,    67,
      66,    70,    74,   114,   101,   102,    73,    72,    58,    90,
     147,    89,    54,     0,    59,    60,     0,    80,    92,    83,
      87,     0,    93,    94,    88,     0,   105,   106,    84,    85,
      86,     0,   153,   154,    55,    56,     0,   148,    69,   246,
     246,    71,     0,     0,    68,    67,    66,     2,    70,    74,
       0,     0,     0,     0,    11,     0,   219,   209,     0,    43,
      58,    47,     0,    46,    53,   139,     0,   136,    48,   204,
     210,   205,   211,     0,   206,   207,   208,   231,   232,   212,
     213,   214,   217,   216,   218,   254,   283,   286,   222,   223,
     224,     0,   225,   226,     0,     0,     0,    71,    61,    78,
      82,     0,    12,    13,   100,    98,    97,    96,    99,    95,
     120,   119,     0,     0,   111,   113,   110,   109,   108,   112,
     116,   107,   160,   150,     0,   158,   157,   156,   155,   309,
     246,   245,   248,   138,     0,   249,     0,   250,   138,   255,
       0,     0,     0,    41,    45,    49,    52,    51,     0,   140,
     137,   221,    62,     0,     0,     0,   122,     0,     4,     6,
     146,   145,   103,     0,   118,     0,   151,     0,   126,   247,
     239,   242,     0,   235,   238,     0,     0,   274,   272,   268,
     270,   273,     0,   284,     0,     0,   252,   257,   255,     0,
     220,    50,     0,    64,    63,   174,   172,   197,     0,     7,
       8,    91,     0,   126,   117,     0,   141,   142,   162,   149,
     129,   138,     0,     0,     0,   241,     2,     0,     0,   269,
       0,   138,     0,     0,   253,   258,   265,   256,     0,    75,
       0,     0,    65,   184,   176,   175,   180,     0,     0,   198,
     199,   202,    92,   187,     5,   138,   144,     0,     0,   280,
       0,    58,   163,     0,     0,     0,     0,   125,   131,   134,
       0,   127,     0,   242,     0,   229,   251,   267,   271,   261,
       0,     0,   263,   266,   264,   230,    76,    57,     0,     0,
     182,   177,   178,     0,   201,     0,   196,     0,   193,     0,
     192,     0,    92,   194,     0,   143,   170,   170,     0,     0,
       0,   130,   128,   159,   138,     0,     0,   243,   236,     0,
       0,   260,    77,   185,   183,    92,     0,   179,   181,   203,
     200,     0,   188,   190,   122,     0,     0,     0,   161,     0,
     132,     0,   133,   244,     0,   237,   240,   262,   259,   186,
     173,   195,   121,     0,     0,   170,   170,   135,     0,   165,
     164,     0,     0,   233,     0,     0,   166,   167
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -485,  -294,  -377,  -485,  -484,   231,   -61,  -232,    -6,     6,
    -485,  -485,   -65,   -58,    -5,    -7,   113,  -485,  -485,   405,
      72,   134,   140,   332,  -485,  -485,  -342,  -485,  -485,  -242,
    -485,  -485,   379,  -485,  -485,  -485,  -485,  -485,  -463,    80,
     386,  -444,  -485,  -485,  -485,   387,  -485,  -485,  -485,   375,
    -485,  -485,  -485,  -485,    -1,   162,   208,  -485,  -485,   105,
    -485,  -485,   352,  -457,  -485,   265,   167,  -485,  -485,  -485,
    -485,  -485,  -485,  -441,   399,  -485,  -485,   138,   116,  -485,
    -485,   472,   -62,  -485,  -485,  -485,  -485,  -485,   150,  -485,
    -485,  -485,  -485,  -485,   146,  -485,  -485,  -485,  -485,  -485,
     147,  -485,  -485,  -382,  -485,  -485,  -485,  -485,  -378,  -485,
    -485,  -485,  -485,  -485,  -485,  -485,  -485,   132,   178,  -485,
    -485,  -278,  -485,  -485,  -485,  -485,  -485,   254,  -162,  -485,
    -485,   136,   222,  -485,  -485,  -485,  -485,   225,  -485,  -485,
    -315,  -485,  -485,  -165,   -79,   562,    74,   119,   -88,  -485,
    -485,    11,  -485,  -485,    24,  -485,  -485,   493,  -485,   602,
     604,   601,   603,   606,   191,   277,   325,   260,    18,    45,
      91,  -485,   122,   157,   184,  -485
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,   407,   408,   409,   221,    21,   460,    22,    23,
      24,    25,    26,    27,    63,    28,   222,   236,   223,   224,
     152,   307,   308,   309,   310,   311,   312,   398,   313,   261,
     262,   263,   264,   443,   481,   265,   444,   482,   238,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   362,   363,   414,    93,   506,   461,   462,   505,   507,
     508,   509,   315,   316,   317,   416,   456,   457,   412,   278,
     279,   280,   417,   281,   282,   283,   373,   374,   459,   501,
     502,   153,   154,   284,   446,   484,   532,   566,   485,   486,
     530,   567,   285,   493,   540,   541,   542,   543,   448,   488,
     489,   490,   491,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   422,   584,   423,   585,   424,   465,   328,
     329,   381,   330,   331,   332,   333,   334,   435,   436,   437,
     520,   521,   474,   335,   524,   390,   470,   429,   430,   431,
      30,    31,    32,    33,    34,    70,    35,    36,    37,    38,
      39,   138,   139,    40,    41,    42,   109,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    69,    67,   385,   510,   421,    74,    74,    74,    74,
     440,   161,   382,    81,    68,   166,   314,    84,   527,   156,
     344,   441,    85,    92,   162,   156,   559,   345,   579,   160,
      17,    77,    78,    79,    80,   399,   405,   561,   510,   351,
     140,   420,   546,   361,   534,   406,   428,    71,   538,    72,
      71,   539,    72,   178,  -275,   535,   581,  -297,    73,  -275,
     179,   140,   137,   147,   141,   135,    62,   564,   314,    92,
     346,   582,    29,   432,   406,   494,    84,    83,    62,   160,
     142,   205,  -122,   156,   397,   515,   513,    75,    75,    75,
      75,    82,   157,   336,   165,   158,   525,   510,   538,   163,
     165,   539,   419,    74,    62,    74,    74,    74,    74,    74,
      74,   180,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    68,    65,  -124,     2,   193,   428,
       3,    96,    76,    76,    76,    76,     4,   200,   116,   117,
      74,   204,     5,   503,   227,   336,   190,   191,   192,     6,
     202,     7,   231,   110,   232,    86,   432,   111,   159,     9,
     136,   155,    62,    88,   140,   207,   140,    89,   168,   595,
     337,    90,   514,    91,   583,   219,    87,   212,   286,   213,
     421,   169,   112,   171,    75,   113,    75,    75,    75,    75,
      75,    75,   115,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,   258,   353,   114,   197,   410,
     353,    74,   133,   179,   156,   487,   603,   179,   336,  -228,
     372,    75,   337,   577,  -228,  -228,   158,   336,    66,    76,
     134,    76,    76,    76,    76,    76,    76,   143,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
     199,   353,    88,    94,   203,    95,    89,   144,   179,   314,
     548,   212,    91,   213,   180,   352,    76,   136,   180,   352,
     225,   126,   127,   197,  -227,   475,   477,    68,   555,  -227,
    -227,    68,   338,   402,   403,   404,   123,   124,   125,   159,
     145,   550,    75,    95,   146,   337,   128,   129,   130,   336,
     118,   148,   336,   339,   337,   487,   225,   176,   177,   180,
     352,   131,   132,   336,    65,   388,     2,   258,   -99,     3,
     -99,   149,    68,   -99,   150,     4,   375,   376,   377,   -99,
     418,     5,   458,   151,   338,   -99,   336,    76,     6,  -123,
       7,   164,   -99,   167,   -99,  -112,   194,    84,     9,   340,
    -385,  -385,   -99,   353,   195,   339,   198,  -112,    17,   360,
     179,   -99,   206,  -112,   -99,   119,   120,   121,   122,    29,
     201,   260,   208,   387,   209,   210,   337,    82,   211,   337,
     341,   427,   353,  -386,  -386,   287,   188,   189,   353,   179,
     337,   336,   214,   336,   496,   179,   181,   182,   183,   184,
     215,   340,   260,   354,   216,   450,   135,   338,   455,   218,
     217,   180,   352,   337,   220,   342,   338,    17,   355,   356,
     357,   -99,    92,   358,    68,   258,   226,   229,   339,   230,
     237,   254,   341,   336,   255,   479,   389,   339,   239,   234,
     180,   352,   343,   235,   240,   353,   180,   352,   185,   186,
     187,   500,   179,    68,   241,   242,   425,   379,   426,    68,
     244,   349,   433,   439,   427,   519,   380,   342,   337,   161,
     337,   166,   353,   526,   340,   383,   384,   225,   372,   179,
     386,   391,   392,   340,   575,   576,   393,   160,   338,   399,
     455,   338,   413,   395,   343,    92,   411,   401,   415,   434,
     418,   442,   338,   180,   352,   341,   258,    76,   445,   339,
     337,   447,   339,   451,   341,   452,    68,   453,   458,   463,
     464,   562,   467,   339,   438,   338,   466,   364,   468,   469,
     180,   352,    75,   601,   602,   512,   471,   472,    29,   473,
     342,  -256,   478,    68,   365,   433,   339,   480,   483,   342,
     492,   497,   519,   504,   511,   340,   247,   517,   340,   366,
     367,   368,   140,   529,   369,   370,   528,   343,   253,   340,
    -100,   531,  -100,   592,   533,  -100,   343,    76,   536,   537,
     338,  -100,   338,   547,   551,   552,   341,  -100,   553,   341,
      76,   554,   340,   406,  -100,   556,  -100,  -113,   563,   558,
     341,   339,   516,   339,  -100,   560,   569,   522,   565,  -113,
     572,   574,   578,  -100,   590,  -113,  -100,   593,   594,   596,
     597,   342,   338,   341,   342,   598,   260,   599,   604,   -98,
     605,   -98,   600,   288,   -98,   342,   449,   606,   607,   243,
     -98,   549,   394,   339,   348,   589,   -98,   340,   343,   340,
     347,   343,   371,   -98,   350,   -98,  -110,   544,   342,   580,
     359,   495,   343,   -98,   545,   294,   295,   296,  -110,   400,
     298,   299,   -98,  -100,  -110,   -98,   260,   571,   341,   454,
     341,   228,   378,   568,   570,   343,   256,   591,   573,   340,
     586,   557,   476,   257,   588,   587,   518,   196,   523,   260,
    -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,  -328,
    -328,   233,   170,   342,   173,   342,   172,   174,     0,     0,
     341,   175,     0,     0,   288,     0,     1,   289,     2,     0,
       0,     3,   -98,     0,   290,     0,     0,     4,     0,     0,
     343,   291,   343,     5,   292,     0,   293,     0,     0,     0,
       6,     0,     7,     0,     8,   342,   294,   295,   296,   297,
       9,   298,   299,    10,     0,   300,    11,   301,     0,     0,
     302,    12,     0,   303,     0,     0,     0,   256,     0,     0,
       0,  -111,   343,  -111,   257,     0,  -111,     0,  -138,     0,
       0,     0,  -111,     0,     0,     0,     0,     0,  -111,     0,
       0,  -140,     0,  -140,     0,  -111,  -140,  -111,  -111,     0,
       0,     0,  -140,     0,     0,  -111,     0,     0,  -140,     0,
    -111,     0,     0,    14,    15,  -140,  -111,  -140,     0,   304,
      18,   305,     0,   258,   -42,  -140,   288,   306,     1,   289,
       2,     0,     0,     3,     0,     0,   290,     0,     0,     4,
       0,     0,     0,   291,     0,     5,   292,     0,   293,     0,
       0,     0,     6,  -140,     7,     0,     8,     0,   294,   295,
     296,   297,     9,   298,   299,    10,     0,   300,    11,   301,
     245,     0,   302,    12,  -111,   303,     0,     0,   -58,   256,
       0,     0,     0,     0,     0,   -58,   257,   246,     0,     0,
    -138,     0,     0,     0,  -140,     0,     0,     0,     0,   247,
       0,     0,   248,   249,   250,     0,     0,   251,   252,     0,
       0,   253,   245,     0,     0,   254,     0,  -104,   255,     0,
     -58,     0,     0,   256,     0,    14,    15,   -58,   -58,   246,
     257,   304,    18,   305,     0,   258,   -44,     0,     0,   306,
       0,   247,     0,     0,   248,   249,   250,     0,     0,   251,
     252,     0,     0,   253,     0,     0,   245,   254,     0,  -104,
     255,     0,     0,     0,   -58,   256,     0,     0,     0,     0,
     -58,   -58,   257,   246,     0,     0,     0,     0,     0,   258,
     -79,     0,     0,   259,     0,   247,     0,     0,   248,   249,
     250,     0,     0,   251,   252,     0,     0,   253,   245,     0,
       0,   254,     0,  -104,   255,     0,   -58,     0,     0,   256,
       0,     0,     0,   -58,   -58,   246,   257,     0,     0,     0,
       0,   258,   -81,     0,     0,   259,     0,   247,     0,     0,
     248,   249,   250,     0,     0,   251,   252,     0,     0,   253,
       0,     0,     0,   254,     0,  -104,   255,     0,     0,     0,
       0,   256,     0,     0,     0,     0,   -58,     0,   257,     1,
     289,     2,     0,     0,     3,   258,  -191,   290,     0,   259,
       4,     0,     0,     0,     0,     0,     5,   292,     0,   293,
       0,     0,     0,     6,     0,     7,     0,     8,     0,     0,
       0,     0,   297,     9,     0,     0,    10,     0,   300,    11,
     301,     0,     0,   302,    12,     0,   303,   258,  -189,     0,
       1,   259,     2,     0,     0,     3,     0,     0,     0,     0,
       0,     4,     0,     0,     0,   399,     0,     5,     0,     0,
       0,     0,     0,     0,     6,     0,     7,     0,     8,     0,
       0,     1,     0,     2,     9,     0,     3,    10,     0,     0,
      11,     0,     4,     0,     0,    12,    14,    15,     5,     0,
       0,     0,   304,    18,   305,     6,   258,     7,     0,     8,
     306,     0,     1,     0,     2,     9,     0,     3,    10,     0,
       0,    11,     0,     4,     0,     0,    12,     0,     0,     5,
       0,     0,     0,     0,     0,     0,     6,     0,     7,     0,
       8,     0,     0,     0,     0,     0,     9,    14,    15,    10,
       0,     0,    11,    17,    18,   305,     0,    12,     0,     0,
       0,  -234,     0,     0,     0,     0,    65,     0,     2,     0,
      65,     3,     2,     0,     0,     3,    13,     4,    14,    15,
      16,     4,     0,     5,    17,    18,    19,     5,     0,     0,
       6,   133,     7,     0,     6,     0,     7,     1,     0,     2,
       9,     0,     3,     0,     9,     0,     0,    13,     4,    14,
      15,    16,     0,     0,     5,    17,    18,    19,     0,   198,
       0,     6,     1,     7,     2,     8,     0,     3,   396,     0,
       0,     9,     0,     4,    10,     0,     0,    11,     0,     5,
       0,     0,    12,     0,     0,     0,     6,     0,     7,     0,
       8,     0,     0,     1,     0,     2,     9,     0,     3,    10,
       0,     0,    11,     0,     4,     0,     0,    12,   399,    17,
       5,     0,     0,    17,     0,     0,     0,     6,     0,     7,
       0,     8,     0,     0,     0,     0,     0,     9,     0,     0,
      10,     0,    13,    11,    14,    15,    16,     0,    12,     0,
      17,    18,    19,     0,     1,     0,     2,     0,     0,     3,
       0,     0,     0,     0,     0,     4,     0,     0,     0,    14,
      15,     5,     0,     0,     0,    17,    18,   305,     6,     0,
       7,     0,     8,     0,     0,   -97,     0,   -97,     9,     0,
     -97,   498,     0,     0,   499,     0,   -97,     0,     0,    12,
       0,     0,   -97,     0,     0,     0,    17,    18,   305,   -97,
       0,   -97,  -109,     0,     0,     0,     0,     0,     0,   -97,
       0,   -96,     0,   -96,  -109,     0,   -96,     0,   -97,     0,
    -109,   -97,   -96,     0,     0,     0,     0,     0,   -96,     0,
       0,     0,     0,     0,     0,   -96,     0,   -96,  -108,     0,
       0,  -116,     0,  -116,     0,   -96,  -116,    17,    18,   305,
    -108,     0,  -116,     0,   -96,     0,  -108,   -96,  -116,     0,
       0,     0,     0,     0,     0,  -116,     0,  -116,  -116,     0,
       0,     0,     0,     0,     0,  -116,     0,     0,   -97,     0,
    -116,     0,     0,     0,     0,     0,  -116,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,  -329,  -329,
    -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,  -329,     0,
       0,     0,     0,   108,   -96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -116
};

static const yytype_int16 yycheck[] =
{
       1,     8,     8,   297,   461,   383,    13,    14,    15,    16,
     392,    90,   290,    19,     8,    94,   258,    22,   481,    33,
      11,   398,    23,    28,    33,    33,    83,    18,    42,    90,
     108,    13,    14,    15,    16,    20,    70,   521,   495,   271,
     118,   383,   110,   275,   108,   108,   388,   118,   492,   120,
     118,   492,   120,   118,   106,   119,   119,   110,   118,   111,
     118,   118,    67,   111,    69,   118,   114,   530,   310,    74,
      61,   555,     0,   388,   108,   452,    81,     0,   114,   140,
      69,   143,   118,    33,   316,   467,   464,    13,    14,    15,
      16,    19,    42,   258,   108,    45,   478,   554,   542,   108,
     108,   542,   380,   110,   114,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   118,     5,   111,     7,   133,   471,
      10,   114,    13,    14,    15,    16,    16,   138,    97,    98,
     147,   142,    22,   458,   206,   310,   128,   129,   130,    29,
     139,    31,   214,   101,   216,   120,   471,   105,   108,    39,
     114,    89,   114,   110,   118,   147,   118,   114,    96,   110,
     258,   118,   466,   120,   556,   180,   120,   118,   240,   120,
     558,   109,    99,   111,   110,    83,   112,   113,   114,   115,
     116,   117,    82,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   112,   271,    84,   136,   116,
     275,   218,   115,   271,    33,   447,   598,   275,   383,   111,
     281,   147,   310,    42,   116,   117,    45,   392,   108,   110,
     118,   112,   113,   114,   115,   116,   117,   110,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     137,   316,   110,   118,   141,   120,   114,   108,   316,   501,
     118,   118,   120,   120,   271,   271,   147,   114,   275,   275,
     198,    88,    89,   201,   111,   437,   438,   271,   510,   116,
     117,   275,   258,   344,   345,   346,    85,    86,    87,   108,
     108,   118,   218,   120,    11,   383,    90,    91,    92,   464,
      28,   111,   467,   258,   392,   537,   234,   116,   117,   316,
     316,   102,   103,   478,     5,   110,     7,   112,     5,    10,
       7,   118,   316,    10,   108,    16,    35,    36,    37,    16,
     110,    22,   112,    33,   310,    22,   501,   218,    29,   118,
      31,   118,    29,   108,    31,    32,    11,   352,    39,   258,
     102,   103,    39,   418,   108,   310,   112,    44,   108,    50,
     418,    48,   110,    50,    51,    93,    94,    95,    96,   297,
     114,   237,    11,   301,   117,   111,   464,   305,   115,   467,
     258,   388,   447,   102,   103,   251,   126,   127,   453,   447,
     478,   556,   110,   558,   455,   453,   119,   120,   121,   122,
      11,   310,   268,    20,   110,   406,   118,   383,   415,   106,
     115,   418,   418,   501,   115,   258,   392,   108,    35,    36,
      37,   108,   427,    40,   418,   112,   111,   108,   383,   108,
     112,    48,   310,   598,    51,   442,   302,   392,   111,   117,
     447,   447,   258,   117,   110,   510,   453,   453,   123,   124,
     125,   458,   510,   447,   111,   111,   384,   111,   386,   453,
     113,   113,   388,   391,   471,   472,   108,   310,   556,   548,
     558,   550,   537,   480,   383,   110,   110,   405,   539,   537,
     110,   110,   106,   392,   546,   547,   113,   548,   464,    20,
     497,   467,   108,   116,   310,   500,   362,   116,    47,     9,
     110,    19,   478,   510,   510,   383,   112,   388,   112,   464,
     598,   110,   467,   116,   392,   117,   510,   110,   112,   106,
     117,   528,   111,   478,   390,   501,   116,     3,   111,   106,
     537,   537,   458,   595,   596,   463,   106,   110,   466,    21,
     383,    21,   111,   537,    20,   471,   501,    59,   108,   392,
     112,   117,   559,   108,   117,   464,    32,   111,   467,    35,
      36,    37,   118,   110,    40,    41,   117,   383,    44,   478,
       5,   117,     7,   574,   117,    10,   392,   458,   111,   117,
     556,    16,   558,   110,   118,    45,   464,    22,   111,   467,
     471,   117,   501,   108,    29,   111,    31,    32,   111,   116,
     478,   556,   468,   558,    39,   110,   108,   473,   116,    44,
     113,   111,   113,    48,   113,    50,    51,   111,   111,   110,
     108,   464,   598,   501,   467,   111,   492,   116,   111,     5,
     111,     7,   116,     3,    10,   478,   405,   116,   116,   234,
      16,   501,   310,   598,   265,   565,    22,   556,   464,   558,
      20,   467,   277,    29,   268,    31,    32,   495,   501,   554,
     273,   453,   478,    39,   497,    35,    36,    37,    44,   317,
      40,    41,    48,   108,    50,    51,   542,   539,   556,   414,
     558,   209,   283,   533,   537,   501,    56,   571,   542,   598,
     558,   513,   438,    63,   560,   559,   471,   135,   476,   565,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,   218,   110,   556,   113,   558,   112,   114,    -1,    -1,
     598,   115,    -1,    -1,     3,    -1,     5,     6,     7,    -1,
      -1,    10,   108,    -1,    13,    -1,    -1,    16,    -1,    -1,
     556,    20,   558,    22,    23,    -1,    25,    -1,    -1,    -1,
      29,    -1,    31,    -1,    33,   598,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    44,    45,    46,    -1,    -1,
      49,    50,    -1,    52,    -1,    -1,    -1,    56,    -1,    -1,
      -1,     5,   598,     7,    63,    -1,    10,    -1,    67,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,     5,    -1,     7,    -1,    29,    10,    31,    32,    -1,
      -1,    -1,    16,    -1,    -1,    39,    -1,    -1,    22,    -1,
      44,    -1,    -1,   102,   103,    29,    50,    31,    -1,   108,
     109,   110,    -1,   112,   113,    39,     3,   116,     5,     6,
       7,    -1,    -1,    10,    -1,    -1,    13,    -1,    -1,    16,
      -1,    -1,    -1,    20,    -1,    22,    23,    -1,    25,    -1,
      -1,    -1,    29,    67,    31,    -1,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    44,    45,    46,
       3,    -1,    49,    50,   108,    52,    -1,    -1,    11,    56,
      -1,    -1,    -1,    -1,    -1,    18,    63,    20,    -1,    -1,
      67,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    35,    36,    37,    -1,    -1,    40,    41,    -1,
      -1,    44,     3,    -1,    -1,    48,    -1,    50,    51,    -1,
      11,    -1,    -1,    56,    -1,   102,   103,    18,    61,    20,
      63,   108,   109,   110,    -1,   112,   113,    -1,    -1,   116,
      -1,    32,    -1,    -1,    35,    36,    37,    -1,    -1,    40,
      41,    -1,    -1,    44,    -1,    -1,     3,    48,    -1,    50,
      51,    -1,    -1,    -1,    11,    56,    -1,    -1,    -1,    -1,
      61,    18,    63,    20,    -1,    -1,    -1,    -1,    -1,   112,
     113,    -1,    -1,   116,    -1,    32,    -1,    -1,    35,    36,
      37,    -1,    -1,    40,    41,    -1,    -1,    44,     3,    -1,
      -1,    48,    -1,    50,    51,    -1,    11,    -1,    -1,    56,
      -1,    -1,    -1,    18,    61,    20,    63,    -1,    -1,    -1,
      -1,   112,   113,    -1,    -1,   116,    -1,    32,    -1,    -1,
      35,    36,    37,    -1,    -1,    40,    41,    -1,    -1,    44,
      -1,    -1,    -1,    48,    -1,    50,    51,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    61,    -1,    63,     5,
       6,     7,    -1,    -1,    10,   112,   113,    13,    -1,   116,
      16,    -1,    -1,    -1,    -1,    -1,    22,    23,    -1,    25,
      -1,    -1,    -1,    29,    -1,    31,    -1,    33,    -1,    -1,
      -1,    -1,    38,    39,    -1,    -1,    42,    -1,    44,    45,
      46,    -1,    -1,    49,    50,    -1,    52,   112,   113,    -1,
       5,   116,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    20,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    -1,    31,    -1,    33,    -1,
      -1,     5,    -1,     7,    39,    -1,    10,    42,    -1,    -1,
      45,    -1,    16,    -1,    -1,    50,   102,   103,    22,    -1,
      -1,    -1,   108,   109,   110,    29,   112,    31,    -1,    33,
     116,    -1,     5,    -1,     7,    39,    -1,    10,    42,    -1,
      -1,    45,    -1,    16,    -1,    -1,    50,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    31,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    39,   102,   103,    42,
      -1,    -1,    45,   108,   109,   110,    -1,    50,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    -1,     5,    -1,     7,    -1,
       5,    10,     7,    -1,    -1,    10,   100,    16,   102,   103,
     104,    16,    -1,    22,   108,   109,   110,    22,    -1,    -1,
      29,   115,    31,    -1,    29,    -1,    31,     5,    -1,     7,
      39,    -1,    10,    -1,    39,    -1,    -1,   100,    16,   102,
     103,   104,    -1,    -1,    22,   108,   109,   110,    -1,   112,
      -1,    29,     5,    31,     7,    33,    -1,    10,    67,    -1,
      -1,    39,    -1,    16,    42,    -1,    -1,    45,    -1,    22,
      -1,    -1,    50,    -1,    -1,    -1,    29,    -1,    31,    -1,
      33,    -1,    -1,     5,    -1,     7,    39,    -1,    10,    42,
      -1,    -1,    45,    -1,    16,    -1,    -1,    50,    20,   108,
      22,    -1,    -1,   108,    -1,    -1,    -1,    29,    -1,    31,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      42,    -1,   100,    45,   102,   103,   104,    -1,    50,    -1,
     108,   109,   110,    -1,     5,    -1,     7,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,   102,
     103,    22,    -1,    -1,    -1,   108,   109,   110,    29,    -1,
      31,    -1,    33,    -1,    -1,     5,    -1,     7,    39,    -1,
      10,    42,    -1,    -1,    45,    -1,    16,    -1,    -1,    50,
      -1,    -1,    22,    -1,    -1,    -1,   108,   109,   110,    29,
      -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,     5,    -1,     7,    44,    -1,    10,    -1,    48,    -1,
      50,    51,    16,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,    -1,
      -1,     5,    -1,     7,    -1,    39,    10,   108,   109,   110,
      44,    -1,    16,    -1,    48,    -1,    50,    51,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,   108,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    50,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      -1,    -1,    -1,    97,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     5,     7,    10,    16,    22,    29,    31,    33,    39,
      42,    45,    50,   100,   102,   103,   104,   108,   109,   110,
     122,   127,   129,   130,   131,   132,   133,   134,   136,   141,
     261,   262,   263,   264,   265,   267,   268,   269,   270,   271,
     274,   275,   276,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   114,   135,   175,     5,   108,   129,   130,   136,
     266,   118,   120,   118,   136,   267,   268,   289,   289,   289,
     289,   129,   141,     0,   135,   175,   120,   120,   110,   114,
     118,   120,   135,   175,   118,   120,   114,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    97,   277,
     101,   105,    99,    83,    84,    82,    97,    98,    28,    93,
      94,    95,    96,    85,    86,    87,    88,    89,    90,    91,
      92,   102,   103,   115,   118,   118,   114,   135,   272,   273,
     118,   135,   272,   110,   108,   108,    11,   111,   111,   118,
     108,    33,   141,   202,   203,   141,    33,    42,    45,   108,
     127,   265,    33,   108,   118,   108,   265,   108,   141,   141,
     280,   141,   281,   282,   283,   284,   285,   285,   133,   134,
     136,   286,   286,   286,   286,   287,   287,   287,   288,   288,
     289,   289,   289,   135,    11,   108,   266,   141,   112,   137,
     175,   114,   272,   137,   175,   203,   110,   289,    11,   117,
     111,   115,   118,   120,   110,    11,   110,   115,   106,   135,
     115,   126,   137,   139,   140,   141,   111,   203,   202,   108,
     108,   203,   203,   278,   117,   117,   138,   112,   159,   111,
     110,   111,   111,   140,   113,     3,    20,    32,    35,    36,
      37,    40,    41,    44,    48,    51,    56,    63,   112,   116,
     142,   150,   151,   152,   153,   156,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   190,   191,
     192,   194,   195,   196,   204,   213,   203,   142,     3,     6,
      13,    20,    23,    25,    35,    36,    37,    38,    40,    41,
      44,    46,    49,    52,   108,   110,   116,   142,   143,   144,
     145,   146,   147,   149,   150,   183,   184,   185,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   240,   241,
     243,   244,   245,   246,   247,   254,   264,   269,   275,   290,
     291,   293,   294,   295,    11,    18,    61,    20,   153,   113,
     161,   128,   129,   133,    20,    35,    36,    37,    40,   166,
      50,   128,   172,   173,     3,    20,    35,    36,    37,    40,
      41,   170,   127,   197,   198,    35,    36,    37,   195,   111,
     108,   242,   242,   110,   110,   122,   110,   141,   110,   142,
     256,   110,   106,   113,   144,   116,    67,   128,   148,    20,
     183,   116,   127,   127,   127,    70,   108,   123,   124,   125,
     116,   142,   189,   108,   174,    47,   186,   193,   110,   242,
     147,   229,   234,   236,   238,   141,   141,   136,   147,   258,
     259,   260,   261,   267,     9,   248,   249,   250,   142,   141,
     224,   123,    19,   154,   157,   112,   205,   110,   219,   126,
     175,   116,   117,   110,   186,   136,   187,   188,   112,   199,
     128,   177,   178,   106,   117,   239,   116,   111,   111,   106,
     257,   106,   110,    21,   253,   249,   248,   249,   111,   136,
      59,   155,   158,   108,   206,   209,   210,   128,   220,   221,
     222,   223,   112,   214,   123,   177,   127,   117,    42,    45,
     136,   200,   201,   261,   108,   179,   176,   180,   181,   182,
     184,   117,   141,   229,   122,   224,   142,   111,   258,   136,
     251,   252,   142,   253,   255,   224,   136,   159,   117,   110,
     211,   117,   207,   117,   108,   119,   111,   117,   162,   194,
     215,   216,   217,   218,   176,   187,   110,   110,   118,   143,
     118,   118,    45,   111,   117,   128,   111,   239,   116,    83,
     110,   125,   136,   111,   159,   116,   208,   212,   209,   108,
     221,   198,   113,   215,   111,   203,   203,    42,   113,    42,
     180,   119,   125,   224,   235,   237,   238,   252,   142,   160,
     113,   199,   175,   111,   111,   110,   110,   108,   111,   116,
     116,   203,   203,   224,   111,   111,   116,   116
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   121,   122,   122,   123,   123,   124,   124,   125,   126,
     126,   127,   128,   128,   129,   129,   130,   130,   131,   131,
     131,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   136,   136,   137,   138,   138,   139,   139,   140,   140,
     141,   142,   143,   143,   144,   144,   145,   145,   145,   146,
     147,   148,   148,   149,   150,   150,   150,   151,   152,   152,
     153,   153,   154,   154,   155,   155,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   157,   158,   158,   159,   160,
     160,   161,   161,   162,   162,   162,   162,   163,   163,   163,
     163,   164,   165,   165,   166,   166,   167,   167,   167,   167,
     167,   167,   167,   168,   169,   169,   170,   170,   171,   171,
     171,   171,   171,   171,   171,   171,   171,   172,   172,   173,
     173,   174,   175,   175,   176,   176,   177,   177,   178,   179,
     179,   180,   180,   181,   181,   182,   183,   183,   184,   184,
     185,   186,   187,   187,   188,   189,   189,   190,   191,   192,
     193,   193,   194,   194,   195,   195,   196,   196,   196,   197,
     198,   199,   200,   200,   201,   201,   201,   201,   202,   202,
     203,   203,   204,   205,   206,   206,   207,   207,   208,   208,
     209,   209,   210,   210,   211,   211,   212,   213,   214,   215,
     215,   216,   216,   217,   217,   218,   219,   220,   220,   221,
     221,   222,   222,   223,   224,   224,   224,   224,   224,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   226,
     227,   228,   229,   229,   229,   229,   229,   229,   229,   230,
     231,   232,   232,   233,   234,   234,   235,   235,   236,   236,
     237,   238,   239,   239,   240,   241,   242,   242,   243,   244,
     245,   246,   247,   247,   247,   248,   248,   249,   249,   250,
     251,   252,   252,   253,   254,   255,   255,   256,   257,   257,
     258,   258,   259,   259,   260,   260,   261,   261,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   263,   263,
     263,   263,   264,   264,   264,   265,   265,   266,   266,   267,
     267,   267,   268,   268,   269,   269,   269,   269,   269,   269,
     270,   270,   270,   270,   270,   270,   270,   271,   271,   271,
     271,   272,   272,   273,   274,   274,   275,   276,   276,   276,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   278,   278,   278,   279,   279,   280,   280,   281,
     281,   282,   282,   283,   283,   284,   284,   284,   285,   285,
     285,   285,   285,   285,   286,   286,   286,   286,   287,   287,
     287,   288,   288,   288,   288,   289,   289,   289,   290,   291,
     292,   292,   292,   292,   293,   293,   293,   294,   295,   296
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     3,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       3,     1,     3,     4,     0,     1,     0,     1,     1,     3,
       1,     3,     0,     1,     1,     2,     1,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     6,     0,     1,
       1,     2,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     3,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     2,     1,
       1,     6,     0,     1,     0,     1,     0,     2,     3,     0,
       2,     1,     3,     3,     1,     4,     1,     2,     0,     1,
       1,     2,     1,     3,     2,     1,     1,     1,     2,     4,
       0,     1,     0,     1,     1,     2,     1,     1,     1,     5,
       1,     4,     0,     1,     5,     5,     7,     7,     1,     3,
       0,     1,     4,     5,     0,     1,     0,     1,     0,     1,
       1,     3,     2,     3,     0,     2,     2,     5,     3,     1,
       2,     0,     1,     1,     1,     3,     3,     0,     1,     1,
       3,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     1,     1,     9,     0,     1,     0,     1,     1,     1,
       1,     2,     0,     3,     7,     2,     0,     2,     2,     2,
       2,     5,     3,     4,     1,     0,     1,     1,     2,     5,
       2,     1,     3,     2,     5,     0,     1,     4,     0,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     4,     4,
       4,     3,     1,     3,     3,     5,     6,     1,     3,     3,
       3,     5,     4,     4,     4,     6,     6,     6,     6,     8,
       3,     3,     3,     3,     5,     3,     3,     4,     4,     4,
       4,     1,     2,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     4,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     1,     1,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     2,     2,     4
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

#line 2181 "parser_template_1.tab.c"

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
#line 1140 "parser_template_1.y"
