#include <iostream>

using namespace std;

int main(){
    int matriz[2][3];

    matriz[0][0] = 11;
    matriz[0][1] = 12;
    matriz[0][2] = 13;
    matriz[1][0] = 21;
    matriz[1][1] = 22;
    matriz[1][2] = 23;

    for (int l=0 ; l<2 ; l++){
        for (int c=0 ; c<3 ; c++){
            cout << matriz[l][c] << " ";
        }
        cout << endl;
    }
return 0; 
}