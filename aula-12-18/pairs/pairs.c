#include <stdio.h>
#include <pg/pglib.h>
#include <stdbool.h>
#include "pairs.h"

// variáveis globais

// array para converter valor (de 0 a 51) no nome da carta
char cardNames[][3] = {
	"c2", "c3", "c4", "c5", "c6", "c7", "c8", "c9", "ct", "ca", "cj", "ck", "cq",
	"h2", "h3", "h4", "h5", "h6", "h7", "h8", "h9", "ht", "ha", "hj", "hk", "hq",
	"d2", "d3", "d4", "d5", "d6", "d7", "d8", "d9", "dt", "da", "dj", "dk", "dq",
	"s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "st", "sa", "sj", "sk", "sq"
};


#define CARDS_FOLDER "../../cards"
#define BACK_CARD CARDS_FOLDER"/b.png"

pairs_game_t game;          // estado do jogo

Clock game_time;            // cronometro com o tempo de jogo
Counter counter;            // contador de pares


rem_anim_t ranim1, ranim2;  // estado das animações das duas cartas a remover


// funções auxiliares

/**
 * retorna um valor aleatório entre li e ls-1
 */
int rand_between(int li, int ls) {
	return rand() % (ls-li) + li;
}


void show_victory() {
	char msg[120];
	sprintf(msg, "You win in %d moves!", counter.val);
	graph_text(VICTORY_MSG_X, VICTORY_MSG_Y, COLOR_VICTORY_MSG, msg, LARGE_FONT);
}



void info_init() {
    // componentes de informações
    graph_rect(INFO_X,INFO_Y,INFO_WIDTH, INFO_HEIGHT, INFO_BACK_COLOR, true);
    clk_create_cron(&game_time, CLOCK_X, CLOCK_Y, 0, 0, MEDIUM_FONT, c_orange, INFO_BACK_COLOR);
    ct_create(&counter, COUNT_X, COUNT_Y, 0, "Plays", MEDIUM_FONT);
    info_refresh();
}


void info_refresh() {
    ct_show(&counter);
	clk_show(&game_time);
}


// cartas

// construção do estado inicial da carta
void card_init(card_t *card, int value) {
	card->value = value;
	card->state = HIDDEN;
}


void card_show_aux(int line, int col, int w, int h) {
	// obter coordenadas de ecrã
	int cx = BOARD_X + CARD_BORDER_X + (CARD_BORDER_X + CARD_WIDTH)*col;
	int cy = BOARD_END_Y - (CARD_BORDER_Y + CARD_HEIGHT)*(line+1);
	// obter carta
	card_t card = game.cards[line][col];
	
	char cardPath[100];
	
	graph_rect(cx,cy, CARD_WIDTH, CARD_HEIGHT, BACK_COLOR, true);
	if (card.state == VISIBLE || card.state == REMOVED) {
		sprintf(cardPath, "%s/%s.png", CARDS_FOLDER, cardNames[card.value]);
		graph_image(cardPath, cx, cy, w, h);
	}
	else if (card.state == HIDDEN) {
		graph_image(BACK_CARD, cx, cy, w, h);
	}
}


void card_show(int line, int col) {
	card_show_aux(line, col, CARD_WIDTH, CARD_HEIGHT);
}

int card_value(location_t l) {
	return game.cards[l.line][l.col].value;
}


void card_hide(location_t l) {
	game.cards[l.line][l.col].state = HIDDEN;
	card_show(l.line, l.col);
}

rem_anim_t card_remove(location_t l) {
	game.cards[l.line][l.col].state = REMOVED;
    rem_anim_t anim;
	anim_init(&anim, l.line, l.col);
    return anim;
}



// animações

void anim_init(rem_anim_t *ra, int line, int col) {
	ra->line = line; ra->col = col;
	ra->width = CARD_WIDTH; ra->height = CARD_HEIGHT;
	ra->stopped=false;
}

void anim_step(rem_anim_t *anim) {
	if (!anim->stopped) {
		card_show_aux(anim->line, anim->col, anim->width, anim->height);
		anim->width -= 4; anim->height -= 5;
		 
		if (anim->width <= 0 && anim->height <= 0) {
			game.remaining  -=1;
			if (game.remaining == 0) {
				show_victory();
				game.end=true;
			}
			anim->stopped = true;
		}
	}
}


void hide_pair(location_t l1, location_t l2) {
	game.hide1 = l1; game.hide2=l2;
	game.show_pair = true;
    game.count_milis = 0;
}


// jogo 


