#include "kompiler.h"

void printCurr();

void grabNextCh() {
    //warning: silently drops current ch
    currCh = getc(fp);
}

void storeCh(int ch) {
    tokBuf[tokBufIndex++] = ch;
}

void stashCh(int ch) {
    stashedCh = ch;
}

void storeStashedCh() {
    tokBuf[tokBufIndex++] = stashedCh;
}

void backToDefault() {
    grabNextCh();
}

void discard() {
    //discards current ch and keep doing it
    int nextState;
    int enteredSt = currState;
    
    //currState = getNextSt(currState, currCh);

    while ( (currCh = getc(fp)) != EOF) {
        //keep looping while we find whitespaces
        nextState = getNextSt(currState, currCh);
        if (nextState == ERRST) {
            printf("discard: error state found!\n");
            return;
        }
        if (nextState != enteredSt) {
            //we're done discarding, call the next function
            transFunc f = getTransFunc(currState, currCh);
            currState = nextState;

            //call the transition function
            f();

            //printf("discard: returning\n");
            return;
        }
    }
    //reaching here means end of file
    retToken = EOF;
    return;
}

int validHex(int ch) {
    //check if valid hex using hex table
    return hexTable[ch];
}

void accuHex() {
    int nextState = HEXST;
    while ( (currCh = getc(fp)) != EOF && currState != ACCEPTST && currState != ERRST && tokBufIndex < MAXTOKBUFLEN) {
        //keep looping until we find an accepting state
        nextState = getNextSt(currState, currCh);
        //printf("accumulate loop, currCh: %c nextSt: %d\n", currCh, nextState);
        if (nextState == ACCEPTST) {
            //done accumulating
            tokBuf[tokBufIndex] = '\0';
            retToken = grabRetToken(currState, currCh);
            return;
        }
        
        if (validHex(currCh)) {
            currState = nextState;
            storeCh(currCh);
        }
        else {
            printf("accuHex: invalid hex found\n");
            tokBuf[tokBufIndex] = '\0';
            retToken = ERRTOKEN;
            return;
        }
    }
    //getting out of loop means not accepting state or EOF
    if (currCh == EOF) {
        //done accumulating, still valid
        tokBuf[tokBufIndex] = '\0';
        retToken = grabRetToken(currState, ' ');
        //printf("accumulate: Found EOF, current buf: %s\n", tokBuf);
    }
    else if (tokBufIndex >= MAXTOKBUFLEN) {//string too long
        printf("accuHex: string was too long\n");
        retToken = ERRTOKEN;
    }
    else if (currState == ERRST) {
        printf("accuHex: error state found!\n");
        retToken = ERRTOKEN;
    }
    else {
        printf("accuHex: invalid state found: %d\n", currState);
        retToken = ERRTOKEN;
    }

}

void accumulate() {
    int nextState;
    int enteredSt = currState;

    if (currState == NUMBERST && currCh == '0') {
        grabNextCh();
        if (currCh == 'x') {
            //special case for hex
            storeCh('0');
            storeCh(currCh);
            currState = HEXST;
            accuHex();
            return;
        }
        else while (currState == NUMBERST && currCh == '0' && currCh != EOF) {
            //gets rid of leading zeroes except for one
            currCh = getc(fp);
        }

        storeCh('0');
    }
    
    storeCh(currCh);

    while ( (currCh = getc(fp)) != EOF && currState != ACCEPTST && currState != ERRST && tokBufIndex < MAXTOKBUFLEN) {
        
        //keep looping until we find an accepting state
        nextState = getNextSt(currState, currCh);
        //printf("accumulate loop, currCh: %c nextSt: %d\n", currCh, nextState);
        if (nextState == ACCEPTST) {
            //done accumulating
            tokBuf[tokBufIndex] = '\0';
            retToken = grabRetToken(currState, currCh);
            //printf("accumulate done: %s\n", tokBuf);
            return;
        }
        if (nextState != enteredSt) {
            //TODO: this isn't very robust
            //printf("accumulate next != entered, currCh: %c currSt: %d\n", currCh, currState);
            transFunc f = getTransFunc(currState, currCh);
            currState = nextState;
            f();
            //printf("2nd accumulate next != entered, currCh: %c currSt: %d\n", currCh, currState);
            f = getTransFunc(currState, currCh);
            prevState = currState;
            nextState = getNextSt(currState, currCh);
            currState = nextState;

            f();
            if (retToken != 0) return;
            if (currState == ACCEPTST && (prevState == STRINGST || prevState == STRESCST)) {
                //only allow Strings to enter here
                tokBuf[tokBufIndex] = '\0';
                retToken = STRTOKEN;
                //printf("accumulate done: %s\n", tokBuf);
                return;
            }
        }
        currState = nextState;
        storeCh(currCh);
    }

    //getting out of loop means not accepting state or EOF
    if (currCh == EOF) {
        //done accumulating, still valid
        tokBuf[tokBufIndex] = '\0';
        retToken = grabRetToken(currState, ' ');
        //printf("accumulate: Found EOF, current buf: %s\n", tokBuf);
    }
    else if (tokBufIndex >= MAXTOKBUFLEN) {//string too long
        printf("accumulate: string was too long\n");
        retToken = ERRTOKEN;
    }
    else if (currState == ERRST) {
        printf("accumulate: error state found!\n");
        retToken = ERRTOKEN;
    }
    else {
        printf("accumulate: invalid state found: %d\n", currState);
        retToken = ERRTOKEN;
    }
}

