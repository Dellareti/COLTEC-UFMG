package aula12ex;
import java.util.Scanner;
public class Ex4 {
    public static void main(String[] args) {
        int resposta;
        int p=0;
        
        System.out.println("positivo =1 negativo = 0");
        System.out.println("Telefonou para a vitima?");
        resposta =  new Scanner(System.in).nextInt();
        
        if(resposta==1) p++;
        System.out.println("Esteve no local do crime?");
        resposta =  new Scanner(System.in).nextInt();
        
        if(resposta==1) p++;
        System.out.println("Mora perto da vitima?");
        resposta =  new Scanner(System.in).nextInt();
        
        if(resposta==1) p++;
        System.out.println("Devia para a vitima?");
        resposta =  new Scanner(System.in).nextInt();
        
        if(resposta==1) p++;
        System.out.println("Ja trabalhou com a vitima?");
        resposta =  new Scanner(System.in).nextInt();
        
        if(resposta==1) p++;

        switch (p) {
            case 2:
                System.out.println("suspeito");
                break;
            case 3:
            case 4:
                System.out.println("cumplice");
                break;
            case 5:
                System.out.println("assassino");
                break;
            default:
                System.out.println("inocente");
                break;
        }
    }
}
