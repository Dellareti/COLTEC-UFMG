#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

	int main(){

	
	char s[20];
	
	int i, quant;
	
	quant = 0;
	printf("\n\n Digite uma string: \n\n");
	
	scanf(" \n\n %[^\n] \n\n",s);
	

	printf("\n\nString digitada: %s\n\n",s);
 
	for (i=0; s[i] != '\0' ;i++){
		char ch;
	
	ch = s[i];

		if (ch == ' '){
	
	quant += 1;
	}
}
 
	printf("\n\n Quantidade de espacos digitados e : %d \n\n",quant);
	return 0;
}


 











 

	













