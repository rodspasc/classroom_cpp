#include <iostream>

using namespace std;

class carro{
    private:
    int ano;
    float valor, km;

    public:

    //construtor
    carro(int a=0, float v=-1, float k=-1){
        ano = a;
        valor = v;
        km = k;
    };
    
    //set get

    void setano (int a){
        ano = a;    
    }
    void setvalor(float v){
        valor = v;
    }
    void setkm(float k){
        km = k;
    }
    int getano(){
        return ano;
    }
    float getvalor(){
        return valor;
    }    
    float getkm(){
        return km;
    }
};

int main(){
    carro palio;
    palio.setano(1995);
    palio.setvalor(10000);
    palio.setkm(150000);
    cout << "Palio:\n";
    cout << "Ano: " << palio.getano() << endl;
    cout << "Valor: " << palio.getvalor() << endl;
    cout << "Km: " << palio.getkm() << endl;

    carro celta;
    celta.setano(2001);
    celta.setvalor(18000);
    celta.setkm(80000);
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