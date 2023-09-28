#include <stdio.h>
#include <stdbool.h>


int main() {
    int sum = 0;
    int n_numbers = 0;
    int lower, greater;
    
    int n;
    
    // indica se as variáveis "lower" e "greater" já estão devidamente iniciadas
    bool has_references = false;
    
    printf("sequência de inteiros terminado por valor não numérico:\n");
    
    while(scanf("%d", &n) == 1) { // enquanto número lido corretamente
        
        if (!has_references) {
            lower = n;
            greater = n;
            has_references = true;
        }
        else {
            if (n > greater) greater = n;
            else  if (n < lower) lower = n;
        }
        sum += n;
        n_numbers++;
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
    
