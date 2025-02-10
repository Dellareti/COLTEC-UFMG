#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

	int main(){

	char s[40];

	int numVogais, i;
	char *vogais;
	
	printf("\n\n Digite uma string: \n\n");
	scanf("%[^\n]",s);
	
	vogais = "aeiouAEIOU";
	numVogais = 0;
	

	for (i = 0; s[i] != '\0'; i++) {
	char ch;
	int j;
	ch = s[i];
	

	for (j = 0; vogais[j] != '\0'; j++) {
	
	if (vogais[j] == ch) {
	
	numVogais += 1;
	
	break;
	}
    }
}
	printf("\n\n Quantidade de vogais: %d \n\n",numVogais);
 
 
	return 0;
}
