#define N 100

typedef struct fila2{
	int n;
	int ini;
	float vet[N];
}Fila2;

typedef struct lista{
	float info;
	struct lista *prox;
}Lista;

typedef struct fila2L{
	Lista *ini;
	Lista *fim;
}Fila2L;


Fila2 *fila2_cria();
void fila2_insere_ini(Fila2 *f, float v);
void fila2_insere_fim(Fila2 *f, float v);
float fila2_retira_ini(Fila2 *f);
float fila2_retira_fim(Fila2 *f);
int fila2_vazia(Fila2 *f);
void fila2_libera(Fila2 *f);
void fila2_imprime_vet(Fila2 *f);


Fila2L *fila2_cria_L();
void fila2_insere_ini_L(Fila2L *f, float v);
void fila2_insere_fim_L(Fila2L *f, float v);
float fila2_retira_ini_L(Fila2L *f);
float fila2_retira_fim_L(Fila2L *f);
int fila2_vazia_L(Fila2L *f);
void fila2_libera_L(Fila2L *f);
void fila2_imprime_L(Fila2L *f);