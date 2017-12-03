#include <iostream>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo {

private:
    // Numero de vertices
    int V; 

	// Ponteiro para um array contendo as listas de adjacencias
	list<pair<int, int> > * adj;

public:

	// Construtor
	Grafo(int V){
        
        // Atribui o numero de vertices
        this->V = V; 

	    // Cria as listas onde cada lista e uma lista de pairs,
		// Cada pair e formado pelo vértice destino e o custo
		adj = new list<pair<int, int> >[V];
	}

	// Adiciona uma aresta ao grafo de v1 a v2
	void addAresta(int v1, int v2, int custo) {
		adj[v1].push_back(make_pair(v2, custo));
	}

	// Algoritmo de Dijkstra
	int dijkstra(int orig, int dest) {
		// Vetor de distancias
		int dist[V];

		/*
		   Vetor de visitados serve para caso o vertice ja tenha sido
		   expandido (visitado), nao expandir mais
		*/
		int visitados[V];

		// Fila de prioridades de pair (distancia, vértice)
		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// Inicia o vetor de distancias e visitados
		for(int i = 0; i < V; i++){
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		// A distancia de orig para orig e 0
		dist[orig] = 0;

		// Insere na fila
		pq.push(make_pair(dist[orig], orig));

		// Loop do algoritmo
		while(!pq.empty()){
            // Extrai o pair do topo
			pair<int, int> p = pq.top(); 
            
            // Obtem o vertice do pair
            int u = p.second; 
            
            // Remove da fila
            pq.pop(); 

			// Verifica se o vertice nao foi expandido
			if(visitados[u] == false){
				// Marca como visitado
				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				// Percorre os vertices "v" adjacentes de "u"
				for(it = adj[u].begin(); it != adj[u].end(); it++){
					// Obtem o vertice adjacente e o custo da aresta
					int v = it->first;
					int custo_aresta = it->second;

					// Relaxamento (u, v)
					if(dist[v] > (dist[u] + custo_aresta)){
						// Atualiza a distancia de "v" e insere na fila
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		// Retorna a distancia minima ate o destino
		return dist[dest];
	}
};

int main(int argc, char *argv[]){
	
	Grafo g(6);
	
	//g.addAresta(VerticeX,VerticeY, distância)
	g.addAresta(1, 2, 15);
	g.addAresta(1, 3, 9);
	g.addAresta(2, 4, 2);
	g.addAresta(3, 2, 4);
	g.addAresta(3, 4, 3);
	g.addAresta(4, 5, 6);
	g.addAresta(4, 6, 21);
	g.addAresta(5, 6, 7);

    // Qual o menor caminho entre os vertices 1 e 6?
	cout << g.dijkstra(1, 6) << endl;

	return 0;
}
