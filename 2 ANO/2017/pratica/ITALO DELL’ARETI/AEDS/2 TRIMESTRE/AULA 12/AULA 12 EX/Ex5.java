package aula12ex;
import java.io.IOException;
import java.util.Scanner;
public class Ex5 {
   
    public static void main(String[] args) throws IOException {
        char op = (char) System.in.read();
        int litros = new Scanner(System.in).nextInt();
        float preco = 0;
        
        if(op=='A'){
            preco = (float) (litros * 2.5);
            if(litros<=20)
                preco *= 0.97; 
            else if(litros>20)
                preco *= 0.95;
        }
        
        else if(op=='G'){
            preco = (float) (litros * 2.99);
            if(litros<=20)
                preco *= 0.96;
            else if(litros>20)
                preco *= 0.94;
        }
        System.out.println("O preco a ser pago e = "+ preco);
    }
}    
