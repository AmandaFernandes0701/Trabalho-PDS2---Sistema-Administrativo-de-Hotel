#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Data.hpp"



// Testes com datas
TEST_CASE("Testando se a data e iniciada corretamente"){
    Data* data = new Data();
    data->set_dia(23);
    data->set_mes(12);
    data->set_ano(2022);

    CHECK_EQ(data->get_dia(), 23);
    CHECK_EQ(data->get_mes(), 12);
    CHECK_EQ(data->get_ano(), 2022);
    delete data;
}

TEST_CASE("Testando se a verificacao da data esta correta"){
    Data* data = new Data();
    data->set_dia(23);
    data->set_mes(12);
    data->set_ano(2022);

    Data segunda_data = Data();
    segunda_data.set_dia(23);
    segunda_data.set_mes(12);
    segunda_data.set_ano(2022);

    CHECK_EQ(data->verificar_data(segunda_data), true);

    delete data;
}

TEST_CASE("Testando se a verificacao da data falha"){
    Data* data = new Data();
    data->set_dia(23);
    data->set_mes(12);
    data->set_ano(2022);

    Data segunda_data = Data();
    segunda_data.set_dia(01);
    segunda_data.set_mes(01);
    segunda_data.set_ano(2023);

    CHECK_EQ(data->verificar_data(segunda_data), false);

    delete data;
}