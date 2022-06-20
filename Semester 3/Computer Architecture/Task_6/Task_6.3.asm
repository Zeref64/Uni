.data 
text1: .asciiz  "Positive number"
text2: .asciiz "Negative number"

.text 
.globl main
main: 
#	--Askhsh 3--
addi $v0, $zero, 5   	#Diavazw Arithmo                               
syscall                                                   
srl $t0,$v0,31		#Kanw shift deksia 31 theseis
			#me skopo na er8ei to bit proshmoy sthn prwth thesh(LSB)
andi $t0,$t0,1		#pernw to LSB kanontas and me 0001
beqz $t0,if1		# an einai ==0 tote Positive else Negative
	addi $v0,$zero,4
	la $a0,text2
	syscall
	j exit 
	
if1:
addi $v0,$zero,4
la $a0,text1
syscall

exit:       
addi $v0,$zero,10
syscall 
