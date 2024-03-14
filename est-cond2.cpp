#include <iostream>

using namespace std;

int main(){
    float nota1, nota2;
    cout << "Digite a nota 1\n";
    cin >> nota1;
    cout << "Digite a nota 2\n";
    cin >> nota2;
    float media = (nota1+nota2)/2;
    cout << "Media " << media << endl;

    
    if (media < 2.5){
        cout << "Nota final D\n";
    } else if (media < 5) {
        cout << "Nota final C\n";
    } else if (media < 7.5){
        cout << "Nota final B\n";
    } else {
        cout << "Nota final A\n";
    }

// Operadores logicos: E && , OU || , Não ! 

    float freq;
    cout << "Digite a frequencia do aluno\n";
    cin >> freq;

    if (media >= 5 & freq >= 75){
        cout << "Aluno aprovado\n";
    } else {
        cout << "aluno reprovado\n";
    }

 // Operador Ternario
 // (media >= 5) ? cout << "Aprovado" : "Reprovado";

    system("pause");

    return 0;
}