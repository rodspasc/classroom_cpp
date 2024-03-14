#include <iostream>
#include <cstddef>
#include "arvorebinariaAVL.h"
using namespace std;


ArvoreBinariaBuscaAVL::ArvoreBinariaBuscaAVL(){
    raiz = NULL;
}

ArvoreBinariaBuscaAVL::~ArvoreBinariaBuscaAVL(){
    deletarArvore(raiz);
}

void ArvoreBinariaBuscaAVL::deletarArvore(No* Noatual){
    if (Noatual != NULL){
        deletarArvore(Noatual->filhoesquerda);
        deletarArvore(Noatual->filhodireita);
        delete Noatual;
    }
}

No* ArvoreBinariaBuscaAVL::obterRaiz(){
    return raiz;
}

bool ArvoreBinariaBuscaAVL::estavazio(){
    return (raiz == NULL);
}

bool ArvoreBinariaBuscaAVL::estacheio(){
    try{
        No* temp = new No;
        delete temp;
        return false;
    } catch(bad_alloc exception){
         return true;
    }
}

void ArvoreBinariaBuscaAVL::inserir(Aluno aluno){
    bool cresceu;
    insererecursivo(raiz,aluno, cresceu);
}

void ArvoreBinariaBuscaAVL::insererecursivo(No*& noatual, Aluno aluno, bool& cresceu){
    if (noatual == NULL){
        noatual = new No;
        noatual->filhodireita = NULL;
        noatual->filhoesquerda = NULL;
        noatual->aluno = aluno;
        noatual->fatorB = 0;
        cresceu = true;
        return;
    }
    if (aluno.obterRa() < noatual->aluno.obterRa()){
        insererecursivo(noatual->filhoesquerda, aluno, cresceu);
        if (cresceu){
            noatual->fatorB-=1;
        }
    } else {
        insererecursivo(noatual->filhoesquerda, aluno, cresceu);
        if (cresceu){
            noatual->fatorB+=1;
        }
    }
    realizarotacao(noatual);
    if (cresceu && noatual->fatorB == 0){
        cresceu = false;
    }
}

void ArvoreBinariaBuscaAVL::realizarotacao(No*& pai){
    No* filho;
    No* neto;
    if (pai->fatorB == -2){               //rotaciona para direita
        filho = pai->filhoesquerda;
        if (filho->fatorB == -1){             // rotação simples para direita 
            pai->fatorB = 0;
            filho->fatorB = 0;
            rotacaodireita(pai);
        } else if (filho->fatorB == 0){      // rotação simples para direita
            pai->fatorB = -1;
            filho->fatorB = -1;
            rotacaodireita(pai);
        } else if (filho->fatorB == 1){      // rotação dupla direita esquerda
            neto = filho->filhodireita;
            if (neto->fatorB == -1){
                pai->fatorB = 1;
                filho->fatorB = 0;
            } else if (neto->fatorB == 0){
                pai->fatorB = 0;
                filho->fatorB = 0;
            } else if (filho->fatorB == 1){
                pai->fatorB = 0;
                filho->fatorB = -1;
            }
            neto->fatorB = 0;
            rotacaodireitaesquerda(pai);
        } 
    } else if (pai->fatorB == 2){           // rotação para esquerda
        filho = pai->filhodireita;
        if (filho->fatorB = 1){            // rotação simples para esquerda
            pai->fatorB = 0;
            filho->fatorB = 0;
            rotacaodireitaesquerda(pai);
        } else if (filho->fatorB == 0){   // rotação simples para a esquerda
            pai->fatorB = 1;
            filho->fatorB = -1;
            rotacaodireitaesquerda(pai);
        } else if (filho->fatorB == -1){  // rotação dupla esquerda direita
            neto = filho->filhoesquerda;
            if (neto->fatorB == -1){
                pai->fatorB = 0;
                filho->fatorB = 1;
            } else if (neto->fatorB == 0){
                pai->fatorB = 0;
                filho->fatorB = 0;
            } else if (neto->fatorB == 1){
                pai->fatorB = -1;
                filho->fatorB = 0;
            }
            neto->fatorB = 0;
            rotacaodireitaesquerda(pai);
        }
    }    
}

