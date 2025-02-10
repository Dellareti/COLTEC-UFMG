package aula12ex;
import java.util.Scanner;
public class Ex6 {
    public static void main(String[] args) {
        boolean primo=true;
       
        int numero = new Scanner(System.in).nextInt();
        
        for(int i=(numero/2);i>1;i--)
            if(numero%i==0)
               primo=false;
        if(primo)
            System.out.println("primo");
        else
            System.out.println("nao primo");
    }
}
