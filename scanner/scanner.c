#include "kompiler.h"

int tokBufIndex;
int currState;
char tokBuf[MAXTOKBUFLEN + 1];

//array of tokens declare here

int getToken() {
    FILE * ptr;
    int ch;
    tokBufIndex = 0;
    currState = 0;
    
    
    
    while (ch = getc(ptr) not end of file or line or space or semicolon) {
        //read in next char and transition states
        currState = stMachine[currState][ch].nextState;
        //stTable[][].func();
        
        if (currState == errState) break;
        
        //otherwise append
        tokBuf[tokIndex++] = ch;
    }
    
    tokBuf[tokIndex] = '\0';

    //decide what token to return
    //states return specific tokens


    if(currState == ERRSTATE) {
        return ERRTOKEN;
    }
    else if (currState == s2) {
        //return number token and set value
    }
    else if (s3) {
        //return OP token and set value to the operation
        
    }
    printf("Something went wrong, unknown state found...\n");
    return ERRTOKEN;
}
