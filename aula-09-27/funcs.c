/**
 * Ilustra a criação e utilização de funções
 * 
 * experimente alterar a chamada factorial(6) para factorial(20)
 * 
 * tente explicar o resultado obtido
 */

#include <stdio.h>

int max(int i1, int i2) {
    if (i1 > i2) return i1;
    else return i2;
}

int max3(int i1, int i2, int i3) {
    return max(i1, max(i2, i3));
}


int factorial(int n) {
    int f = 1;
    while ( n > 1) {
        f *= n;
        n--;
    }
    return f;
}


// outra implementação possível podia ser a mostrada abaixo
// notem que estamos a usar a definição recursiva (0! = 1; n! = n * (n-1)!)
// que corresponde a uma chamada recursiva da função "factorial2"
// neste semestre não abordaremos oficialmente código recursivo
// mas poderemos ver outros exemplos mais tarde
int factorial2(int n) {
    if (n <= 1) return 1;
    else return n * factorial2(n-1);
}


int main() {
    int i1 = 3, i2 = 5, i3 = 1;
    
    int r1 = max(i1, i2);
    printf("max(i1, i2)=%d\n", max(i1, i2));
    
    printf("max2(i1, i2, i3)=%d\n", max3(i1, i2, i3));
    
    printf("factorial(20)=%d\n", factorial(6));
    printf("factorial2(6)=%d\n", factorial2(6));
    return 0;
}
