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
#define yyparse         confparse
#define yylex           conflex
#define yyerror         conferror
#define yydebug         confdebug
#define yynerrs         confnerrs
#define yylval          conflval
#define yychar          confchar

/* First part of user prologue.  */
#line 16 "pcomp.y"


  /* -------- System includes:  -------------------------------------------- */

#include <sys/stat.h>
#include <syslog.h>
#include <time.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  /* -------- Includes:  --------------------------------------------------- */

#include "../symtab.h"

extern int num_lines;
extern int testyacc;

static  char    tmp_str[MAX_VARLEN];
static  char    if_str[MAX_VARLEN];
static  char    el_str[MAX_VARLEN];

/* define this to see indivdual parsing. Controled by ptions -y -l */

#define YYERROR_VERBOSE

#define DEBUGYYY
#define TESTPCOMP


#line 110 "parser/pcomp.yacc.c"

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
extern int confdebug;
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
    SP = 258,                      /* SP  */
    NL = 259,                      /* NL  */
    NUM = 260,                     /* NUM  */
    ID = 261,                      /* ID  */
    SEP = 262,                     /* SEP  */
    DIR = 263,                     /* DIR  */
    RID = 264,                     /* RID  */
    DBG = 265,                     /* DBG  */
    LOG = 266,                     /* LOG  */
    DENY = 267,                    /* DENY  */
    YNED = 268,                    /* YNED  */
    FUNC = 269,                    /* FUNC  */
    BEG = 270,                     /* BEG  */
    END = 271,                     /* END  */
    RET = 272,                     /* RET  */
    EQEQ = 273,                    /* EQEQ  */
    LNOT = 274,                    /* LNOT  */
    NUMBER = 275,                  /* NUMBER  */
    OR = 276,                      /* OR  */
    AND = 277,                     /* AND  */
    XOR = 278,                     /* XOR  */
    IF = 279,                      /* IF  */
    ELSE = 280,                    /* ELSE  */
    NOT = 281,                     /* NOT  */
    NEQ = 282,                     /* NEQ  */
    GEQ = 283,                     /* GEQ  */
    SEQ = 284,                     /* SEQ  */
    VAR = 285,                     /* VAR  */
    BUILTIN = 286,                 /* BUILTIN  */
    IBUILTIN = 287,                /* IBUILTIN  */
    UNDEF = 288,                   /* UNDEF  */
    STR = 289,                     /* STR  */
    ROR = 290,                     /* ROR  */
    ROL = 291,                     /* ROL  */
    TO = 292,                      /* TO  */
    FROM = 293,                    /* FROM  */
    STORE = 294,                   /* STORE  */
    RESTORE = 295,                 /* RESTORE  */
    STRVAR = 296,                  /* STRVAR  */
    COMMENT = 297,                 /* COMMENT  */
    COMMENT2 = 298                 /* COMMENT2  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 48 "pcomp.y"
                                                /* stack object type */
    int     val ;                                            /* actual value */
    long    lngval ;                                         /* actual value */
    float   fltlval;                                         /* actual value */
    double  dblval ;                                         /* actual value */
    char    *strval;                                            /* str value */
    Symbol  *sym ;                                       /* symbol table ptr */

#line 209 "parser/pcomp.yacc.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE conflval;

