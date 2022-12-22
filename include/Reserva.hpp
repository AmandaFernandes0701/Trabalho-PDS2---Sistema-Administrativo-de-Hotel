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
        Data* data = NULL;
        /**
		 * @brief quarto reservado
		 */
        Quarto* quarto = NULL;
        /**
		 * @brief hóspede que realizou a reserva
		 */
        Hospede* hospede = NULL;

    public:
        /**
		 * @brief Construtor padrão da classe.
         * 
         * @param data ponteiro para a data reservada
         * @param quarto quarto reservado
         * @param hospede ponteiro para o hóspede que fez a reserva
		 */
        Reserva(Data* data, Quarto quarto, Hospede* hospede);

        /**
         * @brief Retorna o dia
         * 
         * @return int dia do mês
         */
        int get_dia();
        /**
         * @brief Retorna o mês
         * 
         * @return int mês do ano
         */
        int get_mes();
        /**
         * @brief Retorna o ano
         * 
         * @return int ano
         */
        int get_ano();

        /**
         * @brief Retorna o número do quarto
         * 
         * @return int quarto
         */
        int get_quarto();

        /**
         * @brief Retorna o nome do hóspede
         * 
         * @return std::string nome
         */
        std::string get_nome();

        /**
         * @brief Retorna o email do hóspede
         * 
         * @return std::string email do hóspede
         */
        std::string get_email();

        /**
		 * @brief Verifica a data informada
		 * e retorna se a data recebida é igual ou diferente
         * 
		 * @param data data para comparar
		 * @return bool true se data é igual
		 * @return bool false se data é diferente
		 */
        bool verificar_data(Data data);

        /**
		 * @brief Destrutor da classe
		 */
        ~Reserva();
};

#endif
