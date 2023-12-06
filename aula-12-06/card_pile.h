
#include <stdlib.h>
#include <stdbool.h>


// general constants
#define NCARDS 52
#define NSUITS 4
#define CARDS_PER_SUIT (NCARDS/NSUITS)

// card suites
typedef enum suits { Hearts, Diamonds, Clubs, Spades } suits_t;


typedef struct card {
    suits_t suit;   // card suit
    int value;      // card value; 
} card_t;


#define MAX_PILE_SIZE NCARDS
typedef struct card_pile {
    int capacity;   //  pile capacity
    int size;       //  pile current size
    card_t cards[MAX_PILE_SIZE];
} card_pile_t;


// card pile operations


void pile_init_full(card_pile_t *pile, bool shuffled);
 
bool pile_push(card_pile_t *pile, card_t card);
bool pile_pop(card_pile_t *pile, card_t *card);
 
int pile_size(const card_pile_t *p);
 
