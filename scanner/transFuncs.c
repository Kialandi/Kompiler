#include "kompiler.h"

void discard(FILE * fp) {
    
    while (currCh = getc(fp) != EOF) {
        //keep looping while we find whitespaces
        currState = getNextSt(currState, currCh);
        if (currState == ERRST) {
            printf("discard: error state found!\n");
            return;
        }
        if (currState != DISCARDST) {
            //we're done discarding, call the next function
            transFunc f = getTransFunc(currState, currCh);
            f();
            printf("discard: returning\n");
            return;
        }
    }
    //reaching here means end of file
    printf("discard: EOF found\n");
    return;
}

void accumulate(FILE * fp) {
    //store the current character
    tokBuf[tokBufIndex++] = currCh;

    while( (currCh = getc(fp) != EOF) && currState != ERRST && tokBufIndex < MAXTOKBUFLEN) {
        //keep looping until we find an accepting state
        tokBuf[tokBufIndex++] = currCh;
        currState = getNextSt(currState, currCh);
        if (currState == ACCEPTST) {
            //done accumulating
            tokBuf[tokBufIndex] = '\0';
            printf("accumulate done: %s\n", tokBuf);
            return;
        }
    }

    if (tokBufIndex >= MAXTOKBUFLEN) {//string too long
        printf("accumulate: string was too long\n");
    }
    else {
        printf("accumulate: error state found!\n");
    }
    return;
}

token returnTok(int state) {
    if(currState == ERRST) {
        return ERRTOKEN;
    }
    else if (currState == NUMBERST) {
        //return number token and set value
        return NUMBERTOK;
    }
    else if (currState == ALPHAST) {
        //return OP token and set value to the operation
        return ALPHATOK;
    }
    printf("returnTok: something went wrong, unknown state found...\n");
    return ERRTOKEN;
}


void errFunc() {
    printf("errFunc: Error found\n");
    return;
}
