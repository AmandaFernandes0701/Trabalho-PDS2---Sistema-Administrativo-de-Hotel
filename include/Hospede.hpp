#ifndef HOSPEDE_H
#define HOSPEDE_H

#include "Pessoa.hpp"
#include "BancoDeDados.hpp"

/**
 * @brief Classe responsavel pela dados dos hospedes
 */
class Hospede : Pessoa{
	private:
		/**
		 * @brief CPF da pessoa
		 */
		std::string cpf;
		/**
		 * @brief Numero de telefone da pessoa
		 */
        std::string numero_telefone;

	public:
		/**
		 * @brief Construtor padrao da classe
		 * @param nome Nome do hóspede
		 * @param email Email do hóspede
		 * @param senha Senha do hóspede
		 * @param cpf CPF do hóspede
		 * @param numero_telefone Telefone do hóspede
		 */
		Hospede(std::string nome, std::string email, std::string senha,
				std::string cpf, std::string numero_telefone);

		/**
		 * @brief Construtor alternativo da classe
		 * @param email Email do hóspede
		 * @param senha Senha do hóspede
		 */
		Hospede(std::string email, std::string senha);

        /**
		 * @brief Verifica a informacao de login e senha
		 * e retorna se as informacoes estao corretas
		 * @param banco_de_dados Ponteiro para o banco de dados
		 * @return bool Login realizado ou nao
		 */
		bool login(BancoDeDados* banco_de_dados) override;

        /**
		 * @brief Realiza o cadastro do hospede no sistema
		 * e retorna se o cadastro foi efetuado com sucesso
		 * @param banco_de_dados Ponteiro para o banco de dados
		 * @return bool Cadastro realizado ou nao
		 */
		bool cadastrar(BancoDeDados* banco_de_dados);
		
};

#endif
