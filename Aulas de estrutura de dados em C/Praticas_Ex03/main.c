#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * PRÁTICAS:
 *
 * Exercicio 3
 *   Escreva uma função em C, que receba um número inteiro, como parâmetro, e devolva o maior
 *   algarismo contido nesse número (não trate a entrada como string).
 *
 * Material de aula: Prof. MSc. Giulliano Paes Carnielli
 *
 */

 /* Procedimento: getMaiorAlgarismo
  * Descricao: retorna o maior algarismo de um inteiro fornecido como parametro
  * Parametros:
  *    1. numero: inteiro que sera analisado pela funcao
  * Retorno: retorna o maior algarismo de 'numero'
  */
int getMaiorAlgarismo (int numero);

int main()
{
    char stop;
    printf("Programa para verificar maior algarismo em um numero inteiro:\n");

    /* Recebe valor do usuario */
    do {
        unsigned int userVal;
        do {
            printf("\nInforme um valor entre 0 e 65000: ");
            scanf(" %d", &userVal);
        } while (userVal < 0 || userVal > 65000);

        printf("O maior digito e' %d\n", getMaiorAlgarismo(userVal));

        printf("\n\nTentar novamente (S/N)?:\n");
        scanf(" %c", &stop);
    } while(tolower(stop) == 's');
    return 0;
}

 /* Procedimento: getMaiorAlgarismo
  * Descricao: retorna o maior algarismo de um inteiro fornecido como parametro
  * Parametros:
  *    1. numero: inteiro que sera analisado pela funcao
  * Retorno: retorna o maior algarismo de 'numero'
  */
int getMaiorAlgarismo (int numero){
  int maxDigit = 0;
  while (numero > 0) {
    /* Decompoe 'numero' atraves de divisoes inteiras, sucessivas, por 10 */
    int algarismo = numero % 10;
    if (algarismo > maxDigit) {
        maxDigit = algarismo;
    }
    /* Trunca algarismo a direita */
    numero = numero / 10;
  }
  return maxDigit;
}
