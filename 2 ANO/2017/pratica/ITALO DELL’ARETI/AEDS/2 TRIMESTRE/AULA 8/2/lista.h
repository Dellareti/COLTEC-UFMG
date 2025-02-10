typedef struct{
	char nome[30];
	char telefone[9];
	char endereco[30];
}Contato;

struct lista{
	Contato contato;
	struct lista *prox;
};

typedef struct lista Lista;

Lista* lst_cria();//ok

Lista* lst_insere(Lista *l,char nome[],char tel[],char end[]);

void lst_imprime(Lista *l);//ok

int lst_vazia(Lista *l);//ok

void lst_libera(Lista *l);//ok