#include "kompiler.h"

int scinit(const char * path) {
    printf("Initializing Scanner...\n");
    currState = 0;
    currCh = -1;
    fp = fopen(path, "r");
    if (fp == NULL) {
        perror("File open failed.\n");
        return 0;
    }

    return 1;
}