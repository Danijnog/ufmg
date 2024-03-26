#include "../include/programador.h"
#include <iostream>
#include <string>
using namespace std;

Programador::Programador(int matricula, string nome) : Funcionario(matricula, nome) {
  
}

void Programador::registra_ponto(registroPonto p) {
    pontos.push_back(p);
    for(auto it = pontos.begin(); it != pontos.end(); it++) {
        cout << "O programador " << get_nome() << " registrou sua entrada as " << it->get_inicio_jornada() << "\n" << endl;
    }

    for(int i = 0; i < pontos.size(); i++) {
        cout << "O programador " << get_nome() << " registrou sua saida as " << pontos[i].get_fim_jornada() << "\n" << endl;
    }
}