#include <iostream>
#include "hash.h"

using namespace std;

int Hash::FunHash(Aluno aluno){
    return (aluno.obterRa() % max_posicoes);
}
Hash::Hash(int tam_vetor, int max){
    quant_itens = 0;
    max_itens = max;
    max_posicoes = tam_vetor;
    estrutura = new Aluno[tam_vetor];
}

 Hash::~Hash(){
    delete [] estrutura;
 }

bool Hash::estacheio(){
    return (quant_itens == max_itens);
}

int Hash::obterTamanhoAtual(){
    return (quant_itens);
}

void Hash::inserir(Aluno aluno){   
    if (estacheio()){
        cout << "A tabela hash esta cheia!\n";
        cout << "O elemento nao foi inserido!\n";
    } else{
        int local = FunHash(aluno);
        while(estrutura[local].obterRa() > 0){
            local = (local+1) % max_posicoes;
        }
        estrutura[local] = aluno;
        quant_itens++;
    }
}    

void Hash::deletar(Aluno aluno){
    int local = FunHash(aluno);
    bool teste = false;
    while(estrutura[local].obterRa() != -1){
        if (estrutura[local].obterRa() == aluno.obterRa()){
            cout << "Elemento removido!\n";
            estrutura[local] = Aluno(-2, " ");
            quant_itens--;
            teste = true;
            break;
        }
        local = (local+1) % max_posicoes;
    }
    if(!teste){
        cout << "O elemento nao foi encontrado!\n";
        cout << "Nenhum elemento foi removido!\n";
    }
}

void Hash::buscar(Aluno& aluno, bool& busca){
    int local = FunHash(aluno);
    while (estrutura[local].obterRa() != -1){
        if (estrutura[local].obterRa() == aluno.obterRa()){
            busca = true;
            aluno = estrutura[local];
            break;
        }
        local = (local+1) % max_posicoes;
    }
}

void Hash::imprimir(){
    cout << "Tabela Hash:\n";
    for (int i = 0; i < max_posicoes; i++){
        if (estrutura[i].obterRa() > 0){
            cout << i << ":" << estrutura[i].obterRa() << ": ";
            cout << estrutura[i].obterNome() << endl;
        }
    }
}
