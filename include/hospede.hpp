#include "user.hpp"
#include <list>

#ifndef HOSPEDE_HPP
#define HOSPEDE_HPP

#include "reserva.hpp"

class Hospede : public User
{
private:
    std::list <Reserva> historico;

public:
    Hospede();
    Hospede(std::string _nome,
               std::string _email,
               std::string _senha,
               std::string _CPF,
               std::string _telefone, 
               Reserva _reserva);
};

#endif