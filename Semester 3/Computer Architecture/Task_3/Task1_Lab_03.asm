.data
value1: .byte 0
newline: .asciiz "\n\n"
string1: .asciiz "Hello\n"
string2: .asciiz "TEI\n"
buffer: .space 102

.text
.globl main
main:

#Askhsh 01

li $a0, 'a'	# a)
li $v0, 11
syscall 	

li $v0, 4 	
la $a0, newline
syscall


li $a0, 'a'	# b)
li $v0, 11
syscall		

li $a0, '\n'
li $v0, 11
syscall

li $a0, 'd'
li $v0, 11
syscall

li $v0, 4 	
la $a0, newline
syscall

li $v0, 4	# c)
la $a0, string1
syscall

li $a0, '\n'
li $v0, 11
syscall

li $v0, 4	# d)
la $a0, string1
syscall

li $v0, 4	
la $a0, string2
syscall

li $v0, 4
la $a0, newline
syscall

li $v0, 1	# e)
la $a0, 5
syscall
li $v0, 4
la $a0, newline
syscall

la $t0, value1	# f)
li $v0, 5

syscall
sb $v0, 0($t0)
lb $t1, 0($t0)

li $v0, 1
move $a0, $t1
syscall

li $v0, 4
la $a0, newline
syscall

li $v0, 8	# g)
li $a1, 102
la $a0, buffer
syscall

li $v0, 4
syscall

li $v0, 4
la $a0, newline
syscall


li $v0, 10 
syscall