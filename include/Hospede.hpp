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
		string cpf;
		/**
		 * @brief Numero de telefone da pessoa
		 */
        string numero_telefone;

	public:
        /**
		 * @brief Verifica a informacao de login e senha
		 * e retorna se as informacoes estao corretas
		 * @return bool Login realizado ou nao
		 */
		bool login(string, string) override;

        /**
		 * @brief Realiza o cadastro do hospede no sistema
		 * e retorna se o cadastro foi efetuado com sucesso
		 * @param banco_de_dados Ponteiro para o banco de dados.
		 * @return bool Cadastro realizado ou nao
		 */
		bool cadastrar(BancoDeDados* banco_de_dados);
		
};

#endif
