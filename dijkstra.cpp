/********************************************************
 	* David Sobrinho Camurca			*
 	* Implementacao algoritmo de Dijkstra com C++	*
 	* Analise de Algoritmos: Metodo Guloso		*
 	* Professor: Dr. Rainer Xavier Amorim		*
 	* FUCAPI - 05/12/2017 - Manaus AM		*
	* Engenharia de Software			*
*********************************************************/

#include <iostream>
#include <list>
#include <queue>
#define INFINITO 10000000
#include <ctime>

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
	
	// T1 - Grafo g(9);
	// T2 - Grafo g(44);
	Grafo g(5);
	//g.addAresta(VerticeX,VerticeY, distância)

	/* T1
		g.addAresta(0, 2, 6);
		g.addAresta(0, 1, 4);
		g.addAresta(0, 3, 13);
		g.addAresta(1, 2, 2);
		g.addAresta(1, 4, 10);
		g.addAresta(1, 3, 9);
		g.addAresta(2, 5, 2);
		g.addAresta(2, 4, 7);
		g.addAresta(3, 6, 2);
		g.addAresta(5, 4, 5);
		g.addAresta(5, 7, 1);
		g.addAresta(5, 8, 3);
		g.addAresta(6, 8, 1);
		g.addAresta(7, 4, 4);
		g.addAresta(7, 6, 3);
		g.addAresta(7, 8, 2);
	*/	
	

	/* T2
		g.addAresta(0, 1, 3);
		g.addAresta(0, 21, 7);
		g.addAresta(1, 20, 7);
		g.addAresta(1, 2, 5);
		g.addAresta(2, 19, 3);
		g.addAresta(2, 3, 7);
		g.addAresta(3, 4, 1);
		g.addAresta(3, 18, 5);
		g.addAresta(4, 5, 11);
		g.addAresta(4, 17, 1);
		g.addAresta(5, 6, 11);
		g.addAresta(5, 16, 1);
		g.addAresta(6, 7, 1);
		g.addAresta(6, 15, 7);
		g.addAresta(7, 8, 3);
		g.addAresta(7, 14, 1);
		g.addAresta(8, 9, 5);
		g.addAresta(8, 13, 1);
		g.addAresta(9, 10, 11);
		g.addAresta(9, 12, 5);
		g.addAresta(10, 11, 1);
		g.addAresta(11, 32, 1);
		g.addAresta(12, 11, 7);
		g.addAresta(12, 31, 1);
		g.addAresta(13, 12, 3);
		g.addAresta(13, 30, 11);
		g.addAresta(14, 13, 11);
		g.addAresta(14, 29, 3);
		g.addAresta(15, 14, 7);
		g.addAresta(15, 28, 1);
		g.addAresta(16, 15, 5);
		g.addAresta(16, 27, 3);
		g.addAresta(17, 16, 5);
		g.addAresta(17, 26, 11);
		g.addAresta(18, 17, 3);
		g.addAresta(18, 25, 2);
		g.addAresta(19, 18, 2);
		g.addAresta(19, 24, 11);
		g.addAresta(20, 19, 11);
		g.addAresta(20, 23, 1);
		g.addAresta(21, 20, 7);
		g.addAresta(21, 22, 11);
		g.addAresta(22, 23, 1);
		g.addAresta(22, 44, 5);
		g.addAresta(23, 43, 11);
		g.addAresta(23, 24, 7);
		g.addAresta(24, 25, 11);
		g.addAresta(24, 42, 1);
		g.addAresta(25, 26, 3);
		g.addAresta(25, 41, 3);
		g.addAresta(26, 27, 1);
		g.addAresta(26, 40, 1);
		g.addAresta(28, 29, 1);
		g.addAresta(28, 38, 1);
		g.addAresta(29, 30, 1);
		g.addAresta(29, 37, 11);
		g.addAresta(30, 31, 3);
		g.addAresta(30, 36, 5);
		g.addAresta(31, 32, 7);
		g.addAresta(31, 35, 11);
		g.addAresta(32, 34, 1);
		g.addAresta(35, 34, 1);
		g.addAresta(36, 35, 1);
		g.addAresta(37, 36, 7);
		g.addAresta(38, 37, 3);
		g.addAresta(39, 38, 1);
		g.addAresta(40, 39, 3);
		g.addAresta(41, 40, 1);
		g.addAresta(42, 41, 5);
		g.addAresta(43, 42, 11);
		g.addAresta(44, 43, 3);
	*/
	

	/* T3
		g.addAresta(0, 1, 3);
		g.addAresta(0, 21, 7);
		g.addAresta(1, 20, 7);
		g.addAresta(1, 2, 5);
		g.addAresta(2, 19, 3);
		g.addAresta(2, 3, 7);
		g.addAresta(3, 4, 1);
		g.addAresta(3, 18, 5);
		g.addAresta(4, 5, 11);
		g.addAresta(4, 17, 1);
		g.addAresta(5, 6, 11);
		g.addAresta(5, 16, 1);
		g.addAresta(6, 7, 1);
		g.addAresta(6, 15, 7);
		g.addAresta(7, 8, 3);
		g.addAresta(7, 14, 1);
		g.addAresta(8, 9, 5);
		g.addAresta(8, 13, 1);
		g.addAresta(9, 10, 11);
		g.addAresta(9, 12, 5);
		g.addAresta(10, 11, 1);
		g.addAresta(11, 32, 1);
		g.addAresta(12, 11, 7);
		g.addAresta(12, 31, 1);
		g.addAresta(13, 12, 3);
		g.addAresta(13, 30, 11);
		g.addAresta(14, 13, 11);
		g.addAresta(14, 29, 3);
		g.addAresta(15, 14, 7);
		g.addAresta(15, 28, 1);
		g.addAresta(16, 15, 5);
		g.addAresta(16, 27, 3);
		g.addAresta(17, 16, 5);
		g.addAresta(17, 26, 11);
		g.addAresta(18, 17, 3);
		g.addAresta(18, 25, 2);
		g.addAresta(19, 18, 2);
		g.addAresta(19, 24, 11);
		g.addAresta(20, 19, 11);
		g.addAresta(20, 23, 1);
		g.addAresta(21, 20, 7);
		g.addAresta(21, 22, 11);
		g.addAresta(22, 23, 1);
		g.addAresta(22, 44, 5);
		g.addAresta(23, 43, 11);
		g.addAresta(23, 24, 7);
		g.addAresta(24, 25, 11);
		g.addAresta(24, 42, 1);
		g.addAresta(25, 26, 3);
		g.addAresta(25, 41, 3);
		g.addAresta(26, 27, 1);
		g.addAresta(26, 40, 1);
		g.addAresta(28, 29, 1);
		g.addAresta(28, 38, 1);
		g.addAresta(29, 30, 1);
		g.addAresta(29, 37, 11);
		g.addAresta(30, 31, 3);
		g.addAresta(30, 36, 5);
		g.addAresta(31, 32, 7);
		g.addAresta(31, 35, 11);
		g.addAresta(32, 34, 1);
		g.addAresta(34, 58, 1);
		g.addAresta(35, 34, 1);
		g.addAresta(35, 56, 1);
		g.addAresta(36, 35, 1);
		g.addAresta(36, 55, 11);
		g.addAresta(37, 36, 7);
		g.addAresta(37, 52, 11);
		g.addAresta(37, 53, 5);
		g.addAresta(37, 54, 3);
		g.addAresta(38, 37, 3);
		g.addAresta(38, 51, 1);
		g.addAresta(39, 38, 1);
		g.addAresta(39, 50, 1);
		g.addAresta(40, 39, 3);
		g.addAresta(40, 49, 1);
		g.addAresta(41, 40, 1);
		g.addAresta(41, 48, 11);
		g.addAresta(42, 41, 5);
		g.addAresta(42, 47, 1);
		g.addAresta(43, 42, 11);
		g.addAresta(43, 46, 3);
		g.addAresta(44, 43, 3);
		g.addAresta(44, 45, 7);
		g.addAresta(45, 46, 1);
		g.addAresta(45, 72, 5);
		g.addAresta(46, 47, 1);
		g.addAresta(46, 71, 11);
		g.addAresta(47, 48, 5);
		g.addAresta(47, 70, 5);
		g.addAresta(48, 49, 3);
		g.addAresta(48, 69, 7);
		g.addAresta(49, 50, 7);
		g.addAresta(49, 68, 5);
		g.addAresta(50, 51, 3);
		g.addAresta(50, 67, 11);
		g.addAresta(51, 52, 3);
		g.addAresta(51, 66, 7);
		g.addAresta(52, 53, 11);
		g.addAresta(52, 65, 5);
		g.addAresta(53, 54, 1);
		g.addAresta(53, 64, 11);
		g.addAresta(54, 55, 1);
		g.addAresta(54, 63, 1);
		g.addAresta(55, 56, 3);
		g.addAresta(55, 62, 3);
		g.addAresta(56, 57, 1);
		g.addAresta(56, 61, 7);
		g.addAresta(57, 58, 1);
		g.addAresta(57, 60, 3);
		g.addAresta(58, 59, 5);
		g.addAresta(59, 85, 1);
		g.addAresta(60, 59, 7);
		g.addAresta(60, 85, 7);
		g.addAresta(61, 60, 5);
		g.addAresta(61, 84, 3);
		g.addAresta(62, 61, 5);
		g.addAresta(62, 83, 7);
		g.addAresta(63, 62, 7);
		g.addAresta(63, 82, 5);
		g.addAresta(64, 63, 7);
		g.addAresta(64, 81, 3);
		g.addAresta(65, 64, 1);
		g.addAresta(65, 80, 7);
		g.addAresta(66, 65, 3);
		g.addAresta(66, 79, 1);
		g.addAresta(67, 66, 5);
		g.addAresta(67, 78, 5);
		g.addAresta(68, 67, 3);
		g.addAresta(68, 77, 11);
		g.addAresta(69, 68, 7);
		g.addAresta(69, 76, 3);
		g.addAresta(70, 69, 1);
		g.addAresta(70, 75, 11);
		g.addAresta(71, 70, 3);
		g.addAresta(71, 74, 3);
		g.addAresta(72, 71, 11);
		g.addAresta(72, 73, 1);
		g.addAresta(73, 74, 7);
		g.addAresta(73, 98, 11);
		g.addAresta(74, 75, 7);
		g.addAresta(74, 97, 5);
		g.addAresta(75, 76, 7);
		g.addAresta(75, 96, 3);
		g.addAresta(76, 77, 1);
		g.addAresta(76, 95, 11);
		g.addAresta(77, 78, 11);
		g.addAresta(77, 94, 5);
		g.addAresta(78, 79, 11);
		g.addAresta(78, 93, 3);
		g.addAresta(79, 80, 5);
		g.addAresta(79, 92, 7);
		g.addAresta(80, 81, 1);
		g.addAresta(80, 91, 11);
		g.addAresta(81, 82, 11);
		g.addAresta(81, 90, 5);
		g.addAresta(82, 83, 1);
		g.addAresta(82, 89, 7);
		g.addAresta(83, 84, 7);
		g.addAresta(83, 88, 7);
		g.addAresta(84, 85, 1);
		g.addAresta(84, 87, 5);
		g.addAresta(85, 86, 5);
		g.addAresta(86, 111, 3);
		g.addAresta(87, 86, 7);
		g.addAresta(87, 110, 11);
		g.addAresta(88, 87, 11);
		g.addAresta(88, 109, 7);
		g.addAresta(89, 88, 1);
		g.addAresta(89, 108, 11);
		g.addAresta(90, 89, 1);
		g.addAresta(90, 107, 1);
		g.addAresta(91, 90, 7);
		g.addAresta(91, 106, 5);
		g.addAresta(92, 91, 7);
		g.addAresta(92, 105, 1);
		g.addAresta(93, 92, 3);
		g.addAresta(93, 104, 11);
		g.addAresta(94, 93, 1);
		g.addAresta(94, 103, 5);
		g.addAresta(95, 94, 3);
		g.addAresta(95, 102, 11);
		g.addAresta(96, 95, 5);
		g.addAresta(96, 101, 1);
		g.addAresta(97, 96, 1);
		g.addAresta(97, 100, 1);
		g.addAresta(98, 97, 3);
		g.addAresta(98, 99, 7);
		g.addAresta(99, 100, 5);
		g.addAresta(99, 124, 1);
		g.addAresta(100, 101, 3);
		g.addAresta(100, 123, 1);
		g.addAresta(101, 102, 5);
		g.addAresta(101, 122, 7);
		g.addAresta(102, 103, 7);
		g.addAresta(102, 121, 1);
		g.addAresta(103, 104, 3);
		g.addAresta(103, 120, 3);
		g.addAresta(104, 105, 1);
		g.addAresta(104, 119, 7);
		g.addAresta(105, 106, 3);
		g.addAresta(105, 118, 1);
		g.addAresta(106, 107, 11);
		g.addAresta(106, 117, 11);
		g.addAresta(107, 108, 3);
		g.addAresta(107, 116, 7);
		g.addAresta(108, 109, 3);
		g.addAresta(108, 115, 1);
		g.addAresta(109, 110, 3);
		g.addAresta(109, 114, 3);
		g.addAresta(110, 111, 7);
		g.addAresta(110, 113, 1);
		g.addAresta(111, 112, 3);
		g.addAresta(112, 136, 5);
		g.addAresta(113, 112, 7);
		g.addAresta(113, 135, 3);
		g.addAresta(114, 113, 5);
		g.addAresta(114, 134, 3);
		g.addAresta(115, 114, 5);
		g.addAresta(115, 133, 11);
		g.addAresta(116, 115, 5);
		g.addAresta(116, 132, 7);
		g.addAresta(117, 116, 5);
		g.addAresta(118, 117, 3);
		g.addAresta(118, 131, 1);
		g.addAresta(119, 118, 1);
		g.addAresta(119, 130, 1);
		g.addAresta(120, 119, 3);
		g.addAresta(120, 129, 5);
		g.addAresta(121, 120, 11);
		g.addAresta(121, 128, 1);
		g.addAresta(122, 121, 5);
		g.addAresta(122, 127, 1);
		g.addAresta(123, 122, 11);
		g.addAresta(123, 126, 11);
		g.addAresta(124, 123, 11);
		g.addAresta(124, 125, 5);
		g.addAresta(134, 135, 1);
		g.addAresta(135, 136, 7);
		g.addAresta(135, 138, 11);
		g.addAresta(136, 137, 11);
	*/
		

    //Calcula o tempo e Mostra a distancia
	clock_t t0 = clock();
		// T1 - cout << g.dijkstra(0, 6) << endl;
		// T2 - cout << g.dijkstra(21, 11) << endl;
		// T3 - cout << g.dijkstra(45, 136) << endl;
	clock_t t1 = clock();

	// Converte o tempo para segundos
	double tempo = double(t1 - t0) / CLOCKS_PER_SEC;
	
	//Mostra o tempo.
	cout << tempo << endl;
	
	return 0;
}
