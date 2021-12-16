#include <math.h>
#include "otimizacao.h"

#define G ((sqrt(5) - 1) / 2)

double funcX1(double a, double b)
{
    return a + (1 - G) * (b - a);
}

double funcX2(double a, double b)
{
    return a + G * (b - a);
}

int SecaoAurea(double a, double b, double (*f)(double x), double tol, double *xmin)
{

    int cont = 0;
    double x1 = funcX1(a, b);
    double x2 = funcX2(a, b);
    double F1;
    double F2;

    F1 = f(x1);
    F2 = f(x2);

    while ((x2 - x1) / 2.0 > tol)
    {
        cont++;

        if (F1 >= F2)
        {
            a = x1;
            x1 = x2;
            F1 = F2;
            x2 = funcX2(a, b);
            F2 = f(x2);
        }
        //F1 < F2
        else
        {
            b = x2;
            x2 = x1;
            F2 = F1;
            x1 = funcX1(a, b);
            F1 = f(x1);
        }
    }

    *xmin = (x1 + x2) / 2.0;
    return cont;
}

int MIPS(double r, double s, double t, double (*f)(double x), double tol, double *xmin)
{

    int cont = 0;
    double Fr = f(r);
    double Fs = f(s);
    double Ft = f(t);
    double denominador;
    double resultado;
    double Fres;

    while (1)
    {
        if (cont == 50)
            return 0;

        if (cont >= 5 && fabs(Fs - Ft) <= tol)
            break;

        cont++;

        denominador = 2 * ((s - r) * (Ft - Fs) - (Fs - Fr) * (t - s));

        if (denominador < 1e-10)
            resultado = (r + s + t) / 3.0;
        else
            resultado = (((r + s) / 2.0) - ((Fs - Fr) * (t - r) * (t - s)) / denominador);

        Fres = f(resultado);
        r = s;
        Fr = Fs;
        s = t;
        Fs = Ft;
        t = resultado;
        Ft = Fres;
    }

    *xmin = (s + t) / 2.0;
    return cont;
}
