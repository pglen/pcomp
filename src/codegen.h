///////////////////////////////////////////////////////////////////////////
//
// Code generator interfaces
//

#define U8_MAX 	255
#define U16_MAX 1000
#define U32_MAX 10000

#define S8_MAX 	128
#define S16_MAX 1000
#define S32_MAX 10000

#define S8_MIN 	-127
#define S16_MIN -1000
#define S32_MIN -10000

///////////////////////////////////////////////////////////////////////////
// Externals

extern  int   	testflex;
extern  int   	testyacc;
extern  int	  	showcomm;
extern  int	  	dumpsymtab;
extern  int 	errorcount;
extern  int		debuglevel;
extern  int		noprologue;
extern  int 	catsrc;
extern  int		interlace_sym;
extern  int		noassembly;

int		gen_code();


