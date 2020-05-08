/*
   Written by: Fidel Soto
   Date: May 6, 2020
   
   Emit file.
   This C file takes care of emitting mips code to a file whose name was specified by the user.
   This file also takes care of what logic to follow when emitting the mips code. For example,
   if the operator of an expression is +, then the file will emit an addition instruction, and 
   so on for other operators. 
   Emmitting the instructions onto the file specified by the user is one big recursive process that is started
   when emitAST() is called by the y file after parsing the code inputted by the user. Some of the functions
   called emitAST() are also recursive, namely emitExpression(), so you can have expressions with as many
   operators as you want, etc.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ast.h"
#include "emit.h"


static int GLABEL = 0;  // global label counter. Used for strings and conditionals
char *currentFunction; // Used to emit the label for functions

// Prototypes for functions.
void emit(FILE *fp, char *label, char *command, char*comment);
void emitAssignment(ASTNode *p, FILE *fp);
void emitAST(ASTNode *p, FILE *fp);
void emitCall(ASTNode *p, FILE *fp);
void emitExpression(ASTNode *p, FILE *fp);
void emitGlobals(FILE *fp, ASTNode *p);
void emitIf(ASTNode *p, FILE *fp);
void emitIdentifier(ASTNode *p, FILE *fp);
void emitIteration(ASTNode *p, FILE *fp);
void emitFunctionHead(ASTNode *p, FILE *fp);
void emitFunctionReturn(ASTNode *p, FILE *fp);
void emitRead(ASTNode *p, FILE *fp);
void emitStrings(FILE *fp, ASTNode *p);
void emitWrite(ASTNode *p, FILE *fp);



/*
   PRECONDITION: Get called by either emit.c or lab9.y
   POSTCONDITION: Returns a label string with a unique
      number that increments as the program is called.
*/
char * genlabel()
{  
   char s[100];
   char *s1;
   sprintf(s,"_L%d",GLABEL++);
   s1=strdup(s);  // get heap memory for the label name
   return (s1);
}// end of genLabel


/*
   Emit the strings being used by the input program for write statements.
   PRECONDITION: Receives a file pointer and an ASTNode pointer to print out onto the .asm file
   POSTCONDITION: For every node that is a write statement with a string, prints the string onto the .asm file
      with a corresponding label.
*/
void emitStrings(FILE *fp, ASTNode *p)
{
   if (p == NULL)
   {
      return;
   }
   if ( p->Type == myWrite && p->name != NULL )
   {
      //We are in a 'write' ASTNode. emit the label and name (content) of the node onto the .asm file
      fprintf(fp, "%s:\t .asciiz\t%s\n", p->label, p->name);  
   }
   emitStrings(fp,p->next);
   emitStrings(fp,p->s1);
   emitStrings(fp,p->s2);
} // end of emitStrings


/*
   Emit the global variables from the input program. 
   PRECONDITION: The function takes a file pointer and an ASTNode pointer
   POSTCONDITION: The function will print the global variables and their size at the top of the .asm file
*/
void emitGlobals(FILE *fp, ASTNode *p)
{
   if (p == NULL)
   {
      return;
   }
   if ( p->Type == varDeclaration && p->symbol->level == 0 )
   {
      //We are in a global varDeclaration ast node. prin the name, symbol, and size * 4 (each word takes 4 bytes)
      fprintf(fp,"%s:\t .space\t%d\n", p->name, p->symbol->mysize*WSIZE);
   }
   emitGlobals(fp, p->next);
   emitGlobals(fp, p->s1);
} // end of emitGlobals


/*
   Helper functio to make clean MIPS code. Take in 4 params, 
   and print them out    P r e t t y

   pseudo example: emit(fp, "L1","ldi R13, 15", "#Load a number")
   output: L1:    ldi R13, 15    #Load a number

   PRECONDITION: The function takes a file pointer to the .asm file, a label, the command to be printed,
   and a comment. The comment helps in making self documenting mips code.
   
   POSTCONDITION: The function will print out the specified strings in order into the .asm file.
*/
void emit(FILE *fp, char *label, char *command, char*comment){
   if (strcmp("", label) == 0)
   {
      //There's no label. No tabs necessary for label section. print command and comment only
      fprintf(fp,"\t%s\t\t%s\n", command, comment);
   }
   else
   {
      //print the label along with the instruction and comment
      fprintf(fp,"%s:\t\t%s\t\t%s\n", label, command, comment);
   }
}// end of emit


