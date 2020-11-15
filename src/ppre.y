
  /* =====[ PPRE ]=========================================================

     Description: PPRE parallel compiler pre processor.

     Revisions:

     REV    DATE         BY             DESCRIPTION
     ----   --------     ----------     -----------------------------------
     0.00   dec/1/2013   Peter Glen     Initial
     0.03   dec/23/2013  Peter Glen     Progress.
     0.04   jan/22/2014  Peter Glen     Added new symtab
     0.05   jan/22/2014  Peter Glen     Constant expressions
     ======================================================================= */

%{

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

%}

%union {                                                /* stack object type */
    int     val ;                                            /* actual value */
    long    lngval ;                                         /* actual value */
    float   fltlval;                                         /* actual value */
    double  dblval ;                                         /* actual value */
    char    *strval;                                            /* str value */
    Symbol  *sym ;                                       /* symbol table ptr */
}

/* operators */
%token <sym>   PLUS MINUS MULT DIV MOD
%token <sym>   OR AND XOR NOT LSHIFT RSHIFT
%token <sym>   PAREN1 PAREN2

/* laguage elements */
%token <sym>   CH ID SP NL STR COMMENT NUM MAC

/* pre processor strtements */
%token <sym>  IFDEF ENDIF ELSE ELIFDEF DEF UNDEF ERR MSG

%type   <sym>   all1
%type   <sym>   all2
%type   <sym>   ch1
%type   <sym>   ops1
%type   <sym>   id1
%type   <sym>   def1
%type   <sym>   err1
%type   <sym>   msg1
%type   <sym>   mac1
%type   <sym>   undef1
%type   <sym>   ifdef1
%type   <sym>   elifdef1
%type   <sym>   endif1
%type   <sym>   sp1
%type   <sym>   sp1a
%type   <sym>   spnl
%type   <sym>   else1
%type   <sym>   num1
%type   <sym>   expr1
%type   <sym>   expr2
%type   <sym>   expr3
%type   <sym>   expr4
%type   <sym>   expr5

%%

all1:   all2
        | all1 all2
        {
        }
;

all2:   def1
        {
        if(debuglevel > 0)
            printf(" { all1 def1 '%s'} ", (char*)$1);
        }
        | undef1
        {
        if(debuglevel > 0)
            printf("{all1 undef1 x'%s' }\n", (char*)$1);
        }
        | err1
        {
        if(debuglevel > 0)
            printf("{all1 err1 x'%s'  }\n", (char*)$1);
        }
        | msg1
        {
        if(debuglevel > 0)
            printf("{all1 msg1 x'%s'  }\n", (char*)$1);
        }
        | mac1
        {
        if(debuglevel > 0)
            printf("{all1 mac1 x'%s'  }\n", (char*)$1);
        }
        | ifdef1
        {
        if(debuglevel > 0)
            printf("{all1 ifdef1 x'%s'  }\n", (char*)$1);
        }
        | elifdef1
        {
        if(debuglevel > 0)
            printf("{all1 elifdef1 x'%s'  }\n", (char*)$1);
        }
        | else1
        {
        if(debuglevel > 0)
            printf("{all1 else1 x'%s'  }\n", (char*)$1);
        }
        | endif1
        {
        if(debuglevel > 0)
            printf("{all1 endif1 x'%s' }\n", (char*)$1);
        }
        | ch2
        {
        //if(debuglevel > 0)
        //    printf("{all1: ch2 x '%s'  '%s'}\n", (char*)$1);
        }
        | num1
        {
        if(debuglevel > 0)
            printf("{all1: num1 x '%s' }\n", (char*)$1);
        }
;

def1:  sp1 DEF sp2 ID spnl
        {
        if(debuglevel > 0)
            printf("{def1 '%s' '%s'}\n", (char*)$2, (char*)$4);
        Symbol  *st2 = push_symtab((char*)$4, "", "",  DECL_DEFINE, 0);
        }
        |  sp1 DEF spnl
        { // Ignore
        }
;

undef1:  sp1 UNDEF sp2 ID spnl
        {
        if(debuglevel > 0)
            printf("{undef1 '%s' '%s'}\n", (char*)$2, (char*)$4);
        Symbol  *st2 = lookup_symtab((char*)$4, DECL_DEFINE);
        if(st2)
            {
            //printf("UNDEF removing %s\n", (char*)$4);
            st2->name = strdup("");
            }
        else
            {
            printf("Preprocess Warning: '%s' not defined, cannot undefine.\n",
                (char *) $4);
            }
        }
        |  sp1 UNDEF spnl
        { // Ignore
        }
;

err1:   ERR sp1 STR spnl
    {
        // Erase quotes
        if(hasdefine == 2)
            {
            char *tmp_strx = strdup(((char*)$3) + 1);
            char *last = strrchr(tmp_strx, '\"');
            if(last)
                *last = '\0';
            printf("Error: %s\n", tmp_strx);
            free(tmp_strx);
            }
        exit(1);
    }
;

msg1:   MSG sp1 STR spnl
    {
        // Erase quotes
        if(hasdefine == 2)
            {
            char *tmp_strx = strdup(((char*)$3) + 1);
            char *last = strrchr(tmp_strx, '\"');
            if(last)
                *last = '\0';
            printf("%s\n", tmp_strx);
            free(tmp_strx);
            }
     }

