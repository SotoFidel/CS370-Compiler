# Globals
.data

_L0:	 .asciiz	"i is: "
_L1:	 .asciiz	"\n"
_L2:	 .asciiz	"x global is: "
_L3:	 .asciiz	"\n"
_L6:	 .asciiz	"Outside of block statement, i is back to : "
_L7:	 .asciiz	"\n\n"
_L8:	 .asciiz	"conditional test: \n"
_L11:	 .asciiz	"end of conditional test\n\n"
_L12:	 .asciiz	"iteration test increment x while x <= 10\n"
_L14:	 .asciiz	"Done with x <= 10 loop\n\n"
_L15:	 .asciiz	"iteration read test. read x while x < 100\n"
_L16:	 .asciiz	"end iteration read test\n\n"
_L17:	 .asciiz	"Not operation test: \n"
_L18:	 .asciiz	"Not true is "
_L19:	 .asciiz	"\n"
_L20:	 .asciiz	"Not false is "
_L21:	 .asciiz	"\n\n\n"
_L22:	 .asciiz	"array assignment test: \n"
_L24:	 .asciiz	"end of array assignment test\n\n\n"
_L25:	 .asciiz	"i is now: "
_L26:	 .asciiz	"\n"
_L27:	 .asciiz	" x is now: "
_L28:	 .asciiz	"\n"
_L29:	 .asciiz	"Function call tests. pow() is calculates powers, powRecursive() does the same thing recursively.\n"
_L30:	 .asciiz	"Assigned powTest with pow(i, x). powTest is now: "
_L31:	 .asciiz	"\n\n"
_L32:	 .asciiz	"A[pow(2,2)] (same thing as A[4]) is: "
_L33:	 .asciiz	"\n\n"
_L34:	 .asciiz	"assigned powTest with pow(i, A[pow(2,2)]). powTest is now: "
_L35:	 .asciiz	"\n\n"
_L36:	 .asciiz	"Recursive power test: \n"
_L37:	 .asciiz	"powRecursive(2, 3) is: "
_L23:	 .asciiz	"\n"
_L13:	 .asciiz	"\n"
_L9:	 .asciiz	"x is not 0. Positive statement \n"
_L10:	 .asciiz	"x is 0. Negative statement\n"
_L4:	 .asciiz	"Local block statement. Local i is: "
_L5:	 .asciiz	"\n"
_NL:	 .asciiz	"\n"

.align 2

x:	 .space	4

.text

.globl main
pow:				# Start of function

	subu $a0, $sp, 56		# adjust stack for function setup
	sw $sp, ($a0)		
	sw $ra, 4($a0)		
	move $sp, $a0		# adjust the stack pointer


	li $a0, 0		# The expression is just a number
	move $a1, $a0		# Move contents of $a0 into $a1
	add $a0, $sp, 16		 # Identifier is a scalar

	sw $a1, ($a0)		#assign address' value


	li $a0, 1		# The expression is just a number
	move $a1, $a0		# Move contents of $a0 into $a1
	add $a0, $sp, 20		 # Identifier is a scalar

	sw $a1, ($a0)		#assign address' value



	add $a0, $sp, 12		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 32($sp)		# Store contents into temporary offset

	li $a0, 0		# The expression is just a number
	move $a1, $a0		# Move contents of $a0 into $a1
	lw $a0 32($sp)		# retrieve contents from temporary
	sle $a0, $a0, $a1		# $a0 is 1 if $a0 <= $a1. 0 otherwise

	li $t0, 0		# Load $t0 with 0 for comparison
	beq $a0, $t0, _L38		# Compare. Go to negative statement if $a0 is 0, else keep going
			#Positive statements

	li $a0, 1		# The expression is just a number

	lw $ra, 4($sp)		# restore RA
	lw $sp, ($sp)		#restore stack pointer

	jr $ra		# Return from where function was called

	j _L39		#end of positive statements

