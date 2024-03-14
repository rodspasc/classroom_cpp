#include <iostream>
#include "carro.h"

using namespace std;

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