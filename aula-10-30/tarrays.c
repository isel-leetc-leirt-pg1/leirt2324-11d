/**
 * Este programa demonstra a equivalência entre arrays e ponteiros para char
 * Notem como  na assinatura da função m_strcpy se declaram os parâmetros de tipo array
 */

#include <stdio.h>

//#include <string.h>

void m_strcpy(char *dst, const char *src) {
    int i= 0;
    
    /**
     * descomentar qualquer uma das linhas seguintes
     * provoca um erro de compilação devido ao facto
     * do parâmetro "src" ser qualificado como const (constante)
     */
    //src[0] = 'b';
    // *src = 'b';
    
    /**
     * as implementações da função abaixo 
     * são equivalentes
     */
     
    /*
    while(src[i] != 0) {
        dst[i] = src[i];
        ++i;
    }
    dst[i] = 0;
    */
    
    
    while ((dst[i] = src[i]) != 0) ++i;
    
    
}

int main() {
    char a0[] = { 'a', 'b', 'c', 0 };
    
    char a[] = "cba";
    
    printf("&a[0]=%p\n", &a[0]);
    
    printf("a=%p\n", a);
    
    m_strcpy(a0, a);
    
    printf("a0='%s'\n", a0);
    printf("a ='%s'\n", a0);
    return 0;
}
    
