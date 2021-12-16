/*
Marcos Vinicius Araujo Almeida - 1910869
*/
#include <stdio.h>
#include "matriz.h"
#include <math.h>
#include <stdlib.h>

#define MAX_VETOR 5
#define MAX_MATRIZ 3

void exibeVetor(double *v, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%g - ", v[i]);
    }
    printf("]\n\n");
}

void preencheVetor(int escalar, int n, double *v)
{
    for (int i = 0; i < n; i++)
    {
        v[i] = escalar;
    }
}

void exibeMatriz(int linha, int coluna, double **A)
{
    printf("[ \n");

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("%g, ", A[i][j]);
        }
        printf("\n");
    }
    printf("]\n\n");
}

int main()
{
    printf("\n====================Questão 1===================\n");

    double *vetor1 = criavet(MAX_VETOR);
    preencheVetor(3, MAX_VETOR, vetor1);
    exibeVetor(vetor1, MAX_VETOR);

    printf("\n====================Questão 2===================\n");

    double *vetor2 = criavet(MAX_VETOR);
    preencheVetor(4, MAX_VETOR, vetor2);
    double produtoEscalar = prodescalar(MAX_VETOR, vetor1, vetor2);

    printf("Teste Produto Escalar: %g\n\n", produtoEscalar);

    printf("\n====================Questão 3===================\n");

    double norma = norma2(MAX_VETOR, vetor2);
    printf("Teste Norma2: %g\n\n", norma);

    printf("\n====================Questão 4===================\n");

    double *vetorResultadoMultiEscalar = criavet(MAX_VETOR);

    multvs(MAX_VETOR, vetor1, 5, vetorResultadoMultiEscalar);

    exibeVetor(vetorResultadoMultiEscalar, MAX_VETOR);

    printf("\n====================Questão 5===================\n");

    double **matrizQuadrada1 = criamat(3, 3);
    double **matrizRetangular1 = criamat(3, 2);

    exibeMatriz(3, 3, matrizQuadrada1);
    exibeMatriz(3, 2, matrizRetangular1);

    printf("\n====================Questão 7===================\n");

    double **matrizTriangular = criamattri(MAX_MATRIZ);
    //tive que preencher manualmente =(
    matrizTriangular[0][0] = 2.0;
    matrizTriangular[1][0] = 3.0;
    matrizTriangular[1][1] = 4.0;
    matrizTriangular[2][0] = 5.0;
    matrizTriangular[2][1] = 6.0;
    matrizTriangular[2][2] = 7.0;

    exibeMatriz(MAX_MATRIZ, MAX_MATRIZ, matrizTriangular);

    printf("\n====================Questão 8===================\n");

    double **transpostaResultado = criamat(2, 2);
    double **matrizQuadrada2 = criamat(2, 2);

    matrizQuadrada2[0][0] = 1;
    matrizQuadrada2[0][1] = 2;
    matrizQuadrada2[1][0] = 3;
    matrizQuadrada2[1][1] = 4;

    printf("Antes: \n");
    exibeMatriz(2, 2, matrizQuadrada2);

    transposta(2, 2, matrizQuadrada2, transpostaResultado);
    printf("Depois: \n");
    exibeMatriz(2, 2, transpostaResultado);

    printf("\n====================Questão 9===================\n");

    double *vetorTeste = criavet(2);
    double *vetorSaida = criavet(2);
    preencheVetor(3, 2, vetorTeste);

    multmv(2, 2, matrizQuadrada2, vetorTeste, vetorSaida);

    exibeMatriz(2, 2, matrizQuadrada2);
    printf("*\n\n");
    exibeVetor(vetorTeste, 2);
    printf("=\n");
    exibeVetor(vetorSaida, 2);

    printf("\n====================Questão 10==================\n");

    double **matrizQuadrada3 = criamat(2, 2);
    double **matrizSaida = criamat(2, 2);

    matrizQuadrada3[0][0] = 1;
    matrizQuadrada3[1][0] = 2;
    matrizQuadrada3[0][1] = 3;
    matrizQuadrada3[1][1] = 7;

    multmm(2, 2, 2, matrizQuadrada2, matrizQuadrada3, matrizSaida);
    exibeMatriz(2, 2, matrizSaida);

    printf("\n====================Questão 11==================\n");

    liberavet(vetor1);
    liberavet(vetor2);
    liberavet(vetorResultadoMultiEscalar);
    liberavet(vetorTeste);
    liberavet(vetorSaida);

    liberamat(2, matrizQuadrada2);
    liberamat(2, matrizQuadrada3);
    liberamat(2, transpostaResultado);
    liberamat(3, matrizQuadrada1);
    liberamat(3, matrizRetangular1);

    return 0;
}