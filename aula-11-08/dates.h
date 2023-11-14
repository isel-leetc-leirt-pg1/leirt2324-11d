
 #include <stdbool.h>


void date_today(int *day, int *month, int *year);


int date_cmp(int d1, int m1, int y1, int d2, int m2, int y2);
    


// pré declaração da função 
int year_remaining_days(int d, int m, int y);


/**
 * Retorna true se o ano "y" for bissexto
 */
bool leap_year(int y);


/**
 * A função já recebe um mês e ano válidos
 * Retorna o número de dias do mês "m"
 */
int month_days(int m, int y);
     

/**
 * Assume que o ano é válido.
 * A função retorna o número de dias do ano "y".
 */
int year_days(int y);


/**
 * Assume que a data é válida.
 * Retorna o número de dias que faltam até ao fim do ano "y"
 * (sem contar com o dia/mès/ano passado por parâmetro).
 */
int year_remaining_days(int d, int m, int y);
     

/**
 * Assume que a data é válida.
 * Retorna o número de dias que passaram desde o início do ano "y"
 * (contando com o dia/mès/ano passado por parâmetro).
 */
int year_passed_days(int d, int m, int y);
     
/**
 * a função retorna "true" se a data (d/m/y) passada por paràmetro é válida,
 * ou "false" caso contrário
 */

bool date_valid(int d, int m, int y);
    

/**
 * Retorna o número de dias entre duas datas
 * Nesta versão assume-se que a data d1/m1/y1 é menor que a data d2/m2/y2
 * também se assume que as datas pertencem a anos distintos, isto é (y1 != y2)
 */
int date_diff_days(int d1, int m1, int y1, int d2, int m2, int y2);
   
/**
 * Retorna um inteiro que representa o dia da semana da data indicada
 */
int date_weekday(int d, int m, int y);
    
