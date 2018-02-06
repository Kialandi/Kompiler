#include <stdio.h>

//array of tokens declare here

int getToken() {
    FILE * ptr;
    char ch;
    char [] string;//allocate space

    while (ch = getc(ptr) not end of file or line or space or semicolon) {
        //read in next char and transition states
        currState = stTable[][].nextState;
        stTable[][].func();
        
        if (currState == errState) break;
        
        //otherwise append
        
    }

    if (currState == errState) {
        return errToken;
    }
    //decide what token to return
    
}
