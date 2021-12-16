/*
Marcos Vinicius Araujo Almeida - 1910869
*/
#include <stdio.h>
#include <stdlib.h>
#include "sistlinear.h"

#define MAX 6
#define MEDIO 3

void exibeVetor(int n, double * v){
    printf("[ ");
    for (int i = 0; i < n; i++){
        printf("%g, ", v[i]);
    }
    printf("]\n\n");
}

double **criamat(int m, int n)
{
    double **matriz;

    matriz = (double **)malloc(m * sizeof(double *));

    for (int i = 0; i < m; i++)
    {
        matriz[i] = (double *)malloc(n * sizeof(double));
    }

    return matriz;
}


int main(void){

    //criando a matriz
    double **matriz1 = criamat(MEDIO, MEDIO);
    double **matriz2 = criamat(MAX, MAX);

    //alocando os vetores da solução 
    double * solucao1 = (double *)malloc(MEDIO * sizeof(double));
    double * solucao2 = (double *)malloc(MAX * sizeof(double));

    //alocando os vetores independentes 
    double * mult1 = (double *)malloc(MEDIO * sizeof(double));
    double * mult2 = (double *)malloc(MAX * sizeof(double));
    
    //preenchendo os vetores independentes
    mult1[0] = 3.0;
    mult1[1] = 3.0;
    mult1[2] = -6.0;
    
    mult2[0] = 2.5;
    mult2[1] = 1.5;
    mult2[2] = 1.0;
    mult2[3] = 1.0;
    mult2[4] = 1.5;
    mult2[5] = 2.5;

    //preenchendo as matrizes
    
    matriz1[0][0] = 1.0;
    matriz1[0][1] = 2.0;
    matriz1[0][2] = -1.0; 

    matriz1[1][0] = 2.0;    
    matriz1[1][1] = 1.0;    
    matriz1[1][2] = -2.0; 

    matriz1[2][0] = -3.0;    
    matriz1[2][1] = 1.0;    
    matriz1[2][2] = 1.0;

    matriz2[0][0] = 3.0;
    matriz2[0][1] = -1.0;
    matriz2[0][2] = 0.0;
    matriz2[0][3] = 0.0;
    matriz2[0][4] = 0.0;
    matriz2[0][5] = 0.5;

    matriz2[1][0] = -1.0;
    matriz2[1][1] = 3.0;
    matriz2[1][2] = -1.0;
    matriz2[1][3] = 0.0;
    matriz2[1][4] = 0.5;
    matriz2[1][5] = 0.0;

    matriz2[2][0] = 0.0;
    matriz2[2][1] = -1.0;
    matriz2[2][2] = 3.0;
    matriz2[2][3] = -1.0;
    matriz2[2][4] = 0.0;
    matriz2[2][5] = 0.0;

    matriz2[3][0] = 0.0;
    matriz2[3][1] = 0.0;
    matriz2[3][2] = -1.0;
    matriz2[3][3] = 3.0;
    matriz2[3][4] = -1.0;
    matriz2[3][5] = 0.0;

    matriz2[4][0] = 0.0;
    matriz2[4][1] = 0.5;
    matriz2[4][2] = 0.0;
    matriz2[4][3] = -1.0;
    matriz2[4][4] = 3.0;
    matriz2[4][5] = -1.0;

    matriz2[5][0] = 0.5;
    matriz2[5][1] = 0.0;
    matriz2[5][2] = 0.0;
    matriz2[5][3] = 0.0;
    matriz2[5][4] = -1.0;
    matriz2[5][5] = 3.0;


    //chamando as funções 
    gauss(MEDIO, matriz1, mult1, solucao1);

    gauss(MAX, matriz2, mult2, solucao2);

    exibeVetor(MEDIO, solucao1);
    exibeVetor(MAX, solucao2);
    
    //liberando a memoria
    free(matriz1);
    free(matriz2);

    free(solucao1);
    free(solucao2);

    free(mult1);
    free(mult2);

    return 0;
}