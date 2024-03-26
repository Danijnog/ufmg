#include "../include/produto.h"
#include "../include/supermercado.h"
#include "../include/funcionario.h"
#include "../include/gerente.h"
#include "../include/caixa.h"
#include "../include/produto.h"
#include "../include/cliente.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>

int main(){
  string a, b, c, d, e, f;
  a="bis";
  b="leite";
  c="arroz";
  d="feijao";
  e="refrigerante";
  f="manteiga";
  
  
 
  vector<Produto*> produtos;
  Produto bis= Produto(a, 140, 7.50);
  Produto leite= Produto(b, 100, 4);
  Produto arroz= Produto(c, 45, 15.75);
  Produto feijao= Produto(d, 90, 14.90);
  Produto refrigerante= Produto(e, 120, 8);
  Produto manteiga= Produto(f, 50, 11.90);


  
  Supermercado epa;
  epa.insere_produto(bis);
  epa.insere_produto(leite);
  epa.insere_produto(arroz);
  epa.insere_produto(feijao);
  epa.insere_produto(refrigerante);
  epa.insere_produto(manteiga);
 

  //para nao ter varios ifs, vou colocar os produtos em um vetor
  produtos.push_back(&bis);
  produtos.push_back(&leite);
  produtos.push_back(&arroz);
  produtos.push_back(&feijao);
  produtos.push_back(&refrigerante);


  
  vector<Cliente*> clientes; //para facilitar achar o cliente
                           //qnd for emitir nota fiscal  

  string nome_gerente, nome_gerente2, nome_cliente, nome_caixa;
  int loop_geral=1;
  int aux=0, loop_gerente=0, loop_cliente=0, loop_caixa=0, 
  acao=0;
  
  int i_gerente=0;//para poder verificar se eh
  //a primeira vez que ta usando esse tipo de usuario


  while(loop_geral==1){
  cout<< endl << "Selecione seu tipo de usuario: " <<endl;
  cout<< "1-Gerente"<<endl<<"2-Cliente"<<endl<<"3-Caixa"<<endl;
  cout << "Digite o numero e pressione Enter: ";
  cin>> aux;
  if(aux != 1 && aux != 2 && aux != 3) {
    throw NumeroInvalidoException();
  }
  
  if(aux==1){  //Gerente
    cout<< "Digite seu nome: ";
    if(i_gerente==0){
    cin >> nome_gerente;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    loop_gerente=1;
    i_gerente++;
    }else{
      cin>>nome_gerente2;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      if(nome_gerente!=nome_gerente2){
        cout<<endl<<"Voce nao eh o gerente desse supermercado!"<<endl;
        loop_gerente=0;
      }else{
        loop_gerente=1;
      }
    }  
     while(loop_gerente==1){
      Gerente g=Gerente(nome_gerente, 1, &epa);
      cout << endl<<"O que deseja fazer "<<nome_gerente<< "?";
      cout<<endl<< "1-Consultar saldo no caixa do supermercado";
      cout<<endl<<"2-Ver a quantidade de produtos no estoque";
      cout<<endl<<"3-Atualizar o estoque";
      cout<<endl<<"4-Atualizar as promocoes";
      cout<<endl<<"5-Alterar o seu tipo de usuario";
      cout<<endl<<"Digite o numero: ";
      cin >> acao;
       if(acao==1){
        cout<<endl; 
         cout<<"O saldo do supermercado eh: "; 
         cout<< g.consulta_saldo_caixa()<< endl;
       }else if(acao==2){
         cout<<endl;
         g.ver_qtd_produtos();
         cout<<endl;
       }else if(acao==3){
         cout<<endl;
         g.atualiza_estoque();
         g.ver_qtd_produtos();
         cout<< endl<<"Estoque atualizado !" << endl;
        }else if(acao==4){
         cout<<endl;
         g.atualiza_promocoes();
         g.ver_qtd_produtos();
         cout<<endl<<"Promocoes atualizadas !"<<endl;
        }else if(acao==5){
         loop_gerente=0;
        }
      }
    }else if(aux==2){ //Cliente
     cout<< "Digite seu nome: ";
     cin >> nome_cliente; 
     cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
     Cliente c= Cliente(nome_cliente);
     clientes.push_back(&c);
     loop_cliente=1;  
    for(Cliente *x: clientes){
      if(nome_cliente==x->retorna_nome()){
     while(loop_cliente==1){
      cout<<endl<< "1-Ver lista de produtos";
      cout<<endl<<"2-Ver lista de produtos em promocao";
      cout<<endl<<"3-Comprar um produto";
      cout<<endl<<"4-Alterar seu tipo de usuario";
      cout<<endl<<"Digite o numero: ";
      cin >> acao;
       if(acao==1){
         cout<< endl;
         x->ver_lista_produtos(epa);
         cout<<endl;
       }else if(acao==2){
         cout<<endl;
         x->ver_lista_promocional(epa);
         cout<<endl;
       }else if(acao==3){
         string produto;
         int qnt=0;
         cout<< endl;
         cout<< "Digite o nome do produto que quer comprar: ";
         cin>> produto;
         cout<<endl;
         cout<< "Digite quantas unidades quer comprar: ";
         cin>>qnt;
         for(Produto *p: produtos){ 
           if(p->retorna_nome()==produto){
             if(qnt > p->retorna_quantidade() || qnt<=0){ 
              while(qnt > p->retorna_quantidade() || qnt<=0){
               if(qnt > p->retorna_quantidade()){  
                cout<<endl<<"Nao ha essa quantidade no estoque,";
                cout<<" digite uma quantidade menor: "<<endl;
                cin>>qnt;
                }else if(qnt<=0){
                 cout<<endl<<"Digite uma quantidade valida:"<<endl;
                 //throw SaldoNegativoException();
                 cin>>qnt;
                }
               }
              } 
             float gasto= qnt*p->retorna_preco();
             x->comprar_produto(*p, &epa, qnt);
             cout<< "Compra efetuada! ";
             cout<< "Voce gastou "<<"R$"<<gasto<<endl;
             } 
           }
         
          }else if(acao==4){
            loop_cliente=0;
          }
        
      }
     }   
    } 
  }else if(aux==3){  //caixa 
     cout<< "Digite seu nome: ";
     cin >> nome_caixa;   
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     Caixa caixa=Caixa(nome_caixa, 43);
    loop_caixa=1;
    while(loop_caixa==1){
      cout << endl<<"O que deseja fazer "<<nome_caixa<< "?";
      cout<<endl<< "1-Emitir nota fiscal de um cliente";
      cout<<endl<< "2-Alterar o seu tipo de usuario";
      cout<<endl<<"Digite o numero: ";
      cin >> acao;
      if(acao==1){
        if(clientes.empty()==false){
        string cliente_nome;
        cout<<endl<<"Digite o nome do cliente: "<<endl;
        cin>>cliente_nome;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  
         for(Cliente *x: clientes){
           if(x->retorna_nome()==cliente_nome){
            caixa.emitirNotaFiscal(*x);
             cout<<endl<<"entrou if";
           }
          }
         }else{
          cout<<endl<<"Nenhum cliente foi registrado!"<<endl;
         }
        }else if(acao==2){
        loop_caixa=0;
      }
     }
    
}
  
}
  
return 0;
  
}