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

#define WINDOW_WIDTH   1024
#define WINDOW_HEIGHT  800

#define CARD_FOLDER "../cards"
#define CARD_BACK 'b'


// card view struct - a view of a card in a given position
typedef struct card_view {
    card_t card;
    int x, y;
} card_view_t;

// a collection of card views
typedef struct card_view_col {
    card_view_t cviews[NCARDS];
    int size;
} card_view_col_t;


// global variables
card_pile_t deck;
card_view_t curr_view;
bool has_curr_view;


void card_show(card_t card, int x, int y, bool visible) {
    const char suit_names[] = { 'h', 'd', 'c', 's' };
    const char card_values[] = { 'a', '2', '3', '4', '5', '6', '7', '8', '9', 't', 'q', 'j', 'k'};
    char card_name[128];
    
    if (!visible)  sprintf(card_name, "%s/%c.png", CARD_FOLDER, CARD_BACK);
    else sprintf(card_name, "%s/%c%c.png", CARD_FOLDER, suit_names[card.suit], card_values[card.value]);
    graph_image(card_name, x, y, CARD_WIDTH, CARD_HEIGHT);
}


// card view functions

/**
 * card view construction
 */
void card_view_init(card_view_t *cv, card_t card, int x, int y) {
    cv->card = card;
    cv->x = x;
    cv->y = y;
}


/**
 * card view presentation
 */
void card_view_show(card_view_t cv, bool visible) {
    card_show(cv.card, cv.x, cv.y, visible); 
}


/**
 * changes the position of card view by dx, dy
 */
void card_view_translate(card_view_t *cv, int dx, int dy) {
    cv->x += dx;
    cv->y += dy;
}


// deck functions
bool deck_selected(int x, int y) {
    return  x >= DECK_X && x <= DECK_X + CARD_WIDTH &&
            y >= DECK_Y && y <= DECK_Y + CARD_HEIGHT;
}

void deck_show() {
    if (pile_size(&deck) == 0) { // baralho está vazio
        graph_rect(DECK_X, DECK_Y, CARD_WIDTH, CARD_HEIGHT, DECK_EMPTY_CLR, true);
    }
    else {
        char card_name[128];
        sprintf(card_name, "%s/%c.png", CARD_FOLDER, CARD_BACK); 
        graph_image(card_name, DECK_X, DECK_Y, CARD_WIDTH, CARD_HEIGHT);
    }
}


// refresca o estado da tabuleiro
void board_show_all() {
    
   // printf("show all!\n");
   // show the background
   graph_rect(0,0, WINDOW_WIDTH, WINDOW_HEIGHT, BOARD_COLOR, true);
   
   // mostrar o baralho
   deck_show();
   
   if (has_curr_view) { 
        // printf("showall : card!\n");
        card_view_show(curr_view, true);
   }
    
}
        

void mouse_handler(MouseEvent me) {
    if (me.state == BUTTON_PRESSED && me.button == BUTTON_LEFT) {
        if (has_curr_view) { // move the card view
            card_view_translate(&curr_view, me.dx, me.dy);
            board_show_all();
            
        }
        else if (deck_selected(me.x, me.y)) { // add a new card
            card_t card;
            if (pile_pop(&deck, &card)) {
                
                card_view_init(&curr_view, card, DECK_X, DECK_Y);
                has_curr_view = true;
                 
                board_show_all();
                 
            }
           
        }
        
    }
    else if (me.state == BUTTON_RELEASED && me.button == BUTTON_LEFT) {
        // afetr mouse button release no view is movable
        has_curr_view = false;
    }

}

/**
 * general initializations
 */
void init() {
    pile_init_full(&deck, true);
    has_curr_view = false;
    
    board_show_all();

}

int main() {
    graph_init2("Decks", WINDOW_WIDTH, WINDOW_HEIGHT);
  
    init();
    
      
    graph_regist_mouse_handler(mouse_handler);
   
    graph_start();
    return 0;
}