void ArvoreBinariaBuscaAVL::rotacaodireita(No*& pai){
    No* novopai = pai->filhoesquerda;
    pai->filhoesquerda = novopai->filhodireita;
    novopai->filhodireita = pai;
    pai = novopai;
}

void ArvoreBinariaBuscaAVL::rotacaoesquerda(No* pai){
    No* novopai = pai->filhodireita;
    pai->filhodireita = novopai->filhoesquerda;
    novopai->filhoesquerda = pai;
    pai = novopai;
}

void ArvoreBinariaBuscaAVL::rotacaodireitaesquerda(No* pai){
    No* filho = pai->filhodireita;
    rotacaodireita(filho);
    pai->filhodireita = filho;
    rotacaodireitaesquerda(pai);
}

void ArvoreBinariaBuscaAVL::rotacaoesquerdadireita(No* pai){
    No* filho = pai->filhoesquerda;
    rotacaodireitaesquerda(filho);
    pai->filhoesquerda = filho;
    rotacaodireita(pai);
}

void ArvoreBinariaBuscaAVL::removerbusca(Aluno aluno, No*& noatual, bool& diminuiu){
    if (aluno.obterRa() < noatual->aluno.obterRa()){
        removerbusca(aluno, noatual->filhoesquerda, diminuiu);
        if (diminuiu){
            noatual->fatorB+=1;
        }
    } else if (aluno.obterRa() > noatual->aluno.obterRa()){
        removerbusca(aluno, noatual->filhodireita, diminuiu);
        if (diminuiu){
            noatual->fatorB-=1;
        }
    } else {
        deletarNo(noatual, diminuiu);
    }
    if (noatual != NULL){
        realizarotacao(noatual);
        if (diminuiu && noatual->fatorB != 0){
            diminuiu = false;
        }
    }
}

void ArvoreBinariaBuscaAVL::deletarNo(No*& noatual, bool& diminuiu){
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
        removerbusca(AlunoSucessor, noatual->filhodireita, diminuiu);
        if (diminuiu){
            noatual->fatorB-=1;
        } 
    }
}

void ArvoreBinariaBuscaAVL::obterSucessor(Aluno& AlunoSucessor, No* temp){
    temp = temp->filhodireita;
    while (temp->filhoesquerda != NULL){
        temp = temp->filhoesquerda;
    }
    AlunoSucessor = temp->aluno;
}

void ArvoreBinariaBuscaAVL::remover(Aluno aluno){
    bool diminuiu;
    removerbusca(aluno, raiz, diminuiu);
}

void ArvoreBinariaBuscaAVL::buscar(Aluno& aluno, bool& busca){
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

void ArvoreBinariaBuscaAVL::imprimirPre(No* Noatual){
    if (Noatual != NULL){
        cout << Noatual->aluno.obterNome() << ": ";
        cout << Noatual->aluno.obterRa() << endl;
        imprimirPre(Noatual->filhoesquerda);
        imprimirPre(Noatual->filhodireita);
    }
}

void ArvoreBinariaBuscaAVL::imprimirEm(No* Noatual){
    if (Noatual != NULL){
        imprimirEm(Noatual->filhoesquerda);
        cout << Noatual->aluno.obterNome() << ": ";
        cout << Noatual->aluno.obterRa() << endl;
        imprimirEm(Noatual->filhodireita);
    }   
}

void ArvoreBinariaBuscaAVL::imprimirPos(No* Noatual){
    if (Noatual != NULL){
        imprimirPos(Noatual->filhoesquerda);
        imprimirPos(Noatual->filhodireita);
        cout << Noatual->aluno.obterNome() << ": ";
        cout << Noatual->aluno.obterRa() << endl;
    }
}
