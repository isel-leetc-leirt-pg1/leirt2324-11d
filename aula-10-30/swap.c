#include <stdio.h>

/**
 * função que troca os parêmetros
 * de entrada/saída "*i1" e "*i2"
 * 
 * Notem que "i1" e "i2" são ponteiros (também chamados referências)
 * para os valores a serem trocados
 */
void swap(int *i1, int *i2) {
    int tmp = *i1;
    *i1 = *i2;
    *i2 = tmp;
}



int main() {
    int v1, v2;
    
    printf("v1 ? ");
    scanf("%d", &v1);
    
    printf("v2 ? ");
    scanf("%d", &v2);
    
    
    swap(&v1, &v2);
    
    printf("v1=%d, v2=%d\n", v1, v2);
    return 0;
}
