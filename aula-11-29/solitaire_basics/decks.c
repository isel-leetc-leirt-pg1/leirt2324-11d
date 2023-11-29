#include <stdio.h>
#include <pg/pglib.h>
#include "card_pile.h"
#include <stdbool.h>
#include <stdlib.h>

#define BOARD_COLOR graph_rgb(0,64,0)

#define CARD_WIDTH     110 // 73
#define CARD_HEIGHT    146 // 97

#define CARD_MARGIN    10

#define WINDOW_WIDTH  (CARD_MARGIN+(CARD_WIDTH+CARD_MARGIN)*NVALUES)
#define WINDOW_HEIGHT (CARD_MARGIN+(CARD_HEIGHT+CARD_MARGIN)*NSUITS)

#define CARD_FOLDER "cards"
#define CARD_BACK 'b'

 

void card_show(card_t card, int x, int y, bool visible) {
    const char suit_names[] = { 'h', 'd', 'c', 's' };
    const char card_values[] = { 'a', '2', '3', '4', '5', '6', '7', '8', '9', 't', 'q', 'j', 'k'};
    char card_name[128];
    
    if (!visible)  sprintf(card_name, "%s/%c.png", CARD_FOLDER, CARD_BACK);
    else sprintf(card_name, "%s/%c%c.png", CARD_FOLDER, suit_names[card.suit], card_values[card.value]);
    graph_image(card_name, x, y, CARD_WIDTH, CARD_HEIGHT);
}


void init() {
    graph_rect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, BOARD_COLOR, true);
    
    card_pile_t deck;
    
    pile_init_full(&deck);
    
    int x, y; // next card coordinates
    
 
    y= CARD_MARGIN; 
    for (int s = Hearts ; s <= Spades; ++s) {  // for each suit
        
        x= CARD_MARGIN;
        for(int v = 0; v < NVALUES; ++v) {
            card_t card;
       
            if (!pile_pop(&deck, &card)) {
                printf("bad deck!\n");
                return;
            }
            card_show(card, x, y, true);
            x += CARD_WIDTH + CARD_MARGIN;
        }
        y += CARD_HEIGHT + CARD_MARGIN;
    }
     
}

 

int main() {
  
    graph_init2("Decks", WINDOW_WIDTH, WINDOW_HEIGHT);
  
    init();
  
   
    graph_start();
    return 0;
}
