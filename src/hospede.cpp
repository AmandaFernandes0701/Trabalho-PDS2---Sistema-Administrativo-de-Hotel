#include "hospede.hpp"

Hospede::Hospede() {}
Hospede::Hospede(std::string _nome,
                 std::string _email,
                 std::string _senha,
                 std::string _CPF,
                 std::string _telefone) User(_nome,
                                             _email,
                                             _senha,
                                             _CPF,
                                             _telefone) {}

void Hospede::insertReserva(Reserva _reserva) : historico.insert(_reserva) {}