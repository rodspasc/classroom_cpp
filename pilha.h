// pilha = stack

typedef int TipoItem;
const int max_itens = 100;

class pilha{
    private:
    int tamanho;
    TipoItem* estrutura;

    public:
    pilha(); //construtora
    ~pilha(); //destrutora
    bool estacheia(); // verifica se a pilha está cheia 
    bool estavazia(); // verifica se a pilha está vazia
    void inserir(TipoItem); //insere elemento na pilha // push
    TipoItem remover(); //remove elemento da pilha // pop
    void imprimir(); //print
    int qualtamanho(); // lenght
};
