#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "registroPonto.h"

#include <string>
#include <vector>
using namespace std;

class Funcionario {
    protected:
        int _matricula;
        string _nome_funcionario;
        string _departamento;
        vector<registroPonto> pontos;

    public:
        Funcionario(int matricula, string nome);
        int get_matricula();
        string get_nome();
        virtual void registra_ponto(registroPonto p) = 0;

};


#endif