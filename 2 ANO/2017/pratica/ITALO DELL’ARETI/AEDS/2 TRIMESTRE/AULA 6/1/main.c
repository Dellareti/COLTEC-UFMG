#include <stdio.h>
#include <stdlib.h>

int **AlocaMatrizInt(int l,int c){
        int **m;
        int i;
        m = (int**) calloc (l,sizeof(int*));
        for (i=0 ; i<l ; i++)
	        m[i] = (int*) calloc (c,sizeof(int));
        return m;
}
void ImprimeMatrizInt(int **matriz, int l, int c){
        int i, j;
        printf("   ");
       	for(i=1;i<=c;i++)printf("%i  ",i);
       	putchar('\n');
        for (i=0;i<l;i++){
        	printf("%i ",i+1);
            for (j=0;j<c;j++)
            	matriz[i][j] == -1 ? printf ("%i ", matriz[i][j]) : printf (" %i ", matriz[i][j]);
            printf ("\n");
        }
}
void LiberaMatrizInt(int **m,int l){
	int i;
	for(i=0;i<l;i++)
		free(m[i]);	
	free(m);
}

int main(){
	int v,i,j,soma=0;
	int **grafo;
	char op;

	printf("Este eh um exemplo de grafo orientado:\n  ");

	for(i=1;i<=5;i++)printf("%i  ",i);
	printf("\n1 0  1  0  0  0\n2 0  0  1  1  0\n3 0  0  0  0  0\n4 0  0  0  0  1\n5 0  0  1  0  0\n");
	printf("Qual o numero de vertices do grafo a ser criado?\n");
	scanf("%i",&v);

	grafo = AlocaMatrizInt(v,v);

	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			printf("Se a aresta (%i,%i) nao existir, digite 0\n",i+1,j+1);
			printf("Se a aresta (%i,%i) existir, digite 1\n",i+1,j+1);
			printf("Se a aresta (%i,%i) existir e a aresta (%i,%i)tambem, digite -1\n",i+1,j+1,j+1,i+1);
			scanf("%i",&grafo[i][j]);
			printf("-------------------\n");
		}
	}
	printf("O grafo inserido corresponde a:\n");
	ImprimeMatrizInt(grafo,v,v);

	for(i=0;i<v;i++){
		printf("O grau do vertice %i e == ",i+1);
		for(j=0;j<v;j++)
			if(grafo[i][j]==1)
				soma++;
		printf("%i\n",soma);
		soma=0;
	}
	LiberaMatrizInt(grafo,v);
}