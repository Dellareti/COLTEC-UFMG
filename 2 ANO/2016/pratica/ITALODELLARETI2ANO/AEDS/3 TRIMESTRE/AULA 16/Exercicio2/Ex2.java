package Aula;


public class Ex2 {
    
     public static void main(String[] args) {
        int[] numeros = new int []{1,2,3,4,4,5,6,7,8,9};
        
        Estatistica s = new Estatistica();
        
        System.out.println(" A moda é : \n"+ s.moda(numeros));
        System.out.println(" A mediana é \n:" + s.mediana(numeros));
        System.out.println(" A media é : \n" + s.media(numeros));
        
    }
}
