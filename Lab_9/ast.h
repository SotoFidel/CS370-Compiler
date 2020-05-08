    /* ast.h */
    /*
        Written by: Fidel Soto
    */
   /*
        Date: March 21, 2020
        ADDED NODE AND ENUMS DECLARATIONS:
            *Added enumerators for NODETYPE, DATATYPE, and OPERATOR.
            *Added struct ASTNode. Each node is either s1,s2, or 'next'
                connected.
            *All this info will be used by the YACC file
            *Added function prototypes
   */

   /*
        April 13, 2020
        ADDED MORE DECLARATIONS
            *Added a datatype enum for NODETYPE and a pointer to the symbol
             table pointer.
            *Added a prototype for checkFormalsAndParams
   */

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
    argslist,
    exprStmt
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
    enum DATATYPE semanticType;
    enum DATATYPE dataType;
    enum OPERATOR operator;
    
    char *name;
    char *label;
    int size;
    
    struct ASTNodeType *s1, *s2, *next;
    struct SymbTab *symbol;
    
} ASTNode;  // end of struct definition

void printTabs(int level);

void ASTprint(ASTNode *p, int level);

char *typeToString(enum DATATYPE typeParam);

int checkFormalsAndParms(ASTNode *f, ASTNode *a);

ASTNode *ASTCreateNode(enum NODETYPE type);

#endif
