/*
Marcos Vinicius Araujo Almeida - 1910869
*/

#include "sistlinear.h"
#include <stdlib.h>
#include <math.h>

void fatoracao(int n, double **A, int *p)
{

    int i, linha, coluna, maximo, ponteiro_auxiliar;
    double temporario, resultado, auxiliar;

    //preenchendo o vetor p
    for (i = 0; i < n; i++)
        p[i] = i;

    //olhando primeiro para as colunas
    coluna = 0;
    while (coluna < n - 1)
    {

        maximo = coluna; // inicializando o maximo como o "primeiro" valor

        //procurando o valor maximo
        for (linha = coluna + 1; linha < n; linha++)
        {

            if (fabs(A[linha][coluna] > fabs(A[maximo][coluna])))
                maximo = linha;
        }

        //trocando as linhas
        for (ponteiro_auxiliar = 0; ponteiro_auxiliar < n; ponteiro_auxiliar++)
        {
            auxiliar = A[coluna][ponteiro_auxiliar];
            A[coluna][ponteiro_auxiliar] = A[maximo][ponteiro_auxiliar];
            A[maximo][ponteiro_auxiliar] = auxiliar;
        }

        //salvando  a troca do valor maximo encontrado no vetor
        temporario = p[coluna];
        p[coluna] = p[maximo];
        p[maximo] = temporario;

        for (linha = coluna + 1; linha < n; linha++)
        {
            resultado = A[linha][coluna] / A[coluna][coluna];

            for (ponteiro_auxiliar = coluna + 1; ponteiro_auxiliar < n; ++ponteiro_auxiliar)
            {
                A[linha][ponteiro_auxiliar] = A[linha][ponteiro_auxiliar] - (resultado * A[coluna][ponteiro_auxiliar]);
            }
            A[linha][coluna] = resultado;
        }

        coluna++;
    }
}

void substituicao(int n, double **A, int *p, double *b, double *x)
{

    int linha, coluna;

    //algoritmo Foward
    for (linha = 0; linha < n; linha++)
    {
        double soma = 0;

        for (coluna = 0; coluna < linha; coluna++)
            soma += A[linha][coluna] * x[coluna];

        x[linha] = b[p[linha]] - soma;
    }

    //algoritmo Backward
    for (linha = n - 1; linha >= 0; linha--)
    {
        double soma = 0;

        for (coluna = linha + 1; coluna < n; coluna++)
            soma = soma + (A[linha][coluna] * x[coluna]);

        x[linha] = (x[linha] - soma) / A[linha][linha];
    }
}

void gauss(int n, double **A, double *b, double *x)
{

    int *vetor_permutacao = (int *)malloc(n * sizeof(int)); // devo tratar NULL?

    fatoracao(n, A, vetor_permutacao);

    substituicao(n, A, vetor_permutacao, b, x);

    free(vetor_permutacao);
}
