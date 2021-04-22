/* A Bison parser, made by GNU Bison 3.7.2.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.2"

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


#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
//#include "sds.h"
#include "one.h"
#include "print.h"

//int yylex();
void yyerror(const char *s);


#line 86 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_OP_ADD = 3,                     /* OP_ADD  */
  YYSYMBOL_OP_SUB = 4,                     /* OP_SUB  */
  YYSYMBOL_OP_MUL = 5,                     /* OP_MUL  */
  YYSYMBOL_OP_DIV = 6,                     /* OP_DIV  */
  YYSYMBOL_OP_POW = 7,                     /* OP_POW  */
  YYSYMBOL_OP_MOL = 8,                     /* OP_MOL  */
  YYSYMBOL_OP_SIGN = 9,                    /* OP_SIGN  */
  YYSYMBOL_OP_GT = 10,                     /* OP_GT  */
  YYSYMBOL_OP_LT = 11,                     /* OP_LT  */
  YYSYMBOL_OP_EQ = 12,                     /* OP_EQ  */
  YYSYMBOL_OP_TEQ = 13,                    /* OP_TEQ  */
  YYSYMBOL_OP_NE = 14,                     /* OP_NE  */
  YYSYMBOL_OP_TNE = 15,                    /* OP_TNE  */
  YYSYMBOL_OP_LE = 16,                     /* OP_LE  */
  YYSYMBOL_OP_GE = 17,                     /* OP_GE  */
  YYSYMBOL_OP_ASSIGN = 18,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_DOT = 19,                    /* OP_DOT  */
  YYSYMBOL_OP_DOTDOT = 20,                 /* OP_DOTDOT  */
  YYSYMBOL_OP_DOTDOTDOT = 21,              /* OP_DOTDOTDOT  */
  YYSYMBOL_SEMICOLON = 22,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 23,                     /* COLON  */
  YYSYMBOL_LBRACKET = 24,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 25,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 26,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 27,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 28,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 29,                    /* RPAREN  */
  YYSYMBOL_KW_BOOL = 30,                   /* KW_BOOL  */
  YYSYMBOL_KW_VOID = 31,                   /* KW_VOID  */
  YYSYMBOL_KW_TRUE = 32,                   /* KW_TRUE  */
  YYSYMBOL_KW_FALSE = 33,                  /* KW_FALSE  */
  YYSYMBOL_KW_NULL = 34,                   /* KW_NULL  */
  YYSYMBOL_KW_STRING = 35,                 /* KW_STRING  */
  YYSYMBOL_KW_CHAR = 36,                   /* KW_CHAR  */
  YYSYMBOL_KW_INT8 = 37,                   /* KW_INT8  */
  YYSYMBOL_KW_INT16 = 38,                  /* KW_INT16  */
  YYSYMBOL_KW_INT32 = 39,                  /* KW_INT32  */
  YYSYMBOL_KW_INT64 = 40,                  /* KW_INT64  */
  YYSYMBOL_KW_UINT8 = 41,                  /* KW_UINT8  */
  YYSYMBOL_KW_UINT16 = 42,                 /* KW_UINT16  */
  YYSYMBOL_KW_UINT32 = 43,                 /* KW_UINT32  */
  YYSYMBOL_KW_UINT64 = 44,                 /* KW_UINT64  */
  YYSYMBOL_KW_FLOAT32 = 45,                /* KW_FLOAT32  */
  YYSYMBOL_KW_FLOAT64 = 46,                /* KW_FLOAT64  */
  YYSYMBOL_KW_FLOAT128 = 47,               /* KW_FLOAT128  */
  YYSYMBOL_KW_IF = 48,                     /* KW_IF  */
  YYSYMBOL_KW_ELSE = 49,                   /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 50,                  /* KW_WHILE  */
  YYSYMBOL_KW_RETURN = 51,                 /* KW_RETURN  */
  YYSYMBOL_KW_FOR = 52,                    /* KW_FOR  */
  YYSYMBOL_KW_FN = 53,                     /* KW_FN  */
  YYSYMBOL_KW_PRINTLN = 54,                /* KW_PRINTLN  */
  YYSYMBOL_KW_PRINT = 55,                  /* KW_PRINT  */
  YYSYMBOL_KW_WINDOW = 56,                 /* KW_WINDOW  */
  YYSYMBOL_KW_WINDOW_BOX = 57,             /* KW_WINDOW_BOX  */
  YYSYMBOL_KW_WINDOW_FIELD = 58,           /* KW_WINDOW_FIELD  */
  YYSYMBOL_KW_WINDOW_BUTTON = 59,          /* KW_WINDOW_BUTTON  */
  YYSYMBOL_KW_WINDOW_LABEL = 60,           /* KW_WINDOW_LABEL  */
  YYSYMBOL_INT_CONSTANT = 61,              /* INT_CONSTANT  */
  YYSYMBOL_FLOAT_CONSTANT = 62,            /* FLOAT_CONSTANT  */
  YYSYMBOL_STRING_CONSTANT = 63,           /* STRING_CONSTANT  */
  YYSYMBOL_IDENTIFIER = 64,                /* IDENTIFIER  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_translation_unit = 66,          /* translation_unit  */
  YYSYMBOL_element_compound_statement = 67, /* element_compound_statement  */
  YYSYMBOL_element_items = 68,             /* element_items  */
  YYSYMBOL_element_item = 69,              /* element_item  */
  YYSYMBOL_compound_statement = 70,        /* compound_statement  */
  YYSYMBOL_function_list = 71,             /* function_list  */
  YYSYMBOL_function_argument_list = 72,    /* function_argument_list  */
  YYSYMBOL_function_argument = 73,         /* function_argument  */
  YYSYMBOL_function = 74,                  /* function  */
  YYSYMBOL_statement_list = 75,            /* statement_list  */
  YYSYMBOL_statement = 76,                 /* statement  */
  YYSYMBOL_while_statement = 77,           /* while_statement  */
  YYSYMBOL_return_statement = 78,          /* return_statement  */
  YYSYMBOL_element_statement = 79,         /* element_statement  */
  YYSYMBOL_print_statement = 80,           /* print_statement  */
  YYSYMBOL_selection_statement = 81,       /* selection_statement  */
  YYSYMBOL_selection_rest_statement = 82,  /* selection_rest_statement  */
  YYSYMBOL_assignment = 83,                /* assignment  */
  YYSYMBOL_expression_list = 84,           /* expression_list  */
  YYSYMBOL_expression = 85,                /* expression  */
  YYSYMBOL_primary_expression = 86,        /* primary_expression  */
  YYSYMBOL_declaration = 87,               /* declaration  */
  YYSYMBOL_type_specifier = 88             /* type_specifier  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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
typedef yytype_uint8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   384

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   128,   128,   132,   142,   145,   151,   154,   160,   163,
     169,   172,   178,   181,   187,   190,   193,   199,   205,   208,
     211,   214,   221,   224,   229,   230,   231,   232,   233,   234,
     235,   236,   241,   248,   255,   262,   265,   272,   279,   282,
     289,   297,   300,   303,   310,   313,   317,   321,   324,   327,
     331,   334,   337,   340,   343,   346,   349,   352,   355,   358,
     361,   364,   370,   376,   381,   386,   391,   396,   401,   406,
     414,   417,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "OP_ADD", "OP_SUB",
  "OP_MUL", "OP_DIV", "OP_POW", "OP_MOL", "OP_SIGN", "OP_GT", "OP_LT",
  "OP_EQ", "OP_TEQ", "OP_NE", "OP_TNE", "OP_LE", "OP_GE", "OP_ASSIGN",
  "OP_DOT", "OP_DOTDOT", "OP_DOTDOTDOT", "SEMICOLON", "COLON", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "KW_BOOL", "KW_VOID",
  "KW_TRUE", "KW_FALSE", "KW_NULL", "KW_STRING", "KW_CHAR", "KW_INT8",
  "KW_INT16", "KW_INT32", "KW_INT64", "KW_UINT8", "KW_UINT16", "KW_UINT32",
  "KW_UINT64", "KW_FLOAT32", "KW_FLOAT64", "KW_FLOAT128", "KW_IF",
  "KW_ELSE", "KW_WHILE", "KW_RETURN", "KW_FOR", "KW_FN", "KW_PRINTLN",
  "KW_PRINT", "KW_WINDOW", "KW_WINDOW_BOX", "KW_WINDOW_FIELD",
  "KW_WINDOW_BUTTON", "KW_WINDOW_LABEL", "INT_CONSTANT", "FLOAT_CONSTANT",
  "STRING_CONSTANT", "IDENTIFIER", "$accept", "translation_unit",
  "element_compound_statement", "element_items", "element_item",
  "compound_statement", "function_list", "function_argument_list",
  "function_argument", "function", "statement_list", "statement",
  "while_statement", "return_statement", "element_statement",
  "print_statement", "selection_statement", "selection_rest_statement",
  "assignment", "expression_list", "expression", "primary_expression",
  "declaration", "type_specifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
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
     315,   316,   317,   318,   319
};
#endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      36,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,    37,     2,    36,   -67,   -59,    98,
     320,   -67,   -67,   -67,    58,   -67,     8,   -67,   -67,   -67,
       8,   -17,     8,     8,     8,   -67,   -67,   -67,    71,   136,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,    99,   -67,   -67,
     -52,   -20,   -67,   -45,   320,   -67,    -8,   274,   328,     8,
      99,    99,    99,     8,   174,     8,   -67,   -67,   -67,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,     8,
       8,     8,     8,     8,     8,     9,   320,    12,   -67,     5,
     -67,    19,   -67,   301,    99,   -67,    67,   212,   -67,   -67,
       6,    99,   363,   363,     3,     3,     3,     3,     3,    41,
      41,    41,    41,    41,    41,    99,    99,    99,     8,   -67,
     -67,    12,    12,    12,     8,   -67,   -67,     8,   -67,    99,
     -67,   -67,   -67,    99,    99
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    83,    84,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,     2,    12,     0,     0,
      16,    19,     1,    13,     0,    11,     0,    67,    68,    69,
       0,     0,     0,     0,     0,    64,    65,    66,    63,     0,
      22,    28,    30,    31,    29,    27,    26,    25,    61,    24,
       0,     0,    14,     0,    16,    21,    63,     0,     0,     0,
      33,    36,    35,     0,     0,    43,    34,    10,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,     0,    17,     0,
      60,    38,    37,     0,    40,     4,    63,     0,     6,     9,
       0,    41,    44,    45,    51,    53,    52,    50,    46,    54,
      55,    57,    56,    59,    58,    47,    48,    49,     0,    15,
      18,     0,     0,     0,     0,     5,     7,     0,    62,    70,
      20,    39,    32,     8,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -67,   -67,   -67,   -67,   -66,     1,   -67,   -22,     4,    75,
     -67,   -18,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -26,   -67,   -67,    10
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    15,    66,    97,    98,    21,    16,    51,    52,    17,
      39,    99,    41,    42,    43,    44,    45,    92,    46,   100,
      47,    48,    49,    50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    40,    22,    86,    58,    24,    60,    61,    62,    87,
      18,    59,    85,    76,    77,    78,    79,    80,    81,    88,
      65,    68,    82,    83,    84,    55,    18,   118,    86,   127,
      53,   126,    89,    93,   121,   128,    26,    94,    19,   101,
      27,    28,    29,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    91,
      82,    83,    84,    19,    53,    20,     1,     2,   122,    35,
      36,    37,    56,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    19,    63,    54,   124,   120,    63,
     119,    23,   129,    64,     0,    65,    53,    64,   133,    65,
      14,   134,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     0,     0,     0,    82,    83,
      84,     0,   130,   131,   132,    25,    26,     0,     1,     2,
      27,    28,    29,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    30,     0,    31,    32,
       0,     0,    33,    34,     0,     0,     0,     0,     0,    35,
      36,    37,    38,    67,    26,     0,     1,     2,    27,    28,
      29,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    30,     0,    31,    32,     0,     0,
      33,    34,     0,     0,     0,     0,     0,    35,    36,    37,
      38,    95,    26,     0,     1,     2,    27,    28,    29,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    30,     0,    31,    32,     0,     0,    33,    34,
       0,     0,     0,     0,     0,    35,    36,    37,    96,   125,
      26,     0,     1,     2,    27,    28,    29,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      30,     0,    31,    32,     0,     0,    33,    34,     0,     0,
       0,     0,     0,    35,    36,    37,    96,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
       0,     0,     0,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,    90,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,     0,     0,     0,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
     123,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,     0,    82,    83,    84,
       1,     2,     0,     0,    19,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,    82,    83,    84
};

static const yytype_int8 yycheck[] =
{
      26,    19,     0,    23,    30,    64,    32,    33,    34,    29,
       0,    28,    64,    10,    11,    12,    13,    14,    15,    64,
      28,    39,    19,    20,    21,    24,    16,    18,    23,    23,
      20,    97,    54,    59,    29,    29,    28,    63,    26,    65,
      32,    33,    34,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    58,
      19,    20,    21,    26,    54,    28,    30,    31,    49,    61,
      62,    63,    64,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    26,    18,    28,    20,    87,    18,
      86,    16,   118,    26,    -1,    28,    86,    26,   124,    28,
      64,   127,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    -1,   121,   122,   123,    27,    28,    -1,    30,    31,
      32,    33,    34,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    64,    27,    28,    -1,    30,    31,    32,    33,
      34,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    -1,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    27,    28,    -1,    30,    31,    32,    33,    34,    -1,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    -1,    -1,    54,    55,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    27,
      28,    -1,    30,    31,    32,    33,    34,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      30,    31,    -1,    -1,    26,    -1,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,    20,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    31,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    64,    66,    71,    74,    88,    26,
      28,    70,     0,    74,    64,    27,    28,    32,    33,    34,
      48,    50,    51,    54,    55,    61,    62,    63,    64,    75,
      76,    77,    78,    79,    80,    81,    83,    85,    86,    87,
      88,    72,    73,    88,    28,    70,    64,    85,    85,    28,
      85,    85,    85,    18,    26,    28,    67,    27,    76,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    19,    20,    21,    64,    23,    29,    64,    72,
      29,    70,    82,    85,    85,    27,    64,    68,    69,    76,
      84,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    18,    73,
      70,    29,    49,    29,    20,    27,    69,    23,    29,    85,
      70,    70,    70,    85,    85
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    72,    72,    72,    73,    74,    74,
      74,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    76,    77,    78,    79,    80,    80,    81,    82,    82,
      83,    84,    84,    84,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    86,    86,    86,    86,    86,    86,    86,    86,
      87,    87,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     1,     2,     3,     1,
       3,     2,     1,     2,     1,     3,     0,     2,     5,     2,
       6,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     2,     2,     2,     2,     3,     1,     3,
       3,     1,     3,     0,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* translation_unit: function_list  */
