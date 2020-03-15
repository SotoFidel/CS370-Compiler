#include "ast.h"
#include <stdio.h>
#include <malloc.h>

ASTNode *ASTCreateNode(enum NODETYPE type)
{
    ASTNode *p;
    p = ( ASTNode *)(malloc (sizeof( struct ASTNodeType ) ) );
    p->Type = type;
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
            printf("Body: ");
            ASTprint(p->s2, level + 1);
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

            //ASTprint(p->next, level + 1);
            // ASTprint(p->s2, level + 1);
        break;

        case body:
            printf("body found.\n");
            ASTprint(p->s1, level +1);
            ASTprint(p->s2, level +1);
        break;
        
        case expression:
            printTabs(level);
            printf("expression found.\n");
            printf("Operator is ");
            ASTprint(p->s1, level +1);
            ASTprint(p->s2, level +1);
        break;

        case myWrite:
            printTabs(level);
            printf("Write statement found.\n");
        break;
        
        default:
            printf("UNKNOWN type in ASTprint\n");
    }
    ASTprint (p -> next, level);
}
