#include "../../kompiler.h"

var * term() { //terminals
    var * var;
    //has to be freed if not constant

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
            printf("term: negative num found\n");
            getTok();
            var = term();
            if (var->type == NUMBERTOK) {
                //int
                var->value.intVal = - var->value.intVal;
            } else if (var->type == FLOATTOK){
                //float
                var->value.floatVal = - var->value.floatVal;
            } else if (var->type == IDTOKEN) {
                //dont think this can work, need to change
                //what to return
                //consider using a flag to confirm it's a variable
                
            } else {
                //something other than numbers or variables
                printf("term: error in negative numbers\n");
                return NULL;
            }
        break;

        case IDTOKEN:
            printf("Found ID\n");
            var = (struct var * ) malloc(sizeof(struct var));
            getTok();
            //grab the type from symbol table
            //symbol table needed

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
            printf("Constant found : %d, val: %s\n", currTok, tokBuf);
            var = (struct var * ) malloc(sizeof(struct var));
            var->type = currTok;
            switch(currTok) {
                case NUMBERTOK:
                    var->value.intVal = atoi(tokBuf);
                break;

                case FLOATTOK:
                    var->value.floatVal = atof(tokBuf);
                break;

                case CHARTOKEN:
                    var->value.charVal = tokBuf[0];
                break;

                case STRTOKEN:
                    var->value.string = (char *) malloc(strlen(tokBuf) + 1);
                    strcpy(var->value.string, tokBuf);
                break;
        
                case HEXTOK:
                    var->value.hexVal = (char *) malloc(strlen(tokBuf) + 1);
                    strcpy(var->value.hexVal, tokBuf);
                break;
            }
        getTok();
        break;

        default:
            printf("Unexpected token found in term\n");
            printf("tok: %d\n", currTok);
            return NULL;
        break;
    }

    return var;
}