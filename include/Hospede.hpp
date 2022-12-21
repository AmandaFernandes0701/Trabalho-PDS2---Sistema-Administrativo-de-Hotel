#ifndef HOSPEDE_H
#define HOSPEDE_H

#include "Pessoa.hpp"
// #include "BancoDeDados.hpp"

#include <vector>

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
		 * @brief Verifica a informacao de login
		 * e retorna se o email recebido é igual ou diferente
		 * @param email email para comparar
		 * @return bool true se email é igual
		 * @return bool false se email é diferente
		 */
		bool verificar_email(std::string email) override;

		/**
		 * @brief Verifica a informacao de login
		 * e retorna se a senha recebido é igual ou diferente
		 * @param senha senha para comparar
		 * @return bool true se senha é igual
		 * @return bool false se senha é diferente
		 */
		bool verificar_senha(std::string senha) override;

		/**
		 * @brief Retorna o nome do hóspede
		 * @return std::string nome do hóspede
		 */
		std::string get_nome();
		/**
		 * @brief Retorna o email do hóspede
		 * @return std::string email do hóspede
		 */
		std::string get_email();
		/**
		 * @brief Retorna o senha do hóspede
		 * @return std::string senha do hóspede
		 */
		std::string get_senha();
		/**
		 * @brief Retorna o cpf do hóspede
		 * @return std::string cpf do hóspede
		 */
		std::string get_cpf();
		/**
		 * @brief Retorna o telefone do hóspede
		 * @return std::string telefone do hóspede
		 */
		std::string get_telefone();

};

#endif
