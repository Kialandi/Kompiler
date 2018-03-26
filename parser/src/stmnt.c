#include "../../kompiler.h"

int currTok;

int parse() {
    //add a layer for a statement that ends with a semicolon
    //handle assignments
    //probably add another layer for {}
    //support for structs need {};
    
    //while (currTok != EOF) {
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
                return 1;
                break;
        }
   // }
    printf("Parsing complete\n");
    return 0;
}

int main(int argc, char ** argv) {
    if (argc != 2) {
        printf("Usage: ./%s <filename>\n", argv[0]);
        return 0;
    }
    scinit(argv[1]);
    printf("Begin parsing1\n");
    getTok();
    parse();
    return 0;
}