// fila = queue

typedef int TipoItem;
const int max_itens = 100;

class fila{
    private:
    int primeiro, ultimo;
    TipoItem* estrutura;

    public:
    fila(); //construtor
    ~fila(); //destrutor

    bool estacheio(); //isempty
    bool estavazio(); //isfull
    void inserir(TipoItem item);   //push ou enqueue
    TipoItem remover(); //pop ou dequeue
    void imprimir();  //print
};
