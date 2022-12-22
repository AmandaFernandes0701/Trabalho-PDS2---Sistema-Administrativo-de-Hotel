#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Reserva.hpp"



// Testes com reservas
TEST_CASE("Testando se a classe e iniciada corretamente"){
    Data* data = new Data();
    data->set_dia(23);
    data->set_mes(12);
    data->set_ano(2022);

    Quarto quarto = Quarto(101);

    Hospede* hospede = new Hospede("Chico Buarque de Holanda", "chico@gmail.com",
                            "o que sera", "11698599315", "1134569000");

    Reserva reserva = Reserva(data, quarto, hospede);

    CHECK_EQ(reserva.get_dia(), 23);
    CHECK_EQ(reserva.get_mes(), 12);
    CHECK_EQ(reserva.get_ano(), 2022);

    CHECK_EQ(reserva.get_quarto(), 101);

    CHECK_EQ(reserva.get_nome(), "Chico Buarque de Holanda");
    CHECK_EQ(reserva.get_email(), "chico@gmail.com");
}

TEST_CASE("Testando se a classe e iniciada corretamente e data da reserva esta correta"){
    Data* data = new Data();
    data->set_dia(23);
    data->set_mes(12);
    data->set_ano(2022);

    Data data_certa = Data();
    data_certa.set_dia(23);
    data_certa.set_mes(12);
    data_certa.set_ano(2022);

    Quarto quarto = Quarto(101);

    Hospede* hospede = new Hospede("Chico Buarque de Holanda", "chico@gmail.com",
                            "o que sera", "11698599315", "1134569000");

    Reserva reserva = Reserva(data, quarto, hospede);

    CHECK_EQ(reserva.verificar_data(data_certa), true);
}

TEST_CASE("Testando se a classe e iniciada corretamente e data da reserva esta incorreta"){
    Data* data = new Data();
    data->set_dia(23);
    data->set_mes(12);
    data->set_ano(2022);

    Data data_errada = Data();
    data_errada.set_dia(23);
    data_errada.set_mes(12);
    data_errada.set_ano(2023);

    Quarto quarto = Quarto(101);

    Hospede* hospede = new Hospede("Chico Buarque de Holanda", "chico@gmail.com",
                            "o que sera", "11698599315", "1134569000");

    Reserva reserva = Reserva(data, quarto, hospede);

    CHECK_EQ(reserva.verificar_data(data_errada), false);

}