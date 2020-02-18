/*
    Fidel Soto
    February 7, 2020
    An implementation of a symbol table. Objective: understand and/or modify the implementation.

    ********************S Y M T A B L E     I M P L E M E N T A T I O N********************
    This code is an simple implementation of a symbol table. Each entry has information about
    its label, symbol and address. This code was pulled from https://forgetcode.com/C/101-Symbol-table
*/

#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include "symtable.h"

    int size=0;
    struct SymbTab *first,*last;
//     void main()
//     {
//         int optionInput,searchResult;   /** op = operation  -------  y = search result **/
//         char label[10];
//         do
//         {
//             printf("\n\tSYMBOL TABLE IMPLEMENTATION\n");
//             printf("\n\t1.INSERT\n\t2.DISPLAY\n\t3.DELETE\n\t4.SEARCH\n\t5.MODIFY\n\t6.END\n");
//             printf("\n\tEnter your option : ");
//             scanf("%d",&optionInput); /** Scan an integer and store it into 'op' memory location**/
//             switch(optionInput)
//             {
//                 case 1:
//                     Insert();
//                     break;
//                 case 2:
//                     Display();
//                     break;
//                 case 3:
//                     Delete();
//                     break;
//                 case 4:
//                     printf("\n\tEnter the label to be searched : ");
//                     scanf("%s",label); /**Scan a string and store each character of said string into 'la'**/
//                     searchResult=Search(label);
//                     printf("\n\tSearch Result:");
//                     if(searchResult==1)
//                         printf("\n\tThe label is present in the symbol table\n");
//                     else
//                         printf("\n\tThe label is not present in the symbol table\n");
//                     break;
//                 case 5:
//                     Modify();
//                     break;
//                 case 6:
//                     exit(0);
//             }
//         } while(optionInput<6); /** exit if invalid input **/
//         
//     }  /* and of main */
    
    void Insert(char *symbolParam, int offsetParam)
    {
        struct SymbTab *newEntry;

        newEntry = malloc( sizeof( struct SymbTab ) ); /*Allocate memory of the size in bytes of the SymbTab struct*/

        newEntry->symbol = strdup(symbolParam);
        newEntry->addr = offsetParam;
        newEntry->next=NULL;

        if(size==0) 
        {
            first=newEntry;
            last=newEntry;
        }
        else
        {
            last->next=newEntry;
            last=newEntry;
        }
        size++;
        Display();
    }
    
    void Display()
    {
        struct SymbTab *printCursor;
        printCursor=first;
        printf("\n\tSYMBOL\t\tADDRESS\n");
        for(int i=0;i<size;i++)
        {
            printf("\t%s\t\t%d\n",printCursor->symbol,printCursor->addr);
            printCursor=printCursor->next;
        }
    }
    
    int Search(char *symbolParam)
    {
        int flag=0;
        struct SymbTab *searchCursor;
        searchCursor=first;
        for(int i=0;i<size;i++)
        {
            if(strcmp(searchCursor->symbol,symbolParam)==0) /*Compare p->label and lab[]*/
                flag=1;
            searchCursor=searchCursor->next;
        }
        return flag;
    }
        
    int fetchAddress(char *symbolParam) {
        struct SymbTab *cursor;
        cursor = first;
        while (cursor != NULL) {
            if (strcmp(cursor->symbol, symbolParam) == 0) {
                // fprintf(stderr, "symbol Found!\n");
                return cursor->addr;
            }
            cursor = cursor->next;
        }
        fprintf(stderr, "FATAL ERROR: This Variable was not declared\n");
        exit(1);
    }
    
    
