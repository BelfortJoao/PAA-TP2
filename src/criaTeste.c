#include "criaTeste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define UPPER 15
#define LOWER 1
#define NOME_ARQUIVO "../input/teste"


int** criaTeste(int** matriz, int altura, int largura){
    matriz = (int**) malloc(sizeof(int*)*altura);

    for (int i = 0; i < altura; i++){
        matriz[i] = (int*) malloc(sizeof(int)*largura);
    }

    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {
            matriz[i][j] = (rand() % (UPPER - LOWER + 1)) + LOWER;
        }
    }
    return matriz;
}

void criaTxt(int numeroArquivo, int altura, int largura, int** matriz){
    char* strNumeroArquivo;
    char caminhoArquivo[CHAR_MAX];
    FILE* fp;
    strcpy(caminhoArquivo, NOME_ARQUIVO);
    // convert int to string
    sprintf(strNumeroArquivo, "%d", numeroArquivo);
    strcat(caminhoArquivo, strNumeroArquivo);
    strcat(caminhoArquivo, ".txt");
    fp = fopen(caminhoArquivo ,"a");

    if(fp==NULL)
    {
        printf("Erro ao criar o arquivo.");
        exit(0); /*exit from program*/
    }
    printf("%s", caminhoArquivo);

    matriz=criaTeste(matriz,altura,largura);

    fprintf(fp,"%d ", altura);
    fprintf(fp, "%d\n",largura);

    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {
            fprintf(fp,"%d ",matriz[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    fp = NULL;
}