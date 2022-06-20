.data
table: .ascii "0123456789abcdef"
label: .asciiz " hex" 
.text
.globl main
main:
#	--Askhsh 5--
addi $s0,$zero,255		#orio arithmou
loop:
	addi $v0, $zero, 5	#Diavazw arithmo
	syscall 
blez $v0,loop			# >0
bgt $v0,$s0,loop 		# <256 ara  (1-255)
addi $t0,$v0,0 		#Kanw save ton arithmo
andi $s1,$t0,0xf0 	#kanw and me to 1111 0000 gia na parw ta MSB ston $s1
srl $s1,$s1,4 		#kanw shift gia na pane sthn LSB thesh  1111 0000 -> 0000 1111
andi $s2,$t0,0x0f 	#pernw ta LSB me ton idio tropo ston $s2
la $a2,table
add $t1,$a2,$s1 	#Vazw ston $t1 to apotelesma ths dieuthynsh toy 
			#1ou stoixeioy + oti eixe o $s1
					
addi $v0,$zero,11
lb $a0,0($t1)		#Vazw ston $a0 to periexomeno toy $t1
syscall			#Print to 1o hex

add $t1,$a2,$s2
addi $v0,$zero,11
lb $a0,($t1)
syscall			#Print to 2o hex

addi $v0,$zero,4
la $a0,label
syscall

addi $v0,$zero,10
syscall
