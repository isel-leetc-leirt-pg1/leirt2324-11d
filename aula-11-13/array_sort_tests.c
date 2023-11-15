#include "arrays.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// para usar a função time
#include <time.h>



#define MAX_SIZE 100

// constroi o array com valores aleatórios entre 1 e lim
void array_build(int a[], int size, int lim) {
    for (int i=0; i < size; ++i) {
        a[i] = abs(rand()) % lim + 1;
    }
}

void show_array(int a[], int size) {
    printf("[");
    // o resto...
    if (size > 0) {
        printf("%d", a[0]);
        for(int i=1; i < size; ++i) {
            printf(", %d", a[i]);
        }
    }
    
    printf("]\n");
    
}


bool a_is_sorted(int a[], int size) {
    for(int i = 0; i < size - 1; ++i) {
        if (a[i] > a[i+1]) return false;
    }
    return true;
}

 

int main() {
    
    int v[MAX_SIZE];
    
    // iniciar o gerador pseudo-aleatório
    // a função time retorna o número de segundos desde 1/1/1970
    srand(time(NULL));
    
    array_build(v, MAX_SIZE, 100);
    show_array(v, MAX_SIZE);
    a_position_sort(v, MAX_SIZE);
    
    if (a_is_sorted(v, MAX_SIZE)) {
        printf("OK!\n");
        
        show_array(v, MAX_SIZE);
    }
    else {
        printf("FAIL!\n");
    }
    return 0;
}

