.data 
buffer: .space 17 
m: .asciiz  "Askisi 5.2\n\n"

.text
.globl main 
main:
addi $v0,$zero,4
la $a0, m
syscall
#2
addi $v0,$zero,8      #Read String
addi $a1,$zero,17 	
la $a0, buffer
syscall

addi $t0,$zero,0   # $t0 = counter 
la $t1 , buffer 	#t1 = adress of buffer
li $t3,  '\n'
lb $t2, ($t1)  

loop:
beq $t2,$t3,exitl
	addi $t0,$t0,1	#Counter ++
	addi $t1,$t1,1	 #pointer $t1++
	lb $t2,($t1)	#Loads the N character from $t1 in $t2
	j loop
exitl:

#Mexri edw to programma einai idio me to 5.1
#Ara ston $t0 exw to Plhthos kai o "pointer" $t1 deixnei sto teleytaio character	
#poy exei dwsei o xrhsths
									
addi $t4,$zero,0   #$t4 = 0
loop1:			
bgt $t4,$t0, exitl1 	# N loops (0 - N "$t0")
	addi $t4,$t4,1		# $t4++
	addi $v0,$zero,11	#print character
	lb $a0, ($t1)		#reverse order
	syscall
	addi $t1,$t1,-1
	j loop1
exitl1:
addi $v0,$zero,10
syscall
