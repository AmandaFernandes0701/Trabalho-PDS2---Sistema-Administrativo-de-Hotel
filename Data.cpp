#include "Data.hpp"


int Data::get_dia(){
    return this->dia;
}

int Data::get_mes(){
    return this->mes;
}

int Data::get_ano(){
    return this->ano;
}

void Data::set_dia(int dia){
    this->dia = dia;
}

void Data::set_mes(int mes){
    this->mes = mes;
}

void Data::set_ano(int ano){
    this->ano = ano;
}

bool Data::verificar_data(Data data){
    if(this->dia == data.get_dia() && this->mes == data.get_mes() &&
    this->ano == data.get_ano())
        return true;
    return false;
}