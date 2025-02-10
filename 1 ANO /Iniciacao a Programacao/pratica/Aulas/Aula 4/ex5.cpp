#include <stdio.h>
     #include <stdlib.h>
      
     int main()
     {
         int x,y,z;
      
         printf("Digite os tres valores inteiros \n");
        scanf("%d %d %d", &x, &y, &z);
     
        if ((x < (y + z)) && (y < (x + z)) && (z < (x + y)))
     
            printf("Os valores %d, %d e %d formam um triangulo", x,y,z);
        else
            printf("Os valores %d, %d e %d NAO formam um triangulo", x,y,z);
        return 0;
    }
