#include <stdio.h>
#include <math.h>

int main() {
    double real_value;
    
    printf("indique um valor real: ");
    scanf("%lf", &real_value);
    
    
    printf("round(%lf)=%d\n", real_value, (int) round(real_value));
    
    return 0;
}
