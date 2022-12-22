#ifndef PESSOA_H
#define PESSOA_H

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
		 * @brief Verifica a informacao de login
		 * e retorna se o email recebido é igual ou diferente
		 * @param email email para comparar
		 * @return bool true se email é igual
		 * @return bool false se email é diferente
		 */
		virtual bool verificar_email(std::string email) = 0;

		/**
		 * @brief Verifica a informacao de login
		 * e retorna se a senha recebido é igual ou diferente
		 * @param senha senha para comparar
		 * @return bool true se senha é igual
		 * @return bool false se senha é diferente
		 */
		virtual bool verificar_senha(std::string senha) = 0;

		/**
		 * @brief Destrutor da classe
		 */
		virtual ~Pessoa() = default;
};

#endif
