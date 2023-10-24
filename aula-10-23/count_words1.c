
/**
 * a "wc" similar, counting the lines, words and chars of the input
 */

#include <stdio.h>


int main() {
    int line_count = 0;
    int char_count = 0;
    int word_count = 0;
    
    int c;  // caracter lido
    
     
    c= getchar(); // get a first char from input
    while( c  != EOF ) {
        while (c == ' ' || c == '\t') { char_count++; c= getchar(); } // separadores
        if (c == '\n') { char_count++; line_count++;  c = getchar(); } // mudança de linha
        else if (c != EOF) { // início de uma palavra
            word_count++;
            do {
                char_count++;
                c = getchar();
            }
            while( c != ' ' && c != '\t' && c != '\n' && c != EOF);
        }
  
    }
    
    printf("foram lidas %d linhas, %d palavras, %d caracters!\n", 
            line_count, word_count, char_count);
    
    return 0;
    
}


