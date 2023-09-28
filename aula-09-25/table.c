/**
 * este programa apresenta a tabuada do número lido da consola
 */

#include <stdio.h>

int main() {
    int n;
    
    printf("n? ");
    scanf("%d", &n);
    
    
    int i = 1;
    
    while( i <= 10) {
        //printf("%02d x %02d = %3d\n", i, n, i*n);
        printf("%2d x %2d = %3d\n", i, n, i*n);
        i += 1;
    }
    return 0;
}
