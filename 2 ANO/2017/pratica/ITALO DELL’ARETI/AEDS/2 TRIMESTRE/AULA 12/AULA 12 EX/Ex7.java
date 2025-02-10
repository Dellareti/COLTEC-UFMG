package aula12ex;

import java.io.IOException;
import java.util.Scanner;

public class Ex7 {
    public static class Pessoa{
        
        int idade=0;
        float peso=0;
        char sexo='0';
        void pega_dados() throws IOException{
            
            System.out.print("idade: ");
            this.idade = new Scanner(System.in).nextInt();
            System.out.print("peso: ");
            this.peso = new Scanner(System.in).nextFloat();
            System.out.print("sexo: ");
            this.sexo = (char) System.in.read();
        }
    }
    public static void main(String[] args) throws IOException {
        Pessoa grupo[] = new Pessoa[10];
        
        for(int i=0;i<10;i++)
            grupo[i] = new Pessoa();
            
        for(int i=0;i<10;i++)
            grupo[i].pega_dados();
        
        int h=0,m=0;
        float idades=0,pesos=0;
        
        for(int i=0;i<10;i++){
            if(grupo[i].sexo=='h'){
                h++;
                idades+=grupo[i].idade;
            }
            else if(grupo[i].sexo=='m'){
                m++;
                pesos+=grupo[i].peso;
            }
        }
        
        System.out.println("Tem " + h + " homens");
        System.out.println("Tem " + m + "mulheres");
        System.out.println("A media das idades dos homens e " + idades/h);
        System.out.println("A media dos pesos das mulheres e " + pesos/m);
    }
}
