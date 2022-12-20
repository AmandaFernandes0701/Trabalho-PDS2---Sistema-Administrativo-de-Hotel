#ifndef QUARTO_H
#define QUARTO_H

/**
 * @brief Classe responsavel por gerenciar os quartos do hotel.
 */
class Quarto {
    private:
        int numero_quarto;
        bool status_ocupado;
    public:
        Quarto(int);
};

#endif