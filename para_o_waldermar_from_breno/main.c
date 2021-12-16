#include <stdio.h>
#include <math.h>
#include "trapezio.h"

#define PI 3.14159265358979323846

double teste1(double x)
{
    return x / sqrt(x * x + 9.0);
}

double teste2(double x)
{
    return exp(-x * x) * 2.0 * pow(PI, -0.5);
}

double teste3(double x)
{
    return log(sin(x) + cos(x));
}

int main()
{
    printf("%.6g\n", adaptiva(0.0, 1.0, teste1, 0.5e-6));
    printf("%.7g\n", adaptiva(0.0, 1.0, teste1, 0.5e-7));
    printf("%.8g\n\n", adaptiva(0.0, 1.0, teste1, 0.5e-8));

    printf("%.6g\n", adaptiva(0.0, 3.0, teste2, 0.5e-6));
    printf("%.7g\n", adaptiva(0.0, 3.0, teste2, 0.5e-7));
    printf("%.8g\n\n", adaptiva(0.0, 3.0, teste2, 0.5e-8));

    printf("%.6g\n", adaptiva(0.0, PI / 2.0, teste3, 0.5e-6));
    printf("%.7g\n", adaptiva(0.0, PI / 2.0, teste3, 0.5e-7));
    printf("%.8g\n\n", adaptiva(0.0, PI / 2.0, teste3, 0.5e-8));

    printf("%g\n", probabilidade(1.0));
    printf("%g\n", probabilidade(2.0));
    printf("%g\n", probabilidade(PI));

    return 0;
}