#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>


#define MAX_LINE 1024
#define MAX_PATH 256
#define MAX_WORD 32

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




/**
 * Descrição:
 *  verifica se a string "sub" ocorre dentro da string "str"
 * 
 * retorna true caso isso aconteça, ou false caso contrário.
 */
bool find_substr(char str[], char sub[]) {
    int i = 0, j;
    
    
    while(str[i] != 0) {
        j = 0;
        
        while(tolower(str[i+j]) == tolower(sub[j]) && sub[j] != 0) {
            j++;
        }
        
        if (sub[j] == 0) // ocorreu match
            return true;
        
        ++i;
         
    }

    return false;
}



int main(int argc, char *argv[]) {
   
    // get filename
    char filename[MAX_PATH];
    printf("ficheiro? ");
    //scanf("%s", filename);
    getl(filename, MAX_PATH);
    
    
    // open the file
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("erro ao abrir o ficheiro '%s'\n", filename);
        return 1;
    }
    // get word to find
    
   
    char word[MAX_WORD+1];
    
    // faltava este printf
    // o programa estava simplesmente à espera de ler a palavra...
    printf("palavra? ");
    getl(word, MAX_WORD+1);
    
    int line_number = 0;
    char line[MAX_LINE];
    
    while (fgets(line, MAX_LINE, file) != NULL) {
        line_number++;
        if (find_substr(line, word)) {
            printf("%3d: %s", line_number, line);
        }
    }
    
    fclose(file);
    
    return 0;
}
