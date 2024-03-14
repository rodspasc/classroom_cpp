#include <iostream>
#include "pilhaenc.h"
#include <cstddef> // NULL
#include <new>

using namespace std;

pilhaenc::pilhaenc(){
    NoTopo = NULL;
} //construtor

pilhaenc::~pilhaenc(){
    No* NoTemp;
    while(NoTopo != NULL){
        NoTemp = NoTopo;
        NoTopo = NoTopo->proximo;
        delete NoTemp;
    }
    
} // destrutor

bool pilhaenc::estavazio(){
    return(NoTopo == NULL);
} //is empty

bool pilhaenc::estacheio(){
    No* NoNovo;
    try{
        NoNovo = new No;
        delete NoNovo;
        return false;
    } catch(bad_alloc exception){
        return true;
    }
} // tem memória // isfull

void pilhaenc::inserir(TipoItem item){
    if(estacheio()){
        cout << "A Pilha esta cheia!\n";
        cout << "Nao foi possivel inserir este elemento!\n";
    } else {
        No* NoNovo = new No;
        NoNovo->valor = item;
        NoNovo->proximo = NoTopo;
        NoTopo = NoNovo; 
    }
} //push

TipoItem pilhaenc::remover(){
    if(estavazio()){
        cout << "A pilha esta vazia!\n";
        cout << "Nao foi possivel remover nenhum elemento!\n";
        return 0;
    } else{
        No* NoTemp;
        NoTemp = NoTopo;
        TipoItem rem = NoTopo->valor;
        NoTopo = NoTopo->proximo;
        delete NoTemp;
        return rem;
    }
} //pop
 
void pilhaenc::imprimir(){
    No* NoTemp = NoTopo;
    cout << "Pilha: [ ";
    while(NoTemp != NULL){
        cout << NoTemp->valor << " ";
        NoTemp = NoTemp->proximo;
    }
    cout << " ]\n";
} //print 
