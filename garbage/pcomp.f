%{

/* This lexer and parser assumes that int is same size as pointer */

#include "symtab.h"
#include "emalloc.h"

// Flags for operation. Some referenced in other files.

int   	testflex = 0;
int   	testyacc = 0;
int	  	showcomm = 0;
int	  	dumpsymtab = 0;
int 	errorcount = 0;
int		debuglevel = 0;
int		noprologue = 0;
int 	catsrc = 0;
int 	catpre = 0;
int		interlace_sym = 0;
int		noassembly = 0;
int		showallocbuff = 0;
int		noprog = 0;
int		nocompile = 0;
int		nopre = 0;

static	char tmp_str2[1024];

extern char ppfile2[];

void	calc_usec_diff(struct timespec *ts, struct timespec *ts2, int *pdts, int *pdtu);

FILE *infp, *asmfp, *ppfp;

int num_lines = 1, num_chars = 0, backslash = 0, prog = 0;

#define YY_INPUT(buf,result,max_size) \
               { \
               int c = getc(infp); \
               result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
               }
void conferror(const char *str)
{
 static int count = 0;
       printf("%s  Line: %d  Near '%s'\n", str, num_lines, yytext); count++;
       if(count > 5) exit(0);
}

#define DEBUGLEX

#include "pcomp.tab.c"

%}


%x STR2
%option noyywrap

FN   [\~_a-zA-Z]
FNN  [\~_a-zA-Z0-9]

%%

\/\/\/\/.*\n                       { /* comment */
								num_lines++;
	#ifdef DEBUGLEX
                                if(testflex)
                                    printf("[double slash comment] '%s", yytext);
	#endif
                                yylval.strval = strdup(yytext);
								return COMMENT2;
								}

\/\/\/.*\n                       { /* comment */
								num_lines++;
	#ifdef DEBUGLEX
                                if(testflex)
                                    printf("[slash comment2] '%s", yytext);
	#endif
                                yylval.strval = strdup(yytext);
								return COMMENT2;
								}



\/\/.*\n                       { /* comment */
								num_lines++;
	#ifdef DEBUGLEX
                                if(testflex)
                                    printf("[slash comment] '%s", yytext);
	#endif
                                yylval.strval = strdup(yytext);
								return COMMENT;
								}

##.*\n                           {  /* double comment */
								num_lines++;
	#ifdef DEBUGLEX
                                if(testflex)
                                    printf("[double comment] '%s", yytext);
	#endif
                                yylval.strval = strdup(yytext);
								return COMMENT2;
								}

#.*\n                           {  /* comment */
								num_lines++;
	#ifdef DEBUGLEX
                                if(testflex)
                                    printf("[comment] '%s", yytext);
	#endif
                                yylval.strval = strdup(yytext);
								return COMMENT;
								}

^\r\n                             /* empty line */ {
								if(testflex)
                                    printf("[empty line]\r\n");
								num_lines++;
								}

^\r                             /* empty line */ {
								if(testflex)
                                    printf("[empty line \\r]\r\n");
								num_lines++;
								}

^\n                             /* empty line */ {
								if(testflex)
                                    printf("[empty line \\n]\r\n");
								num_lines++;
								}


	/* commands: ------------------------------------------------------- */

  /*
\<class\>                           {
	#ifdef DEBUGLEX
                                if(testflex)
                                    printf("<CLASS> ");
	#endif
                                yylval.strval = strdup(yytext);
                                return(CLASS);
                                }
\<ssalc\>                           {
	#ifdef DEBUGLEX
                                if(testflex)
                                    printf("<SSALC> ");
	#endif
                                yylval.strval = strdup(yytext); return(SSALC);
                                }
    /* ----------------------------------------------------------------- */
\<dir\>                            {
	#ifdef DEBUGLEX
                                if(testflex)
	                                printf("<DIR> ");
	#endif
                                yylval.strval = strdup(yytext); return(DIR);
                                }
\<rid\>                         {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<RID> ");
	#endif
                                yylval.strval = strdup(yytext); return(RID);
                                }

function                        {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("[Function] ");
	#endif
                                yylval.strval = strdup(yytext); return(FUNC);
                                }

