
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "strutils.h"


#define MAX_LINE        1024
#define MAX_ENTRIES     1024


typedef struct word_entry {
    int count;
    word_t word;
} word_entry_t;


typedef struct word_table {
    int num_entries;
    word_entry_t entries[MAX_ENTRIES];
} word_table_t;

    


int main() {
    word_table_t words;    // words table
     
    
    char line[MAX_LINE];   // current line
    
    while(fgets(line, MAX_LINE, stdin) != NULL) {
       // ..............
    }
   
   
    return 0;
}
