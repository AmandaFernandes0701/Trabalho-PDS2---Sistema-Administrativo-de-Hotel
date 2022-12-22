#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "BancoDeDados.hpp"


BancoDeDados banco_de_dados = BancoDeDados();


// Testes com login do funcionário
TEST_CASE("Testando se funcionario loga corretamente"){
    CHECK(banco_de_dados.login_funcionario("funcionario@hotel.com",
                                            "pds2") == 1);
}

TEST_CASE("Testando se funcionario nao consegue logar"){
    CHECK(banco_de_dados.login_funcionario("funcionario@gmail.com",
                                            "pds2") == 0);
}



// Testes com login de hóspedes
TEST_CASE("Testando se hospede loga corretamente"){
    CHECK(banco_de_dados.login_hospede("sandrinha@ufmg.br", "chapaunica") == 1);
}

TEST_CASE("Testando se hospede loga corretamente"){
    CHECK(banco_de_dados.login_hospede("sandrinha@ufmg.br", "chapaunica") == 1);
}

TEST_CASE("Testando se hospede loga corretamente"){
    CHECK(banco_de_dados.login_hospede("milton@gmail.com", "clubedaesquina") == 1);
}

TEST_CASE("Testando se hospede nao consegue logar"){
    CHECK(banco_de_dados.login_hospede("milton@gmail.com", "clube da esquina") == 0);
}



// Teste com login para novo cadastro de hóspede
TEST_CASE("Testando se login para novo cadastro e feito corretamente") {
    CHECK_EQ(true, banco_de_dados.cadastrar_hospede("Julius","julius@gmail.com",
                                                    "desconto", "11564578691",
                                                    "+1583334121"));
    CHECK_EQ(true, banco_de_dados.login_hospede("julius@gmail.com", "desconto"));
}



// Teste com conversão de data
TEST_CASE("Testando se data e convertida corretamente"){
    Data data = banco_de_dados.converter_string_para_data("23/12/2022");
    CHECK_EQ(23, data.get_dia());
    CHECK_EQ(12, data.get_mes());
    CHECK_EQ(2022, data.get_ano());
}



// Teste para verificar se exceção é lançada corretamente
TEST_CASE("Testando se excecao e lancada para data digitada no formato errado") {
  CHECK_THROWS_AS(banco_de_dados.converter_string_para_data("23-12-2022"), std::exception);
  CHECK_THROWS_AS(banco_de_dados.converter_string_para_data("23/12-2022"), std::exception);
}

