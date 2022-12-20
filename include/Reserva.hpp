#ifndef RESERVA_H
#define RESERVA_H

#include "Hospede.hpp"
#include "Funcionario.hpp"
#include "Data.hpp"
#include "Quarto.hpp"

/**
 * @brief Classe responsavel por gerenciar as reservas dos hospedes.
 */
class Reserva {
    private:
        /**
		 * @brief data da reserva
		 */
        Data* data;
        /**
		 * @brief quarto reservado
		 */
        Quarto* quarto;
        /**
		 * @brief hóspede que realizou a reserva
		 */
        Hospede* hospede;
    public:

};

#endif