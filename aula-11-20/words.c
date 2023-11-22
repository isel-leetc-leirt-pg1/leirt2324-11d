
#include <stdio.h>
 

#define MAX_LINE        256
#define MAX_ENTRIES     1024


#define MAX_WORD_SIZE 32

typedef char word_t[MAX_WORD_SIZE+1];

typedef struct word_entry {
    int num_occurs;
    word_t word;
} word_entry_t;


typedef struct word_table {
    int num_entries;
    word_entry_t entries[MAX_ENTRIES];
} word_table_t;

    
 


int main() {
    word_table_t words;               // words table
     
    
    return 0;
}
