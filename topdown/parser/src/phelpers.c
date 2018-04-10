#include "../../kompiler.h"

void getTok() {
    currTok = getToken();
    //printf("getTok: %d: val: %s\n", currTok, tokBuf);
}

int match(int op, var * var1, var * var2) {
    //given an operator, is var1 and var2 valid together?
    //handle int to float upcasting
    return 1;
}
