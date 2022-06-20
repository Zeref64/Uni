.data 
text1: .asciiz  "Den einai pollaplasio toy 4"
text2: .asciiz "Einai pollaplasio tou 4"
.text 
.globl main
main: 

# --Askhsh 2--
addi $v0, $zero, 5	#Diavazw integer
syscall 

andi $t0,$v0,3		#Kanw and ton ari8mo mou
 			#me to 0011 gia na parw ta 2 LS-bits 
beqz $t0,if1		# an ta 2 LSbit toy t1 == 0 tote einai pollaplasio toy 4
	addi $v0,$zero,4 
	la $a0,text1
	syscall
	j exit 
if1:
addi $v0,$zero,4
la $a0,text2
syscall
exit:
addi $v0,$zero,10
syscall 
