#ifndef PROGRAMADOR_H
#define PROGRAMADOR_H

#include "funcionario.h"

class Programador : public Funcionario {

    private:

    public:
        Programador(int matricula, string nome);
        virtual void registra_ponto(registroPonto p) override;

};


#endif