_L38:				 #Negative statements
_L40:				# Loop


	add $a0, $sp, 16		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 36($sp)		# Store contents into temporary offset

	add $a0, $sp, 12		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	move $a1, $a0		# Move contents of $a0 into $a1
	lw $a0 36($sp)		# retrieve contents from temporary
	slt $a0, $a0, $a1		 # $a0 is 1 if $a0 < $a1. 0 Otherwise

	li $t0, 0 		 # Load $t0 with 0 for comparison
	beq $a0, $t0, _L41		# Compare. Get out of loop if result if $a is 0. Otherwise keep going


	add $a0, $sp, 20		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 40($sp)		# Store contents into temporary offset

	add $a0, $sp, 8		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	move $a1, $a0		# Move contents of $a0 into $a1
	lw $a0 40($sp)		# retrieve contents from temporary
	mult $a0, $a1		#Multiply $a0 and $a1, and store the result in $LO
	mflo $a0		# Move the product from $LO into $a0

	move $a1, $a0		# Move contents of $a0 into $a1
	add $a0, $sp, 20		 # Identifier is a scalar

	sw $a1, ($a0)		#assign address' value



	add $a0, $sp, 16		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 48($sp)		# Store contents into temporary offset

	li $a0, 1		# The expression is just a number
	move $a1, $a0		# Move contents of $a0 into $a1
	lw $a0 48($sp)		# retrieve contents from temporary
	add $a0, $a0, $a1		 # Perform add operation and store the result in $a0

	move $a1, $a0		# Move contents of $a0 into $a1
	add $a0, $sp, 16		 # Identifier is a scalar

	sw $a1, ($a0)		#assign address' value

	j _L40		# Jump back to the loop conditional

_L41:				 # Exit of loop

_L39:				# End of If (or if/else) Statement


	add $a0, $sp, 20		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier


	lw $ra, 4($sp)		# restore RA
	lw $sp, ($sp)		#restore stack pointer

	jr $ra		# Return from where function was called


	lw $ra, 4($sp)		# restore RA
	lw $sp, ($sp)		#restore stack pointer

	jr $ra		# Return from where function was called


powRecursive:				# Start of function

	subu $a0, $sp, 36		# adjust stack for function setup
	sw $sp, ($a0)		
	sw $ra, 4($a0)		
	move $sp, $a0		# adjust the stack pointer



	add $a0, $sp, 12		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 16($sp)		# Store contents into temporary offset

	li $a0, 0		# The expression is just a number
	move $a1, $a0		# Move contents of $a0 into $a1
	lw $a0 16($sp)		# retrieve contents from temporary
	sne $a0, $a0, $a1		# $a0 is 1 if $a0 != $a1. 0 Otherwise

	li $t0, 0		# Load $t0 with 0 for comparison
	beq $a0, $t0, _L42		# Compare. Go to negative statement if $a0 is 0, else keep going
			#Positive statements


	add $a0, $sp, 8		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 32($sp)		# Store contents into temporary offset


	add $a0, $sp, 8		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 28($sp)		


	add $a0, $sp, 12		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 20($sp)		# Store contents into temporary offset

	li $a0, 1		# The expression is just a number
	move $a1, $a0		# Move contents of $a0 into $a1
	lw $a0 20($sp)		# retrieve contents from temporary
	sub $a0, $a0, $a1		# Perform subtraction and store the result in $a0

	sw $a0, 24($sp)		
	subu $t2, $sp, 36		# calculate the future activation record
	lw $t0 28($sp)		#load actual parameter value
	sw $t0 8($t2)		#Stick it into the formal parameter
	lw $t0 24($sp)		#load actual parameter value
	sw $t0 12($t2)		#Stick it into the formal parameter
	jal powRecursive		# jump and link to the called function

	move $a1, $a0		# Move contents of $a0 into $a1
	lw $a0 32($sp)		# retrieve contents from temporary
	mult $a0, $a1		#Multiply $a0 and $a1, and store the result in $LO
	mflo $a0		# Move the product from $LO into $a0


	lw $ra, 4($sp)		# restore RA
	lw $sp, ($sp)		#restore stack pointer

	jr $ra		# Return from where function was called

	j _L43		#end of positive statements

