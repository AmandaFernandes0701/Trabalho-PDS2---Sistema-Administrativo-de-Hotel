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
        /**
		 * @brief Construtor padrão da classe.
         * @param data ponteiro para a data reservada
         * @param quarto quarto reservado
         * @param hospede ponteiro para o hóspede que fez a reserva
		 */
        Reserva(Data* data, Quarto quarto, Hospede* hospede);

        /**
         * @brief Retorna o dia
         * @return int dia do mês
         */
        int get_dia();
        /**
         * @brief Retorna o mês
         * @return int mês do ano
         */
        int get_mes();
        /**
         * @brief Retorna o ano
         * @return int ano
         */
        int get_ano();

        /**
         * @brief Retorna o número do quarto
         * @return int quarto
         */
        int get_quarto();

        /**
         * @brief Retorna o email do hóspede
         * @return std::string email do hóspede
         */
        std::string get_email();
};

#endif