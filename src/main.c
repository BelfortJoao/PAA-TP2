#include <string.h>
#include <limits.h>
#include "achaCaminho.h"
#include "criaTeste.h"
#define PATH_ARQUIVO "./input/"
int main(){
    int escolha;
    MapaGalatico map;

    //Menu Basico Para o Programa
    while(1) {
        printf("\n\nPrograma de Varredura Intergalática\n"
               "\n0.Sair\n"
               "1.Escanear novo mapa galatico.[Criar]\n"
               "2.inserir dados de mapa galatico.[Ler]\n"
               ":");
        scanf("%d", &escolha);

        int altura,  largura;
        FILE *pArquivo = NULL;
        char nomeArquivo[CHAR_MAX];
        int idFile;
        int menor;
        int** matriz;

        switch (escolha)
        {
            default:
                printf("Entrada invalida\n");
                break;

            //Sai do programa
            case 0:
                exit(0);

            //Cria um arquivo de Teste
            case 1:
                printf("Insira um número para identificar o arquivo: ");
                scanf("%d", &idFile);
                printf("Altura: ");
                scanf("%d",&altura);
                printf("Largura: ");
                scanf("%d",&largura);
                criaTxt(idFile,altura, largura, matriz);
                break;

            //Realiza a contagem de caminhos mais curtos e o calculo do peso do caminho mais curto Abrindo um arquivo
            case 2:
                printf("Digite o nome do arquivo \nOBS: O arquivo deve estar na pasta 'input'.\n:");

                //Abertura de arquivo e escrita na estrutura de dados

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
                for (int i = 0; i < map.altura; ++i)
                {
                    for (int j = 0; j < map.largura; ++j)
                    {
                        fscanf(pArquivo,"%d ",&map.matriz[i][j]);
                    }
                }

                fclose(pArquivo);
                pArquivo = NULL;

                //Calculos e monstração dos resultados
                printf("\nSoma minima: %d\n",menorTamanho(&map));
                printf("Quantidade de Caminhos: %d", caminhosNumeros(&map));
                break;


        }
    }
}

