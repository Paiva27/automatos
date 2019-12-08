// Aluno:  Rafael Paiva   		   Matricula:  172050018
// Aluno:  Lucas Marchisotti       Matricula:  172050060
// Aluno:  Alexander Cristian      Matricula:  172050020

// TP Teoria de Linguagens - AFD e AFN

#include "tp.h"

//Funções auxiliares------------------------------------------------------------

int *newVetorDeEstadosAtivos(int numeroEstados, int tamPalavra){
    int *estadosAtivos;
    estadosAtivos = (int *)malloc((numeroEstados*tamPalavra*tamPalavra)*sizeof(int));
    for (int i =0; i < numeroEstados*tamPalavra; i++){
        estadosAtivos[i] = -1;
    }
    return estadosAtivos;
}

//Função para printar os estados atualmente ativos
void printEstadosAtivos(int *estadosAtivos, int numeroEstados){
    printf("Estados ativos :  ");
    for (int i =0; i < numeroEstados; i++){
        if (estadosAtivos[i] != -1){
        printf("- %d ", estadosAtivos[i]);
        }else{
        break;
        }
    }
}

//Função principal que lê um char (p) e cria um vetor de estados ativos futuros
int *lePalavra(char p, int *estadosAtivos, int numeroEstados, ESTADO automato[numeroEstados][numeroEstados],int tamPalavra){

    //iteracao estados
    int i =0;
    //Criação de novo vetor de estados
    int *estadosAtivosFuturos = newVetorDeEstadosAtivos(numeroEstados,tamPalavra);
    //iteracao futuros estados
    int c = 0;

 //While que passa em todos os estados ativos do vetor de estados ativos (-1 significa q n tem mais nada)
    while(estadosAtivos[i] != -1){
        //Para cada estado ativo o for passa por todas as possiveis saidas deste estado
        for(int j=0 ; j < numeroEstados ; j++){
            //Este for passa pelo vetor de saidas possíveis do estado.
            for(int x=0 ; x < 100 ; x++){
                //O if verifica se alguma dessas saidas possíveis é igual a da palavra p
                if(automato[estadosAtivos[i]][j].saidas[x] == p){
                    /*Se a p estiver no vetor de saidas do estado então é
                    adicionado aos estadosAtivos futuros*/
                    estadosAtivosFuturos[c] = j;
                    c++;
                 //Se entrar no else quer dizer que não tem mais char no vetor então sai do for(x)
                }else if(automato[estadosAtivos[i]][j].saidas[x] == 'x'){
                    break;
                }
            }
        }
    //Incrementa em i e só sai do while quando não tiver mais estados ativos para serem checados
    i++;
    }
    //Retorna o novo vetor de estados ativos
    return estadosAtivosFuturos;
}

//Compara se nos estados ativos existe algum estado final.
void verificaSolucao(int *estadosAtivosFinais,int *vetorDeEstadosFinais, int numeroEstados, int Tam_Estados_Finais){
 int flag = 0;
 for(int i = 0; i < (numeroEstados*numeroEstados); i++){
    for(int j = 0; j < Tam_Estados_Finais; j++){
        if (estadosAtivosFinais[i] == vetorDeEstadosFinais[j]){
            printf("\nSolução:\nComo o estado %d está ativo então a palavra é aceita pelo automato\n",estadosAtivosFinais[i]);
            flag = 1;
            break;
        }
    }
    if(flag != 0 )break;
 }
 if(flag == 0)printf("\nSolução:\nPalavra não aceita pelo automato\n");
}

//Leitura do arquivo de construcao do automato.
void leitura(int numeroEstados,ESTADO automato[numeroEstados][numeroEstados], int Num_Active_States, int Max_Tam_Palavra, int Tam_Estados_Finais, int *estadosFinais){
    int aux = 0, lcounter = 0;
    int i=0;
    int a=0, b=0, c=0;
    char d ='x';
    char lc;

    FILE *read;
    read = fopen (Diretorio,"rt");
    if (read == NULL){
        printf (" ERRO \n");
        exit (1);
    }

    while(!feof(read)){
        if(fread(&lc, sizeof(char), 1, read));
        if(lc == '\n' && !feof(read)){
            lcounter++;
        }
    }
    rewind(read);

    do{
        if(fread(&lc, sizeof(char), 1, read));
        if(lc == '\n'){
            aux++;
        }
    }while(aux<=1);

    for( i=3 ; i<=lcounter ; i++ ){
        if(fscanf(read, "%d %d %d %c", &a, &b, &c, &d));
        automato[a][b].saidas[c] = d;

    }

    rewind(read);
    aux=0;
    char ends[30];
    char dlimit[] = " ";
    do{
        if(fread(&lc, sizeof(char), 1, read));
        if(lc == '\n'){
            aux++;
        }
    }while(aux<=0);

    if(fscanf(read, "%[^\n]\n", ends));
    char *ptr = strtok(ends, dlimit);
    //int TAMends = strlen(ends);

    i=0;
    while(ptr != NULL){
        estadosFinais[i]=atoi(ptr);
        ptr = strtok(NULL, dlimit);
        i++;
    }
    
    fclose(read);
}