#line 128 "parser.y"
                        {
		(yyval.translation_unit) = create_translation_unit((yyvsp[0].statement_list));
		print_program((struct ast_node *) (yyval.translation_unit));
	}
#line 1317 "parser.tab.c"
    break;

  case 3: /* translation_unit: %empty  */
#line 132 "parser.y"
          {
	}
#line 1324 "parser.tab.c"
    break;

  case 4: /* element_compound_statement: LBRACE RBRACE  */
#line 142 "parser.y"
                   {
      (yyval.compound_statement) = create_compound_statement_empty();
   }
#line 1332 "parser.tab.c"
    break;

  case 5: /* element_compound_statement: LBRACE element_items RBRACE  */
#line 145 "parser.y"
                                 {
      (yyval.compound_statement) = create_compound_statement((yyvsp[-1].statement_list));
   }
#line 1340 "parser.tab.c"
    break;

  case 6: /* element_items: element_item  */
#line 151 "parser.y"
                  {
      (yyval.statement_list) = create_statement_list((struct ast_node *) (yyvsp[0].element_item));
   }
#line 1348 "parser.tab.c"
    break;

  case 7: /* element_items: element_items element_item  */
#line 154 "parser.y"
                                {
      (yyval.statement_list) = statement_list_add_statement((yyvsp[-1].statement_list), (struct ast_node *) (yyvsp[0].element_item));
   }
