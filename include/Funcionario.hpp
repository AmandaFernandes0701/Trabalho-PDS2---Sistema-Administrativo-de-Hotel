#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Pessoa.hpp"

/**
 * @brief Classe responsavel pelos dados dos funcionários
 */
class Funcionario : Pessoa {

	public:
        /**
		 * @brief Construtor padrao da classe.
		 * Inicializa com o email padrão: "funcionario@hotel.com"
		 * e senha padrão: "pds2"
		 */
        Funcionario();

		/**
		 * @brief Verifica a informacao de login
		 * e retorna se o email recebido é igual ou diferente
		 * 
		 * @param email email para comparar
		 * @return bool true se email é igual
		 * @return bool false se email é diferente
		 */
		bool verificar_email(std::string email) override;

		/**
		 * @brief Verifica a informacao de login
		 * e retorna se a senha recebido é igual ou diferente
		 * 
		 * @param senha senha para comparar
		 * @return bool true se senha é igual
		 * @return bool false se senha é diferente
		 */
		bool verificar_senha(std::string senha) override;
};

#endif
