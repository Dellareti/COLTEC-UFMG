/*definindo lista encadeada*/
struct listae{
	int info;
	int qtd ;
	struct listae *prox;
};

typedef struct listae Listae;

/*definindo lista duplamente encadeada*/
struct lista2{
	int info;
	struct lista2 *ant;
	struct lista2 *prox;
};

typedef struct lista2 Lista2;

/*Funcoes de lista encadeada*/

Listae* lst_cria();

Listae* lst_insere(Listae *l, int i);

void lst_imprime(Listae *l);

int lst_vazia(Listae *l);

Listae* lst_busca(Listae *l, int v);

Listae *lst_retira(Listae *l, int v);

void lst_libera(Listae *l);

Listae *lst_insere_ordenado(Listae *l, int v);