#line 1356 "parser.tab.c"
    break;

  case 8: /* element_item: IDENTIFIER OP_DOTDOT expression  */
#line 160 "parser.y"
                                     {
      (yyval.element_item) = create_element_item((yyvsp[-2].identifier), (yyvsp[0].expression));
   }
#line 1364 "parser.tab.c"
    break;

  case 9: /* element_item: statement  */
#line 163 "parser.y"
               {
      (yyval.element_item) = (yyvsp[0].node);
   }
#line 1372 "parser.tab.c"
    break;

  case 10: /* compound_statement: LBRACE statement_list RBRACE  */
#line 169 "parser.y"
                                  {
      (yyval.compound_statement) = create_compound_statement((yyvsp[-1].statement_list));
   }
#line 1380 "parser.tab.c"
    break;

  case 11: /* compound_statement: LBRACE RBRACE  */
#line 172 "parser.y"
                   {
      (yyval.compound_statement) = create_compound_statement_empty();
   }
#line 1388 "parser.tab.c"
    break;

  case 12: /* function_list: function  */
#line 178 "parser.y"
              {
      (yyval.statement_list) = create_statement_list((yyvsp[0].node));
   }
#line 1396 "parser.tab.c"
    break;

  case 13: /* function_list: function_list function  */
#line 181 "parser.y"
                            {
      (yyval.statement_list) = statement_list_add_statement((yyvsp[-1].statement_list), (yyvsp[0].node));
   }
