#include "Quarto.hpp"

Quarto::Quarto(){}

Quarto::Quarto(int quarto){
    this->numero_quarto = quarto;
}

int Quarto::get_quarto(){
    return this->numero_quarto;
}