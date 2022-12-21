#ifndef BANCO_DE_DADOS_H
#define BANCO_DE_DADOS_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "Reserva.hpp"

/**
 * @brief Classe responsavel por gerenciar os dados de hospedes,
 * lista de reservas e lista de quartos do hotel
 */
class BancoDeDados {
    private:
        /**
		 * @brief Guarda os dados de cadastros de hospedes do hotel
		 */
        std::string nome_arquivo_lista_de_hospedes = "banco_de_dados/lista_de_hospedes.txt";
        std::string nome_arquivo_lista_de_quartos = "banco_de_dados/lista_de_quartos.txt";
        std::string nome_arquivo_lista_de_reservas = "banco_de_dados/lista_de_reservas.txt";

        /**
		 * @brief Armazena os hóspedes em tempo de execução. Antes de encerrar, o programa salva
         * os hóspedes cadastrados/alterados no '.txt'
		 */
        std::vector<Hospede*> hospedes;

        /**
         * @brief Armazena as reservas em tempo de execução. Antes de encerrar, o programa salva
         * as reservas cadastradas/alteradas no '.txt'.
        */
        std::vector<Reserva*> reservas;

        /**
         * @brief Armazena os quartos em tempo de execução.
        */
        std::vector<Quarto*> quartos;

    public:
        /**
		 * @brief Construtor padrao da classe
		 */
        BancoDeDados();

        /**
		 * @brief Lê os dados de hóspedes salvos em arquivo `.txt`
         * e carrega todos os dados para a memória de forma estruturada
         * usando um vector do tipo Hospede*
		 */
        void carregar_dados_hospedes();
        /**
		 * @brief Lê os dados de quartos salvos em arquivo `.txt`
         * e carrega todos os dados para a memória de forma estruturada
         * usando um vector do tipo Quarto*
		 */
        void carregar_dados_quartos();

        // carregar_dados_reservas();

        /**
		 * @brief Realiza o cadastro de um novo hóspede
		 * e informa se o usuário foi cadastrado.
         * @return bool cadastro realizado ou nao
		 */
        bool cadastrar_hospede(std::string,std::string,std::string,std::string,std::string);

        /**
		 * @brief Realiza o login de um hóspede
		 * e informa se os dados de login estão corretos
         * @param email Email de login
         * @param senha Senha de login
         * @return bool login realizado ou nao
		 */
        bool login_hospede(std::string email, std::string senha);

        /**
		 * @brief Realiza o login de um funcionário
		 * e informa se os dados de login estão corretos
         * @param email Email de login
         * @param senha Senha de login
         * @return bool login realizado ou nao
		 */
        bool login_funcionario(std::string email, std::string senha);

        /**
		 * @brief Salva os dados dos hóspedes armazenados no vector de
         * hóspedes no .txt
		 */
        void salvar_dados_hospedes();

        /**
		 * @brief Destrutor da classe
         * Quando chamado, todos os dados salvos na memória são transferidos
         * para arquivos .txt
		 */
		~BancoDeDados();
};

#endif
