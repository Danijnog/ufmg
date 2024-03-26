#ifndef CAIXA_H
#define CAIXA_H
#include "funcionario.h"
#include "produto.h"
#include "supermercado.h"
#include "cliente.h"

#include <string>
#include <list>

using namespace std;

class Caixa : public Funcionario {

  private:
  /**
  *@brief Lista com de produtos comprados para emitir a nota fiscal
  */
    list<Produto> *_notaFiscal;

  public:
      /**
      *@brief Metodo construtor de um caixa
      *@param nome é o nome do caixa
      *@param id é o id do caixa
      */
      Caixa(string nome, int id);

     /**
      *@brief Método que emite a nota fiscal no cmd
      *@param c é o cliente que fez as compras
      */
      void emitirNotaFiscal(Cliente c); //emitir a nota fiscal de um produto comprado
        
         
};
#endif