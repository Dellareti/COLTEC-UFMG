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
       	for(i=0;i<c;i++)printf("%i  ",i);
       	putchar('\n');
        for (i=0;i<l;i++){
        	printf("%i ",i);
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
	int a,b,i,j,cont=0;
	int **grafo;
	char op;

	grafo = AlocaMatrizInt(10,10);

	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(j==i)grafo[i][j] = 0;
			else grafo[i][j] = 1;
		}
	}
	printf("Todos os 10 servidores comunicam entre si, mas nao comunicam consigo mesmos\nSegue abaixo um grafo nao orientado da situacao:\n");
	ImprimeMatrizInt(grafo,10,10);
	printf("Press enter.");
	getchar();

	do{
		system("clear");
		printf("Digite:\n1- Caso deseje verificar se existe algum problema na conexao entre algum servidor.\n2- Caso queira estabelecer uma conexao\n3- Caso queira interromper alguma conexao\n4-Sair\n");
		op=getchar();
		__fpurge(stdin);
		switch(op){
			case '1':{
				for(i=0;i<10;i++){
					for(j=0;j<10;j++){
						if(grafo[i][j]==0 && i!=j){
							printf("Exite um problema na conexao entre o servidor %i e o %i\n",i,j);
							cont++;
						}
					}
				}
				if(cont==0)
					printf("Nao foi encontrado nenhum problema\n");
				cont=0;
				break;
			}
			case '2':{
				printf("Quais os servidores?\n");
				scanf("%i%i",&a,&b);
				grafo[a][b]=1;
				break;
			}
			case'3':{
				printf("Quais os servidores?\n");
				scanf("%i%i",&a,&b);
				grafo[a][b]=0;
				break;
			}
			default:{
				if(op!='4')printf("OP nao existente\n");
				break;
			}
		}
			__fpurge(stdin);
			printf("Press enter.");
			getchar();
	}while(op!='4');
	LiberaMatrizInt(grafo,10);

}