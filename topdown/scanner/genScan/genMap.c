#include <stdio.h>
#include <stdlib.h>

#define ASCIIMAX    127 //DEL

int main (int arg, char ** argv) {
    int j;
    printf("#include \"kompiler.h\"\n\nint mapTable[ASCIIMAX + 1] =\n");


    printf("{ /* Mapping Table */\n");

    for (j = 0; j < ASCIIMAX + 1; j++) {
        if (j != 0)
            printf(",\n");

        if (j < 32 || j > 126)
            printf("\t/* . */ %d", j);
        else
            printf("\t/* %c */ %d", j, j);

    }

    printf("\n};\n");
}
