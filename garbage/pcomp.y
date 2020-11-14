
  /* =====[ PCOMP ]=========================================================

     Description: PCOMP parallel compiler. See README and SYNTAX.

     Revisions:

     REV    DATE         BY             DESCRIPTION
     ----   --------     ----------     -----------------------------------
     0.00   dec/1/2013   Peter Glen     Initial
     0.03   dec/23/2013  Peter Glen     Progress.
     0.04   jan/22/2014  Peter Glen     Added new symtab

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

//#include <sys/param.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/ftp.h>
//#include <signal.h>
//#include <setjmp.h>
//#include <pwd.h>
//#include <unistd.h>
//#include <ctype.h>

  /* -------- Includes:  --------------------------------------------------- */

#include "symtab.h"


extern int testyacc;

static  char    tmp_str[MAX_VARLEN];
static  char    if_str[MAX_VARLEN];
static  char    el_str[MAX_VARLEN];

/* define this to see indivdual parsing. Controled by ptions -y -l */

#define YYERROR_VERBOSE

#define DEBUGYYY
#define TESTPCOMP

%}

%union {                                                /* stack object type */
    int     val ;                                            /* actual value */
    long    lngval ;                                         /* actual value */
    float   fltlval;                                         /* actual value */
    double  dblval ;                                         /* actual value */
    char    *strval;                                            /* str value */
    Symbol  *sym ;                                       /* symbol table ptr */
}

%token <sym>    SP NL NUM ID SEP DIR RID DBG LOG
%token <sym>    DENY YNED FUNC BEG END RET EQEQ LNOT
%token <sym>    NUMBER OR AND XOR IF ELSE  NOT NEQ GEQ SEQ
%token <sym>    VAR BUILTIN IBUILTIN  UNDEF STR ROR ROL
%token <sym>    TO FROM STORE RESTORE STRVAR COMMENT COMMENT2

%type   <sym>   all1
%type   <sym>   debug1
%type   <sym>   decl1
%type   <sym>   fdecl1
%type   <sym>   fdecl2
%type   <sym>   fdecl3
%type   <sym>   func1
%type   <sym>   expr1
%type   <sym>   exprlist
%type   <sym>   expr2
%type   <sym>   expr2a
%type   <sym>   expr3
%type   <sym>   expr4
%type   <sym>   assn1
%type   <sym>   assn2
%type   <sym>   val1
%type   <sym>   comments
%type   <sym>   funcbody
%type   <sym>   funcbody2
%type   <sym>   if1
%type   <sym>   ret1
%type   <sym>   condexpr
%type   <sym>   funcdecl
%type   <sym>   ifdecl1
%type   <sym>   elsedecl1


%%

