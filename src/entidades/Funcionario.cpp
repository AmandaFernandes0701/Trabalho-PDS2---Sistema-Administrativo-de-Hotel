#include "Funcionario.hpp"


Funcionario::Funcionario(string email, string senha){
    this->email = email;
    this->senha = senha;
}

bool Funcionario::login(string email, string senha) {
    if(this->email != email || this->senha != senha)
        return false;

    return true;
}

