#include "../include/estagiario.h"
#include <iostream>

using namespace std;

Estagiario::Estagiario(int matricula, string nome) : Funcionario(matricula, nome) {
}

 void Estagiario::registra_ponto(registroPonto p) {
     cout << "Estagiario nao bate ponto em horarios de intervalo" << endl;
}

void Estagiario::registra_ponto_estagiario(registroPonto p) {
    pontos.push_back(p);
}