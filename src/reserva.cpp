#include "reserva.hpp"

Reserva::Reserva() {}
Reserva::Reserva(data _entrada,
                 data _saida,
                 Hospede *_hospede_r,
                 Quarto *_quarto_r) : entrada(_entrada),
                 saida(_saida),
                 hospede_r(_hospede_r),
                 quarto_r(quarto_r) {}

data Reserva::getEntrada() {return entrada;}
data Reserva::getSaida() { return saida;}
Hospede *Reserva::getHospede() {return hospede_r;}
Quarto *Reserva::getQuarto() {return quarto_r;}