#line 1404 "parser.tab.c"
    break;

  case 14: /* function_argument_list: function_argument  */
#line 187 "parser.y"
                       {
      (yyval.statement_list) = create_argument_list((yyvsp[0].function_argument));
   }
#line 1412 "parser.tab.c"
    break;

  case 15: /* function_argument_list: function_argument_list COLON function_argument  */
#line 190 "parser.y"
                                                    {
      (yyval.statement_list) = argument_list_add_argument((yyvsp[-2].statement_list), (yyvsp[0].function_argument));
   }
#line 1420 "parser.tab.c"
    break;

  case 16: /* function_argument_list: %empty  */
#line 193 "parser.y"
     {
      (yyval.statement_list) = create_argument_list_empty();
   }
#line 1428 "parser.tab.c"
    break;

  case 17: /* function_argument: type_specifier IDENTIFIER  */
#line 199 "parser.y"
                               {
      (yyval.function_argument) = create_function_argument((yyvsp[-1].type_specifier), (yyvsp[0].identifier));
   }
#line 1436 "parser.tab.c"
    break;

  case 18: /* function: IDENTIFIER LPAREN function_argument_list RPAREN compound_statement  */
#line 205 "parser.y"
                                                                        {
      (yyval.node) = (struct ast_node *) create_function(create_type(AST_VALUE_VOID), (yyvsp[-4].identifier), (yyvsp[-2].statement_list), (yyvsp[0].compound_statement));
   }
