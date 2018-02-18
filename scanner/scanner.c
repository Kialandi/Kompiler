#include "kompiler.h"

int currState;
int tokBufIndex;
int currCh;
char tokBuf[MAXTOKBUFLEN + 1];

//array of tokens declare here

token getToken(FILE * ptr) {
    //empty out buffer and return to default state
    tokBufIndex = 0;
    tokBuf[tokBufIndex] = '\0';
    currState = 0;
    
    if (currCh == -1)
        currCh = getc(ptr);
    
    currState = getNextSt(currState, currCh);

    //call the transition function
    transFunc f = getTransFunc(currState, currCh);
    f();

    //decide what token to return
    //states return specific tokens

    printf("getToken: returning token, currState: %d\n", currState);
    return returnTok(currState);
}