/*
   PRECONDITION: The function takes an ASTNode and a file pointer to the file that the 
      user has specified. 
   POSTCONDITION: The function will print mips code
      that adjusts the stack pointer and return address upon
      entering the function. 
   Necessary for every function
*/
void emitFunctionHead(ASTNode *p, FILE *fp){
   fprintf(fp, "\n");
   char s[100];
   emit(fp, p->name, "", "# Start of function\n");
   currentFunction = p->name;

   //Build stack pointer Movement
   sprintf(s, "subu $a0, $sp, %d", p->size*WSIZE);
   emit(fp, "", s, "# adjust stack for function setup");
   emit(fp, "", "sw $sp, ($a0)", "");
   emit(fp, "", "sw $ra, 4($a0)","");
   emit(fp, "", "move $sp, $a0", "# adjust the stack pointer");
   fprintf(fp, "\n");
}//end of emitFunctionHead


/*
   PRECONDITION: The function receives a pointer to an identifier.
   POSTCONDITION: Emits MIPS code such that $a0 is the ADDRESS of where
      the identifier is in memory.
*/
void emitIdentifier(ASTNode *p, FILE *fp)
{
   char s[100];
   if (p->symbol->level == 0)
   {
      //Global var
      if (p->symbol->IsAFunc == 2)
      {
         //This is a global array reference 
         emitExpression(p->s1, fp); //stores value in $a0

         sprintf(s, "sll $t0, $a0, %d", LOGWSIZE); //Multiply $a0 by two and store into $t0
         emit(fp, "", s, "# Shift to get to word size");

         sprintf(s, "la $a0, %s", p->name); //Get the offset of the global variable
         emit(fp, "", s, " # Identifier is a global array reference");

         sprintf(s, "add $a0, $a0, $t0"); //We compensate for internal array offset.
         emit(fp, "", s, " # Compensate for internal offset of array");

      }
      else
      {
         //This is a global scalar
         sprintf(s, "la $a0, %s", p->name);
         emit(fp, "", s, " # Identifier is a global scalar");
         fprintf(fp, "\n");
      }
      
   } // end of global conditional
   else 
   {
      //Local var
      if (p->symbol->IsAFunc == 2)
      {
         //This is a local array reference
         emitExpression(p->s1, fp);

         sprintf(s, "sll $t0, $a0, %d", LOGWSIZE); //Multiply $a0 by two and store into $t0
         emit(fp, "", s, "# Shift to get to word size");
         
         sprintf(s, "add $a0, $sp, %d", p->symbol->offset * WSIZE); //get to the initial address of the array. stack pointer + offset
         emit(fp, "", s, " # Identifier is a local array reference. Offset of local array"); //We calculate the local offset

         sprintf(s, "add $a0, $a0, $t0"); //We compensate for internal array offset.
         emit(fp, "", s, " # Compensate for internal offset of array");
         
         fprintf(fp, "\n");
      }
      else
      {
         sprintf(s, "add $a0, $sp, %d", p->symbol->offset * WSIZE); //get to address of variable. stack pointer + offset
         emit(fp, "", s, " # Identifier is a scalar");
         fprintf(fp, "\n");
      }
      
      
   }//end of local conditional

}//end of emitIdentifier


/*
   PRECONDITION: The function receives pointer to the call node, and a pointer to the file
   that is specified by the user into the .asm file
   POSTCONDITION: The function will emit mips code for a function call and jumps to the function
*/
void emitCall(ASTNode *p, FILE *fp)
{
   char s[100];

   //Make an arguments node
   ASTNode *arguments;
   arguments = p->s1;

  
   //While arguments is not null, store the value into temporary stack pointer offset
   while (arguments != NULL){
      emitExpression(arguments->s1, fp); // Now $a0 has the evaluated value
      sprintf(s, "sw $a0, %d($sp)", arguments->symbol->offset * WSIZE); //store the valuee in to temporary mem location
      emit(fp, "", s, "");
      arguments = arguments->next;
   }

   //Calculate the future activation record stack value in t2. that is stack pointer minus size of function
   sprintf(s, "subu $t2, $sp, %d", p->symbol->mysize*WSIZE);
   emit(fp, "", s, "# calculate the future activation record");

   //Now copy each argument into the appropiate t2 + offset location
   arguments = p->s1;
   ASTNode *formals;
   formals = p->symbol->fparms;

   while (arguments != NULL){

      sprintf(s, "lw $t0 %d($sp)", arguments->symbol->offset * WSIZE); //Load the actual parameter value from the temporary mem location
      emit(fp, "", s, "#load actual parameter value");

      sprintf(s, "sw $t0 %d($t2)", formals->symbol->offset * WSIZE); //And then stick it into the formal parameter address
      emit(fp, "", s, "#Stick it into the formal parameter");

      formals = formals->next;
      arguments = arguments->next;
   }

   //Now we do the jump
   sprintf(s, "jal %s", p->name);
   emit(fp, "", s, "# jump and link to the called function");
   fprintf(fp, "\n");

}

