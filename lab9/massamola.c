#include <math.h>
#include "massamola.h"

void forca(double t, double x, double y, double *fx, double *fy)
{
    double norma = sqrt(x * x + y * y);

    *fx = VENTO * exp(-t / 20) - K * (norma - R) * (x / norma);
    *fy = MASSA * GRAVIDADE - K * (norma - R) * (y / norma);
}

double evolui(double t, double h, double x, double y, double xp, double yp, double *xn, double *yn)
{
    double fx = 0.0, fy = 0.0;

    forca(t, x, y, &fx, &fy);

    *xn = x + (1 - DELTA) * (x - xp) + (h * h) * fx / MASSA;
    *yn = y + (1 - DELTA) * (y - yp) + (h * h) * fy / MASSA;

    return t + h;
}

void simula(double x0, double y0, double t_final, int n, double *x, double *y)
{

    double tempo_atual = 0.0, h = t_final / n;

    double xj = x0, yj = y0;

    for (int i = 0; i < n; i++)
    {

        tempo_atual = evolui(tempo_atual, h, x0, y0, xj, yj, &x[i], &y[i]);

        xj = x0;
        yj = y0;

        x0 = x[i];
        y0 = y[i];
    }
}
