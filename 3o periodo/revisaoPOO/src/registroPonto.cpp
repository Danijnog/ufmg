#include "../include/registroPonto.h"

using namespace std;

registroPonto::registroPonto(int matricula, string data) {
    _matricula_funcionario = matricula;
    _data = data;
}

void registroPonto::registra_inicio_jornada(string h) {
    _hora_inicio = h;
}

void registroPonto::registra_inicio_intervalo(string h) {
   _hora_inicio_intervalo = h;
}

void registroPonto::registra_fim_intervalo(string h) {
    _hora_fim_intervalo = h;
}

 void registroPonto::registra_fim_jornada(string h) {
    _hora_fim = h;
}

string registroPonto::get_inicio_jornada() {
    return _hora_inicio;
}

string registroPonto::get_fim_jornada() {
    return _hora_fim;
}
