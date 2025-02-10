#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct aluno{
    int telefone;
    char nome[30];
    int endereco;
};

int buscaOrdenada(int *V, int N, int elem){
    int i;
    for(i = 0; i<N; i++){
        if(elem == V[i])
            return i;//elemento encontrado
        else
            if(elem < V[i])
                return -1;//para a busca
    }
    return -1;//elemento não encontrado
}
//============================================

int buscaBinaria(int *V, int N, int elem){
    int i, inicio, meio, final;
    inicio = 0;
    final = N-1;
    while(inicio <= final){
        meio = (inicio + final)/2;
        if(elem < V[meio])
            final = meio-1;//busca na metade da esquerda
        else
            if(elem > V[meio])
                inicio = meio+1;//busca na metade da direita
            else
                return meio;
    }
    return -1;//elemento não encontrado
}
//============================================
int buscaLinearTelefone(struct aluno *V, int N, int elem){
    int i;
    for(i = 0; i<N; i++){
        if(elem == V[i].telefone)
            return i;//elemento encontrado
    }
    return -1;//elemento não encontrado
}

int buscaLinearNome(struct aluno *V, int N, char* elem){
    int i;
    for(i = 0; i<N; i++){
        if(strcmp(elem,V[i].nome)==0)
            return i;//elemento encontrado
    }
    return -1;//elemento não encontrado
}
int main(){

//    int vet[10] = {-8,-5,1,4,14,21,23,54,67,90};
//
//    if(buscaBinaria(vet,10,14) != -1)
//        printf("OK\n");
//    else
//        printf("ERRO\n");

    struct aluno V[4] = {{4123445,"Andre",43},
                         {4133345,"Bianca",51},
                         {7168743,"Carlos",71},
                         {5135435,"Daniel",34}};
    int pos;
    
	pos = buscaLinearNome(V,4,"Daniel");
    
	if(pos != -1)
        printf("Nome encontrado\n\n");
    else
        printf("Nome NAO encontrado\n\n");

	int sop;
	
	pos =	buscaLinearTelefone(V,4,5135435);
	
	 if(sop != -1)
        printf("Numero encontrado\n");
    else
        printf("Numero NAO encontrado\n");

    system("pause");
    return 0;
}