#line 1444 "parser.tab.c"
    break;

  case 19: /* function: IDENTIFIER compound_statement  */
#line 208 "parser.y"
                                   {
      (yyval.node) = (struct ast_node *) create_function(create_type(AST_VALUE_VOID), (yyvsp[-1].identifier), create_argument_list_empty(), (yyvsp[0].compound_statement));
   }
#line 1452 "parser.tab.c"
    break;

  case 20: /* function: type_specifier IDENTIFIER LPAREN function_argument_list RPAREN compound_statement  */
#line 211 "parser.y"
                                                                                       {
      (yyval.node) = (struct ast_node *) create_function((yyvsp[-5].type_specifier), (yyvsp[-4].identifier), (yyvsp[-2].statement_list), (yyvsp[0].compound_statement));
   }
#line 1460 "parser.tab.c"
    break;

  case 21: /* function: type_specifier IDENTIFIER compound_statement  */
#line 214 "parser.y"
                                                  {
      (yyval.node) = (struct ast_node *) create_function((yyvsp[-2].type_specifier), (yyvsp[-1].identifier), create_argument_list_empty(), (yyvsp[0].compound_statement));
   }
#line 1468 "parser.tab.c"
    break;

  case 22: /* statement_list: statement  */
#line 221 "parser.y"
               {
      (yyval.statement_list) = create_statement_list((yyvsp[0].node));
   }
#line 1476 "parser.tab.c"
    break;

  case 23: /* statement_list: statement_list statement  */
#line 224 "parser.y"
                              {
      (yyval.statement_list) = statement_list_add_statement((yyvsp[-1].statement_list), (yyvsp[0].node));
   }
#line 1484 "parser.tab.c"
    break;

  case 24: /* statement: declaration  */
#line 229 "parser.y"
                       { (yyval.node) = (struct ast_node *) (yyvsp[0].declaration); }
#line 1490 "parser.tab.c"
    break;

  case 25: /* statement: expression  */
#line 230 "parser.y"
                       { (yyval.node) = (struct ast_node *) (yyvsp[0].expression); }
#line 1496 "parser.tab.c"
    break;

  case 26: /* statement: assignment  */
#line 231 "parser.y"
                       { (yyval.node) = (struct ast_node *) (yyvsp[0].expression); }
#line 1502 "parser.tab.c"
    break;

  case 27: /* statement: selection_statement  */
#line 232 "parser.y"
                                 { (yyval.node) = (struct ast_node *) (yyvsp[0].selection_statement); }
#line 1508 "parser.tab.c"
    break;

  case 28: /* statement: while_statement  */
#line 233 "parser.y"
                                 { (yyval.node) = (struct ast_node *) (yyvsp[0].while_statement); }
#line 1514 "parser.tab.c"
    break;

  case 29: /* statement: print_statement  */
#line 234 "parser.y"
                                 { (yyval.node) = (struct ast_node *) (yyvsp[0].print_statement); }
#line 1520 "parser.tab.c"
    break;

  case 30: /* statement: return_statement  */
#line 235 "parser.y"
                                 { (yyval.node) = (struct ast_node *) (yyvsp[0].return_statement); }
#line 1526 "parser.tab.c"
    break;

  case 31: /* statement: element_statement  */
#line 236 "parser.y"
                                  { (yyval.node) = (struct ast_node *) (yyvsp[0].element_statement); }
#line 1532 "parser.tab.c"
    break;

  case 32: /* while_statement: KW_WHILE LPAREN expression RPAREN compound_statement  */
#line 241 "parser.y"
                                                          {
      (yyval.while_statement) = create_while_statement((yyvsp[-2].expression), (yyvsp[0].compound_statement));
   }
#line 1540 "parser.tab.c"
    break;

  case 33: /* return_statement: KW_RETURN expression  */
#line 248 "parser.y"
                          {
      (yyval.return_statement) = create_return_statement((yyvsp[0].expression));
   }
#line 1548 "parser.tab.c"
    break;

  case 34: /* element_statement: IDENTIFIER element_compound_statement  */
#line 255 "parser.y"
                                           {
      (yyval.element_statement) = create_element_statement((yyvsp[-1].identifier), (yyvsp[0].compound_statement));
   }
#line 1556 "parser.tab.c"
    break;

  case 35: /* print_statement: KW_PRINT expression  */
#line 262 "parser.y"
                         {
      (yyval.print_statement) = create_print_statement((yyvsp[0].expression), FALSE);
   }
