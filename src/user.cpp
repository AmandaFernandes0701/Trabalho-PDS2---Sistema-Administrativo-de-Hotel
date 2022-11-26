#include "user.hpp"

User::User() {}
User::User(std::string _nome,
           std::string _email,
           std::string _senha,
           std::string _CPF,
           std::string _telefone) : nome(_nome),
                                    email(_email),
                                    senha(_senha),
                                    CPF(_CPF),
                                    telefone(_telefone) {}

std::string User::getNome() { return nome;}

std::string User::getEmail() { return email;}

std::string User::getSenha() { return senha;}

std::string User::getCPF() { return CPF;}

std::string User::getTelefone() { return telefone;}
