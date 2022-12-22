#include "Funcionario.hpp"

Funcionario::Funcionario(){
    this->email = "funcionario@hotel.com";
    this->senha = "pds2";
}

bool Funcionario::verificar_email(std::string email){
    if(this->email == email)
        return true;
    else
        return false;
}

bool Funcionario::verificar_senha(std::string senha){
    if(this->senha == senha)
        return true;
    else
        return false;
}
