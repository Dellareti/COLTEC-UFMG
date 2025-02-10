#include <stdio.h>
#include <stdlib.h>

void impar(int x){ 

	if(x%2!=0) 
	printf("\n %d \n",x); 
	x++; 
	if(x<30) 
	impar(x); 
} 

int main(){
	
	impar(0);
	
	return 0;
}
