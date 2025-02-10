package aula12ex;
import java.util.Scanner;
public class Ex3 {
  
    public static void main(String[] args) {
        int ano = new Scanner(System.in).nextInt();
       
        if(ano%100==0 && ano%400!=0)
            System.out.println("nao");
        else if(ano%4==0)
                System.out.println("Ano bissexto");
    }
}    
