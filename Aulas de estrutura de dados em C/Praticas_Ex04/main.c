#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
 * PRÁTICAS:
 *
 * Exercicio 4
 *   Modularize o codigo do Exercicio 2, apresentado no laboratório anteriormente. Sugira e
 *   implemente uma alternativa para evitar a repeticao do codigo que imprime as matrizes.
 *
 * Material de aula: Prof. MSc. Giulliano Paes Carnielli
 *
 */
#define DIMENSION 5
#define MAX_VAL 10

 /* Procedimento: imprimeMatriz
  * Descricao: imprime uma matriz inteira quadrada, formatando a saida de acordo com parametros
  * Parametros:
  *    1. char nomeMat[32]: nome da matriz a ser impressa. Tamanho maximo = 31 caracteres + '\0'
  *    2. int matriz[][]: matriz que deve ser impressa
  *    3. int digits: numero de digitos esperado para a entrada (usado na formatacao)
  */
void imprimeMatriz(char nomeMat[32], int matriz[][DIMENSION], int digits);

int main()
{
    /* Declara matrizes A e B (10x10) */
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

    /* Imprime matrizes */
    imprimeMatriz("Matriz A:", matA, 2);

    imprimeMatriz("Matriz B:", matB, 2);

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
    imprimeMatriz("Matriz Resultante: C = A x B", matResult, 3);

    return 0;
}

/* Procedimento: imprimeMatriz
 * Descricao: imprime uma matriz inteira quadrada, formatando a saida de acordo com parametros
 * Parametros:
 *    1. char nomeMat[32]: nome da matriz a ser impressa. Tamanho maximo = 31 caracteres + '\0'
 *    2. int matriz[][]: matriz que deve ser impressa
 *    3. int digits: numero de digitos esperado para a entrada (usado na formatacao)
 */
void imprimeMatriz(char nomeMat[32], int matriz[][DIMENSION], int digits) {
    char formato[8];
    char strDigits[3];
    itoa(digits, strDigits, 10);

    /* Ajusta precisao para formatacao da saida */
    strcpy(formato, "%.");
    strcat(formato, strDigits);
    strcat(formato, "d  ");

    /* Imprime matriz  */
    int i, j;
    /* Imprime nome da matriz */
    printf("\n%s\n", nomeMat);
    for (i = 0; i < DIMENSION; i++) {
        printf("\t"); /* Tabulacao entre colunas */
        for (j = 0; j < DIMENSION; j++) {
            /* Formata cada entrada com dois digitos, preenchidos com zeros */
            printf(formato, matriz[i][j]);
        }
        /* Proxima linha */
        printf("\n");
    }
}
