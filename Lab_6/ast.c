#include "ast.h"
#include <stdio.h>
#include <malloc.h>

ASTNode *ASTCreateNode(enum NODETYPE type)
{
    ASTNode *p;
    p = ( ASTNode *)(malloc (sizeof( struct ASTNodeType ) ) );
    p->Type = type;
    p->next = NULL;
    p->s1 = NULL;
    p->s2 = NULL;
    return p;
}

void printTabs(int level) {
    for (int i = 0; i  < level; i++)
    {
        printf("\t");
    }
}

void ASTprint(ASTNode *p, int level)
{
    if (level == 0)
        printf("\n\n"); 
    if (p == NULL) return;
    char *type;
    char *op;
    switch (p->Type) 
    {
        
        case varDeclaration:   
            
            printTabs(level);
            printf("varDeclaration found.\n");
            
            switch (p->dataType) 
            {
                case intType:
                    type = "int";
                break;
                case boolType:
                    type = "bool";
                break;
                case voidType:
                    type = "void";
                break;
                default:
                    type = "ERROR";
                break;
            }
            
            printTabs(level);
            printf("Type: %s\n", type);

            printTabs(level);
            printf("Name: %s\n", p->name);

            printTabs(level);
            printf("Size: %d\n\n", p->size);

            ASTprint(p->s1, level + 1);
            ASTprint(p->s2, level + 1);
        break;
        
        case funDeclaration:
            printTabs(level);
            printf("funDeclaration found.\n");
            switch (p->dataType) 
            {
                case intType:
                    type = "int";
                break;
                case boolType:
                    type = "bool";
                break;
                case voidType:
                    type = "void";
                break;
                default:
                    type = "ERROR";
                break;
            }

            printTabs(level);
            printf("Return type: %s\n", type);

            printTabs(level);
            printf("Name: %s\n", p->name);

            printTabs(level);
            printf("Parameters: \n");
            ASTprint(p->s1, level + 1);
            printf("\n");

            printTabs(level);
            printf("Body:\n");
            ASTprint(p->s2, level + 1);
            
            printTabs(level);
            printf("END of funDeclaration\n");
        break;
        
        case param:
            printTabs(level);
            printf("Parameter found.\n");
            switch (p->dataType) 
            {
                case intType:
                    type = "int";
                break;
                case boolType:
                    type = "bool";
                break;
                case voidType:
                    type = "void";
                break;
                default:
                    type = "ERROR";
                break;
            }
            printTabs(level);
            printf("Type: %s\n", type);

            printTabs(level);
            printf("Name: %s\n", p->name);
        break;

        case body:
            printTabs(level);
            printf("body found.\n");
            
            ASTprint(p->s1, level +1);
            ASTprint(p->s2, level +1);
            
            printTabs(level);
            printf("END of body\n");
        break;
        
        case expression:
            printTabs(level);
            printf("Expression:\n");
            ASTprint(p->s1, level + 1);
            printTabs(level);
            switch(p->operator)
            {
                case plus:
                    op = "plus";
                break;

                case minus:
                    op = "minus";
                break;

                case mult:
                    op = "multiplication";
                break;

                case division:
                    op = "division";
                break;

                case myAnd:
                    op = "and";
                break;

                case myOr:
                    op = "or";
                break;

                case myNot:
                    op = "not";
                break;

                default: op = "ERROR";
            }
            printf("Operator: %s\n", op);
            ASTprint(p->s2, level);
            printTabs(level);
            printf("END of expression\n");
        break;

        case myWrite:
            printTabs(level);
            printf("Write statement found.\n");
            ASTprint(p->s1, level + 1);
        break;
        
        case myRead:
            printTabs(level);
            printf("Read statement found.\n");
            ASTprint(p->s1, level + 1);
        break;
        
        case myNum:
            printTabs(level);
            printf("Number found\n");
            printTabs(level);
            printf("Value: %d\n", p->size);
        break;
        
        case variable:
            printTabs(level);
            if (p->s1 == NULL)
            {
                printf("Variable found\n");
                printTabs(level);
                printf("Name: %s\n", p->name);
            }
            else 
            {
                printf("Array reference found\n");
                printTabs(level);
                printf("Name: %s\n", p->name);
                printTabs(level);
                printf("Index:\n");
                ASTprint(p->s1, level + 1);
            }
        break;
        
        case myCall:
            
            printTabs(level);
            printf("Function call found.\n");
            
            printTabs(level);
            printf("Name: %s\n", p->name);
            
            printTabs(level);
            printf("Arguments:\n");
            ASTprint(p->s1, level + 1);
            
            printTabs(level);
            printf("END of function call\n");
        break;

        case myReturn:
            printTabs(level);
            printf("Return statement found.\n");
            if (p->s1 != NULL)
            {
                printTabs(level);
                printf("Return values:\n");
                ASTprint(p->s1, level + 1);
            }

        break;

        case assignment:
            printTabs(level);
            printf("Assignment statement found.\n");

            ASTprint(p->s1, level + 1);

            printTabs(level);
            if (p->operator == equals)
            {
                printf("Operator: equals\n");
            }
            else 
            {
                printf("ERROR\n");
            }
            
            ASTprint(p->s2, level + 1);
        break;

        case iteration:
            printTabs(level);
            printf("Iteration statement found.\n");
        break;
        
        default:
            printf("UNKNOWN type in ASTprint\n");
    }

    ASTprint (p -> next, level);

}
