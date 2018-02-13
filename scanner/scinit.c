
int currState;
char [] tokBuf;
state stMachine[][];

int scinit() {
    currState = 0;
    tokBuf = (char *) malloc(MAXTOKBUFLEN);
    
    stTable = malloc(MAXTABROW * sizeof(  ));

    for (i = 0; i < MAXTABCOL; i++) {
        stTable[i] = malloc(MAXTABCOL * sizeof(  ));
    }
}
