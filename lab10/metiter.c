#include <stdlib.h>
#include <math.h>
#include "matriz.h"
#include "metiter.h"

int diagonal_dominante(int n, double **A)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && A[i][i] < fabs(A[i][j]))
                return 0;
        }
    }

    return 1;
}

double calculaResiduo(double **M, int tamanho, double *b, double *x)
{
    double *aux = criavet(tamanho);
    double *resultMult1 = criavet(tamanho);
    double residuo = 0.0;

    multmv(tamanho, tamanho, M, x, resultMult1);

    for (int i = 0; i < tamanho; i++)
    {
        aux[i] = b[i] - resultMult1[i];
    }

    residuo = norma2(tamanho, aux);

    return residuo;
}

int gauss_seidel(int n, double **A, double *b, double *x, double tol)
{
    int interacoes = 0;
    if (!diagonal_dominante(n, A))
        return 0;

    while (calculaResiduo(A, n, b, x) > tol)
    {
        for (int i = 0; i < n; i++)
        {
            double aux1 = b[i];

            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    aux1 = aux1 - A[i][j] * x[j];
            }

            aux1 = aux1 * (1 / A[i][i]);

            x[i] = aux1;
        }

        interacoes++;
    }

    return interacoes;
}

int SOR(int n, double **A, double *b, double *x, double tol, double w)
{
    int interacoes = 0;
    while (calculaResiduo(A, n, b, x) > tol)
    {
        for (int i = 0; i < n; i++)
        {
            double aux1 = b[i];

            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    aux1 = aux1 - A[i][j] * x[j];
            }

            aux1 = aux1 * (1 / A[i][i]);

            x[i] = (w * aux1) + ((1 - w) * x[i]);
        }

        interacoes++;
    }

    return interacoes;
}