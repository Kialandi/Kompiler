#include "../../kompiler.h"

var * fact() { //handle * and /
    int currOP;
    var * var1;
    var * var2;

    var1 = term();//get the first variable
    while (currTok == STARTOK || currTok == DIVTOK) {
        printf("in fact loop\n");
        if (var1->type != NUMBERTOK && var1->type != FLOATTOK) {
            //error check for numbers
            printf("fact: mult and div needs numbers");
            return NULL;
        }
        //save the current operation
        currOP = currTok;
        getTok();
        var2 = term();//get second variable

        //see if they are compatible
        if (!match(currOP, var1, var2)) {
            printf("fact: vars don't match\n");
            return NULL;
        }
        
        //compatible, so figure out what to do with the variables
        if (currOP == STARTOK) {
            //multiply
            //TODO: Handle float * int and int * float
            if (var1->type == NUMBERTOK)
                var1->value.intVal *= var2->value.intVal;
            else 
                var1->value.floatVal *= var2->value.floatVal;
        }
        else if (currOP == DIVTOK) {
            //divide
            //TODO: Handle float / int and int / float
            //TODO: special case for upcasting or downcasting
            if (var1->type == NUMBERTOK)
                var1->value.intVal /= var2->value.intVal;
            else 
                var1->value.floatVal /= var2->value.floatVal;
        }
        else {
            //fatal error
            printf("fact: Invalid operator found\n");
            return NULL;
        }
        free(var2);
    }
    return var1;
}