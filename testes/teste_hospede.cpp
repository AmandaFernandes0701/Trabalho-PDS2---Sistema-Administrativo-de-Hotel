#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Hospede.hpp"



// Testes com hóspede
TEST_CASE("Testando se o hospede foi iniciado corretamente"){
    Hospede hospede = Hospede("Chico Buarque de Holanda", "chico@gmail.com",
                            "o que sera", "11698599315", "1134569000");

    CHECK_EQ(hospede.get_nome(), "Chico Buarque de Holanda");
    CHECK_EQ(hospede.get_email(), "chico@gmail.com");
    CHECK_EQ(hospede.get_senha(), "o que sera");
    CHECK_EQ(hospede.get_cpf(), "11698599315");
    CHECK_EQ(hospede.get_telefone(), "1134569000");
}

TEST_CASE("Testando se o email e senha sao iguais aos dados corretos"){
    Hospede hospede = Hospede("Chico Buarque de Holanda", "chico@gmail.com",
                            "o que sera", "11698599315", "1134569000");

    CHECK_EQ(hospede.verificar_email("chico@gmail.com"), true);
    CHECK_EQ(hospede.verificar_senha("o que sera"), true);
}