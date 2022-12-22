#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Quarto.hpp"



// Teste para verificar se classe é instanciada corretamente
TEST_CASE("Testando se classe e instanciada corretamente") {
    Quarto quarto = Quarto(101);
    CHECK_EQ(quarto.get_quarto(), 101);
}
