#include "../../kompiler.h"

var * term() { //terminals
    var * var2;
    var * var1;
    
    //has to be freed if not constant

    switch(currTok) {

        //another expression
        case LPARANTOK:
            //get the next token and check if it's an expr
            getTok();
            //TODO: dangerous, have to left factor everything
            var1 = expr();
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
            var1 = term();
            if (var1->type == NUMBERTOK) {
                //int
                var1->value.intVal = - var1->value.intVal;
            } else if (var1->type == FLOATTOK){
                //float
                var1->value.floatVal = - var1->value.floatVal;
            } else if (var1->type == IDTOKEN) {
                //dont think this can work, need to change
                //what to return
                //consider using a flag to confirm it's a variable
                
            } else {
                //something other than numbers or var1iables
                printf("term: error in negative numbers\n");
                return NULL;
            }
        break;

        case IDTOKEN:
            printf("Found ID\n");
            //check if it's a type, if it is, it's a var declaration
            //cases: int x; int x = expr();
            //if not, then it's followed by some op 
            //grab the type from symbol table
            //symbol table needed
            int type;

            if ((type = getType(tokBuf)) != NOTTYPE) {
                printf("Found var declaration\n");
                //found variable declaration
                //int x
                getTok();
                var1 = getSymEntry(tokBuf);
                if (var1 == NULL) {
                    //valid variable declaration
                    printf("valid var1 declare type: %d\n", type);
                    var1 = (struct var * ) malloc(sizeof(struct var));
                    var1->type = type;
                    memcpy(var1->name, tokBuf, strlen(tokBuf));
                }
                else {
                    printf("Variable exists! Cannot declare this var\n");
                    return NULL;
                }
                getTok();
            }
            else {
                printf("found var\n");
                //found a variable
                //either x = expr or ... <OPERATION>* x<++/-->* <OPERATION>*;
                var1 = getSymEntry(tokBuf);
                
                if (var1 == NULL) {
                    printf("Unknown symbol found: %s\n", tokBuf);
                    return NULL;
                }

                getTok();

                if ((var1->type == NUMBERTOK || var1->type == FLOATTOK)
                 && (currTok == PLUSPLUS || currTok == MINUSMINUS)) {
                    //perform post incre/decre
                    printf("increment or decrement found\n");
                    if (var1->type == NUMBERTOK)
                        var1->value.intVal++;
                    else if (var1->type == FLOATTOK)
                        var1->value.floatVal++;
                    getTok();
                }
            }

            if (currTok == EQTOK) {
                printf("found = \n");
                //assignment
                getTok();
                if (currTok != var1->type) {
                    printf("Assignment of non-matching type\n");
                    return NULL;
                }
                var2 = expr();
                insertSymEntry(var1->name, var2);
                getTok();
            }

        break;

        //constants - have to malloc
        case NUMBERTOK:
        case FLOATTOK:
        case CHARTOKEN:
        case STRTOKEN:
        case HEXTOK:
            printf("Constant found : %d, val: %s\n", currTok, tokBuf);
            var1 = (struct var * ) malloc(sizeof(struct var));
            var1->type = currTok;
            switch(currTok) {
                case NUMBERTOK:
                    var1->value.intVal = atoi(tokBuf);
                break;

                case FLOATTOK:
                    var1->value.floatVal = atof(tokBuf);
                break;

                case CHARTOKEN:
                    var1->value.charVal = tokBuf[0];
                break;

                case STRTOKEN:
                    var1->value.string = (char *) malloc(strlen(tokBuf) + 1);
                    strcpy(var1->value.string, tokBuf);
                break;
        
                case HEXTOK:
                    var1->value.hexVal = (char *) malloc(strlen(tokBuf) + 1);
                    strcpy(var1->value.hexVal, tokBuf);
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

    return var1;
}