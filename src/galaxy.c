#include "galaxy.h"

void inicializaMatriz(MapaGalatico* map){

    map->matriz = (int**) malloc(sizeof(int*)*map->altura);
    map->pesos = (int**) malloc(sizeof(int*)*map->altura);
    for (int i = 0; i < map->altura; i++){
        map->matriz[i] = (int*) malloc(sizeof(int)*map->largura);
        map->pesos[i] = (int*) malloc(sizeof(int)*map->largura);
    }
}
