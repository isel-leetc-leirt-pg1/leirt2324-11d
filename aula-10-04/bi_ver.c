#include <stdio.h>



int bi_ver(int bi) {
    int sum = 0;    // soma inicial
    int weight = 2; // peso inicial 
    
    while (bi > 0) {
        
        int dig = (bi% 10);   // algarismo das unidades
        sum = sum + weight*dig;
        
        bi = bi / 10;       // retirar algarismo das unidades
        weight++;           // incrementar o peso
        //weight = weight + 1;
        //weight += 1;
    }
    
    return 11 - sum % 11;
}

int main() {
    int b;
    
    printf("indique o bi: ");
    scanf("%d", &b);
    
    printf("O digito de vericação é: %d\n", bi_ver(b));
    
    return 0;
}
    
    
    
    
    
    
    
    
    
    
