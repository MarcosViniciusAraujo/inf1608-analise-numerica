#include <stdlib.h>
#include "matriz.h"
#include "gradconj.h"

int gradconj(int n, double **A, double *b, double *x, double tol, int precond)
{
    int cont = 0;

    double alfa;
    double beta;

    double *residuo = criavet(n);
    double *aux2 = criavet(n);
    double *z = criavet(n);
    double *r = criavet(n);
    double *d = criavet(n);
    double *aux3 = criavet(n);
    double *aux4 = criavet(n);
    double *aux5 = criavet(n);
    double *aux6 = criavet(n);
    double *aux7 = criavet(n);
    double *aux8 = criavet(n);
    double *aux9 = criavet(n);

    double **matrizPrecondicao = criamat(n, n);

    multmv(n, n, A, x, aux2);

    for (int i = 0; i < n; i++)
    {
        r[i] = b[i] - aux2[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            matrizPrecondicao[i][j] = 0.0;

        if (precond)
            matrizPrecondicao[i][i] = 1 / A[i][i];

        else
            matrizPrecondicao[i][i] = 1.0;
    }

    multmv(n, n, matrizPrecondicao, r, z);

    for (int i = 0; i < n; i++)
        d[i] = z[i];

    while (norma2(n, r) >= tol)
    {
        cont++;

        beta = escalar(n, r, z);

        multmv(n, n, A, d, aux2);

        alfa = escalar(n, r, z) / escalar(n, d, aux2);

        for (int i = 0; i < n; i++)
        {

            aux8[i] = x[i];
        }

        multvs(n, d, alfa, aux4);

        for (int i = 0; i < n; i++)
        {
            aux8[i] += aux4[i];
        }

        for (int i = 0; i < n; i++)
        {
            x[i] = aux8[i];
        }

        multmv(n, n, A, d, aux2);

        //cvome

        for (int i = 0; i < n; i++)
        {
            aux5[i] = r[i];
        }

        multvs(n, aux2, alfa, aux3);

        for (int i = 0; i < n; i++)
        {
            aux5[i] += -1.0 * aux3[i];
        }

        for (int i = 0; i < n; i++)
        {
            r[i] = aux5[i];
        }

        multmv(n, n, matrizPrecondicao, r, z);

        beta = escalar(n, r, z) / beta;

        for (int i = 0; i < n; i++)
        {
            aux6[i] = z[i];
        }

        multvs(n, d, beta, aux7);

        for (int i = 0; i < n; i++)
        {
            aux6[i] += aux7[i];
        }

        for (int i = 0; i < n; i++)
        {
            d[i] = aux6[i];
        }
    }

    return cont;
}
