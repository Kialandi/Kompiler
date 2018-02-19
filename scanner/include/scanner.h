#ifndef SCANNER_H
#define SCANNER_H

#define OK              1
#define ERR             0
#define MAXTOKBUFLEN    100
#define MAXTOKENS       25

#define MAXSTATES       10
#define ASCIIMAX        127 //DEL
#define MAXCHARS        ASCIIMAX - ASCIIMIN + 1

/* States */
#define DISCARDST       0
#define NUMBERST        1
#define IDST            2
#define ERRST           -1
#define ACCEPTST        30

/* Tokens */
#define ERRTOKEN        0
#define NUMBERTOK       1
#define ALPHATOK        2

/* Typedefs */
typedef int token;
typedef void (*transFunc)();

struct state {
    int nextState;
    transFunc func;
    token tok;
};

extern struct state stMachine[MAXSTATES][ASCIIMAX + 1];
extern int currState;
extern int tokBufIndex;
extern int currCh;
extern char tokBuf[MAXTOKBUFLEN + 1];//+1 to enable last \0
extern FILE * fp;

#endif
