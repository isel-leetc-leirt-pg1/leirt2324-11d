#include <stdio.h>



int count_digits(int n) {
    int count = 0;
    
    if (n== 0) return 1;
    
    do {
        count++;
        n = n / 10;
    } 
    while(n > 0);
    
    return count;
}

int main() {
    int n;
    printf("n? ");
    scanf("%d", &n);
    
    printf("%d tem %d  algarismos!\n", n, count_digits(n));
    return 0;
}
