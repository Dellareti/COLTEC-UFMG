				/*lista encadeada*/
struct lista{
	int info;
	struct lista *prox;
};

typedef struct lista Lista;

				/*duplamente encadeada*/
struct lista2{
	int info;
	struct lista2 *ant;
	struct lista2 *prox;
};

typedef struct lista2 Lista2;

				/*listas circulares*/


void lcirc_imprime(Lista *l); 

Lista* lst_circular(Lista *l);

Lista *lst_comeca(Lista *l, int in);


				/*encadeada*/

Lista* lst_cria();

Lista* lst_insere(Lista *l, int i);

Lista* lst_enche(Lista *l, int i);

void lst_imprime(Lista *l);

int lst_vazia(Lista *l);

Lista* lst_busca(Lista *l, int v);

Lista *lst_retira(Lista *l, int v);

void lst_libera(Lista *l);

Lista *lst_insere_ordenado(Lista *l, int v);

int lst_igual(Lista *l1, Lista *l2);


				

			/*duplamente encadeadas*/


Lista2 *lst2_insere(Lista2 *l, int v);

Lista2 *lst2_busca(Lista2 *l, int v);

Lista2 *lst2_retira(Lista2 *l, int v);
