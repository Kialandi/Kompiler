#include "kompiler.h"

int scinit() {
    printf("Initializing Scanner...\n");
    currState = 0;
    currCh = -1;

    return OK;
}
