/**
 * version of file counting lines, words and chars
 * using a line by line strategy
 */
 
 
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LINE 1024

/**
 * read a line from input
 * return the size of the line or EOF(-1) 
 * next input char is EOF
 * 
 * if the line is toobig to fit in "line" ramaining chars are discarded
 */
 
int getl(char line[], int size) {
   int i = 0;
   int c;
   
   while ( i < size - 1 && (c= getchar()) != '\n' && c != EOF) {
       line[i++] = c; 
   }
   if (i == 0 && c == EOF) {
       printf("end of file!\n");
       return EOF;
   }
   
   line[i] = 0; // string terminator
   
   if (c != '\n')  {
       printf("discard remaining chars!\n");
       // read remaining chars of line
       while ((c=getchar()) != '\n' && c != EOF);
   }
   //printf("line: %s\n", line);
   return i;
}



int main() {
    char line[MAX_LINE];
    int char_count = 0, word_count = 0, line_count = 0;
  
    int ls;
    while((ls = getl(line, MAX_LINE)) != EOF) {
        bool in_word = false;
        int i= 0;
        //printf("start line process!\n");
        line_count++;
        while ( line[i] != 0 ) {
            if (isspace(line[i])) in_word = false;
            else {
                if (!in_word) {
                    in_word = true;
                    word_count++;
                }
            }
            char_count++;
            ++i;
        }
        //printf("end line process!\n");
        
    }
    
    printf("%d %d %d\n", line_count, word_count, char_count+ line_count);
    return 0;
}
