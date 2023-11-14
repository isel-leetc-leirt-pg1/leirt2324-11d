#include <stdio.h>
#include <stdbool.h>
#include "dates.h"
#include <string.h>

#include <unistd.h>

#define MAX_PATH_NAME 256
#define MAX_LINE 256
#define LINE_TOO_BIG -2


#define SUCCESS 0
#define ERROR -1

int getl(FILE *file, char *line, int size) {
    if (fgets( line, size, file) == NULL) return EOF;
    int ls = strlen(line);
    if (line[ls -1 ] =='\n')
        line[ls-1] = 0;
    else
        return LINE_TOO_BIG;
    return ls-1;
}


int main() {
    chdir("/home/isel/disciplinas/pg1/2023-2024/aulas/leirt2324-11d/aula-11-08");
    char path_in[MAX_PATH_NAME], path_out[MAX_PATH_NAME];
    
    printf("ficheiro contactos? ");
    if (getl(stdin, path_in, MAX_PATH_NAME) <= 0) {
        printf("nome inválido!\n");
        return 1;
    }
    FILE *fin = fopen(path_in, "r");
    if (fin == NULL) {
        printf("erro a abrir o ficheiro %s\n", path_in);
        return 2;
    }
    printf("ficheiro destino? ");
    if (getl(stdin, path_out, MAX_PATH_NAME) <= 0) {
        printf("nome inválido!\n");
        return 1;
    }
    FILE *fout = fopen(path_out, "w");
    if (fout == NULL) {
        printf("erro a criar o ficheiro %s\n", path_out);
        return 2;
    }
    
    int maxd;
    printf("dias máximos? ");
    scanf("%d", &maxd);
    
    int res = SUCCESS;
    
    int today_day, today_month, today_year;
    
    date_today(&today_day, &today_month, &today_year);
    
    // ciclo de processamento do ficheiro
    while(true) {
        char name[MAX_LINE];
        int day, month, year;
        
        // ler nome
        int ls;
        if ((ls = getl(fin, name, MAX_LINE)) <= 0) {
            if (ls != EOF) res = ERROR;
            break;
        }
        printf("nome= '%s'\n", name);
        
        // ler data de mascimento
        char birthday_line[MAX_LINE];
        if (getl(fin, birthday_line, MAX_LINE) <= 0) {
            res = ERROR;
            break;
        }
        printf("data nascimento = '%s'\n\n", birthday_line);
        int scan_res;
        if ((scan_res=sscanf(birthday_line, "%d/%d/%d", &day, &month, &year)) != 3) {
            printf("erro: sscanf retornou %d\n", scan_res);
            res = ERROR;
            break;
        }
        
        
        // validar a data
        if (!date_valid(day, month, year)) {
            res = ERROR;
            break;
        }   
        
        char empty[2];
        
        if (getl(fin, empty, 2) != 0) {
            res = ERROR;
            break;
        }
        // ler linha em branco
        
        // mudar ano do aniversariante
        year = today_year;
        
        // calcular diferença em dias
        int ndays = date_diff_days(today_day, today_month, today_year,day, month, year);
        printf("ndays=%d\n", ndays);
        if (ndays >= 0 && ndays <= maxd) { // aniversariante encontrado!
            fprintf(fout, "%s\n", name); // escrever o nome
            fprintf(fout, "%d\n\n", ndays); // escrever ndias e linha de intervalo
        }
    }
    
    
    // close dos ficheiros
    fclose(fin);
    fclose(fout);
    
    if (res != SUCCESS) {
        printf("erro de processamento!\n");
    }
    
    return 0;
    
}
    
    
