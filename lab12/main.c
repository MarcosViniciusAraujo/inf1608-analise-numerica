#include <stdio.h>
#include <math.h>
#include "otimizacao.h"

double f(double x)
{
    return x * x + sin(x);
}

double g(double x)
{
    return x * x * x * x * x * x + 11 * x * x * x + 17 * x * x - 7 * x + 1;
}

int main(void)
{
    int inter;
    double xmin;

    printf("===============================SECAO AUREA==================================\n\n");
    inter = SecaoAurea(-2.0, 1.0, f, 1e-5, &xmin);
    printf("Xmin = %.2f interacoes = %d\n", xmin, inter);

    inter = SecaoAurea(-1.5, 0.0, f, 1e-5, &xmin);
    printf("Xmin = %.2f interacoes = %d\n", xmin, inter);

    inter = SecaoAurea(-1.0, 5.0, f, 1e-5, &xmin);
    printf("Xmin = %.2f interacoes = %d\n", xmin, inter);

    inter = MIPS(3.1, 3.1415, 3.9, f, 1e-5, &xmin);
    printf("Xmin = %.2f interacoes = %d\n", xmin, inter);

    inter = MIPS(2.1, 3.2, 3.45, f, 1e-5, &xmin);
    printf("Xmin = %.2f interacoes = %d\n", xmin, inter);

    printf("===============================MIPS===============================\n\n");
    inter = SecaoAurea(-2.0, 1.0, g, 1e-5, &xmin);
    printf("Xmin = %.2f interacoes = %d\n", xmin, inter);

    inter = SecaoAurea(-1.5, 0.0, g, 1e-5, &xmin);
    printf("Xmin = %.2f interacoes = %d\n", xmin, inter);

    inter = SecaoAurea(-1.0, 5.0, g, 1e-5, &xmin);
    printf("Xmin = %.2f interacoes = %d\n", xmin, inter);

    inter = MIPS(3.1, 3.1415, 3.9, g, 1e-5, &xmin);
    printf("Xmin = %.2f interacoes = %d\n", xmin, inter);

    inter = MIPS(2.1, 3.2, 3.45, g, 1e-5, &xmin);
    printf("Xmin = %.2f interacoes = %d\n", xmin, inter);
}