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
	
	Grafo grafo(70);// criando o  grafo de n vértices;colocar o numero de vértices

	// adicionando as arestas,vétice1,ligado a...
	
	grafo.adicionarAresta(1, 2);
		grafo.adicionarAresta(1, 3);
			grafo.adicionarAresta(1, 4);
				grafo.adicionarAresta(1, 5);
					grafo.adicionarAresta(1, 6);
						grafo.adicionarAresta(1, 7);
							grafo.adicionarAresta(1, 8);
	grafo.adicionarAresta(2, 1);
		grafo.adicionarAresta(2, 3);
			grafo.adicionarAresta(2, 4);
				grafo.adicionarAresta(2, 5);
					grafo.adicionarAresta(2, 6);
						grafo.adicionarAresta(2, 7);
							grafo.adicionarAresta(2, 8);
							
	grafo.adicionarAresta(3, 1);
        grafo.adicionarAresta(3, 2);
		    grafo.adicionarAresta(3, 4);
		        grafo.adicionarAresta(3, 5);
		            grafo.adicionarAresta(3, 6);
					    grafo.adicionarAresta(3, 7);
		                    grafo.adicionarAresta(3, 8);
		                        
	
	grafo.adicionarAresta(4, 1);
		grafo.adicionarAresta(4, 2);
			grafo.adicionarAresta(4, 3);
				grafo.adicionarAresta(4, 5);
					grafo.adicionarAresta(4, 6);
						grafo.adicionarAresta(4, 7);
							grafo.adicionarAresta(4, 8);
    grafo.adicionarAresta(5, 1);
        grafo.adicionarAresta(5, 2);
            grafo.adicionarAresta(5, 3);
                grafo.adicionarAresta(5, 4);
                    grafo.adicionarAresta(5, 6);
                        grafo.adicionarAresta(5, 7);
                            grafo.adicionarAresta(5, 8);
    
    
	grafo.adicionarAresta(6, 1);
		grafo.adicionarAresta(6, 2);
			grafo.adicionarAresta(6, 3);
				grafo.adicionarAresta(6, 4);
					grafo.adicionarAresta(6, 5);
						grafo.adicionarAresta(6, 7);
							grafo.adicionarAresta(6, 8);
						
									
    grafo.adicionarAresta(7, 1);
    grafo.adicionarAresta(7, 2);
    grafo.adicionarAresta(7, 3);
    grafo.adicionarAresta(7, 4);
    grafo.adicionarAresta(7, 5);
    grafo.adicionarAresta(7, 6);
    grafo.adicionarAresta(7, 8);
  
    
    
    grafo.adicionarAresta(8, 1);
    grafo.adicionarAresta(8, 2);
    grafo.adicionarAresta(8, 3);
    grafo.adicionarAresta(8, 4);
    grafo.adicionarAresta(8, 5);
    grafo.adicionarAresta(8, 6);
    grafo.adicionarAresta(8, 7);
   
    
    grafo.adicionarAresta(9, 1);
     grafo.adicionarAresta(9, 2);
      grafo.adicionarAresta(9, 3);
       grafo.adicionarAresta(9, 4);
        grafo.adicionarAresta(9, 5);
         grafo.adicionarAresta(9, 6);
          grafo.adicionarAresta(9, 7);
         grafo.adicionarAresta(9, 8);
         
          
    grafo.adicionarAresta(10, 1);
    grafo.adicionarAresta(10, 2);
    grafo.adicionarAresta(10, 3);
    grafo.adicionarAresta(10, 4);
    grafo.adicionarAresta(10, 5);
    grafo.adicionarAresta(10, 6);
    grafo.adicionarAresta(10, 7);
    grafo.adicionarAresta(10, 8);
    
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	// mostrando os graus ,insere na função grafo.grauDeSaida
	
	cout << "Grau do vertice 1: " << grafo.obterGrauDeSaida(1);
	cout << "\nGrau do vertice 3: " << grafo.obterGrauDeSaida(2);
    cout << "\nGrau do vertice 4: " << grafo.obterGrauDeSaida(3);
    cout << "\nGrau do vertice 5: " << grafo.obterGrauDeSaida(4);
    cout << "\nGrau do vertice 5: " << grafo.obterGrauDeSaida(5);
    cout << "\nGrau do vertice 5: " << grafo.obterGrauDeSaida(6);
    cout << "\nGrau do vertice 5: " << grafo.obterGrauDeSaida(7);
    cout << "\nGrau do vertice 5: " << grafo.obterGrauDeSaida(8);
    cout << "\nGrau do vertice 5: " << grafo.obterGrauDeSaida(9);
    cout << "\nGrau do vertice 5: " << grafo.obterGrauDeSaida(10);
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	

	// verifica se existe vizinhos,INSERIR em existeVizinho
	
	

   if(grafo.existeVizinho(5, 1))
		printf( "\n 1 eh vizinho de 5\n");
	else
		printf( "\n1 NAO eh vizinho de 5\n");

	return 0;
}
