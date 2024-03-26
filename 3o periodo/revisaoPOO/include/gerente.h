#ifndef GERENTE_H
#define GERENTE_H

#include "funcionario.h"

class Gerente : public Funcionario {

    private:

    public:
        Gerente(int matricula, string nome);
        virtual void registra_ponto(registroPonto p) override;
};

#endif