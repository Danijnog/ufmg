#include "../third_party/doctest.h"
#include "../include/caixa.h"

TEST_CASE("Testando o caixa") {
    Caixa f = Caixa("Joao", 1);
    REQUIRE(f.getNome() == "Joao");
}