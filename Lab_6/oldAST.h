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
    char *dataType;
    int size;
    struct ASTNodeType *s1, *s2, *next;
} ASTNode;

void printTabs(int level);

void ASTprint(ASTNode *p, int level);

ASTNode *ASTCreateNode(enum NODETYPE type);

#endif
