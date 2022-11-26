#include "user.hpp"

#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

class Funcionario : public User
{
private:
    unsigned int chave;

public:
    Funcionario();
    Funcionario(std::string _nome,
               std::string _email,
               std::string _senha,
               std::string _CPF,
               std::string _telefone, 
               unsigned int _chave);
    unsigned int getChave();
};

#endif