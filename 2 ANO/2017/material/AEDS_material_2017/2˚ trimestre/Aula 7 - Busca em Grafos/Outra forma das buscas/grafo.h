typedef struct grafo{
	//matriz de adjacências
	int **matriz;
	//matriz de incidencia
	int **incidencia;
	int *ligacoes;
	//vetor com grau de cada vértice
	int *graus;
	int n_vertices;
	int orientado;
	int tem_pesos;
	//orientado == 1
	//nao orientado == 0	
	//tem_pesos == 1
	//nao tem pesos == 0
}Grafo;

Grafo cria_grafo(int n_vertices,int orientacao,int pesos);
Grafo faz_ligacao(Grafo g,int a,int b,int peso);
void libera_grafo(Grafo g);
void imprime_informacoes_grafo(Grafo g);

int *recebe_copia_vet_int(int *destino,int *origem,int tam);

int **aloca_matriz_int(int m, int n);
int *aloc_vetor_int(int tam);
void imprime_matriz_int(int **m,int c,int l);


struct lista{
	int info;
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
void fila_insere_l(FilaL *f,int v);
int fila_retira_l(FilaL *f);
int fila_vazia_l(FilaL *f);
void fila_libera_l(FilaL *f);
void fila_imprime_l(FilaL *f);