#include "../include/gerente.h"
#include <iostream>

Gerente::Gerente(int matricula, string nome) : Funcionario(matricula, nome) {
    _departamento = "Gerente";
}

void Gerente::registra_ponto(registroPonto p) {
     cout << "Gerente nao bate ponto" << endl;
}