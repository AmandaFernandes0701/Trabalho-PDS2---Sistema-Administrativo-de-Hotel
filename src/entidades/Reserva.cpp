#include "Reserva.hpp"

Reserva::Reserva(Data* data, Quarto quarto, Hospede* hospede){
    this->data = data;
    this->quarto = new Quarto(quarto);
    this->hospede = hospede;
}

int Reserva::get_dia(){
    return this->data->get_dia();
}

int Reserva::get_mes(){
    return this->data->get_mes();
}

int Reserva::get_ano(){
    return this->data->get_ano();
}

int Reserva::get_quarto(){
    return this->quarto->get_quarto();
}

std::string Reserva::get_nome(){
    return this->hospede->get_nome();
}

std::string Reserva::get_email(){
    return this->hospede->get_email();
}

bool Reserva::verificar_data(Data data_para_verificar){
    return this->data->verificar_data(data_para_verificar);
}