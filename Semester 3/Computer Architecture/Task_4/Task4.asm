.data
x: .word 0
y: .word 0
m: .asciiz "Askisi 4\n\n"
m1: .asciiz "Non Zero\n"
m2: .asciiz "Zero\n"
negative: .asciiz "Non possitive\n"
positive: .asciiz "Possitive\n"
m5: .asciiz "x:"
m6: .asciiz "y:" 
m7: .asciiz "x:5\ny:4\n"

.text
.globl main
main:
li $v0, 4
la $a0, m
syscall
#1
li $v0, 5
syscall
sw $v0, x
lw $t1, x
beq $t1,$zero,l1
	li $v0, 4
	la $a0, m1
	syscall 
	j exit1
l1:
	li $v0, 4
	la $a0, m2
	syscall
exit1:

#2
li $v0, 5
syscall 
sw $v0, x
lw $t1, x
blez $t1,l2
	li $v0, 4
	la $a0, positive
	syscall
	j exit2
l2:
	li $v0, 4
	la $a0, negative
	syscall
exit2:

#3
addi $t0,$zero, 0
addi $t1,$zero,5
loop1:
bge $t0,$t1,exitloop1
	li $a0, '*'
	li $v0, 11
	syscall
	addi $t0,$t0,1
	j loop1
exitloop1:
li $v0, 11
li $a0, '\n'
syscall

#4
li $v0, 5
syscall
sw $v0, x
lw $t1,x
addi $t0,$zero,0
loop2:
bge $t0,$t1,exitloop2
	li $v0, 11
	li $a0, '*'
	syscall
	addi $t0,$t0,1
	j loop2
exitloop2: 
li $v0, 11
li $a0, '\n'
syscall
#5
li $v0, 4
la $a0, m7
syscall
addi $t0,$zero,0
addi $t2,$zero,5
addi $t3,$zero,4
loop3:
bge $t0,$t2,exitloop3
	addi $t1,$zero,0
	loop4:
	bge $t1,$t3,exitloop4
		li $v0,11
		li $a0, '*'
		syscall
		addi $t1,$t1,1
		j loop4
	exitloop4:
	li $v0, 11
	li $a0, '\n'
	syscall
	addi $t0,$t0,1
	j loop3
exitloop3:
li $v0, 11
li $a0, '\n'
#6
li $v0,4    
la $a0, m5
syscall 
li $v0, 5
syscall
sw $v0, x
li $v0, 4
la $a0, m6  
syscall
li $v0, 5
syscall
sw $v0, y
li $v0, 11
li $a0, '\n'
addi $t0,$zero,0
lw $t2, x
lw $t3, y
loop5:
bge $t0,$t2,exitloop5
	addi $t1,$zero,0
	loop6:
	bge $t1,$t3,exitloop6
		li $v0, 11
		li $a0, '*'
		syscall
		addi $t1,$t1,1
		j loop6
	exitloop6:
	li $v0, 11
	li $a0, '\n'
	syscall
	addi $t0,$t0,1
	j loop5
exitloop5:
#end
li $v0, 10
syscall
