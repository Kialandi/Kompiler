#include "kompiler.h"

char * tokens[MAXTOKENS];

void printToken(int token) {
    printf("Token: %s\n", tokens[token]);
}
