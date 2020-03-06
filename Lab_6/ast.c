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


void ASTprint(ASTNode *p, int level)
{
    if (p == NULL) return;
    
    switch (p->Type) 
    {
        case varDeclaration:    
            printf("varDeclaration found\n");
            printf("name is %s\n\n", p->name);
        break;
        
        default:
            printf("UNKNOWN type in ASTprint\n");
    }
    ASTprint (p -> next, level++);
}
