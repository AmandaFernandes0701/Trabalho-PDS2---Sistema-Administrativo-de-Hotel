#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using namespace std;

/**
 * @brief Classe abstrata responsavel pela dados mais basicos
 * de uma pessoa.
 */
class Pessoa{
	protected:
		/**
		 * @brief Nome da pessoa
		 */
		string nome;
		/**
		 * @brief Email da pessoa
		 */
		string email;
		/**
		 * @brief Senha da pessoa
		 */
		string senha;

	public:
		/**
		 * @brief Verifica a informacao de login e senha
		 * e retorna se as informacoes estao corretas
		 * @return bool Login realizado ou nao
		 */
		virtual bool login(string, string) = 0;

		/**
		 * @brief Destrutor da classe
		 */
		virtual ~Pessoa() = default;
};

#endif
