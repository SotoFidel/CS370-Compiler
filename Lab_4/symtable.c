/*
    Fidel Soto
    February 7, 2020
    An implementation of a symbol table. Objective: understand and/or modify the implementation.

    ********************S Y M T A B L E     I M P L E M E N T A T I O N********************
    This code is an simple implementation of a symbol table. Each entry has information about
    its label, symbol and address. This code was pulled from https://forgetcode.com/C/101-Symbol-table

    February 21, 2020
    Changes:
        *Modified Insert() so that it now takes a string and an int parameter. 
        *Modified Search() and fetchAddress() so that they now take a string parameter.
*/

#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include "symtable.h"

    int size=0;
    struct SymbTab *first,*last;
    
    void Insert(char *symbolParam, int offsetParam)
    {
        struct SymbTab *newEntry;

        newEntry = malloc( sizeof( struct SymbTab ) ); /*Allocate memory of the size in bytes of the SymbTab struct*/

        newEntry->symbol = strdup(symbolParam);
        newEntry->addr = offsetParam;
        newEntry->next=NULL;

        if (size==0) 
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
        /*Display();*/
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
        for(int i=0 ; i<size ; i++)
        {
            if(strcmp(searchCursor->symbol,symbolParam)==0) /*Compare searchCursor->symbol and symbolParam*/
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
        
        //This check is done in the front end Yacc, so if this
        //side can't find it, then something wen't horribly wrong.
        fprintf(stderr, "FATAL ERROR: This Variable was not declared\n");
        exit(1);
    }
    
    
