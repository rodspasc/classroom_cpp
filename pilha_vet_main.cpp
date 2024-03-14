#include <iostream>
#include "pilha.h"
using namespace std;

int main(){
    pilha pilha1;
    TipoItem item;
    int opcao;
    cout << "Programa gerador de pilha:\n";

    do {
       cout << "Digite 0 para parar o programa!\n";
       cout << "Digite 1 para inserir um elemento!\n";
       cout << "Digite 2 para remover um elemento!\n";
       cout << "Digite 3 para imprimir a pilha!\n";
       cout << "Digite 4 para ver tamanho da pilha!\n";
       cin >> opcao;
       if (opcao == 1){
        cout << "Digite o elemento para inserir!\n";
        cin >> item;
        pilha1.inserir(item);
       } else if(opcao == 2){
        pilha1.remover();
        cout << "Elemento removido: " << item << endl; 
       } else if(opcao == 3){
        pilha1.imprimir();
       } else if(opcao == 4){
        cout << "O tamanho da pilha e: " << pilha1.qualtamanho() << endl;
       }
    } while(opcao != 0);
return 0;
}