_L42:				 #Negative statements

	li $a0, 1		# The expression is just a number

	lw $ra, 4($sp)		# restore RA
	lw $sp, ($sp)		#restore stack pointer

	jr $ra		# Return from where function was called

_L43:				# End of If (or if/else) Statement


	lw $ra, 4($sp)		# restore RA
	lw $sp, ($sp)		#restore stack pointer

	jr $ra		# Return from where function was called


main:				# Start of function

	subu $a0, $sp, 144		# adjust stack for function setup
	sw $sp, ($a0)		
	sw $ra, 4($a0)		
	move $sp, $a0		# adjust the stack pointer


	li $a0, 0		# The expression is just a number
	move $a1, $a0		# Move contents of $a0 into $a1
	add $a0, $sp, 48		 # Identifier is a scalar

	sw $a1, ($a0)		#assign address' value


	li $a0, 5		# The expression is just a number
	move $a1, $a0		# Move contents of $a0 into $a1
	la $a0, x		 # Identifier is a global scalar

	sw $a1, ($a0)		#assign address' value

	li $v0, 4		# We will print a string
	la $a0, _L0		
	syscall		


	add $a0, $sp, 48		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	li $v0, 1		 # Print the number
	syscall		 # System call to print number

	li $v0, 4		# We will print a string
	la $a0, _L1		
	syscall		

	li $v0, 4		# We will print a string
	la $a0, _L2		
	syscall		


	la $a0, x		 # Identifier is a global scalar

	lw $a0, ($a0)		# Fetch value for identifier

	li $v0, 1		 # Print the number
	syscall		 # System call to print number

	li $v0, 4		# We will print a string
	la $a0, _L3		
	syscall		


	li $a0, 8888		# The expression is just a number
	move $a1, $a0		# Move contents of $a0 into $a1
	add $a0, $sp, 64		 # Identifier is a scalar

	sw $a1, ($a0)		#assign address' value

	li $v0, 4		# We will print a string
	la $a0, _L4		
	syscall		


	add $a0, $sp, 64		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	li $v0, 1		 # Print the number
	syscall		 # System call to print number

	li $v0, 4		# We will print a string
	la $a0, _L5		
	syscall		

	li $v0, 4		# We will print a string
	la $a0, _L6		
	syscall		


	add $a0, $sp, 48		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	li $v0, 1		 # Print the number
	syscall		 # System call to print number

	li $v0, 4		# We will print a string
	la $a0, _L7		
	syscall		

	li $v0, 4		# We will print a string
	la $a0, _L8		
	syscall		


	la $a0, x		 # Identifier is a global scalar

	lw $a0, ($a0)		# Fetch value for identifier

	li $t0, 0		# Load $t0 with 0 for comparison
	beq $a0, $t0, _L44		# Compare. Go to negative statement if $a0 is 0, else keep going
			#Positive statements
	li $v0, 4		# We will print a string
	la $a0, _L9		
	syscall		

	j _L45		#end of positive statements

_L44:				 #Negative statements
	li $v0, 4		# We will print a string
	la $a0, _L10		
	syscall		

_L45:				# End of If (or if/else) Statement

	li $v0, 4		# We will print a string
	la $a0, _L11		
	syscall		

	li $v0, 4		# We will print a string
	la $a0, _L12		
	syscall		

