/*
 * Array of pointers.
 * First entry is number of current allocated pointers,
 * second entry next available index.
 *
 * Note:
 *     
 *  The first two array entries are used as integers. (nty noty)
 *
 * Input: pointer to root list, pointer to string to add
 *
 * Reading the list:
 *
 *  for(loop = 0; loop < (int)list[1]; loop++)
 *     {
 *     item =  list[loop+2]);
 *     }
 */

char **ulist = 0;
char **clist = 0;
char **dlist = 0;
char **flist = 0;
char **xdlist = 0;

//int add_array(char ***ulist,  char *ptr);
//int add_ptr  (char ***list, char *ptr);
//int init_array(char ***list);


int add_array(char ***list, char *ptr)

{
  char *tmp;

      /* init list: */
    if (*list == 0)
        {
        //printf ("add_array(newlist)\n"); fflush(stdout);
        tmp = malloc((MAX_ARRAY + 2) * sizeof(char *));
        if(!tmp) printf("Out of memory.\n"), exit(0);

        *list = (char**)tmp;
        (*list)[0] = (char*)MAX_ARRAY;  /* limit */
        (*list)[1] = (char*)0;          /* index */
        }

    //printf ("add_array(list) len = %d idx = %d str= %s\n", (int)(*list)[0], (int)(*list)[1], ptr);

      /*  expand the list if needed */
     if((*list)[1] >= (*list)[0])
        {
        tmp = malloc( ((int)(*list)[0] + MAX_ARRAY + 2) * sizeof(char *));
        if(!tmp) printf("Out of memory.\n"), exit(0);

      //  printf ("add_array(expandlist)\n"); fflush(stdout);

        memcpy(tmp, *list, ((int)(*list)[1] + 2) * sizeof(char*));

        if(*list) free(*list);
        *list = (char **)tmp;
        (*list)[0] += MAX_ARRAY;
        }
    //printf ("add_array(assignlist)\n"); fflush(stdout);

     (*list)[(int)(*list)[1] + 2] = ptr;
     (*list)[1]++;
}

int free_array(char ***list)

{
  //printf("Free array \n"); fflush(stdout);

  if(*list)
    {
    free(*list);
    *list = 0;
    }
}

int init_array(char ***list)

{
    char *tmp;

    tmp = malloc((MAX_ARRAY + 2) * sizeof(char *));
    if(!tmp) printf("Out of memory.\n"), exit(0);

    *list = (char**)tmp;
    (*list)[0] = (char*)MAX_ARRAY;  /* limit */
    (*list)[1] = (char*)0;          /* index */
}

