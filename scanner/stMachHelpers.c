#include "kompiler.h"

int getNextSt(int state, int ch) {
    if (ch == EOF) {
        //many dependencies on this, have to test if changed
        printf("getNextSt: Found EOF\n");
        exit(1);
    }
	return stMachine[state][mapTable[ch]].nextState;
}

transFunc getTransFunc(int state, int ch) {
    if (ch == EOF) {
        //printf("getTransFunc: Found EOF\n");
        return NULL;
    }
	return stMachine[state][mapTable[ch]].func;
}

int grabRetToken(int state, int ch) {
    if (ch == EOF) {
        printf("grabRetToken: Found EOF\n");
        return -1;
    }
    if (state == TOKST)
        return stMachine[DEFAULTST][mapTable[ch]].tok;

    return stMachine[state][mapTable[ch]].tok;
}