
#include <iostream>
#include <cstddef>
#include "arvorebinaria.h"
using namespace std;


ArvoreBinariaBusca::ArvoreBinariaBusca(){
    raiz = NULL;
}

ArvoreBinariaBusca::~ArvoreBinariaBusca(){
    deletarArvore(raiz);
}

void ArvoreBinariaBusca::deletarArvore(No* Noatual){
    if (Noatual != NULL){
        deletarArvore(Noatual->filhoesquerda);
        deletarArvore(Noatual->filhodireita);
        delete Noatual;
    }
}

No* ArvoreBinariaBusca::obterRaiz(){
    return raiz;
}

bool ArvoreBinariaBusca::estavazio(){
    return (raiz == NULL);
}

bool ArvoreBinariaBusca::estacheio(){
    try{
        No* temp = new No;
        delete temp;
        return false;
    } catch(bad_alloc exception){
         return true;
    }
}

void ArvoreBinariaBusca::inserir(Aluno aluno){
    if(estacheio()){
        cout << "A arvore esta cheia!\n";
        cout << "Nao e possivel inserir este elemento!\n";
    } else {
        No* NoNovo = new No;
        NoNovo->aluno = aluno;
        NoNovo->filhodireita = NULL;
        NoNovo->filhoesquerda = NULL;
        if (raiz == NULL){
            raiz = NoNovo;
        } else {
            No* temp = raiz;
            while (temp != NULL){
                if (aluno.obterRa() < temp->aluno.obterRa()){
                    if (temp->filhoesquerda == NULL){
                        temp->filhoesquerda = NoNovo;
                        break;
                    } else {
                        temp = temp->filhoesquerda;
                    }
                } else {
                    if (temp->filhodireita == NULL){
                        temp->filhodireita = NoNovo;
                        break;
                    } else {
                        temp = temp->filhodireita;
                    }
                }
            }
        }
    } 
}

void ArvoreBinariaBusca::removerbusca(Aluno aluno, No*& noatual){
    if (aluno.obterRa() < noatual->aluno.obterRa()){
        removerbusca(aluno, noatual->filhoesquerda);
    } else if (aluno.obterRa() > noatual->aluno.obterRa()){
        removerbusca(aluno, noatual->filhodireita);
    } else {
        deletarNo(noatual);
    }
}

void ArvoreBinariaBusca::deletarNo(No*& noatual){
    No* temp = noatual;
    if (noatual->filhoesquerda == NULL){
        noatual = noatual->filhodireita;
        delete temp;
    } else if (noatual->filhodireita == NULL){
        noatual = noatual->filhoesquerda;
        delete temp;
    } else {
        Aluno AlunoSucessor;
        obterSucessor(AlunoSucessor, noatual);
        noatual->aluno = AlunoSucessor;
        removerbusca(AlunoSucessor, noatual->filhodireita); 
    }
}

void ArvoreBinariaBusca::obterSucessor(Aluno& AlunoSucessor, No* temp){
    temp = temp->filhodireita;
    while (temp->filhoesquerda != NULL){
        temp = temp->filhoesquerda;
    }
    AlunoSucessor = temp->aluno;
}

void ArvoreBinariaBusca::remover(Aluno aluno){
    removerbusca(aluno, raiz);
}

void ArvoreBinariaBusca::buscar(Aluno& aluno, bool& busca){
    busca = false;
    No* noatual = raiz;
    while (noatual != NULL){
        if (aluno.obterRa() < noatual->aluno.obterRa()){
            noatual = noatual->filhoesquerda;           
        } else if (aluno.obterRa() > noatual->aluno.obterRa()){
            noatual = noatual->filhodireita;
        } else {
            busca = true;
            aluno = noatual->aluno;
            break;
        }
    }
}

void ArvoreBinariaBusca::imprimirPre(No* Noatual){
    if (Noatual != NULL){
        cout << Noatual->aluno.obterNome() << ": ";
        cout << Noatual->aluno.obterRa() << endl;
        imprimirPre(Noatual->filhoesquerda);
        imprimirPre(Noatual->filhodireita);
    }
}

void ArvoreBinariaBusca::imprimirEm(No* Noatual){
    if (Noatual != NULL){
        imprimirEm(Noatual->filhoesquerda);
        cout << Noatual->aluno.obterNome() << ": ";
        cout << Noatual->aluno.obterRa() << endl;
        imprimirEm(Noatual->filhodireita);
    }   
}

void ArvoreBinariaBusca::imprimirPos(No* Noatual){
    if (Noatual != NULL){
        imprimirPos(Noatual->filhoesquerda);
        imprimirPos(Noatual->filhodireita);
        cout << Noatual->aluno.obterNome() << ": ";
        cout << Noatual->aluno.obterRa() << endl;
    }
}
