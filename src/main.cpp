#include "Hospede.hpp"
#include "BancoDeDados.hpp"
#include <iostream>


int main()
{
    BancoDeDados banco_de_dados = BancoDeDados();
    int escolha;

    while(true){
        std::cout<<"Digite:"<<std::endl;
        std::cout<<"1 para cadastrar hóspede"<<std::endl;
        std::cout<<"2 para logar hóspede"<<std::endl;
        std::cout<<"3 para sair"<<std::endl;
        std::cin>>escolha;

        if(escolha == 1)
        {
            std::string nome, email, senha, cpf, telefone;

            std::cin.ignore(); // https://pt.stackoverflow.com/a/319643
            std::cout<<"Digite o seu nome: ";
            std::getline(std::cin, nome);
            std::cout<<"Digite o seu email: ";
            std::cin>>email;
            std::cout<<"Digite uma senha: ";
            std::cin>>senha;
            std::cout<<"Digite o seu CPF: ";
            std::cin>>cpf;
            std::cout<<"Digite o seu telefone: ";
            std::cin>>telefone;

            Hospede *hospede = new Hospede(nome, email, senha, cpf, telefone);
            // TODO: Verificar se dados foram preenchidos corretamente
            // hospede->verificar_corretude_dados()
            hospede->cadastrar(&banco_de_dados);
            break;
        }else if(escolha == 2){
            std::string email, senha;
            std::cout<<"Digite o seu email: ";
            std::cin>>email;
            std::cout<<"Digite a sua senha: ";
            std::cin>>senha;
            Hospede *hospede = new Hospede(email, senha);
            bool retorno = hospede->login(&banco_de_dados);

        }
        else if(escolha == 3){
            break;
        }
    }

    return 0;
}
