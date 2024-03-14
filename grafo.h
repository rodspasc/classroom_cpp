// grafos simples direcionado e ponderado

#include <iostream>
#include "pilhaenc.h"
#include "filaenc.h"
using namespace std;

//typedef string TipoItem;

class Grafo{
    
    private:
    int arestaNula;
    int maxVertices;
    int numVertices;
    TipoItem* vertices;
    int** matrizAdjacencias;
    bool* marcador; 
    
    public:

    Grafo(int max, int valorarestanula);
    ~Grafo();
    int obterIndice(TipoItem item);
    bool estaCheio();
    void inserirVertice(TipoItem item);
    void inserirAresta(TipoItem noSaida, TipoItem noEntrada, int peso);
    int obterPeso(TipoItem noSaida, TipoItem noEntreda);
    int obterGrau(TipoItem item);
    void imprimirMatriz();
    void imprimirVertices();
    void limpaMarcador();
    void buscaLargura(TipoItem origem, TipoItem destino);
    void buscaProfundidade(TipoItem origem, TipoItem destino);
};