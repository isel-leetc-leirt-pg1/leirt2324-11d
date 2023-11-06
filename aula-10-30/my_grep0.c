
#include <stdio.h>
#include <stdbool.h>


/**
 * Descrição:
 *  lê uma linha de texto do standard input
 *  sem incluir o caracter mudança de linha '\n' até
 *  ao máximo de "size" caracteres
 *  Se a linha no input for superior ao máximo os caracteres
 *  
 * 
 * retorna o número de caracteres da linha 
 * ou -1 (EOF) se não houver mais caracteres disponíveis (fim do input)
 */
int getl(char line[], int size) {
    int c;
    int i=0;
    while(i < size -1 && (c = getchar()) != '\n' && c != EOF) {
        line[i] = c;
        ++i;
    }
    if (i== 0 && c == EOF) return -1;
    if (c != '\n') {
      // discard remaining chars in line
      while(getchar() != '\n');
    }
    line[i] = 0;
    return i;
}



bool find_substr(char str[], char sub[]) {
    int i = 0, j;
    
    while(str[i] != 0) {
        j = 0;
        
        while(str[i+j] == sub[j] && sub[j] != 0) {
            j++;
        }
         
    }
    // TEM DE SER COMPLETADA!
    return false;
}
