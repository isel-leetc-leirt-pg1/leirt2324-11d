#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_NAME 256
#define MAX_LINE 256

int getl(FILE *file, char *line, int size) {
    if (fgets( line, size, file) == NULL) return EOF;
    int ls = strlen(line);
    if (line[ls-1] == '\n') {
        line[ls-1] = 0;
        return ls -1;
    }
    while( fgetc(file) != '\n');
    return ls;
}
 
int main() {
    chdir("/home/isel/disciplinas/pg1/2023-2024/aulas/leirt2324-11d/aula-11-08");
    char path_in[MAX_PATH_NAME], path_out[MAX_PATH_NAME];
    
    printf("origem? ");
    if (getl(stdin, path_in, MAX_PATH_NAME) <= 0) {
        printf("nome inválido!\n");
        return 1;
    }
    FILE *fin = fopen(path_in, "r");
    if (fin == NULL) {
        printf("erro a abrir o ficheiro %s\n", path_in);
        return 2;
    }
    printf("destino? ");
    if (getl(stdin, path_out, MAX_PATH_NAME) <= 0) {
        printf("nome inválido!\n");
        return 1;
    }
    FILE *fout = fopen(path_out, "w");
    if (fout == NULL) {
        printf("erro a criar o ficheiro %s\n", path_out);
        return 2;
    }
    
    int maxl;
    printf("máxima linha? ");
    scanf("%d", &maxl);
    
    char line[MAX_LINE];
    
    int ls, lc = 0;;
    while ((ls = getl(fin, line, maxl)) != EOF) {
        lc++;
        fprintf(fout, "%4d: %s", lc, line);
        if (ls == maxl-1) fprintf(fout, "...");
        fputc('\n', fout);
    }
    
    fclose(fin);
    fclose(fout);
    return 0;
}
    
    
