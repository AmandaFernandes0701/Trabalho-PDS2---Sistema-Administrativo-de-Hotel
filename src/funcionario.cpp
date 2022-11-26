#include "funcionario.hpp"

Funcionario::Funcionario() {}
Funcionario::Funcionario(std::string _nome,
                         std::string _email,
                         std::string _senha,
                         std::string _CPF,
                         std::string _telefone,
                         unsigned int _chave) : User(_nome,
                                                    _email,
                                                    _senha,
                                                    _CPF,
                                                    _telefone),
                                               chave(_chave) {}

unsigned int Funcionario::getChave() { return chave;}