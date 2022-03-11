#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define DIMENSION 5
#define MAX_VAL 10

/*
 * PRÁTICAS:
 *
 * Exercicio 2
 *  Escrever programa que declare duas matrizes A e B, inteiras e bidimensionais 5x5, preenchidas
 *  aleatoriamente com valores entre 0 e 10. Depois:
 *  1. Imprimir as matrizes
 *  2. Executar a multiplicacao de A por B
 *  3. Imprimir a matriz resultante
 *
 * Material de aula: Prof. MSc. Giulliano Paes Carnielli
 *
 */
int main()
{
    /* Declara matrizes A e B (5x5) */
    int matA[DIMENSION][DIMENSION];
    int matB[DIMENSION][DIMENSION];

    /* Inicializa as matrizes aleatoriamente */
    int i, j;
    srand(time(0));
    for (i = 0; i < DIMENSION; i++) {
        for (j = 0; j < DIMENSION; j++) {
            matA[i][j] = rand() % (MAX_VAL + 1);
            matB[i][j] = rand() % (MAX_VAL + 1);
        }
    }

    /* Imprime matrizes  (o que poderia ser melhorado neste codigo?) */
    printf("\nMatriz A: \n");
    for (i = 0; i < DIMENSION; i++) {
        printf("\t"); /* Tabulacao entre colunas */
        for (j = 0; j < DIMENSION; j++) {
            /* Formata cada entrada com dois digitos, preenchidos com zeros */
            printf("%.2d  ", matA[i][j]);
        }
        /* Proxima linha */
        printf("\n");
    }

    printf("\nMatriz B: \n");
    for (i = 0; i < DIMENSION; i++) {
        printf("\t"); /* Tabulacao entre colunas */
        for (j = 0; j < DIMENSION; j++) {
            /* Formata cada entrada com dois digitos, preenchidos com zeros */
            printf("%.2d  ", matB[i][j]);
        }
        /* Proxima linha */
        printf("\n");
    }

    /* Multiplica Matrizes AxB */
    int matResult[DIMENSION][DIMENSION];
    int aux = 0;
    for (i = 0; i < DIMENSION; i++) {
        for (j = 0; j < DIMENSION; j++) {
            matResult[i][j] = 0;
            for (aux = 0; aux < DIMENSION; aux++) {
                matResult[i][j] += matA[i][aux]*matB[aux][j];
            }
        }
    }

    /* Imprime matriz resultante */
    printf("\nMatriz Resultante: C = A x B \n");
    for (i = 0; i < DIMENSION; i++) {
        printf("\t"); /* Tabulacao entre colunas */
        for (j = 0; j < DIMENSION; j++) {
            /* Formata cada entrada com dois digitos, preenchidos com zeros */
            printf("%.4d  ", matResult[i][j]);
        }
        /* Proxima linha */
        printf("\n");
    }

    getch();
    return 0;
}