#line 1564 "parser.tab.c"
    break;

  case 36: /* print_statement: KW_PRINTLN expression  */
#line 265 "parser.y"
                           {
      (yyval.print_statement) = create_print_statement((yyvsp[0].expression), TRUE);
   }
#line 1572 "parser.tab.c"
    break;

  case 37: /* selection_statement: KW_IF expression selection_rest_statement  */
#line 272 "parser.y"
                                               {
      (yyval.selection_statement) = (yyvsp[0].selection_statement);
      (yyval.selection_statement)->condition = (yyvsp[-1].expression);
   }
#line 1581 "parser.tab.c"
    break;

  case 38: /* selection_rest_statement: compound_statement  */
#line 279 "parser.y"
                        {
      (yyval.selection_statement) = create_selection_statement(NULL, (yyvsp[0].compound_statement), NULL);
   }
#line 1589 "parser.tab.c"
    break;

  case 39: /* selection_rest_statement: compound_statement KW_ELSE compound_statement  */
#line 282 "parser.y"
                                                   {
      (yyval.selection_statement) = create_selection_statement(NULL, (yyvsp[-2].compound_statement), (yyvsp[0].compound_statement));
   }
#line 1597 "parser.tab.c"
    break;

  case 40: /* assignment: IDENTIFIER OP_ASSIGN expression  */
#line 289 "parser.y"
                                     {
   (yyval.expression) = create_expression(AST_ASSIGN, (yyvsp[0].expression), NULL);
   (yyval.expression)->value.primary.value_identifier = (yyvsp[-2].identifier);
}
#line 1606 "parser.tab.c"
    break;

  case 41: /* expression_list: expression  */
#line 297 "parser.y"
                {
      (yyval.expression_list) = create_expression_list((struct ast_node *) (yyvsp[0].expression));
   }
#line 1614 "parser.tab.c"
    break;

  case 42: /* expression_list: expression_list COLON expression  */
#line 300 "parser.y"
                                      {
      (yyval.expression_list) = expression_list_add_expression((yyvsp[-2].expression_list), (struct ast_node *) (yyvsp[0].expression));
   }
#line 1622 "parser.tab.c"
    break;

  case 43: /* expression_list: %empty  */
#line 303 "parser.y"
     {
      (yyval.expression_list) = create_expression_list_empty();
   }
#line 1630 "parser.tab.c"
    break;

  case 44: /* expression: expression OP_ADD expression  */
#line 310 "parser.y"
                                  {
      (yyval.expression) = create_expression(AST_ADD, (yyvsp[-2].expression), (yyvsp[0].expression));
   }
#line 1638 "parser.tab.c"
    break;

  case 45: /* expression: expression OP_SUB expression  */
#line 313 "parser.y"
                                  {
      (yyval.expression) = create_expression(AST_SUB, (yyvsp[-2].expression), (yyvsp[0].expression));
   }
#line 1646 "parser.tab.c"
    break;

  case 46: /* expression: expression OP_SIGN expression  */
#line 317 "parser.y"
                                   {
      (yyval.expression) = create_expression(AST_SIGN, (yyvsp[-2].expression), (yyvsp[0].expression));
   }
#line 1654 "parser.tab.c"
    break;

  case 47: /* expression: expression OP_DOT expression  */
#line 321 "parser.y"
                                  {
      (yyval.expression) = create_expression(AST_DOT, (yyvsp[-2].expression), (yyvsp[0].expression));
   }
#line 1662 "parser.tab.c"
    break;

  case 48: /* expression: expression OP_DOTDOT expression  */
#line 324 "parser.y"
                                     {
      (yyval.expression) = create_expression(AST_DOTDOT, (yyvsp[-2].expression), (yyvsp[0].expression));
   }
#line 1670 "parser.tab.c"
    break;

  case 49: /* expression: expression OP_DOTDOTDOT expression  */
#line 327 "parser.y"
                                        {
      (yyval.expression) = create_expression(AST_DOTDOTDOT, (yyvsp[-2].expression), (yyvsp[0].expression));
   }
#line 1678 "parser.tab.c"
    break;

  case 50: /* expression: expression OP_MOL expression  */
#line 331 "parser.y"
                                  {
      (yyval.expression) = create_expression(AST_MOL, (yyvsp[-2].expression), (yyvsp[0].expression));
   }
#line 1686 "parser.tab.c"
    break;

  case 51: /* expression: expression OP_MUL expression  */
#line 334 "parser.y"
                                  {
      (yyval.expression) = create_expression(AST_MUL, (yyvsp[-2].expression), (yyvsp[0].expression));
   }
#line 1694 "parser.tab.c"
    break;

  case 52: /* expression: expression OP_POW expression  */
