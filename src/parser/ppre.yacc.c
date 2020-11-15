/* A Bison parser, made by GNU Bison 3.7.  */

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
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         preparse
#define yylex           prelex
#define yyerror         preerror
#define yydebug         predebug
#define yynerrs         prenerrs
#define yylval          prelval
#define yychar          prechar

/* First part of user prologue.  */
#line 16 "ppre.y"


  /* -------- System includes:  -------------------------------------------- */

#include <sys/stat.h>
#include <syslog.h>
#include <time.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../symtab.h"

/* define this to see indivdual parsing. Controled by ptions -y -l */

#define YYERROR_VERBOSE

#define DEBUGYYY
#define TESTPCOMP

extern FILE *ppfp, *ppfp2;
extern int verbose;

static  char    tmp_str3[128];
static  int     str2int(char *ptr);

int hasdefine = 2;


#line 109 "parser/ppre.yacc.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int predebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PLUS = 258,                    /* PLUS  */
    MINUS = 259,                   /* MINUS  */
    MULT = 260,                    /* MULT  */
    DIV = 261,                     /* DIV  */
    MOD = 262,                     /* MOD  */
    OR = 263,                      /* OR  */
    AND = 264,                     /* AND  */
    XOR = 265,                     /* XOR  */
    NOT = 266,                     /* NOT  */
    LSHIFT = 267,                  /* LSHIFT  */
    RSHIFT = 268,                  /* RSHIFT  */
    PAREN1 = 269,                  /* PAREN1  */
    PAREN2 = 270,                  /* PAREN2  */
    CH = 271,                      /* CH  */
    ID = 272,                      /* ID  */
    SP = 273,                      /* SP  */
    NL = 274,                      /* NL  */
    STR = 275,                     /* STR  */
    COMMENT = 276,                 /* COMMENT  */
    NUM = 277,                     /* NUM  */
    MAC = 278,                     /* MAC  */
    IFDEF = 279,                   /* IFDEF  */
    ENDIF = 280,                   /* ENDIF  */
    ELSE = 281,                    /* ELSE  */
    ELIFDEF = 282,                 /* ELIFDEF  */
    DEF = 283,                     /* DEF  */
    UNDEF = 284,                   /* UNDEF  */
    ERR = 285,                     /* ERR  */
    MSG = 286                      /* MSG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 47 "ppre.y"
                                                /* stack object type */
    int     val ;                                            /* actual value */
    long    lngval ;                                         /* actual value */
    float   fltlval;                                         /* actual value */
    double  dblval ;                                         /* actual value */
    char    *strval;                                            /* str value */
    Symbol  *sym ;                                       /* symbol table ptr */

#line 196 "parser/ppre.yacc.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE prelval;

