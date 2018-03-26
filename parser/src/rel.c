#include "../../kompiler.h"

var * rel() { //handle + and -
    int currOP;
    var * var1;
    var * var2;

    var1 = fact();
    while (currTok == PLUSTOK || currTok == MINUSTOK) {
        printf("in rel loop\n");
        if (var1->type != NUMBERTOK && var1->type != FLOATTOK) {
            //error check for numbers
            printf("rel: add and minus needs numbers");
            return NULL;
        }

        //save the current operation
        currOP = currTok;
        getTok();
        var2 = fact();//get second variable

        //see if they are compatible
        if (!match(currOP, var1, var2)) {
            printf("rel: vars don't match\n");
            return NULL;
        }

        if (currOP == PLUSTOK) {
            //add
            if (var1->type == NUMBERTOK)
                var1->value.intVal += var2->value.intVal;
            else 
                var1->value.floatVal += var2->value.floatVal;
        }
        else if (currOP == MINUSTOK){
            //subtract
            if (var1->type == NUMBERTOK)
                var1->value.intVal -= var2->value.intVal;
            else 
                var1->value.floatVal -= var2->value.floatVal;
        }
        else {
            //fatal error
            printf("rel: Invalid operator found\n");
            return NULL;
        }
        free(var2);
    }
    return var1;
}