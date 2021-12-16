#include <stdio.h>
#include <math.h>
#include "taylor.h"

#define MAX 5
#define PI 3.1415926535897932

int main(){

    double testes[MAX] = {PI/10, PI/8, PI/6, PI/4, PI/3};
    
    printf("====================TESTE 1====================\n\n");
    printf("TAN(PI/10) = %g\n\n", tan(testes[0]));
    printf("tan1(PI/10) = %g     tan2(Pi/10) = %g\n\n", tan1(testes[0]), tan2(testes[0]));
    
    printf("====================TESTE 2====================\n\n");
    printf("TAN(PI/8) = %g\n\n", tan(testes[1]));
    printf("tan1(PI/8) = %g     tan2(Pi/8) = %g\n\n", tan1(testes[1]), tan2(testes[1]));
    
    printf("====================TESTE 3====================\n\n");
    printf("TAN(PI/6) = %g\n\n", tan(testes[2]));
    printf("tan1(PI/6) = %g     tan2(Pi/6) = %g\n\n", tan1(testes[2]), tan2(testes[2]));
    
    printf("====================TESTE 4====================\n\n");
    printf("TAN(PI/4) = %g\n\n", tan(testes[3]));
    printf("tan1(PI/4) = %g     tan2(Pi/4) = %g\n\n", tan1(testes[3]), tan2(testes[3]));
    
    printf("====================TESTE 5====================\n\n");
    printf("TAN(PI/3) = %g\n\n", tan(testes[4]));
    printf("tan1(PI/3) = %g     tan2(Pi/3) = %g\n\n", tan1(testes[4]), tan2(testes[4]));

}