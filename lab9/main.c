#include <stdio.h>
#include <stdlib.h>
#include "massamola.h"

int main()
{
    double x = 200.0, y = 0.0, t = 100.0;
    int n = 1000;

    double *xn, *yn;

    xn = (double *)malloc(n * sizeof(double));
    yn = (double *)malloc(n * sizeof(double));

    simula(x, y, t, n, xn, yn);

    for (int i = 0; i < n; i++)
    {
        printf("%g %g\n", xn[i], yn[i]);
    }
    return 0;
}