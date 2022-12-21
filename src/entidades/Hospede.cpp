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

bool Hospede::verificar_email(std::string email){
    if(this->email == email)
        return true;
    else
        return false;
}

bool Hospede::verificar_senha(std::string senha){
    if(this->senha == senha)
        return true;
    else
        return false;
}

std::string Hospede::get_nome(){
    return this->nome;
}
std::string Hospede::get_email(){
    return this->email;
}
std::string Hospede::get_senha(){
    return this->senha;
}

std::string Hospede::get_cpf(){
    return this->cpf;
}

std::string Hospede::get_telefone(){
    return this->numero_telefone;
}
