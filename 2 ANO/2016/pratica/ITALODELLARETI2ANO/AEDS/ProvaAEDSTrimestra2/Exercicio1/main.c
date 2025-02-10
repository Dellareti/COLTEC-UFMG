#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hash.h"

int main (){
    srand(time(NULL));
    system("clear");

    char op, nome[20],letra,procurar[20],retira[20];
    Lista *a[42];
    int key,i,n_contatos=0;

    for(i=0;i<29;i++)
        a[i]=lst_cria();

    do{
        printf("1 - Add Passageiro.\n2 - Buscar Passageiro.\n3 - Retirar Passageiro.\nQualquer outra coisa para sair.\n\nOpção:\t");
        scanf("%c",&op);
        getchar();

        if(op=='1'){
            printf("Digite o nome de seu passageiro:\t");
            fgets(nome,20,stdin);
            key = define_key(nome);
            if(key!=-1){
                n_contatos++;
                a[key] = insere_contato(a[key],nome,key);
            }
            else
                printf("\nNome incorreto.\n");
        }
        else if(op=='2'){
            if(n_contatos==0)
                printf("\n vazio!!\n");
            else{
                printf("\nDigite o nome do passageiro que deseja buscar:\t");
                fgets(procurar,20,stdin);
                key = define_key(procurar);

                procura_contato(a[key],procurar);
            }
        }
        else if(op=='3'){
            if(n_contatos==0)
                printf("\n vazio!!\n");
            else{
                printf("\nDigite o nome do passageiro:\t");
                fgets(retira,20,stdin);
                key = define_key(retira);
                int controle=0;
                a[key] = lst_retira(a[key],key,&controle);
                if(controle==0)
                    n_contatos--;
            }
        }
        printf("Digite <enter>\n");
        getchar();
        system("clear");
    }while(op=='1'||op=='2'||op=='3');

    for(i=0;i<29;i++)
        lst_libera(a[i]);

    return 0;
}
