#include "../include/supermercado.h"
#include "../include/produto.h"
#include <vector>
#include <iostream>

using namespace std;

float Supermercado::retorna_saldo_caixa(){ 
  if(_saldo_caixa < 0) {
    throw NumeroInvalidoException();
  }
  return _saldo_caixa;
}

void Supermercado::insere_produto(Produto p){
    _lista_produtos.push_back(p);
}

void Supermercado::insere_produto_promocional(Produto p){
    _lista_promocional.push_back(p);
}

void Supermercado::remove_produto(Produto p){
  if(_lista_produtos.empty()==false){
      for(auto it=_lista_produtos.begin();
         it<=_lista_produtos.end();
         it++){
           if(p.retorna_nome()==it->retorna_nome()){
           _lista_produtos.erase(it);
           break;
           }
      }
    }

  if(_lista_promocional.empty()==false){
      for(auto it=_lista_promocional.begin();
          it<=_lista_promocional.end();
          it++){
            if(p.retorna_nome()==it->retorna_nome()){
            _lista_promocional.erase(it);
            break;
            }
      }
  
  }
}//acho q ta com bug essa funcao

void Supermercado::imprime_lista_produtos() {
  if(_lista_produtos.empty() == false)
  {
    cout<< "Lista de produtos: "<< endl;
    for(Produto p: _lista_produtos){
    cout << p.retorna_nome()<<" "<< p.retorna_quantidade() 
      << " R$"<< p.retorna_preco()<< endl;
    }
  }
  else
  {
    cout << "Lista de produtos vazia" << endl;
  }
} 

void Supermercado::imprime_lista_promocional() {
  if(_lista_promocional.empty()==false){
    cout<< "Produtos em promocao: "<< endl;
    for(Produto p: _lista_promocional){
    cout<<p.retorna_nome()<<" " << p.retorna_quantidade()
      << " R$"<< p.retorna_preco()<< endl;
    }
  }
  else
  {
    cout<<endl<<"Nao ha produtos em promocao!"<<endl;
  } 
}//imprime os produtos em promocao, mas se nao houver 
 //promocoes, imprime um aviso de que nao ha promocoes

void Supermercado::produto_comprado(int qnt, Produto p){

  if(_lista_produtos.empty()==false){ 
    
    for(auto it=_lista_produtos.begin(); 
        it!=_lista_produtos.end();it++){
      if(it->retorna_nome()==p.retorna_nome()){
        it->decrementa_quantidade(qnt);
        _saldo_caixa+= qnt*(it->retorna_preco() );
      }
    }
    
  }
  if(_lista_promocional.empty()==false){
  
    for(auto it=_lista_promocional.begin();
      it!=_lista_promocional.end(); it++){
      if(it->retorna_nome()==p.retorna_nome()){
        it->decrementa_quantidade(qnt);
        _saldo_caixa+= qnt*(it->retorna_preco() );
      }
    }

  }
    
  }// se as listas estiverem vazias, essa funcao nao faz nada
 //se nao tiver esses "if" verificando se elas estao vazias,
 // a funcao pode dar erro

void Supermercado::verifica_promocoes(){

  if(_lista_produtos.empty()==false){
      
    for(auto it=_lista_produtos.begin();
        it<=_lista_produtos.end();it++){
          
          if(it->retorna_quantidade()>QNT_MAX){
            float novo_preco=(it->retorna_preco()*(0.75) );//deu com 0.75 ao inves de 75/100
            Produto aux= Produto(it->retorna_nome(),
            it->retorna_quantidade(),
            novo_preco);
            
            _lista_promocional.push_back(aux);
            _lista_produtos.erase(it);
            
          }
          
        } 
  }

  if(_lista_promocional.empty()==false){
  
    for(auto it=_lista_promocional.begin();
      it<=_lista_promocional.end();it++){
            
        if(it->retorna_quantidade()<70){
          float valor_original=it->retorna_preco()+(it->retorna_preco()/3);
          Produto aux=Produto(it->retorna_nome(),
            it->retorna_quantidade(), valor_original);
          _lista_produtos.push_back(aux);
          _lista_promocional.erase(it);
          }
        
    }

  }
    
  } //coloca produtos em excesso no estoque para promocao
  //retira da promocao produtos que estavam na promocao e 
  //atingiram menos de 70 unidades no estoque, voltando o preco original


void Supermercado::verifica_estoque(){

 if(_lista_produtos.empty()==false){ 
   
     for(auto it=_lista_produtos.begin();
       it<=_lista_produtos.end();it++){
         if(it->retorna_quantidade()<QNT_MIN){
          it->incrementa_quantidade( 70 - it->retorna_quantidade() );
        }
     }

  }  
} //aumenta para 70 unidades produtos abaixo do minimo

int Supermercado::retorna_qtd_produtos() {
  return _lista_produtos.size();
}

int Supermercado::retorna_qtd_promocional() {
  return _lista_promocional.size();
}