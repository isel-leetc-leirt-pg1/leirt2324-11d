/**
 * programa de teste dos operações sobre arrays
 * 
 * comando de build: gcc -o tstsarrays -Wall tstarrays.c arrsys.c
 * 
 * O programa deve produzir um output idêntico ao conteúdo do ficheiro arrays_output_expected
 */

#include <stdio.h>
#include "arrays.h"


#define ARRAY_CAPACITY(a) (sizeof(a)/sizeof(a[0]))

void show_int_array(int a[], int size, int max_size) {
    printf("[");
    if (size > 0) {
        if (size > max_size) {
            printf("OVERFLOW");
        }
        else {
            printf("%d", a[0]);
            for(int i=1; i < size; ++i) {
                printf(",%d", a[i]);
            }
        }
    }
    printf("]\n");
}

void print_error() {
    printf("FAIL!\n");
}

void print_success() {
    printf("OK!\n");
}


int main() {
   
    printf("REMOVE REPS TESTS:\n");
    { 
      // test no repetitions
      int vals[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
      int size = ARRAY_CAPACITY(vals);
      if (a_remove_reps(vals, size) != size) print_error();
      else show_int_array(vals, size, size);
    }
    { // test all reps
      int vals[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
      int size = ARRAY_CAPACITY(vals);
      if (a_remove_reps(vals, size) != 1) print_error();
      else show_int_array(vals, 1, 1);
    }
    { // test some reps
      int vals[] = { 1, 2, 1, 1, 7, 7, 3, 6, 6, 5 };
      int size = ARRAY_CAPACITY(vals);
      int sz = a_remove_reps(vals, size);
      show_int_array(vals, sz, 6);
    }
    
    printf("\nROTATE RIGHT TESTS:\n");
    { 
        int vals[] = { 1, 2, 1, 1, 7, 7, 3, 6, 6, 5 };
        a_rotate_right(vals, ARRAY_CAPACITY(vals));
        show_int_array(vals, ARRAY_CAPACITY(vals), ARRAY_CAPACITY(vals));
    }
    
    { 
        int vals[] = { 1, 2, 3 };
        a_rotate_right(vals, ARRAY_CAPACITY(vals));
        show_int_array(vals, ARRAY_CAPACITY(vals), ARRAY_CAPACITY(vals));
    }
    
    printf("\nROTATE LEFT TESTS:\n");
    { 
        int vals[] = { 1, 2, 1, 1, 7, 7, 3, 6, 6, 5 };
        a_rotate_left(vals, ARRAY_CAPACITY(vals));
        show_int_array(vals, ARRAY_CAPACITY(vals), ARRAY_CAPACITY(vals));
    }
    { 
        int vals[] = { 1, 2, 3 };
        a_rotate_left(vals, ARRAY_CAPACITY(vals));
        show_int_array(vals, ARRAY_CAPACITY(vals), ARRAY_CAPACITY(vals));
    }
    printf("\nNAME COMPRESSED TESTS:\n");
    { 
        char name[] =  "Carlos  Manuel  SANtos";
        char result[20];
        name_compressed(name, result);
        printf("%s\n", result);
    }
    
    
    return 0;
}
