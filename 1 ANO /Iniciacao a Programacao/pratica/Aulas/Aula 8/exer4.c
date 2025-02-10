#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

int main(){

char s[40];
int i;
 

	printf("\n\n Digite uma string: \n\n");
		scanf("%[^\n]",s);


	printf("\n\n String digitada: %s \n\n",s);
 
	for (i=0; s[i] != '\0' ;i++){

	char ch;

	ch = s[i];

	if (ch == s[0]){
	s[i] = s[i] - 32;
	}
 
	if (ch == ' '){
	s[i+1] = s[i+1] - 32;
	}
}
	printf("\n\n String digitada concertada: %s  \n\n",s);
 
 
	return 0;
}

