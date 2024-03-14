// pilha dinâmica = dynamic stack

typedef int TipoItem;

struct No{
    TipoItem valor;
    No* proximo;
}; 
class pilhaenc{
    
    private:

    No* NoTopo;
    
    public:

    pilhaenc(); //construtor
    ~pilhaenc(); // destrutor
    bool estavazio(); //is empty
    bool estacheio(); // tem memória // isfull
    void inserir(TipoItem item); //push
    TipoItem remover(); //pop
    void imprimir(); //print 
};