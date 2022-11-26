#include "criaTeste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define UPPER 15
#define LOWER 1
#define NOME_ARQUIVO "../input/teste"

// Função para criar números aleatorios e inseri-los em uma matriz de inteiros
//input:
//  matriz: Matriz para se escrever os números aleatorias, e ser alocada dinamicamente na memoria.
//  altura: Altura da matriz, eixo y.
//  largura: Largura da matriz, eito x.
//output:
//  matriz: Matriz alocada na mémoria e com números aleatorios inseridos.
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

//Função que cria o arquivo txt e gera uma matrix aleatoria de tamanho definido dentro do arquivo
//input:
//  numeroArquivo: Número para indentificar o arquivo gerado.
//  altura: Altura da matriz, eixo y.
//  largura: Largura da matriz, eito x.
//  matriz: Matriz para se escrever os números aleatorias, e ser alocada dinamicamente na memoria.
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