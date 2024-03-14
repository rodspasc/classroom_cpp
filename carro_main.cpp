#include <iostream>
#include "carro.h"

using namespace std;

int main(){
    carro palio(1995, 10000, 150000);
    cout << "Palio:\n";
    cout << "Ano: " << palio.getano() << endl;
    cout << "Valor: " << palio.getvalor() << endl;
    cout << "Km: " << palio.getkm() << endl;

    carro celta(2001, 18000, 80000);
    cout << "Celta:\n";
    cout << "Ano: " << celta.getano() << endl;
    cout << "Valor: " << celta.getvalor() << endl;
    cout << "Km: " << celta.getkm() << endl;

    carro gol(2020, 55000, 15000);
    cout << "Gol:\n";
    cout << "Ano: " << gol.getano() << endl;
    cout << "Valor: " << gol.getvalor() << endl;
    cout << "Km: " << gol.getkm() << endl;

    system("pause");


    return 0;
}