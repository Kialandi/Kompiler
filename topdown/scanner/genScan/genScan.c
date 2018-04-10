#include <stdio.h>
#include <stdlib.h>

#define MAXSTATES   25
#define ASCIIMAX    127 //DEL

int main (int arg, char ** argv) {
    int i, j;
    printf("#include \"kompiler.h\"\n\nstruct state stMachine[MAXSTATES][TOTALMAPS] = {\n");

    for (i = 0; i < MAXSTATES; i++) {        
        if (i != 0) 
            printf(",");

        printf("{ /* State row %d */\n", i);
        printf("\t/* JUNK */ {ERRST, &errFunc, 0},\n");
        printf("\t/* WHITESPACE */ {0, &errFunc, 0},\n");
        printf("\t/* NUMBERS */ {NUMBERST, &accumulate, 0},\n");
        printf("\t/* CHARS */ {IDST, &accumulate, 0},\n");
        
        for (j = 0; j < ASCIIMAX + 1; j++) {
            if ((j > ' ' && j < '0') || (j > '9' && j < 'A') || (j > 'Z' && j < 'a') || (j > 'z' && j < 126))
                printf("\t/* %c */ {ERRST, &errFunc, 0},\n", j);
            else if (j == 126)
                printf("\t/* %c */ {ERRST, &errFunc, 0}\n", j);
        
        }
        printf("}\n\n");
    }

    printf("};\n");
}
