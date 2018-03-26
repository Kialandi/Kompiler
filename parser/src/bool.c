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
        switch(currTok) {
            //can simplify constants, but for ID you have to generate code
            case LTTOK:
                case NUMBERTOK:
                break;
                case FLOATTOK:
                break;
                case CHARTOKEN:
                break;
                case STRTOKEN:
                break;
            break;
            
            case LTEQ:
            break;
            
            case GTTOK:
            break;
            
            case GTEQ:
            break;
            
            case COMPARE:
            break;
            
            case NOTEQ:
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