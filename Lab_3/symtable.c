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
    void main()
    {
        int optionInput,searchResult;   /** op = operation  -------  y = search result **/
        char label[10];
        do
        {
            printf("\n\tSYMBOL TABLE IMPLEMENTATION\n");
            printf("\n\t1.INSERT\n\t2.DISPLAY\n\t3.DELETE\n\t4.SEARCH\n\t5.MODIFY\n\t6.END\n");
            printf("\n\tEnter your option : ");
            scanf("%d",&optionInput); /** Scan an integer and store it into 'op' memory location**/
            switch(optionInput)
            {
                case 1:
                    Insert();
                    break;
                case 2:
                    Display();
                    break;
                case 3:
                    Delete();
                    break;
                case 4:
                    printf("\n\tEnter the label to be searched : ");
                    scanf("%s",label); /**Scan a string and store each character of said string into 'la'**/
                    searchResult=Search(label);
                    printf("\n\tSearch Result:");
                    if(searchResult==1)
                        printf("\n\tThe label is present in the symbol table\n");
                    else
                        printf("\n\tThe label is not present in the symbol table\n");
                    break;
                case 5:
                    Modify();
                    break;
                case 6:
                    exit(0);
            }
        }while(optionInput<6); /** exit if invalid input **/
        
    }  /* and of main */
    void Insert()
    {
        int isDuplicate; /** n = search result **/
        char label[10];
        printf("\n\tEnter the label : ");
        scanf("%s",label); /** Scan a string and store its characters into l**/
        isDuplicate=Search(label);
        if(isDuplicate==1)
            printf("\n\tThe label exists already in the symbol table\n\tDuplicate can't be inserted");
        else
        {
            struct SymbTab *newEntry;
            newEntry=malloc(sizeof(struct SymbTab)); /*Allocate memory of the size in bytes of the SymbTab struct*/
            strcpy(newEntry->label,label); /*copy l into p->label*/
            printf("\n\tEnter the symbol : ");
            scanf("%s",newEntry->symbol); /*Scan a string and store its characters into p->symbol*/
            printf("\n\tEnter the address : ");
            scanf("%d",&newEntry->addr); /*scan an integer and store it in the memory address of p-addr*/
            newEntry->next=NULL; /** Initialize p **/
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
        }
        printf("\n\tLabel inserted\n");
    }
    void Display()
    {
        struct SymbTab *printCursor;
        printCursor=first;
        printf("\n\tLABEL\t\tSYMBOL\t\tADDRESS\n");
        for(int i=0;i<size;i++)
        {
            printf("\t%s\t\t%s\t\t%d\n",printCursor->label,printCursor->symbol,printCursor->addr);
            printCursor=printCursor->next;
        }
    }
    int Search(char lab[])
    {
        int flag=0;
        struct SymbTab *searchCursor;
        searchCursor=first;
        for(int i=0;i<size;i++)
        {
            if(strcmp(searchCursor->label,lab)==0) /*Compare p->label and lab[]*/
                flag=1;
            searchCursor=searchCursor->next;
        }
        return flag;
    }
    void Modify()
    {
        char label[10],newLabel[10]; /*l = old label ------ nl = new label */
        int add,choice,searchResult;
        struct SymbTab *modCursor;
        modCursor=first;
        printf("\n\tWhat do you want to modify?\n");
        printf("\n\t1.Only the label\n\t2.Only the address\n\t3.Both the label and address\n");
        printf("\tEnter your choice : ");
        scanf("%d",&choice); /*Scan an integer and store it into 'choice' memory address*/
        switch(choice)
        {
            case 1:
                printf("\n\tEnter the old label : ");
                scanf("%s",label);
                searchResult=Search(label);
                if(searchResult==0)
                    printf("\n\tLabel not found\n");
                else
                {
                    printf("\n\tEnter the new label : ");
                    scanf("%s",newLabel);
                    for(int i=0;i<size;i++)
                    {
                        if(strcmp(modCursor->label,label)==0)
                            strcpy(modCursor->label,newLabel);
                        modCursor=modCursor->next;
                    }
                    printf("\n\tAfter Modification:\n");
                    Display();
                }
                break;
            case 2:
                printf("\n\tEnter the label where the address is to be modified : ");
                scanf("%s",label);
                searchResult=Search(label);
                if(searchResult==0)
                    printf("\n\tLabel not found\n");
                else
                {
                    printf("\n\tEnter the new address : ");
                    scanf("%d",&add);
                    for(int i=0;i<size;i++)
                    {
                        if(strcmp(modCursor->label,label)==0)
                            modCursor->addr=add;
                        modCursor=modCursor->next;
                    }
                    printf("\n\tAfter Modification:\n");
                    Display();
                }
                break;
            case 3:
                printf("\n\tEnter the old label : ");
                scanf("%s",label);
                searchResult=Search(label);
                if(searchResult==0)
                    printf("\n\tLabel not found\n");
                else
                {
                    printf("\n\tEnter the new label : ");
                    scanf("%s",newLabel);
                    printf("\n\tEnter the new address : ");
                    scanf("%d",&add);
                    for(int i=0;i<size;i++)
                    {
                        if(strcmp(modCursor->label,label)==0)
                        {
                            strcpy(modCursor->label,newLabel);
                            modCursor->addr=add;
                        }
                        modCursor=modCursor->next;
                    }
                    printf("\n\tAfter Modification:\n");
                    Display();
                }
                break;
        }
    }
    void Delete()
    {
        int searchResult;
        char label[10]; /** l = label **/
        struct SymbTab *p,*q; 
        p=first;
        printf("\n\tEnter the label to be deleted : ");
        scanf("%s",label);
        searchResult=Search(label);
        if(searchResult==0)
            printf("\n\tLabel not found\n");
        else
        {
            if(strcmp(first->label,label)==0) /*Delete first node case*/
                first=first->next;
            else if(strcmp(last->label,label)==0) /* Delete last node case */
            {
                q=p->next; 
                while(strcmp(q->label,label)!=0)
                {
                    p=p->next;
                    q=q->next;
                }
                p->next=NULL;
                last=p;
            }
            else
            {
                q=p->next; /*delete Anything in between case */
                while(strcmp(q->label,label)!=0) /*Find the node based on the label*/
                {
                    p=p->next;
                    q=q->next;
                }
                p->next=q->next;
            }
            size--;
            printf("\n\tAfter Deletion:\n");
            Display();
        }
    }
    
    
