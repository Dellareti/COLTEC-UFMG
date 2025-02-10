typedef struct aluno{ 	//coisas do aluno
	   int num; 		// identificador do aluno
	   char nome[50]; 	// nome do aluno
	   int cola;		// 1 = cola e 2 = nao cola 
}
Aluno;

int **cria_matriz(int **G, int x, int y, int n); //funcao para criar_sala

void next_color(int **G, int x[], int k); //funcao aux para coloracao do grafo

Aluno *cria_ficha(Aluno *a1, int n); //cria a ficha de alunos

void cria_sala(int k, Aluno *sla, Aluno *a1, int n, int x[]); //cria a sala de acordo com a coloracao

void corrige_erros(Aluno *sla, Aluno *a1, int n); //corrige erros deixados pela funcao cria_sala

void imprime_lista(Aluno *a1, int n); // imprime lista de chamada (numero e nome)

void mapeia_sala(Aluno *a1, int n, int **rep, int x,int y); //mapeia a matriz usada para representar a sala

void imprime_sala(int **rep, int x, int y); // imprime configuração da sala

void colore_grafo(int **grafo, int *cores, int n); //funcao para coloracao do grafo

char getch();
