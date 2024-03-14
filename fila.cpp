#include <iostream>
#include "fila.h"

using namespace std;

fila::fila(){
    primeiro = 0;
    ultimo = 0;
    estrutura = new TipoItem[max_itens];
} //construtor

fila::~fila(){
    delete [] estrutura;
} //destrutor

bool fila::estacheio(){
    return (ultimo - primeiro == max_itens);
    } //isempty
    
bool fila::estavazio(){
    return (ultimo == primeiro);
} //isfull
    
void fila::inserir(TipoItem item){
    if (estacheio()){
        cout << "A fila esta cheia!\n";
        cout << "Nao e possivel inserir este elemento!\n";
    } else {
        estrutura[ultimo % max_itens] = item;
        ultimo++;
    }
}   //push ou enqueue
    
TipoItem fila::remover(){
    if (estavazio()){
        cout << "A fila esta vazia!\n";
        return 0;
    } else {
        primeiro++;
        return (estrutura[(primeiro-1) & max_itens]);
    }

} //pop ou dequeue
    
void fila::imprimir(){
    cout << "Fila: [ ";
    for (int i=primeiro ; i<ultimo ; i++){
        cout << estrutura[i % max_itens] << " ";
    }
    cout << "]\n";
}  //print
