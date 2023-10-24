/**
 * a "wc" similar, counting the lines, words and chars of the input,
 * now using a state variable, to identify a now word to word transition.
 */

#include <stdio.h>
#include <stdbool.h>

int main() {
    int line_count = 0;
    int char_count = 0;
    int word_count = 0;
    bool in_word = false; // state variable
    int c;
    
    while((c=getchar()) != EOF) {
        if (c == '\n') { in_word = false; line_count++; }
        else if (c == ' ' || c == '\t') {
            in_word = false;
        }
        else {
            if (!in_word) word_count++;
            in_word = true;
        }
        char_count++;
    }
    
    
    
    printf("foram lidas %d linhas, %d palavras, %d caracters!\n", 
        line_count, word_count, char_count);
    return 0;
}


