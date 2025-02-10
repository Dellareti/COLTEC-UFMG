struct lista{
	char nome[20];
	int telefone;
	char endereco[50];
	int key;
	struct lista *prox;
};


typedef struct lista Lista;


Lista* lst_cria();
int lst_vazia(Lista *l);
void lst_libera(Lista *l);
int define_key(char nome[20]);
Lista* insere_contato(Lista *l, char nome[20], int key);
void imprime_info(Lista *l, int letra);
void procura_contato(Lista *l,char procurado[20]);
Lista *lst_retira(Lista *l, int v, int *cont);