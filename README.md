# Automatos teoria de linguagens
Programa em C que representa AFD e AFN's

## Compilação:

Para compilar é necessário utilizar-se do comando make no terminal e após isso para executar é necessário
digitar "./tp" sem as áspas no terminal. Lembrando que para leitura de cada arquivo o arquivo "tp.h" deve
ter sua variável "Diretorio" definida com o caminho do arquivo que deseja testar. E depois dar o comando
"make limpar" no terminal e em seguida dar o comando "make" novamente.

----------------------------------------------------------------------------------------------------
## Descrições do Trabalho:

Trabalho não apresenta falhas para representar AFNs e AFDs caso siga as orientações corretamente:

1- Arquivo de entrada exatamente com a formatação explicada abaixo;
2- Palavra digitada nunca maior que o "Max_Tam_Palavra" descrito no arquivo de entrada;
3- Não digite palavras vazias na hora de entrar com a palavra
4- Não tente entrar com mais de um entrado inicial no arquivo

----------------------------------------------------------------------------------------------------
## Modelagem do problema:

É comum modelar automatos em grafos para representações gráficas, então a representação do simulador
foi feita com uma matriz de adjacencia sendo cada estado um nó e cada mudança possível de estado representado
por uma aresta.

----------------------------------------------------------------------------------------------------
## Arquivo de entrada: 
cabeçalho
```
X Y Z W (Separados por espaço)
X = numeroEstados          //Numeros total de transicoes do automato
Y = Num_Active_States      //Numero de estados ativos (qual o estado ativo na inicilizacao)
Z = Max_Tam_Palavra        //Numero maximo para permitir a palavra (atribuimos o tamanho de 100 caracteres)
W = Tam_Estados_Finais      //Numero máximo de estados finais 1 para AFD e N para AFN
```
Segunda linha
```
Preencher quais sao os estados finais (unico valor para AFD e no caso de AFN colocar espacos entre os estados)
X (AFD)
X X X (AFN com exemplo para 3 estados finais)
```
Todo o restante do arquivo de entrada/configuracao (Todas linhas seguintes)
```
i j x y
exemplo:
automato[i][j].saidas[x] = y;
```
Usando esses valores para preencher uma matriz de adjacencia representando como grafo o automato.
Cada vértice na verdade é um vetor de saidas que possui todas as palavras que ativam aquela aresta;
E a variável y representa esse valor que é usado para preencher as saidas.

Para melhor entendimento tome algum dos exemplos disponiveis nesse arquivo.

----------------------------------------------------------------------------------------------------
## Integrantes do grupo:

 Aluno:  Rafael Paiva   		 Matricula:  172050018
 Aluno:  Lucas Marchisotti       Matricula:  172050060
 Aluno:  Alexander Cristian      Matricula:  172050020
