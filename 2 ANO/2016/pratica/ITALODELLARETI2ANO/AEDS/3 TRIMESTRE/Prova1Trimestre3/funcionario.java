package Prova1;
import java.util.Scanner;

    
    class Bombom {
        
    String sabor ;
    String codigo ;
    String ingre1;
    String ingre2;
    String ingre3;
    String ingre4;
    int fabrica; 
    
     
    void mostra(){
        
        System.out.println("\n\nBombon:\n");
        
        System.out.println("\n Fabrica :" + this.fabrica);
        System.out.println("Sabor:" + this.sabor);
        System.out.println("Ingrediente 1:" + this.ingre1);
        System.out.println("Ingrediente 2:" + this.ingre2);
        System.out.println("Ingrediente 3:" + this.ingre3);
        System.out.println("Ingrediente 4:" + this.ingre4);
        System.out.println("codigo:" + this.codigo);
      
    }
     
    void preencher(){
      
        
        System.out.println("Digite Qual fabrica esta o bombom ");
        System.out.println(" 1 para Fabrica 1, 2 para Fabrica 2, 3 para Fabrica 3 ");
        
        this.fabrica = new Scanner(System.in).nextInt(fabrica); 
        
        System.out.println("Digite o sabor:");
        this.sabor = new Scanner(System.in).next();
        
        System.out.println("Digite os ingrediente 1:");
        this.ingre1 = new Scanner(System.in).next();
        
        System.out.println("Digite os ingredientes 2:");
        this.ingre2 = new Scanner(System.in).next();
        
        System.out.println("Digite os ingredientes 3:");
        this.ingre3 = new Scanner(System.in).next();
        
        System.out.println("Digite os ingredientes 4:");
        this.ingre4 = new Scanner(System.in).next();  
        
        System.out.println("Digite o codigo:");
        this.codigo = new Scanner(System.in).next();
     
         
         
         
         
         
     }
    }
          
    

