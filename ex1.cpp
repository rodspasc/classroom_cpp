#include <iostream>
#include <math.h>

using namespace std;

float fx (float x){
    float f = pow(x,2) - 3*x + 5; 
    return f;
}

int main(){
    float x;
    float y;
    cout << "Digite um valor para X\n";
    cin >> x;
    y = fx (x);
    cout << "O valor de Y para X = " << x << " e " << y << endl;
    return 0;
}

