//Arvore Binaria

struct arv{
	int info;
	struct arv *esq;
	struct arv *dir;
};

typedef struct arv Arv;

Arv* arv_criavazia(void);
Arv* arv_cria(int valor,Arv* esq,Arv* dir);
Arv* arv_libera(Arv* a);
int arv_vazia(Arv* a);
int arv_pertence(Arv* a,int v);
void imprime_arvore(Arv *r);
void arv_imprime_preordem(Arv* a);
void arv_imprime_simetrica(Arv* a);
void arv_imprime_posordem(Arv* a);

static int max2(int a,int b);
int arv_altura(Arv *a);

//Fila de Arvores Binarias

struct lista{
	Arv *r;
	struct lista *prox;
};

typedef struct lista Lista;
typedef struct fila Fila;
typedef struct filal FilaL;

struct filal{
	Lista *ini;
	Lista *fim;
};

FilaL *fila_cria_l();
void fila_insere_l(FilaL *f, Arv* no);
Arv* fila_retira_l(FilaL *f);
int fila_vazia_l(FilaL *f);
void fila_libera_l(FilaL *f);
void fila_imprime_l(FilaL *f);

//Arvore Com Filhos Variados

struct arvvar{
	int info;
	struct arvvar *filho;
	struct arvvar *irmao;
};

typedef struct arvvar ArvVar;

ArvVar *arvv_cria(int v);
void arvv_insere(ArvVar *r,ArvVar *inserido);
void arvv_imprime(ArvVar *a);
int arvv_pertence(ArvVar *a,int v);
void arvv_libera(ArvVar *a);
int arvv_altura(ArvVar *a);
