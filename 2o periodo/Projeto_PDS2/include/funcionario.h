#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

using namespace std;

class Funcionario {
    protected:
        string _nome;
        int _id;

    public:
        /**
        *@brief Método construtor de um funcionario
        *@param nome é o nome do funcionario
        *@param id é o id do funcionario
        */
        Funcionario(string nome, int id);

        /**
        *@brief Método que retorna o nome do funcionario
        *@return retorna o nome do funcionario
        */
        string getNome();

        /**
        *@brief Método que retorna o id do funcionario
        *@return retorna o id do funcionario
        */
        int getId();

         /**
        *@brief Método que introduz um nome a um funcionario
        *@param nome é o nome que deve ser atribuidio ao funcionario
        */
        void setNome(string nome);

         /**
        *@brief Método que introduz um id a um funcionario
        *@param id é o nome que deve ser atribuidio ao funcionario
        */
        void setId(int id);
};

#endif