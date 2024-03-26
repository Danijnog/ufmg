#include "../include/funcionario.h"
#include "../third_party/doctest.h"

TEST_CASE("Testando o funcionario") {
    Funcionario f = Funcionario("Joao", 1);
    REQUIRE(f.getNome() == "Joao");
    REQUIRE(f.getId() == 1);
    
    //testar o setNome e setId
    f.setNome("Maria");
    f.setId(2);
    REQUIRE(f.getNome() == "Maria");
    REQUIRE(f.getId() == 2);

}