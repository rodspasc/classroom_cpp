#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int a=5, b=2;
    //int soma=a+b;
    //cout << "Soma: " << soma << endl;
    cout << "Soma: " << a+b << endl;
    cout << "Subtracao: " << a-b << endl;
    cout << "Multiplicacao: " << a*b << endl;
    cout << "Quociente: " << a/b << endl;
    cout << "Resto: " << a%b << endl;

    float div;
    div = (float)a/(float)b;
    cout << "Divisao: " << div << endl; 

    float pot = pow(a,b);
    cout << "Potencia: " << pot << endl;

    // Incremento e Decremento
    cout << "Antigo a: " << a << endl;
    // a = a+1;
    // a+=1;
    // a++;
    // a = a-1;
    // a-=1;
    // a--;
    a*=2;

    cout << "Novo a: " << a << endl; 

    return 0;

}