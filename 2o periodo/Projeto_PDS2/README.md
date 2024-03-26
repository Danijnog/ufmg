Trabalho final da disciplina Programação e Desenvolvimento de Software || - UFMG 2022/1

Sistema de Gerenciamento de Fluxo de Produtos em um supermercado

User Stories:

GERENTE

-Eu como gerente quero poder ter acesso ao fluxo de caixa para averiguar quanto capital está entrando no caixa.

-Eu como gerente quero ter acesso a uma lista com a quantidade de cada produto, afim de saber quais estão em falta e quais estão em excesso.

-Eu como gerente quero poder adicionar produtos que estão em excesso no estoque a uma "lista promocional", para que eles possam ser vendidos mais rápido.

No sistema, o gerente tem a opção de fazer 4 coisas além de alterar o seu tipo de usuário se desejar: 1- consultar o saldo no caixa do supermercado. 2- ver a quantidade de produtos no estoque. 3- atualizar o estoque. 4- atualizar as promoções.

CLIENTE

-Eu como cliente quero ter acesso a uma lista de produtos e seus preços, para poder escolher e comprar o que for do meu interesse.

-Eu como cliente quero ter acesso a uma lista promocional, para saber quais produtos estão sendo vendidos com preços abaixo do normal.

No sistema, um cliente tem a opção de fazer 3 coisas além de alterar o seu tipo de usuário se desejar: 1- ver lista de produtos. 2- ver lista de produtos em promoção. 3- comprar um produto.

CAIXA

-Eu como caixa quero poder incrementar o valor do lucro atual do supermercado, para atualizar este valor a cada venda de produtos realizada e contabilizada por mim.

-Eu como caixa quero poder emitir uma nota fiscal após cada compra, para entregar ao cliente o "documento" que consta o valor de cada produto comprado, as quantidades e o valor total da compra.

No sistema, o caixa tem a opção de emitir a nota fiscal de um cliente, além de alterar o seu tipo de usuário se desejar.

FUNCIONARIO

-Funcionario é uma superclasse que servirá de herança para a classe caixa e gerente, fazendo essas classes herdarem por exemplo o nome e id.



COMO COMPILAR E RODAR O PROGRAMA:
No WINDOWS - clone o repositório do GitHub copiando o link do repositório e depois cole-o no VS Code como mostrado na imagem abaixo, ou na sua IDE preferida! 

![clonar](https://user-images.githubusercontent.com/97178655/179424633-b07bcd3b-463d-41f9-8d16-7d25666638f2.png)
![vscode clonar](https://user-images.githubusercontent.com/97178655/179424946-f8f03018-294e-4b7e-a520-80c5ae58ef95.png)

depois disso, crie uma pasta chamada "obj" dentro da pasta do Projeto que você tiver criado, como mostrado na imagem abaixo!

![pastaobj](https://user-images.githubusercontent.com/97178655/179425083-581206bd-a469-4be1-b0de-d0393b10fd1c.png)

Agora, abra o terminal selecionando a opção "Terminal" do VS Code que está na parte superior centralizada, e no terminal digite "mingw32-make" para que compile os arquivos e gere o executável
![comando make](https://user-images.githubusercontent.com/97178655/179425206-ecdc41c5-24b2-4643-a966-faec3c52cf15.png)
Depois disso, o executável "e-commerce.exe" será gerado, e execute-o no terminal também dando o comando ".\e-commerce.exe" 
Agora o programa será executado, e faça bom uso dele! :)

No LINUX/WSL: Repita os mesmos passados do tutorial para o Windows e não se esqueça de criar a pasta "obj" também, e por último abra o terminal e de o comando "make" e depois rode o executável digitando "./e-commerce" no terminal como mostrado abaixo"
![compilar no linux](https://user-images.githubusercontent.com/97178655/179426130-beb8dada-e30f-4144-9221-7973f0b404bd.png)


UTILIZANDO O PROGRAMA:
Ao executar o programa, é possível escolher qual tipo de usuário deseja:

1-GERENTE
Escolhendo ser gerente, o usuário pode: ver o saldo do supermercado, ver os produtos(em promoção ou não)do supermercado com seus preços e quantidades no estoque, atualizar as promoções(colocar produtos acima de 100 unidades na lista promocional com 25% de desconto e/ou retirar da promoção produtos com menos de 70 unidades) e atualizar o estoque(adicionar unidades de produtos que estão abaixo da quantidade mínima, que são 50 unidades).
Será pedido o nome do usuário quando ele(a) escolher ser gerente e será registrado um gerente para o supermercado com esse nome. Caso altere o tipo de usuário e posteriormente queira ser gerente de novo, será pedido o nome, e se o indivíduo  digitar um nome diferente do nome registrado, o sistema não permitirá que o usuário execute ações de um gerente.

2-CLIENTE 
Escolhendo ser cliente, o usuário pode: ver uma lista de produtos, ver uma lista somente com produtos em promoção e comprar algum produto. Ao comprar algum produto, deve-se informar a quantidade e o nome do produto, e será mostrado ao final da compra qual foi o valor gasto.

3-CAIXA
Escolhendo ser caixa, o usuário pode: emitir a nota fiscal de um cliente. Para isso, é necessário algum cliente tenha comprado algum produto. Basta digitar o nome do cliente que deseja emitir a nota fiscal. A nota fiscal consta a quantidade comprada de cada produto, seus preços e o total gasto.

A qualquer momento, é possível trocar o tipo de usuário.

