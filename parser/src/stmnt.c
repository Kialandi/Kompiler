#include "../../kompiler.h"

int currTok;

int parse() {
    //add a layer for a statement that ends with a semicolon
    //handle assignments
    //probably add another layer for {}
    //support for structs need {};
    while (currTok != EOF) {
        var * var = expr();
        printf("returned from expr\n");
        printf("Type: %d\n", var->type);
        switch(var->type) {
            case NUMBERTOK:
                printf("Value: %d\n", var->value.intVal);
                break;
            case FLOATTOK:
                printf("Value: %f\n", var->value.floatVal);
                break;
            case CHARTOKEN:
                printf("Value: %c\n", var->value.charVal);
                break;
            default:
                printf("parse: unknown token from expr\n");
                break;
        }
    }
    printf("Parsing complete\n");
}
