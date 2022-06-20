.data 
first: .byte 0
second: .byte 0
third: .byte 0
fourth: .byte 0
x: .word 0xabcd

.text 
.globl main
main:
lw $t0,x
addi $t1,$t1,0
addi $t2,$t2,4
loop:
bge $t1,$t2,exitl
	beqz $t1, firstl
	beq $t1,1,secondl
	beq $t1,2,thirdl
	beq $t1,3,fourthl
	j loop
	firstl: 
		addi $t1,$t1,1
		andi $t3,$t0,0xf000
		srl $t3,$t3,12
		sb $t3, first
		j loop
	secondl:
		addi $t1,$t1,1
		andi $t3,$t0,0x0f00
		srl $t3,$t3,8
		sb $t3, second
		j loop
	thirdl:
		addi $t1,$t1,1
		andi $t3,$t0,0x00f0
		srl $t3,$t3,4
		sb $t3, third
		j loop
	fourthl:
		addi $t1,$t1,1
		andi $t3,$t0,0x000f
		sb $t3, fourth
		j loop
exitl:
addi $v0,$zero,10
syscall
