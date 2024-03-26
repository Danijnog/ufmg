#include "../include/funcionario.h"
#include <iostream>

#include <string>

Funcionario::Funcionario(string nome, int id) {
    _nome = nome;
    _id = id;
}

void Funcionario::setNome(string nome) {
    _nome = nome;
}

string Funcionario::getNome() {
    return _nome;
}

void Funcionario::setId(int id) {
    _id = id;
}

int Funcionario::getId() {
    return _id;
}