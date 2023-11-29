#include <pg/pglib.h>

#define WINDOW_WIDTH 300
#define WINDOW_HEIGHT 200

#define TIMER_BASE 1000

typedef struct my_clock {
    int h, m, s;
} my_clock_t;

// clock é uma variável global
my_clock_t c;
  
  
  
void mc_init(my_clock_t *c) {
    c->h =0;
    c->m = 0;
    c->s = 0;
}

void mc_tick(my_clock_t *c) {
    c->s ++;
    if (c->s == 60) {
        c->s = 0;
        c->m++;
        if (c->m == 60) {
            c->m =0;
            c->h++;
        }
    }
}

void mc_show(my_clock_t *c) {
    printf("%02d:%02d:%02d\r", c->h, c->m, c->s);
    fflush(stdout);
}

void timer_handler() {
    //printf("clock!\n");
    mc_tick(&c);
    mc_show(&c);
}

int main() {
    graph_init("Clock", WINDOW_WIDTH, WINDOW_HEIGHT);
     
    mc_init(&c);
    
    
    graph_regist_timer_handler(timer_handler, TIMER_BASE);
    graph_start();
    return 0;
}
    
