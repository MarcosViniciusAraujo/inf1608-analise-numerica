#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "interp.h"

#define PI 3.1415926535897932
#define N 10
#define M 20
double f_teste1(double x)
{
    return (2.0 / (sqrt(2 * 3.1415926535897932))) * exp(-2.0 * x * x);
}

void exibeVetor(int n, double *v)
{
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%g\n", v[i]);
    }
}

int main()
{

    printf("TESTE 1\n\n");
    double *x1, *y1;

    x1 = (double *)malloc(N * sizeof(double));
    y1 = (double *)malloc(N * sizeof(double));

    double *x2, *y2;

    x2 = (double *)malloc(N * sizeof(double));
    y2 = (double *)malloc(N * sizeof(double));

    regular(N, -2.0, 2.0, f_teste1, x1, y1);

    chebyshev(N, -2.0, 2.0, f_teste1, x2, y2);

    double teste_1 = lagrange(N, x1, y1, 1.0);
    double teste_2 = lagrange(N, x2, y2, 1.0);

    printf("%g %g\n\n", teste_1, teste_2);

    printf("TESTE 2\n\n");
    double *x3, *y3;

    x3 = (double *)malloc(M * sizeof(double));
    y3 = (double *)malloc(M * sizeof(double));

    double *x4, *y4;

    x4 = (double *)malloc(M * sizeof(double));
    y4 = (double *)malloc(M * sizeof(double));

    regular(M, -2.0, 2.0, f_teste1, x3, y3);

    chebyshev(M, -2.0, 2.0, f_teste1, x4, y4);

    double teste_3 = lagrange(M, x3, y3, 1.0);
    double teste_4 = lagrange(M, x4, y4, 1.0);

    printf("%g %g\n\n", teste_3, teste_4);

    return 0;
}