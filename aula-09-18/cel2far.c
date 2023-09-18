#include <stdio.h>

int main() {
    int celsius;
    printf("valor em celsius: ");
    scanf("%d", &celsius);
    
    int far = celsius*(9.0/5) + 32;
    
    printf("valor em farenheit: %d\n", far);
    return 0;
}
