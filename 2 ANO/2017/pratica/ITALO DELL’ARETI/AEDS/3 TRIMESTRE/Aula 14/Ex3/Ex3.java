
import java.util.Scanner;

public class Ex3 {
    public static void main(String[] args) {
        int n = new Scanner(System.in).nextInt();
        int[][] matriz = new int[n][];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matriz[i]=new int[n];
            }
        }
        
        
        for(int i=0;i<n;i++){
            matriz[i][i]=1;
            matriz[i][0]=1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<i;j++){
                if(matriz[i][j]==0)
                    matriz[i][j]=matriz[i-1][j]+matriz[i-1][j-1];
            }
        }
        
        for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        System.out.print(matriz[i][j]);
                        if(matriz[i][j]<10)
                            System.out.print("   ");
                        else if(matriz[i][j]>100)
                            System.out.print(" ");
                        else
                            System.out.print("  ");
                    }
                    System.out.println("");
        }
    }
}