int preparse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PLUS = 3,                       /* PLUS  */
  YYSYMBOL_MINUS = 4,                      /* MINUS  */
  YYSYMBOL_MULT = 5,                       /* MULT  */
  YYSYMBOL_DIV = 6,                        /* DIV  */
  YYSYMBOL_MOD = 7,                        /* MOD  */
  YYSYMBOL_OR = 8,                         /* OR  */
  YYSYMBOL_AND = 9,                        /* AND  */
  YYSYMBOL_XOR = 10,                       /* XOR  */
  YYSYMBOL_NOT = 11,                       /* NOT  */
  YYSYMBOL_LSHIFT = 12,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 13,                    /* RSHIFT  */
  YYSYMBOL_PAREN1 = 14,                    /* PAREN1  */
  YYSYMBOL_PAREN2 = 15,                    /* PAREN2  */
  YYSYMBOL_CH = 16,                        /* CH  */
  YYSYMBOL_ID = 17,                        /* ID  */
  YYSYMBOL_SP = 18,                        /* SP  */
  YYSYMBOL_NL = 19,                        /* NL  */
  YYSYMBOL_STR = 20,                       /* STR  */
  YYSYMBOL_COMMENT = 21,                   /* COMMENT  */
  YYSYMBOL_NUM = 22,                       /* NUM  */
  YYSYMBOL_MAC = 23,                       /* MAC  */
  YYSYMBOL_IFDEF = 24,                     /* IFDEF  */
  YYSYMBOL_ENDIF = 25,                     /* ENDIF  */
  YYSYMBOL_ELSE = 26,                      /* ELSE  */
  YYSYMBOL_ELIFDEF = 27,                   /* ELIFDEF  */
  YYSYMBOL_DEF = 28,                       /* DEF  */
  YYSYMBOL_UNDEF = 29,                     /* UNDEF  */
  YYSYMBOL_ERR = 30,                       /* ERR  */
  YYSYMBOL_MSG = 31,                       /* MSG  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_all1 = 33,                      /* all1  */
  YYSYMBOL_all2 = 34,                      /* all2  */
  YYSYMBOL_def1 = 35,                      /* def1  */
  YYSYMBOL_undef1 = 36,                    /* undef1  */
  YYSYMBOL_err1 = 37,                      /* err1  */
  YYSYMBOL_msg1 = 38,                      /* msg1  */
  YYSYMBOL_mac1 = 39,                      /* mac1  */
  YYSYMBOL_ifdef1 = 40,                    /* ifdef1  */
  YYSYMBOL_elifdef1 = 41,                  /* elifdef1  */
  YYSYMBOL_endif1 = 42,                    /* endif1  */
  YYSYMBOL_else1 = 43,                     /* else1  */
  YYSYMBOL_sp1 = 44,                       /* sp1  */
  YYSYMBOL_sp1a = 45,                      /* sp1a  */
  YYSYMBOL_sp2 = 46,                       /* sp2  */
  YYSYMBOL_spnl = 47,                      /* spnl  */
  YYSYMBOL_ch2 = 48,                       /* ch2  */
  YYSYMBOL_ops1 = 49,                      /* ops1  */
  YYSYMBOL_ch1 = 50,                       /* ch1  */
  YYSYMBOL_id1 = 51,                       /* id1  */
  YYSYMBOL_num1 = 52,                      /* num1  */
  YYSYMBOL_expr1 = 53,                     /* expr1  */
  YYSYMBOL_expr2 = 54,                     /* expr2  */
  YYSYMBOL_expr3 = 55,                     /* expr3  */
  YYSYMBOL_expr4 = 56,                     /* expr4  */
  YYSYMBOL_expr5 = 57                      /* expr5  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    93,    93,    94,    99,   104,   109,   114,   119,   124,
     129,   134,   139,   144,   149,   156,   162,   167,   183,   188,
     204,   218,   238,   254,   273,   281,   293,   294,   297,   298,
     299,   302,   303,   306,   307,   308,   311,   312,   315,   316,
     317,   318,   319,   321,   328,   334,   340,   346,   352,   358,
     366,   381,   390,   393,   399,   405,   411,   417,   425,   428,
     434,   442,   445,   451,   457,   465,   468,   472,   481
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
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS",
  "MULT", "DIV", "MOD", "OR", "AND", "XOR", "NOT", "LSHIFT", "RSHIFT",
  "PAREN1", "PAREN2", "CH", "ID", "SP", "NL", "STR", "COMMENT", "NUM",
  "MAC", "IFDEF", "ENDIF", "ELSE", "ELIFDEF", "DEF", "UNDEF", "ERR", "MSG",
  "$accept", "all1", "all2", "def1", "undef1", "err1", "msg1", "mac1",
  "ifdef1", "elifdef1", "endif1", "else1", "sp1", "sp1a", "sp2", "spnl",
  "ch2", "ops1", "ch1", "id1", "num1", "expr1", "expr2", "expr3", "expr4",
  "expr5", YY_NULLPTR
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
     285,   286
};
#endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-32)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      64,   -51,   -51,   -51,   -51,   -51,   -51,   -51,    75,   -51,
     -51,   -51,     7,   -51,     7,     7,    17,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,    48,    40,   102,
     -51,   -51,   -51,   -51,     6,     1,    23,   -51,   -51,   -51,
      38,    45,    54,   -51,   -51,    70,    92,    70,    96,    96,
      78,    78,   -51,    78,   -51,   -51,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,     7,    92,    92,   -51,
      24,   -51,   -51,   -51,   -51,    28,    74,   121,   -51,   123,
     -51,   -51,    80,    80,    94,     1,     1,     1,     1,     1,
      23,    23,   -51,   -51,   -51,   107,   -51,   -51,    92,   -51,
      92,    92,    92,   -51,   -16,   -51,   116,    92,   -51,   -51,
     -51,   -51,    -5,   -51,    78,    94
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      26,    38,    39,    40,    41,    42,    43,    50,    45,    47,
      48,    49,    26,    25,    26,    26,    26,     2,     4,     5,
       6,     7,     8,     9,    10,    12,    11,     0,     0,    13,
      46,    36,    44,    14,    51,    52,    58,    61,    65,    27,
       0,     0,     0,     1,     3,     0,     0,     0,     0,     0,
      28,    28,    30,    28,    45,    37,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    26,     0,     0,    31,
       0,    33,    34,    35,    24,     0,    33,     0,    16,     0,
      18,    29,    28,    28,    68,    53,    55,    54,    57,    56,
      59,    60,    62,    63,    64,     0,    19,    20,     0,    32,
       0,     0,     0,    29,     0,    67,    28,     0,    22,    23,
      15,    17,     0,    21,    28,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -51,   -51,    85,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,    -3,   -50,    83,   -41,   -51,   -51,    87,   -51,
     -51,    50,    -7,    81,    72,    62
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    70,    74,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      82,    83,    52,    84,    61,    62,    53,    78,    80,    40,
     114,    41,    42,    52,    56,    57,    58,    43,    59,    60,
       1,     2,     3,     4,     5,    39,    96,    97,    63,    64,
      65,   -28,   104,     6,     7,     8,     9,    10,    11,   -28,
      12,    98,    99,    13,    50,   100,    99,    14,    15,    85,
      86,    87,    88,    89,    51,    66,   112,   108,    52,   109,
     110,   111,    53,    95,   115,    67,   113,     1,     2,     3,
       4,     5,    45,    46,    68,    47,    48,    49,   -28,   -29,
       6,     7,     8,     9,    10,    11,   -28,    12,    69,   -29,
      13,   -31,   -31,   -29,    14,    15,    81,   -29,   103,   -27,
     -27,    44,   -27,   -27,   -27,     1,     2,     3,     4,     5,
      71,    72,    52,    73,    76,    72,    55,    73,     6,     7,
      54,     9,    10,    11,    56,    57,    58,   107,    59,    60,
      75,    77,    79,   106,    81,    92,    93,    94,   101,    99,
     102,    99,    90,    91,   105
};

static const yytype_int8 yycheck[] =
{
      50,    51,    18,    53,     3,     4,    22,    48,    49,    12,
      15,    14,    15,    18,     8,     9,    10,     0,    12,    13,
       3,     4,     5,     6,     7,    18,    67,    68,     5,     6,
       7,    14,    82,    16,    17,    18,    19,    20,    21,    22,
      23,    17,    18,    26,     4,    17,    18,    30,    31,    56,
      57,    58,    59,    60,    14,    17,   106,    98,    18,   100,
     101,   102,    22,    66,   114,    20,   107,     3,     4,     5,
       6,     7,    24,    25,    20,    27,    28,    29,    14,     4,
      16,    17,    18,    19,    20,    21,    22,    23,    18,    14,
      26,    17,    18,    18,    30,    31,    18,    22,    18,    24,
      25,    16,    27,    28,    29,     3,     4,     5,     6,     7,
      18,    19,    18,    21,    18,    19,    29,    21,    16,    17,
      18,    19,    20,    21,     8,     9,    10,    20,    12,    13,
      47,    48,    49,    83,    18,    63,    64,    65,    17,    18,
      17,    18,    61,    62,    82
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    16,    17,    18,    19,
      20,    21,    23,    26,    30,    31,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    18,
      44,    44,    44,     0,    34,    24,    25,    27,    28,    29,
       4,    14,    18,    22,    18,    50,     8,     9,    10,    12,
      13,     3,     4,     5,     6,     7,    17,    20,    20,    18,
      46,    18,    19,    21,    47,    46,    18,    46,    47,    46,
      47,    18,    45,    45,    45,    54,    54,    54,    54,    54,
      55,    55,    56,    56,    56,    44,    47,    47,    17,    18,
      17,    17,    17,    18,    45,    57,    53,    20,    47,    47,
      47,    47,    45,    47,    15,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    33,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    35,    35,    36,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    44,    45,    45,
      45,    46,    46,    47,    47,    47,    48,    48,    49,    49,
      49,    49,    49,    50,    50,    50,    50,    50,    50,    50,
      51,    52,    53,    53,    53,    53,    53,    53,    54,    54,
      54,    55,    55,    55,    55,    56,    56,    56,    57
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     5,     3,     4,
       4,     6,     5,     5,     3,     1,     0,     1,     0,     1,
       2,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     7,     4,     3
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
  case 3: /* all1: all1 all2  */