/*
   PRECONDITION: Receives a ptr to an expression defined by the Yacc file
   POSTCONDITION: Writes MIPS code that sets $a0 to said pointer
*/
void emitExpression(ASTNode *p, FILE *fp)
{
   fprintf(fp, "\n");
   char s[100];

   //Base cases of emitExpresssion
   //Will return if base case, otherwise keep going recursively
   switch(p->Type)
   {
      case myNum:
         //This is a number
         sprintf(s, "li $a0, %d", p->size);
         emit(fp, "", s, "# The expression is just a number");
         return;
         break; //Unreachable, but helpful nonetheless
      case variable:
         //This is a variable
         emitIdentifier(p, fp); // we know $a0 is the ADDRESS of the identifier.
         emit(fp, "", "lw $a0, ($a0)", "# Fetch value for identifier"); //this is effectively a replacement
         fprintf(fp, "\n");
         return;
         break; //same here. Unreachable. but we want to make sure these are separate from recursive cases. 
      case myCall:
         //We'll be making a function call
         emitCall(p, fp);
         return;
         break; // Same here again.
   }




   //We are now in the recursive cases

   emitExpression(p->s1, fp); //Whatever the value was, it gets stored into $a0
   sprintf(s, "sw $a0, %d($sp)", p->symbol->offset * WSIZE); //Now we store the contents of $a0 into temporary
   emit(fp, "", s, "# Store contents into temporary offset");

   if (p->s2 == NULL){
      //If p->s2 is null, then we're in a NOT operation. Then we perform NOT unary and return
      emit(fp, "", "sltiu $a0, $a0, 1", "#Perform not operation on value");
      return;
   }
   
   //We are in an expression composed of non-unary operators
   emitExpression(p->s2, fp); //Same thing here. get stored into $a0
   emit(fp, "", "move $a1, $a0", "# Move contents of $a0 into $a1"); //Then moved $a0 contents into $a1
   sprintf(s, "lw $a0 %d($sp)", p->symbol->offset * WSIZE); //We retrieve the contents from the temporary
   emit(fp, "", s, "# retrieve contents from temporary");


   // Now perform the operation specified by p->operator
   switch (p->operator)
   {
   case plus: //add
      emit(fp, "", "add $a0, $a0, $a1", " # Perform add operation and store the result in $a0");
      break;
   case minus: //subtract
      emit(fp, "", "sub $a0, $a0, $a1", "# Perform subtraction and store the result in $a0");
      break;
   case mult: //multiply
      emit(fp, "", "mult $a0, $a1", "#Multiply $a0 and $a1, and store the result in $LO");
      emit(fp, "", "mflo $a0", "# Move the product from $LO into $a0");
      break;
   case division:  //divide
      emit(fp, "", "div $a0, $a1", " # Divide $a0 by $a1. Quotient -> $LO, Remainder -> $HI");
      emit(fp, "", "mflo $a0", "#Get the quotient from $LO and store it into $a0");
      break;
   case myAnd: // and operation
      emit(fp, "", "and $a0, $a0, $a1", "# Perform and on $a0 and $a1, store result in $a0");
      break;
   case myOr: // or operation
      emit(fp, "", "or $a0, $a0, $a1", "# Perform or on $a0 and $a0. store result in $a0");
      break;
   case le://Less than or equal to
      emit(fp, "", "sle $a0, $a0, $a1", "# $a0 is 1 if $a0 <= $a1. 0 otherwise");
      break;
   case lt: // Less than
      emit(fp, "", "slt $a0, $a0, $a1", " # $a0 is 1 if $a0 < $a1. 0 Otherwise");
      break;
   case gt: //greater than
      emit(fp, "", "sgt $a0, $a0, $a1", "# $a0 is 1 if $a0 > $a1. 0 Otherwise");
      break;
   case ge: // greater than or equal to
      emit(fp, "", "sge $a0, $a0, $a1", "# $a0 is 1 if $a0 >= $a1. 0 Otherwise");
      break;
   case eq: // Equal to
      emit(fp, "", "seq $a0, $a0, $a1", "# $a0 is 1 if $a0 == $a1. 0 Otherwise");
      break;
   case ne: // not equal to
      emit(fp, "", "sne $a0, $a0, $a1", "# $a0 is 1 if $a0 != $a1. 0 Otherwise");
      break;
   default:
      break;
   }

   fprintf(fp, "\n");
}// end of emitExpression


