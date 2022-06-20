.data
value: .byte 0
string1: .asciiz "hello\n"
newline: .asciiz "\n\n"
buffer: .space 32
x: .word 0
a: .word 20
b: .word 30
c: .word 15
status: .asciiz "x="

.text
.globl main
main:

la $t0 string1 	# a)
li $v0, 11
lb $a0, ($t0) 
syscall

li $v0, 11
li $a0, '\n'
syscall

li $v0, 11
lb $a0, 1($t0) 
syscall

li $v0, 4
la $a0, newline
syscall

##la $t1, value 	# b)
##li $v0, 5
##syscall
##sb $v0, 0($t1)
##lb $t2, 0($t1)
##move $a0, $t2
##li $v0, 1
##syscall
##li $v0, 4
##la $a0, string1
##syscall

li $v0, 5
syscall
lb $a0, string1($v0)
li $v0, 11
syscall

li $v0, 4
la $a0, newline
syscall
##-------------------------------
li $v0, 8	# c)
li $a1, 32
la $a0, buffer
move $t0, $a0
syscall

lb $a0, 1($t0)
li $v0, 11
syscall

li $v0, 4
la $a0, newline
syscall

lw $t1, a	# d)
lw $t2, b
lw $t3, c
add $t5, $t1,$t2
add $t6, $t3,10
sub $t4, $t5,$t6
sw $t4, x
li $v0, 4
la $a0, status
syscall
li $v0 1
lw $a0, x
syscall

li $v0, 10 
syscall
