#include <stdio.h>
#include <pg/pglib.h>
#include "card_pile.h"
#include <stdbool.h>
#include <stdlib.h>

#define BOARD_COLOR graph_rgb(0,128,0)
#define DECK_EMPTY_CLR graph_rgb(0,32,0)

#define CARD_WIDTH     110 // 73
#define CARD_HEIGHT    146 // 97

 
#define DECK_X    50
#define DECK_Y    50

#define DISCARD_X   (DECK_X + 300)
#define DISCARD_Y    50

#define WINDOW_WIDTH   1024
#define WINDOW_HEIGHT  800

#define CARD_FOLDER "../cards"
#define CARD_BACK 'b'

 

void card_show(card_t card, int x, int y, bool visible) {
    const char suit_names[] = { 'h', 'd', 'c', 's' };
    const char card_values[] = { 'a', '2', '3', '4', '5', '6', '7', '8', '9', 't', 'q', 'j', 'k'};
    char card_name[128];
    
    if (!visible)  sprintf(card_name, "%s/%c.png", CARD_FOLDER, CARD_BACK);
    else sprintf(card_name, "%s/%c%c.png", CARD_FOLDER, suit_names[card.suit], card_values[card.value]);
    graph_image(card_name, x, y, CARD_WIDTH, CARD_HEIGHT);
}

 
 


void board_show_all() {
     
   
}
        

void mouse_handler(MouseEvent me) {
    
   
       
}


int main() {
  
    graph_init2("Decks", WINDOW_WIDTH, WINDOW_HEIGHT);
  
    board_show_all();
    
    graph_regist_mouse_handler(mouse_handler);
   
    graph_start();
    return 0;
}
