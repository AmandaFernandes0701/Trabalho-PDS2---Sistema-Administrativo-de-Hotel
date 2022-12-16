#include "Hospede.hpp"

Hospede::Hospede(std::string nome, std::string email, std::string senha, std::string cpf, std::string telefone){
    this->nome = nome;
    this->email = email;
    this->senha = senha;
    this->cpf = cpf;
    this->numero_telefone = telefone;
}

Hospede::Hospede(std::string email, std::string senha){
    this->email = email;
    this->senha = senha;
}

bool Hospede::login(BancoDeDados* banco_de_dados){
    bool retorno = banco_de_dados->login(this->email, this->senha);
    if(retorno == true)
        std::cout<<"Login realizado com sucesso!"<<std::endl;
    else{
        std::cout<<"Falha no login\nVerifique se digitou ";
        std::cout<<"o email e senha corretamente."<<std::endl;
    }
    return retorno;
}

bool Hospede::cadastrar(BancoDeDados* banco_de_dados){

    bool retorno = banco_de_dados->cadastrar_hospede(this->nome, this->email,
                    this->senha, this->cpf, this->numero_telefone);
    if(retorno == true)
        std::cout<<"Cadastro realizado com sucesso"<<std::endl;
    else
        std::cout<<"Cadastro não realizado"<<std::endl;
    return false;
}
