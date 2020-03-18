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
    myRead,
    myNum,
    expression,
    assignment,
    variable,
    myCall,
    myReturn,
    selection,
    selectionBody,
    iteration,
    
}; // end of enum NODETYPE

enum DATATYPE
{
    intType,
    boolType,
    voidType
}; // end of enum DATATYPE

enum OPERATOR
{
    plus, 
    minus,
    mult,
    division,
    equals,
    myAnd,
    myOr,
    myNot,
    le,
    lt,
    gt,
    ge,
    eq,
    ne
}; // end of enum OPERATOR

typedef struct ASTNodeType
{
    enum NODETYPE Type;
    enum DATATYPE dataType;
    enum OPERATOR operator;
    
    char *name;
    int size;
    
    struct ASTNodeType *s1, *s2, *next;
    
} ASTNode;  // end of struct definition

void printTabs(int level);

void ASTprint(ASTNode *p, int level);

ASTNode *ASTCreateNode(enum NODETYPE type);

#endif
