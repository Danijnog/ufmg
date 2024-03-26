#include "../third_party/doctest.h"
#include "../include/cliente.h"
#include "../include/supermercado.h"

//testar o comprar_produto do cliente
TEST_CASE("Testando o cliente") {
    Supermercado s;
    Cliente c = Cliente("Armando");
    Produto p = Produto("Coca-Cola", 1.5, 1);
    c.comprar_produto(p, &s, 1);
    //CHECK(c.retorna_carrinho() == doctest::Approx(1.5));

}
/*
TEST_CASE("Testando a impressão") {
    Supermercado s;
    Cliente c = Cliente("Regina");
    Produto p = Produto("Coca-Cola", 1, 1.5);
    c.comprar_produto(p, &s, 1);
    s.insere_produto(p);
    s.imprime_lista_produtos();
    CHECK(c.ver_lista_produtos(s).size() == 1);

}
*/