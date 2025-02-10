package Prova1;

import java.util.Scanner;

public class Teste {
    public static void main(String[] args){
    
    Empresa dados = new Empresa();
        dados.cria_Fabrica();
                 
        int op;
        int qtd=0;
         
        do{
            System.out.println("\t Digite a opção:");
            System.out.println(" \n1 - Adicionar Bombons\n2 - Mostar Bombons\n3 - Sair \n");
            op = new Scanner(System.in).nextInt();
            
            if(op==1){
                
                dados.adiciona(qtd);
                qtd++;
            }
            
            else if(op==2){
                dados.mostraBombons(qtd);
            }
        }
        
        while(op==1||op==2);
      }   
   }
    
    
    
    
   
