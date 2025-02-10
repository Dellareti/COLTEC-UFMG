#recursivo

.data
	promptmensagem: .asciiz "\n\n Digite o numero do fatorial : "
	resultado: .ascii "\n\n O fatorial e :"
	numero : .word 0
	pergunta: .word 0
.text 
	.globl main
	main:

#ler
	li $v0,4
	la $a0,promptmensagem	
	syscall

	li $v0,5	
	syscall 

	sw $v0,numero
	
#chamar fatorial

	lw $v0,numero
	jal  fatorial 

	sw $v0 pergunta
	
#displays 

	li $v0,4
	la $a0,resultado
	syscall
	
	li $v0,1
	lw $a0,pergunta
	syscall 
	

	li $v0,10
	syscall
	
.globl 	fatorial
fatorial:

	subu $sp,$sp,8
	sw $ra,($sp)
	sw $s0,4($sp)
	


	li $v0,1
	beq $a0,0,prontoFat
	
# fatorial (numero -1)

	move $s0,$a0
	sub $a0,$a0,1
	jal fatorial


	mul $v0,$s0,$v0
	
		prontoFat:
		lw $ra,($sp)
		lw $s0,4($sp)	
		addu $sp,$sp,8
		
		jr $ra 
			
	
	
	
