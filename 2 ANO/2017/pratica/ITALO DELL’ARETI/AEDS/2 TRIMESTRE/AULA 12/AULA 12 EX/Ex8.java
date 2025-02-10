package aula12ex;
import java.util.Scanner;

public class Ex8 {
    public static void main(String[] args) {
        int eleitores = 3;
        int c[] = new int[4];
        
        for(int i=0;i<4;i++)
            c[i]=0;
        int voto=0,nulo=0,branco=0;
        
        for(int i=0;i<eleitores;i++){
            voto = new Scanner(System.in).nextInt();
            if(voto == 1)
                c[0]++;
            else if(voto == 2)
                c[1]++;
            else if(voto == 3)
                c[2]++;
            else if(voto == 4)
                c[3]++;
            else if(voto == 5)
                nulo++;
            else if(voto ==6)
                branco++;
        }
       
        for(int i=0;i<4;i++){
            System.out.println("total candidato " + (i+1) + ": " + c[i]);
            System.out.println("total de nulos: " + nulo);
            System.out.println("total de brancos: " + branco);
        }   
        
        System.out.println("nulos/total = " + ((float)nulo/eleitores)*100 + "%");
        System.out.println("brancos/total = " + ((float)branco/eleitores)*100 + "%");
        System.out.println("0?");
    }
}
