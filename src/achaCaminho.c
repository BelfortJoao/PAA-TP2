#include "achaCaminho.h"
int menorTamanho(MapaGalatico* mapa) {

    //setting up the "matrix of maximums"

    //Base Case
    mapa->pesos[0][0] = mapa->matriz[0][0];
    //Bottom Row
    for (int i = 1; i < mapa->largura; i++) {
        mapa->pesos[i][0] = mapa->pesos[i - 1][0] + mapa->matriz[i][0];
    }
    //Bottom Column
    for (int i = 1; i < mapa->altura; i++) {
        mapa->pesos[0][i] = mapa->pesos[0][i - 1] + mapa->matriz[0][i];
    }
//Everywhere else
    for (int i = 1; i < mapa->largura; i++) {
        for (int k = 1; k < mapa->altura; k++) {
            if (mapa->pesos[i - 1][k] > mapa->pesos[i][k - 1]) {
                mapa->pesos[i][k] = mapa->pesos[i - 1][k] + mapa->matriz[i][k];
            } else {
                mapa->pesos[i][k] = mapa->pesos[i][k - 1] + mapa->matriz[i][k];
            }
        }
    }
    return mapa->pesos[mapa->largura - 1][mapa->altura - 1];
}