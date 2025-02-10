#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *p;
    char c, str[30];
    int i = 0;

    printf("Entre com um nome para o arquivo:\n");
    gets(str);

    if (!(p = fopen(str,"r"))) 
		
    {   
        printf("Erro! Impossivel abrir o arquivo!\n");
        exit(1);
    }

    c = getc(p);
    while (!feof(p))
    {
		printf("Caracter %c, %d = %d\n", c, c, i);
        i++;               
        c = getc(p); 
    }

    fclose(p); 
    
    printf("O numero de caracteres do arquivo %s e' igual a %d\n", str, i);

return 0;
}
