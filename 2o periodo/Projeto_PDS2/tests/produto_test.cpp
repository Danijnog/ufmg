#include "../third_party/doctest.h"
#include "../include/produto.h"

TEST_CASE("Testando o produto") {
    Produto p = Produto("Fanta", 3, 4.7);
    CHECK(p.retorna_nome() == "Fanta");
    CHECK(p.retorna_preco() == doctest::Approx(4.7));
    CHECK(p.retorna_quantidade() == 3);

    SUBCASE("Testando o decrementa") {
        p.decrementa_quantidade(2);
        CHECK(p.retorna_quantidade() == 1);
    }
    SUBCASE("Testando o incrementa") {
        p.incrementa_quantidade(2);
        CHECK(p.retorna_quantidade() == 5);
    }
}


