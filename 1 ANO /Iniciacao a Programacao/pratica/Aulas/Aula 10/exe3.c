#include <stdio.h>
#include <string.h>
#include <stdlib.h>
  
typedef struct DadosAlunos{
    char nome[30];
    char curso[20];
    int idade;
    float notas[3];
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
      
    printf("\n---------------------------- Cadastro de aluno ---------------------------------\n\n\n");
      
    for(i=0;i<a;i++){
    printf("\t Aluno %i\n\n",i+1);
     
    printf("\n\n Digite seu nome : \n\n");
    fgets(inf[i].nome,30,stdin);
     
    printf("\n\n Digite sua idade : \n\n");
    scanf("%i",&inf[i].idade);
    getchar();
     
    printf("\n\n Digite seu curso : \n\n");
    fgets(inf[i].curso,20,stdin);
     
     
     
        for(j=0;j<3;j++){
            printf("\n\n Digite a nota %i :\n\n\n",j+1);
            scanf("%f",&inf[i].notas[j]);
        }
    inf[i].media = (inf[i].notas[0] + inf[i].notas[1] + inf[i].notas[2])/3;
    printf("\n Media : %.2f \n\n\n",inf[i].media);
    getchar();
    }
     
     
    printf("\n--------------------------- Dados do aluno -----------------------------------\n\n\n");
     
    for(k=0;k < a;k++){ 
         
    printf("Nome..........: %s",inf[k].nome);
    printf("Curso.........: %s",inf[k].curso);
    printf("Idade.........: %d \n",inf[k].idade);
    printf("Media.........: %.2f",inf[k].media);
     
    printf("\n\n");
               
    }
     
    for(i=0;i<a;i++)
    mediatotal += inf[i].media;
      
    printf("\n-------------------------- A media total e : %.2f -----------------------------\n\n\n",mediatotal/a);
 

free(inf);
return 0;
} 