#line 337 "parser.y"
                                  {
      (yyval.expression) = create_expression(AST_POW, (yyvsp[-2].expression), (yyvsp[0].expression));
   }
#line 1702 "parser.tab.c"
    break;

  case 53: /* expression: expression OP_DIV expression  */
#line 340 "parser.y"
                                  {
      (yyval.expression) = create_expression(AST_DIV, (yyvsp[-2].expression), (yyvsp[0].expression));
   }
#line 1710 "parser.tab.c"
    break;

  case 54: /* expression: expression OP_GT expression  */
#line 343 "parser.y"
                                  {
      (yyval.expression) = create_expression(AST_GT, (yyvsp[-2].expression), (yyvsp[0].expression));
   }
#line 1718 "parser.tab.c"
    break;

  case 55: /* expression: expression OP_LT expression  */
#line 346 "parser.y"
                                  {
      (yyval.expression) = create_expression(AST_LT, (yyvsp[-2].expression), (yyvsp[0].expression));
   }
#line 1726 "parser.tab.c"
    break;

  case 56: /* expression: expression OP_TEQ expression  */
#line 349 "parser.y"
                                   {
      (yyval.expression) = create_expression(AST_TEQ, (yyvsp[-2].expression), (yyvsp[0].expression));
   }
#line 1734 "parser.tab.c"
    break;

  case 57: /* expression: expression OP_EQ expression  */
#line 352 "parser.y"
                                  {
      (yyval.expression) = create_expression(AST_EQ, (yyvsp[-2].expression), (yyvsp[0].expression));
   }
#line 1742 "parser.tab.c"
    break;

  case 58: /* expression: expression OP_TNE expression  */
#line 355 "parser.y"
                                  {
      (yyval.expression) = create_expression(AST_TNE, (yyvsp[-2].expression), (yyvsp[0].expression));
   }
#line 1750 "parser.tab.c"
    break;

  case 59: /* expression: expression OP_NE expression  */
#line 358 "parser.y"
                                  {
      (yyval.expression) = create_expression(AST_NE, (yyvsp[-2].expression), (yyvsp[0].expression));
   }
#line 1758 "parser.tab.c"
    break;

  case 60: /* expression: LPAREN expression RPAREN  */
#line 361 "parser.y"
                              {
      (yyval.expression) = create_expression(AST_PARENT, (yyvsp[-1].expression), NULL);
   }
#line 1766 "parser.tab.c"
    break;

  case 61: /* expression: primary_expression  */
#line 364 "parser.y"
                        {
      (yyval.expression) = (yyvsp[0].expression);
   }
#line 1774 "parser.tab.c"
    break;

  case 62: /* primary_expression: IDENTIFIER LPAREN expression_list RPAREN  */
#line 370 "parser.y"
                                              {
      //$$ = create_function_call($1, $3);
      (yyval.expression) = create_expression(AST_VALUE, NULL, NULL);
      (yyval.expression)->value.tag = AST_FUNCTION_CALL;
      (yyval.expression)->value.primary.function_call = create_function_call((yyvsp[-3].identifier), (yyvsp[-1].expression_list));
   }
#line 1785 "parser.tab.c"
    break;

  case 63: /* primary_expression: IDENTIFIER  */
#line 376 "parser.y"
                {
      (yyval.expression) = create_expression(AST_VALUE, NULL, NULL);
      (yyval.expression)->value.tag = AST_VALUE_IDENTIFIER;
      (yyval.expression)->value.primary.value_identifier = (yyvsp[0].identifier);
   }
#line 1795 "parser.tab.c"
    break;

  case 64: /* primary_expression: INT_CONSTANT  */
#line 381 "parser.y"
                  {
      (yyval.expression) = create_expression(AST_VALUE, NULL, NULL);
      (yyval.expression)->value.tag = AST_VALUE_INT32;
      (yyval.expression)->value.primary.value_int32 = (yyvsp[0].int_const);
   }
#line 1805 "parser.tab.c"
    break;

  case 65: /* primary_expression: FLOAT_CONSTANT  */
#line 386 "parser.y"
                    {
      (yyval.expression) = create_expression(AST_VALUE, NULL, NULL);
      (yyval.expression)->value.tag = AST_VALUE_FLOAT32;
      (yyval.expression)->value.primary.value_float32 = (yyvsp[0].float_const);
   }
#line 1815 "parser.tab.c"
    break;

  case 66: /* primary_expression: STRING_CONSTANT  */
#line 391 "parser.y"
                     {
      (yyval.expression) = create_expression(AST_VALUE, NULL, NULL);
      (yyval.expression)->value.tag = AST_VALUE_STRING;
      (yyval.expression)->value.primary.value_string = (yyvsp[0].string_const);
   }
#line 1825 "parser.tab.c"
    break;

  case 67: /* primary_expression: KW_TRUE  */
