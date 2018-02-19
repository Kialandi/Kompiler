#include "kompiler.h"

int getNextSt(int state, int ch) {
    //printf("getting next st with st: %d, ch:%d\n", state, ch);
	return stMachine[state][mapTable[ch]].nextState;
}

transFunc getTransFunc(int state, int ch) {
    //printf("getting next func with st: %d, ch:%d\n", state, ch);
	return stMachine[state][mapTable[ch]].func;
}