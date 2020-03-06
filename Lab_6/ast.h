//ast.h

#ifndef AST

#define AST

enum NODETYPE
{
    varDeclaration,
    funDeclaration
    //and so forth
}; // end of enum NODETYPE

typedef struct ASTNodeType
{
    enum NODETYPE Type;
    char *name;
    struct ASTNodeType *s1, *s2, *next;
} ASTNode;

void ASTprint(ASTNode *p, int level);

ASTNode *ASTCreateNode(enum NODETYPE type);

#endif