_L46:				# Loop


	la $a0, x		 # Identifier is a global scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 64($sp)		# Store contents into temporary offset

	li $a0, 10		# The expression is just a number
	move $a1, $a0		# Move contents of $a0 into $a1
	lw $a0 64($sp)		# retrieve contents from temporary
	sle $a0, $a0, $a1		# $a0 is 1 if $a0 <= $a1. 0 otherwise

	li $t0, 0 		 # Load $t0 with 0 for comparison
	beq $a0, $t0, _L47		# Compare. Get out of loop if result if $a is 0. Otherwise keep going

	la $a0, x		 # Identifier is a global scalar

	lw $a0, ($a0)		# Fetch value for identifier

	li $v0, 1		 # Print the number
	syscall		 # System call to print number

	li $v0, 4		# We will print a string
	la $a0, _L13		
	syscall		



	la $a0, x		 # Identifier is a global scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 68($sp)		# Store contents into temporary offset

	li $a0, 1		# The expression is just a number
	move $a1, $a0		# Move contents of $a0 into $a1
	lw $a0 68($sp)		# retrieve contents from temporary
	add $a0, $a0, $a1		 # Perform add operation and store the result in $a0

	move $a1, $a0		# Move contents of $a0 into $a1
	la $a0, x		 # Identifier is a global scalar

	sw $a1, ($a0)		#assign address' value

	j _L46		# Jump back to the loop conditional

_L47:				 # Exit of loop

	li $v0, 4		# We will print a string
	la $a0, _L14		
	syscall		

	li $v0, 4		# We will print a string
	la $a0, _L15		
	syscall		


	li $a0, 0		# The expression is just a number
	move $a1, $a0		# Move contents of $a0 into $a1
	la $a0, x		 # Identifier is a global scalar

	sw $a1, ($a0)		#assign address' value

_L48:				# Loop


	la $a0, x		 # Identifier is a global scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 72($sp)		# Store contents into temporary offset

	li $a0, 100		# The expression is just a number
	move $a1, $a0		# Move contents of $a0 into $a1
	lw $a0 72($sp)		# retrieve contents from temporary
	slt $a0, $a0, $a1		 # $a0 is 1 if $a0 < $a1. 0 Otherwise

	li $t0, 0 		 # Load $t0 with 0 for comparison
	beq $a0, $t0, _L49		# Compare. Get out of loop if result if $a is 0. Otherwise keep going
	la $a0, x		 # Identifier is a global scalar

	li $v0, 5		 # Read a number from input
	syscall		# reading a number
	sw $v0, ($a0)		 #Store the read into a memory location

	j _L48		# Jump back to the loop conditional

_L49:				 # Exit of loop

	li $v0, 4		# We will print a string
	la $a0, _L16		
	syscall		

	li $v0, 4		# We will print a string
	la $a0, _L17		
	syscall		

	li $v0, 4		# We will print a string
	la $a0, _L18		
	syscall		



	li $a0, 1		# The expression is just a number
	sw $a0, 76($sp)		# Store contents into temporary offset
	sltiu $a0, $a0, 1		#Perform not operation on value
	li $v0, 1		 # Print the number
	syscall		 # System call to print number

	li $v0, 4		# We will print a string
	la $a0, _L19		
	syscall		

	li $v0, 4		# We will print a string
	la $a0, _L20		
	syscall		



	li $a0, 0		# The expression is just a number
	sw $a0, 80($sp)		# Store contents into temporary offset
	sltiu $a0, $a0, 1		#Perform not operation on value
	li $v0, 1		 # Print the number
	syscall		 # System call to print number

	li $v0, 4		# We will print a string
	la $a0, _L21		
	syscall		

	li $v0, 4		# We will print a string
	la $a0, _L22		
	syscall		

