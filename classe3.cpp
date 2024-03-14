#include <iostream>

using namespace std;

class carro{
    private:
    
    int ano;
    float valor, km;

    public:

    //construtor
    carro(int a, float v, float k);
    
    //set get
    void setano (int a);   
    void setvalor(float v);
    void setkm(float k);
    int getano();
    float getvalor();
    float getkm();   
};

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

    return 0;
}

    //construtor
    carro::carro(int a=0, float v=-1, float k=-1){
        ano = a;
        valor = v;
        km = k;
    }
    
    //set get
    void carro::setano (int a){
        ano = a;    
    }
    void carro::setvalor(float v){
        valor = v;
    }
    void carro::setkm(float k){
        km = k;
    }
    int carro::getano(){
        return ano;
    }
    float carro::getvalor(){
        return valor;
    }    
    float carro::getkm(){
        return km;
    }
