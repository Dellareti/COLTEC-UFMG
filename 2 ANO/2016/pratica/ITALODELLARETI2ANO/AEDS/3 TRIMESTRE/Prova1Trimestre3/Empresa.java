
package Prova1;

import java.util.Scanner;
 
  class Empresa {
    String cnpj;
    Bombom[] bombons = new Bombom[3];
 
    void cria_Fabrica(){
       
        System.out.println("Digite o cnpj:");
        this.cnpj = new Scanner(System.in).next();
     
        for(int i=0;i<3;i++){
            bombons[i] = new Bombom();
        }
    }
     
    void adiciona(int qtd){
        Bombom b = new Bombom();
        
        if(qtd==this.bombons.length){ //realocar
            Bombom[] bombons2 = new Bombom[qtd*2];     
            System.arraycopy(bombons,0,bombons2,0,this.bombons.length);
            bombons = bombons2;
        }
        
        b.preencher();
        this.bombons[qtd] = b;
    }
 
    void mostraBombons(int qtd){
        for(int i=0;i<qtd;i++){
            System .out . println ("Bombom : " + i);
            this.bombons[i].mostra();
        }
    }
}

