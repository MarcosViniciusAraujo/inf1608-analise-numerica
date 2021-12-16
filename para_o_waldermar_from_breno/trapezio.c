#include <math.h>
#include "trapezio.h"

#define PI 3.14159265358979323846

double adaptiva(double a, double b, double (*f)(double x), double tol)
{
    double m = (a + b) / 2.0;
    double i, j, k, delta;

    i = (b - a) * (f(a) + f(b)) / 2.0;
    j = (m - a) * (f(a) + f(m)) / 2.0;
    k = (b - m) * (f(m) + f(b)) / 2.0;
    delta = i - j - k;
    if (fabs(delta) > 3.0 * tol)
    {
        return adaptiva(a, m, f, tol / 2.0) + adaptiva(m, b, f, tol / 2.0);
    }
    return j + k - delta / 3.0;
}

double probabilidade(double sigma)
{
    double treco_chato(double x)
    {
        return exp(-x * x / 2.0) * pow(2.0 * PI, -0.5);
    }

    return adaptiva(-sigma, sigma, treco_chato, 0.5e-8);
}