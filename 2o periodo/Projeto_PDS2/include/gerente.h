#ifndef GERENTE_H
#define GERENTE_H
#include "supermercado.h"
#include "funcionario.h"
#include <string>

using namespace std;

class Gerente : public Funcionario{
    
    private:
      Supermercado *_supermercado_referente; //o gerente tem que ser gerente de algum supermercado, esse supermercado 
                                            //sera o "supermercado referente" a esse gerente
                                            //alterei o supermercado para ponteiro, caso contrario, a funcao consulta_saldo_caixa
                                              //nao retorna valor atualizado caso um cliente tenha comprado algo

    public:
      /**
      *@brief Método contrutor de um Gerente
      *@param id é o id que deve ser atribuidio ao gerente
      *@param nome é o nome atribuido ao gerente
      *@param s é o supermercado referente
      */
      Gerente(string nome, int id, Supermercado *s );

      /**
      *@brief Método que retorna o saldo do caixa
      *@return retorna o saldo do caixa
      */
      float consulta_saldo_caixa();

      /**
      *@brief Atualiza a lista de promoções
      */
      void atualiza_promocoes();

      /**
      *@brief Atualiza o nomero de produtos no estoque
      */
      void atualiza_estoque();

      /**
      *@brief Método que imprime a quantidade de cada produto
      */
      void ver_qtd_produtos();

      
};

#endif
