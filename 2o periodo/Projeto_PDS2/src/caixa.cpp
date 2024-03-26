#include "../include/caixa.h"
#include "../include/supermercado.h"
#include "../include/produto.h"
#include <string>
#include <iostream>
using namespace std;

Caixa::Caixa(string nome, int id) : Funcionario(nome, id) {


}

void Caixa::emitirNotaFiscal(Cliente c){
  _notaFiscal= c.retorna_carrinho();
  float total=0;
  for(Produto p: *_notaFiscal){
    total+=( p.retorna_quantidade() * p.retorna_preco() );
  }
  
  cout<<endl;
  cout<<"NOTA FISCAL"<<endl;
  cout<< "Cliente: "<< c.retorna_nome()<<endl;

  for(Produto p: *_notaFiscal){
    cout<< p.retorna_nome()<< " "<< p.retorna_quantidade()<< "x R$" 
    <<p.retorna_preco()<<endl;
  }

  cout<<"Valor total da compra: R$"<< total<<endl;
}