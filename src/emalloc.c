
/* =====[ emalloc.c ]=========================================================


      REV     DATE     	BY             DESCRIPTION
      ----  --------  	 ----------    --------------------------------------
      0.00  dec/23/2013  Peter Glen    Progress.

   ======================================================================= */

// --------------------------------------------------------------------------
//  EMALLOC -   allocate memory -- exit on error.
//
//  Add an entry to allocated list of buffers for debugging
//

#include "emalloc.h"
#include "malloc.h"
#include "string.h"

#define	EMALLOC_MAGIC 0x32345654

typedef struct meminf {
		int 	magic;
		int	 	line;
		void 	*ptr;
		char 	file[24];
  		struct meminf *next ;
} meminf;

#define MNULL  (meminf*)0
#define CNULL  (char*)0

static	meminf  *emalloc_info = MNULL;
static	meminf  *strdup_info = MNULL;

static	int      emalloc_cnt = 0;
static	int      strdup_cnt = 0;

static	int pop_minfo(meminf **root, void **ptr, int *line, char *file);
static	int push_minfo(meminf **root, void *ptr, int line, char *file);

///////////////////////////////////////////////////////////////////////////
// Allocate and free memory

char    *emalloc2(unsigned nn, int line, char *file)

{
	char *pp = (char*)malloc(nn) ;

   	if (pp == CNULL)
   		execerror("Out of memory while emalloc2", (char *) 0) ;

	push_minfo(&emalloc_info, pp, line, file);

	emalloc_cnt++;

    return pp ;
}

char    *emalloc(unsigned nn)

{
 	char *pp ;

   	pp = (char *)malloc(nn) ;

   	if (pp == CNULL)
   		execerror("Out of memory while emalloc", (char *) 0) ;

	push_minfo(&emalloc_info, pp, __LINE__, __FILE__);

	emalloc_cnt++;

   	return pp ;
}

void	efree(void *ptr)

{
	// Testing
    //printf("efree %p\n", ptr);
    //return;

	int found = 0;
	meminf *sp2, *prev = emalloc_info;

    for(sp2 = emalloc_info; sp2 != MNULL; sp2 = sp2->next)
        {
    	if(sp2->magic != EMALLOC_MAGIC)
    		printf("efree1 sp2->magic != EMALLOC_MAGIC\n");

        if(ptr == sp2->ptr)
        	{
        	//printf("found %p\n", ptr);
			//*((char*)sp2->ptr) = 'x';

			if(sp2 == emalloc_info)
				prev->next = MNULL, free(prev), emalloc_info = NULL;
			else
        		prev->next = sp2->next, free(sp2);

            found = 1;
        	break;
        	}
        prev = sp2;
   		}
	prev = strdup_info;
    for(sp2 = strdup_info; sp2 != MNULL; sp2 = sp2->next)
        {
    	if(sp2->magic != EMALLOC_MAGIC)
    		printf("efree2 sp2->magic != EMALLOC_MAGIC\n");

        if(ptr == sp2->ptr)
        	{
        	//printf("found strdup %p\n", ptr);
			//*((char*)sp2->ptr) = 'x';

			if(sp2 == strdup_info)
				prev->next = MNULL, free(prev), strdup_info = NULL;
			else
        		prev->next = sp2->next,  free(sp2);

            found = 1;
        	break;
        	}
        prev = sp2;
   		}

   	if(found)
		free(ptr);
}

void	efreeall()

{
	void *ptr; int ret;

#if 1
	while(1)
		{
		ret = pop_minfo(&emalloc_info, &ptr, 0, 0);

		if(!ret)
			break;
		}

#endif
	while(1)
		{
		ret = pop_minfo(&strdup_info, &ptr, 0, 0);
		free(ptr);
		if(!ret)
			break;
		}

}

///////////////////////////////////////////////////////////////////////////

int print_emalloc()

{
    meminf *sp2; int loop;

    printf("Printing emalloc data at %p - %d total allocations:\n",
    				 emalloc_info, emalloc_cnt);

    for(sp2 = emalloc_info; sp2 != MNULL; sp2 = sp2->next)
        {
        unsigned char *ptr = (unsigned char*)sp2->ptr;

	    if(sp2->magic != EMALLOC_MAGIC)
    		printf("print_emalloc sp2->magic != EMALLOC_MAGIC\n");

        printf(" %p %12s:%d  '", sp2->ptr, sp2->file, sp2->line);
		for(loop = 0; loop < 16; loop++)
			printf("%02x ", *ptr++);

		printf("'\n");
        }
    return 0;
}

///////////////////////////////////////////////////////////////////////////

int push_minfo(meminf **root, void *ptr, int line, char *file)

{
    meminf *sp = (meminf *) malloc( sizeof(meminf)) ;

    sp->magic = EMALLOC_MAGIC;
    sp->line = line;
    strncpy(sp->file, file, 24);
    sp->ptr = ptr;
    sp->next = MNULL;

    sp->next = *root;
    *root = sp;

	return 1;
}

int pop_minfo(meminf **root, void **ptr, int *line, char *file)

{
	if(*root == MNULL)
        	return;

    if((*root)->magic != EMALLOC_MAGIC)
    	printf("pop_minfo (*root)->magic != EMALLOC_MAGIC\n");

    meminf *last = *root;

	if(line)
  		*line = (*root)->line;

	if(ptr)
    	*ptr = (*root)->ptr;

    if(file)
	    strncpy(file, (*root)->file, 24);

    *root = (*root)->next;

    free(last);

	if(*root)
    	return 1;
    else
    	return 0;
}

///////////////////////////////////////////////////////////////////////////
// Strdup

char *estrdup(char *str)

{
	char *ptr = emalloc2(strlen(str) + 1, __LINE__, __FILE__) ;

	if(ptr == (char*)0)
   		execerror("Out of memory while strdup", (char *) 0) ;

    strcpy(ptr, str);

	return ptr;
}

char *estrdup2(char *str, int line, char *file)

{
	char *ptr = malloc(strlen(str) + 1);

	if(ptr == (char*)0)
   		execerror("Out of memory while in estrdup2", (char *) 0) ;

    strcpy(ptr, str);

	push_minfo(&strdup_info, ptr, line, file);
	strdup_cnt++;

	return ptr;
}

int print_estrdup()

{
    meminf *sp2; int loop;

    printf("Printing  strdup data at %p - %d total allocations:\n",
    				 strdup_info, strdup_cnt);

    for(sp2 = strdup_info; sp2 != MNULL; sp2 = sp2->next)
        {
        char *ptr = (char*)sp2->ptr;

	    if(sp2->magic != EMALLOC_MAGIC)
    		printf("print_estrdup sp2->magic != EMALLOC_MAGIC\n");

        printf(" %p %12s:%d  '", sp2->ptr, sp2->file, sp2->line);
		for(loop = 0; loop < 32; loop++)
			{
			if(*ptr == 0) break;
			printf("%c", *ptr++);
			}
		printf("'\n");
        }
    return 0;
}


