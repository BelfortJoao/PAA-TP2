#include <stdio.h>
#include <stdlib.h>
typedef struct mapaGalatico{
    int** matriz;
    int largura;
    int altura;
    int** pesos;
}MapaGalatico;

void inicializaMatriz(MapaGalatico* map);
