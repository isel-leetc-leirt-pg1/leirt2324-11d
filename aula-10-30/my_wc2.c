
/**
 * Nova versão de my_wc onde process_line
 * actualiza directamente os paràmetros de saída que representam a 
 * contagem de caracteres e palavras
 */
 
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LINE 1024


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

void process_line(char line[], int *wc, int *cc /* char count address */) {
    int i= 0;
    bool in_word = false;
    int nwords = 0;
    while ( line[i] != 0 ) {
        if (isspace(line[i])) in_word = false;
        else {
            if (!in_word) {
                in_word = true;
                nwords++;
            }
        }
        ++i;
    }
    *cc = *cc + i;
    // *cc += i
    *wc +=  nwords;
}
 


int main() {
    char line[MAX_LINE];
    int char_count = 0, word_count = 0, line_count = 0;
  
    int ls;
    while((ls = getl(line, MAX_LINE)) != EOF) {
        // process line
        
        line_count++;
        process_line(line, &word_count, &char_count);
    }
    
    char_count += line_count; // count line terminators
    
    printf("%d %d %d\n", line_count, word_count, char_count);
    return 0;
}
