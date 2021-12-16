#include <stdio.h>
#include <stdlib.h>
#include "gradconj.h"
#include "matriz.h"

#define N 10

double **matrizTeste()
{
    double **saida = criamat(N, N);

    for (int i = 0; i < N; i++)
    {

        if (i > 0)
            saida[i][i - 1] = 0.4;
        saida[i][i] = (double)i + 1;
        if (i < 9)
            saida[i][i + 1] = 0.4;
    }

    return saida;
}

int main()
{
    double **A = matrizTeste();
    double *b = criavet(N);
    double *x = criavet(N);
    double *y = criavet(N);

    b[0] = 1.4;
    b[1] = 2.8;
    b[2] = 3.8;
    b[3] = 4.8;
    b[4] = 5.8;
    b[5] = 6.8;
    b[6] = 7.8;
    b[7] = 8.8;
    b[8] = 1.8;
    b[9] = 10.4;

    for (int i = 0; i < N; i++)
    {
        x[i] = 0.0;
        y[i] = 0.0;
    }

    int res1, res2;

    res1 = gradconj(N, A, b, x, 1e-7, 0);
    res2 = gradconj(N, A, b, y, 1e-7, 1);
    printf("Interacoes: %d Precondicao: %d\n\n", res1, 0);

    printf("Solucao:\n");
    printf("[");
    for (int i = 0; i < N; i++)
        printf("%g ", x[i]);
    printf("]\n\n");

    printf("Interacoes: %d Precondicao: %d\n\n", res2, 1);
    printf("Solucao:\n");
    printf("[");
    for (int i = 0; i < N; i++)
        printf("%g ", y[i]);
    printf("]\n\n");

    return 0;
}