begin                          {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("lex: begin ");
	#endif

                                yylval.strval = strdup(yytext); return(BEG);
                                }

end                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("lex: end ");
	#endif

                                yylval.strval = strdup(yytext); return(END);
                                }

    /* ----------------------------------------------------------------- */

debug                          {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<DBG> ");
	#endif
                                yylval.strval = strdup(yytext); return(DBG);
                                }

return                         {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("[RET] ");
	#endif
                                yylval.strval = strdup(yytext); return(RET);
                                }

\|\|                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<OR> ");
	#endif
                                yylval.strval = strdup(yytext); return(OR);
                                }

\!\!                            {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<LNOT> ");
	#endif
                                yylval.strval = strdup(yytext); return(LNOT);
                                }

\&\&                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<AND> ");
	#endif
                                yylval.strval = strdup(yytext); return(AND);
                                }

\=\=                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<EQEQ> ");
	#endif
                                yylval.strval = strdup(yytext); return(EQEQ);
                                }

!\=                            {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<NEQ> ");
	#endif
                                yylval.strval = strdup(yytext); return(NEQ);
                                }

\^\^                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<XOR> ");
	#endif
                                yylval.strval = strdup(yytext); return(XOR);
                                }

\>\=                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<GEQ> ");
	#endif
                                yylval.strval = strdup(yytext); return(GEQ);
                                }


\<\=                            {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<SEQ> ");
	#endif
                                yylval.strval = strdup(yytext); return(SEQ);
                                }


\<\<\<                          {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<ROL> ");
	#endif
                                yylval.strval = strdup(yytext); return(ROL);
                                }

\>\>\>                          {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<ROR> ");
	#endif
                                yylval.strval = strdup(yytext); return(ROR);
                                }


if                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<IF> ");
	#endif
                                yylval.strval = strdup(yytext); return(IF);
                                }

else                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<ELSE> ");
	#endif
                                yylval.strval = strdup(yytext); return(ELSE);
                                }

log                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<LOG> ");
	#endif
                                yylval.strval = strdup(yytext); return(LOG);
                                }
0y[0-1]+                        {
	#ifdef DEBUGLEX
                                if(testflex)
                                	printf("[NUM] '%s' ", yytext);
	#endif
                                return(NUM);
                                }
0x[0-9a-fA-f]+                  {            /* hexadecimal */
	#ifdef DEBUGLEX
                                if(testflex)
                                	printf("[ID] '%s' ", (char*)yytext);
	#endif
                                yylval.strval = strdup(yytext); return(ID);
                                }
[0-9]+                          {
	#ifdef DEBUGLEX
                                if(testflex)
 	                               printf("[NUM] '%s' ", (char*)yytext);
	#endif
                                yylval.strval = strdup(yytext); return(NUM);
                                }
{FN}{FNN}*                      {             /* Identity */
	#ifdef DEBUGLEX
                                if(testflex)
                                	printf("[ID] '%s' ", (char*)yytext);
	#endif
                                yylval.strval = strdup(yytext); return(ID);
                                }

[ \t\r\n]+                        {          /* white space */
	#ifdef DEBUGLEX
                                if(testflex)
                                	printf("[SP] '%d' len=%d ",
													yytext[0], strlen(yytext));
	#endif
                                yylval.strval = strdup(yytext);

								if(yytext[0] == '\r')
									num_lines++;

								//return(SP);
                                }

\"                              {              /* begin quote */
                                BEGIN(STR2);
	#ifdef DEBUGLEX
                                if(testflex)
                                    printf(" str<<<");
	#endif
                                prog = 0; backslash  = 0;
							   	tmp_str2[prog++] = yytext[0];

                                backslash  = 0;
                                }

.                               {
                                if(testflex)
                                    printf("[CHAR] '%c' ", yytext[0]);

                                return(yytext[0]);
                                }

