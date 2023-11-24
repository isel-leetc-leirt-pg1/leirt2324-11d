#include <pg/pglib.h>


/**
 * programa exemplo de utilização da biblioteca gráfica
 * 
 * build: gcc -o hello_graph -Wall hello_graph.c -lpg
 *
 */
 
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
    graph_init2("Hello World!", WINDOW_WIDTH,  WINDOW_HEIGHT);
    
    graph_rect(0,0, WINDOW_WIDTH, WINDOW_HEIGHT, c_red, true);
    graph_image("cartas/sa.png", 100, 50, 200, 300);
    graph_start();
}
