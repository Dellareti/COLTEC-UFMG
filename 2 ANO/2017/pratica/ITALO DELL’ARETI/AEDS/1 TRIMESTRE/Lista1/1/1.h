typedef struct lista{
	int info;
	struct lista *prox;
}Lista;


void lst_imprime_rec(Lista *l);
Lista* lst_insere(Lista *l, int i);
Lista *lst_retira_rec(Lista *l,int v);
void lst_libera_rec(Lista *l);