#define N 500

typedef struct pilha {
	int n;
	int vet[N];
} Pilha;

struct lista{
	float info;
	struct lista *prox;
};
typedef struct lista Lista;

typedef struct pilha_l{
	Lista *prim;
}Pilha_l;


Pilha_l *pilha_l_cria();
void pilha_l_push(Pilha_l *p, int v);
int pilha_l_pop(Pilha_l *p);
int pilha_l_vazia(Pilha_l *p);
void pilha_l_libera(Pilha_l *p);
void pilha_l_imprime(Pilha_l *p);


Pilha *pilha_cria();
void pilha_push(Pilha *p, int v);
int pilha_pop(Pilha *p);
int pilha_vazia(Pilha *p);
void pilha_libera(Pilha *p);
void pilha_imprime(Pilha *p);
