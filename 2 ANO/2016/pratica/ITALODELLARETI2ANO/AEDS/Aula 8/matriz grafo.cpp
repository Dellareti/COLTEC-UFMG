#include<stdio.h>
#include<iostream>

using namespace std;

int grafo[5][5] =
{
	{1, 1, 1, 1, 1},
	{0, 0, 1, 0, 0},
	{1, 1, 1, 1, 1},
	{0, 0, 1, 0, 1},
	{1, 0, 1, 1, 0}
};

int tem_ligacao(int v1, int v2){
	
	if(grafo[v1][v2])
		return printf("\n Existe ligacao entre eles");
	    return printf("\n Nao existe ligacao entre eles");
}

void grauVertice(){
	int i=0;
	int j=0;	
	int grau = 0;
	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(grafo[i][j] == 1)
		      grau = grau + 1;
		     printf("\n O grau do vertice %d : %d\n",i,grau);
		}
	}
	
}

int main(){
	
    tem_ligacao(0, 2);
	grauVertice();
	
	return 0;
} 
