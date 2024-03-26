#include "../include/funcionario.h"

Funcionario::Funcionario(int matricula, string nome) {
    _matricula = matricula;
    _nome_funcionario = nome;
}

int Funcionario::get_matricula() {
    return _matricula;
}

string Funcionario::get_nome() {
    return _nome_funcionario;
}