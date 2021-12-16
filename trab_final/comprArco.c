// Rodrigo Biscaia Fernandes - 1911416 - 3WA
#include "comprArco.h"
#include <math.h>

double fcao(double *kx, double *ky, double t)
{
    return kx[1] + 2.0 * kx[2] * t + 3.0 * kx[3] * t * t + ky[1] + 2.0 * ky[2] * t + 3.0 * ky[3] * t * t;
}

double simpson(double (*f)(double), double a, double b, int n)
{
    double h = (b - a) / ((double)n);
    double med = a + (h / 2.0);
    int i;
    double sumOne = 0.0;
    double sumTwo = 0.0;
    for (i = 1; i < n; i++)
    {
        sumOne += f(a + ((double)i) * h);
        sumTwo += f(med);
        med += h;
    }
    sumTwo += f(med);
    sumOne *= 2.0;
    sumTwo *= 4.0;
    return (f(a) + f(b) + sumOne + sumTwo) * (h / 6.0);
}

double bissection(double a, double b, double (*f)(double), double tol)
{
    double c;
    while (fabs(b - a) <= tol)
    {
        c = (a + b) / 2.0;
        if (f(a) * f(b) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }
    return c;
}

// questao 2
double maping(double s, double par, int n, double a, double b, double tol)
{
    return bissection(a, b, s - simpson(fcao, 0.0, par, n), tol);
}

// questao 3
double *position_time(double *p, double *kx, double *ky, double t)
{
    p[0] = kx[1] + 2.0 * kx[2] * t + 3.0 * kx[3] * t * t;
    p[1] = ky[1] + 2.0 * ky[2] * t + 3.0 * ky[3] * t * t;

    return p;
}

// questao 4
double *position_space(double s, double *kx, double *ky, double par, int n, double a, double b, double tol, double *pStar)
{
    double t = maping(s, kx, ky, par, n, a, b, tol);
    return position_time(pStar, kx, ky, t);
}