_L50:				# Loop


	add $a0, $sp, 48		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 84($sp)		# Store contents into temporary offset

	li $a0, 10		# The expression is just a number
	move $a1, $a0		# Move contents of $a0 into $a1
	lw $a0 84($sp)		# retrieve contents from temporary
	slt $a0, $a0, $a1		 # $a0 is 1 if $a0 < $a1. 0 Otherwise

	li $t0, 0 		 # Load $t0 with 0 for comparison
	beq $a0, $t0, _L51		# Compare. Get out of loop if result if $a is 0. Otherwise keep going

	add $a0, $sp, 48		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	move $a1, $a0		# Move contents of $a0 into $a1

	add $a0, $sp, 48		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sll $t0, $a0, 2		# Shift to get to word size
	add $a0, $sp, 8		 # Identifier is a local array reference. Offset of local array
	add $a0, $a0, $t0		 # Compensate for internal offset of array

	sw $a1, ($a0)		#assign address' value



	add $a0, $sp, 48		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sll $t0, $a0, 2		# Shift to get to word size
	add $a0, $sp, 8		 # Identifier is a local array reference. Offset of local array
	add $a0, $a0, $t0		 # Compensate for internal offset of array

	lw $a0, ($a0)		# Fetch value for identifier

	li $v0, 1		 # Print the number
	syscall		 # System call to print number

	li $v0, 4		# We will print a string
	la $a0, _L23		
	syscall		



	add $a0, $sp, 48		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 92($sp)		# Store contents into temporary offset

	li $a0, 1		# The expression is just a number
	move $a1, $a0		# Move contents of $a0 into $a1
	lw $a0 92($sp)		# retrieve contents from temporary
	add $a0, $a0, $a1		 # Perform add operation and store the result in $a0

	move $a1, $a0		# Move contents of $a0 into $a1
	add $a0, $sp, 48		 # Identifier is a scalar

	sw $a1, ($a0)		#assign address' value

	j _L50		# Jump back to the loop conditional

