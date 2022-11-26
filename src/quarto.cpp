#include "quarto.hpp"

Quarto::Quarto() {}
Quarto::Quarto(unsigned short int _numero,
               tipoDeQuarto _tipo,
               bool _ocupado) : numero(_numero),
                                tipo(_tipo),
                                ocupado(_ocupado) {}
unsigned short int Quarto::getNumero() { return numero; }
tipoDeQuarto Quarto::getTipo() { return tipo; }
bool Quarto::isOcupado() { return ocupado; }