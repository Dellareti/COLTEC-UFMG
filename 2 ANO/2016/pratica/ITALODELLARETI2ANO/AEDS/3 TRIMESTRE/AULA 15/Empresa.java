package Empresa;

public class Empresa {
    public static void main(String[] args){
    
      Funcionarios funcionario1 = new Funcionarios();
       funcionario1.preenche("Italo" , "info" , "1.500" , "01/09/1999" ,"MG.2424.444"); 
      
       Funcionarios funcionario2 = new Funcionarios();
        funcionario2.preenche("asd", "qulquer um", "500", "09/06/1998", "MG.3534.435");
   
    
      funcionario1.mostrar();
      funcionario2.mostrar();
   }
       
}