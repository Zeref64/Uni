.data 

.text 
.globl main 
main:
#	--Askhsh 4--
addi $s0,$zero,15		#orio arithmou
loop:
	addi $v0, $zero, 5	#Diavazw arithmo
	syscall 
bltz $v0,loop
bgt $v0,$s0,loop     	#Elegxw an einai >=0 & <=15
addi $t0,$v0,0		#Kanw save ton arithmo ston $t0

addi $s0,$zero,0	#Counter 
addi $s1,$zero,4     	#Orio gia to loop
loop1:               
bge $s0,$s1,exit 		#Kanw 4 loop
	andi $t1,$t0,8 		#Kanw and me to 1000  gia na parw to 4o psifio ston $t1
	sll $t0,$t0,1 		#Shift mia thesi gia na parw to epomeno sto next loop
	srl $t1,$t1,3          #kanw shift to psifio sthn thesh toy LSB gia na emfanizei mono 0 h 1      
	addi $v0,$zero,1	#kai to emfanizw ka8e fora
	add $a0,$zero,$t1
	syscall
	
	addi $s0,$s0,1		#Counter ++
	j loop1
exit:
addi $v0,$zero, 10
syscall
    
