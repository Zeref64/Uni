.data 
buffer: .space 17 
m: .asciiz  "Askisi 5.1\n\n"
m1: .asciiz "Plhthos:"



.text 
.globl main 
main:
addi $v0,$zero,4
la $a0, m
syscall
#1
addi $v0,$zero,8      #li $v0,8
addi $a1,$zero,17 	#buffer
la $a0, buffer
syscall

addi $t0,$zero,0   # $t0 = counter 
la $t1 , buffer		#$t1 = adress of buffer
li $t3,  '\n'		#Condition for loop
lb $t2, ($t1)		#Loads the 1st character from $t1 in $t2

loop:
beq $t2,$t3,exitl
	addi $t0,$t0,1		#counter++
	addi $t1,$t1,1		#point to the next character in buffer
	lb $t2,($t1)		# get the next character
	j loop
exitl:
addi $v0,$zero,4		
la $a0, m1 
syscall 
addi $v0,$zero,1		
add $a0,$zero,$t0
syscall
addi $v0,$zero,10
syscall 
