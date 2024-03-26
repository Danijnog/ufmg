#include "../include/cliente.h"
#include <iostream>

using namespace std;

Cliente::Cliente(string nome){
  _nome=nome;
}

string Cliente::retorna_nome(){
  return _nome;
}

void Cliente::ver_lista_produtos(Supermercado s){
   return s.imprime_lista_produtos();
}

void Cliente::ver_lista_promocional(Supermercado s){
  s.imprime_lista_promocional();
}

void Cliente::comprar_produto(Produto p, Supermercado *s, int quantidade){

s->produto_comprado(quantidade, p);

int produto_repetido=0;
  
 if(_carrinho.empty()==false){  
  for(auto it=_carrinho.begin();it!=_carrinho.end();it++){
     if(it->retorna_nome()==p.retorna_nome()){
      it->incrementa_quantidade(quantidade);
       produto_repetido=1;
      }
  }
  if(produto_repetido==0){
    Produto aux=Produto(p.retorna_nome(), quantidade, 
    p.retorna_preco());
    _carrinho.push_back(aux);
  }
  
 }else{
  Produto aux=Produto(p.retorna_nome(), quantidade, 
  p.retorna_preco());
  _carrinho.push_back(aux);
 }
     
}
  
list<Produto>* Cliente::retorna_carrinho(){
  return &_carrinho;
}
