#include <stdio.h>
#include <stdlib.h>

#define MAXSTATES   10
#define ASCIIMAX    127 //DEL

int main (int arg, char ** argv) {
    int i, j;
    printf("#include \"kompiler.h\"\n\nstruct state stMachine[MAXSTATES][ASCIIMAX] = {\n");

    for (i = 0; i < MAXSTATES; i++) {        
        if (i != 0) 
            printf(",");

        printf("{ /* State row %d */\n", i);
        
        for (j = 0; j < ASCIIMAX + 1; j++) {
            if (j != 0)
                printf(",\n");
            
            if (j < 32 || j > 126)
                printf("\t/* . */ {%d, &errFunc, 0}", 0);
            else
                printf("\t/* %c */ {%d, &errFunc, 0}", j, 0);
        
        }
        printf("}\n\n");
    }

    printf("};\n");
}
