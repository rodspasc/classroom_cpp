#include <iostream>

using namespace std;

int main(){
    
    int n;
    cout << "Digite um numero inteiro positivo.\n";
    cin >> n;

    int soma=0;
    int cont=1;

    while (cont <= n){
        soma+=cont;
        cont++;
    }

// Usando um laço FOR não precisa de contador pois ele ja está dentro do FOR
// for (int j=1 ; j<=n ; j+=1){
//    soma+=j   
// }   
    
    cout << "Soma de 0 ate " << n << " e " << soma << endl;

    return 0;
}