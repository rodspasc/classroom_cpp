#include <iostream>
#include <cstddef>

using namespace std;

int main(){
    int var1;
    int* pont1;
    var1 = 5;
    pont1 = &var1;
    cout << "Valor da variavel atraves do seu nome " << var1 << endl;
    cout << "Endereco armazenado no ponteiro " << pont1 << endl;
    cout << "Valor da variavel atraves do ponteiro " << *pont1 << endl;
    
    //int var2;
    // var2 = var1;
    // var2 = *pont1;
    // cout << var2;

    // var1 = 30;
    // *pont1 = int var1;
    // cout << var1;

    //var2 = 50;
    //pont1 = &var2;
    //cout << *pont1;
   
    //int* pont2;
    //cout << *pont2 << endl;
    //pont2 = NULL;
    //cout << pont2 << endl;
    //cout << *pont2 << endl;

    int* pont3 = new int;
    *pont3 = 35;
    cout << pont3 << endl;
    cout << *pont3 << endl;

    //*pont3 = *pont1;
    //cout << *pont3 << endl;

    
    // Não perder espaço de memoria que pont3 apontava (vazamento de memoria)
    delete pont3;
    pont3 = pont1;
    cout << *pont3;





return 0;
}