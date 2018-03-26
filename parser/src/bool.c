#include "../../kompiler.h"

var * doBool() { //handle comparators
    int currOP;
    var * var1;
    var * var2;

    var1 = rel();
    //clean this up later
    if (currTok == NOTEQ || currTok == LTTOK 
        || currTok == LTEQ || currTok == GTTOK
        || currTok == GTEQ || currTok == COMPARE) {
            printf("in dobool loop\n");
        //don't need to check types, all allowed

        //save the current operation
        currOP = currTok;
        getTok();
        var2 = rel();//get second variable

        //see if they are compatible
        if (!match(currOP, var1, var2)) {
            printf("bool: vars don't match\n");
            return NULL;
        }

        //TODO: fill in code for all cases
        switch (currOP) {
            //can simplify constants, but for ID you have to generate code
            case LTTOK:
                switch (var1->type) {
                    case NUMBERTOK:
                        var1->value.intVal = var1->value.intVal < var2->value.intVal;
                        break;
                    case FLOATTOK:
                        var1->value.intVal = var1->value.floatVal < var2->value.floatVal;
                        break;
                    case CHARTOKEN:
                        var1->value.intVal = var1->value.charVal < var2->value.charVal;
                        break;
                    case STRTOKEN:
                        //TODO: probably implement a comparator
                        var1->value.intVal = var1->value.string < var2->value.string;
                        break;
                }
            break;
            
            case LTEQ:
                switch (var1->type) {
                    case NUMBERTOK:
                        var1->value.intVal = var1->value.intVal <= var2->value.intVal;
                        break;
                    case FLOATTOK:
                        var1->value.intVal = var1->value.floatVal <= var2->value.floatVal;
                        break;
                    case CHARTOKEN:
                        var1->value.intVal = var1->value.charVal <= var2->value.charVal;
                        break;
                    case STRTOKEN:
                        //TODO: probably implement a comparator
                        var1->value.intVal = var1->value.string <= var2->value.string;
                        break;
                }
            break;
            
            case GTTOK:
                switch (var1->type) {
                    case NUMBERTOK:
                        var1->value.intVal = var1->value.intVal > var2->value.intVal;
                        break;
                    case FLOATTOK:
                        var1->value.intVal = var1->value.floatVal > var2->value.floatVal;
                        break;
                    case CHARTOKEN:
                        var1->value.intVal = var1->value.charVal > var2->value.charVal;
                        break;
                    case STRTOKEN:
                        //TODO: probably implement a comparator
                        var1->value.intVal = var1->value.string > var2->value.string;
                        break;
                }
            break;
            
            case GTEQ:
                switch (var1->type) {
                    case NUMBERTOK:
                        var1->value.intVal = var1->value.intVal >= var2->value.intVal;
                        break;
                    case FLOATTOK:
                        var1->value.intVal = var1->value.floatVal >= var2->value.floatVal;
                        break;
                    case CHARTOKEN:
                        var1->value.intVal = var1->value.charVal >= var2->value.charVal;
                        break;
                    case STRTOKEN:
                        //TODO: probably implement a comparator
                        var1->value.intVal = var1->value.string >= var2->value.string;
                        break;
                }
            break;
            
            case COMPARE:
                switch (var1->type) {
                    case NUMBERTOK:
                        var1->value.intVal = var1->value.intVal == var2->value.intVal;
                        break;
                    case FLOATTOK:
                        var1->value.intVal = var1->value.floatVal == var2->value.floatVal;
                        break;
                    case CHARTOKEN:
                        var1->value.intVal = var1->value.charVal == var2->value.charVal;
                        break;
                    case STRTOKEN:
                        //TODO: probably implement a comparator
                        var1->value.intVal = var1->value.string == var2->value.string;
                        break;
                }
            break;
            
            case NOTEQ:
                switch (var1->type) {
                    case NUMBERTOK:
                        var1->value.intVal = var1->value.intVal != var2->value.intVal;
                        break;
                    case FLOATTOK:
                        var1->value.intVal = var1->value.floatVal != var2->value.floatVal;
                        break;
                    case CHARTOKEN:
                        var1->value.intVal = var1->value.charVal != var2->value.charVal;
                        break;
                    case STRTOKEN:
                        //TODO: probably implement a comparator
                        var1->value.intVal = var1->value.string != var2->value.string;
                        break;
                }
            break;

            default:
                printf("bool: fatal error\n");
            break;
        }
        var1->type = NUMBERTOK; //just true or false
        free(var2);
    }
    return var1;
}