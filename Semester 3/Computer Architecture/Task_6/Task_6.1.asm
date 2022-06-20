.data 
text1: .asciiz "Odd Number"
text2: .asciiz "Even Number"

.text 
.globl main 
main:
# --Askhsh 1--

addi $v0, $zero, 5  #Diavazw integer
syscall 
andi $t0,$v0,1      #Kanw and ton ari8mo moy  me to 0001    
beqz $t0,if1		# an einai 0 einai "even" alliws einai "odd"
	addi $v0,$zero,4
	la $a0,text1
	syscall
	j exit
	 
if1:
addi $v0,$zero,4
la $a0,text2
syscall

exit:                                    
addi $v0,$zero, 10
syscall 
