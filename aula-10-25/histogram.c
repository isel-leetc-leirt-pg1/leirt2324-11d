/**
 * this program produces and shows an
 * histogram of the letters read from input
 */

#include <stdio.h>
#include <ctype.h>

#define NLETTERS ('Z' - 'A' + 1)

typedef int histo_t[NLETTERS];

// is assumed that the histogram "h" is initilized with zeros
void histo_build( histo_t h) {
    int c;
    while ( (c = getchar()) != EOF) {
        if (isalpha(c)) {
            c = toupper(c);
            h[c - 'A']++; // increment occurrences for letter c
        }
    }
    
}

#define MAX_GRAPH_LINE  70

// return the letter position with more ocurrences
int biggest_letter(histo_t h) {
    int big_p = 0;
    for (int l = 1; l < NLETTERS; ++l) {
        if (h[l] > h[big_p]) 
            big_p = l;
    }
    return big_p;
}


// a simple version of histo_show
void histo_show_0(histo_t h) {
    for(int l = 0; l < NLETTERS; l++) {
        printf("'%c': %5d\n", 'A' + l, h[l]);
      
    }
}

// a "graphical bar" version of histo_show
void histo_show(histo_t h) {
    int big_p = biggest_letter(h), max_occurs = h[big_p];
    for(int l = 0; l < NLETTERS; l++) {
        printf("'%c': ", 'A' + l);
        int nstars = (h[l] * MAX_GRAPH_LINE) / max_occurs;
        if (h[l] > 0 && nstars == 0) nstars++;
        for(int i = 0; i < nstars; ++i) putchar('*');
        printf("(%d)\n", h[l]);
    }
}


int main() {
    histo_t histo = {0};
    
    histo_build(histo);
    
    histo_show(histo);
    
    return 0;
    
}
