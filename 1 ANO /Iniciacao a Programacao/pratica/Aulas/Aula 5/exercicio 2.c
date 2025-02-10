#include <stdio.h>
int main ()
{

    int fat, i, valor;
    float total=0;

    printf("Digite um numero inteiro:\n");
    scanf("%d", &i);

    fat=i;
    valor=i;

    while(i>0)
    {
        while(fat>1)
        {
            fat--;
            valor=valor*fat;
        }
        i--;
        fat=i;
        total=total+(1.0/valor);
        valor=i;
    }

    printf("O valor e := %f\n\n", total);
    return 0;

}
