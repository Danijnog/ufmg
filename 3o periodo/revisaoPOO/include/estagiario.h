#ifndef ESTAGIARIO_H
#define ESTAGIARIO_H

#include "funcionario.h"


class Estagiario : public Funcionario {

    private:   

    public:
        Estagiario(int matricula, string nome);
        virtual void registra_ponto(registroPonto p) override;
        void registra_ponto_estagiario(registroPonto p);

};


#endif