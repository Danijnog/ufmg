#include "../include/produto.h"

Produto::Produto(string nome, int qtd, float preco){
    _nome = nome;
    _qtd = qtd;
    _preco = preco;
}

string Produto::retorna_nome() {
    return _nome;
}

float Produto::retorna_preco() {
    return _preco;
}

void Produto::decrementa_quantidade(int qtd) {
    _qtd -= qtd;
}

void Produto::incrementa_quantidade(int qtd) {
    _qtd += qtd;
}

int Produto::retorna_quantidade() {
    return _qtd;
}

