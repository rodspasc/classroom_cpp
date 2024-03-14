#include <iostream>

using namespace std;

#define pi 3.14;

#define curtir cout << "Curta seus estudos!\n";

void inscrever(){
    cout << "Estude para ser esperto" << endl;
}

int somar(int x, int y){
    int soma;
    soma = x+y;
    return soma;
}

int main(){
    
    inscrever();
    inscrever();
    
    int a=5, b=4;
    int s;
    s = somar(a,b);
    cout << "Soma: " << s << endl;
    // cout << pi;
    curtir;

    return 0;
}