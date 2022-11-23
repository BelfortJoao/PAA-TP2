#include "achaCaminho.h"
void menorTamanho(MapaGalatico* mapa) {
    //Base Case
    mapa->pesos[0][0] = mapa->matriz[0][0];
    //Bottom Row
    printf("%d %d", mapa->altura, mapa->largura);
    for (int i = 1; i < mapa->largura-1; i++) {
        mapa->pesos[i][0] = mapa->pesos[i - 1][0] + mapa->matriz[i][0];
        printf("%d\n",mapa->pesos[i][1]);
        printf("%d",mapa->matriz[i][0]);
    }
    //Bottom Column
    for (int i = 1; i < mapa->altura-1; i++) {
        mapa->pesos[0][i] = mapa->pesos[0][i - 1] + mapa->matriz[0][i];
        printf("%d\n",mapa->pesos[0][i]);
    }
//Everywhere else
    for (int i = 1; i < mapa->largura-1; i++) {
        for (int k = 1; k < mapa->altura-1; k++) {
            if (mapa->pesos[i - 1][k] > mapa->pesos[i][k - 1]) {
                mapa->pesos[i][k] = mapa->pesos[i - 1][k] + mapa->matriz[i][k];
            } else {
                mapa->pesos[i][k] = mapa->pesos[i][k - 1] + mapa->matriz[i][k];
            }
            printf("cu?\n");
            printf("%d\n", mapa->pesos[i][k]);
        }
    }

}