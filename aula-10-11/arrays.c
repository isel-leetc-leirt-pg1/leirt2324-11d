#include <stdio.h>

#define MAX_VALS 1000


int search(int nums[], int size, int v);


int main() {
    int vals[MAX_VALS];
    
    int size = 0;
    
    int n;
    
    int nreps = 0;
    
    while(size < MAX_VALS && scanf("%d", &n) == 1) {
        if (search(vals, size, n) >= 0) // já existe
           nreps++;
        
        vals[size] = n;
        size++;
        
        // another way to break the cycle
        //if (size == MAX_VALS) break;
    }
    
    
    printf("foram introduzidos %d valores repetidos!\n", nreps);
    return 0;
    
}