void returnTok() {
    //TODO: consider using a table for this too - there has to be a better way to do this
    //checks which state the caller was from to figure out which token to send back
    //is only called from the state machine
    //if keeping this, have to account for more other states.
    if (currState == ERRST) {
        retToken = ERRTOKEN;
        return;
    }
    else if (currState == ACCEPTST) {
        retToken = grabRetToken(prevState, currCh);
        return;
    }
    else if (currState == NUMBERST) {
        printf("DO I EVER COME HERE?!@$!$!@$!@#!@\n");
        //consider returning double/floats
        //return number token
        retToken = NUMBERTOK;
        return;
    }
    else if (currState == IDST) {
        //consider returning string? maybe have to consider between single and double quotes
        //return ID token
        printf("DO I EVER COME HERE?!@$!$!@$!@#!@\n");

        retToken = IDTOKEN;
        return;
    }
    else if (currState == FLOATST) {
        printf("DO I EVER COME HERE?!@$!$!@$!@#!@\n");
        retToken = FLOATTOK;
        return;
    }
    else if (currState == TOKST) {
        storeCh(currCh);
        tokBuf[tokBufIndex] = '\0';
        retToken = grabRetToken(currState, currCh);
        grabNextCh(); //get next char for next iteration
        return;
    }
    printf("returnTok: something went wrong, unknown state found...\n");
    retToken = ERRTOKEN;
    return;
}

void slashFunc() {
    int nextState;
    grabNextCh();
    transFunc f = getTransFunc(currState, currCh);
    nextState = getNextSt(currState, currCh);
    if (nextState == TOKST) {
        //if it's just a divide op
        storeCh('/');
        retToken = grabRetToken(currState, currCh);
        if (currCh == '=') {
            storeCh('=');
            grabNextCh();
        }
        storeCh('\0');
        return;
    }
    else {
        //reaching here means it's a comment
        currState = nextState;
        grabNextCh();
        f();
        //returning means comments are done
        //printf("done discarding comment: state: %d, currCh: %c\n", currState, currCh);
        if (retToken == EOF) return;
        f = getTransFunc(currState, currCh);
        currState = getNextSt(currState, currCh);
        f();
    }
}

void strSTFunc() {
    if (currCh != '\"') {
        printf("charSTFunc: This function should only be called by double quote\n");
        retToken = ERRTOKEN;
        return;
    }
    //throw away the first quote
    grabNextCh();

    if (currCh == '\"') {
        //if empty string found
        grabNextCh();
        storeCh('\0');
        retToken = STRTOKEN;
        return;
    }

    transFunc f = getTransFunc(currState, currCh);
    currState = getNextSt(currState, currCh);
    f();

    if (currState == STRESCST) {
        f = getTransFunc(currState, currCh);
        currState = getNextSt(currState, currCh);
        f();

        if (currState != ACCEPTST) {
            f = getTransFunc(currState, currCh);
            currState = getNextSt(currState, currCh);
            f();
        }
        else if (currState == ACCEPTST) {
            retToken = STRTOKEN;
        }
        else {
            printf("strSTFunc: something went wrong\n");
            retToken = ERRTOKEN;
        }
    }
    storeCh('\0');
    //throw away last quote
    grabNextCh();
}

void charSTFunc() {
    if (currCh != '\'') {
        printf("charSTFunc: This function should only be called by single quote\n");
        retToken = ERRTOKEN;
        return;
    }
    //throw away the first quote
    grabNextCh();
    transFunc f = getTransFunc(currState, currCh);
    currState = getNextSt(currState, currCh);

    f();
    if (retToken == EOF) return;

    if (currState == CHARACCST) {
        retToken = CHARTOKEN;
    }
    else if (currState == CHARESCST) {//handle escape case
        transFunc f = getTransFunc(currState, currCh);
        currState = getNextSt(currState, currCh);
        f();
        if (currState == CHARACCST) 
            retToken = CHARTOKEN;
        else
            retToken = ERRTOKEN;
    }
    else 
        retToken = ERRTOKEN;
        
    storeCh('\0');

    //throw away last quote
    grabNextCh();
}

void storeAndGrab() {
    //store current ch, change state and grab next ch
    storeCh(currCh);
    grabNextCh();
    currState = getNextSt(currState, currCh);
}

void escChar() {
    //TODO: fix for escaped chars instead of accepting all chars
    storeCh('\\');
    storeAndGrab();
}

void storeSlashAccu() {
    storeCh('\\');
    accumulate();
}

void tokFunc() {
    //printf("storegrab: currch: %c, currSt: %d\n", currCh, currState);
    int originalCh = currCh;
    storeCh(currCh);
    grabNextCh();
    //printf("grabbing token: currch: %c, currSt: %d\n", currCh, currState);
    retToken = grabRetToken(currState, currCh);
    //printf("rettok: %d\n", retToken);

    //** will give you trouble here if you support pointers
    //TODO: handle %% !! ^^ (think it already is)
    //TODO: handle **
    if (currCh == '=' || currCh == originalCh || (originalCh == '-' && currCh == '>')) {
        storeCh(currCh);
        grabNextCh(); //get next char for next iteration
    }

    tokBuf[tokBufIndex] = '\0';
}

void errFunc() {
    //TODO: should probably dump some info here
    printf("errFunc: Error found\n");
    retToken = ERRTOKEN;
    exit(-1);
}

void printCurr() {
    printf("currCh: %c currSt: %d\n", currCh, currState);
}