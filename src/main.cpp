#include "Hospede.hpp"
#include "BancoDeDados.hpp"
#include <iostream>

using namespace std;

int main()
{
    BancoDeDados banco_de_dados = BancoDeDados();
    int escolha;

    while(true){
        cout<<"Digite:"<<endl;
        cout<<"1 para cadastrar hóspede"<<endl;
        cout<<"2 para logar hóspede"<<endl;
        cin>>escolha;

        if(escolha == 1)
        {
            Hospede *hospede = new Hospede();
            hospede->cadastrar(&banco_de_dados);
            break;
        }else if(escolha == 2){}
    }

    return 0;
}
