#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include "metiter.h"

int main()
{
    int interTest1, interTest2;

    double **A = criamat(2, 2);
    double *b = criavet(2);
    double *retorno1 = criavet(2);
    double *retorno2 = criavet(2);

    interTest1 = gauss_seidel(2, A, b, retorno1, 1e-7);
    interTest2 = SOR(2, A, b, retorno2, 1e-7, 1.0);

    printf("%d %d\n", interTest1, interTest2);
}