#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Funcionario.hpp"



// Testes com funcionario
TEST_CASE("Testando se o email e senha sao iguais aos dados corretos"){
    Funcionario funcionario = Funcionario();

    CHECK_EQ(funcionario.verificar_email("funcionario@hotel.com"), true);
    CHECK_EQ(funcionario.verificar_senha("pds2"), true);
}

TEST_CASE("Testando se o email e senha sao diferentes dos dados corretos"){
    Funcionario funcionario = Funcionario();

    CHECK_EQ(funcionario.verificar_email("funcionario@hotel.com.br"), false);
    CHECK_EQ(funcionario.verificar_senha("PDS2"), false);
}