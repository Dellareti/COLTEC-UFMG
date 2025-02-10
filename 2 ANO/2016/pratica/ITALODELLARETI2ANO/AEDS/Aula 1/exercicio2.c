#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct DadosAlunos{
    char nome[30];
    float notas[4];
    float media;
}aluno;

int main(){
    int a,i,j,k;
    float mediatotal;

    printf("\n\n Quantos alunos voce ira calcula ? \n\n");
    scanf("%i",&a);
    getchar();
    struct DadosAlunos *inf;

    inf = (aluno*) calloc(a,sizeof(aluno));

    for(i=0;i<a;i++){
    printf("\t Aluno %i\n\n",i+1);

    printf("\n\n Digite seu nome : \n\n");
    fgets(inf[i].nome,30,stdin);


        for(j=0;j<4;j++){
            printf("\n\n Digite a nota %i :\n\n\n",j+1);
            scanf("%f",&inf[i].notas[j]);
        }
    inf[i].media = (inf[i].notas[0] + inf[i].notas[1] + inf[i].notas[2])/3;
    printf("\n Media : %.2f \n\n\n",inf[i].media);
    getchar();
    }


    printf("\n-------------------------- ALUNOS -----------------------------------\n\n\n");

    for(k=0;k < a;k++){

    printf("Nome..........: %s",inf[k].nome);

    printf("Media.........: %.2f",inf[k].media);

    printf("\n\n");

    }


free(inf);
return 0;
}
