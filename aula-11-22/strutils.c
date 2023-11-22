#include "strutils.h"
#include <string.h>
#include <ctype.h>



#define NORMAL_MODE 0
#define CAMEL_MODE  1
#define UNIX_MODE   2


static void trim_with_mode(char src[], char dst[], int mode) {
    int iget = 0, iput = 0;
    bool first = true;
    while(src[iget] != 0) {
        while(src[iget] == ' ') iget++;
        if (first) {
            first = false;
        }
        else {
            if (src[iget]!= 0) {
                switch(mode) {
                    case NORMAL_MODE:
                        dst[iput++] = ' '; break;
                    case UNIX_MODE:
                        dst[iput++] = '_'; break;
                        break;
                    default:
                        break;
                }
            }
        }
        // copy next word to put position
        if (src[iget] != 0) {
            switch(mode) {
                case CAMEL_MODE:
                    dst[iput++] = toupper(src[iget++]); break;
                case UNIX_MODE:
                    dst[iput++] = toupper(src[iget++]); break;
                default:
                    break;
            }
        }
        while(src[iget] != ' ' && src[iget] != 0) {
            char c = (mode == NORMAL_MODE) ? src[iget] : tolower(src[iget]);
            iget++;
            dst[iput++] =  c;
        }
       
    }
    dst[iput] = 0;
}


    
/**
 * Descrição:
 * 	remove os espaços iniciais e finais e mais do que 
 * 	um espaço entre as palavras de um nome
 * Parâmetros:
 * 	"name": texto a converter
 * Retorno:
 * 	Não tem
 */
void str_trim0(char name[]) {
    int iget = 0, iput = 0;
    bool first = true;
    
    while(name[iget] != 0) {
        while(name[iget] == ' ') iget++;
        if (first) {
            first = false;
        }
        else {
            if (name[iget] != 0) name[iput++] = ' ';
        }
        // copy next word to put position
        while(name[iget] != ' ' && name[iget] != 0) {
            name[iput++] = name[iget++];
        }
       
    }
    name[iput] = 0;
    
}

void str_trim(char src[], char dst[]) {
    trim_with_mode(src, dst, NORMAL_MODE);
}



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
void snake_2_camel_case(char src[], char dst[]) {
    int iget = 0, iput = 0;
    
    while(src[iget] == '_') dst[iput++] = src[iget++];
    while (src[iget] != 0) {
        dst[iput++] = toupper(src[iget++]);
        while(src[iget] != 0 && src[iget] != '_') dst[iput++] = src[iget++];
        int i_start = iget;
        while(src[iget] == '_') iget++;  
        if (src[iget] == 0) {
            for(int i= i_start; i < iget; ++i) dst[iput++] = '_';
        }
    }
    dst[iput] = 0;
}

 
/**
 * Descrição:
 *	  Gera o formato alternativo para o nome recebido por parâmetro em que apenas 
 * 	  o primeiro nome e o ultimo apelido são apresentados por extenso, estando os nomes 
 * 	  intermédios apresentado na forma de abreviatura.
 * 	  Espaços iniciais e finais e espaços intermédios a mais devem ser eliminados.
 *    Nomes intermédios com 1 ou 2 caracteres são omitidos
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
bool name_middle_compressed0(char orig[], char result[]) {
    // first, remove unnecessary spaces 
    str_trim(orig, result);
    
    int wc = 0;
    int iget=1, iput=1;
    
    // first name
    if (result[0] == 0) return false;
    result[0] = toupper(result[0]);
    while(result[iget] != ' ' && result[iget] != 0) {
       result[iput++] = result[iget++];
    }
    wc = 1;
     
    // other names
    while(result[iget] != 0) {
        result[iput++] = result[iget++]; // put the space
        int size = 1;
        result[iput++] = toupper(result[iget++]);
       
        while(result[iget] != ' ' && result[iget] != 0) { 
            result[iput++] = result[iget++];
            size++; 
        }
        if (result[iget] != 0) { 
            if (size <= 2) iput -= size+1;
            else {
                iput -= size - 1;
                result[iput++] = '.';
                wc++;
            }
        }
        else { wc++; } // last word
    }
    result[iput] = 0;
    return wc >= 2;
    
}

bool name_middle_compressed(char orig[], char result[]) {
    // first, remove unnecessary spaces 
    str_trim(orig, result);
    int last = strlen(result);
    
    
    // get last word position()
    while(last > 0 && result[last] != ' ') last--;
    
    if (last == 0) return false; // just one word
    
   
    int iget=1, iput=1;
    
    // first name
    result[0] = toupper(result[0]);
    while(iget <= last && result[iget] != ' ') {
       result[iput++] = result[iget++];
    }
    result[iput++] = result[iget++]; // put the space
    
    // intermediate names
    while(iget <= last) {
        bool new_word = false;
        if (result[iget+1] != ' ' && result[iget+2] != ' ') {
            result[iput++] = toupper(result[iget++]);
            new_word = true;
        }
        while(result[iget] != ' ') iget++;
        iget++;
        if (new_word) {
            result[iput++] = '.';
            result[iput++] = ' ';
        }
    }
    
    // last name
    
    result[iput++] = toupper(result[iget++]);
    while (result[iget] != 0) result[iput++] = result[iget++];
    
    result[iput] = 0;
    return true;
    
}


#define HISTO_SIZE ('Z'-'A'+1)

typedef int Histogram[HISTO_SIZE];

static bool histo(char str[], Histogram histo) {
    char c;
    int i = 0;
    while((c= str[i++]) != 0) {
        if (isalpha(c)) {
            histo[toupper(c) - 'A']++;
        }
        else if (!isspace(c)) return false;
    }
    return true;
}
    
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
bool anagram(char str1[], char str2[]) {
    Histogram h1 = {0}, h2 = {0};
    
    
    if (!histo(str1, h1)) return false;
    if (!histo(str2, h2)) return false;
    
    int c1 = 0, c2=0;
    for(int i= 0; i < HISTO_SIZE; ++i) {
        c1 += h1[i];
        c2 += h2[i];
        if (h1[i] != h2[i]) return false;
    }
    return c1 > 1 && c2 > 1;
    return true;
}



static void copy_word(char src[], int start, int end, char dst[]) {
    int i, j;
    for(i= start, j=0; i < end; ++i, ++j) dst[j] = tolower(src[i]);
    dst[j] = 0;
}


/**
 * Descrição:
 *    Esta função coloca no array "words" as palavras (word_t) existentes no array "text" 
 * 	  até ao máximo de size palavras
 * Retorno:
 *    A função retorna o total de palavras colocadas no array "words"
 */
int str_split(char text[], word_t words[], int size) {
    int i = 0;  // posição do texto
    int nw = 0; // total de palavras recolhidas
    
    while(text[i] != '\0' && nw < size) {
        while(text[i] != 0 && !isalpha(text[i])) ++i;
        // next word to words
        if (text[i] != 0) {
            int i_start = i;  ++i;
         
            while(isalpha(text[i])) ++i;
            copy_word(text, i_start, i, words[nw]);
            nw++;
        }
      
    }
    return nw;
}


