# Trabalho Final Laboratorio 
## Implementação de uma Matriz de Coocorrência Estrutural(Structural Co-occurrence Matrix, SCM)
## 👨‍💻 Integrantes
- Aldenor Neto
- Davi Nascimento
- Lucas viana 
## 🚨 Sobre 
O projeto consiste na leitura de duas imagens.pgm, uma versão original e outra versão suavizada com um filtro gaussiano, no qual será gerado uma matriz de coocorrência a partir da frequência estabelecida e dos dados que compõe cada arquivo
![Captura de tela 2022-12-13 105240](https://user-images.githubusercontent.com/111457772/207347548-8769a859-4136-4c01-b8fe-e4766a8c1304.png)
## ⌨A implementação no código
Foi disponibilizado uma pasta com mais de 1300 imagens no qual o programa deve armazenar os dados das duas imagens(original e filtrada) de acordo com a quantização escolhida pelo usuário, realizar a computação de uma matriz SCM derivada desses dados e a sua vetorização em um arquivo texto
- **A leitura das imagens e sua quantização:**
A leitura é feita a partir das funções disponibilizadas pelo professor. A função "readPGMImage" é a responsável por armazenar todos os dados da imagem e a função "writePGMImage" é encarregada de escrever os dados adquiridos em um outro local. Também foi utilizado a função "viewPGMImage" para fins de organização caso fosse necessário transpor as informações desejadas na tela

![Captura de tela 2022-12-13 153711](https://user-images.githubusercontent.com/111457772/207417336-95efd122-fa47-401b-a8d3-d1f0223b13f4.png)

Ao final da coleta dos dados foi preciso quantizar as duas imagens. Isso foi possível graças a função "quantizar_matriz" que foi desenvolvida inteiramente pela equipe

![image](https://user-images.githubusercontent.com/111457772/207419282-561accb6-7475-4f3f-a556-f53775fe87a5.png)

- **A realização e vetorização da matriz SCM**:
Para formar a matriz SCM utilizamos uma função chamada "preencher_mat_scm" que captura os dados das duas imagens, o ponteiro "mat_scm" que foi alocado com todos os valores zerados, a largura, altura e frequência desejada

![image](https://user-images.githubusercontent.com/111457772/207420293-ff1dc0e6-be10-4bde-89f9-a858508f8e6a.png)

## 🧠A lógica por trás da leitura de todas as imagens
A equipe também utilizou um código disponibilizado anteriormente que tem um laço que corre por todos os arquivos
- Após aberto o diretório das imagens, foi usado um laço while que percorria todo o diretório, as imagens, o armazenamento de dados, quantização e vetorização da matriz desejada foram feitas em sequência até o fim das imagens

![image](https://user-images.githubusercontent.com/111457772/207425063-4495a1e4-822b-48db-92e1-d2e2ae02725a.png)


## ⏳A medição do tempo
- Ao incluir a biblioteca "<time.h>" é possível chamar funções específicas, como a "clock()" que possibilita a medida de tempo ao longo do código.

- No começo do arquivo principal declaramos as seguintes variáveis:

![image](https://user-images.githubusercontent.com/111457772/207423481-91f496d3-0ec8-4ad7-97e8-569165c50913.png)


Já no início do laço resposável por ler todas as imagens o tempo começa a ser contado

![image](https://user-images.githubusercontent.com/111457772/207424267-8edafa24-af32-4207-b445-ee423ab856b0.png)

E no final ele é encerrado

![image](https://user-images.githubusercontent.com/111457772/207424366-74202f07-9885-45db-b8fc-555417ec6dcc.png)

A lógica utilizada para a contagem do tempo total foi feita através da variável soma que recebe a diferença entre o tempo inicial e final dividido pelo número de clocks por segundo da máquina

## 🎯Resultado Final
- Ao fim do programa é gerado um arquivo texto com todas as matrizes SCM vetorizadas e uma mensagem na tela contendo o tempo total

![image](https://user-images.githubusercontent.com/111457772/207427009-43ea1012-f62a-4d4f-b895-81456bc789b3.png)

![image](https://user-images.githubusercontent.com/111457772/207427388-48dc93dd-ffbf-4600-b677-1a7d2ed78ca4.png)

Na imagem acima temos o exemplo das primeiras matrizes com uma frequência de 8
