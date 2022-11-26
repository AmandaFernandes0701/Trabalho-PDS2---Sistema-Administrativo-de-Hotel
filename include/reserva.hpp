
#include "quarto.hpp"

struct data
{
    unsigned short int dia;
    unsigned short int mes;
    unsigned short int ano;
};

#ifndef RESERVA_HPP
#define RESERVA_HPP

#include "hospede.hpp"

class Reserva
{
private:
    data entrada;
    data saida;
    Hospede *hospede_r;
    Quarto *quarto_r;

public:
    Reserva();
    Reserva(data _entrada,
            data _saida,
            Hospede *_hospede_r,
            Quarto *_quarto_r);
    data getEntrada();
    data getSaida();
    Hospede *getHospede();
    Quarto *getQuarto();
};

#endif