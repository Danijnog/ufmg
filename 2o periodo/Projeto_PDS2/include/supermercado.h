#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#include <vector> 
#include "produto.h"
#include <exception>

using namespace std;

class NumeroInvalidoException : public exception {
  public:
    const char *what() const noexcept {
      return "Numero invalido! :(";
    }
};

class Supermercado{
    
    private:
      vector<Produto> _lista_produtos;
      float _saldo_caixa = 0;
      vector<Produto> _lista_promocional;

    public:
      /**
      @brief Método que retorna o saldo do caixa
      @return retorna o saldo do caixa
      */
      float retorna_saldo_caixa();

      /**
      @brief Método que coloca um produto novo (p) na lista de produtos do supermercado
      */
      void insere_produto(Produto p);

      /**
      @brief Método que coloca um produto novo (p) na lista de produtos promocionais do supermercado
      */
      void insere_produto_promocional(Produto p);

      /**
      @brief Método que remove um produto da lista que ele estiver do supermercado
      @param p é o produto que deve ser retirado da lista
      */
      void remove_produto(Produto p);

      /**
      *@brief Imprime a os produtos no vetor _lista_produtos
      */
      void imprime_lista_produtos();

      /**
      *@brief Imprime a os produtos no vetor _lista_promocional
      */
      void imprime_lista_promocional();

      /**
      *@brief Decrementa a quantidade do produto com as unidades
      *compradas, aumenta o saldo do supermercado com o respectivo
      *valor
      *@param qnt Quantidade que esta sendo comprada
      *@param nome_produto Nome do produto que ira comprar
      *@param preco Preco do produto
      */
      void produto_comprado(int qtd, Produto p);

      /**
      *@brief Coloca em promocao produtos acima com quantiade acima
      * de 100
      */
      void verifica_promocoes();

      /**
      *@brief Aumenta para 70 unidades produtos com quantiade abaixo
      * de 50
      */
      void verifica_estoque();

      /**
      *@brief retorna a quantidade de produtos na lista
      */
      int retorna_qtd_produtos();

      /**
      *@brief retorna a quantidade de produtos na lista de produtos na promoção
      */
      int retorna_qtd_promocional();
};

#endif
