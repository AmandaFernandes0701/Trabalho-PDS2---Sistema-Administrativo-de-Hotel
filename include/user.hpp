#include <iostream>
#include <string>

#ifndef USER_HPP
#define USER_HPP

class User
{
private:
    std::string nome;
    std::string email;
    std::string senha;
    std::string CPF;
    std::string telefone;

public:
    User();
    User(std::string _nome,
               std::string _email,
               std::string _senha,
               std::string _CPF,
               std::string _telefone);
    std::string getNome();
    std::string getEmail();
    std::string getSenha();
    std::string getCPF();
    std::string getTelefone();
};

#endif