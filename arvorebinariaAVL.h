# include <iostream>
#include "aluno.h"

struct No{
    Aluno aluno;
    No* filhoesquerda;
    No* filhodireita;
    int fatorB; 
};

class ArvoreBinariaBuscaAVL{  // BST Binary Search Tree
    private:
    No* raiz;

    public:
    ArvoreBinariaBuscaAVL();
    ~ArvoreBinariaBuscaAVL();
    void deletarArvore(No* Noatual);
    No* obterRaiz();
    bool estavazio();
    bool estacheio();
    void inserir(Aluno aluno);
    void remover(Aluno aluno);
    void removerbusca(Aluno aluno, No*& noatual, bool& diminuiu);
    void deletarNo(No*& noatual, bool& diminuiu);
    void obterSucessor(Aluno& AlunoSucessor, No* temp);
    void buscar(Aluno& aluno, bool& busca);
    void imprimirPre(No* Noatual);
    void imprimirEm(No* Noatual);
    void imprimirPos(No* Noatual);
    void rotacaodireita(No*& pai);
    void rotacaoesquerda(No* pai);
    void rotacaodireitaesquerda(No* pai);
    void rotacaoesquerdadireita(No* pai);
    void realizarotacao(No*& pai);
    void insererecursivo(No*& noatual, Aluno aluno, bool& cresceu);
};