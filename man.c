#include <stdio.h>
#include <stdlib.h>
#include "TString.h"

int main()
{
    TString *str1;

    str1 = create_empty_str();

    if (str1) {
        printf("String str1 criada!\n");
    } else {
        printf("String str1 nao foi criada!\n");
    }

    printf("Hello world!\n");
    return 0;
}
