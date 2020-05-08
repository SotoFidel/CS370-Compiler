# ******sumUser.asm*********
# Edited version of sum100. Edited by Fidel Soto
# Date: 4/20/20


#
#
#	This is an edited version of the sum100.asm file. This was edited so that now, 
#	instead of calculating the sum of squares from 0-100 hardcoded, the program
#	first asks for input, and then calculates the sum of squares from 0 to that
#	inputted number. 
#	
#	CHANGES:
#	*Added global variables to print out the prompt and the output of the user's input.
#	*Changed the '16' in the first line to 20, effectively adding a new variable. 
#	*Changed the 100 to $t1, where the user's input is being stored.
#
#

.data
L1: .asciiz "Please enter value: "
L2: .asciiz "The number read was "
L3:  .asciiz "The square is "
NL:  .asciiz "\n"
str:  .asciiz "The sum of squares from 0..."
str1:   .asciiz " is \n "
.align 0
        
 .text  # directive that we are in the code segment

main:
        subu $a0, $sp, 20 # We want 5 mem locations for main SP, RA, i , s, input
        sw $ra, 4($a0)  # we need to store the RA in the Activation record
        sw $sp, ($a0) # store SP
        move $sp, $a0  # adjust SP

        sw $0, 8($sp)  # store 0 into memory -- counting variable 
        sw $0, 12($sp)  # store 0 into memory -- accumulating variable
 	
 	li $v0, 4
	la $a0, L1
	syscall 
	
	li $v0, 5 #reads one integer from user and saves in t0
	syscall
	sw $v0 16($sp)
       
loop:
        lw $t6, 8($sp)
        mul $t7, $t6, $t6  #  i * i
        lw $t8, 12($sp)   #  s
        addu $t9, $t8, $t7  #  s + i*i
        sw $t9, 12($sp)  #   s= s + i*i 
        lw $t6, 8($sp)   # i 
        addu $t0, $t6, 1  # i+1
        sw $t0, 8($sp)  #  i = i + 1
        lw $t1, 16($sp) # Get the value I read in
        ble $t0, $t1, loop  #   keep iterating through the loop for input times
        
        nop   # no operation
        
        la $a0, str
        li $v0 4  #   print the first part of the resulting output.
        syscall
        nop
        
        li $v0, 1
	lw $a0, 16($sp)     #  Print out the the number that the user put in.
	syscall   
        
        la $a0, str1
        li $v0 4  #  Print out the second part of the string with newline
        syscall
        nop
        
        lw $a0, 12($sp)
        li $v0 1 #   Print the resultant number
        syscall
        
       
        lw $ra, 4($sp)
        lw $sp , ($sp)  # put backl Ra and SP
        
        li $v0, 10 
        syscall     #  exit for MAIN only
        
        
