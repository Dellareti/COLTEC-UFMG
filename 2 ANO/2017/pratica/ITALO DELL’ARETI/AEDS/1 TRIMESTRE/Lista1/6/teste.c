#include <stdio.h>

int TTT(int x[],int n){
	if(n==0)	
		return 0;
	if(x[n]>0)
		return x[n] + TTT(x,n-1);
	else
		return TTT(x,n-1);
}

int main(){
	int x[4]={1,2,-1,1};
	int r;
	r=TTT(x,4);
	printf("%i",r);
}
