 
#include<stdlib.h>
#include<stdio.h>

main()
{
    int n,num,fat;
    printf("\n\nDigite um valor para ser calculado: \n\n");
    scanf("%d",&num);
    if(num>=0)
    {
           fat=1;
           n=num;
           while(n>0)
           {
                     fat*=n;    
                     n--;
           }
           printf("\n\n %d!=%d\n\n",num,fat);
    }
    else printf("\n\nO calculo do fatorial se aplica somene aos numeros naturais.\n\n");
	return 0;
}
