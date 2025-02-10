typedef struct lista2{
	int info;
	struct lista2 *ant;
	struct lista2 *prox;
}Lista2;


Lista2 *lst2_insere_ordenado(Lista2 *l, int v);
void *lst2_imprime(Lista2 *l);
Lista2* lst2_busca(Lista2 *l, int v);
Lista2* lst2_retira(Lista2 *l, int v);
void *lst2_libera(Lista2 *l);