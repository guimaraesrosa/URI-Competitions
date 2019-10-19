#include <iostream>
#include <list>

using namespace std;

class Grafo{
    int V;
    list<int> *adjacencia;
public:
    Grafo(int V);
    void adicionarAresta(int v1, int v2);
    void buscaEmProfundidade_Rec(int v, bool visitado[]);
    int buscaEmProfundidade();
};

Grafo::Grafo(int V){
    this->V = V;
    adjacencia = new list<int>[V];
}

void Grafo::adicionarAresta(int v1, int v2){
    adjacencia[v1].push_back(v2);
    adjacencia[v2].push_back(v1);
}

void Grafo::buscaEmProfundidade_Rec(int v, bool visitado[]){

    visitado[v] = true;

    list<int>::iterator it;
    for(it = adjacencia[v].begin(); it != adjacencia[v].end(); it++){
        if(!visitado[*it]){
            buscaEmProfundidade_Rec(*it,visitado);
        }
    }

}

int Grafo::buscaEmProfundidade(){
    bool visitado[V];
    int qt = 0;

    for(int i = 0; i < V; i++){
        visitado[i] = false;
    }

    for(int i = 0; i < V; i ++){
        if(!visitado[i]){
            buscaEmProfundidade_Rec(i,visitado);
            qt++;
        }
    }

    return qt;

}

int main(){

    int M, N, count, elem1, elem2, qtd;
    cin >> N >> M;

    Grafo g(N);

    while(count < M){
        cin >> elem1 >> elem2;
        g.adicionarAresta(elem1-1,elem2-1);
        count++;
    }

    qtd = g.buscaEmProfundidade();

    cout << qtd <<endl;

    return 0;
}