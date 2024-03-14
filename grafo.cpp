#include <iostream>
#include "grafo.h"

using namespace std;

Grafo::Grafo(int max, int valorarestanula){
    numVertices = 0;
    maxVertices = max;
    arestaNula = valorarestanula;
    marcador = new bool[maxVertices];
    vertices = new TipoItem[maxVertices];
    matrizAdjacencias = new int*[maxVertices];
    for (int i = 0 ; i < maxVertices ; i++){
        matrizAdjacencias[i] = new int[maxVertices];
    }
    for (int i = 0 ; i < maxVertices ; i++){
        for (int j = 0 ; j < maxVertices ; j++){
            matrizAdjacencias[i][j] = arestaNula;
        }
    }
}

Grafo::~Grafo(){
    delete [] vertices;
    for (int i = 0 ; i < maxVertices ; i++){
        delete [] matrizAdjacencias[i];
    }
    delete [] matrizAdjacencias;
}

int Grafo::obterIndice(TipoItem item){
    int indice = 0;
    while (item != vertices[indice]){
        indice++;
    }
    return indice;
}    

bool Grafo::estaCheio(){
    return (numVertices == maxVertices);
}

void Grafo::inserirVertice(TipoItem item){
    if (estaCheio()){
        cout << "O numero maximo de vertices ja foi alancado!\n";
    } else {
        vertices[numVertices] = item;
        numVertices++;
    }
}

void Grafo::inserirAresta(TipoItem noSaida, TipoItem noEntrada, int peso){
    int linha = obterIndice(noSaida);
    int coluna = obterIndice(noEntrada);    
    matrizAdjacencias[linha][coluna] = peso;
//  matrizAdjacencias[coluna][linha] = peso;  // retirar se grafo for direcionado
}
    

int Grafo::obterPeso(TipoItem noSaida, TipoItem noEntrada){
    int linha = obterIndice(noSaida);
    int coluna = obterIndice(noEntrada);
    return (matrizAdjacencias[linha][coluna]);
}

int Grafo::obterGrau(TipoItem item){
    int linha = obterIndice(item);
    int grau = 0;
    for (int i = 0 ; i < maxVertices ; i++){
        if (matrizAdjacencias[linha][i] != arestaNula){
            grau++;
        }
    }    
    return grau;
}    

void Grafo::imprimirMatriz(){
    cout << "Matriz de adjacencias:\n";
    for (int i = 0 ; i < maxVertices ; i++){
        for (int j = 0 ; j < maxVertices ; j++){
            cout << matrizAdjacencias[i][j] << " ";
        }
        cout << endl;
    }
}

void Grafo::imprimirVertices(){
    cout << "Lista de vertices:\n";
    for (int i = 0 ; i < numVertices ; i++){
        cout << i << ": " << vertices[i] << endl;
    }
}

void Grafo::limpaMarcador(){
    for (int i = 0 ; i < maxVertices ; i++){
        marcador[i] = false;
    }
}

void Grafo::buscaLargura(TipoItem origem, TipoItem destino){
    filaenc filavertices;
    bool encontrado = false;
    limpaMarcador();
    filavertices.inserir(origem);
    do{
        TipoItem verticeatual = filavertices.remover();
        if (verticeatual == destino){
            cout << "Visitando: " << verticeatual << endl;
            cout << "Caminho encontrado!\n";
            encontrado = true;
        } else{
            int indice = obterIndice(verticeatual);
            cout << "Visitando: " << verticeatual << endl;
            for (int i=0 ; i<maxVertices ; i++){
                if (matrizAdjacencias[indice][i] != arestaNula){
                    if (!marcador[i]){
                        cout << "Enfileirando: " << vertices[i] << endl;
                        filavertices.inserir(vertices[i]);
                        marcador[i] = true;
                    }
                }  
            }
        }
    } while (!filavertices.estavazio() && !encontrado);
    if (!encontrado){
        cout << "Caminho nao encontrado!\n";
    }
}

void Grafo::buscaProfundidade(TipoItem origem, TipoItem destino){
pilhaenc pilhavertices;
    bool encontrado = false;
    limpaMarcador();
    pilhavertices.inserir(origem);
    do{
        TipoItem verticeatual = pilhavertices.remover();
        if (verticeatual == destino){
            cout << "Visitando: " << verticeatual << endl;
            cout << "Caminho encontrado!\n";
            encontrado = true;
        } else{
            int indice = obterIndice(verticeatual);
            cout << "Visitando: " << verticeatual << endl;
            for (int i=0 ; i<maxVertices ; i++){
                if (matrizAdjacencias[indice][i] != arestaNula){
                    if (!marcador[i]){
                        cout << "Empilhando: " << vertices[i] << endl;
                        pilhavertices.inserir(vertices[i]);
                        marcador[i] = true;
                    }
                }  
            }
        }
    } while (!pilhavertices.estavazio() && !encontrado);
    if (!encontrado){
        cout << "Caminho nao encontrado!\n";
    }
}