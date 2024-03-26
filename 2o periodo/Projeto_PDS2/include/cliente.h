#ifndef CLIENTE_H
#define CLIENTE_H
#include "supermercado.h"
#include "produto.h"

#include <string> 
#include<list>

using namespace std;

class Cliente{

private:
  string _nome;
  list<Produto> _carrinho; //carrinho de compras
                           //lista com produtos comprados

public:
   /**
   *@brief Método construtord de um cliente
   *@param nome é o nome do cliente
   */
   Cliente(string nome);

   /**
   *@brief Método que retorna o nome do cliente
   *@return retorna o nome do cliente
   */
   string retorna_nome();

   /**
   *@brief Método que retorna os produtos que o cliente quer comprar
   *@return retorna os produtos que o cliente quer comprar
   */
   list<Produto>* retorna_carrinho();

   /**
   *@brief Método que coloca o produto no carrinho do cliente
   *@param p é o produto que o cliente quer comprar
   *@param s é o ponteiro referente a o supermercado
   *@param quantidade é a quantidade desse produto que o cliente quer colocar no carrinho
   */
   void comprar_produto(Produto p, Supermercado *s, int quantidade);
   void ver_lista_produtos(Supermercado s);

   /**
   *@brief Método que imprime no cmd a lista de produtos na promoção
   *@param s é o supermercado com os produtos que estão na promoção
   */
   void ver_lista_promocional(Supermercado s);
  
};
#endif
