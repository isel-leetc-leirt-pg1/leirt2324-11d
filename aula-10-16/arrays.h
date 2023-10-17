#include <stdbool.h>

/**
 * Descrição:
 *    Procura o valor "v" no array "nums"
 * Retorna:
 *    a posição onde o valor foi encontrado
 *    -1 caso o valor não exista no array
 */ 
int a_search(int nums[], int size, int v);

 
/**
 * Descrição:
 *    remove o valor "to_remove" do array "vals"
 * Retorna:
 *    true se o valor foi removido
 *    false caso o valor não exista no array
 */
bool a_remove0(int vals[], int size, int to_remove);

/**
 * Descrição:
 *    remove o valor "to_remove" do array "vals"
 *     Nesta versão é usada a função search
 * Retorna:
 *    true se o valor foi removido
 *    false caso o valor não exista no array
 */
bool a_remove(int vals[], int size, int to_remove);
   
/**
 * Descrição:
 *    remove o valor "to_remove" do array "vals"
 *    Nesta versão assume-se que a ordem dos valores no array não se pode alterar
 * Retorna:
 *    true se o valor foi removido
 *    false caso o valor não exista no array
 */
bool a_remove_ordered(int vals[], int size, int to_remove);


     
