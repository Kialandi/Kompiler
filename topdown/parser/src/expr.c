#include "../../kompiler.h"

var * expr() {
    int currOP;
    var * var1;
    var * var2;

    var1 = doBool();
    while (currTok == ANDAND || currTok == OROR) {
        printf("in expr loop\n");
        if (var1->type != NUMBERTOK) {
            //error check for bools
            printf("expr: Non-boolean found\n");
            return NULL;
        }

        //save the current operation
        currOP = currTok;
        getTok();
        var2 = doBool();//get second variable

        if (var2->type != NUMBERTOK) {
            //error check for bools
            printf("expr: Non-boolean found\n");
            return NULL;
        }

        if (currOP == ANDAND) {
            //AND
            if (var1->value.intVal != 0 
                && var2->value.intVal != 0) {
                var1->value.intVal = 1;
            }
            else {
                var1->value.intVal = 0;
            }
        }
        else if (currOP == OROR) {
            //OR
            if (var1->value.intVal != 0 
                || var2->value.intVal != 0) {
                var1->value.intVal = 1;
            }
            else {
                var1->value.intVal = 0;
            }
        }
        else {
            //fatal error
            printf("expr: invalid operator\n");
            return NULL;
        }
        free(var2);
    }
    return var1;
}