
#include <stdbool.h>

/**
 * Descrição:
 * 	remove os espaços iniciais e finais e mais do que 
 * 	um espaço entre as palavras de um nome
 * Parâmetros:
 * 	"name": texto a converter
 * Retorno:
 * 	Não tem
 */
void str_trim(char src[], char dst[]);


/**
 * Descrição:
 *    a função  "camel_case" altera a string para o formato Camel Case (ver https://en.wikipedia.org/wiki/Camel_case). 
 *    Neste formato as frases são escritas sem espaços ou pontuações com as palavras iniciando-se com a primeira letra 
 *    maiúscula. 
 * Retorno:
 * 	  Não tem.
 * Ex:
 *    A frase “Disciplina de programacao 1” será escrita no formato Camel Case como “DisciplinaDeProgramacao1”.
 */
void snake_2_camel_case (char src[], char dst[]);

 
/**
 * Descrição:
 *	  Gera o formato alternativo para o nome recebido por parâmetro em que apenas 
 * 	  o primeiro nome e o ultimo apelido são apresentados por extenso, estando os nomes 
 * 	  intermédios apresentado na forma de abreviatura.
 * 	  Espaços iniciais e finais e espaços intermédios a mais devem ser eliminados
 * 	 
 * Parâmetros:
 * 	"orig": nome a converter
 * 	"result": o nome no formato requerido
 * Retorno:
 * 	"true" se o nome for passível de conversão (tem de ter pelo menos um nome próprio e um 
 *   apelido)  "false" caso contrário.
 * Ex: se o nome original for:  "  pedro manuel  vieira   rodrigues  "
 * 	  o nome resultante da conversão é:  "Pedro M. V. Rodrigues".
 */
bool name_middle_compressed(char orig[], char result[]);


/**
 * Descrição:
 *		A função "anagram" verifica se as duas strings recebidas em parâmetro são anagramas, 
 * 		ou seja, se têm, exatamente, as mesmas letras (ignorando os espaços), 
 * 		embora os carateres possam estar dispostos  em diferentes posições.
 * 		Na verificação não distinga entre letras maiúsculas e minúsculas. 
 * Parâmetros:
 *		"str1": primeira string a avaliar
 *	    "str2": segunda string a avaliar
 * Retorno:
 *	"true" se as string "str1" e "str2" só contiverem letras (pelo menos duas) e espaços, e forem anagramas, 
 *  "false" caso contrário. 
 * Ex: “setimo ANDAR” e “desmontaria” são anagramas.
 *     "ator" e "rota1" não são anagramas
 */
bool anagram(char str1[], char str2[]);


#define MAX_WORD_SIZE 32

typedef char word_t[MAX_WORD_SIZE+1];

/**
 * Descrição:
 *    Esta função coloca no array "words" as palavras (word_t) existentes no array "text" 
 * 	  até ao máximo de size palavras
 * Retorno:
 *    A função retorna o total de palavras colocadas no array "words"
 */
int str_split(char text[], word_t words[], int size);


