struct grafo{
	struct grafo **adjacentes;
	int n_adjacentes;
	int v;
	int estado; // 0-nao passou
				// 1-ja passou
				// 2-passou por ele e pelos adjacentes
};
typedef struct grafo Grafo;

Grafo *busca_grafo(Grafo *g,int valor);
void imprime_grafo(Grafo *g);
Grafo *cria_grafo(int valor);
Grafo *insere_como_adjacente(Grafo *g,int valor);
void conecta_vertices();
void zera_estados(Grafo *g);


//FILA DE GRAFOS
struct lista{
	Grafo *g;
	struct lista *prox;
};
typedef struct lista Lista;
typedef struct filal FilaL;

struct filal{
	Lista *ini;
	Lista *fim;
};

FilaL *fila_cria_l();
void fila_insere_l(FilaL *f, Grafo* no);
Grafo* fila_retira_l(FilaL *f);
int fila_vazia_l(FilaL *f);
void fila_libera_l(FilaL *f);
