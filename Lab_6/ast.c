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
                    type = "INT";
                break;
                case boolType:
                    type = "BOOL";
                break;
                case voidType:
                    type = "VOID";
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
            printf("FUNCTION:\n");
            switch (p->dataType) 
            {
                case intType:
                    type = "INT";
                break;
                case boolType:
                    type = "BOOL";
                break;
                case voidType:
                    type = "VOID";
                break;
                default:
                    type = "ERROR";
                break;
            }

            printTabs(level);
            printf("%s ", type);

            printf("%s \n", p->name);

            printTabs(level);
            printf("(\n");
            if (p->s1 != NULL)
            {
                ASTprint(p->s1, level + 1);
            }
            else
            {
                printTabs(level + 1);
                printf("VOID\n");
            }
            printf(")\n");
                        
            printTabs(level);
            printf("BODY:\n");
            ASTprint(p->s2, level + 1);
            
            printTabs(level);
            printf("END OF BODY\n");
            
            printTabs(level);
            printf("END OF FUNCTION\n");
        break;
        
        case param:
            printTabs(level);
            printf("PARAMETER: ");
            switch (p->dataType) 
            {
                case intType:
                    type = "INT";
                break;
                case boolType:
                    type = "BOOL";
                break;
                case voidType:
                    type = "VOID";
                break;
                default:
                    type = "ERROR";
                break;
            }
            printTabs(level);
            printf("%s ", type);
            
            if (p->size == -1)
            {
                printf(" []");
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
            printf("EXPRESSION:\n");
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
            printf("OPERATOR: %s\n", op);
            ASTprint(p->s2, level);
            printTabs(level);
            printf("END OF EXPRESSION\n");
        break;

        case myWrite:
            printTabs(level);
            printf("WRITE STATEMENT.\n");
            ASTprint(p->s1, level + 1);
        break;
        
        case myRead:
            printTabs(level);
            printf("READ STATEMENT\n");
            ASTprint(p->s1, level + 1);
        break;
        
        case myNum:
            printTabs(level);
            printf("NUMBER:\n");
            printTabs(level);
            printf("VALUE: %d\n", p->size);
        break;
        
        case variable:
            printTabs(level);
            if (p->s1 == NULL)
            {
                printf("IDENTIFIER: %s\n", p->name);
            }
            else 
            {
                printf("ARRAY REFERENCE:\n");
                printTabs(level);
                printf("%s\n", p->name);
                printTabs(level);
                printf("[\n");
                ASTprint(p->s1, level + 1);
                printTabs(level);
                printf("]\n");
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
            printf("ASSIGNMENT STATEMENT\n");

            ASTprint(p->s1, level + 1);

            printTabs(level);
            if (p->operator == equals)
            {
                printf("OPERATOR: equals\n");
            }
            else 
            {
                printf("ERROR\n");
            }
            
            ASTprint(p->s2, level + 1);

            printTabs(level);
            printf("END OF ASSIGNMENT STATEMENT\n");
        break;

        case iteration:
            printTabs(level);
            printf("ITERATION STATMENT\n");
            
            printTabs(level);
            printf("CONDITION:\n");
            ASTprint(p->s1, level + 1);
            
            printTabs(level);
            printf("END OF CONDITION\n");
            
            printTabs(level);
            printf("BODY:\n");
            ASTprint(p->s2, level + 1);
            printTabs(level);
            printf("END OF BODY\n");
            
            printTabs(level);
            printf("END OF ITERATION STATEMENT\n");
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
