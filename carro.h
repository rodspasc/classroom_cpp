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