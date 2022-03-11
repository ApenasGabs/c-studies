#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

/*
 * PRÁTICAS:
 *
 * Exercicio 1
 *   Escrever programa que declare um vetor de 100 elementos numéricos, preenchido aleatoriamente
 *   com valores entre 1 e 1000. Depois, deve receber um valor do usuário e verificar se existem
 *   elementos iguais a esse valor no vetor. Se existir, escrever as posições em que estão
 *   armazenados.
 *
 * Material de aula: Prof. MSc. Giulliano Paes Carnielli
 *
 */

 #define VET_TAM 100
 #define MAX_ITEM 1000
 #define MIN_ITEM 1

int main()
{
    /* Declara vetor de 100 posicoes */
    int vetNum[VET_TAM];

    /* Inicializa o vetor aleatoriamente */
    int i;
    srand(time(0));
    for (i = 0; i < VET_TAM; i++) {
        vetNum[i] = (rand() % MAX_ITEM) + MIN_ITEM;
        /* Tire o comentario da linha abaixo para ver os valores do vetor
         * printf("vet[%d]=%d\n", i, vetNum[i]);
         */
    }

    /* Recebe valor do usuario */
    int userVal;
    do {
        printf("Informe um valor no intervalo [%i, %i]:\n", MIN_ITEM, MAX_ITEM);
        scanf(" %i", &userVal);
    } while (userVal < MIN_ITEM || userVal > MAX_ITEM);

    /* Verifica se o valor fornecido encontra-se no vetor */
    short int found = 0;
    for (i = 0; i < VET_TAM; i++) {
        if (userVal == vetNum[i]) {
            printf("Encontrado: vetNum[%i]\n", i);
            found = 1;
        }
    }

    /* Se nenhuma ocorrencia foi encontrada, notificar o usuario */
    if (!found) {
            printf("Nenhuma ocorrencia encontrada!");
    }

    getch();

    return 0;
}