#line 396 "parser.y"
             {
      (yyval.expression) = create_expression(AST_VALUE, NULL, NULL);
      (yyval.expression)->value.tag = AST_VALUE_BOOLEAN;
      (yyval.expression)->value.primary.value_boolean = TRUE;
   }
#line 1835 "parser.tab.c"
    break;

  case 68: /* primary_expression: KW_FALSE  */
#line 401 "parser.y"
              {
      (yyval.expression) = create_expression(AST_VALUE, NULL, NULL);
      (yyval.expression)->value.tag = AST_VALUE_BOOLEAN;
      (yyval.expression)->value.primary.value_boolean = FALSE;
   }
#line 1845 "parser.tab.c"
    break;

  case 69: /* primary_expression: KW_NULL  */
#line 406 "parser.y"
             {
      (yyval.expression) = create_expression(AST_VALUE, NULL, NULL);
      (yyval.expression)->value.tag = AST_VALUE_NULL;
   }
#line 1854 "parser.tab.c"
    break;

  case 70: /* declaration: type_specifier IDENTIFIER OP_ASSIGN expression  */
#line 414 "parser.y"
                                                    {
      (yyval.declaration) = create_declaration_value((yyvsp[-3].type_specifier), (yyvsp[-2].identifier), (yyvsp[0].expression));
   }
#line 1862 "parser.tab.c"
    break;

  case 71: /* declaration: type_specifier IDENTIFIER  */
#line 417 "parser.y"
                               {
      (yyval.declaration) = create_declaration((yyvsp[-1].type_specifier), (yyvsp[0].identifier));
   }
#line 1870 "parser.tab.c"
    break;

  case 72: /* type_specifier: KW_INT8  */
#line 422 "parser.y"
                            { (yyval.type_specifier) = create_type(AST_VALUE_INT32);     }
#line 1876 "parser.tab.c"
    break;

  case 73: /* type_specifier: KW_INT16  */
#line 423 "parser.y"
                           { (yyval.type_specifier) = create_type(AST_VALUE_INT32);   }
#line 1882 "parser.tab.c"
    break;

  case 74: /* type_specifier: KW_INT32  */
#line 424 "parser.y"
                           { (yyval.type_specifier) = create_type(AST_VALUE_INT32);   }
#line 1888 "parser.tab.c"
    break;

  case 75: /* type_specifier: KW_INT64  */
#line 425 "parser.y"
                           { (yyval.type_specifier) = create_type(AST_VALUE_INT32);   }
#line 1894 "parser.tab.c"
    break;

  case 76: /* type_specifier: KW_UINT8  */
#line 426 "parser.y"
                           { (yyval.type_specifier) = create_type(AST_VALUE_INT32);   }
#line 1900 "parser.tab.c"
    break;

  case 77: /* type_specifier: KW_UINT16  */
#line 427 "parser.y"
                            { (yyval.type_specifier) = create_type(AST_VALUE_INT32);   }
#line 1906 "parser.tab.c"
    break;

  case 78: /* type_specifier: KW_UINT32  */
#line 428 "parser.y"
                            { (yyval.type_specifier) = create_type(AST_VALUE_INT32);   }
#line 1912 "parser.tab.c"
    break;

  case 79: /* type_specifier: KW_UINT64  */
#line 429 "parser.y"
                            { (yyval.type_specifier) = create_type(AST_VALUE_INT32);   }
#line 1918 "parser.tab.c"
    break;

  case 80: /* type_specifier: KW_FLOAT32  */
#line 430 "parser.y"
                             { (yyval.type_specifier) = create_type(AST_VALUE_FLOAT32);   }
#line 1924 "parser.tab.c"
    break;

  case 81: /* type_specifier: KW_FLOAT64  */
#line 431 "parser.y"
                             { (yyval.type_specifier) = create_type(AST_VALUE_FLOAT32);   }
#line 1930 "parser.tab.c"
    break;

  case 82: /* type_specifier: KW_FLOAT128  */
#line 432 "parser.y"
                              { (yyval.type_specifier) = create_type(AST_VALUE_FLOAT32);   }
#line 1936 "parser.tab.c"
    break;

  case 83: /* type_specifier: KW_BOOL  */
#line 433 "parser.y"
                          { (yyval.type_specifier) = create_type(AST_VALUE_BOOLEAN);   }
#line 1942 "parser.tab.c"
    break;

  case 84: /* type_specifier: KW_VOID  */
#line 434 "parser.y"
                          { (yyval.type_specifier) = create_type(AST_VALUE_VOID); }
#line 1948 "parser.tab.c"
    break;


#line 1952 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 437 "parser.y"


//int yylex(YYSTYPE *, void *);

void
yyerror(const char *s)
{
   printf("%s\n", s);
}
