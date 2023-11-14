#include <stdio.h>
#include "dates.h"


int main() {
    int d, m, y;
    
    date_today(&d, &m, &y);
    
    printf("hoje é %d/%d/%d\n", d, m, y);
    return 0;
}
