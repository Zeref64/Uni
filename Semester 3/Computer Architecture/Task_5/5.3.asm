.data 
arr: .word 1,15,0,-3,99,48,-17,-9,20,15 
sum: .word 0
i: .word 0 ##NOT USED
size: .word 10
.text
.globl main
main:
lw $t0,i
lw $t1,size 
lw $t2,sum 
la $t3, arr 
loop:
bge $t0,$t1,exitl
	addi $t0,$t0,1
	lw $t4, ($t3)
	add $t2,$t2,$t4
	addi $t3,$t3,4
	j loop
exitl:
sw $t2, sum
addi $v0,$zero,1
add $a0,$zero,$t2
syscall
addi $v0,$zero,10
syscall
