package aula12ex;
import java.util.Scanner;
public class Ex2 {
   
    public static void main(String[] args) {
        int notas[] = new int[3];
        for(int i=0;i<3;i++){
            System.out.print("Digite a nota "+(i+1)+": ");
            notas[i] = new Scanner(System.in).nextInt();
    }
        double media = (notas[0]+notas[1]+notas[2])/3; 
       
        if(media>=7.0)
            System.out.println("aprovado");
        else if(media>=5.0 && media<7.0)
            System.out.println("recuperacao");
        else
            System.out.println("reprovado");
    }
}    
