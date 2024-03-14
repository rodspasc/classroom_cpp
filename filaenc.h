// Fila encadeada = queue

typedef int TipoItem;

struct No{
    TipoItem valor;
    No* proximo;
};

class filaenc{

    private:
    No* primeiro; // front
    No* ultimo; // rear

    public:
    filaenc(); // construtor
    ~filaenc(); // destrutor
    bool estavazio(); // isEmpty
    bool estacheio(); // isFull
    void inserir(TipoItem item); // enqueue // push
    TipoItem remover(); // dequeue // pop
    void imprimir(); // print
};
