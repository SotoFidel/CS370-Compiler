#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

#ifndef SYMBTAB
#define SYMBTAB

void Insert(char *symbolParam, int offsetParam);
void Display();
void Delete();
void Modify();
int fetchAddress(char *symbolParam);
int Search(char *symbolParam);

struct SymbTab
{
    char *symbol;
    int addr;
    struct SymbTab *next;
};

#endif
