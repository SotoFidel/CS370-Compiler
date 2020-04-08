    /* Lab6: ast.c Node creating and printing took */
    /*
        Written by: Fidel Soto
    */
    /*
        Date: March 21, 2020
        INITIAL IMPLEMENTATION
            *Created a function that will create and return a node
                to the yacc file, at which point the yacc file
                will manipulate the node as needed.
            *Added print routine that will recursively print the
                abstract syntax tree, with matching tabs for levels.
    */

#include "ast.h"
#include <stdio.h>
#include <malloc.h>

    /*
        variables to use when printing. This is being 
        done because the DATAYPE and OPERATOR enums
        are, technically, numbers, and they get printed as such.
        This aleviates that problem.
    */ 
    char *type;
    char *op;

ASTNode *ASTCreateNode(enum NODETYPE type)
{
    ASTNode *p;
    p = ( ASTNode *)(malloc (sizeof( struct ASTNodeType ) ) );
    p->Type = type;
    
    /*
        The pointers need to be set to null explicitly, otherwise
        they will be set to whatever the computer wants
    */
    p->next = NULL;
    p->s1 = NULL;
    p->s2 = NULL;
    return p;
}

/**
 * printTabs function to print tabs according to the level.
*/
void printTabs(int level) {
    for (int i = 0; i  < level; i++)
    {
        printf("\t");
    }
}

char *typeToString(enum DATATYPE typeParam) {

    // Datatype of variable declaration
    switch (typeParam) 
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
    } //end of p->datatype switch

}

 