#line 95 "ppre.y"
        {
        }
#line 1307 "parser/ppre.yacc.c"
    break;

  case 4: /* all2: def1  */
#line 100 "ppre.y"
        {
        if(debuglevel > 0)
            printf(" { all1 def1 '%s'} ", (char*)(yyvsp[0].sym));
        }
#line 1316 "parser/ppre.yacc.c"
    break;

  case 5: /* all2: undef1  */
#line 105 "ppre.y"
        {
        if(debuglevel > 0)
            printf("{all1 undef1 x'%s' }\n", (char*)(yyvsp[0].sym));
        }
#line 1325 "parser/ppre.yacc.c"
    break;

  case 6: /* all2: err1  */
#line 110 "ppre.y"
        {
        if(debuglevel > 0)
            printf("{all1 err1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1334 "parser/ppre.yacc.c"
    break;

  case 7: /* all2: msg1  */
#line 115 "ppre.y"
        {
        if(debuglevel > 0)
            printf("{all1 msg1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1343 "parser/ppre.yacc.c"
    break;

  case 8: /* all2: mac1  */
#line 120 "ppre.y"
        {
        if(debuglevel > 0)
            printf("{all1 mac1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1352 "parser/ppre.yacc.c"
    break;

  case 9: /* all2: ifdef1  */
#line 125 "ppre.y"
        {
        if(debuglevel > 0)
            printf("{all1 ifdef1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1361 "parser/ppre.yacc.c"
    break;

  case 10: /* all2: elifdef1  */
#line 130 "ppre.y"
        {
        if(debuglevel > 0)
            printf("{all1 elifdef1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1370 "parser/ppre.yacc.c"
    break;

  case 11: /* all2: else1  */
#line 135 "ppre.y"
        {
        if(debuglevel > 0)
            printf("{all1 else1 x'%s'  }\n", (char*)(yyvsp[0].sym));
        }
#line 1379 "parser/ppre.yacc.c"
    break;

  case 12: /* all2: endif1  */
#line 140 "ppre.y"
        {
        if(debuglevel > 0)
            printf("{all1 endif1 x'%s' }\n", (char*)(yyvsp[0].sym));
        }
#line 1388 "parser/ppre.yacc.c"
    break;

  case 13: /* all2: ch2  */
#line 145 "ppre.y"
        {
        //if(debuglevel > 0)
        //    printf("{all1: ch2 x '%s'  '%s'}\n", (char*)$1);
        }
#line 1397 "parser/ppre.yacc.c"
    break;

  case 14: /* all2: num1  */
#line 150 "ppre.y"
        {
        if(debuglevel > 0)
            printf("{all1: num1 x '%s' }\n", (char*)(yyvsp[0].sym));
        }
#line 1406 "parser/ppre.yacc.c"
    break;

  case 15: /* def1: sp1 DEF sp2 ID spnl  */
#line 157 "ppre.y"
        {
        if(debuglevel > 0)
            printf("{def1 '%s' '%s'}\n", (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym));
        Symbol  *st2 = push_symtab((char*)(yyvsp[-1].sym), "", "",  DECL_DEFINE, 0);
        }
#line 1416 "parser/ppre.yacc.c"
    break;

  case 16: /* def1: sp1 DEF spnl  */
#line 163 "ppre.y"
        { // Ignore
        }
#line 1423 "parser/ppre.yacc.c"
    break;

  case 17: /* undef1: sp1 UNDEF sp2 ID spnl  */
#line 168 "ppre.y"
        {
        if(debuglevel > 0)
            printf("{undef1 '%s' '%s'}\n", (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym));
        Symbol  *st2 = lookup_symtab((char*)(yyvsp[-1].sym), DECL_DEFINE);
        if(st2)
            {
            //printf("UNDEF removing %s\n", (char*)$4);
            st2->name = strdup("");
            }
        else
            {
            printf("Preprocess Warning: '%s' not defined, cannot undefine.\n",
                (char *) (yyvsp[-1].sym));
            }
        }
#line 1443 "parser/ppre.yacc.c"
    break;

  case 18: /* undef1: sp1 UNDEF spnl  */
#line 184 "ppre.y"
        { // Ignore
        }
#line 1450 "parser/ppre.yacc.c"
    break;

  case 19: /* err1: ERR sp1 STR spnl  */
#line 189 "ppre.y"
    {
        // Erase quotes
        if(hasdefine == 2)
            {
            char *tmp_strx = strdup(((char*)(yyvsp[-1].sym)) + 1);
            char *last = strrchr(tmp_strx, '\"');
            if(last)
                *last = '\0';
            printf("Error: %s\n", tmp_strx);
            free(tmp_strx);
            }
        exit(1);
    }
#line 1468 "parser/ppre.yacc.c"
    break;

  case 20: /* msg1: MSG sp1 STR spnl  */
#line 205 "ppre.y"
    {
        // Erase quotes
        if(hasdefine == 2)
            {
            char *tmp_strx = strdup(((char*)(yyvsp[-1].sym)) + 1);
            char *last = strrchr(tmp_strx, '\"');
            if(last)
                *last = '\0';
            printf("%s\n", tmp_strx);
            free(tmp_strx);
            }
     }
#line 1485 "parser/ppre.yacc.c"
    break;

  case 21: /* mac1: MAC sp1 ID sp1 STR spnl  */
#line 219 "ppre.y"
        {
        // Erase quotes
        char *tmp_strx = strdup(((char*)(yyvsp[-1].sym)) + 1);
        char *last = strrchr(tmp_strx, '\"');
        if(last)
            *last = '\0';

        Symbol  *st = lookup_symtab((char*)(yyvsp[-3].sym), DECL_MACRO);
        if(st)   // replace
            {
            if(st->var) free(st->var);
            st->var = strdup(tmp_strx);
            }
        else
            push_symtab((char*)(yyvsp[-3].sym), tmp_strx, "",  DECL_MACRO, 0);

        free(tmp_strx);
        }
#line 1508 "parser/ppre.yacc.c"
    break;

  case 22: /* ifdef1: sp1 IFDEF sp2 ID spnl  */
#line 239 "ppre.y"
        {
        if(debuglevel > 0)
            printf("{ifdef1 '%s' '%s'}\n", (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym));

        if(lookup_symtab((char*)(yyvsp[-1].sym), DECL_DEFINE) != NULL)
            {
            hasdefine = 2;
            }
         else
            {
            hasdefine = 1;
            }
        }
#line 1526 "parser/ppre.yacc.c"
    break;

  case 23: /* elifdef1: sp1 ELIFDEF sp2 ID spnl  */
#line 255 "ppre.y"
        {
        if(debuglevel > 0)
            printf("{elifdef1 '%s' '%s'}\n", (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym));

        if(hasdefine == 1)
            {
            if(lookup_symtab((char*)(yyvsp[-1].sym), DECL_DEFINE) != NULL)
                {
                hasdefine = 2;
                }
            }
        else
            {
            hasdefine = 0;
            }
        }
#line 1547 "parser/ppre.yacc.c"
    break;

  case 24: /* endif1: sp1 ENDIF spnl  */
#line 274 "ppre.y"
        {
        if(debuglevel > 0)
            printf("{endif1 '%s'}\n", (char*)(yyvsp[-1].sym));
        hasdefine = 2;
        }
#line 1557 "parser/ppre.yacc.c"
    break;

  case 25: /* else1: ELSE  */
#line 282 "ppre.y"
        {
        if(debuglevel > 0)
            printf("{else1 '%s'}\n", (char*)(yyvsp[0].sym));

        if(hasdefine == 1)
            hasdefine = 2;
        else
            hasdefine = 1;
        }
#line 1571 "parser/ppre.yacc.c"
    break;

  case 26: /* sp1: %empty  */
#line 293 "ppre.y"
               {}
#line 1577 "parser/ppre.yacc.c"
    break;

  case 27: /* sp1: SP  */
#line 294 "ppre.y"
               {}
#line 1583 "parser/ppre.yacc.c"
    break;

  case 28: /* sp1a: %empty  */
#line 297 "ppre.y"
                    {}
#line 1589 "parser/ppre.yacc.c"
    break;

  case 29: /* sp1a: SP  */
#line 298 "ppre.y"
                    {}
#line 1595 "parser/ppre.yacc.c"
    break;

  case 30: /* sp1a: sp1a SP  */
#line 299 "ppre.y"
                    {}
#line 1601 "parser/ppre.yacc.c"
    break;

  case 43: /* ch1: CH  */
#line 322 "ppre.y"
      {
      //if(debuglevel > 0)
      //      printf(" { CH '%s' }", (char*)$2);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1612 "parser/ppre.yacc.c"
    break;

  case 44: /* ch1: id1  */
#line 329 "ppre.y"
      { if(debuglevel > 0)
            printf("{ ID '%s' }", (char*)(yyvsp[0].sym));
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1622 "parser/ppre.yacc.c"
    break;

  case 45: /* ch1: SP  */
#line 335 "ppre.y"
      { if(debuglevel > 0)
            printf("{ SP '%s' }", (char*)(yyvsp[0].sym));
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1632 "parser/ppre.yacc.c"
    break;

  case 46: /* ch1: ops1  */
#line 341 "ppre.y"
      { if(debuglevel > 0)
            printf("{ ops '%s' }", (char*)(yyvsp[0].sym));
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1642 "parser/ppre.yacc.c"
    break;

  case 47: /* ch1: NL  */
#line 347 "ppre.y"
      { if(debuglevel > 0)
            printf("{ NL '%s' }", (char*)(yyvsp[0].sym));
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1652 "parser/ppre.yacc.c"
    break;

  case 48: /* ch1: STR  */
#line 353 "ppre.y"
      { if(debuglevel > 0)
            printf("{ STR '%s}' ", (char*)(yyvsp[0].sym));
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1662 "parser/ppre.yacc.c"
    break;

  case 49: /* ch1: COMMENT  */
#line 359 "ppre.y"
      { if(debuglevel > 0)
            printf("{ COM '%s}' ", (char*)(yyvsp[0].sym));
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)(yyvsp[0].sym));
      }
#line 1672 "parser/ppre.yacc.c"
    break;

  case 50: /* id1: ID  */
#line 367 "ppre.y"
    {
    if(debuglevel > 0)
            printf("{ id1 : ID '%s}' ", (char*)(yyvsp[0].sym));
    Symbol *sp = lookup_symtab((char*)(yyvsp[0].sym), DECL_MACRO);
    if(sp)
        {
        printf("Macro expansion '%s to %s'\n",  sp->name, sp->var);
        (yyval.sym) = (void*)strdup(sp->var);
        }
    else
        (yyval.sym) = (yyvsp[0].sym);
    }
#line 1689 "parser/ppre.yacc.c"
    break;

  case 51: /* num1: expr1  */
#line 382 "ppre.y"
        {
        if(hasdefine == 2)
            fprintf(ppfp2, "%d", str2int((char*)(yyvsp[0].sym)));

        str2int((char*)(yyvsp[0].sym));
        }
#line 1700 "parser/ppre.yacc.c"
    break;

  case 52: /* expr1: expr2  */
#line 391 "ppre.y"
    {
    }
#line 1707 "parser/ppre.yacc.c"
    break;

  case 53: /* expr1: expr1 OR expr2  */
#line 394 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) | str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1717 "parser/ppre.yacc.c"
    break;

  case 54: /* expr1: expr1 XOR expr2  */
#line 400 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) ^ str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1727 "parser/ppre.yacc.c"
    break;

  case 55: /* expr1: expr1 AND expr2  */
#line 406 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) & str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1737 "parser/ppre.yacc.c"
    break;

  case 56: /* expr1: expr1 RSHIFT expr2  */
#line 412 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) >> str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1747 "parser/ppre.yacc.c"
    break;

  case 57: /* expr1: expr1 LSHIFT expr2  */
#line 418 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) << str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1757 "parser/ppre.yacc.c"
    break;

  case 58: /* expr2: expr3  */
#line 426 "ppre.y"
    {
    }
#line 1764 "parser/ppre.yacc.c"
    break;

  case 59: /* expr2: expr2 PLUS expr3  */
#line 429 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) + str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1774 "parser/ppre.yacc.c"
    break;

  case 60: /* expr2: expr2 MINUS expr3  */
#line 435 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) - str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1784 "parser/ppre.yacc.c"
    break;

  case 61: /* expr3: expr4  */
#line 443 "ppre.y"
    {
    }
#line 1791 "parser/ppre.yacc.c"
    break;

  case 62: /* expr3: expr3 MULT expr4  */
#line 446 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) * str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1801 "parser/ppre.yacc.c"
    break;

  case 63: /* expr3: expr3 DIV expr4  */
#line 452 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) / str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1811 "parser/ppre.yacc.c"
    break;

  case 64: /* expr3: expr3 MOD expr4  */
#line 458 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[-2].sym)) % str2int((char*)(yyvsp[0].sym));
        sprintf(tmp_str3, "%d", val);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1821 "parser/ppre.yacc.c"
    break;

  case 65: /* expr4: expr5  */
#line 466 "ppre.y"
    {
    }
#line 1828 "parser/ppre.yacc.c"
    break;

  case 66: /* expr4: sp1a PAREN1 sp1a expr1 sp1a PAREN2 sp1a  */
#line 469 "ppre.y"
        {
        (yyval.sym) = (yyvsp[-3].sym);
        }
#line 1836 "parser/ppre.yacc.c"
    break;

  case 67: /* expr4: sp1a MINUS sp1a expr5  */
#line 473 "ppre.y"
        {
        int val = str2int((char*)(yyvsp[0].sym)); val = -val;
        sprintf(tmp_str3, "%d", val);
        //printf("MINUS %d %s\n", val, tmp_str3);
        (yyval.sym) = (void*)strdup(tmp_str3);
        }
#line 1847 "parser/ppre.yacc.c"
    break;

  case 68: /* expr5: sp1a NUM sp1a  */
#line 482 "ppre.y"
        {
        //printf("NUM %s\n", (char*)$2);
        (yyval.sym) = (yyvsp[-1].sym);
        }
#line 1856 "parser/ppre.yacc.c"
    break;


#line 1860 "parser/ppre.yacc.c"

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

#line 487 "ppre.y"


///////////////////////////////////////////////////////////////////////////

int     str2int(char *ptr)

{
    int ret = 0, base = 10, sign = 0;

    if(ptr[0] && ptr[1])    // If string is big enough
        {
        // Determine base
        char base1 = ptr[0], base2 = ptr[1];

        if(base1 == '0' && (base2 == 'x' || base2 == 'X'))
            base = 16, ptr += 2;

        if(base1 == '0' && (base2 == 'y' || base2 == 'Y'))
            base = 8, ptr += 2;

        if(base1 == '0' && (base2 == 'z' || base2 == 'Z'))
            base = 2, ptr += 2;
        }

    if(ptr[0])    // If string is big enough
        {
        // Determine sign
        char sign1 = ptr[0];
        if(sign1 == '-')
            sign = 1, ptr++;
        else if(sign1 == '+')
            ptr++;  // skip plus
        }

    //printf(" str2int(%s) ", ptr);

    while(1)
        {
        char digit = *ptr++;

        if(digit == 0)      // End of str
            break;

        if(digit >= '0' && digit <= '9')
            {
            ret *= base;
            ret += digit - '0';
            }
          else if(digit >= 'A' && digit <= ('A' + base))
            {
            ret *= base;
            ret += digit - 'A' + 10;
            }
          else if(digit >= 'a' && digit <= ('a' + base))
            {
            ret *= base;
            ret += digit - 'a' + 10;
            }
        else
            {
            // Not a valid number
            break;
            }
        }

    if(sign)
        ret = - ret;

    //printf("base=%d  ret=%d\n", base, ret);
    return ret;
}

// EOF