all1:    {   /* empty */
         }
         | all1 debug1
            {
            #ifdef TESTPCOMP
            if(testyacc)
                printf("{all1}: %s\r\n", $1);
            #endif

            create_unique(tmp_str, "debug" );
            //Symbol  *st2 = push_symtab((char*)$2, tmp_str, "", ALL_ITEM_DEBUG, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
            }
         | all1 comments
            {
            #ifdef TESTPCOMP
            if(testyacc)
                printf("{all1}: %s\r\n", $1);
            #endif

            create_unique(tmp_str, "comment" );
            $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
            //if(showcomm)
            //    {
            //    printf("%s", (char*)$2);
            //    }
            }
         | all1 decl1
            {
            #ifdef TESTPCOMP
            if(testyacc)
                printf("{all1}: %s\r\n", $1);
            #endif

            create_unique(tmp_str, "decl" );
            //Symbol  *st2 = push_symtab((char*)$2, tmp_str, "", ALL_ITEM_DECL, 0);
            $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
            }

         | all1 func1
        {
        #ifdef TESTPCOMP
        if(testyacc)
            printf("{all1}: %s\r\n", $1);
        #endif

        create_unique(tmp_str, "func" );
        //Symbol  *st2 = push_symtab((char*)$2, tmp_str, "", ALL_ITEM_FUNC, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        /*
         | all1 expr1
        {
        #ifdef TESTPCOMP
        if(testyacc)
            printf("{all1}: %s\r\n", $1);
        #endif

        create_unique(tmp_str, "expr" );
        //Symbol  *st2 = push_symtab((char*)$2, tmp_str, "", ALL_ITEM_EXPR, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        */
        | all1 if1
        {
        #ifdef TESTPCOMP
        if(testyacc)
            printf("{all1}: %s\r\n", $1);
        #endif

        create_unique(tmp_str, "if" );
        //Symbol  *st2 = push_symtab((char*)$2, tmp_str, "", ALL_ITEM_IF, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        | all1 assn2
        {
        #ifdef TESTPCOMP
        if(testyacc)
            printf("{all1}: %s\r\n", $1);
        #endif

        create_unique(tmp_str, "assn" );
        //Symbol  *st2 = push_symtab((char*)$2, tmp_str, "", ALL_ITEM_ASSN, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
;

comments:
    COMMENT
        {
        #ifdef TESTPCOMP
        if(testyacc)
          printf("{Comment}: %s\r\n", $1);
        #endif

        //create_unique(tmp_str, "comment");
        //Symbol  *st2 = push_symtab(tmp_str, "tmp", COMMENT, 0);
        //Symbol  *st = push_symtab("Comment", (char*)$1, COMMENT, 0);
        //if(showcomm)
        //  printf("%s", $1);
        }
    | COMMENT2
        {
        #ifdef TESTPCOMP
        if(testyacc)
          printf("{Comment}: %s\r\n", $1);
        #endif

        create_unique(tmp_str, "comment");
        Symbol  *st2 = push_symtab(tmp_str, "tmp", "", COMMENT2, 0);
        Symbol  *st = push_symtab("Comment", (char*)$1, "", COMMENT2, 0);
        if(showcomm)
            printf("%s", &((char*)$1)[4]); // fourth after start
        }
;

debug1: DBG val1

{
    #ifdef TESTPCOMP
    if(testyacc)
        printf("{Debug level}: %s\r\n", $2);
    #endif

    create_unique(tmp_str, "debug");
    Symbol  *st = push_symtab(tmp_str, (char*)$2, "", DBG, (double)atoi((char*)$2));
    //dump_symtab();
    $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
}
;

decl1:
    ID ID  '='  STR  ';'
    {
    Symbol  *st;

    #ifdef TESTPCOMP
    if(testyacc)
         printf("{decl}='type=%s var=%s val=%s'\r\n ", $1, $2, $4);
    #endif
    }

    | ID ID  '='  expr2  ';'
    {
    Symbol  *st;

    #ifdef TESTPCOMP
    if(testyacc)
         printf("{decl}='type=%s var=%s val=%s'\r\n ", $1, $2, $4);
    #endif

    if(lookup_symtab((char*)$2, DECL_VAR) != NULL)
        {
        printf("Error: Duplicate definition of '%s' on line %d\r\n", $2, num_lines);
        errorcount++;
        //errstate++;
        }
    else
        {
        st = push_symtab((char*)$2, (char*)$1, (char*)$4, DECL_VAR, atoi((char*)$4));
        //st->con_name = $2->type;  //st->con_var = $4->type;
        }
    $$ = $2;
    }

    | ID ID ';'
    {
    #ifdef TESTPCOMP
    if(testyacc)
         printf("{decl ni}='type=%s var=%s'\r\n", $1, $2);
    #endif

    if(lookup_symtab((char*)$2, DECL_VAR) != NULL)
        {
        printf("Error: Duplicate definition of '%s' on line %d\r\n", $2, num_lines);
        errorcount++;
        //exit(1);
        }
    else
        {
        Symbol  *st = push_symtab((char*)$2, (char*)$1, "", DECL_VAR, 0);

        //printf("decl1: $2 %d  $1 %d\n", $2->type, $1->type);
        //st->con_name = ID; st->con_var = ID;
        }
    $$ = $2;
    }

  /*
    | ID  exprlist  ';'
    {
    Symbol  *st = push_symtab((char*)$2, (char*)$1, "", DECL_VARLIST, 0);
    }
    | ID assnlist  ';'
    {
    Symbol  *st = push_symtab((char*)$1,  "", "", DECL_VARLIST, 0);
    }
    */
;

funcbody2:    assn1 ';'
            | comments
            | expr1
            | decl1
            | ret1
            | if1
            {
            }
;

funcbody:    funcbody2 {}
           | funcbody funcbody2
            {}
;

assn2:  assn1 ';'
        {
        }
;

assn1:
        ID '=' STR
        {
        printf("string %s\n", (char*)$3);
        create_unique2(tmp_str, "tmp", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, '=', 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        | ID '=' expr2
        {
        create_unique2(tmp_str, "tmp", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, '=', 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        |  ID '=' condexpr ';'
        {
        create_unique2(tmp_str, "tmp", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, '=', 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        | ID '=' assn1 ';'
        {
        create_unique2(tmp_str, "tmp", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, '=', 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        /*| ID '=' ID
        {
        create_unique2(tmp_str, "tmp", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, '=', 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        } */

/*
assnlist:   assn1
        {
        Symbol  *st = push_symtab((char*)$1, "", "", DECL_VARITEM, 0);
        }
        | assnlist ','  assn1
        {
        create_unique2(tmp_str, "assn", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$3, "", tmp_str, DECL_VARITEM, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
;
 */

exprlist:     expr2
        {
        Symbol  *st = push_symtab((char*)$1, "", "", DECL_VARITEM, 0);
        }
        | exprlist ',' expr2
        {
        create_unique2(tmp_str, "arg", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$3, "", tmp_str, DECL_VARITEM, 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", 1031, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
;

condexpr: {}
        | expr2 '<' expr2
    {
        create_unique2(tmp_str, "cond", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, '<', 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", 1031, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
    }

        | expr2 '>' expr2
    {
        create_unique2(tmp_str, "cond", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, '<', 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", 1031, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
    }

        | expr2 EQEQ expr2
    {
        create_unique2(tmp_str, "cond", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, EQEQ, 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", 1031, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
    }
        | expr2 NEQ expr2
    {
        create_unique2(tmp_str, "cond", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, NEQ, 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", 1031, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
    }
        | expr2 GEQ expr2
    {
        create_unique2(tmp_str, "cond", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, GEQ, 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", 1031, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
    }
        | expr2 SEQ expr2
    {
        create_unique2(tmp_str, "cond", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, SEQ, 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", 1031, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
    }
;

expr1:  expr2 ';'
    {
    #ifdef TESTPCOMP
    if(testyacc)
        printf("{expr1}='%s' \r\n", $1);
    #endif

    //create_unique2(tmp_str, "expr1", (char*)$1, "");
    //Symbol  *st = push_symtab((char*)$1, tmp_str, "", 1050, 0);

    //Symbol  *st = push_symtab((char*)$1, "", "", 1050, 0);
    $$ = $1;
    }
;

expr2:  expr2a
        {
        //Symbol  *st = push_symtab("", "", "", 1100, 0);
        }
        | expr2 OR  expr2a
        {
        create_unique2(tmp_str, "tmp", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, OR, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        | expr2 AND  expr2a
        {
        create_unique2(tmp_str, "tmp", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, AND, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        | expr2 XOR expr2a
        {
        create_unique2(tmp_str, "tmp", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, XOR, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        | expr2 '|'  expr2a
        {
        create_unique2(tmp_str, "tmp", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, '|', 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        | expr2 '&'  expr2a
        {
        create_unique2(tmp_str, "tmp", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, '&', 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        | expr2 '^'  expr2a
        {
        create_unique2(tmp_str, "tmp", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, '^', 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }

expr2a:  expr3
        {
        //create_unique(tmp_str, "var");
        //Symbol  *st = push_symtab(tmp_str, "", 1002, 0);
        //Symbol  *st = push_symtab((char*)$1, "", 1002, 0);
        }
        | expr2a '+'  expr3
        {
        create_unique2(tmp_str, "tmp", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, '+', 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        | expr2a '-'  expr3
        {
        create_unique2(tmp_str, "tmp", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, '-', 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
;

expr3:  expr4
        {
        //Symbol  *st = push_symtab((char*)$1, "", ' ', 0);
        //create_unique(tmp_str, "var");
        //$$ = tmp_str;
        }
        | expr3 '*'  expr4
        {
        create_unique2(tmp_str, "tmp", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, '*', 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        | expr3 '/'  expr4
        {
        create_unique2(tmp_str, "tmp", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, '/', 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        | expr3 '%'  expr4
        {
        create_unique2(tmp_str, "tmp", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, '%', 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
 ;

expr4:  val1
        {
        }
        |'(' expr2 ')'
        {
        //Symbol  *st = push_symtab((char*)$2, "", '(', 0);
        //create_unique(tmp_str, "tmp");
        //Symbol  *st2 = push_symtab(tmp_str, "", DECL_VAR3, 0);
        //$$ = estrdup(tmp_str);
        $$ = $2;
        }
        |  ID '('  ')'
        {
        create_unique2(tmp_str, "call", (char*)$1, (char*)"void");
        Symbol  *st = push_symtab((char*)$1, (char*)"", tmp_str, DECL_CALL2, 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", DECL_CALL, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        |  ID '(' exprlist ')'
        {
        create_unique2(tmp_str, "call", (char*)$1, (char*)$3);
        Symbol  *st = push_symtab((char*)$1, (char*)$3, tmp_str, DECL_CALL3, 0);
        //Symbol  *st2 = push_symtab(tmp_str, "", DECL_CALL, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        | '!' expr4
        {
        create_unique(tmp_str, "tmp");
        Symbol  *st = push_symtab((char*)$2, (char*)"", tmp_str, '!', 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        | LNOT expr4
        {
        create_unique(tmp_str, "tmp");
        Symbol  *st = push_symtab((char*)$2, (char*)"", tmp_str, LNOT, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        |  '-' expr4
        {
        create_unique(tmp_str, "tmp");
        Symbol  *st = push_symtab((char*)$2, "", tmp_str, '-', 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        |  '^' expr4
        {
        create_unique(tmp_str, "tmp");
        Symbol  *st = push_symtab((char*)$2, "", tmp_str, '^', 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        |  '*' expr4
        {
        create_unique(tmp_str, "tmp");
        Symbol  *st = push_symtab((char*)$2, "", tmp_str, DECL_DEREF, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        |  '&' expr4
        {
        create_unique(tmp_str, "tmp");
        Symbol  *st = push_symtab((char*)$2, "", tmp_str, DECL_ADDOF, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
        |  '(' ID ')' expr4
        {
        create_unique(tmp_str, "tmp");
        Symbol  *st = push_symtab((char*)$2, (char*)$4, tmp_str, DECL_CAST, 0);
        //$$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        $$ = (void*)estrdup2((char*)$4, __LINE__, __FILE__);
        }
;

elsedecl1: ELSE
        {
        peek_ifstack(tmp_str, if_str, el_str, NULL);
        Symbol  *st = push_symtab(tmp_str, if_str, el_str, DECL_ELSE, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
;

ifdecl1: IF '(' condexpr ')'
        {
        create_unique(if_str, "if");
        create_unique(el_str, "else");
        Symbol  *st = push_symtab((char*)$3, if_str, el_str, DECL_IF, 0);
        push_ifstack( (char *)$3, if_str, el_str, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
;

if1:  ifdecl1 '{'  funcbody '}'
        {
        if($3)
            {
            Symbol  *st2 = push_symtab((char*)$1, (char*)$3, "", TERM_IF, 0);
            }

        pop_ifstack(tmp_str, if_str, el_str, NULL);

        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }

    | ifdecl1 '{'  funcbody '}' elsedecl1 '{' funcbody '}'
        {
        pop_ifstack(tmp_str, if_str, el_str, 0);
        Symbol  *st2 = push_symtab(tmp_str, if_str, "", TERM_IF, 0);

        create_unique2(tmp_str, "else", (char*)$3, "");
        //Symbol  *st2 = push_symtab(tmp_str, "", 1014, 0);
        $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
        }
;

val1:   NUM
        {
        #ifdef TESTPCOMP
        if(testyacc)
           printf("{val}='%s' NUM", (char*)$1);
        #endif
        $1->type = NUM;
        $$ = $1;
        }
        |   ID
        {
        #ifdef TESTPCOMP
        if(testyacc)
           printf("{val}='%s' ID", (char*)$1);
        #endif

        $1->type = ID;
        $$ = $1;
        }
;

fdecl1:
    ID ID
    {
    //strcpy($$->name, $1);
    create_unique2(tmp_str, "funcarg", (char*)$2, (char*)$1);
    Symbol  *st = push_symtab((char*)$2, (char*)$1, tmp_str, FUNC_DECL_ARG, 0);
            $$ = (void*)estrdup2(tmp_str, __LINE__, __FILE__);
    }
;

fdecl2:  /* {} | */
    fdecl1
    {
    #ifdef TESTPCOMP
    if(testyacc)
         printf("{fdecl1}='%s'\r\n", $1);
    #endif
    //$$ = (void*)estrdup((char*)$1);
    $$ = (void*)estrdup2((char*)$1, __LINE__, __FILE__);
    }
    | fdecl2 ',' fdecl1
    {
    #ifdef TESTPCOMP
    if(testyacc)
         printf("{Fdecl2}='%s' '%s'\r\n", $1, $3);
    #endif
    $$ = (void*)estrdup2((char*)$1, __LINE__, __FILE__);
    //$$ = (void*)estrdup((char*)$1);
    }
;

fdecl3: /* | {}  empty */
        '(' ')' { }
        | '(' fdecl2 ')'
    {
        $$ = (void*)estrdup2((char*)$2, __LINE__, __FILE__);
        //$$ = (void*)estrdup((char*)$2);
    }
;

funcdecl: FUNC ID
    {
    Symbol  *st = push_symtab((char*)$2, "", "", FUNC_DECL_NAME, 0);
    //$$ = (void*)estrdup((char*)$2);
    $$ = (void*)estrdup2((char*)$2, __LINE__, __FILE__);
    }
;

func1:  funcdecl  fdecl3  '{'  '}'
    {
    if(lookup_symtab((char*)$1, FUNC) != NULL)
        {
        printf("Error: Duplicate function '%s' on line %d\r\n", $1, num_lines);
        errorcount++;
        //exit(1);
        }
    else
        {
        Symbol  *st = push_symtab("", "", "", FUNC, 0);
        $$ = $1;
        }

    }
    | funcdecl  fdecl3  '{' funcbody '}'
    {
    #ifdef TESTPCOMP
    if(testyacc)
         printf("{Function}='%s' '%s'\r\n", $2, $4);
    #endif

    if(lookup_symtab((char*)$1, FUNC) != NULL)
        {
        printf("Error: Duplicate function(2) '%s' on line %d\r\n", $1, num_lines);
        errorcount++;
        //exit(1);
        }
    else
        {
        if((char*)$4 == NULL)
                $4 = (void*)estrdup2((char*)"", __LINE__, __FILE__);
                //$4 = (void*)estrdup("");

        Symbol  *st = push_symtab((char*)$1, (char*)$2, (char*)$4, FUNC, 0);
        $$ = $1;
        }
    }
;

ret1:
    RET ';'
    {
    #ifdef TESTPCOMP
    if(testyacc)
        printf("{ret}='%s'\r\n", $1);
    #endif
    Symbol  *st = push_symtab("", "", "", RET, 0);
    }

    | RET expr2 ';'
    {
    #ifdef TESTPCOMP
    if(testyacc)
        printf("{ret}='%s' '%s' \r\n", $1, $2);
    #endif
    Symbol  *st = push_symtab((char*)$2, "", "", RET_EXPR, 0);
    }
/*    | RET NUM ';'
    {
    #ifdef TESTPCOMP
    if(testyacc)
        printf("{ret}='%s' '%s' \r\n", $1, $2);
    #endif
    Symbol  *st = push_symtab((char*)$2, "", "", RET_NUM, 0);
    }
*/
;

/*

call1:  ID '(' ID ')' ';'
    {
    #ifdef TESTPCOMP
    if(testyacc)
      printf("{CALL} '%s + %s'\n", $3);
    #endif
    Symbol  *st = push_symtab((char*)$1, (char*)$3, 1000, 0);
    }
;
*/

%%

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

