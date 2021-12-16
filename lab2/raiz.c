#include <math.h>
#include <stdio.h>
#include "raiz.h"

int secante (double x0, double x1, double (*f) (double x), double* r){

    double erro = fabs((x1 - x0))/fabs(x1);
    double diff = 0;
    double x2 = 0;
    int cont = 0;
    double fX1 = 0;
    double fZero = 0;

    while (erro > 0.5e-8){
        
        fZero = f(x0);
        fX1 = f(x1);
        //calculando a diferença entre as chamadas
        diff = fabs(fX1 - fZero);
        
        //retorna 0 caso não exista convergencia
        if (cont > 50) return 0;

        //calculando o x2
        if (diff < 1e-15) x2 = (x0 + x1)/2;
        else x2 = x1 - ((fX1*(x1 - x0)) / (fX1 - fZero));

        //atualizando as variaveis 
        x0 = x1;
        x1 = x2;

        //recalculando o erro 
        erro = fabs((x1 - x0))/fabs(x1);

        //atualizando o contador
        cont++;
    }

    //retorna o valor se convergiu
    if (cont <= 50){

        *r = x2;
        return cont;
    }
    
}

int IQI (double x0, double x1, double x2, double (*f) (double x), double* r){

    double erro = fabs((x2 - x1))/fabs(x2);
    double x3 = 0;
    double detA = 0, detAc = 0;
    int cont = 0;
    double fZero = 0, fX1 = 0, fX2 = 0;

    while (erro > 0.5e-8){
        
        //calculando o valor dos f's
        fZero = f(x0);
        fX1 = f(x1);
        fX2 = f(x2);
        /*
        printf("====================\n\n");
        printf("ERRO = %.2f\n\n", erro);
        printf("X1 = %f    X2 = %f\n\n", x1, x2);
        printf("====================\n\n");

        */
        //caso de não convergencia
        if(cont > 50) return 0;
        
        //calculando o determinante
        detA  = -(fX1-fZero)*(fX2-fZero)*(fX2-fX1);
        detAc = fZero * fZero * fX1 * x2 + fZero * x1 * fX2 * fX2 + fX1 * fX1 * fX2 * x0 - 
        fX2 * fX2 * fX1 * x0 - fZero * fZero * fX2 * x1 - fX1 * fX1 * fZero * x2;

        //calculando o x3 = c
        x3 = detAc/detA;

        //reescrevendo os valores
        x0 = x1;
        x1 = x2;
        x2 = x3;

        //reescrevendo o erro 
        erro = fabs((x2 - x1))/fabs(x2);

        //atualizando o contador
        cont++;

        //printf("CONT = %d\n\n", cont);
    }

    //printf("R = %f\n\n", x3);

    if(cont <= 50){
        *r = x3;
        return cont;
    }
}