package programa;
public class Programa {
    public static void main(String[] args) {
  
//--FUNCIONARIO--------------------------------------//

        
    Funcionario meusfuncionarios ;
    meusfuncionarios = new Funcionario () ;
    
    meusfuncionarios.nome = "Lucas";
    meusfuncionarios.mostra();
    
    Funcionario f1 = new Funcionario();    
    f1.nome = "Danilo";
    f1.salario = 100;

    Funcionario f2 = new Funcionario();    
    f2.nome = "Danilo";
    f2.salario = 100;
    
    Funcionario f3 = f1;    

    if (f1 == f3) {
      System.out.println("iguais");
    } 
    else {
        System.out.println("diferentes");    
    }
    
    Funcionario a = new Funcionario();    
    a.preencher();
    Funcionario b = new Funcionario();    
    b.preencher();
    
    
    int x;
    x = a.comparar(b);
    if(x==1)
        System.out.println("iguais");
    else
        System.out.println("diferentes");
   
    }   
}