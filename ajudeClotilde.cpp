#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define C 1000000

int distancia[C];
int canais_proibidos[C];

class Grafo{
    int O;
    int D;
    int K;
public:
    Grafo(int O, int D, int K);
    void geraCanais(int u, int w, queue<int> &canais);
    int buscaEmLargura();
};

Grafo::Grafo(int O, int D, int K){
    
    this->O = O;
    this->D = D;
    this->K = K;

}

void Grafo::geraCanais(int u, int w, queue<int> &canais){


    if(distancia[w] != 0)
        return;
    if(1 > w || w > 100000 || canais_proibidos[w] == 1)
        return;
    /*if(1<= w <=100000){
        if (find(canais_proibidos.begin(), canais_proibidos.end(),w) != canais_proibidos.end()){
            return;
        }
    }*/
    canais.push(w);
    distancia[w] = distancia[u] + 1;
    
}

int Grafo::buscaEmLargura(){

    queue<int> canais;
    int u;

    fill(distancia, distancia + C, 0);
    
    canais.push(O);
    distancia[O] = 0;

    while(!canais.empty()){
        u = canais.front();
        if(u == D)
            return distancia[u];

        canais.pop();
    
        geraCanais(u, u+1, canais);
    
        geraCanais(u, u-1, canais);
    
        geraCanais(u, u*2, canais);

        geraCanais(u, u*3, canais);
        
        if(u % 2 == 0){
            geraCanais(u, u/2, canais);
        }
        
    }

    return -1;

}

int main(){
    int O, D, K;
    int cp;
    int qtd_cliques;
    
    while(true){
        cin >> O >> D >> K;
        if(O == 0 && D == 0 && K == 0){
            break;
        }
        if(1<=O && D <=100000 && (0<=K<=100)){
            //vector<int> canais_proibidos;
            fill(canais_proibidos, canais_proibidos + C, -1);
            for(int i = 0; i < K; i++){
                cin >> cp;
                canais_proibidos[cp] = 1;
            }
            Grafo g(O, D, K);
            qtd_cliques = g.buscaEmLargura();
            cout << qtd_cliques << endl;
        }
    }

    return 0;
}