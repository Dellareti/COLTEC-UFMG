# interativo
	.data
	
numero: .word 	 		# número que será calculada a fatorial			 		
 	.text
 	
inicio: lw	$t0, numero	
 	beqz    $t0, zero     	
 	bltz    $t0, neg        
 	lw	$t1, numero	# $t1 recebe conteúdo de número 

loop: 	subi    $t1, $t1, 1     # subtraio $t1 em uma unidade e guardo em $t1
	beqz    $t1, print     
	mul     $t0, $t0, $t1   # multiplico $t0 por $t1 e guardo em $t0
	sw      $t0, numero     # guardo a multiplicação 
	j 	loop 		# volta para o loop 

print:  lw   	$a0, numero	# ler
        li   	$v0, 1                    
        syscall			
        j end			# salta para o final do programa

zero: 	li   	$a0, 1 		
        li   	$v0, 1                  
        syscall						
        j end			# salta para o final do programa

	.data
msg:    .asciiz  		"\n\n Numero negativo !!!"       
	.text        
neg: 	la   $a0, msg		# carrega endereço de mensagem      
        li   $v0, 4             # 4 especifica que vai imprimir uma string          
        syscall		
end:              
    
