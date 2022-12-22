#ifndef QUARTO_H
#define QUARTO_H

/**
 * @brief Classe responsavel por gerenciar os quartos do hotel.
 */
class Quarto {
    private:
        int numero_quarto;

    public:
        /**
		 * @brief Construtor padrao da classe.
		 */
        Quarto();
        /**
		 * @brief Construtor alternativo da classe.
         * 
         * @param quarto número do quarto
		 */
        Quarto(int quarto);

        /**
		 * @brief Retorna o número do quarto
         * 
         * @return int quarto
		 */
        int get_quarto();
};

#endif
