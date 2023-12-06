#include "card_pile.h"
#include <stdlib.h>
#include <stdio.h>

static int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}



static void pile_shuffle(card_pile_t *p) {
  
}


void pile_init_full(card_pile_t *p, bool shuffled) {
    int nc = 0;
    for (int s= Hearts; s <= Spades; ++s) {
       for (int v = 0; v < CARDS_PER_SUIT ; v++) {
           p->cards[nc].suit = s; p->cards[nc].value = v;
           nc++;
       }
    }
    p->size = p->capacity = NCARDS;
    if (shuffled) pile_shuffle(p);
}


 

bool pile_push(card_pile_t *p, card_t card) {
     
    return false;
}

bool pile_pop(card_pile_t *p, card_t *card) {
    return false;
}

 

int pile_size(const card_pile_t *p) {
    return p-> size;
}
 