/*
   PRECONDITION: The function takes assignment node and a pointer to the file that is being written into
   POSTCONDITION: The function evaluates the right size (s2) and the left side (s1), and makes the 
   assignment in mips code
*/
void emitAssignment(ASTNode *p, FILE *fp)
{
   
   char s[100];

   emitExpression(p->s2, fp); //Evaluate the right hand expression. Result gets stored into $a0
   emit(fp, "", "move $a1, $a0", "# Move contents of $a0 into $a1"); //store contents of $a0 into $a1

   emitIdentifier(p->s1, fp); // Get the identifier's memory location and store it into $a0
   emit(fp, "", "sw $a1, ($a0)", "#assign address' value"); // copy $a1's value into the address of $a0, which is the addresss of the identifier

   fprintf(fp, "\n");
} // end of emitAssignment


/*
   PRECONDITION: The function will take an ASTNODE that is either NULL or an expression to return, and 
      a file pointer to the asm file
   POSTCONDITION: mips code that restores the return address and stack pointer will be printed onto the .asm file

   Handles implicit and explicit returns. If there is a return value, then emit expression and the final value will be in $a0
*/
void emitFunctionReturn(ASTNode *p, FILE *fp)
{

   if (p != NULL)
   {
      //We need to evaluate the expression.
      emitExpression(p, fp); // this leaves $a0 with the result
   }

   //adjust activation record back
   fprintf(fp, "\n");
   emit(fp, "", "lw $ra, 4($sp)", "# restore RA");
   emit(fp, "", "lw $sp, ($sp)", "#restore stack pointer");

   fprintf(fp, "\n");

   //exit for main only
   if (strcmp(currentFunction, "main") == 0) 
   {
      emit(fp, "", "li $v0, 10", "# Leave MAIN program ");
      emit (fp, "", "syscall", "#leave main");
   }
   else
   {
      //exit for any other function
      emit(fp, "", "jr $ra", "# Return from where function was called");
   }
   
   fprintf(fp, "\n");
}//end of emitFunctionReturn


/*
   PRECONDITION: The function receives a pointer to a write node
   POSTCONDITION: MIPS code for WRITE gets printed out into the .asm file pointed to by fp
*/
void emitWrite(ASTNode *p, FILE *fp) 
{
   
   if(p->s1 == NULL && p->name != NULL && p->label != NULL)
   {
      //WRITE STRING definition
      char s[100];
      emit(fp, "", "li $v0, 4", "# We will print a string");
      sprintf(s, "la $a0, %s", p->label);
      emit(fp, "", s, "");
      emit(fp, "", "syscall", "");
   }
   else
   {
      //WRITE EXPRESSION definition
      emitExpression(p->s1, fp); // $a0 is the value set from expression
      emit(fp,"","li $v0, 1"," # Print the number");
      emit(fp, "", "syscall", " # System call to print number");
   }
   
   fprintf(fp, "\n");
}//end of emitWrite


/*
   PRECONDITION: Receives a pointer to a write node and a pointer to a .asm file
   POSTCONDITION: mips code will be printed out onto the .asm file for read
*/
void emitRead(ASTNode *p, FILE *fp) 
{
   emitIdentifier(p->s1, fp); //  $a0 is the address we want to store in
   emit(fp, "", "li $v0, 5", " # Read a number from input");
   emit(fp,"", "syscall", "# reading a number");
   emit(fp, "", "sw $v0, ($a0)", " #Store the read into a memory location");
   fprintf(fp, "\n"); //$v0 had the value read in. The value is passed into $a0's address
}



