// Aluno:  Rafael Paiva   		   Matricula:  172050018
// Aluno:  Lucas Marchisotti       Matricula:  172050060
// Aluno:  Alexander Cristian      Matricula:  172050020

// TP Teoria de Linguagens - AFD e AFN

#ifndef __TP_H__
#define __TP_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//--------------------VARIAVEIS GLOBAIS ------------------------------

//int Tam_Temp = 100;
#define Tam_temp 100

//PARA TROCAR O ARQUIVO É NECESSÁRIO ALTERAR ESSA VARIÁVEL
#define Diretorio "anlexico.txt"
//--------------------------------------------------------------------


//Estrutura com as possíveis palavras que podem ativar próximos estados

typedef struct state {
int saidas[100]; //100 = Numero máximo de palavras que podem ativar um estado
}ESTADO;

//Funções auxiliares------------------------------------------------------------

int *newVetorDeEstadosAtivos(int numeroEstados, int tamPalavra);                                     //Funçao que cria um vetor com todos os itens sendo -1
void printEstadosAtivos(int *estadosAtivos, int numeroEstados);                                      //Função para printar os estados atualmente ativos
int *lePalavra(char p,int *estadosAtivos, int numeroEstados, ESTADO automato[numeroEstados][numeroEstados],int tamPalavra);   //Função principal que lê um char (p) e cria um vetor de estados ativos futuros
void verificaSolucao(int *estadosAtivosFinais,int *vetorDeEstadosFinais, int numeroEstados , int Tam_Estados_Finais);                   //Compara se nos estados ativos existe algum estado final.
void leitura(int numeroEstados,ESTADO automato[numeroEstados][numeroEstados], int Num_Active_States, int Max_Tam_Palavra, int Tam_Estados_Finais, int *estadosFinais);                                //Função de leitura do arquivo de configuracao do automato

#endif
