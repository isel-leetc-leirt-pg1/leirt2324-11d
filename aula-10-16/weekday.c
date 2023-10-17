#include <stdio.h>
#include "dates.h"



/**
 * Apresenta o dia da semana (0..6) por extenso.
 * Assume-se que é passado um dia da semana válido
 */
void print_wd(int wd) {
    switch(wd) {
        case 0: printf("domingo"); break;
        case 1: printf("segunda-feira"); break;
        case 2: printf("terça-feira"); break;
        case 3: printf("quarta-feira"); break;
        case 4: printf("quinta-feira"); break;
        case 5: printf("sexta-feira"); break;
        case 6: printf("sábado"); break;
    }
}


int main() {
    int d, m, y;
    
    printf("data (d/m/a)? ");
    scanf("%d/%d/%d", &d, &m, &y);
    
    int wd = date_weekday(d, m, y);
    
    printf("dia %d/%d/%d foi ", d, m, y);
    print_wd(wd);
    printf("\n");
    return 0;
}
