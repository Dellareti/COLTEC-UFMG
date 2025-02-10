#include <stdio.h>
#include <string.h>

void func(char s[100] , int *vogal , int *conso){

	int i,tam;
	int a=0, b=0;
	
	tam = strlen(s);

	for (i = 0 ; i < tam ; i++){
		if (isalpha(s[i])){
			if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
				a++;
			}
			else {
				b++;
			}
		}
	}

	*vogal = a;
	*conso = b;

}

int main (){

	
	char s[100];
	int v=0, c=0;

	printf ("Digite uma string.\n");
	fgets(s,100,stdin);

	func(s,&v,&c);

	printf ("Vogais = %d \nConsoantes = %d\n", v, c);

	printf("bOA prOvA ");
return 0;

}
