#include <stdio.h>
#include <math.h>
#include "raiz.h"

double f(double x){
    return x*x*x + x - 7; 
}

double g(double x){
    return x*x*x*x + x + 1;
}

double h(double m){
    return 9.8*m/15.0*(1.0 - exp(-15.0/m*9.0)) - 35.0;
}

int main(){

    double raiz = 0;
    int resultado;

    printf("\n\n                LETRA A      \n\n");
    printf("====================SECANTE====================\n\n");

    printf("                   TESTE 1                   \n");
    resultado = secante(1.0, 2.0, f, &raiz);
    printf("Estiamtiva: [%g] - [%g]\n", 1.0, 2.0);
    printf("Interações: %d     Raiz: %f\n", resultado, raiz);
    
    printf("                   TESTE 2                   \n");
    resultado = secante(0.0, 3.0, f, &raiz);
    printf("Estiamtiva: [%g] - [%g]\n", 0.0, 3.0);
    printf("Interações: %d     Raiz: %f\n", resultado, raiz);
    
    printf("                   TESTE 3                   \n");
    resultado = secante(-1.0, 1.0, f, &raiz);
    printf("Estiamtiva: [%g] - [%g]\n", -1.0, 1.0);
    printf("Interações: %d     Raiz: %f\n", resultado, raiz);
    
    printf("====================IQI====================\n\n");

    printf("                   TESTE 1                   \n");
    resultado = IQI(1.0, 1.5, 3.0, f, &raiz);
    printf("Estiamtiva: [%g] - [%g] - [%g]\n", 1.0, 1.5, 2.0);
    printf("Interações: %d     Raiz: %f\n", resultado, raiz);

    printf("                   TESTE 2                   \n");
    resultado = IQI(0.0, 1.0, 2.0, f, &raiz);
    printf("Estiamtiva: [%g] - [%g] - [%g]\n", 0.0, 1.0, 2.0);
    printf("Interações: %d     Raiz: %f\n", resultado, raiz);

    printf("                   TESTE 3                   \n");
    resultado = IQI(-3.0, -1.5, 1.0, f, &raiz);
    printf("Estiamtiva: [%g] - [%g] - [%g]\n", -3.0, -1.5, 1.0);
    printf("Interações: %d     Raiz: %f\n", resultado, raiz);

    printf("\n\n                LETRA B      \n\n");
    printf("====================SECANTE====================\n\n");

    printf("                   TESTE 1                   \n");
    resultado = secante(1.0, 2.0, g, &raiz);
    printf("Estiamtiva: [%g] - [%g]\n", 1.0, 2.0);
    printf("Interações: %d     Raiz: NÃO CONVERGE\n", resultado);
    
    printf("                   TESTE 2                   \n");
    resultado = secante(0.0, 3.0, g, &raiz);
    printf("Estiamtiva: [%g] - [%g]\n", 0.0, 3.0);
    printf("Interações: %d     Raiz: NÃO CONVERGE\n", resultado);
    
    printf("                   TESTE 3                   \n");
    resultado = secante(-1.0, 1.0, g, &raiz);
    printf("Estiamtiva: [%g] - [%g]\n", -1.0, 1.0);
    printf("Interações: %d     Raiz: NÃO CONVERGE\n", resultado);
    
    printf("====================IQI====================\n\n");

    printf("                   TESTE 1                   \n");
    resultado = IQI(1.0, 1.5, 2.0, g, &raiz);
    printf("Estiamtiva: [%g] - [%g] - [%g]\n", 1.0, 1.5, 2.0);
    printf("Interações: %d     Raiz: NÃO CONVERGE\n", resultado);

    printf("                   TESTE 2                   \n");
    resultado = IQI(0.0, 1.0, 2.0, g, &raiz);
    printf("Estiamtiva: [%g] - [%g] - [%g]\n", 0.0, 1.0, 2.0);
    printf("Interações: %d     Raiz: NÃO CONVERGE\n", resultado);

    printf("                   TESTE 3                   \n");
    resultado = IQI(-3.0, -1.5, 1.0, g, &raiz);
    printf("Estiamtiva: [%g] - [%g] - [%g]\n", -3.0, -1.5, 1.0);
    printf("Interações: %d     Raiz: NÃO CONVERGE\n", resultado);


    printf("\n\n                LETRA C      \n\n");
    printf("====================SECANTE====================\n\n");

    printf("                   TESTE 1                   \n");
    resultado = secante(1.0, 2.0, h, &raiz);
    printf("Estiamtiva: [%g] - [%g]\n", 1.0, 2.0);
    printf("Interações: %d     Raiz: %g\n", resultado, raiz);
    

    
    printf("====================IQI====================\n\n");

    printf("                   TESTE 1                   \n");
    resultado = IQI(1.0, 1.5, 2.0, h, &raiz);
    printf("Estiamtiva: [%g] - [%g] - [%g]\n", 1.0, 1.5, 2.0);
    printf("Interações: %d     Raiz: %g\n", resultado, raiz);


    return 0;
}