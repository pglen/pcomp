
/* =====[ pcomp.h ]=========================================================


      REV     DATE     	    BY             DESCRIPTION
      ----  --------  	     ----------    --------------------------------------
      0.00  Sun 15.Nov.2020  Peter Glen    Initial

   ======================================================================= */

extern int   	testflex ;
extern int   	testyacc ;
extern int	  	showcomm ;
extern int	  	dumpsymtab ;
extern int 	errorcount ;
extern int		debuglevel ;
extern int		noprologue ;
extern int 	catsrc ;
extern int 	catpre ;
extern int		interlace_sym ;
extern int		noassembly ;
extern int		nolink ;
extern int		showallocbuff ;
extern int		noprog ;
extern int		nocompile ;
extern int		verbose ;
extern int		nopre ;

extern char ppfile2[];

void	calc_usec_diff(struct timespec *ts, struct timespec *ts2, int *pdts, int *pdtu);

// EOF




