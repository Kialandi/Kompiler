#include "kompiler.h"

char * tokens[MAXTOKENS];

int main(int argc, char ** argv) {
    if (argc != 2) {
        printf("Usage: ./test <filename>");
        return 0;
    }

    const char * path = argv[1];
    printf("path: %s\n", path);

    FILE * fp = fopen(path, "r");
    if (fp == NULL) {
        perror("file open failed.\n");
        return 0;
    }
    
    token tok;
    
    while ( (tok = getToken(fp)) != EOF) {
        printf("Token: %d, Value: %s\n", tok, tokBuf);
    }
    if (strcmp(tokBuf, "") != 0)
        printf("Last value: %s\n", tokBuf);

    return 1;
}