void board_init(board_t b)  {
    int values[DECK_SIZE];
    for(int i=0; i < DECK_SIZE; ++i) values[i] = i;
    
    
    int board_pos[BOARD_SIZE];
    for(int i=0; i < BOARD_SIZE; ++i) board_pos[i] = i;
    
	int board_values[BOARD_SIZE];

	int nvals = DECK_SIZE;
    int ncells = BOARD_SIZE;
    
	// initialize values
	for (int i=0; i < BOARD_SIZE; i+=2) {
        int cv = rand_between(0,nvals);
        int card = values[cv];
        values[cv] = values[--nvals];
        
        int bindex = rand_between(0,ncells);
        int bv = board_pos[bindex];
        board_pos[bindex] = board_pos[--ncells];
		board_values[bv] = card;
        
        bindex = rand_between(0,ncells);
        bv = board_pos[bindex];
        board_pos[bindex] = board_pos[--ncells];
        board_values[bv] = card;
	}
	
	// build a random board
	for (int l=0; l < NLINES; ++l) {
		for(int c=0; c < NCOLS; ++c) {
            card_init(&b[l][c], board_values[l*NCOLS+c]);
		}
	}
}


void game_init() {
    // background
    graph_rect(0,0,WINDOW_WIDTH, WINDOW_HEIGHT, c_black, true);
    
    // build a random board
    board_init(game.cards);
    
    // init state variables
	game.first.line =-1;
	game.remaining = BOARD_SIZE;
    ranim1.stopped=true;
	ranim2.stopped=true;
    
    game_refresh();
}

// converte as coordenadas da janela em coordenadas do tabuleiro
bool graph_to_board_loc(int x, int y, location_t *l) {
	 
	
	if (x < (BOARD_X + CARD_BORDER_X ) || x >= BOARD_X + BOARD_WIDTH - CARD_BORDER_X ||
	    y <= BOARD_END_Y - BOARD_HEIGHT + CARD_BORDER_Y || y > BOARD_END_Y - CARD_BORDER_Y) {
		  return false;
	}
 
    l->col = (x- BOARD_X)/(CARD_BORDER_X+CARD_WIDTH);
    l->line = (BOARD_END_Y - y) /(CARD_BORDER_Y+CARD_HEIGHT);
	 
	return true;
}


void game_refresh() {
	graph_rect(BOARD_X, BOARD_START_Y,BOARD_WIDTH, BOARD_HEIGHT, BACK_COLOR, true);
	for (int l=0; l < NLINES; ++l) {
		for(int c=0; c < NCOLS; ++c) {
			 card_show(l,c);
		}
	}
}

void game_play(location_t l) {
	if (game.cards[l.line][l.col].state != HIDDEN || game.show_pair || !ranim1.stopped ||
	 !ranim2.stopped) return;
	
    ct_inc(&counter);
	game.cards[l.line][l.col].state = VISIBLE;
	
    if (game.first.line == -1) {
		game.first = l;
	}
	else {
		if (card_value(game.first) == card_value(l)) {
			ranim1 = card_remove(game.first );
			ranim2 = card_remove(l );
			
		}
		else {
			hide_pair(game.first, l );
		}	
		game.first.line = -1;
	}	
	card_show(l.line, l.col);
}


// handlers de eventos

void mouse_handler(MouseEvent me) {
	if (me.type != MOUSE_BUTTON_EVENT || me.state != BUTTON_PRESSED)
		return;
	location_t l;
    
    if (graph_to_board_loc(me.x, me.y, &l)) {
        game_play(l);
    }
}

void timer_handler() {
	if (game.end) return;
    
    // esconder cartas visiveis
	if (game.show_pair) {
		game.count_milis += BASE_TIME;
		if (game.count_milis >= HIDE_TIME) {
			card_hide(game.hide1);
			card_hide(game.hide2);
			game.show_pair = false;
			
		}
	}
    
    // resolver animações
	if (!ranim1.stopped) 
		anim_step(&ranim1);
	if (!ranim2.stopped) 
		anim_step(&ranim2);
    
    // atualizar relógio
	++game.ticks;
	if (game.ticks == TICKS_PER_SEC) {
		clk_tick(&game_time);
		clk_show(&game_time);
		game.ticks=0;
	}
}


void key_handler(KeyEvent ke) {
	if (ke.state == KEY_PRESSED) {
		if (game.end) graph_exit();
	}
}

int main() {
    srand(time(NULL));
	graph_init2("Pairs", WINDOW_WIDTH, WINDOW_HEIGHT);
    
    
	game_init();
    info_init();
   
     
  	graph_regist_mouse_handler(mouse_handler);
	graph_regist_key_handler(key_handler);
	graph_regist_timer_handler(timer_handler, BASE_TIME);
	 
	graph_start();
	return 0;
}
