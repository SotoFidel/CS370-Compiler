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
    
    switch (p->Type) 
    {
        case varDeclaration:   
            printTabs(level);
            printf("varDeclaration found.\n");
            printTabs(level);
            char *type;
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
                    type = "undetermined?";
                break;
            }
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
        break;
        
        case body:
        printTabs(level);
        printf("body found.\n");
        break;
        
        case expression:
        printTabs(level);
        printf("expression found.\n");
        printf("Operator is ");
        ASTprint(p->s1, level +1);
        ASTprint(p->s2, level +1);
        break;
        
        default:
            printf("UNKNOWN type in ASTprint\n");
    }
    ASTprint (p -> next, level);
}
