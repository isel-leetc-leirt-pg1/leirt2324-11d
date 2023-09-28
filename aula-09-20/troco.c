/**
 * Este programa apresenta as moedas mínimas necessárias
 * para entregar um dado troco lido da console em cêntimos
 * 
 * Jorge Martins, 2023
 */


#include <stdio.h>

int main() {
    int troco;
    
    int n_moedas;
    
    printf("O valor do troco em cêntimos: ");
    scanf("%d", &troco);
    
    printf("São necessárias:\n");
    
    // começar com a moeda de 2 euros (200 cêntimos)
    n_moedas = troco / 200;
    if (n_moedas > 0) {
        printf("%d moeda(s) de 2 euros\n", n_moedas);
        troco = troco % 200;
    }
    
    // moeda de 1 euro (100 cêntimos)
    n_moedas = troco / 100;
    if (n_moedas > 0) {
        printf("%d moeda(s) de 1 euro\n", n_moedas);
        troco = troco % 100;
    }
    
    // moeda de 50 cêntimos 
    n_moedas = troco / 50;
    if (n_moedas > 0) {
        printf("%d moeda(s) de 50 cêntimos\n", n_moedas);
        troco = troco % 50;
    }
    
    // moeda de 20 cêntimos 
    n_moedas = troco / 20;
    if (n_moedas > 0) {
        printf("%d moeda(s) de 20 cêntimos\n", n_moedas);
        troco = troco % 20;
    }
    
    // moeda de 10 cêntimos 
    n_moedas = troco / 10;
    if (n_moedas > 0) {
        printf("%d moeda(s) de 10 cêntimos\n", n_moedas);
        troco = troco % 10;
    }
    
    // moeda de 5 cêntimos 
    n_moedas = troco / 5;
    if (n_moedas > 0) {
        printf("%d moeda(s) de 5 cêntimos\n", n_moedas);
        troco = troco % 5;
    }
    
    // moeda de 2 cêntimos 
    n_moedas = troco / 2;
    if (n_moedas > 0) {
        printf("%d moeda(s) de 2 cêntimos\n", n_moedas);
        troco = troco % 2;
    }
    
    // moeda de 1 cêntimo
    if (troco > 0) {
        printf("1 moeda de 1 cêntimo\n");
    }
    
    return 0;
}
    
