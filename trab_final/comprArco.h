//Rodrigo Biscaia Fernandes - 1911416 - 3WA
#ifndef COMPRARCO_H
#define COMPRARCO_H

double fcao(double * kx, double * ky, double t);

double simpson (double (*f) (double), double a, double b, int n);

double bissection(double a, double b, double (*f) (double), double tol);

double maping(double s, double * kx, double * ky,double par, int n, double a, double b, double tol);

double * position_time(double * p, double * kx, double * ky, double t);

double * position_space(double s, double * kx, double * ky,double par, int n, double a, double b, double tol, double * pStar);

#endif


