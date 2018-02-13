#ifndef SCANNER_H
#define SCANNER_H

#define OK              1
#define ERR             0
#define MAXTOKBUFLEN    100
#define MAXTOKENS       25

#define MAXSTATES       10
#define ASCIIMAX        127 //DEL
#define MAXCHARS        ASCIIMAX - ASCIIMIN + 1

/* Tokens */
#define ERRTOKEN        -1

struct state {
    int nextState;
    void * func;
    int token;
};

extern struct state stMachine[MAXSTATES][ASCIIMAX + 1];
extern int currState;
extern int tokBufIndex;
extern char tokBuf[MAXTOKBUFLEN + 1];//+1 to enable last \0

#endif
