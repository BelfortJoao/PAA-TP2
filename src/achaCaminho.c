#include "achaCaminho.h"
int menorTamanho(MapaGalatico* mapa) {

    mapa->pesos[0][0] = mapa->matriz[0][0];
    mapa->sol[0]=0;
    mapa->sol[1]=0;

    for (int i=1 ; i<mapa->largura; i++){
        mapa->pesos[0][i] = mapa->pesos[0][i-1]+mapa->matriz[0][i];

    }

    for (int i=1 ; i<mapa->altura; i++){
        mapa->pesos[i][0] = mapa->pesos[i-1][0]+mapa->matriz[i][0];
    }
    int cont=2;
    for (int i=1; i<mapa->largura; i++){
        for (int k=1; k<mapa->altura; k++){
            if (mapa->pesos[k][i-1]<mapa->pesos[k-1][i]){
                mapa->pesos[k][i] = mapa->pesos[k][i-1]+mapa->matriz[k][i];
                mapa->sol[cont] = k;
                mapa->sol[cont+1]=i-1;
            }else {
                mapa->pesos[k][i] = mapa->pesos[k-1][i]+mapa->matriz[k][i];
                mapa->sol[cont] = k-1;
                mapa->sol[cont+1]=i;
            }
            cont+=2;
        }
    }
    mapa->sol[((mapa->largura+mapa->altura-1)*2)-1]= mapa->largura-1;
    mapa->sol[(mapa->largura+mapa->altura-1)*2-2]= mapa->altura-1;
    return mapa->pesos[mapa->altura-1][mapa->largura-1];
}
void printSolucao(MapaGalatico* map){
    int i = 0;
    while (1) {
        printf("(%d, %d) ",map->sol[i],map->sol[i+1]);
        i+=2;
        if(i < map->altura+map->largura+2){
        printf("->");} else{ break;}
    }
}

int caminhosNumeros(MapaGalatico* mapa){
    mapa->qtdcaminhos[mapa->altura-1][mapa->largura-1]=1;
    for (int i = mapa->altura-1; i >= 0; --i) {
        for (int j = mapa->largura-1; j >= 0; --j) {
            if (i == mapa->altura-1 && j==mapa->largura-1){} else {
                if(j == mapa->largura-1){if (mapa->pesos[i][j]+mapa->matriz[i+1][j] == mapa->pesos[i+1][j]){mapa->qtdcaminhos[i][j]++;} } else {
                if(i == mapa->altura-1){if (mapa->pesos[i][j]+mapa->matriz[i][j+1] == mapa->pesos[i][j+1]){mapa->qtdcaminhos[i][j]++;} }else{
                    if (mapa->pesos[i][j]+mapa->matriz[i][j+1] == mapa->pesos[i][j+1]){mapa->qtdcaminhos[i][j]+= mapa->qtdcaminhos[i][j+1];}
                    if (mapa->pesos[i][j]+mapa->matriz[i+1][j] == mapa->pesos[i+1][j]){mapa->qtdcaminhos[i][j]+= mapa->qtdcaminhos[i+1][j];}
                }}
            }
        }
    }
    //for (int i = 0; i < mapa->altura; ++i) {
    //    for (int j = 0; j < mapa->largura; ++j) {
    //        printf("\n%d .",mapa->qtdcaminhos[i][j]);
    //    }
    //}
    return mapa->qtdcaminhos[0][0];
}

//Não usado atualmente
void caminhosIguais(MapaGalatico* mapa){
    mapa->caminhos[0][0]=1;
    mapa->caminhos[mapa->altura-1][mapa->largura-1]=1;
    for (int i = mapa->altura-1; i > 1; --i) {
        for (int j = mapa->largura-1; j > 1; --j) {
            if(mapa->pesos[i-1][j] == mapa->pesos[i][j-1]){
                if(mapa->caminhos[i-1][j]!=0){mapa->caminhos[i-1][j] = 1;}
                if(mapa->caminhos[i-1][j]!=0){mapa->caminhos[i][j-1] = 1;}
            } else {
                if(mapa->pesos[i-1][j] < mapa->pesos[i][j-1]){
                    if(mapa->caminhos[i-1][j]!=0){mapa->caminhos[i-1][j] = 1;}
                    mapa->caminhos[i][j-1] = 0;
                }
                if(mapa->pesos[i-1][j] > mapa->pesos[i][j-1]){
                    if(mapa->caminhos[i][j-1]!=0){mapa->caminhos[i][j-1] = 1;}
                    mapa->caminhos[i-1][j] = 0;
                }
            }
        }
    }
}

//Função para achar possiveis caminhos entre as diagonais de uma array de 0 ou 1
void achaCaminho(MapaGalatico* mapa){

}