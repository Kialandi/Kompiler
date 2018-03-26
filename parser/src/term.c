#include "../../kompiler.h"

var * term() { //terminals
    var * var;
    switch(currTok) {

        //another expression
        case LPARANTOK:
            //get the next token and check if it's an expr
            getTok();
            //TODO: dangerous, have to left factor everything
            var = expr();
            //expect return to have the next token already
            if (currTok != RPARANTOK) {
                printf("Missing matching RPARAN\n");
                return NULL;
            }
            else
                getTok();
        break;

        //negative numbers
        case MINUSTOK:
            getTok();
            var = term();
            if (var->type == NUMBERTOK) {
                //int
            } else if (var->type == FLOATTOK){
                //float
            } else {
                //something other than numbers, therefore error
                return;
            }
        break;

        case IDTOKEN:
            //can either be increment or decrement
            //can also be assignment
            //look at symbol table

        break;

        //constants - have to malloc
        case NUMBERTOK:
        case FLOATTOK:
        case CHARTOKEN:
        case STRTOKEN:
        case HEXTOK:
        
        break;

        default:
            printf("Unexpected token found in term\n");
            return NULL;
        break;
    }

    return var;
}