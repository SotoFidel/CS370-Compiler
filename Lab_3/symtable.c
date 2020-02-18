/*
    Fidel Soto
    February 7, 2020
    An implementation of a symbol table. Objective: understand and/or modify the implementation.

    1)
    ********************S Y M T A B L E     I M P L E M E N T A T I O N********************
        This code is an simple implementation of a symbol table. Each entry has information about
        its label, symbol and address. This code was pulled from https://forgetcode.com/C/101-Symbol-table
    
    **Changes**
        *Made various variable name changes around the program so that their names are much more representative
            of their functions. (For example, 'int n' which was used to store the result of the Search function
            to see if a label was a duplicate or not will now be named 'isDuplicate').
        *Added documentative comments for each function, as well as some inline comments for some parts of these functions.
    2)
    (Screenshot in pdf)

    3)
    **Data Structure**
        The main data structure this symbol table implementation uses is a LINKED LIST. The fields of each node of the list
        is as follows:
        char label[10] ---- The label of the entry in the table
        char symbol[10] ---- The symbol of the new entry in the table.
        int addr ---- The address (in "memory") of the entry in the table.
        structy Symtab *next ---- A pointer (link) to the next node in the linked list.
    
    4)
        malloc() is a function that allocates memory for an object by returning a pointer to the allocated
        memory location. It's comparable the 'new' keyword in Java. We use malloc in order to allocate memory 
        space for a new object, which will act as the memory address for *next.
*/

#include<stdio.h>
/* #include<conio.h> */
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
#include "symtable.h"

    // Global Variables
    int size=0;
    struct SymbTab *first,*last;

    /*
        main() Function.
        Acts as the menu of the whole program. Asks the user for input
        to see what they want to do with the symbol table.
    */
    void main()
    {
        int optionInput,searchResult;
        char label[10];
        do
        {
            printf("\n\tSYMBOL TABLE IMPLEMENTATION\n");
            printf("\n\t1.INSERT\n\t2.DISPLAY\n\t3.DELETE\n\t4.SEARCH\n\t5.MODIFY\n\t6.END\n");
            printf("\n\tEnter your option : ");
            scanf("%d",&optionInput); /** Scan an integer and store it into 'option' memory location**/
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
                    scanf("%s",label); /**Scan a string and store each character of said string into 'label'**/
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
        
    }  /* end of main */
    
    /*
        Insert function.
        
        Inserts a new SymbTab struct node into the linked list representing the symbol table.
        
        Checks that the input label isn't a dupe beforehand. If it is, then the program will
        return. Otherwise, the program asks the user to input the fields for symbol and address
        of the symbol table entry.
    */
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
            newEntry=malloc(sizeof(struct SymbTab));
            strcpy(newEntry->label,label); /*copy label into newEntry->label*/
            printf("\n\tEnter the symbol : ");
            scanf("%s",newEntry->symbol); /*Scan a string and store its characters into newEntry->symbol*/
            printf("\n\tEnter the address : ");
            scanf("%d",&newEntry->addr); /*scan an integer and store it in the memory address of newEntry->addr*/
            newEntry->next=NULL; /** Initialize newEntry's *next value **/
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

    /*
        Displays the linked list as an actual symbol 'table'
    */
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

    /*
        Search method.
        Iterates through the linked list to search for a label and check if it exists.
        0 = false
        1 = true
    */
    int Search(char lab[])
    {
        int flag=0;
        struct SymbTab *searchCursor;
        searchCursor=first;
        for(int i=0;i<size;i++)
        {
            if(strcmp(searchCursor->label,lab)==0) /*Compare searchCursor->label and lab[]*/
                flag=1;
            searchCursor=searchCursor->next; /*Cursor moves on to next node*/
        }
        return flag;
    }

    /*
        Modify method
        
        Method that can modify entries in the symbol table

        The method first aks the user what they wanna do with the table
        then ask which option the user would like to take on the entry.
    */
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
            case 1: /**Edit the label of the entry**/
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
                        if(strcmp(modCursor->label,label)==0) /*If label found, change the label itself*/
                            strcpy(modCursor->label,newLabel);
                        modCursor=modCursor->next;
                    }
                    printf("\n\tAfter Modification:\n");
                    Display();
                }
                break;
            case 2: /**Edit the address of the entry**/
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
                        if(strcmp(modCursor->label,label)==0) /*If label found, change the address*/
                            modCursor->addr=add;
                        modCursor=modCursor->next;
                    }
                    printf("\n\tAfter Modification:\n");
                    Display();
                }
                break;
            case 3: /**Rename the label of the entry**/
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
                        if(strcmp(modCursor->label,label)==0) /**If the label is found, change the address and label**/
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

    /*
        Delete method
        Deletes the node of the linked list that represents the entry that the user entered.
        The method first asks the user to enter the name of the label and the method 
        searches for the lable. If it's not found, then return. Otherwise, delete the requested 
        entry.
    */
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
    
    
