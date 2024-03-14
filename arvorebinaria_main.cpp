#include <iostream>
#include "arvorebinaria.h"

using namespace std;

int main(){
    ArvoreBinariaBusca Arvorealunos;
    int opcao, ra, imp;
    string nome;
    bool busca = false;

    do{
        cout << "Digite o para parar o algoritmo!\n";
        cout << "Digite 1 para inserir um elemento!\n";
        cout << "Digite 2 para remover um elemmento!\n";
        cout << "Digite 3 para buscar um elemento!\n";
        cout << "Digite 4 para imprimir!\n";
        cin >> opcao;
        if(opcao == 1){
            cout << "Qual e o RA do aluno?\n";
            cin >> ra;
            cout << "Qual e o nome do aluno?\n";
            cin >> nome;
            Aluno aluno(ra, nome);
            if (Arvorealunos.estacheio()){
                cout << "A arvore esta cheia!\n";
                cout << "Nao foi possivel inserir o elemento!\n";
            } else {
                Arvorealunos.inserir(aluno);
            }  
        } else if(opcao == 2){
            cout << "Qual RA do aluno a ser removido?\n";
            cin >> ra;
            Aluno aluno(ra, " ");
            Arvorealunos.remover(aluno);   
        } else if(opcao == 3){
            cout << "Qual o RA do aluno a ser buscado?\n";
            cin >> ra;
            Aluno aluno(ra, " ");
            Arvorealunos.buscar(aluno, busca);
            if(busca){
                cout << "Aluno encontrado:\n";
                cout << "RA: " << aluno.obterRa() << endl;
                cout << "Nome: " << aluno.obterNome() << endl;
            } else{
                cout << "Aluno nao encontrado!\n";
            } 
        } else if(opcao == 4){
             cout << "Digite 1 para imprimir em pre ordem!\n";
             cout << "Digite 2 para imprimir em ordem!\n";
             cout << "Digite 3 para imprimir em pos ordem!\n";
             cin >> imp;
             if (imp == 1){
                cout << "1\n";
                Arvorealunos.imprimirPre(Arvorealunos.obterRaiz());
             } else if (imp ==2){
                cout << "2\n";
                Arvorealunos.imprimirEm(Arvorealunos.obterRaiz());
             } else {
                cout << "3\n";
                Arvorealunos.imprimirPos(Arvorealunos.obterRaiz());
             }           
        } 
    } while(opcao != 0);   
return 0;
}