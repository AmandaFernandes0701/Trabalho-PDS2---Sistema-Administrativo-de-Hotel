#ifndef PESSOA_H
#define PESSOA_H

#include "BancoDeDados.hpp"
#include <string>

/**
 * @brief Classe abstrata responsavel pela dados basicos
 * de uma pessoa.
 */
class Pessoa{
	protected:
		/**
		 * @brief Nome da pessoa
		 */
		std::string nome;
		/**
		 * @brief Email da pessoa
		 */
		std::string email;
		/**
		 * @brief Senha da pessoa
		 */
		std::string senha;

	public:
		/**
		 * @brief Verifica a informacao de login e senha
		 * e retorna se as informacoes estao corretas
		 * @param banco_de_dados Ponteiro para o banco de dados
		 * @return bool Login realizado ou nao
		 */
		virtual bool login(BancoDeDados* banco_de_dados) = 0;

		/**
		 * @brief Destrutor da classe
		 */
		virtual ~Pessoa() = default;
};

#endif