/*
   PRECONDITION: The function takes if node and writes the code to file
   POSTCONDITION: The function emits expression on p->s1 (the condition). The resule will be 0(false) or not 0 (true).
   If true, go to positive statements, else negative statements
*/
void emitIf(ASTNode *p, FILE *fp){
   char *L1, *L2;
   char s[100];

   //Generate labels for positive and negative statement sections
   L1 = genlabel();
   L2 = genlabel();

   emitExpression(p->s1, fp); // The result will be stored in $a0. False if 0, True if anything else
   emit(fp, "", "li $t0, 0", "# Load $t0 with 0 for comparison");

   sprintf(s, "beq $a0, $t0, %s", L1); //Comparison 
   emit(fp, "", s, "# Compare. Go to negative statement if $a0 is 0, else keep going");
   
   emit(fp, "", "", "#Positive statements");
   emitAST(p->s2->s1, fp); //Positive Statement
   sprintf(s, "j %s", L2); //Jump past negative statement and keep going
   emit(fp, "", s, "#end of positive statements");
   fprintf(fp, "\n");

   emit(fp, L1, "", " #Negative statements"); // Negative Statement
   emitAST(p->s2->s2, fp);

   emit(fp, L2, "", "# End of If (or if/else) Statement");

   fprintf(fp, "\n");

}//end of emitIf



/*
   PRECONDITION: Takes iteration node and file pointer to file specified by user.
   POSTCONDITION: The function will emit iteration mips code into the file. Each 
      iteration involves evaluating to 0 or not 0. If 0, get out of loop. Otherwise continue
*/
void emitIteration(ASTNode *p, FILE *fp) {
   char s[100];
   char *L1, *L2;
   L1 = genlabel();
   L2 = genlabel();

   emit(fp, L1, "", "# Loop");
   emitExpression(p->s1, fp);
   emit(fp, "", "li $t0, 0 ", " # Load $t0 with 0 for comparison");

   sprintf(s, "beq $a0, $t0, %s", L2); // Comparison
   emit(fp, "", s, "# Compare. Get out of loop if result if $a is 0. Otherwise keep going");

   emitAST(p->s2, fp); // do whatever is in the body of the while loop
   sprintf(s, "j %s", L1); // jump back to compare again.
   emit(fp, "", s, "# Jump back to the loop conditional");
   
   fprintf(fp, "\n");
   
   emit(fp, L2, "", " # Exit of loop");

   fprintf(fp, "\n");

}// end of emitIteration




/*
   PRECONDITION: Takes pointer to the global pointer and a file pointer to the file specified by the user.
   POSTCONDITION: Calls functions based on the type of node that the function is, and keeps going until
      the end of compouond statement or file
*/
void emitAST(ASTNode *p, FILE *fp)
{
   if (p == NULL) return;
   switch (p->Type){
      case varDeclaration:
         //Already taken care of by function entries, and global variables. Break and go to next
         break;
      case funDeclaration:
         //Function declaration. Write the head, followed by the body, followed by return if not explicitly stated
         emitFunctionHead(p, fp);
         emitAST(p->s2, fp);
         emitFunctionReturn(NULL, fp);
         break;
      case body:
         //emit the body
         emitAST(p->s2, fp);
         break;
      case myWrite:
         //write statement
         emitWrite(p, fp);
         break;
      case myRead:
         //emit read statement
         emitRead(p, fp);
         break;
      case selection:
         //emit selection statement
         emitIf(p, fp);
         break;
      case iteration:
         //emit loop
         emitIteration(p, fp);
         break;
      case assignment:
         //emit assignment statement
         emitAssignment(p, fp);
         break;
      case exprStmt:
         //emit expression, which is exprstatement's p->s1 node pointer
         emitExpression(p->s1, fp);
         break;
      case myReturn:
         //emit function return for explicitly stated function
         emitFunctionReturn(p->s1, fp);
         break;
      default: printf("Not yet implemented. type was %d\n", p->Type); // oh GOD no
   }

   emitAST(p->next, fp);

}