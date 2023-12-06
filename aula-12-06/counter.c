#include <pg/pglib.h>

// SDLK

#define WINDOW_WIDTH    400
#define WINDOW_HEIGHT   300
#define BACK_CLR        c_dgray

#define TIMER_X         50
#define TIMER_Y         50
#define TIMER_DIG_CLR   c_green
#define TIMER_BACK_CLR  c_gray

#define COUNTER_X   220
#define COUNTER_Y   50

#define BASE_TIME   1000

// global variables
Clock clk;
Counter counter;

void init() {
    graph_rect(0,0, WINDOW_WIDTH, WINDOW_HEIGHT, BACK_CLR, true);
    
    clk_create(&clk, TIMER_X, TIMER_Y, LARGE_FONT, TIMER_DIG_CLR, TIMER_BACK_CLR);
    
    ct_create(&counter, COUNTER_X, COUNTER_Y, 0, "Value", LARGE_FONT);
    
    clk_show(&clk);
    ct_show(&counter);
}

// event functions

void timer_handler() {
    clk_tick(&clk);
    clk_show(&clk);
}

void key_handler(KeyEvent ke) {
    if (ke.state == KEY_PRESSED) {
        if (ke.keysym == SDLK_DOWN) {
            ct_dec(&counter);
        }
        else if (ke.keysym == SDLK_UP) {
            ct_inc(&counter);
        }
        else if (ke.keysym == SDLK_t) {
            graph_exit();
        }
    }
}

int main() {
    graph_init2("Decks", WINDOW_WIDTH, WINDOW_HEIGHT);
  
    init();
    
      
    //graph_regist_mouse_handler(mouse_handler);
    //graph_set_auto_repeat_on();
    graph_regist_timer_handler(timer_handler, BASE_TIME);
    graph_regist_key_handler(key_handler);
    graph_start();
    return 0;
}

