.data 
number: .word 0
m: .asciiz  "Askisi 5.4\n\n"


.text 
.globl main 
main:
addi $v0,$zero,4
la $a0, m
syscall
#5
addi $s0,$zero,0x30		#Panw kai katw orio
addi $s1,$zero,0x39
addi $t1,$zero,0                     #counter  

addi $v0,$zero,12		#diavazw arithmo
syscall
loop1:
blt $v0,$s0,exitl1            #v0<0 
bgt $v0,$s1,exitl1          #v0>9
	beqz $t1,exitif 
		sll $t2,$t2,4
	exitif:
	addi $t1,$t1,1
	andi $t0,$v0,0xf           #0x34 - 0x30 =0x04 mono     
	or $t2,$t2,$t0                                                                                          
	addi $v0,$zero,12                                                                                  
	syscall	                                                                                                                
	j loop1 
exitl1: 

addi $s0,$zero,0
loop2:
bge $s0,$t1,exitl2
	andi $t3,$t2,0xf                        
	addi $s1,$zero,0
	loop3:
	bge $s1,$s0,exitl3  
 		sll $t4,$t3,3                #(2^3x$t3)
 		sll $t5,$t3,1               #(2^1x$t3)
 		add $t3,$t4,$t5 
 		addi $s1,$s1,1
 		j loop3
 	exitl3:
 	addi $s0,$s0,1
 	srl $t2,$t2,4
	add $t6,$t6,$t3
	j loop2
exitl2:
sw $t6, number
addi $v0,$zero,1
add $a0,$zero,$t6
syscall
addi $v0,$zero,10
syscall
