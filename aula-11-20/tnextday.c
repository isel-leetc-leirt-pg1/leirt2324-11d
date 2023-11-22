#include <stdio.h>
#include "dates.h"


int main() {
    date_t d1 = { .d = 30, .m = 11, .y = 2023 };
    
    date_t d2 = date_next(d1);
    
    date_show(d2);
    return 0;
}
