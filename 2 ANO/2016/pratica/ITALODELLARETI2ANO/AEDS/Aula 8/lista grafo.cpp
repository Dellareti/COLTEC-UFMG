#include <stdio.h>
#include <iostream>
#include <list>
#include <algorithm> 

using namespace std;

class Grafo {
	int V; 							// número de vértices
	list<int> *adj; 				// ponteiro para um array contendo as listas de adjacências

public:
	Grafo(int V); // construtor   
	void adicionarAresta(int v1, int v2);     // adiciona uma aresta no grafo

									    	// obtém o grau de saída de um dado vértice
										   // grau de saída é o número de arcos que saem de "v"
	int obterGrauDeSaida(int v); 

	int existeVizinho(int v1, int v2); // verifica se v2 é vizinho de v1
};

Grafo::Grafo(int V){
	
	this->V = V; 					// atribui o número de vértices
	adj = new list<int>[V]; 		// cria as listas
}

void Grafo::adicionarAresta(int v1, int v2){
								           // adiciona vértice v2 à lista de vértices adjacentes de v1
	adj[v1].push_back(v2);
}

int Grafo::obterGrauDeSaida(int v){       // basta retornar o tamanho da lista que é a quantidade de vizinhos
	return adj[v].size();
}

int Grafo::existeVizinho(int v1, int v2){
	
	if(find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end())
		return 1;
	return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main(){
	
	Grafo grafo(10);// criando o  grafo de n vértices;colocar o numero de vértices

	// adicionando as arestas,vétice1,ligado a...
	
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 3);
	grafo.adicionarAresta(1, 2);
	grafo.adicionarAresta(3, 1);
	grafo.adicionarAresta(3, 2);
    grafo.adicionarAresta(4, 2);
    grafo.adicionarAresta(4, 3);
    grafo.adicionarAresta(5, 1);
    grafo.adicionarAresta(5, 4);
    grafo.adicionarAresta(5, 3);
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	// mostrando os graus ,insere na função grafo.grauDeSaida
	
	printf( "\nGrau do vertice 1: ",grafo.obterGrauDeSaida(1)); 
   	printf( "\nGrau do vertice 3: "); grafo.obterGrauDeSaida(3);
 	printf( "\nGrau do vertice 4: "); grafo.obterGrauDeSaida(4);
 	printf( "\nGrau do vertice 5: "); grafo.obterGrauDeSaida(5);
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	

	// verifica se existe vizinhos,INSERIR em existeVizinho
	
	if(grafo.existeVizinho(0, 1))
		printf("\n\n1 eh vizinho de 0\n");
	else
		printf("\n\n1 NAO eh vizinho de 0\n");

	if(grafo.existeVizinho(0, 2))
		printf("2 eh vizinho de 0\n");
	else
		printf( "2 NAO eh vizinho de 0\n");

   if(grafo.existeVizinho(5, 1))
		printf("1 eh vizinho de 5\n");
	else
		printf("1 NAO eh vizinho de 5\n");

	return 0;
}