#ifndef HOSPEDE_H
#define HOSPEDE_H

#include "Pessoa.hpp"

/**
 * @brief Classe responsavel pela dados dos hospedes
 */
class Hospede : Pessoa{
	private:
		string cpf;
        string numero_telefone;

	public:
        /**
		 * @brief Verifica a informacao de login e senha
		 * e retorna se as informacoes estao corretas
		 * @return bool Login realizado ou nao
		 */
		bool login(string, string);

        /**
		 * @brief Realiza o cadastro do hospede no sistema
		 * e retorna se o cadastro foi efetuado com sucesso
		 * @return bool Cadastro realizado ou nao
		 */
		bool cadastrar(string, string);
		
};

#endif
