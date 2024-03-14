#include <iostream>

using namespace std;

int main(){
   
//Alocação estática
    //int vet[4];
    //vet[0] = 5;
    //vet[1] = 10;
    //vet[2] = 0;
    //vet[3] = 0;
    
    int vet[4] = {5,10};
    //cout << vet[0] <<endl;
    for (int i=0 ; i<4 ; i++){
        cout << vet[i] << endl;
    }

// Tamanho do vetor

    int x = sizeof(vet); // tamnanho em bytes
    int y = sizeof(int);
    int z = sizeof(vet)/sizeof(int); 
    cout << "Tamanho de inteiro " << y << endl;
    cout << "Tamanho do vetor " << x << endl; 
    cout << "Quantidade de elementos do vetor " << z << endl;

// Alocação dinâmica

    int tamanho;
    cout << "Digite o tamanho de vetor "<< endl;
    cin >> tamanho;
    int* vetor = new int[tamanho]; // Cria vetor com tamanho definido pelo usuário
    
    for (int i=0 ; i<tamanho ; i++){
        cout << "Digite o elemento " << i+1 << " do vetor " << endl;
        cin >> vetor[i]; 
    }

    for (int i=0 ; i<tamanho ; i++){
        cout << vetor[i] << " ";
    }
    
//Desalocando espaço em memória usado pelo vetor
    
    delete [] vetor;
    
return 0;    
}