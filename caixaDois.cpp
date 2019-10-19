#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

struct Aresta{
    int v1;
    int v2;
    int peso;

    Aresta(int vertice1 = 0, int vertice2 = 0, int w = 0){
        v1 = vertice1;
        v2 = vertice2;
        peso = w;
    }

};

class Grafo{
    int V;
    int A;
    vector<Aresta> aresta;
public:
    Grafo(int V, int A);
    void adicionarAresta(int v1, int v2, int peso);
    bool sortMin(Aresta const& a1, Aresta const& a2);
    bool sortMax(Aresta const& a1, Aresta const& a2);
    int busca(int conj_vertices[], int v);
    void uniao(int conj_vertices[], int u, int w);
    void algoritmoKruskal();
};

Grafo::Grafo(int V, int A){
    this->V = V;
    this->A = A;
}

void Grafo::adicionarAresta(int v1, int v2, int peso){
    Aresta a(v1, v2, peso);
    aresta.push_back(a);
}

bool Grafo::sortMin(Aresta const& a1, Aresta const& a2) {
    return (a1.peso < a2.peso);
}

bool Grafo::sortMax(Aresta const& a1, Aresta const& a2) {
    return (a1.peso > a2.peso);
}

int Grafo::busca(int conj_vertices[], int v){
    if(conj_vertices[v] == -1);
        return v;
    return busca(conj_vertices,conj_vertices[v]);
}

void Grafo::uniao(int conj_vertices[], int u, int w){
    int v1 = busca(conj_vertices, u);
    int v2 = busca(conj_vertices, w);
    conj_vertices[v1] = v2;
}

void Grafo::algoritmoKruskal(){
    vector<Aresta> arvore_max;
    vector<Aresta> arvore_min;

    int conj_vertices[V];
    fill(conj_vertices, conj_vertices + V, -1);

    //Trata árvore com maiores pesos
    sort(aresta.begin(), aresta.end(), sortMax);

    for(int i = 0; i < aresta.size(); i++){
        int u = busca(conj_vertices, aresta[i].v1);
        int w = busca(conj_vertices, aresta[i].v2);

        if(u != w){
            arvore_max.push_back(aresta[i]);
            uniao(conj_vertices, u, w);
        }
    }

    int qt_max=0;
    for(int i; i < arvore_max.size(); i++){
        qt_max += arvore_max[i].peso;
    }

    //Trata árvore com menores pesos




}

int main(){
    int M, N, X, Y, C, count = 0;

    while(true){
        cin >> N >> M;
        if(1 <= N <= 10000 && 1 <= M <= 100000)
            break;
    }

    Grafo g(N,M);

    while(count < M){
        cin >> X >> Y >> C;
        if((1 <= X <= N) && (1 <= Y <= N) && (1 <= C <= 1000)){
            g.adicionarAresta(X-1,Y-1,C);
            count++;
        }
        
    }

    g.algoritmoKruskal();


    return 0;
}