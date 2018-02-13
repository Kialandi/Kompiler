#include "kompiler.h"



void discard(FILE * fp) {
    int ch;
    
    while( (ch = getc(fp) != EOF) && currState != ERRSTATE && currState == WHITESPACE) {
        currState = stMachine[currState][ch].nextState;
    }

}

void accumulate(FILE * fp) {
    int ch;
    
    while( (ch = getc(fp) != EOF) && currState != ERRSTATE && tokBufIndex < MAXTOKBUFLEN) {
        tokBuf[tokBufIndex++] = ch;
        currState = stMachine[currState][ch].nextState;
        if (currState == ACCEPT)
            return;
    }

    if (tokBufIndex == MAXTOKBUFLEN) {//string too long
        printf("accumulate: string was too long\n");
        currState = ERRSTATE;//TODO: consider setting a special state for this
    }
}

/* Two possible states returning to parser */
void returnTok() {
    //can only be called by an accepting state

}


void errFunc() {
    printf("Error found\n");
    currState = ERRSTATE;
    return;
}
