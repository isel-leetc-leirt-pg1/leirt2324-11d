#include <pg/pglib.h>

 
// variáveis globais para representar o ponto anterior do rato
// o valor -1 significa que esse ponto não está definido
int lx= -1, ly = -1;

void mouse_handler(MouseEvent me) {
    
    if (me.state == BUTTON_PRESSED && me.button == BUTTON_LEFT) {
        if (lx != -1) {
            graph_line(lx,ly, me.x, me.y, c_black);
        }
        lx = me.x;
        ly = me.y;
    }
    else if (me.state == BUTTON_RELEASED && me.button == BUTTON_LEFT) {
        lx= -1, ly = -1;
    }
}

int main() {
    graph_init("Drawing", 800, 600);
    
    graph_regist_mouse_handler(mouse_handler);
    graph_start();
    return 0;
}
