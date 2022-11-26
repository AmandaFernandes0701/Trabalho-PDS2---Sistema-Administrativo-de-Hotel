#include "reserva.hpp"
#include "hospede.hpp"
#include "quarto.hpp"
#include "funcionario.hpp"
#include <list>
#include <map>

#ifndef HOTEL_HPP
#define HOTEL_HPP

class Hotel
{
private:
  std::list <Hospede *> hopedes_list;
  std::list <Funcionario *> funcionarios_list;
  std::list <Quarto *> quartos_list;
  std::list <Reserva *> reservas_list;

public:
    Hotel();
    void insertHospede(Hospede *_hospede);
    void insertHospede(Funcionario *_Funcionario);
    void insertHospede(Quarto *_Quarto);
    void insertHospede(Reserva *_Reserva);

};

#endif