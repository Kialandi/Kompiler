#include "kompiler.h"

int prevState;
int currState;
int nextState;
int retToken;
int tokBufIndex;
int stashedCh;
int currCh;
char tokBuf[MAXTOKBUFLEN + 1];
FILE * fp;

//array of tokens declare here

token getToken() {
    //empty out buffer and return to default state
    tokBufIndex = 0;
    memset(tokBuf, '\0', MAXTOKBUFLEN + 1);
    currState = 0;
    prevState = 0;
    nextState = 0;
    stashedCh = -1;
    retToken = 0;

    if (currCh == -1) {
        //get first character
        currCh = getc(fp);
    }
    transFunc f = getTransFunc(currState, currCh);
    if (f == NULL) {
        return EOF;
    }
    currState = getNextSt(currState, currCh);

    //call the transition function
    f();

    //decide what token to return
    //states return specific tokens

    //printf("getToken: returning token, currState: %d\n", currState);
    return retToken;
}
