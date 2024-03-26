#include "../third_party/doctest.h"
#include "../include/supermercado.h"
#include "../include/produto.h"
#include <iostream>


TEST_CASE("Testando o supermercado") {
    Supermercado s;
    Produto p1 = Produto("Fanta", 3, 5.4);

    SUBCASE("Testando o insere e remove o produto") {
        s.insere_produto(p1);
        CHECK(s.retorna_qtd_produtos() == 1);
        s.imprime_lista_produtos();

        s.remove_produto(p1);
        CHECK(s.retorna_qtd_produtos() == 0);
        s.imprime_lista_produtos();
    }
    cout << "-----------" << endl;

    SUBCASE("Testando o insere e remove produto promocional") {
        Produto p2 = Produto("Pizza", 8, 30.5);
        Produto p3 = Produto("Coquinha light", 1, 4.5);
        s.insere_produto_promocional(p2);
        s.insere_produto_promocional(p3);
        CHECK(s.retorna_qtd_promocional() == 2);
        s.imprime_lista_promocional();

        s.remove_produto(p2);
        CHECK(s.retorna_qtd_promocional() == 1);
        s.imprime_lista_promocional();

    }
}

TEST_CASE("Testando o produto_comprado e o retorna_saldo_caixa") {
    Supermercado s;
    Produto p = Produto("Chocolate", 3, 7.5);
    s.insere_produto(p);
    s.produto_comprado(2, p);
    //CHECK(p.retorna_quantidade() == 1);
    CHECK(s.retorna_saldo_caixa() == doctest::Approx(15));

    Produto p2 = Produto("Cerveja", 10, 5.5);

    s.insere_produto_promocional(p2);
    s.produto_comprado(3, p2);
    CHECK(s.retorna_saldo_caixa() == doctest::Approx(31.5));

}

TEST_CASE("Testando o verifica promoções") {
    Supermercado s;
    Produto p = Produto("Bolacha", 140, 2.5);
    s.insere_produto(p);
    s.verifica_promocoes();
    CHECK(s.retorna_qtd_promocional() == 1);
    CHECK(s.retorna_qtd_produtos() == 0);

    Produto p2 = Produto("Cerveja", 10, 5.5);
    s.insere_produto_promocional(p2);
    s.verifica_promocoes();
    CHECK(s.retorna_qtd_produtos() == 1);
    
}

TEST_CASE("Testando o verifica estoque") {
    Supermercado s;
    Produto p = Produto("nescau", 3, 7.5);
    s.insere_produto(p);
    s.verifica_estoque();
    CHECK(s.retorna_qtd_produtos() == 1);

}

