package aula12ex;
import java.util.Scanner;

public class Ex1 {
    public static void main(String[] args) {
       
        System.out.print("Digite tua idade: ");
        
        int idade = new Scanner(System.in).nextInt();
        System.out.println("Voce nasceu em "+(2017-idade));
    }    
}
