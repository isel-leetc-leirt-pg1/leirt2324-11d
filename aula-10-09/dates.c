#include <stdio.h>
#include <stdbool.h>


/**
 * Apresenta o dia da semana (0..6) por extenso.
 * Assume-se que é passado um dia da semana válido
 */
void print_wd(int wd) {
    switch(wd) {
        case 0: printf("domingo"); break;
        case 1: printf("segunda-feira"); break;
        case 2: printf("terça-feira"); break;
        case 3: printf("quarta-feira"); break;
        case 4: printf("quinta-feira"); break;
        case 5: printf("sexta-feira"); break;
        case 6: printf("sábado"); break;
    }
}


// pré declaração da função 
int year_remaining_days(int d, int m, int y);


/**
 * Retorna true se o ano "y" for bissexto
 */
bool leap_year(int y) {
   return  y % 4 == 0 && ( y % 100 != 0 || y % 400 == 0);
    
}

/**
 * A função já recebe um mês e ano válidos
 * Retorna o número de dias do mês "m"
 */
int month_days(int m, int y) {
    /*
    int dm;
    if (m == 4 || m == 6 || mes == 9 || mes == 11) dm = 30;
    else if (m == 2) { if (leap_year(y)) dm = 29; else dm = 28; }
    else dm = 31;
    return dm;
    
    ou 
     
    if (m == 4 || m == 6 || mes == 9 || mes == 11) return 30;
    else if (m == 2) { if (leap_year(y)) return 29; else return 28; }
    else return 31;
    */
    
    // utilizando a instrução "switch"
    int dm;
    switch(m) {
        case 4: case 6: case 9: case 11:
            dm = 30; break;
        case 2:
            if (leap_year(y)) dm = 29; else dm = 28;
            break;
        default:
            dm = 31; break;
    }
    return dm;
}

/**
 * Assume que o ano é válido.
 * A função retorna o número de dias do ano "y".
 */
int year_days(int y) {
  if (leap_year(y)) return 366; else return 365;
}

/**
 * Assume que a data é válida.
 * Retorna o número de dias que faltam até ao fim do ano "y"
 * (sem contar com o dia/mès/ano passado por parâmetro).
 */
int year_remaining_days(int d, int m, int y) {
     int days = month_days(m, y) - d;
     
     for(int ma = m + 1; ma <= 12; ma++) {
         days += month_days(ma, y);
     }
     //printf("year_remaining_days=%d\n", days);
     return days;
}

/**
 * Assume que a data é válida.
 * Retorna o número de dias que passaram desde o início do ano "y"
 * (contando com o dia/mès/ano passado por parâmetro).
 */
int year_passed_days(int d, int m, int y) {
    /*
    int days = d;
    for(int ma = 1; ma < m; ma++) {
        days += month_days(ma, y);
    }
    return days;
    */
    
    // outra versão usando a função remaining_days
    int dm = year_days(y) - year_remaining_days(d,m,y);
    
    //printf("year_passed_days=%d\n", dm);
    return dm;
}




/**
 * a função retorna "true" se a data (d/m/y) passada por paràmetro é válida,
 * ou "false" caso contrário
 */

bool date_valid(int d, int m, int y) {
    /*
    if (y < 1600) return false;
    if (m < 1 || m > 12) return false;
    return d >= 1 && d <= month_days(m, y);
    */
    
    return (y >= 1600) &&
           (m >= 1 && m <= 12) &&
           d >= 1 && d <= month_days(m, y);
}

/**
 * Retorna o número de dias entre duas datas
 * Nesta versão assume-se que a data d1/m1/y1 é menor que a data d2/m2/y2
 * também se assume que as datas pertencem a anos distintos, isto é (y1 != y2)
 */
int date_diff_days(int d1, int m1, int y1, int d2, int m2, int y2) {
    
    int d = year_remaining_days(d1, m1, y1);
    int ndays = d;
    
    for(int ya = y1 + 1; ya < y2; ya++) ndays += year_days(ya);
    
    //printf("days between=%d\n", ndays -  d);
    
    
    ndays += year_passed_days(d2, m2, y2);
    
    //printf("ndays=%d\n", ndays);
    
    return ndays;
}


/**
 * Retorna um inteiro que representa o dia da semana da data indicada
 */
int date_weekday(int d, int m, int y) {
    int dr = 1, mr = 1, yr = 1900;
    int wdr = 1; // segunda-feira
    
    int ndays = date_diff_days(dr, mr, yr, d, m, y);
    
    return (wdr + ndays) % 7;
}


int main() {
    
    int wd = date_weekday(9, 10, 2023);
    
    printf("dia 9/10/2023 foi ");
    print_wd(wd);
    printf("\n");
    return 0;
}
