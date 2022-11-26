#include "galaxy.h"

//Inicializa as matrizes e os Arrays da estrutura de dados MapaGalatico, alocando-os na mémoria dinamica e definindo os
// seus valores padrão.
//inputs:
//  map: estrutura de dados para ser inicializada.
void inicializaMatriz(MapaGalatico* map){

    map->matriz = (int **) malloc(sizeof(int *) * map->altura);
    map->pesos = (int **) malloc(sizeof(int *) * map->altura);
    map->caminhos= (int**) malloc(sizeof (int*)*map->altura);
    map->qtdcaminhos= (int**) malloc(sizeof (int*)*map->altura);
    map->sol=(int *)malloc( sizeof( int ) * (map->altura+map->largura-1)*2);
    for (int i = 0; i < map->altura; i++){
        map->matriz[i] = (int*) malloc(sizeof(int)*map->largura);
        map->pesos[i] = (int*) malloc(sizeof(int)*map->largura);
        map->caminhos[i] = (int*) malloc(sizeof(int)*map->largura);
        map->qtdcaminhos[i] = (int*) malloc(sizeof(int)*map->largura);
    }
    for (int i = 0; i < (map->altura+map->largura-1)*2; ++i) {
        map->sol[i]= -1;
    }
}