int confparse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SP = 3,                         /* SP  */
  YYSYMBOL_NL = 4,                         /* NL  */
  YYSYMBOL_NUM = 5,                        /* NUM  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_SEP = 7,                        /* SEP  */
  YYSYMBOL_DIR = 8,                        /* DIR  */
  YYSYMBOL_RID = 9,                        /* RID  */
  YYSYMBOL_DBG = 10,                       /* DBG  */
  YYSYMBOL_LOG = 11,                       /* LOG  */
  YYSYMBOL_DENY = 12,                      /* DENY  */
  YYSYMBOL_YNED = 13,                      /* YNED  */
  YYSYMBOL_FUNC = 14,                      /* FUNC  */
  YYSYMBOL_BEG = 15,                       /* BEG  */
  YYSYMBOL_END = 16,                       /* END  */
  YYSYMBOL_RET = 17,                       /* RET  */
  YYSYMBOL_EQEQ = 18,                      /* EQEQ  */
  YYSYMBOL_LNOT = 19,                      /* LNOT  */
  YYSYMBOL_NUMBER = 20,                    /* NUMBER  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_XOR = 23,                       /* XOR  */
  YYSYMBOL_IF = 24,                        /* IF  */
  YYSYMBOL_ELSE = 25,                      /* ELSE  */
  YYSYMBOL_NOT = 26,                       /* NOT  */
  YYSYMBOL_NEQ = 27,                       /* NEQ  */
  YYSYMBOL_GEQ = 28,                       /* GEQ  */
  YYSYMBOL_SEQ = 29,                       /* SEQ  */
  YYSYMBOL_VAR = 30,                       /* VAR  */
  YYSYMBOL_BUILTIN = 31,                   /* BUILTIN  */
  YYSYMBOL_IBUILTIN = 32,                  /* IBUILTIN  */
  YYSYMBOL_UNDEF = 33,                     /* UNDEF  */
  YYSYMBOL_STR = 34,                       /* STR  */
  YYSYMBOL_ROR = 35,                       /* ROR  */
  YYSYMBOL_ROL = 36,                       /* ROL  */
  YYSYMBOL_TO = 37,                        /* TO  */
  YYSYMBOL_FROM = 38,                      /* FROM  */
  YYSYMBOL_STORE = 39,                     /* STORE  */
  YYSYMBOL_RESTORE = 40,                   /* RESTORE  */
  YYSYMBOL_STRVAR = 41,                    /* STRVAR  */
  YYSYMBOL_COMMENT = 42,                   /* COMMENT  */
  YYSYMBOL_COMMENT2 = 43,                  /* COMMENT2  */
  YYSYMBOL_44_ = 44,                       /* '='  */
  YYSYMBOL_45_ = 45,                       /* ';'  */
  YYSYMBOL_46_ = 46,                       /* ','  */
  YYSYMBOL_47_ = 47,                       /* '<'  */
  YYSYMBOL_48_ = 48,                       /* '>'  */
  YYSYMBOL_49_ = 49,                       /* '|'  */
  YYSYMBOL_50_ = 50,                       /* '&'  */
  YYSYMBOL_51_ = 51,                       /* '^'  */
  YYSYMBOL_52_ = 52,                       /* '+'  */
  YYSYMBOL_53_ = 53,                       /* '-'  */
  YYSYMBOL_54_ = 54,                       /* '*'  */
  YYSYMBOL_55_ = 55,                       /* '/'  */
  YYSYMBOL_56_ = 56,                       /* '%'  */
  YYSYMBOL_57_ = 57,                       /* '('  */
  YYSYMBOL_58_ = 58,                       /* ')'  */
  YYSYMBOL_59_ = 59,                       /* '!'  */
  YYSYMBOL_60_ = 60,                       /* '{'  */
  YYSYMBOL_61_ = 61,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_all1 = 63,                      /* all1  */
  YYSYMBOL_comments = 64,                  /* comments  */
  YYSYMBOL_debug1 = 65,                    /* debug1  */
  YYSYMBOL_decl1 = 66,                     /* decl1  */
  YYSYMBOL_funcbody2 = 67,                 /* funcbody2  */
  YYSYMBOL_funcbody = 68,                  /* funcbody  */
  YYSYMBOL_assn2 = 69,                     /* assn2  */
  YYSYMBOL_assn1 = 70,                     /* assn1  */
  YYSYMBOL_exprlist = 71,                  /* exprlist  */
  YYSYMBOL_condexpr = 72,                  /* condexpr  */
  YYSYMBOL_expr1 = 73,                     /* expr1  */
  YYSYMBOL_expr2 = 74,                     /* expr2  */
  YYSYMBOL_expr2a = 75,                    /* expr2a  */
  YYSYMBOL_expr3 = 76,                     /* expr3  */
  YYSYMBOL_expr4 = 77,                     /* expr4  */
  YYSYMBOL_elsedecl1 = 78,                 /* elsedecl1  */
  YYSYMBOL_ifdecl1 = 79,                   /* ifdecl1  */
  YYSYMBOL_if1 = 80,                       /* if1  */
  YYSYMBOL_val1 = 81,                      /* val1  */
  YYSYMBOL_fdecl1 = 82,                    /* fdecl1  */
  YYSYMBOL_fdecl2 = 83,                    /* fdecl2  */
  YYSYMBOL_fdecl3 = 84,                    /* fdecl3  */
  YYSYMBOL_funcdecl = 85,                  /* funcdecl  */
  YYSYMBOL_func1 = 86,                     /* func1  */
  YYSYMBOL_ret1 = 87                       /* ret1  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   359

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
       2,     2,     2,    59,     2,     2,     2,    56,    50,     2,
      57,    58,    54,    52,    46,    53,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
      47,    44,    48,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,    49,    61,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,    94,   105,   119,   131,   155,   166,   180,
     193,   208,   224,   234,   257,   292,   293,   294,   295,   296,
     297,   302,   303,   307,   313,   320,   326,   332,   359,   363,
     372,   373,   381,   389,   396,   403,   410,   419,   434,   438,
     444,   450,   456,   462,   468,   475,   481,   487,   495,   501,
     507,   513,   521,   524,   532,   539,   546,   552,   558,   564,
     570,   576,   582,   591,   599,   609,   621,   632,   641,   654,
     664,   673,   685,   686,   693,   701,   716,   742,   751
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
  "\"end of file\"", "error", "\"invalid token\"", "SP", "NL", "NUM",
  "ID", "SEP", "DIR", "RID", "DBG", "LOG", "DENY", "YNED", "FUNC", "BEG",
  "END", "RET", "EQEQ", "LNOT", "NUMBER", "OR", "AND", "XOR", "IF", "ELSE",
  "NOT", "NEQ", "GEQ", "SEQ", "VAR", "BUILTIN", "IBUILTIN", "UNDEF", "STR",
  "ROR", "ROL", "TO", "FROM", "STORE", "RESTORE", "STRVAR", "COMMENT",
  "COMMENT2", "'='", "';'", "','", "'<'", "'>'", "'|'", "'&'", "'^'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'", "'!'", "'{'", "'}'",
  "$accept", "all1", "comments", "debug1", "decl1", "funcbody2",
  "funcbody", "assn2", "assn1", "exprlist", "condexpr", "expr1", "expr2",
  "expr2a", "expr3", "expr4", "elsedecl1", "ifdecl1", "if1", "val1",
  "fdecl1", "fdecl2", "fdecl3", "funcdecl", "func1", "ret1", YY_NULLPTR
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
     295,   296,   297,   298,    61,    59,    44,    60,    62,   124,
      38,    94,    43,    45,    42,    47,    37,    40,    41,    33,
     123,   125
};
#endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -64,   215,   -64,    -2,    25,    12,   -37,   -64,   -64,   -64,
     -64,   -64,   -64,   -17,   -34,   -64,   -14,   -64,    -4,   159,
     -64,   -64,   -64,   -64,   232,   -64,   138,    -3,   -24,   177,
     -64,   -36,   232,   -64,   232,   232,   232,   232,   250,   232,
       3,     9,   290,    26,   -21,   -64,   -64,    -1,     5,   290,
       0,   195,   -64,   -64,   -64,    56,    13,   -64,   271,   -64,
     -64,    63,   -64,   -64,   -31,    77,    29,   302,   214,   -64,
     -64,   -64,   -64,   -64,    27,     1,   -64,   -64,   -64,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   -64,   -64,   305,    51,
     -64,   -64,   -64,   -64,    75,   -64,   -64,    97,   -64,   -64,
     -64,   -29,   308,   232,   -64,   308,    26,    26,    26,   308,
     308,   308,   308,   308,    26,    26,    26,   -21,   -21,   -64,
     -64,   -64,   -64,   -64,    31,   -64,   -64,   232,   -64,   -64,
     138,   308,   118,   -64
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     9,    10,     4,
       3,     5,     8,     0,     0,     7,     0,     6,     0,    30,
      67,    68,    11,    74,    30,    23,     0,     0,     0,     0,
      14,    68,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    38,    45,    48,    52,    68,     0,     0,
      68,     0,    16,    18,    21,     0,     0,    17,     0,    20,
      19,     0,    72,    70,     0,     0,     0,     0,     0,    57,
      61,    59,    58,    60,    68,     0,    56,    27,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    64,    77,     0,    65,
      22,    15,    37,    69,     0,    73,    75,     0,    12,    13,
      54,     0,    28,     0,    53,    33,    39,    40,    41,    34,
      35,    36,    31,    32,    42,    43,    44,    46,    47,    49,
      50,    51,    78,    63,     0,    71,    76,     0,    55,    62,
       0,    29,     0,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,   -64,    88,   -64,    91,   -54,   -63,   -64,     6,   -64,
      69,   -64,   -19,   -43,    -5,   -23,   -64,   -64,    94,    93,
       4,   -64,   -64,   -64,   -64,   -64
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    52,    10,    53,    54,    55,    12,    56,   111,
      41,    57,    58,    43,    44,    45,   134,    14,    59,    46,
      63,    64,    28,    16,    17,    60
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      42,   100,   107,    61,    18,    49,    18,    13,    19,    69,
      67,    70,    71,    72,    73,   104,    76,   137,    23,    75,
      24,    68,    80,    81,    82,    40,    26,   105,    25,   138,
      20,    21,    98,    93,    94,    95,    65,   116,   117,   118,
      29,    30,    19,    27,    19,   124,   125,   126,    77,   112,
      88,    89,    90,   100,    78,    62,    68,    68,   101,   114,
     115,    20,    50,    96,   119,   120,   121,   122,   123,   103,
     129,   130,   131,    51,   108,    32,   133,   142,    91,    92,
       6,    61,    20,    50,    68,   113,   127,   128,   100,     9,
     139,   140,    11,    48,    51,    15,    32,    22,     7,     8,
       0,     6,    20,    50,     0,     0,    34,    35,   135,    36,
      37,     0,     0,    38,    51,    39,    32,    99,   141,     7,
       8,     6,     0,    20,    50,     0,     0,    34,    35,     0,
      36,    37,     0,     0,    38,    51,    39,    32,   106,     7,
       8,     0,     6,    20,    50,     0,     0,    34,    35,     0,
      36,    37,     0,     0,    38,    51,    39,    32,   136,     0,
       7,     8,     6,     0,    20,    31,     0,     0,    34,    35,
       0,    36,    37,     0,     0,    38,     0,    39,    32,   143,
       7,     8,    20,    47,     0,     0,     0,     0,    34,    35,
       0,    36,    37,    33,     0,    38,    32,    39,     0,     0,
      20,    47,     0,     0,     0,     0,     0,     0,     0,    34,
      35,    66,    36,    37,    32,     2,    38,     0,    39,    20,
      47,     3,     0,     0,     0,     4,     0,    34,    35,     5,
      36,    37,     0,    32,    38,     0,    39,    20,    47,     6,
      97,     0,     0,     0,     0,    34,    35,     0,    36,    37,
       0,    32,    38,     0,    39,    20,    74,     7,     8,     0,
       0,     0,     0,     0,    34,    35,     0,    36,    37,    32,
       0,    38,   110,    39,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    35,     0,    36,    37,     0,     0,    38,
       0,    39,    80,    81,    82,     0,     0,     0,     0,     0,
      34,    35,     0,    36,    37,     0,     0,    38,    79,    39,
       0,    80,    81,    82,     0,     0,   102,    83,    84,    85,
      88,    89,    90,    80,    81,    82,    80,    81,    82,    80,
      81,    82,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,     0,     0,   109,     0,     0,
     132,    88,    89,    90,    88,    89,    90,    88,    89,    90
};

static const yytype_int16 yycheck[] =
{
      19,    55,    65,     6,     6,    24,     6,     1,    44,    32,
      29,    34,    35,    36,    37,    46,    39,    46,     6,    38,
      57,    57,    21,    22,    23,    19,    60,    58,    45,    58,
       5,     6,    51,    54,    55,    56,    60,    80,    81,    82,
      44,    45,    44,    57,    44,    88,    89,    90,    45,    68,
      49,    50,    51,   107,    45,    58,    57,    57,    45,    58,
      79,     5,     6,    58,    83,    84,    85,    86,    87,     6,
      93,    94,    95,    17,    45,    19,    25,   140,    52,    53,
      24,     6,     5,     6,    57,    58,    91,    92,   142,     1,
     113,    60,     1,    24,    17,     1,    19,     4,    42,    43,
      -1,    24,     5,     6,    -1,    -1,    50,    51,   104,    53,
      54,    -1,    -1,    57,    17,    59,    19,    61,   137,    42,
      43,    24,    -1,     5,     6,    -1,    -1,    50,    51,    -1,
      53,    54,    -1,    -1,    57,    17,    59,    19,    61,    42,
      43,    -1,    24,     5,     6,    -1,    -1,    50,    51,    -1,
      53,    54,    -1,    -1,    57,    17,    59,    19,    61,    -1,
      42,    43,    24,    -1,     5,     6,    -1,    -1,    50,    51,
      -1,    53,    54,    -1,    -1,    57,    -1,    59,    19,    61,
      42,    43,     5,     6,    -1,    -1,    -1,    -1,    50,    51,
      -1,    53,    54,    34,    -1,    57,    19,    59,    -1,    -1,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    34,    53,    54,    19,     0,    57,    -1,    59,     5,
       6,     6,    -1,    -1,    -1,    10,    -1,    50,    51,    14,
      53,    54,    -1,    19,    57,    -1,    59,     5,     6,    24,
      45,    -1,    -1,    -1,    -1,    50,    51,    -1,    53,    54,
      -1,    19,    57,    -1,    59,     5,     6,    42,    43,    -1,
      -1,    -1,    -1,    -1,    50,    51,    -1,    53,    54,    19,
      -1,    57,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,    53,    54,    -1,    -1,    57,
      -1,    59,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      50,    51,    -1,    53,    54,    -1,    -1,    57,    18,    59,
      -1,    21,    22,    23,    -1,    -1,    45,    27,    28,    29,
      49,    50,    51,    21,    22,    23,    21,    22,    23,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      45,    49,    50,    51,    49,    50,    51,    49,    50,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    63,     0,     6,    10,    14,    24,    42,    43,    64,
      65,    66,    69,    70,    79,    80,    85,    86,     6,    44,
       5,     6,    81,     6,    57,    45,    60,    57,    84,    44,
      45,     6,    19,    34,    50,    51,    53,    54,    57,    59,
      70,    72,    74,    75,    76,    77,    81,     6,    72,    74,
       6,    17,    64,    66,    67,    68,    70,    73,    74,    80,
      87,     6,    58,    82,    83,    60,    34,    74,    57,    77,
      77,    77,    77,    77,     6,    74,    77,    45,    45,    18,
      21,    22,    23,    27,    28,    29,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    58,    45,    74,    61,
      67,    45,    45,     6,    46,    58,    61,    68,    45,    45,
      58,    71,    74,    58,    58,    74,    75,    75,    75,    74,
      74,    74,    74,    74,    75,    75,    75,    76,    76,    77,
      77,    77,    45,    25,    78,    82,    61,    46,    58,    77,
      60,    74,    68,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    63,    63,    63,    63,    63,    64,
      64,    65,    66,    66,    66,    67,    67,    67,    67,    67,
      67,    68,    68,    69,    70,    70,    70,    70,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    73,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    75,    76,    76,
      76,    76,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    78,    79,    80,    80,    81,    81,    82,
      83,    83,    84,    84,    85,    86,    86,    87,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     1,
       1,     2,     5,     5,     3,     2,     1,     1,     1,     1,
       1,     1,     2,     2,     3,     3,     4,     4,     1,     3,
       0,     3,     3,     3,     3,     3,     3,     2,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     4,     2,     2,     2,     2,
       2,     2,     4,     1,     4,     4,     8,     1,     1,     2,
       1,     3,     2,     3,     2,     4,     5,     2,     3
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
  case 2: /* all1: %empty  */
