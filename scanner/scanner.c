#include <stdio.h>

//array of tokens declare here

int getToken() {
    FILE * ptr;
    char ch;
    tokenIndex = 0;

    while (ch = getc(ptr) != EOF && (whitespace)) {
        //get rid of whitespace
    }       

    while (ch = getc(ptr) not end of file or line or space or semicolon) {
        //read in next char and transition states
        currState = stTable[currState][ch].nextState;
        //stTable[][].func();
        
        if (currState == errState) break;
        
        //otherwise append
        tokBuf[tokIndex++] = ch;
    }
    

    if (currState == errState) {
        return errToken;
    }
    //decide what token to return
    //check state, if s1 - ID, s2 - numbers, s3 - operations

    tokBuf[tokIndex] = '\0';

    if(s1) {
        //check type of ID
    }
    else if (s2) {
        //return number token and set value
    }
    else if (s3) {
        //return OP token and set value to the operation
        
    }
    else {
        return errToken;
    }
}
