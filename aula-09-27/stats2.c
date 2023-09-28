
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int main() {
    int sum = 0;
    int n_numbers = 0;
    
    // iniciar "lower" com o máximo valor possível
    // iniciar "greater" com o minímo valor possível
    // assim quaisquer que sejam os valores introduzidos
    // "lower" e "greater" serão devidamente iniciados
    int lower = INT_MAX, greater = INT_MIN;
    
    int n;
    
    while(scanf("%d", &n) == 1) {
        if (n > greater) greater = n;
        if (n < lower) lower = n;
        sum += n;
        n_numbers++;
    }
    
    // show stats
    if (n_numbers < 3) {
        printf("dados inválidos!\n");
    }
    else {
        double mean = (sum - (lower + greater))/ ((double) n_numbers - 2);
        
        printf("greater=%d\n", greater);
        printf("lower=%d\n", lower);
        printf("mean=%lf\n", mean);
        
    }
    
    return 0;
    
}
    
