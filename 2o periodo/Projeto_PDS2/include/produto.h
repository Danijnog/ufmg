#ifndef PROD_H
#define PROD_H

#define QNT_MIN 50
#define QNT_MAX 100

#include <string>

using namespace std;

class Produto {
    private:
        string _nome;
        int _qtd;
        float _preco;
        bool _promocao;

    public:
        /**
        *@brief Metodo construtor de um produto
        *@param nome é o nome do produto
        *@param qtd é a quantidade do produto que tem em estoque
        *@param preco é o preço do produto
        */
        Produto(string nome, int qtd, float preco);

        /**
        *@brief Metodo que retorna o nome do produto
        *@return retorna o nome do produto
        */       
        string retorna_nome();

        /**
        *@brief Metodo que retorna o preço do produto
        *@return retorna o preço do produto
        */        
        float retorna_preco();

        /**
        *@brief Metodo que decrementa uma quantidade dos produtos no estoque
        *@param qtd é a quantidade de produtos que deve ser decrementada do estoque
        */                
        void decrementa_quantidade(int qtd);

        /**
        *@brief Metodo que incrementa uma quantidade dos produtos no estoque
        *@param qtd é a quantidade de produtos que deve ser incrementada do estoque
        */            
        void incrementa_quantidade(int qtd);

        /**
        *@brief Metodo que retorna uma quantidade dos produtos no estoque
        *@return retorna uma quantidade dos produtos no estoque
        */            
        int retorna_quantidade();
};


#endif