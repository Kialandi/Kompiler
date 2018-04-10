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
            printf("fact: mult and div needs numbers\n");
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
            if (var1->type == NUMBERTOK) { 
                if (var2->type == NUMBERTOK) {//int * int
                    var1->value.intVal *= var2->value.intVal;
                }
                else { //int * float
                    var1->value.floatVal = var1->value.intVal * var2->value.floatVal;
                    var1->type = FLOATTOK;
                }
            }
            else {
                if (var2->type == NUMBERTOK) {//float * int
                    var1->value.floatVal *= var2->value.intVal;
                }
                else { //float * float
                    var1->value.floatVal *= var2->value.floatVal;
                }
            }
        }
        else if (currOP == DIVTOK) {
            //divide
            //TODO: Handle float / int and int / float
            //TODO: special case for upcasting
            if (var1->type == NUMBERTOK) {
                if (var2->type == NUMBERTOK) {//int / int
                    float fl = (float) var1->value.intVal / var2->value.intVal;
                    int in = var1->value.intVal / var2->value.intVal;
                    if (fl == (float) in) {
                        //means still integer
                        var1->value.intVal = in;
                    }
                    else {
                        //casted to float
                        var1->value.floatVal = fl;
                        var1->type = FLOATTOK;
                    }
                }
                else { //int / float
                    var1->value.floatVal = var1->value.intVal / var2->value.floatVal;
                    var1->type = FLOATTOK;
                }
            }
            else {
                if (var2->type == NUMBERTOK) {//float / int
                    var1->value.floatVal /= var2->value.intVal;
                }
                else { //float / float
                    var1->value.floatVal /= var2->value.floatVal;
                }
            }
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