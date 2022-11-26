#include <stdio.h>
#include <stdlib.h>
typedef struct mapaGalatico{
    int** matriz;
    int largura;
    int altura;
    int** pesos;
    int* sol;
    int** caminhos;
    int** qtdcaminhos;
}MapaGalatico;

void inicializaMatriz(MapaGalatico* map);
