#include "trapezio.h"
#include <math.h>

#define PI 3.14159265358979323846

double adaptiva(double a, double b, double (*f)(double x), double tol)
{
    double m, Tab, Tam, Tmb, delta;

    m = (a + b) / 2.0;
    Tab = (b - a) * (f(a) + f(b)) / 2.0;
    Tam = (m - a) * (f(a) + f(m)) / 2.0;
    Tmb = (b - m) * (f(m) + f(b)) / 2.0;

    delta = Tab - (Tam + Tmb);

    if (fabs(delta) > 3.0 * tol)
    {
        return adaptiva(a, m, f, tol / 2.0) + adaptiva(m, b, f, tol / 2.0);
    }

    return Tam + Tmb - delta / 3.0;
}

double probabilidade(double sigma)
{
    double exp1(double x)
    {
        return exp((-x * x) / 2);
    }

    return 1 / (pow(2 * PI, 0.5)) * adaptiva(-sigma, sigma, exp1, 0.5e-8);
}