#ifndef QUARTO_HPP
#define QUARTO_HPP

enum tipoDeQuarto
{
    comum = 1,
    suite,
    master
};

class Quarto
{
private:
    unsigned short int numero;
    tipoDeQuarto tipo;
    bool ocupado;

public:
    Quarto();
    Quarto(unsigned short int _numero,
           tipoDeQuarto _tipo,
           bool _ocupado);
    unsigned short int getNumero();
    tipoDeQuarto getTipo();
    bool isOcupado();
};

#endif