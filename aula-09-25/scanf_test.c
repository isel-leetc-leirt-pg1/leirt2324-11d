/**
 * Este programa ilustra a forma como o "scanf"
 * informa de erros na leitura de valores"
 */

#include <stdio.h>


int main() {
    int n1, n2;
    
    printf("n1 n2? ");
    int res = scanf("%d%d", &n1, &n2);
    
    if (res == 2) {
        printf("valores lidos: %d %d\n", n1, n2);
    }
    else if (res == 1) {
        printf("apenas primeiro valor  numérico!: %d\n", n1);
    }
    else {
         printf("primeiro valor não numérico!");
    }
    return 0;
}
