#ifndef REGISTRO_PONTO
#define REGISTRO_PONTO

#include <string>

using namespace std;


class registroPonto {
    private:
        int _matricula_funcionario;
        string _data;
        string _hora_inicio;
        string _hora_inicio_intervalo;
        string _hora_fim_intervalo;
        string _hora_fim;

    public:
        registroPonto(int matricula, string data);
        void registra_inicio_jornada(string h);
        void registra_inicio_intervalo(string h);
        void registra_fim_intervalo(string h);
        void registra_fim_jornada(string h);

        string get_inicio_jornada();
        string get_fim_jornada();

};


#endif