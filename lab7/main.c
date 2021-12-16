#include <stdio.h>
#include <math.h>
#include "trapezio.h"

#define PI 3.14159265358979323846

//0 --> 1
double f(double x)
{
    return x / sqrt((x * x + 9.0));
}

//0 --> 3
double g(double x)
{
    return (2.0 / sqrt(PI)) * exp(-x * x);
}

//0 -> Pi/2
double h(double x)
{
    return log(cos(x) + sin(x));
}

int main()
{

    double res1, res2, res3;

    printf("\n========================= F =========================\n");
    res1 = adaptiva(0, 1, f, 0.5e-8);
    printf("res1 = %.8g [tol: 8 digitos]\n", res1);

    res1 = adaptiva(0, 1, f, 0.5e-6);
    printf("res1 = %.6g [tol: 6 digitos]\n", res1);

    res1 = adaptiva(0, 1, f, 0.5e-3);
    printf("res1 = %.3g [tol: 3 digitos]\n", res1);

    printf("\n========================= G =========================\n");
    res2 = adaptiva(0, 3, g, 0.5e-8);
    printf("res2 = %.8g [tol: 8 digitos]\n", res2);

    res2 = adaptiva(0, 3, g, 0.5e-6);
    printf("res2 = %.6g [tol: 6 digitos]\n", res2);

    res2 = adaptiva(0, 3, g, 0.5e-3);
    printf("res2 = %.3g [tol: 3 digitos]\n", res2);

    printf("\n========================= H =========================\n");
    res3 = adaptiva(0, PI / 2, h, 0.5e-8);
    printf("res3 = %.8g [tol: 8 digitos]\n", res3);

    res3 = adaptiva(0, PI / 2, h, 0.5e-6);
    printf("res3 = %.6g [tol: 6 digitos]\n", res3);

    res3 = adaptiva(0, PI / 2, h, 0.5e-3);
    printf("res3 = %.3g [tol: 3 digitos]\n", res3);

    //probabilidade
    printf("\n========================= probabilidade =========================\n");
    printf("Sigma: 2 => %.8g\n", probabilidade(2.0));
    printf("Sigma: 3 => %.8g\n", probabilidade(3.0));
    printf("Sigma: 4 => %.8g\n", probabilidade(4.0));
    return 0;
}