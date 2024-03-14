#include <iostream>

using namespace std;

int main(){
    int intero;
    intero = 5;
    cout << intero << endl;

    float real;
    real = 5.2;
    cout << real << endl;

    double real2;
    real2 = 5.2e101;
    cout << real2 << endl;

    bool booleano;
    booleano = true;
    cout << booleano << endl;

    char letra;
    letra = 'b';
    cout << letra << endl;

    string palavra;
    palavra = "bola";
    cout << palavra << endl;

    int idade;
    cout << "Qual sua idade?" << endl;
    cin >> idade;
    cout << "Idade: " << idade << endl;

    system("pause");
 
   return 0; 
}