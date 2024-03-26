#include "../include/gerente.h"
#include "../include/estagiario.h"
#include "../include/funcionario.h"
#include "../include/programador.h"
#include "../include/registroPonto.h"
#include <iostream>

using namespace std;

int main() {

    Programador p1 = Programador(222, "daniel");
    Programador p2 = Programador(323, "einstein");
    Gerente g1 = Gerente(100, "steve jobs");


    registroPonto primeiro_ponto = registroPonto(50, "30/01/2002");
    primeiro_ponto.registra_inicio_jornada("05:30");
    primeiro_ponto.registra_inicio_intervalo("12:00");
    primeiro_ponto.registra_fim_intervalo("13:00");
    primeiro_ponto.registra_fim_jornada("19:00");

    p1.registra_ponto(primeiro_ponto);
    p2.registra_ponto(primeiro_ponto);
    g1.registra_ponto(primeiro_ponto);

    cout << p1.get_nome() << endl;
    cout << p1.get_matricula() << endl;
}