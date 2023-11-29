#include <stdbool.h>
#include "card_pile.h"
#include <stdlib.h>

int rand_range(int li, int ls) {
    return rand() % (ls -li) + li;
}

void card_init(card_t *c, suits_t s, int v) {
    c->value = v;
    c->suit = s;
}


void pile_shuffle(pile_card_t *p) {
    
}



void pile_init_full(card_pile_t *p, bool shuffle) {
    
    for (int s= Hearts; s <= Spades; ++s) {
       for (int v = 0; v < NVALUES ; v++) {
           //p->cards[nc].suit = s; p->cards[nc].value = v;
           card_init(&p->cards[s*NVALUES+v], s, v);
          
       }
    }
    
    p->size = NCARDS;
    p->capacity = NCARDS;
    
    if (shuffle) pile_shuffle(p);
    
      
}


bool pile_push(card_pile_t *p, card_t card) {
   // TO IMPLEMENT
   return false;
}

bool pile_pop(card_pile_t *p, card_t *card) {
   // TO IMPLEMENT
   return false;
}


 


