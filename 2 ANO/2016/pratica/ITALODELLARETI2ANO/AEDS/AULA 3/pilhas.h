#define N 500

typedef struct pilha {
	int n;
	char vet[N];
} Pilha;

Pilha *pilha_cria();
void pilha_push(Pilha *p, char v);
char pilha_pop(Pilha *p);
int pilha_vazia(Pilha *p);
void pilha_libera(Pilha *p);
