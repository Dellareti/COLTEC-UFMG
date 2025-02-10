package triangulopascal;

import java.util.Scanner;

public class TrianguloPascal {
   
    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
        System.out.println(" Digite o numero de filas de para o triangulo de pascal:\n");
        int NumeroFilas =sc.nextInt();
       System.out.println("\n");
        
        int[] a = new int[1];
        for (int i = 1; i <= NumeroFilas; i++) {
            int[] x = new int[i];
            for (int j = 0; j < i; j++) {
                if (j == 0 || j == (i - 1)) {
                    x[j] = 1;
                } else {
                    x[j] = a[j] + a[j - 1];
                }
                System.out.print(x[j] + " ");
            }
            a = x;
            System.out.println();
        }
    }
}
