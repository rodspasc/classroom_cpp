# include <iostream>
#include "aluno.h"

struct No{
    Aluno aluno;
    No* filhoesquerda;
    No* filhodireita;
};

class ArvoreBinariaBusca{  // BST Binary Search Tree
    private:
    No* raiz;

    public:
    ArvoreBinariaBusca();
    ~ArvoreBinariaBusca();
    void deletarArvore(No* Noatual);
    No* obterRaiz();
    bool estavazio();
    bool estacheio();
    void inserir(Aluno aluno);
    void remover(Aluno aluno);
    void removerbusca(Aluno aluno, No*& noatual);
    void deletarNo(No*& noatual);
    void obterSucessor(Aluno& AlunoSucessor, No* temp);
    void buscar(Aluno& aluno, bool& busca);
    void imprimirPre(No* Noatual);
    void imprimirEm(No* Noatual);
    void imprimirPos(No* Noatual);
};