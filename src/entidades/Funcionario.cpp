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

// TODO
// Implementar USER STORY seguinte
// --> Acesso somente a histórico de reservas do hóspede
// --> Filtrar por nome de usuário

/*
Como funcionário do hotel, eu desejo acessar determinadas informações dos
hóspedes cadastrados na base de dados do meu sistema, assim, posso tomar
decisões de como adequar o hotel para atender ainda melhor ao perfil de hóspede
que nele se hospeda.
*/
