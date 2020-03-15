//ast.h

#ifndef AST

#define AST

enum NODETYPE
{
    varDeclaration,
    funDeclaration,
    param,
    body,
    myWrite,
    myNum,
    expression
    //and so forth
}; // end of enum NODETYPE

enum DATATYPE
{
    intType,
    boolType,
    voidType
};

enum OPERATOR
{
    plus, 
    minus
};

typedef struct ASTNodeType
{
    enum NODETYPE Type;
    char *name;
    enum DATATYPE dataType;
    int size;
    struct ASTNodeType *s1, *s2, *next;
    enum OPERATOR operator;
} ASTNode;

void printTabs(int level);

void ASTprint(ASTNode *p, int level);

ASTNode *ASTCreateNode(enum NODETYPE type);

#endif
