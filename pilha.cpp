#include <iostream>
#include "pilha.h"
using namespace std;

//construtora
pilha::pilha(){
    tamanho = 0;
    estrutura = new TipoItem[max_itens];
} 

//destrutora
pilha::~pilha(){
    delete [] estrutura;
} 

// verifica se a pilha está cheia 
bool pilha::estacheia(){
    return (tamanho == max_itens);
} 

// verifica se a pilha está vazia
bool pilha::estavazia(){
    return (tamanho == 0);
} 

//insere elemento na pilha // push
void pilha::inserir(TipoItem item){
    if (estacheia()){
        cout << "A pilha esta cheia!\n";
        cout << "Nao e possivel inserir este elemento!\n";
    } else{
        estrutura[tamanho] = item;
        tamanho++;
    }
} 

//remove elemento da pilha // pop
TipoItem pilha::remover(){
    if (estavazia()){
        cout << "A pilha esta vazia!\n";
        cout << "Nao tem elemento para ser removido!\n";
        return 0;
    } else{
        tamanho--;
        return estrutura[tamanho];
    }
} 

//print
void pilha::imprimir(){
    cout << "Pilha: [ ";
    for (int i=0 ; i<tamanho ; i++){
        cout << estrutura[i] << " ";
    }
    cout << "]\n";
} 

//lenght
int pilha::qualtamanho(){
    return tamanho;
} 