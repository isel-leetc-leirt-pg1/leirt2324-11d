#include <string.h>
#include <ctype.h>

#include "arrays.h"

/**
 * Descrição:
 *    Procura o valor "v" no array "nums"
 * Retorna:
 *    a posição onde o valor foi encontrado
 *    -1 caso o valor não exista no array
 */ 
int a_search(int nums[], int size, int v) {
    for(int i= 0; i < size; i++) {
        if (nums[i] == v) return i;
    }
    return -1;
}

/**
 * Descrição:
 *    remove o valor "to_remove" do array "vals"
 * Retorna:
 *    true se o valor foi removido
 *    false caso o valor não exista no array
 */
bool a_remove0(int vals[], int size, int to_remove) {
    for(int i=0; i < size; ++i) {
         if (vals[i] == to_remove) {
             // remove element
             vals[i] = vals[size - 1];
             return true;
         }
    }
    return false;
        
}

/**
 * Descrição:
 *    remove o valor "to_remove" do array "vals"
 *     Nesta versão é usada a função search
 * Retorna:
 *    true se o valor foi removido
 *    false caso o valor não exista no array
 */
bool a_remove(int vals[], int size, int to_remove) {
    int idx = a_search(vals, size, to_remove);
    if (idx == -1) return false;
    // remove element
    vals[idx] = vals[size - 1];
    return true;
}

/**
 * Descrição:
 *    remove o valor "to_remove" do array "vals"
 *    Nesta versão assume-se que a ordem dos valores no array não se pode alterar
 * Retorna:
 *    true se o valor foi removido
 *    false caso o valor não exista no array
 */
bool a_remove_ordered(int vals[], int size, int to_remove) {
    int idx = a_search(vals, size, to_remove);
    if (idx == -1) return false;
    // remove element
    for(int i= idx + 1; i < size; ++i) vals[i-1] = vals[i];
    return true;
}


