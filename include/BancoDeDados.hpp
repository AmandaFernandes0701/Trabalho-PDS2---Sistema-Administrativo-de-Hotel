#ifndef BANCO_DE_DADOS_H
#define BANCO_DE_DADOS_H

#include <string>
#include <fstream>
#include <iostream>

/**
 * @brief Classe responsavel por gerenciar os dados de hospedes,
 * lista de reservas e lista de quartos do hotel
 */
class BancoDeDados {
    private:
        /**
		 * @brief Guarda os dados de cadastros de hospedes do hotel
		 */
        std::string nome_arquivo_lista_de_hospedes = "lista_de_hospedes.txt";
        // Lista de reservas;
        // Lista de quartos;

    public:
        /**
		 * @brief Construtor padrao da classe
		 */
        BancoDeDados();

        /**
		 * @brief Realiza o cadastro de um novo hóspede
		 * e informa se o usuário foi cadastrado.
         * @return bool cadastro realizado ou nao
		 */
        bool cadastrar_hospede(std::string,std::string,std::string,std::string,std::string);

        /**
		 * @brief Realiza o login de um hóspede ou funcionário
		 * e informa se os dados de login estão corretos
         * @param email Email de login
         * @param senha Senha de login
         * @return bool login realizado ou nao
		 */
        bool login(std::string email, std::string senha);

        /**
		 * @brief Destrutor da classe
		 */
		~BancoDeDados();
};

#endif
