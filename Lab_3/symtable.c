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
        int op,y;   /** op = operation  -------  y = search result **/
        char la[10];
        do
        {
            printf("\n\tSYMBOL TABLE IMPLEMENTATION\n");
            printf("\n\t1.INSERT\n\t2.DISPLAY\n\t3.DELETE\n\t4.SEARCH\n\t5.MODIFY\n\t6.END\n");
            printf("\n\tEnter your option : ");
            scanf("%d",&op); /** Scan an integer and store it into 'op' memory location**/
            switch(op)
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
                    scanf("%s",la); /**Scan a string and store each character of said string into 'la'**/
                    y=Search(la);
                    printf("\n\tSearch Result:");
                    if(y==1)
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
        }while(op<6); /** exit if invalid input **/
        
    }  /* and of main */
    void Insert()
    {
        int n; /** n = search result **/
        char l[10];
        printf("\n\tEnter the label : ");
        scanf("%s",l); /** Scan a string and store its characters into l**/
        n=Search(l);
        if(n==1)
            printf("\n\tThe label exists already in the symbol table\n\tDuplicate can't be inserted");
        else
        {
            struct SymbTab *p;
            p=malloc(sizeof(struct SymbTab)); /*Allocate memory of the size in bytes of the SymbTab struct*/
            strcpy(p->label,l); /*copy l into p->label*/
            printf("\n\tEnter the symbol : ");
            scanf("%s",p->symbol); /*Scan a string and store its characters into p->symbol*/
            printf("\n\tEnter the address : ");
            scanf("%d",&p->addr); /*scan an integer and store it in the memory address of p-addr*/
            p->next=NULL; /** Initialize p **/
            if(size==0)
            {
                first=p;
                last=p;
            }
            else
            {
                last->next=p;
                last=p;
            }
            size++;
        }
        printf("\n\tLabel inserted\n");
    }
    void Display()
    {
        int i;
        struct SymbTab *p;
        p=first;
        printf("\n\tLABEL\t\tSYMBOL\t\tADDRESS\n");
        for(i=0;i<size;i++)
        {
            printf("\t%s\t\t%s\t\t%d\n",p->label,p->symbol,p->addr);
            p=p->next;
        }
    }
    int Search(char lab[])
    {
        int i,flag=0;
        struct SymbTab *p;
        p=first;
        for(i=0;i<size;i++)
        {
            if(strcmp(p->label,lab)==0) /*Compare p->label and lab[]*/
                flag=1;
            p=p->next;
        }
        return flag;
    }
    void Modify()
    {
        char l[10],nl[10]; /*l = old label ------ nl = new label */
        int add,choice,i,s;
        struct SymbTab *p;
        p=first;
        printf("\n\tWhat do you want to modify?\n");
        printf("\n\t1.Only the label\n\t2.Only the address\n\t3.Both the label and address\n");
        printf("\tEnter your choice : ");
        scanf("%d",&choice); /*Scan an integer and store it into 'choice' memory address*/
        switch(choice)
        {
            case 1:
                printf("\n\tEnter the old label : ");
                scanf("%s",l);
                s=Search(l);
                if(s==0)
                    printf("\n\tLabel not found\n");
                else
                {
                    printf("\n\tEnter the new label : ");
                    scanf("%s",nl);
                    for(i=0;i<size;i++)
                    {
                        if(strcmp(p->label,l)==0)
                            strcpy(p->label,nl);
                        p=p->next;
                    }
                    printf("\n\tAfter Modification:\n");
                    Display();
                }
                break;
            case 2:
                printf("\n\tEnter the label where the address is to be modified : ");
                scanf("%s",l);
                s=Search(l);
                if(s==0)
                    printf("\n\tLabel not found\n");
                else
                {
                    printf("\n\tEnter the new address : ");
                    scanf("%d",&add);
                    for(i=0;i<size;i++)
                    {
                        if(strcmp(p->label,l)==0)
                            p->addr=add;
                        p=p->next;
                    }
                    printf("\n\tAfter Modification:\n");
                    Display();
                }
                break;
            case 3:
                printf("\n\tEnter the old label : ");
                scanf("%s",l);
                s=Search(l);
                if(s==0)
                    printf("\n\tLabel not found\n");
                else
                {
                    printf("\n\tEnter the new label : ");
                    scanf("%s",nl);
                    printf("\n\tEnter the new address : ");
                    scanf("%d",&add);
                    for(i=0;i<size;i++)
                    {
                        if(strcmp(p->label,l)==0)
                        {
                            strcpy(p->label,nl);
                            p->addr=add;
                        }
                        p=p->next;
                    }
                    printf("\n\tAfter Modification:\n");
                    Display();
                }
                break;
        }
    }
    void Delete()
    {
        int a;
        char l[10]; /** l = label **/
        struct SymbTab *p,*q; 
        p=first;
        printf("\n\tEnter the label to be deleted : ");
        scanf("%s",l);
        a=Search(l);
        if(a==0)
            printf("\n\tLabel not found\n");
        else
        {
            if(strcmp(first->label,l)==0) /*Delete first node case*/
                first=first->next;
            else if(strcmp(last->label,l)==0) /* Delete last node case */
            {
                q=p->next; 
                while(strcmp(q->label,l)!=0)
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
                while(strcmp(q->label,l)!=0) /*Find the node based on the label*/
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
    
    
