#include "../../kompiler.h"

int currTok;

int parse() {
    //add a layer for a statement that ends with a semicolon
    //handle assignments
    //probably add another layer for {}
    //support for structs need {};
    int i =0;
    while (currTok != EOF) {
        var * var = expr();
        if (var == NULL) {
            printf("NULL var found\n");
            return 1;
        }
        printf("returned from expr\n");
        printf("curTok should be %d: %d\n", SEMICOLTOK, currTok);
        printf("=================================================\n");
        printf("Type: %d\n", var->type);
        //getTok();
        switch(var->type) {
            case NUMBERTOK:
                printf("Int value: %d\n", var->value.intVal);
                break;
            case FLOATTOK:
                printf("Float value: %f\n", var->value.floatVal);
                break;
            case CHARTOKEN:
                printf("Char: %c\n", var->value.charVal);
                break;
            case STRTOKEN:
                printf("String: %s\n", var->value.string);
                break;
            default:
                printf("parse: unknown token from expr\n");
                return 1;
                break;
        }
        printf("=================================================\n");
        getTok();
    }
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