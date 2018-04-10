#include "../../kompiler.h"

var * rel() { //handle + and -
    int currOP;
    var * var1;
    var * var2;

    var1 = fact();
    while (currTok == PLUSTOK || currTok == MINUSTOK) {
        //printf("in rel loop\n");
        if (var1->type != NUMBERTOK && var1->type != FLOATTOK) {
            if (var1->type == STRTOKEN) {
                //TODO: strcat
                printf("String append not supported yet\n");
            }
            //error check for numbers
            printf("rel: add and minus needs numbers\n");
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
            printf("adding\n");
            if (var1->type == NUMBERTOK) { //int
                printf("var1 is int\n");
                if (var2->type == NUMBERTOK) {
                    printf("var 2 is int\n");
                    var1->value.intVal += var2->value.intVal;
                }
                else {
                    printf("var2 is float, upcasting\n");
                    var1->value.floatVal = (float) var1->value.intVal + var2->value.floatVal;
                    var1->type = FLOATTOK;
                }
            }
            else {
                printf("var1 is float\n");
                if (var2->type == NUMBERTOK)
                    var1->value.floatVal += (float) var2->value.intVal;
                else
                    var1->value.floatVal += var2->value.floatVal;
            }
            //printf("var1: %d, var2: %d\n", var1->value.intVal, var2->value.intVal);
            //printf("var1: %f, var2: %f\n", var1->value.floatVal, var2->value.floatVal);
        }
        else if (currOP == MINUSTOK){
            //subtract
            printf("subtracting\n");
            if (var1->type == NUMBERTOK) { //int
                if (var2->type == NUMBERTOK)
                    var1->value.intVal -= var2->value.intVal;
                else {
                    printf("var2 is float, upcasting\n");
                    var1->value.floatVal = (float) var1->value.intVal - var2->value.floatVal;
                    var1->type = FLOATTOK;
                }
            }
            else {
                if (var2->type == NUMBERTOK)
                    var1->value.floatVal -= var2->value.intVal;
                else
                    var1->value.floatVal -= var2->value.floatVal;
            }
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