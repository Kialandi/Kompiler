#define errToken        -1
#define MAXTOKBUFLEN    50

#define MAXSTATES   10
#define ASCIIMIN    33  //!
#define ASCIIMAX    126 //~
#define MAXCHARS    ASCIIMAX - ASCIIMIN

typedef int state;

typedef struct state {
    int nextState;
    void * func;
}state;

extern state stMachine[][];
extern int currState;
extern char tokBuf[];
extern void printToken(int);
