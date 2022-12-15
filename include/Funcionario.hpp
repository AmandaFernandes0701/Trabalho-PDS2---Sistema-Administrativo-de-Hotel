#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.hpp"

/**
 * @brief Classe responsavel pela dados dos funcionários
 */
class Funcionario : Pessoa {

	public:
        /**
		 * @brief Construtor padrao da classe
		 */
        Funcionario(string, string);
        /**
		 * @brief Verifica a informacao de login e senha
		 * e retorna se as informacoes estao corretas
		 * @return bool Login realizado ou nao
		 */
		bool login(string, string) override;
		
};

#endif