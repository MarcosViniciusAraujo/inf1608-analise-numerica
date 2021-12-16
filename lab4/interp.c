#include <stdlib.h>
#include <math.h>
#include "interp.h"

void regular(int n, double a, double b, double (*f)(double x), double *xi, double *yi)
{
    int i;
    double tamanho_amostra = (b - a) / (n - 1);

    xi[0] = a;
    yi[0] = f(xi[0]);

    for (i = 1; i < n; i++)
    {
        xi[i] = xi[0];
        xi[i] += tamanho_amostra * i;
        yi[i] = f(xi[i]);
    }
}

void chebyshev(int n, double a, double b, double (*f)(double x), double *xi, double *yi)
{
    int i, beta;
    int parcela_1 = (b - a) / 2;
    int parcela_2 = (a + b) / 2;

    for (i = 1; i <= n; i++)
    {
        beta = 2 * i - 1;
        xi[i - 1] = parcela_1 * cos((beta * 3.1415926535897932) / (2 * n)) + parcela_2;
        yi[i - 1] = f(xi[i - 1]);
    }
}

double lagrange(int n, double *xi, double *yi, double x)
{
    int k, j;
    double _p = 0, _l;

    for (k = 0; k < n; k++)
    {

        //calculando o L
        double numerador = 1.0, denominador = 1.0;
        for (j = 0; j < n; j++)
        {
            if (j == k)
                continue;

            numerador *= (x - xi[j]);
            denominador *= (xi[k] - xi[j]);
            //printf("DENOMINADOR: %g\n\n", denominador);
        }

        _l = numerador / denominador;

        _p += yi[k] * _l;
    }

    return _p;
}
