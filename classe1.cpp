#include <iostream>

using namespace std;

class propaganda{
     private:
    
     public:
    
     void inscrever(){
        cout << "Se increva no curso do Prof. Rodrigo.\n";
    }
     void curta(){ 
        cout << "Curta esse o curso.\n";
    }
     };


int main(){
    propaganda canal;
    canal.inscrever();
    canal.curta();

return 0;
}