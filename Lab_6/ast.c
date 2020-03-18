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
    if (p == NULL) return;
    char *type;
    char *op;
    switch (p->Type) 
    {
        
        case varDeclaration:   
            
            printTabs(level);
            printf("VARIABLE DEC: ");
            
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
            
            printf("%s ", type);

            printf(" %s ", p->name);

            if (p->size > 1)
            {
                printf("[%d]", p->size);
            }
            printf("\n");

            ASTprint(p->s1, level);
            ASTprint(p->s2, level);
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
            if (p->s1 != NULL)
            {
                ASTprint(p->s1, level + 1);
            }
            else
            {
                printf("VOID\n");
            }
            
            printTabs(level);
            printf("END of parameters\n");
            
            printf("\n");
            
            printTabs(level);
            printf("Body:\n");
            ASTprint(p->s2, level + 1);
            
            printTabs(level);
            printf("END of body\n");
            
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
            printf("Type: %s", type);
            
            if (p->size == -1)
            {
                printf(" array");
            }
            
            printf("\n");

            printTabs(level);
            printf("Name: %s\n", p->name);
        break;

        case body:
            
            ASTprint(p->s1, level +1);
            ASTprint(p->s2, level +1);
            
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
                
                case le:
                    op = "LE";
                break;
                
                case lt:
                    op = "LT";
                break;
                
                case gt:
                    op = "GT";
                break;
                
                case ge:
                    op = "GE";
                break;
                
                case eq:
                    op = "EQ";
                break;
                
                case ne:
                    op = "NE";
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
            
            printTabs(level);
            printf("Condition:\n");
            ASTprint(p->s1, level + 1);
            
            printTabs(level);
            printf("END of condition\n");
            
            printTabs(level);
            printf("Body:\n");
            ASTprint(p->s2, level + 1);
            
            printTabs(level);
            printf("END of iteration statment \n");
        break;
        
        case selection:
            printTabs(level);
            printf("Selection statement found\n");
            
            printTabs(level);
            printf("Condition:\n");
            ASTprint(p->s1, level + 1);
            
            printTabs(level);
            printf("END of condition\n");
            
            ASTprint(p->s2, level);
            
            printTabs(level);
            printf("END of selection statement\n");
            
        break;
        
        case selectionBody:
            printTabs(level);
            printf("Positive Statement:\n");
            ASTprint(p->s1, level + 1);
            
            if (p->s2 != NULL)
            {
                printTabs(level);
                printf("Negative statement: \n");
                ASTprint(p->s2, level + 1);
            }
            
        break;
        
        default:
            printf("UNKNOWN type in ASTprint\n");
    }
    
    ASTprint (p -> next, level);

}