mac1:   MAC sp1 ID sp1 STR spnl
        {
        // Erase quotes
        char *tmp_strx = strdup(((char*)$5) + 1);
        char *last = strrchr(tmp_strx, '\"');
        if(last)
            *last = '\0';

        Symbol  *st = lookup_symtab((char*)$3, DECL_MACRO);
        if(st)   // replace
            {
            if(st->var) free(st->var);
            st->var = strdup(tmp_strx);
            }
        else
            push_symtab((char*)$3, tmp_strx, "",  DECL_MACRO, 0);

        free(tmp_strx);
        }

ifdef1:  sp1 IFDEF sp2 ID spnl
        {
        if(debuglevel > 0)
            printf("{ifdef1 '%s' '%s'}\n", (char*)$2, (char*)$4);

        if(lookup_symtab((char*)$4, DECL_DEFINE) != NULL)
            {
            hasdefine = 2;
            }
         else
            {
            hasdefine = 1;
            }
        }
;

elifdef1:  sp1 ELIFDEF sp2 ID spnl
        {
        if(debuglevel > 0)
            printf("{elifdef1 '%s' '%s'}\n", (char*)$2, (char*)$4);

        if(hasdefine == 1)
            {
            if(lookup_symtab((char*)$4, DECL_DEFINE) != NULL)
                {
                hasdefine = 2;
                }
            }
        else
            {
            hasdefine = 0;
            }
        }
;

endif1:  sp1 ENDIF spnl
        {
        if(debuglevel > 0)
            printf("{endif1 '%s'}\n", (char*)$2);
        hasdefine = 2;
        }
;

else1:  ELSE
        {
        if(debuglevel > 0)
            printf("{else1 '%s'}\n", (char*)$1);

        if(hasdefine == 1)
            hasdefine = 2;
        else
            hasdefine = 1;
        }
;

sp1:           {}   /* empty */
        | SP   {}   /* single */
;

sp1a:               {}  /* empty */
        | SP        {}  /* single */
        | sp1a SP   {}  /* multiple */
;

sp2:    SP
        | sp2 SP
;

spnl:   SP
        | NL
        | COMMENT
;

ch2:   ch1
      | ch2 ch1
;

ops1:   PLUS
     |  MINUS
     |  MULT
     |  DIV
     |  MOD

ch1:   CH
      {
      //if(debuglevel > 0)
      //      printf(" { CH '%s' }", (char*)$2);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)$1);
      }
      | id1
      { if(debuglevel > 0)
            printf("{ ID '%s' }", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)$1);
      }
      | SP
      { if(debuglevel > 0)
            printf("{ SP '%s' }", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)$1);
      }
      | ops1
      { if(debuglevel > 0)
            printf("{ ops '%s' }", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)$1);
      }
      | NL
      { if(debuglevel > 0)
            printf("{ NL '%s' }", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)$1);
      }
      | STR
      { if(debuglevel > 0)
            printf("{ STR '%s}' ", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)$1);
      }
      | COMMENT
      { if(debuglevel > 0)
            printf("{ COM '%s}' ", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)$1);
      }
;

id1:   ID
    {
    if(debuglevel > 0)
            printf("{ id1 : ID '%s}' ", (char*)$1);
    Symbol *sp = lookup_symtab((char*)$1, DECL_MACRO);
    if(sp)
        {
        printf("Macro expansion '%s to %s'\n",  sp->name, sp->var);
        $$ = (void*)strdup(sp->var);
        }
    else
        $$ = $1;
    }


num1:   expr1
        {
        if(hasdefine == 2)
            fprintf(ppfp2, "%d", str2int((char*)$1));

        str2int((char*)$1);
        }
;

expr1:  expr2
    {
    }
    |   expr1 OR expr2
        {
        int val = str2int((char*)$1) | str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
    |  expr1 XOR expr2
        {
        int val = str2int((char*)$1) ^ str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
    |  expr1 AND expr2
        {
        int val = str2int((char*)$1) & str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
    |  expr1 RSHIFT expr2
        {
        int val = str2int((char*)$1) >> str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
    |  expr1 LSHIFT expr2
        {
        int val = str2int((char*)$1) << str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
;

expr2:   expr3
    {
    }
    |   expr2 PLUS expr3
        {
        int val = str2int((char*)$1) + str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
    |  expr2 MINUS expr3
        {
        int val = str2int((char*)$1) - str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
;

expr3:  expr4
    {
    }
    | expr3 MULT expr4
        {
        int val = str2int((char*)$1) * str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
    |  expr3 DIV expr4
        {
        int val = str2int((char*)$1) / str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
    |  expr3 MOD expr4
        {
        int val = str2int((char*)$1) % str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
;

expr4:  expr5
    {
    }
    | sp1a PAREN1 sp1a expr1 sp1a PAREN2 sp1a
        {
        $$ = $4;
        }
    | sp1a MINUS sp1a expr5
        {
        int val = str2int((char*)$4); val = -val;
        sprintf(tmp_str3, "%d", val);
        //printf("MINUS %d %s\n", val, tmp_str3);
        $$ = (void*)strdup(tmp_str3);
        }
;

expr5:  sp1a NUM sp1a
        {
        //printf("NUM %s\n", (char*)$2);
        $$ = $2;
        }

%%

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