#line 92 "pcomp.y"
         {   /* empty */
         }
#line 1411 "parser/pcomp.yacc.c"
    break;

  case 3: /* all1: all1 debug1  */
#line 95 "pcomp.y"
            {
            #ifdef TESTPCOMP
            if(testyacc)
                printf("{all1}: %s\r\n", (yyvsp[-1].sym));
            #endif

            create_unique(tmp_str, "debug" );
            //Symbol  *st2 = push_symtab((char*)$2, tmp_str, "", ALL_ITEM_DEBUG, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
            }
#line 1426 "parser/pcomp.yacc.c"
    break;

  case 4: /* all1: all1 comments  */
#line 106 "pcomp.y"
            {
            #ifdef TESTPCOMP
            if(testyacc)
                printf("{all1}: %s\r\n", (yyvsp[-1].sym));
            #endif

            create_unique(tmp_str, "comment" );
            (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
            //if(showcomm)
            //    {
            //    printf("%s", (char*)$2);
            //    }
            }
#line 1444 "parser/pcomp.yacc.c"
    break;

  case 5: /* all1: all1 decl1  */
#line 120 "pcomp.y"
            {
            #ifdef TESTPCOMP
            if(testyacc)
                printf("{all1}: %s\r\n", (yyvsp[-1].sym));
            #endif

            create_unique(tmp_str, "decl" );
            //Symbol  *st2 = push_symtab((char*)$2, tmp_str, "", ALL_ITEM_DECL, 0);
            (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
            }
#line 1459 "parser/pcomp.yacc.c"
    break;

  case 6: /* all1: all1 func1  */
#line 132 "pcomp.y"
        {
        #ifdef TESTPCOMP
        if(testyacc)
            printf("{all1}: %s\r\n", (yyvsp[-1].sym));
        #endif

        create_unique(tmp_str, "func" );
        //Symbol  *st2 = push_symtab((char*)$2, tmp_str, "", ALL_ITEM_FUNC, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1474 "parser/pcomp.yacc.c"
    break;

  case 7: /* all1: all1 if1  */
#line 156 "pcomp.y"
        {
        #ifdef TESTPCOMP
        if(testyacc)
            printf("{all1}: %s\r\n", (yyvsp[-1].sym));
        #endif

        create_unique(tmp_str, "if" );
        //Symbol  *st2 = push_symtab((char*)$2, tmp_str, "", ALL_ITEM_IF, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1489 "parser/pcomp.yacc.c"
    break;

  case 8: /* all1: all1 assn2  */
#line 167 "pcomp.y"
        {
        #ifdef TESTPCOMP
        if(testyacc)
            printf("{all1}: %s\r\n", (yyvsp[-1].sym));
        #endif

        create_unique(tmp_str, "assn" );
        //Symbol  *st2 = push_symtab((char*)$2, tmp_str, "", ALL_ITEM_ASSN, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1504 "parser/pcomp.yacc.c"
    break;

  case 9: /* comments: COMMENT  */
#line 181 "pcomp.y"
        {
        #ifdef TESTPCOMP
        if(testyacc)
          printf("{Comment}: %s\r\n", (yyvsp[0].sym));
        #endif

        //create_unique(tmp_str, "comment");
        //Symbol  *st2 = push_symtab(tmp_str, "tmp", COMMENT, 0);
        //Symbol  *st = push_symtab("Comment", (char*)$1, COMMENT, 0);
        //if(showcomm)
        //  printf("%s", $1);
        }
#line 1521 "parser/pcomp.yacc.c"
    break;

  case 10: /* comments: COMMENT2  */
#line 194 "pcomp.y"
        {
        #ifdef TESTPCOMP
        if(testyacc)
          printf("{Comment}: %s\r\n", (yyvsp[0].sym));
        #endif

        create_unique(tmp_str, "comment");
        Symbol  *st2 = push_symtab(tmp_str, "tmp", "", COMMENT2, 0);
        Symbol  *st = push_symtab("Comment", (char*)(yyvsp[0].sym), "", COMMENT2, 0);
        //if(showcomm)
        //    printf("%s", &((char*)$1)[4]); // fourth after start
        }
#line 1538 "parser/pcomp.yacc.c"
    break;

  case 11: /* debug1: DBG val1  */
#line 210 "pcomp.y"
{
    #ifdef TESTPCOMP
    if(testyacc)
        printf("{Debug level}: %s\r\n", (yyvsp[0].sym));
    #endif

    create_unique(tmp_str, "debug");
    Symbol  *st = push_symtab(tmp_str, (char*)(yyvsp[0].sym), "", DBG, (double)atoi((char*)(yyvsp[0].sym)));
    //dump_symtab();
    (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
}
#line 1554 "parser/pcomp.yacc.c"
    break;

  case 12: /* decl1: ID ID '=' STR ';'  */
#line 225 "pcomp.y"
    {
    Symbol  *st;

    #ifdef TESTPCOMP
    if(testyacc)
         printf("{decl}='type=%s var=%s val=%s'\r\n ", (yyvsp[-4].sym), (yyvsp[-3].sym), (yyvsp[-1].sym));
    #endif
    }
#line 1567 "parser/pcomp.yacc.c"
    break;

  case 13: /* decl1: ID ID '=' expr2 ';'  */
#line 235 "pcomp.y"
    {
    Symbol  *st;

    #ifdef TESTPCOMP
    if(testyacc)
         printf("{decl}='type=%s var=%s val=%s'\r\n ", (yyvsp[-4].sym), (yyvsp[-3].sym), (yyvsp[-1].sym));
    #endif

    if(lookup_symtab((char*)(yyvsp[-3].sym), DECL_VAR) != NULL)
        {
        printf("Error: Duplicate definition of '%s' on line %d\r\n", (yyvsp[-3].sym), num_lines);
        errorcount++;
        //errstate++;
        }
    else
        {
        st = push_symtab((char*)(yyvsp[-3].sym), (char*)(yyvsp[-4].sym), (char*)(yyvsp[-1].sym), DECL_VAR, atoi((char*)(yyvsp[-1].sym)));
        //st->con_name = $2->type;  //st->con_var = $4->type;
        }
    (yyval.sym) = (yyvsp[-3].sym);
    }
#line 1593 "parser/pcomp.yacc.c"
    break;

  case 14: /* decl1: ID ID ';'  */
#line 258 "pcomp.y"
    {
    #ifdef TESTPCOMP
    if(testyacc)
         printf("{decl ni}='type=%s var=%s'\r\n", (yyvsp[-2].sym), (yyvsp[-1].sym));
    #endif

    if(lookup_symtab((char*)(yyvsp[-1].sym), DECL_VAR) != NULL)
        {
        printf("Error: Duplicate definition of '%s' on line %d\r\n", (yyvsp[-1].sym), num_lines);
        errorcount++;
        //exit(1);
        }
    else
        {
        Symbol  *st = push_symtab((char*)(yyvsp[-1].sym), (char*)(yyvsp[-2].sym), "", DECL_VAR, 0);

        //printf("decl1: $2 %d  $1 %d\n", $2->type, $1->type);
        //st->con_name = ID; st->con_var = ID;
        }
    (yyval.sym) = (yyvsp[-1].sym);
    }
#line 1619 "parser/pcomp.yacc.c"
    break;

  case 20: /* funcbody2: if1  */
#line 298 "pcomp.y"
            {
            }
#line 1626 "parser/pcomp.yacc.c"
    break;

  case 21: /* funcbody: funcbody2  */
#line 302 "pcomp.y"
                       {}
#line 1632 "parser/pcomp.yacc.c"
    break;

  case 22: /* funcbody: funcbody funcbody2  */
#line 304 "pcomp.y"
            {}
#line 1638 "parser/pcomp.yacc.c"
    break;

  case 23: /* assn2: assn1 ';'  */
#line 308 "pcomp.y"
        {
        }
#line 1645 "parser/pcomp.yacc.c"
    break;

  case 24: /* assn1: ID '=' STR  */
#line 314 "pcomp.y"
        {
        printf("string %s\n", (char*)(yyvsp[0].sym));
        create_unique2(tmp_str, "tmp", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, '=', 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1656 "parser/pcomp.yacc.c"
    break;

  case 25: /* assn1: ID '=' expr2  */
#line 321 "pcomp.y"
        {
        create_unique2(tmp_str, "tmp", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, '=', 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1666 "parser/pcomp.yacc.c"
    break;

  case 26: /* assn1: ID '=' condexpr ';'  */
#line 327 "pcomp.y"
        {
        create_unique2(tmp_str, "tmp", (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym), tmp_str, '=', 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1676 "parser/pcomp.yacc.c"
    break;

  case 27: /* assn1: ID '=' assn1 ';'  */
#line 333 "pcomp.y"
        {
        create_unique2(tmp_str, "tmp", (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym), tmp_str, '=', 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1686 "parser/pcomp.yacc.c"
    break;

  case 28: /* exprlist: expr2  */
#line 360 "pcomp.y"
        {
        Symbol  *st = push_symtab((char*)(yyvsp[0].sym), "", "", DECL_VARITEM, 0);
        }
#line 1694 "parser/pcomp.yacc.c"
    break;

  case 29: /* exprlist: exprlist ',' expr2  */
#line 364 "pcomp.y"
        {
        create_unique2(tmp_str, "arg", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[0].sym), "", tmp_str, DECL_VARITEM, 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", 1031, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1705 "parser/pcomp.yacc.c"
    break;

  case 30: /* condexpr: %empty  */
#line 372 "pcomp.y"
          {}
#line 1711 "parser/pcomp.yacc.c"
    break;

  case 31: /* condexpr: expr2 '<' expr2  */
#line 374 "pcomp.y"
    {
        create_unique2(tmp_str, "cond", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, '<', 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", 1031, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
    }
#line 1722 "parser/pcomp.yacc.c"
    break;

  case 32: /* condexpr: expr2 '>' expr2  */
#line 382 "pcomp.y"
    {
        create_unique2(tmp_str, "cond", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, '<', 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", 1031, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
    }
#line 1733 "parser/pcomp.yacc.c"
    break;

  case 33: /* condexpr: expr2 EQEQ expr2  */
#line 390 "pcomp.y"
    {
        create_unique2(tmp_str, "cond", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, EQEQ, 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", 1031, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
    }
#line 1744 "parser/pcomp.yacc.c"
    break;

  case 34: /* condexpr: expr2 NEQ expr2  */
#line 397 "pcomp.y"
    {
        create_unique2(tmp_str, "cond", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, NEQ, 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", 1031, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
    }
#line 1755 "parser/pcomp.yacc.c"
    break;

  case 35: /* condexpr: expr2 GEQ expr2  */
#line 404 "pcomp.y"
    {
        create_unique2(tmp_str, "cond", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, GEQ, 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", 1031, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
    }
#line 1766 "parser/pcomp.yacc.c"
    break;

  case 36: /* condexpr: expr2 SEQ expr2  */
#line 411 "pcomp.y"
    {
        create_unique2(tmp_str, "cond", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, SEQ, 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", 1031, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
    }
#line 1777 "parser/pcomp.yacc.c"
    break;

  case 37: /* expr1: expr2 ';'  */
#line 420 "pcomp.y"
    {
    #ifdef TESTPCOMP
    if(testyacc)
        printf("{expr1}='%s' \r\n", (yyvsp[-1].sym));
    #endif

    //create_unique2(tmp_str, "expr1", (char*)$1, "");
    //Symbol  *st = push_symtab((char*)$1, tmp_str, "", 1050, 0);

    //Symbol  *st = push_symtab((char*)$1, "", "", 1050, 0);
    (yyval.sym) = (yyvsp[-1].sym);
    }
#line 1794 "parser/pcomp.yacc.c"
    break;

  case 38: /* expr2: expr2a  */
#line 435 "pcomp.y"
        {
        //Symbol  *st = push_symtab("", "", "", 1100, 0);
        }
#line 1802 "parser/pcomp.yacc.c"
    break;

  case 39: /* expr2: expr2 OR expr2a  */
#line 439 "pcomp.y"
        {
        create_unique2(tmp_str, "tmp", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, OR, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1812 "parser/pcomp.yacc.c"
    break;

  case 40: /* expr2: expr2 AND expr2a  */
#line 445 "pcomp.y"
        {
        create_unique2(tmp_str, "tmp", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, AND, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1822 "parser/pcomp.yacc.c"
    break;

  case 41: /* expr2: expr2 XOR expr2a  */
#line 451 "pcomp.y"
        {
        create_unique2(tmp_str, "tmp", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, XOR, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1832 "parser/pcomp.yacc.c"
    break;

  case 42: /* expr2: expr2 '|' expr2a  */
#line 457 "pcomp.y"
        {
        create_unique2(tmp_str, "tmp", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, '|', 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1842 "parser/pcomp.yacc.c"
    break;

  case 43: /* expr2: expr2 '&' expr2a  */
#line 463 "pcomp.y"
        {
        create_unique2(tmp_str, "tmp", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, '&', 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1852 "parser/pcomp.yacc.c"
    break;

  case 44: /* expr2: expr2 '^' expr2a  */
#line 469 "pcomp.y"
        {
        create_unique2(tmp_str, "tmp", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, '^', 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1862 "parser/pcomp.yacc.c"
    break;

  case 45: /* expr2a: expr3  */
#line 476 "pcomp.y"
        {
        //create_unique(tmp_str, "var");
        //Symbol  *st = push_symtab(tmp_str, "", 1002, 0);
        //Symbol  *st = push_symtab((char*)$1, "", 1002, 0);
        }
#line 1872 "parser/pcomp.yacc.c"
    break;

  case 46: /* expr2a: expr2a '+' expr3  */
#line 482 "pcomp.y"
        {
        create_unique2(tmp_str, "tmp", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, '+', 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1882 "parser/pcomp.yacc.c"
    break;

  case 47: /* expr2a: expr2a '-' expr3  */
#line 488 "pcomp.y"
        {
        create_unique2(tmp_str, "tmp", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, '-', 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1892 "parser/pcomp.yacc.c"
    break;

  case 48: /* expr3: expr4  */
#line 496 "pcomp.y"
        {
        //Symbol  *st = push_symtab((char*)$1, "", ' ', 0);
        //create_unique(tmp_str, "var");
        //$$ = tmp_str;
        }
#line 1902 "parser/pcomp.yacc.c"
    break;

  case 49: /* expr3: expr3 '*' expr4  */
#line 502 "pcomp.y"
        {
        create_unique2(tmp_str, "tmp", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, '*', 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1912 "parser/pcomp.yacc.c"
    break;

  case 50: /* expr3: expr3 '/' expr4  */
#line 508 "pcomp.y"
        {
        create_unique2(tmp_str, "tmp", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, '/', 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1922 "parser/pcomp.yacc.c"
    break;

  case 51: /* expr3: expr3 '%' expr4  */
#line 514 "pcomp.y"
        {
        create_unique2(tmp_str, "tmp", (char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, '%', 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1932 "parser/pcomp.yacc.c"
    break;

  case 52: /* expr4: val1  */
#line 522 "pcomp.y"
        {
        }
#line 1939 "parser/pcomp.yacc.c"
    break;

  case 53: /* expr4: '(' expr2 ')'  */
#line 525 "pcomp.y"
        {
        //Symbol  *st = push_symtab((char*)$2, "", '(', 0);
        //create_unique(tmp_str, "tmp");
        //Symbol  *st2 = push_symtab(tmp_str, "", DECL_VAR3, 0);
        //$$ = estrdup(tmp_str);
        (yyval.sym) = (yyvsp[-1].sym);
        }
#line 1951 "parser/pcomp.yacc.c"
    break;

  case 54: /* expr4: ID '(' ')'  */
#line 533 "pcomp.y"
        {
        create_unique2(tmp_str, "call", (char*)(yyvsp[-2].sym), (char*)"void");
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)"", tmp_str, DECL_CALL2, 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", DECL_CALL, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1962 "parser/pcomp.yacc.c"
    break;

  case 55: /* expr4: ID '(' exprlist ')'  */
#line 540 "pcomp.y"
        {
        create_unique2(tmp_str, "call", (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym));
        Symbol  *st = push_symtab((char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym), tmp_str, DECL_CALL3, 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", DECL_CALL, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1973 "parser/pcomp.yacc.c"
    break;

  case 56: /* expr4: '!' expr4  */
#line 547 "pcomp.y"
        {
        create_unique(tmp_str, "tmp");
        Symbol  *st = push_symtab((char*)(yyvsp[0].sym), (char*)"", tmp_str, '!', 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1983 "parser/pcomp.yacc.c"
    break;

  case 57: /* expr4: LNOT expr4  */
#line 553 "pcomp.y"
        {
        create_unique(tmp_str, "tmp");
        Symbol  *st = push_symtab((char*)(yyvsp[0].sym), (char*)"", tmp_str, LNOT, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 1993 "parser/pcomp.yacc.c"
    break;

  case 58: /* expr4: '-' expr4  */
#line 559 "pcomp.y"
        {
        create_unique(tmp_str, "tmp");
        Symbol  *st = push_symtab((char*)(yyvsp[0].sym), "", tmp_str, '-', 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 2003 "parser/pcomp.yacc.c"
    break;

  case 59: /* expr4: '^' expr4  */
#line 565 "pcomp.y"
        {
        create_unique(tmp_str, "tmp");
        Symbol  *st = push_symtab((char*)(yyvsp[0].sym), "", tmp_str, '^', 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 2013 "parser/pcomp.yacc.c"
    break;

  case 60: /* expr4: '*' expr4  */
#line 571 "pcomp.y"
        {
        create_unique(tmp_str, "tmp");
        Symbol  *st = push_symtab((char*)(yyvsp[0].sym), "", tmp_str, DECL_DEREF, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 2023 "parser/pcomp.yacc.c"
    break;

  case 61: /* expr4: '&' expr4  */
#line 577 "pcomp.y"
        {
        create_unique(tmp_str, "tmp");
        Symbol  *st = push_symtab((char*)(yyvsp[0].sym), "", tmp_str, DECL_ADDOF, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 2033 "parser/pcomp.yacc.c"
    break;

  case 62: /* expr4: '(' ID ')' expr4  */
#line 583 "pcomp.y"
        {
        create_unique(tmp_str, "tmp");
        Symbol  *st = push_symtab((char*)(yyvsp[-2].sym), (char*)(yyvsp[0].sym), tmp_str, DECL_CAST, 0);
        //$$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        (yyval.sym) = (void*)estrdup2((char*)(yyvsp[0].sym), __LINE__, __FILE__);
        }
#line 2044 "parser/pcomp.yacc.c"
    break;

  case 63: /* elsedecl1: ELSE  */
#line 592 "pcomp.y"
        {
        peek_ifstack(tmp_str, if_str, el_str, NULL);
        Symbol  *st = push_symtab(tmp_str, if_str, el_str, DECL_ELSE, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 2054 "parser/pcomp.yacc.c"
    break;

  case 64: /* ifdecl1: IF '(' condexpr ')'  */
#line 600 "pcomp.y"
        {
        create_unique(if_str, "if");
        create_unique(el_str, "else");
        Symbol  *st = push_symtab((char*)(yyvsp[-1].sym), if_str, el_str, DECL_IF, 0);
        push_ifstack( (char *)(yyvsp[-1].sym), if_str, el_str, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 2066 "parser/pcomp.yacc.c"
    break;

  case 65: /* if1: ifdecl1 '{' funcbody '}'  */
#line 610 "pcomp.y"
        {
        if((yyvsp[-1].sym))
            {
            Symbol  *st2 = push_symtab((char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym), "", TERM_IF, 0);
            }

        pop_ifstack(tmp_str, if_str, el_str, NULL);

        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 2081 "parser/pcomp.yacc.c"
    break;

  case 66: /* if1: ifdecl1 '{' funcbody '}' elsedecl1 '{' funcbody '}'  */
#line 622 "pcomp.y"
        {
        pop_ifstack(tmp_str, if_str, el_str, 0);
        Symbol  *st2 = push_symtab(tmp_str, if_str, "", TERM_IF, 0);

        create_unique2(tmp_str, "else", (char*)(yyvsp[-5].sym), "");
        //Symbol  *st2 = push_symtab(tmp_str, "", 1014, 0);
        (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
#line 2094 "parser/pcomp.yacc.c"
    break;

  case 67: /* val1: NUM  */
#line 633 "pcomp.y"
        {
        #ifdef TESTPCOMP
        if(testyacc)
           printf("{val}='%s' NUM", (char*)(yyvsp[0].sym));
        #endif
        //$1->type = NUM;
        (yyval.sym) = (yyvsp[0].sym);
        }
#line 2107 "parser/pcomp.yacc.c"
    break;

  case 68: /* val1: ID  */
#line 642 "pcomp.y"
        {
        #ifdef TESTPCOMP
        if(testyacc)
           printf("{val}='%s' ID", (char*)(yyvsp[0].sym));
        #endif

        //$1->type = ID;
        (yyval.sym) = (yyvsp[0].sym);
        }
#line 2121 "parser/pcomp.yacc.c"
    break;

  case 69: /* fdecl1: ID ID  */
#line 655 "pcomp.y"
    {
    //strcpy($$->name, $1);
    create_unique2(tmp_str, "funcarg", (char*)(yyvsp[0].sym), (char*)(yyvsp[-1].sym));
    Symbol  *st = push_symtab((char*)(yyvsp[0].sym), (char*)(yyvsp[-1].sym), tmp_str, FUNC_DECL_ARG, 0);
            (yyval.sym) = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
    }
#line 2132 "parser/pcomp.yacc.c"
    break;

  case 70: /* fdecl2: fdecl1  */
#line 665 "pcomp.y"
    {
    #ifdef TESTPCOMP
    if(testyacc)
         printf("{fdecl1}='%s'\r\n", (yyvsp[0].sym));
    #endif
    //$$ = (void*)estrdup((char*)$1);
    (yyval.sym) = (void*)estrdup2((char*)(yyvsp[0].sym), __LINE__, __FILE__);
    }
#line 2145 "parser/pcomp.yacc.c"
    break;

  case 71: /* fdecl2: fdecl2 ',' fdecl1  */
#line 674 "pcomp.y"
    {
    #ifdef TESTPCOMP
    if(testyacc)
         printf("{Fdecl2}='%s' '%s'\r\n", (yyvsp[-2].sym), (yyvsp[0].sym));
    #endif
    (yyval.sym) = (void*)estrdup2((char*)(yyvsp[-2].sym), __LINE__, __FILE__);
    //$$ = (void*)estrdup((char*)$1);
    }
#line 2158 "parser/pcomp.yacc.c"
    break;

  case 72: /* fdecl3: '(' ')'  */
#line 685 "pcomp.y"
                { }
#line 2164 "parser/pcomp.yacc.c"
    break;

  case 73: /* fdecl3: '(' fdecl2 ')'  */
#line 687 "pcomp.y"
    {
        (yyval.sym) = (void*)estrdup2((char*)(yyvsp[-1].sym), __LINE__, __FILE__);
        //$$ = (void*)estrdup((char*)$2);
    }
#line 2173 "parser/pcomp.yacc.c"
    break;

  case 74: /* funcdecl: FUNC ID  */
#line 694 "pcomp.y"
    {
    Symbol  *st = push_symtab((char*)(yyvsp[0].sym), "", "", FUNC_DECL_NAME, 0);
    //$$ = (void*)estrdup((char*)$2);
    (yyval.sym) = (void*)estrdup2((char*)(yyvsp[0].sym), __LINE__, __FILE__);
    }
#line 2183 "parser/pcomp.yacc.c"
    break;

  case 75: /* func1: funcdecl fdecl3 '{' '}'  */
#line 702 "pcomp.y"
    {
    if(lookup_symtab((char*)(yyvsp[-3].sym), FUNC) != NULL)
        {
        printf("Error: Duplicate function '%s' on line %d\r\n", (yyvsp[-3].sym), num_lines);
        errorcount++;
        //exit(1);
        }
    else
        {
        Symbol  *st = push_symtab("", "", "", FUNC, 0);
        (yyval.sym) = (yyvsp[-3].sym);
        }

    }
#line 2202 "parser/pcomp.yacc.c"
    break;

  case 76: /* func1: funcdecl fdecl3 '{' funcbody '}'  */
#line 717 "pcomp.y"
    {
    #ifdef TESTPCOMP
    if(testyacc)
         printf("{Function}='%s' '%s'\r\n", (yyvsp[-3].sym), (yyvsp[-1].sym));
    #endif

    if(lookup_symtab((char*)(yyvsp[-4].sym), FUNC) != NULL)
        {
        printf("Error: Duplicate function(2) '%s' on line %d\r\n", (yyvsp[-4].sym), num_lines);
        errorcount++;
        //exit(1);
        }
    else
        {
        if((char*)(yyvsp[-1].sym) == NULL)
                (yyvsp[-1].sym) = (void*)estrdup2((char*)"", __LINE__, __FILE__);
                //$4 = (void*)estrdup("");

        Symbol  *st = push_symtab((char*)(yyvsp[-4].sym), (char*)(yyvsp[-3].sym), (char*)(yyvsp[-1].sym), FUNC, 0);
        (yyval.sym) = (yyvsp[-4].sym);
        }
    }
#line 2229 "parser/pcomp.yacc.c"
    break;

  case 77: /* ret1: RET ';'  */
#line 743 "pcomp.y"
    {
    #ifdef TESTPCOMP
    if(testyacc)
        printf("{ret}='%s'\r\n", (yyvsp[-1].sym));
    #endif
    Symbol  *st = push_symtab("", "", "", RET, 0);
    }
#line 2241 "parser/pcomp.yacc.c"
    break;

  case 78: /* ret1: RET expr2 ';'  */
#line 752 "pcomp.y"
    {
    #ifdef TESTPCOMP
    if(testyacc)
        printf("{ret}='%s' '%s' \r\n", (yyvsp[-2].sym), (yyvsp[-1].sym));
    #endif
    Symbol  *st = push_symtab((char*)(yyvsp[-1].sym), "", "", RET_EXPR, 0);
    }
#line 2253 "parser/pcomp.yacc.c"
    break;


#line 2257 "parser/pcomp.yacc.c"

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

#line 783 "pcomp.y"


///////////////////////////////////////////////////////////////////////////

char    op_str[12];

int  translate_type(int type, char **str)

{
    if(type < 128)
        {
        sprintf(op_str, "'%c'", type);
        *str = op_str;
        }
    else
        switch(type)
        {
        case DECL_DEFINE:     *str = "DECL_DEFINE";     break;
        case DECL_MACRO:      *str = "DECL_MACRO";      break;

        case DECL_VARITEM:  *str = "DECL_VARITEM";      break;
        case DECL_VARLIST:  *str = "DECL_VARLIST";      break;
        case DECL_IF:      *str = "DECL_IF";            break;
        case DECL_ELSE:    *str = "DECL_ELSE";          break;

        case TERM_IF:      *str = "TERM_IF";            break;
        case TERM_ELSE:    *str = "TERM_ELSE";          break;

        case RET_EXPR:      *str = "RET_EXPR";          break;
        case RET_VAL:       *str = "RET_VAL";           break;
        case RET_NUM:       *str = "RET_NUM";           break;

        case FUNC_DECL:     *str = "FUNC_DECL";         break;
        case FUNC_ASSN:     *str = "FUNC_ASSN";         break;
        case FUNC_DECL_ARG:    *str = "FUNC_DECL_ARG";  break;
        case FUNC_DECL_NAME:    *str = "FUNC_DECL_NAME"; break;

        case ALL_ITEM_FUNC:    *str = "ALL_ITEM_FUNC"; break;
        case ALL_ITEM_EXPR:    *str = "ALL_ITEM_EXPR"; break;
        case ALL_ITEM_ASSN:    *str = "ALL_ITEM_ASSN"; break;
        case ALL_ITEM_IF:    *str = "ALL_ITEM_IF"; break;

        case NEQ:               *str = "NEQ !="; break;
        case EQEQ:              *str = "EQEQ =="; break;
        case GEQ:               *str = "GEQ >="; break;
        case SEQ:               *str = "SEQ '<='"; break;

        case ID:                *str = "ID"; break;

        case IF:                *str = "IF"; break;
        case ELSE:              *str = "ELSE"; break;

        case OR:                *str = "LOR || "; break;
        case AND:               *str = "LAND && "; break;
        case XOR:               *str = "LXOR ^^"; break;
        case LNOT:              *str = "LNOT '!!'"; break;

        case SP:                *str = "SP"; break;
        case NL:                *str = "NL"; break;
        case NUM:               *str = "NUM"; break;
        case SEP:               *str = "SEP"; break;

        //case CLASS:           *str = "CLASS"; break;

         case DIR:          *str = "DIR"; break;
         case RID:          *str = "RID"; break;
         case DBG:          *str = "DBG"; break;
         case LOG:          *str = "LOG"; break;
         case DENY:         *str = "DENY"; break;
         case YNED:         *str = "YNED"; break;
         case FUNC:         *str = "FUNC"; break;
         case BEG:          *str = "BEG"; break;
         case END:          *str = "END"; break;
         case RET:          *str = "RET"; break;
         //case LCUR:         *str = "LCUR"; break;
         //case RCUR:         *str = "RCUR"; break;
         //case PLUS:         *str = "PLUS"; break;
         //case MINUS:        *str = "MINUS"; break;
         case COMMENT:      *str = "COMMENT"; break;
         case COMMENT2:     *str = "COMMENT2"; break;
         case NUMBER:       *str = "NUMBER"; break;
         case VAR:          *str = "VAR"; break;
         case BUILTIN:      *str = "BUILTIN"; break;
         case UNDEF:        *str = "UNDEF"; break;
         case STR:          *str = "STR"; break;
         case FROM:         *str = "FROM"; break;
         case STORE:        *str = "STORE"; break;
         case RESTORE:      *str = "RESTORE"; break;
         case STRVAR:       *str = "STRVAR"; break;
         case IBUILTIN:     *str = "IBUILTIN"; break;
         //case UNARYMINUS:   *str = "UNARYMINUS"; break;

        // Translation for off parser defines
        case    DECL_VAR:   *str =  "DECL_VAR"; break;
        case    DECL_VAR2:  *str =  "DECL_VAR2"; break;
        case    DECL_VAR3:  *str =  "DECL_VAR3"; break;

        case    DECL_CALL:  *str =  "DECL_CALL"; break;
        case    DECL_CALL2: *str =  "DECL_CALL2"; break;
        case    DECL_CALL3: *str =  "DECL_CALL3"; break;

        case    DECL_CAST: *str =  "DECL_CAST"; break;
        case    DECL_DEREF: *str =  "DECL_DEREF"; break;
        case    DECL_ADDOF: *str =  "DECL_ADDOF"; break;

        default:
            *str = "XX";
        }

    return 0;
}

///////////////////////////////////////////////////////////////////////////

int     if_func(int type)

{
    return type == FUNC;
}

int     getretcode()

{
    return yynerrs;
}



