#include <stdbool.h>

// general constants
#define NCARDS 52
#define NSUITS 4
#define NVALUES (NCARDS/NSUITS)

// card suites
typedef enum suits { Hearts, Diamonds, Clubs, Spades } suits_t;


typedef struct card {
    suits_t suit;   // card suit
    int value;      // card value; 
} card_t;


 
typedef struct card_pile {
    int capacity;   //  pile capacity
    int size;       //  pile current size
    card_t cards[NCARDS];
} card_pile_t;


void card_init(card_t *c, suits_t s, int v) {
    c->value = v;
    c->suit = s;
}

void pile_init_full(card_pile_t *p ) {
    
    for (int s= Hearts; s <= Spades; ++s) {
       for (int v = 0; v < NVALUES ; v++) {
           //p->cards[nc].suit = s; p->cards[nc].value = v;
           card_init(&p->cards[s*NVALUES+v], s, v);
          
       }
    }
    p->size = NCARDS;
    p->capacity = NCARDS;
     
}


bool pile_push(card_pile_t *p, card_t card) {
   // TO IMPLEMENT
   return false;
}

bool pile_pop(card_pile_t *p, card_t *card) {
   // TO IMPLEMENT
   return false;
}


 


