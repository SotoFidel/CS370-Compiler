#include "ast.h"
#include <stdio.h>
#include <malloc.h>

ASTNode *ASTCreateNode(enum NODETYPE type)
{
    switch (type) 
    {
        ASTNode *p;
        case    varDeclaration:
            p = ( ASTNode *)(malloc (sizeof( struct ASTNodeType ) ) );
            return p;
        break;
    }
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
            printf("varDeclaration found.");
            printf("Name is %s \t size is %d\n", p->name, p->size);
        break;
        
        default:
            printf("UNKNOWN type in ASTprint\n");
    }
    ASTprint(p->s1, level + 1);
    ASTprint(p->s2, level + 1);
    ASTprint (p -> next, level);
}
