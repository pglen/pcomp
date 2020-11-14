%{

/* This lexer and parser assumes that int is same size as pointer */

#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <getopt.h>

#include "../symtab.h"

static int num_lines = 1, num_chars = 0, backslash = 0;

extern	int testflex;
extern	int debuglevel;
extern	int noprog;
extern	int catpre;

static	char	tmp_str[256];
static	char	tmp_str2[256];
static 	int 	prog = 0;

char ppfile2[MAX_VARLEN];

FILE *ppfp3, *ppfp2;

#define YY_INPUT(buf,result,max_size) \
               { \
               int c = getc(ppfp3); \
               result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
               }

void preerror(const char *str)

{
 	static int count = 0;
  	printf("%s  Line: %d  Near '%s'\n", str, num_lines, yytext); count++;
    if(count > 5) exit(0);
}


#define DEBUGLEX

#include "ppre.yacc.c"


%}

%x STR2
%x COM2

%option noyywrap

FN   [\~_a-zA-Z]
FNN  [\~_a-zA-Z0-9]

%%

\/\/.*\n                       { /* comment */
								num_lines++;

                                if(testflex)
                                    printf("[slash comment2] '%s", yytext);

                                yylval.strval = strdup(yytext);
								return COMMENT;
								}

0x[0-9a-fA-F]+                  {
                                if(testflex)
                                	printf("[NUM] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
                                return(NUM);
                                }

0y[0-7]+                  		{
                                if(testflex)
                                	printf("[NUM] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
                                return(NUM);
                                }

0z[0-1]+                        {
                                if(testflex)
                                	printf("[NUM] '%s' ", yytext);

                                yylval.strval = strdup(yytext);

                                return(NUM);
                                }

[0-9]+                          {
                                if(testflex)
 	                               printf("[NUM] '%s' ", (char*)yytext);

                                yylval.strval = strdup(yytext); return(NUM);
                                }

\>\>                            {
                                if(testflex)
                                    printf(" [RSHIFT] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(RSHIFT);
								}

\<\<                            {
                                if(testflex)
                                    printf(" [LSHIFT] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(LSHIFT);
								}

\+                              {
                                yylval.strval = strdup(yytext); return(PLUS);
								}
\-                              {
                                if(testflex)
                                    printf(" [MINUS] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(MINUS);
								}
\*                              {
                                if(testflex)
                                    printf(" [MULT] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(MULT);
								}
\/                              {
                                if(testflex)
                                    printf(" [DIV] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(DIV);
								}
\%                              {
                                if(testflex)
                                    printf(" [MOD] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(MOD);
								}
\|                              {
                                if(testflex)
                                    printf(" [OR] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(OR);
								}
\&                              {
                                if(testflex)
                                    printf(" [AND] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(AND);
								}
\!                              {
                                yylval.strval = strdup(yytext); return(NOT);
								}
\^                              {
                                if(testflex)
                                    printf(" [XOR] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(XOR);
								}
\(                              {
                                if(testflex)
                                    printf(" [PAREN1] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(PAREN1);
								}
\)                              {
                                if(testflex)
                                    printf(" [PAREN2] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(PAREN2);
								}
#error                      	{
                                if(testflex)
                                    printf(" [error] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
								return ERR;
								}

#macro                      	{
                                if(testflex)
                                    printf(" [mmacro] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
								return MAC;
								}

#message                      	{
                                if(testflex)
                                    printf(" [message] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
								return MSG;
								}
#define                       	{
                                if(testflex)
                                    printf(" [define] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
								return DEF;
								}

#undef                       	{
                                if(testflex)
                                    printf(" [undef] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
								return UNDEF;
								}

#ifdef                       	{
                                if(testflex)
                                    printf(" [ifdef] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
								return IFDEF;
								}

#elifdef                       	{
                                if(testflex)
                                    printf(" [elifdef] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
								return ELIFDEF;
								}

#else                       	{
                                if(testflex)
                                    printf(" [else] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
								return ELSE;
								}

#endif                       	{
                                if(testflex)
                                    printf(" [ifdef] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
								return ENDIF;
								}

{FN}{FNN}*            			{
                                if(testflex)
                                    printf(" [ID] '%s'\n", yytext);

                                yylval.strval = strdup(yytext);
								return ID;
								}

[ \t]							{
                                if(testflex)
                                    printf(" [SP] '%s' ", yytext);
                                yylval.strval = strdup(yytext);
								return SP;
								}

\r								{
								// Ignore
								}

\n								{
                                if(testflex)
                                    printf(" [nl] '%d'\n", yytext[0]);

								num_lines++;
                                yylval.strval = strdup(yytext);
								return NL;
								}

\"                              {              /* begin quote */
                                BEGIN(STR2);

                                if(testflex)
                                    printf(" str<<<");

                                prog = 0; backslash  = 0;
							   	tmp_str2[prog++] = yytext[0];
                                }

<STR2>\\                        {
                                if(testflex)
									printf("\\");

								tmp_str2[prog++] = yytext[0];
								backslash++;
								}

<STR2>\"                        {  			/* end quote */
                                if( (backslash % 2) == 0) /* odd backslash */
                                     {
                                     BEGIN(INITIAL);

                                     if(testflex)
                                        printf(">>>str ");

								     tmp_str2[prog++] = yytext[0];
									 tmp_str2[prog] = '\0';
                                	 yylval.strval = strdup(tmp_str2);
                                     return(STR);
                                     }
                                  else
                                  	{  /* add quote */
									tmp_str2[prog++] = yytext[0];
                                  	}
                                }

<STR2>.                         {   // default string charater
                                backslash  = 0;

                                if(testflex)
                                    printf("'%s'", yytext);

								tmp_str2[prog++] = yytext[0];
                                }


.								{  // default character

                                if(testflex)
                                    printf(" [char] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
								return CH;
								}

%%

/* ========================= End of LEX ================================ */

///////////////////////////////////////////////////////////////////////////

int 	preprocess(char *ptr)

{
	int ret_val = 1;
	struct stat buf;

	// re - initialize preprocessor
	num_lines = 1;

	#if 1
	if(stat(ptr, &buf) < 0)
		{
		//printf("Cannot stat file '%s'.\n", ptr);
		//if(debuglevel > 0)
		//	syslog(LOG_DEBUG, "Cannot stat file %s\n", ptr);
		return 0;
		}
	if(S_ISDIR(buf.st_mode))
		{
		//printf("Cannot operate on directory '%s'.\n", ptr);
		if(debuglevel > 0)
			syslog(LOG_DEBUG, "cannot operate on dir %s\n", ptr);
		return 0;
		}
	#endif

	ppfp3 = fopen(ptr, "r");
	if(!ppfp3)
		{
		printf("Cannot open file '%s'.\n", ptr);
		if(debuglevel > 0)
			syslog(LOG_DEBUG, "Cannot open file %s\n", ptr);
		return 0;
		}

	char outdir[MAX_VARLEN];
	strcpy(outdir, ptr);
	char *last2 = strrchr(outdir, '/');
	if (last2 != NULL)
		{
		*last2 = '\0';
		}
	else
		{
		outdir[0] = '.'; outdir[1] = '\0';
		}
	strcat(outdir, "/tmp/");

	//printf("outdir: '%s'\n", outdir);

    #if 1
	if(stat(outdir, &buf) < 0)
		{
		if(mkdir(outdir, 0777) < 0)
			{
			printf("Cannot create tmp dir: '%s'\n", outdir);
			return 0;
			}
		}
    #endif

	char ppfile[MAX_VARLEN];
	strcpy(ppfile, ptr);
	char *last = strrchr(ppfile, '/');
	if (last != NULL)
		{
		strcpy(ppfile, last + 1);
		}

	strcpy(ppfile2, outdir);
	strcat(ppfile2, ppfile);
	char *last3 = strrchr(ppfile2, '.');
	if (last3 != NULL)
		{
		*last3 = '\0';
		strcat(ppfile2, ".pcp");
		//printf("asm2: '%s'\n", ppfile2);
		}

	ppfp2 = fopen(ppfile2, "w");

	if(!ppfp2)
		{
		printf("Cannot create file '%s'.\n", ppfile);
		syslog(LOG_DEBUG, "pcomp: Cannot create asm file.\n");
		return 0;
		}

	int	olderrcnt = errorcount;

	if(!noprog)
		printf ("Pre processing: '%s' ", ptr);

	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
    preparse();
	struct timespec ts2;
	//sleep(2); // test time measurement
	clock_gettime(CLOCK_REALTIME, &ts2);

    fclose(ppfp3);

	int dts, dtu; calc_usec_diff(&ts, &ts2, &dts, &dtu);

	int ret = getretcode();

	if(!noprog)
		{
		if(ret == 0 && (olderrcnt == errorcount))
			printf ("OK %d sec %d usec\n", dts, dtu);
		else
			printf ("Compiled: '%s' ERR %d sec %d usec\n", ptr, dts, dtu);
		}

	fclose(ppfp2);

	if(catpre)
		{
		printf("Displaying pre processed file:\n\n");
		sprintf(tmp_str, "cat %s\n", ppfile2);
		int ret = system(tmp_str);
		printf("\n");
		}

    return ret_val;
}




