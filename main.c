// Aluno:  Rafael Paiva   		   Matricula:  172050018
// Aluno:  Lucas Marchisotti       Matricula:  172050060
// Aluno:  Alexander Cristian      Matricula:  172050020

// TP Teoria de Linguagens - AFD e AFN

#include "tp.h"

int main(){


  //LEITURA DO CABEÇALHO
  int numeroEstados = 0;        // Sera lido no cabeçalho do arquivo
  int Num_Active_States = 0;    // Variavel temporaria que sera repassada para os estadosAtivos e evitar o deadlock
  int Max_Tam_Palavra = 0;      // Sera lido no cabeçalho do arquivo
  int Tam_Estados_Finais = 0;   // Sera lido no cabeçalho do arquivo

  //LEITURA DO CABECALHO DO ARQUIVO-----------------------------------------------------
  FILE *readHEADER;
  readHEADER = fopen (Diretorio,"rt");
  if (readHEADER == NULL){
      printf (" ERRO \n");
      exit (1);
  }

  if(fscanf(readHEADER, "%d %d %d %d", &numeroEstados, &Num_Active_States, &Max_Tam_Palavra, &Tam_Estados_Finais));
  fclose(readHEADER);



  //Criação do vetor de estados finais
  int *estadosFinais = newVetorDeEstadosAtivos(numeroEstados,Max_Tam_Palavra);

  ESTADO automato[numeroEstados][numeroEstados];
  int i,j,k;
    //Setando todas as posições com x.
    for (i=0; i < numeroEstados; i++){


        for (j=0 ; j < numeroEstados; j++){
            for (k=0 ; k < 100; k++){
                automato[i][j].saidas[k] ='x';
            }
        }
    }

  //LEITURA DO ARQUIVO DE CONFIGURACAO DO AUTOMATO -----------------------------------------------------
  leitura( numeroEstados,automato, Num_Active_States, Max_Tam_Palavra, Tam_Estados_Finais, estadosFinais);
  //---------------------------------------------------------------------------------

  //Iniciacao do vetor de estadosAtivos
  int *estadosAtivos = newVetorDeEstadosAtivos(numeroEstados,Max_Tam_Palavra);
  estadosAtivos[0] = Num_Active_States;


  //Pega a palavra digitada pelo usuário
  char *palavra = (char*)calloc(Max_Tam_Palavra,sizeof(char));
  printf("Digite a palavra a ser testada pelo automato (Máximo %d caracteres)\n",Max_Tam_Palavra);

  if(scanf("%s",palavra));

  //Para cada letra digitada chama a função principal
  for (int i =0; i < Max_Tam_Palavra; i++){
    //Se a palavra não for vazia ele chama a função principal
    if (palavra[i] != 0){
    printf("\nAnalisando Entrada: '%c' \n", palavra[i]);
    int *estadoFinal =  lePalavra(palavra[i], estadosAtivos, numeroEstados ,automato,Max_Tam_Palavra);
    printEstadosAtivos(estadoFinal, numeroEstados);
    estadosAtivos = estadoFinal;
    }
  }
  verificaSolucao(estadosAtivos, estadosFinais , numeroEstados, Tam_Estados_Finais);

  return  0;

}
