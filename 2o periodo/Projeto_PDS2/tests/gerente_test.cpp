#include "../include/gerente.h"
#include "../include/supermercado.h"
#include "../third_party/doctest.h"
#include <exception>

TEST_CASE("Testando o gerente") {
    Supermercado s;
    Gerente g = Gerente("Armando", 1, &s);
    REQUIRE(g.getNome() == "Armando");
    REQUIRE(g.getId() == 1);
    //testar o atualiza_promocoes
    g.atualiza_promocoes();
}

TEST_CASE("Testando o consulta saldo caixa do gerente") {
    Supermercado s;
    Gerente g = Gerente("Diana", 1, &s);
    REQUIRE(g.consulta_saldo_caixa() == 0);

    //CHECK_THROWS_AS(g.consulta_saldo_caixa(), std::exception());//testando saldo negativo
}