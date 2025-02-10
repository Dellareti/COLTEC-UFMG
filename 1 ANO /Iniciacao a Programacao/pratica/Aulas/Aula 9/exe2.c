#include <stdio.h>
#include <stdlib.h>


int  main(void)	{


	int **m;
	int i,k,soma=0,l,c;

	printf("\n\n Digite as dimensoes da sua matriz,primeiro linhas e depois colunas : \n\n");
	scanf("%d %d",&l,&c);
	

	//alocacao

	m = (int **)malloc(l*sizeof(int*));
	for(i=0;i<c;i++){		
		m[i] = (int *)malloc(c*sizeof(int));
	}
	
	
	printf("\n\n Digite os valores de sua matriz : \n\n");
			
	for(i=0;i<l;i++){
		for(k=0;k<c;k++){
			scanf("%d",&m[i][k]);
				soma = soma + m[i][k];
		}
	}


 
	printf("\n\n A soma dos vetores e : %d  \n\n",soma);

	free(m);
	

	return 0;

}
