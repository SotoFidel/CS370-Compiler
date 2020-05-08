/*  Symbol Table --linked list
    Used for Compilers class

    Modified Spring 2015 to allow for name to pointed to by symtable, instead of copied, since the name is copied
    into the heap

    Modified to have levels.  A level 0 means global variable, other levels means in range of the function.  We
    start out our offsets at 0 (from stack pointer) for level 1,,,when we enter a functional declaration.
    We increment offset each time we insert a new variable.  A variable is considered to be valid if it is found in
    the symbol table at our level or lesser level.  If at 0, then it is global.  

    We return a pointer to the symbol table when a variable matches our creteria.

    We add a routine to remove variables at our level and above.

    **Edited by: Fidel Soto
    Date: April 13, 2020
   EDITED DISPLAY FUNCTION
      *Added more information to be printed in the symbol table display function.
       Added a switch statement that will print out a word represenation of 
       IsAFunc and Type.

   Datee: May 6, 2020
      *Edited documentation to match precondition and postcondition documentation requiremments
*/

    
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "symtable.h"

struct SymbTab * first = NULL;
int GTEMP = 0;


/*
   PRECONDITION: The function takes information abou thte symbol (its  name, data type, isafunc, level, size, offset, and formal parameters)
   POSTCONDITION: The function will insert the symbol with said information into the symbol table.
*/
struct SymbTab * Insert(char *name, enum DATATYPE Type, int isafunc, int  level, int mysize, int offset , ASTNode * fparms)
{
  struct SymbTab * n;
    n=Search(name,level, 0);
    if(n!=NULL)
      {
         printf("\n\tThe name %s exists at level %d already in the symbol table\n\tDuplicate can.t be inserted",name, level);
         return (NULL);
      }
    else
    {
      struct SymbTab *p;
      p=malloc(sizeof(struct SymbTab));
      p->name=name;
      p->offset=offset;  /* assign the offset */
      p->level=level;  /* assign the level */
      p->mysize=mysize;  /* assign the size */
      p->Type=Type;  /* assign the Type */
      p->IsAFunc=isafunc;  /* assign the Function  */
      p->fparms=fparms;  /* assign the Function  */
      p->next=NULL;

   /* Check on how many elements we have in the symbol table */
      if(first==NULL)
      {
        first=p;
      }
      else
      {
        p->next=first;
        first=p;
      }
      return (p);
 
    }
  
}//end of Insert


/*
   PRECONDITION: the function gets called by the Y file
   POSTCONDITION: The function will return a temp label for an expression
*/
char * CreateTemp()
{ 
char hold[100];
char *s;
sprintf(hold,"_t%d",GTEMP++);
s=strdup(hold);
return (s);

} //End of CreateTemp

/* 
   PRECONDITION: The function takes a symbol table pointer to a symbol
   POSTCONDITION: Print out a single symbol table entry with as much info as possible -- for debugging */
void PrintSym(struct SymbTab *s)
{
         printf("%-10s\t%-10d\t%-10d\t%-10d",s->name, s->offset, s->level,s->mysize);


         //Both of the switch statements are to print strings rather than enum values
         switch(s->Type){
           case intType:
              printf("\t%-10s","INT");
           break;
           case boolType:
               printf("\t\tBOOL");
           break;
           case voidType: 
               printf("\t\tVOID");
           break;
           default:
              printf("\t\thow");
           break;
         }

         switch(s->IsAFunc) {
           case 0:
              printf("\t%-10s","SCALAR");
           break;
           case 1:
              printf("\t%-10s","FUNCTION");
           break;
           case 2:
              printf("\t%-10s","ARRAY");
            break;
            default:
            printf("\t\thowwww");
            break;
         }

         printf("\n");

} // end of PrintSym


/*  General display to see what is our symbol table. Calls PrintSym */
void Display()
{
   int i;
   struct SymbTab *p;
   p=first;
   printf("\n%-10s\t%-10s\t%-10s\t%-10s\t%-10s\t%-10s\n", "LABEL", "OFFSET", "LEVEL", "SIZE", "TYPE", "ISAFUNC");
   //printf("\n\tLABEL\t\tSize\t\tOffset\t\tLEVEL\t\tType\t\tIsAFunc\n");
      while (p!=NULL)
      {
         PrintSym(p);
         p=p->next;
      }
} // end of Display



/* 

   PRECONDITION: Takes the symbol name to be searched, which level to search it at, and whether the search should be recursive or not.
   
   POSTCONDITION:
   Search for a symbol name at level or below.  We have to do multiple passes into the symbol table because we have to find
   the name closest to us 
  If recur is non-zero, then we look through all of the levels, otherwise, only our level 
   We return a pointer to a SymbolTab structure so that we can use other functions/methods to get the attributes */
struct SymbTab * Search(char name[], int level, int recur)
{
   int i,flag=0;
   struct SymbTab *p;

  /* for each level, try to find our symbol */
   while (level >= 0)
    {
       p=first;
       while (p!=NULL)
        {
         if((strcmp(p->name,name)==0) && (p->level == level))
           return p;
         p=p->next;
        }
       if (recur == 0) return (NULL);   /* we did not find it at our level */
       level--; /* check the next level up */
    }


   return  NULL;  /* did not find it, return 0 */
} // end of Search



/* 
   PRECONDITION: The function takes the level at which to delete all the entries.
   POSTCONDITION: Remove all enteries that have the indicated level
   We need to take care about updating first pointer into the linked list when we are deleting edge elements */
int Delete(int level)
{
    struct SymbTab *p,*f=NULL;  /* we follow with pointer f */
    int SIZE=0;
    p=first;

    
    
  /* cruise through the list */

    while (p != NULL)
      {
        /* do we match? */
        if (p->level>= level )
        { /* if it is the first in the list we have to update first, we know this by f being NULL */
           SIZE+=p->mysize;
           if ( f==NULL) first=p->next;
           else /* not the first element */
              {f->next=p->next;
              }
            p=p->next;
           
        }
        else
         {
               /* update follow pointer, move the p pointer */
                f=p;
                p=p->next;
          }

      }
    return(SIZE);
} // end of Delete
