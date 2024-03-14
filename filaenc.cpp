#include "filaenc.h"
#include "cstddef"
#include <new>
#include <iostream>
using namespace std;



filaenc::filaenc(){
    primeiro = NULL;
    ultimo = NULL;
} // construtor

filaenc::~filaenc(){
    No* temp;
    while(primeiro != NULL){
        temp = primeiro;
        primeiro = primeiro->proximo;
        delete temp;
    }
    ultimo = NULL;
} // destrutor

bool filaenc::estavazio(){
    return (primeiro == NULL);
} // isEmpty

bool filaenc::estacheio(){
    No* temp;
    try{
        temp = new No;
        delete temp;
        return false;
    } catch(bad_alloc exception){
        return true;
    }
} // isFull

void filaenc::inserir(TipoItem item){
    if(estacheio()){
        cout << "A fila esta cheia!\n";
        cout << "Nao e possivel inserir este elemento!\n";
    } else{
        No* NoNovo = new No;
        NoNovo->valor = item;
        NoNovo->proximo = NULL;
        if(primeiro == NULL){
            primeiro = NoNovo;
        } else{
            ultimo->proximo = NoNovo;
        }
        ultimo = NoNovo;
    }
} // enqueue // push

TipoItem filaenc::remover()
{
    if(estavazio())
    {
        cout << "A fila esta vazia!\n";
        cout << "Nao tem elemento a ser removido!\n";
        return 0;
    } else{
        No* temp = primeiro;
        TipoItem rem = primeiro->valor;
        primeiro = primeiro->proximo;
        if(primeiro == NULL)
        {
           ultimo = NULL;
        }
        delete temp;
        return rem;
    }
} // dequeue // pop

void filaenc::imprimir(){
    No* temp = primeiro;
    cout << "Fila [ ";
    while(temp != NULL){
        cout << temp->valor << " ";
        temp = temp->proximo;
    }
    cout << "]\n";
} // print
