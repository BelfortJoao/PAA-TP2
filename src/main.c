#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "achaCaminho.h"
#define PATH_ARQUIVO "./input/"
int main(){
    int escolha;
    MapaGalatico map;

    while(1) {
        printf("\n\nPrograma de Varredura Intergalática\n"
               "\n0.Sair\n"
               "3.Escanear novo mapa galatico.[Criar]\n"
               "2.inserir dados de mapa galatico.[Ler]\n"
               ":");
        scanf("%d", &escolha);
        int altura,  largura;
        FILE *pArquivo = NULL;
        char nomeArquivo[CHAR_MAX];

        if(escolha==1||escolha==2)
        {
            printf("Digite o nome do arquivo: \nOBS: O arquivo deve estar na pasta 'input'.\n");
            scanf("%s", nomeArquivo);
            char caminhoArquivo[strlen(PATH_ARQUIVO) + strlen(nomeArquivo) + 1];
            strcpy(caminhoArquivo, PATH_ARQUIVO);
            strcat(caminhoArquivo, nomeArquivo);
            pArquivo = fopen(caminhoArquivo, "r");

            if (!pArquivo)
            {
                printf("\nErro ao tentar abrir o arquivo.\n");
                printf("%s",caminhoArquivo);
                break;
            }
            fscanf(pArquivo,"%d %d",&map.altura, &map.largura);
            inicializaMatriz(&map);

            for (int i = 0; i < altura; ++i)
            {

                for (int j = 0; j < largura; ++j)
                {
                          fscanf(pArquivo,"%d ",&map.matriz[i][j]);
                }
            }
            fclose(pArquivo);
            pArquivo = NULL;
        }

        int menor;
        switch (escolha)
        {
            default:
                printf("Entrada invalida\n");
                break;

            case 0:
                exit(0);
            case 2:
                menor = menorTamanho(&map);
                printf("menor caminho: %d", menor);
                break;

            case 1:
                //buscaCaminho(&mat, analise);
                break;
        }
    }
}
