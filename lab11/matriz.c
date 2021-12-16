/*
Marcos Vinicius Araujo Almeida - 1910869
*/
#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double *criavet(int n)
{
    double *vetor;
    vetor = (double *)malloc(n * sizeof(double));

    return vetor;
}

void liberavet(double *v)
{
    free(v);
}

double escalar(int n, const double *v, const double *w)
{
    double prodEscalar = 0;

    for (int i = 0; i < n; i++)
    {
        prodEscalar += v[i] * w[i];
    }

    return prodEscalar;
}

double norma2(int n, const double *v)
{
    double norma = 0;

    for (int i = 0; i < n; i++)
    {
        norma += pow(v[i], 2);
    }

    norma = sqrt(norma);

    return norma;
}

void multvs(int n, const double *v, double s, double *w)
{
    for (int i = 0; i < n; i++)
    {
        w[i] = v[i] * s;
    }
}

double **criamat(int m, int n)
{
    double **matriz;

    matriz = (double **)malloc(m * sizeof(double *));

    for (int i = 0; i < m; i++)
    {
        matriz[i] = criavet(n);
    }

    return matriz;
}

double **criamattri(int n)
{
    double **matrizTri;

    matrizTri = (double **)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++)
    {
        matrizTri[i] = (double *)malloc((i + i) * sizeof(double));
    }

    return matrizTri;
}

void liberamat(int m, double **A)
{
    for (int i = 0; i < m; i++)
    {
        free(A[i]);
    }

    free(A);
}

void transposta(int m, int n, const double **A, double **T)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            T[j][i] = A[i][j];
        }
    }
}

void multmv(int m, int n, const double **A, const double *v, double *w)
{
    for (int i = 0; i < m; i++)
    {
        w[i] = escalar(n, A[i], v);
    }
}

void multmm(int m, int n, int q, const double **A, const double **B, double **C)
{
    double **transpostaB = criamat(n, q);

    transposta(n, q, B, transpostaB);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            C[i][j] = 0;

            for (int l = 0; l < n; l++)
            {
                C[i][l] += A[i][l] * B[l][j];
            }
        }
    }
}
