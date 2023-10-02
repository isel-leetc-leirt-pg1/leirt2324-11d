#include <stdio.h>
#include "chrono.h"


/**
 * Este programa testa uma implementação da função
 * near_pi do 2º exercício da 2ª lista de exercícios.
 * 
 * Para produzir o executável terá executar o comando:
 * 
 * gcc -o near_pi_test -Wall near_pi_test.c chrono.c
 * 
 * Para testar no debugger use o comando:
 * 
 * gcc -o near_pi_test -Wall -g near_pi_test.c chrono.c
 * 
 */
 
 
//#include <math.h>

// declaração (assinatura) das funções my_power e near_pi

// A partir deste ponto, as definições das funções podem 
// ser colocadas em qualquer ponto do programa, antes ou depois da sua utilização (chamada)

double my_power(double base, int expon);
double near_pi(int n);



int main() {
    // teste do my_power
    printf("my_power(2,0) = %.0lf\n", my_power(2,0));
 //   printf("pow(2,0) = %.0lf\n", pow(2,0));
    
    printf("my_power(3,3) = %.0lf\n", my_power(3,3));
 //   printf("pow(3,3) = %.0lf\n", pow(3,3));
    
    // teste do near_pi
    int n;
    printf("ordem do somatório para avaliar pi? ");
    scanf("%d", &n);
    
    chrono_t chrono = chrono_start();
    
    double n_pi = near_pi(n);
    
    long micros = chrono_micros(chrono);
    
    printf("near_pi(%d)=%lf in %ld micros!\n", n, n_pi, micros);
    
    return 0;
}


/**
 * Esta função é uma versão limitada da função pow da biblioteca que
 * suoporta apenas expoentes inteiros naturais (>= 0)
 */ 
double my_power(double base, int expon) {
    
    double p = 1;
    
    /*
    int i = 0;
    
    while (i < expon) {
        p *= base;
        i = i + 1;
        printf("p=%.0lf\n", p);
    }
    */
    
    for( int i = 0; i < expon ; i++) {
        p *= base;
        //printf("p=%.0lf\n", p);
    }
    return p;
}

/**
 * Esta função é uma solução possível
 * do exercício 2 da 2ª lista de exercícios
 */ 
 
double near_pi(int n) {
    double np = 0;
    int numerator = 1;
    for( int k = 1; k <= n; k++) {
        // experimente a função tal como está e
        // também trocando os comentários das duas linhas seguintes
        // comentando a seguinte e descomentando a que agora está comentada
        // observe as diferenãs nos tempos de execução para valores n muito grandes (superiores a 10000)
        np += my_power(-1, k + 1) / ( 2* k -1);
        //np +=  (double) numerator / ( 2* k -1);
        
        numerator = -numerator;
    }
    return 4*np;
}
    
