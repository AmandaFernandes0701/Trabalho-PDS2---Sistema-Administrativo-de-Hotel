#ifndef DATA_H
#define DATA_H

/**
 * @brief Classe responsavel por representar uma data.
 */
class Data {
    private:
        int dia;
        int mes;
        int ano;

    public:
        /**
         * @brief Retorna o dia
         * @return int dia do mês
         */
        int get_dia();
        /**
         * @brief Retorna o mês
         * @return int mês do ano
         */
        int get_mes();
        /**
         * @brief Retorna o ano
         * @return int ano
         */
        int get_ano();

        /**
         * @brief Define o dia do mês
         * @param dia dia do mês
         */
        void set_dia(int dia);
        /**
         * @brief Define o mês do ano
         * @param mes mês do ano
         */
        void set_mes(int mes);
        /**
         * @brief Define o ano
         * @param ano ano
         */
        void set_ano(int ano);
};

#endif