<STR2>\\                        {
								//printf("\\");
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

<STR2>.                         {
                                backslash  = 0;

                                if(testflex)
                                    printf("%s", yytext);

								tmp_str2[prog++] = yytext[0];
                                }

%%

/* ========================= End of LEX ================================ */

#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <getopt.h>

#include "codegen.h"

int     main (int argc, char **argv)

{
   	int cc, digit_optind = 0, loop, loop2;

    // Parse command line
   	while (1) {
       int this_option_optind = optind ? optind : 1;
       int option_index = 0;
       static struct option long_options[] = {
           {"add", 1, 0, 0},
           {"append", 0, 0, 0},
           {"delete", 1, 0, 0},
           {"verbose", 0, 0, 0},
           {"create", 1, 0, 'c'},
           {"file", 1, 0, 0},
           {0, 0, 0, 0}
       	};

    	cc = getopt_long (argc, argv, "abcd:012fmnpiorsty",
                        long_options, &option_index);

               if (cc == -1)
                   break;

               switch (cc) {
               case 0:
                   printf ("long option %s", long_options[option_index].name);
                   if (optarg)
                       printf (" with arg %s", optarg);
                   printf ("\n");
                   break;

               case '0': case '1': case '2':
                   if (digit_optind != 0 && digit_optind != this_option_optind)
                     printf ("digits occur in two different argv-elements.\n");
                   digit_optind = this_option_optind;
                   printf ("digits option %c\n", cc);

                case 'a':
                   //printf ("option a\n");
                   noassembly = 1;
                   break;

               case 'b':
                   //printf ("option b\n");
                   showallocbuff = 1;
                   break;

               case 'c':
                   //printf ("option c\n");
                   catsrc = 1;
                   break;

               case 'd':
                   //printf ("option d with value '%s'\n", optarg);
                   debuglevel = atoi(optarg);
                   break;

               case 'f':
                   //printf ("Debug FLEX option is on\n");
                   testflex = 1;
                   break;

               case 'i':
                   //printf ("option i\n");
                   interlace_sym = 1;
                   break;

               case 'm':
                   //printf ("option m\n");
					showcomm = 1;
                   	break;

               case 'n':
                   //printf ("option m\n");
					noprog = 1;
                   	break;

               case 'o':
                   //printf ("option c\n");
                   catpre = 1;
                   break;

               case 'p':
                   //printf ("option b\n");
                   noprologue = 1;
                   break;

               case 'r':
                   //printf ("option r\n");
                   nopre = 1;
                   break;

               case 's':
                   //printf ("Showing symtab\n");
                   dumpsymtab = 1;
                   break;

               case 't':
                   //printf ("Do not compile\n");
                   nocompile = 1;
                   break;

               case 'y':
                   //printf ("Debug YACC option is on\n");
                   testyacc = 1;
                   break;

               case '?':
                   break;

               default:
                   printf ("?? getopt returned character code 0%o ??\n", cc);
               }
            }

            if (optind < argc)
                {
				struct timespec ts;
				clock_gettime(CLOCK_REALTIME, &ts);

                //printf ("non-option ARGV-elements: ");
                while (optind < argc)
                    {
                    // Preprocess and compile
					num_lines = 1; empty_symtab();

					if(nopre == 0)
						preprocess(argv[optind]);
					else
						strcpy(ppfile2, argv[optind]);

					if(nocompile == 0)
	                	compile(argv[optind]);

                    optind++;
                    }
                //printf ("\n");

				//dump_symtab();

				struct timespec ts2;
				clock_gettime(CLOCK_REALTIME, &ts2);

				int dts, dtu; calc_usec_diff(&ts, &ts2, &dts, &dtu);
				if(!noprog)
            	 	printf("Total %d sec %d usec\n", dts, dtu);
                }
             else
                {
                printf("Usage: pcomp [options] filename(s)\n");
                printf("       -a no assembly phase\n");
                printf("       -b show alloc buffers\n");
                printf("       -c cat assembly\n");
                printf("       -d debug level\n");
                printf("       -i interlace symtab in output\n");
                printf("       -l show lex output\n");
                printf("       -m show comments in source\n");
                printf("       -n do not show progress\n");
                printf("       -o cat preprocessing\n");
                printf("       -p no prologue for assembly\n");
                printf("       -r no pre processing\n");
                printf("       -s show symtab\n");
                printf("       -t do not compile\n");
                printf("       -y show yacc output\n");

        		exit(0);
                }

	//print_emalloc();
	//print_estrdup();

	//empty_symtab();
	//efreeall();

	if(showallocbuff)
		{
		print_emalloc();
		print_estrdup();
		}

	exit(errorcount);
}

///////////////////////////////////////////////////////////////////////////
//

int compile(char *ptr)

{
	int ret_val = 1;
	struct stat buf;

	// re - initialize compiler

	#if 1
	if(stat(ptr, &buf) < 0)
		{
		printf("Cannot stat file '%s'.\n", ptr);
		if(debuglevel > 0)
			syslog(LOG_DEBUG, "Cannot stat file %s\n", ptr);
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

	infp = fopen(ppfile2, "r");
	if(!infp)
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

	//strcat(outdir, "/tmp/");
	strcat(outdir, "/");

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

	char asmfile[MAX_VARLEN];
	strcpy(asmfile, ptr);
	char *last = strrchr(asmfile, '/');
	if (last != NULL)
		{
		strcpy(asmfile, last + 1);
		}
	char asmfile2[MAX_VARLEN];
	strcpy(asmfile2, outdir);
	strcat(asmfile2, asmfile);
	char *last3 = strrchr(asmfile2, '.');
	if (last3 != NULL)
		{
		*last3 = '\0';
		strcat(asmfile2, ".asm");
		//printf("asm2: '%s'\n", asmfile2);
		}

	asmfp = fopen(asmfile2, "w");

	if(!asmfp)
		{
		printf("Cannot create file '%s'.\n", asmfile);
		syslog(LOG_DEBUG, "pcomp: Cannot create asm file.\n");
		return 0;
		}

	int	olderrcnt = errorcount;

	if(!noprog)
		printf ("Compiling: '%s' ", ptr);

	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
    confparse();
	struct timespec ts2;
	//sleep(2); // test time measurement
	clock_gettime(CLOCK_REALTIME, &ts2);

    fclose(infp);

	int dts, dtu; calc_usec_diff(&ts, &ts2, &dts, &dtu);

	int ret = getretcode();

	if(!noprog)
		{
		if(ret == 0 && (olderrcnt == errorcount))
			printf ("OK %d sec %d usec\n", dts, dtu);
		else
			printf ("Compiled: '%s' ERR %d sec %d usec\n", ptr, dts, dtu);
		}

	errorcount += ret;

	if(!showcomm)
		{
		//printf("\n");
		if(dumpsymtab)
			{
			dump_symtab();
			//printf("\n");
			}
		gen_code();
		//printf("\n");
		}

	fclose(asmfp);

	if(!noassembly)
		{
		sprintf(tmp_str, "fasm %s > /dev/null\n", asmfile2);
		//printf("Assembly %s\n", tmp_str);
		int ret = system(tmp_str);
		if(ret != 0)
			{
			printf("Assembly failed.\n\n");
			ret_val = 0;
			}
		}

	if(catsrc)
		{
		printf("Displaying source file:\n\n");
		sprintf(tmp_str, "cat %s\n", asmfile2);
		int ret = system(tmp_str);
		}

    return ret_val;
}


///////////////////////////////////////////////////////////////////////////
//

void	calc_usec_diff(struct timespec *ts, struct timespec *ts2, int *pdts, int *pdtu)

{
	#define CALC_NANO  1000000000
	#define CALC_MICRO 1000000

	// Wrapping nanoseconds
	// --------^------^-----|---------------------|---------------------
	// --------^------------|-----^---------------|----------------------
	// --------^------------|---------------------|-----^----------------
    //            NANO - nsec                       nsec2

	int	dtn, dts = ts2->tv_sec - ts->tv_sec;
	if(dts == 0)    // same sec
		dtn = (ts2->tv_nsec - ts->tv_nsec) / 1000;
	else           // jump sec
		dtn = (ts2->tv_nsec + (CALC_NANO - ts->tv_nsec)) / 1000, dts--;

	if(dtn > CALC_MICRO)	// over a sec
		dtn -= CALC_MICRO, dts++;

	*pdts = dts;
	*pdtu = dtn;

	#undef CALC_NANO 	// Make sure define stays local
	#undef CALC_MICRO
}

