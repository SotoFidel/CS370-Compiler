/*
    Header file. The purpose of the header file is to 
    'expose' the methods and variables of a C file to other
    C files. This will be useful in the future for our compiler
*/
#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

#ifndef SYMBTAB
#define SYMBTAB

void Insert();
void Display();
void Delete();
void Modify();

int Search(char label[]);

/*Node for the linked list data structure*/
struct SymbTab
{
    char label[10],symbol[10];
    int addr;
    struct SymbTab *next;
};

#endif
