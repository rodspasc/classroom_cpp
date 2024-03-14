#include <iostream>
#include "filaenc.h"
using namespace std;

int main(){
    filaenc fila1;
    TipoItem item;
    int opcao;
    cout << "Programa gerador de fila:\n";

    do {
       cout << "Digite 0 para parar o programa!\n";
       cout << "Digite 1 para inserir um elemento!\n";
       cout << "Digite 2 para remover um elemento!\n";
       cout << "Digite 3 para imprimir a pilha!\n";
       cin >> opcao;
       if (opcao == 1){
        cout << "Digite o elemento para inserir!\n";
        cin >> item;
        fila1.inserir(item);
       } else if(opcao == 2){
        cout << "Elemento removido: " << fila1.remover()<< endl; 
       } else if(opcao == 3){
        fila1.imprimir();
       } 
    } while(opcao != 0);
return 0;
}