_L51:				 # Exit of loop

	li $v0, 4		# We will print a string
	la $a0, _L24		
	syscall		


	li $a0, 12		# The expression is just a number
	move $a1, $a0		# Move contents of $a0 into $a1
	add $a0, $sp, 48		 # Identifier is a scalar

	sw $a1, ($a0)		#assign address' value



	li $a0, 2		# The expression is just a number
	sll $t0, $a0, 2		# Shift to get to word size
	add $a0, $sp, 8		 # Identifier is a local array reference. Offset of local array
	add $a0, $a0, $t0		 # Compensate for internal offset of array

	lw $a0, ($a0)		# Fetch value for identifier

	move $a1, $a0		# Move contents of $a0 into $a1
	la $a0, x		 # Identifier is a global scalar

	sw $a1, ($a0)		#assign address' value

	li $v0, 4		# We will print a string
	la $a0, _L25		
	syscall		


	add $a0, $sp, 48		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	li $v0, 1		 # Print the number
	syscall		 # System call to print number

	li $v0, 4		# We will print a string
	la $a0, _L26		
	syscall		

	li $v0, 4		# We will print a string
	la $a0, _L27		
	syscall		


	la $a0, x		 # Identifier is a global scalar

	lw $a0, ($a0)		# Fetch value for identifier

	li $v0, 1		 # Print the number
	syscall		 # System call to print number

	li $v0, 4		# We will print a string
	la $a0, _L28		
	syscall		

	li $v0, 4		# We will print a string
	la $a0, _L29		
	syscall		



	add $a0, $sp, 48		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 100($sp)		

	la $a0, x		 # Identifier is a global scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 96($sp)		
	subu $t2, $sp, 56		# calculate the future activation record
	lw $t0 100($sp)		#load actual parameter value
	sw $t0 8($t2)		#Stick it into the formal parameter
	lw $t0 96($sp)		#load actual parameter value
	sw $t0 12($t2)		#Stick it into the formal parameter
	jal pow		# jump and link to the called function

	move $a1, $a0		# Move contents of $a0 into $a1
	add $a0, $sp, 52		 # Identifier is a scalar

	sw $a1, ($a0)		#assign address' value

	li $v0, 4		# We will print a string
	la $a0, _L30		
	syscall		


	add $a0, $sp, 52		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	li $v0, 1		 # Print the number
	syscall		 # System call to print number

	li $v0, 4		# We will print a string
	la $a0, _L31		
	syscall		

	li $v0, 4		# We will print a string
	la $a0, _L32		
	syscall		




	li $a0, 2		# The expression is just a number
	sw $a0, 112($sp)		

	li $a0, 2		# The expression is just a number
	sw $a0, 108($sp)		
	subu $t2, $sp, 56		# calculate the future activation record
	lw $t0 112($sp)		#load actual parameter value
	sw $t0 8($t2)		#Stick it into the formal parameter
	lw $t0 108($sp)		#load actual parameter value
	sw $t0 12($t2)		#Stick it into the formal parameter
	jal pow		# jump and link to the called function

	sll $t0, $a0, 2		# Shift to get to word size
	add $a0, $sp, 8		 # Identifier is a local array reference. Offset of local array
	add $a0, $a0, $t0		 # Compensate for internal offset of array

	lw $a0, ($a0)		# Fetch value for identifier

	li $v0, 1		 # Print the number
	syscall		 # System call to print number

	li $v0, 4		# We will print a string
	la $a0, _L33		
	syscall		



	add $a0, $sp, 48		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 128($sp)		



	li $a0, 2		# The expression is just a number
	sw $a0, 120($sp)		

	li $a0, 2		# The expression is just a number
	sw $a0, 116($sp)		
	subu $t2, $sp, 56		# calculate the future activation record
	lw $t0 120($sp)		#load actual parameter value
	sw $t0 8($t2)		#Stick it into the formal parameter
	lw $t0 116($sp)		#load actual parameter value
	sw $t0 12($t2)		#Stick it into the formal parameter
	jal pow		# jump and link to the called function

	sll $t0, $a0, 2		# Shift to get to word size
	add $a0, $sp, 8		 # Identifier is a local array reference. Offset of local array
	add $a0, $a0, $t0		 # Compensate for internal offset of array

	lw $a0, ($a0)		# Fetch value for identifier

	sw $a0, 124($sp)		
	subu $t2, $sp, 56		# calculate the future activation record
	lw $t0 128($sp)		#load actual parameter value
	sw $t0 8($t2)		#Stick it into the formal parameter
	lw $t0 124($sp)		#load actual parameter value
	sw $t0 12($t2)		#Stick it into the formal parameter
	jal pow		# jump and link to the called function

	move $a1, $a0		# Move contents of $a0 into $a1
	add $a0, $sp, 52		 # Identifier is a scalar

	sw $a1, ($a0)		#assign address' value

	li $v0, 4		# We will print a string
	la $a0, _L34		
	syscall		


	add $a0, $sp, 52		 # Identifier is a scalar

	lw $a0, ($a0)		# Fetch value for identifier

	li $v0, 1		 # Print the number
	syscall		 # System call to print number

	li $v0, 4		# We will print a string
	la $a0, _L35		
	syscall		

	li $v0, 4		# We will print a string
	la $a0, _L36		
	syscall		

	li $v0, 4		# We will print a string
	la $a0, _L37		
	syscall		



	li $a0, 2		# The expression is just a number
	sw $a0, 140($sp)		

	li $a0, 3		# The expression is just a number
	sw $a0, 136($sp)		
	subu $t2, $sp, 36		# calculate the future activation record
	lw $t0 140($sp)		#load actual parameter value
	sw $t0 8($t2)		#Stick it into the formal parameter
	lw $t0 136($sp)		#load actual parameter value
	sw $t0 12($t2)		#Stick it into the formal parameter
	jal powRecursive		# jump and link to the called function

	li $v0, 1		 # Print the number
	syscall		 # System call to print number


	lw $ra, 4($sp)		# restore RA
	lw $sp, ($sp)		#restore stack pointer

	li $v0, 10		# Leave MAIN program 
	syscall		#leave main

