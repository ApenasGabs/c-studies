#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
 * PRÁTICAS:
 *
 * Exercicio 5
 *   Escreva uma função em C que receba um número inteiro “i” e uma matriz 3x3 como parâmetros. A
 *   função deve calcular a multiplicação “m” dos elementos da diagonal principal dessa matriz. Deve
 *   atualizar a matriz original, multiplicando todos os seus elementos por “i”. O valor “m”
 *   calculado deve ser retornado.
 *
 * Material de aula: Prof. MSc. Giulliano Paes Carnielli
 *
 */
#define DIMENSION 3
#define MAX_VAL 10

 /* Procedimento: imprimeMatriz
  * Descricao: imprime uma matriz inteira quadrada, formatando a saida de acordo com parametros
  * Parametros:
  *    1. char nomeMat[32]: nome da matriz a ser impressa. Tamanho maximo = 31 caracteres + '\0'
  *    2. int matriz[][]: matriz que deve ser impressa
  *    3. int digits: numero de digitos esperado para a entrada (usado na formatacao
  */
void imprimeMatriz(char nomeMat[32], int matriz[][DIMENSION], int digits);

 /* Procedimento: processaMatriz
  * Descricao: realiza o processamento solicitado no enunciado do Exercicio 5
  * Parametros:
  *    2. (OUT) int matriz[][]: matriz que deve ser processada
  *    3. int i: numero inteiro usado no processamento
  * Retorno: valor na multiplicacao dos elementos da diagonal principal da matriz
  *          (os elementos da matriz original serao multiplicados por i)
  */
long processaMatriz(int matriz[][DIMENSION], int i);

int main()
{
    /* Declara matrizes A e B (10x10) */
    int matriz[DIMENSION][DIMENSION];

    /* Inicializa a matriz aleatoriamente */
    int i, j;
    srand(time(0));
    for (i = 0; i < DIMENSION; i++) {
        for (j = 0; j < DIMENSION; j++) {
            matriz[i][j] = rand() % (MAX_VAL + 1);
        }
    }

    /* Imprime matriz */
    imprimeMatriz("Matriz original M:", matriz, 2);

    /* Recebe valor do usuario */
    int userVal;
    do {
        printf("Informe um valor entre 1 e 32: ");
        scanf("%d", &userVal);
    } while (userVal < 0 || userVal > 32);

    /* Processa matriz */
    long m = processaMatriz(matriz, userVal);

    /* Imprime multiplicacao da diagonal principal */
    printf("\nValor da multiplicacao da Diagonal Principal de M: %lu\n", m);

    /* Imprime matriz resultante */
    imprimeMatriz("Matriz Resultante:", matriz, 4);

    return 0;
}

 /* Procedimento: processaMatriz
  * Descricao: realiza o processamento solicitado no enunciado do Exercicio 5
  * Parametros:
  *    2. (OUT) int matriz[][]: matriz que deve ser processada
  *    3. int i: numero inteiro usado no processamento
  * Retorno: valor na multiplicacao dos elementos da diagonal principal da matriz
  *          (os elementos da matriz original serao multiplicados por i)
  */
long processaMatriz(int matriz[][DIMENSION], int i) {
    /* Realiza processamento sugerido */
    int a, b;
    long m = 1;
    for (a = 0; a < DIMENSION; a++){
        for (b = 0; b < DIMENSION; b++){
            if (a == b) {
                m *= matriz[a][b];
            }
            matriz[a][b] *= i;
        }
    }
    return m;
}

/* Procedimento: imprimeMatriz
 * Descricao: imprime uma matriz inteira quadrada, formatando a saida de acordo com parametros
 * Parametros:
 *    1. char nomeMat[32]: nome da matriz a ser impressa. Tamanho maximo = 31 caracteres + '\0'
 *    2. int matriz[][]: matriz que deve ser impressa
 *    3. int digits: numero de digitos esperado para a entrada (usado na formatacao
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
