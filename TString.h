#ifndef TSTRING_H_INCLUDED
#define TSTRING_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

// Definições Gerais
#define TRUE 1
#define FALSE 0
#define STR_BLOCK 64

// Código de Retorno
#define OP_OK 0

// Estrutura do TAD
typedef struct tstring {
    char *str;      // Vetor para alocação dinâmica
    int length;     // Tamanho do texto
    int n_blocks;    // Quantidade de blocos alocados
} TString;

// Operações sobre TString
TString *create_empty_str();
TString *create_string(const char str[]);
int append(TString *str1, TString *str2);
TString *substring(TString *str1, int start, int end, int *status);

#endif // TSTRING_H_INCLUDED
