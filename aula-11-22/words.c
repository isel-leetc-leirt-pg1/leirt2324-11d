
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

int we_cmp(word_entry_t *we, word_t w) {
    return strcmp(we->word, w);
}

void we_inc_count(word_entry_t *we) {
    we->count++;
}
    
void wt_init_empty(word_table_t *wt) {
   // (*wt).num_entries = 0;
   wt->num_entries = 0;
}

void we_init(word_entry_t *we, word_t word) {
    strcpy(we->word, word);
    we->count = 1;
}
    

bool wt_add_or_count_word(word_table_t *wt, word_t word) {
    for (int i = 0; i < wt->num_entries; ++i) {
        //if (strcmp(word, wt->entries[i].word) == 0 {
        if (we_cmp(&wt->entries[i], word) == 0) {
            // wt->entries[i].count++
            we_inc_count(&wt->entries[i]);
            return true;
        }
    }
    if (wt->num_entries == MAX_ENTRIES) return false;
    we_init(&wt->entries[wt->num_entries], word);
    wt->num_entries++; // one more entry in table
    return true;
}



#define MAX_WORDS_IN_LINE 32
void process_line(char l[], word_table_t *wt) {
    word_t words[MAX_WORDS_IN_LINE];
    
    int nwords = str_split(l, words, MAX_WORDS_IN_LINE);
    
    for(int i=0; i < nwords; ++i) {
       wt_add_or_count_word(wt, words[i]);
    } 
}


void wt_show(word_table_t *wt) {
    for(int i= 0; i < wt->num_entries; ++i) {
        printf("%-20s: %d\n", wt->entries[i].word, wt->entries[i].count);
    }
}



int main() {
    word_table_t words;    // words table
    
    printf("sizeof(words)=%ld\n", sizeof(word_table_t));
    
    wt_init_empty(&words);
    
    
    char line[MAX_LINE];   // current line
    
    while(fgets(line, MAX_LINE, stdin) != NULL) {
       process_line(line, &words);
    }
   
    wt_show(&words);
   
    return 0;
}
