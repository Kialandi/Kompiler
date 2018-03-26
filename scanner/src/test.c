#include "../../kompiler.h"

int main(int argc, char ** argv) {
    if (argc != 2) {
        printf("Usage: ./%s <filename>\n", argv[0]);
        return 0;
    }
    
    if (scinit(argv[1]) == 0) {
        return 0;
    }

    token tok;
    
    while ( (tok = getToken(fp)) != EOF) {
        printf("Token: %d, Value: %s\n", tok, tokBuf);
    }
    if (tok == EOF)
        printf("EOF Token: %d\n", tok);

    if (strcmp(tokBuf, "") != 0)
        printf("Last value: %s\n", tokBuf);

    return 1;
}
