#include "stack.h"

int main (int argc, char ** argv) {
    int i = 0;
    stackInit();
    for (i = 0; i < 5; i++) {
        push(i);
    }
    printStack();

    for (i = 0; i < 5; i++) {
        printf("val: %d\n", pop());
    }
    printStack();
    stackDestr();

    return 0;
}