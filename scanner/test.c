#include "kompiler.h"

char * tokens[MAXTOKENS];

int main(int argc, char ** argv) {
    if (argc != 2) {
        printf("Usage: ./test <filename>\n");
        return 0;
    }
    
    if (scinit(argv[1]) == 0) {
        return 0;
    }

    token tok;
    tok = getToken();
    printf("Token: %d, Value: %s\n", tok, tokBuf);
    //TODO: fix this to get more than just one
    /*
    while ( (tok = getToken(fp)) != EOF) {
        printf("Token: %d, Value: %s\n", tok, tokBuf);
    }*/
    if (strcmp(tokBuf, "") != 0)
        printf("Last value: %s\n", tokBuf);

    return 1;
}
