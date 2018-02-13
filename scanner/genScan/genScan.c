#include <stdio.h>
#include <stdlib.h>

#define MAXSTATES   10
#define ASCIIMIN    33  //!
#define ASCIIMAX    126 //~

int main (int arg, char ** argv) {
    int i, j;

    printf("{\n");

    for (i = 0; i < MAXSTATES; i++) {        
        if (i != 0) 
            printf(",");

        printf("{ /* State row %d */\n", i);
        
        for (j = 0; j < ASCIIMAX - ASCIIMIN; j++) {
            if (j != 0)
                printf(",\n");
            printf("/* %c */\t{%d, &errState, 0}", ASCIIMIN + j, 0);
        }
        printf("}\n\n");
    }

    printf("}\n");
}