/**
 * ASTprint function. This will print out information about
 * the node according to what type of node it is.
*/
void ASTprint(ASTNode *p, int level)
{
    //base case
    if (p == NULL) return;
    
    switch (p->Type)
    {
        
        case varDeclaration:   
        //Variable declaration    
            printTabs(level);
            printf("VARIABLE DEC: ");
            
            typeToString(p->dataType);
            
            printf("%s ", type);

            printf(" %s ", p->name);

            /*
                if size is more than one, then it's an
                array declaration. So print the size of the 
                array as well.
            */
            if (p->size > 1)
            {
                printf("[%d]", p->size);
            }
            printf("\n");

            /*
                Vardec lists are 's1' connected.
            */
            ASTprint(p->s1, level);
        break;
        
        case funDeclaration:
        //function declaration
            printTabs(level);
            printf("FUNCTION:\n");

            //return type
            typeToString(p->dataType);

            printTabs(level);
            printf("%s ", type);

            /*
                print the name followed by the list
                of parameters.
            */
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
                        
            ASTprint(p->s2, level + 1);
            
            printTabs(level);
            printf("END OF FUNCTION\n");
        break;
        
        case param:
        //Parameter or list of parameters
            printTabs(level);
            printf("PARAMETER: ");
            typeToString(p->dataType); // end of p->parameter switch
            printTabs(level);
            printf("%s ", type);

            printf(" %s", p->name);
            if (p->size == -1)
            {
                printf(" []");
            }

            printf("\n");

        break;

        case body:
        //block statement
            printTabs(level);
            printf("BLOCK STATEMENT:\n");

            //Local declarations
            ASTprint(p->s1, level +1);

            //Statement list
            ASTprint(p->s2, level +1);

            printTabs(level);
            printf("END OF BLOCK STATEMENT\n");
            
        break;
        
        case expression:
        //Expression statement
            /*
                The order of printing for 
                expressions is 
                1. LHS
                2. Operator
                3. RHS
                To make the output file more readable
            */
            printTabs(level);
            printf("EXPRESSION:\n");

            //LHS
            ASTprint(p->s1, level + 1);

            printTabs(level + 1);
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
            } //end of p->operator switch
            
            //Operator
            printf("OPERATOR: %s\n", op);
            
            //RHS
            ASTprint(p->s2, level + 1);

            printTabs(level);
            printf("END OF EXPRESSION\n");
        break;

        case myWrite:
            //Write statement
            printTabs(level);
            printf("WRITE STATEMENT.\n");

            ASTprint(p->s1, level + 1);

            printTabs(level);
            printf("END OF WRITE STATEMENT.\n");
        break;
        
        case myRead:
        //read statement
            printTabs(level);
            printf("READ STATEMENT\n");

            ASTprint(p->s1, level + 1);

            printTabs(level);
            printf("END OF READ STATEMENT\n");
        break;
        
        case myNum:
        //number, or a 1 or 0 representing TRUE or FALSE
        //respectively
            printTabs(level);
            printf("NUMBER WITH VALUE: %d\n", p->size);
        break;
        
        case variable:
            //Variable found.
            printTabs(level);
            if (p->s1 == NULL)
            {
                printf("IDENTIFIER WITH NAME: %s\n", p->name);
            }
            else 
            {
                printf("ARRAY REFERENCE:\n");
                printTabs(level + 1);
                printf("NAME: %s\n", p->name);
                printTabs(level + 1);
                printf("[\n");
                ASTprint(p->s1, level + 2);
                printTabs(level + 1);
                printf("]\n");
            }
        break;
        
        case myCall:
            //Function call
            printTabs(level);
            printf("FUNCTION CALL:\n");
            
            printTabs(level);
            printf("%s\n", p->name);
            
            printTabs(level);
            printf("(\n");

            ASTprint(p->s1, level + 1);
            printTabs(level);

            printf(")\n");
            printTabs(level);

            printf("END OF FUNCTION CALL\n");
        break;

        case argslist:
            ASTprint(p->s1, level);
        break;

        case myReturn:
        //return statement
            printTabs(level);
            printf("Return statement found.\n");
            
            //Print the return values, if any
            if (p->s1 != NULL)
            {
                printTabs(level);
                printf("Return values:\n");
                ASTprint(p->s1, level + 1);
            }

        break;

        case assignment:
        //assignment statement
            printTabs(level);
            printf("ASSIGNMENT STATEMENT\n");

            //variable that is being assigned
            ASTprint(p->s1, level + 1);
            
            /*
                If the operator in an assignment node is not
                '=', then something is horribly wrong.
            */
            printTabs(level + 1);
            if (p->operator == equals)
            {
                printf("OPERATOR: equals\n");
            }
            else 
            {
                printf("ERROR\n");
            }
            
            //right hand side of the assignment
            ASTprint(p->s2, level + 1);

            printTabs(level);
            printf("END OF ASSIGNMENT STATEMENT\n");
        break;

        case iteration:
        //iteration statement
            printTabs(level);
            printf("ITERATION STATEMENT\n");
            
            printTabs(level);
            printf("CONDITION:\n");
            ASTprint(p->s1, level + 1);
            
            printTabs(level);
            printf("END OF CONDITION\n");
            
            /*
                The body of the iteration 
                statement isn't explicitly a 
                block statement. These Iteration Body
                print outs are to help read the output
                of the tree.
            */
            printTabs(level);
            printf("ITERATION BODY:\n");
            ASTprint(p->s2, level + 1);
            printTabs(level);
            printf("END OF ITERATION BODY\n");
            
            printTabs(level);
            printf("END OF ITERATION STATEMENT\n");
        break;
        
        case selection:
        //if | if/else statement
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

            //Body corresponding to the if|if/else statement
            printTabs(level);
            printf("Positive Statement:\n");
            ASTprint(p->s1, level + 1);
            
            //if the 'else' part of the selection body isn't null
            //then there's a negative statement
            if (p->s2 != NULL)
            {
                printTabs(level);
                printf("Negative statement: \n");
                ASTprint(p->s2, level + 1);
            }
            
        break;
        
        default:
            printf("UNKNOWN type in ASTprint\n");
    }//end of p->type switch
    
    //Statements are connected by the 'next' pointer
    ASTprint (p -> next, level);

}
