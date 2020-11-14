
/* =====[ emalloc.h ]=========================================================


      REV     DATE     	BY             DESCRIPTION
      ----  --------  	 ----------    --------------------------------------
      0.00  dec/23/2013  Peter Glen    Progress.

   ======================================================================= */

char    *emalloc(unsigned nn);
char    *emalloc2(unsigned nn, int line, char *file);
void	efree(void *ptr);
void	efreeall();

int 	print_emalloc();
char 	*estrdup(char *str);
char 	*estrdup2(char *str, int line, char *file);
int 	print_estrdup();



