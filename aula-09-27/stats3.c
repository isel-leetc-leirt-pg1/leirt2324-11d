#include <stdio.h>
#include <stdbool.h>
 

int main() {
    int sum = 0;        // soma dos valores lidos
    int n_numbers = 0;  // total de valores lidos
    int lower, greater; // limites inferior e superior dos valores lidos
    
    int n;
    
    printf("sequência de inteiros terminado por valor não numérico:\n");
    
    // ler um primeiro valor para funcionar como referència
    if (scanf("%d", &n) == 1) {
        greater = n;
        lower = n;
        sum = n;
        n_numbers++;
        
        // agora ler os restantes
        while(scanf("%d", &n) == 1) {
            if (n > greater) greater = n;
            else  if (n < lower) lower = n;
            sum += n;
            n_numbers++;
        }
    }   
     
    // show stats
    if (n_numbers < 3) {
        printf("dados inválidos!\n");
    }
    else {
        // o cast de "n_numbers" é para garantir que a divisão
        // é real e não inteira (porque todos os operandos seriam inteiros)
        double mean = (sum - (lower + greater))/ ((double) n_numbers - 2);
   
        
        printf("greater=%d\n", greater);
        printf("lower=%d\n", lower);
        printf("mean=%lf\n", mean);
        
    }


    return 0;
    
}
    
