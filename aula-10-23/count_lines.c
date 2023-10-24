
/**
 * count the lines of the input
 */
 
#include <stdio.h>


int main() {
    int line_count = 0;
       
    int c;  // caracter lido
   
    while( (c = getchar()) != EOF /* -1 */ ) {
        if (c == '\n') line_count++; // mudança de linha
    }
    
    printf("foram lidas %d linhas!\n", line_count );
    
    return 0;
    
}


