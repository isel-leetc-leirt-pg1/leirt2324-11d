
#include <stdio.h>
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

/**
 * Descrição:
 *      Procura o valor "to_find" no array "vals", de dimensão "size", usando o algoritmo da pesquisa dicotómica (ou binária)
 *      Neste método o array original é "partido" ao meio e o elemento central é comparado
 *      com a valor aa encontrar. Se o elemento do meio não corresponde ao valor a aencontrar então
 *      continua-se a pesquisa na metade inferior ou superior, consoante o elemento a encontrar seja inferior
 *      ou superior ao elemento do "meio"
 * Retorno:
 *    a posição onde o valor foi encontrado,
 *    ou -1 caso o valor "to_find" não exista no array
 */
int a_bin_search(int vals[], int size, int to_find) {
    int first = 0, last = size -1;
    
    while (first <= last) {
        int middle = (first + last) /2;
        //printf("middle=%d, vals[middle]=%d\n", middle, vals[middle]);
        if (vals[middle] < to_find) first = middle + 1;
        else if (vals[middle] > to_find) last = middle - 1;
        else return middle;
    }
    return -1;
}


/**
 * Descrição:
 *      inverte os elementos de um array de inteiros
 *      trocando o primeiro com o último, o segundo com
 *      o penultimo e assim sucessivamente...
 * Retorno:
 *      Nada
 */
void invert_array(int vals[], int size) {
    for(int i=0, j = size -1; i < j; ++i, --j) {
        int tmp = vals[i];
        vals[i] = vals[j];
        vals[j] = tmp;
    }
}

/**
 * Descrição:
 *  Ordena um arrsy de inteiros usando o algoritmo de Position Sort:
 *  Procura-se o maior elemento que troca de posição com o último elemento
 *  Faz-se o mesmo para todos os subarrays consecutivos
 * Retorno:
 *  Nada
 *  
 */ 
void a_position_sort(int vals[], int size) {
    for(int i= size-1; i > 0; --i) {
        int ibig = 0, big = vals[0];
        for(int j = 0; j <= i; ++j) {
            if (vals[j] > big) {
                big = vals[j];
                ibig = j;
            }
        }
        vals[ibig] = vals[i];
        vals[i] = big;
    }
}


void a_insertion_sort(int vals[], int size) {
    
    for (int i= 1; i < size; ++i) {
        int choosen = vals[i];
        int j;
        for (j = i - 1; j >= 0 && vals[j] > choosen; j--) {
            vals[j + 1] = vals[j];
        }
        vals[j+1] = choosen;
    }
}

















