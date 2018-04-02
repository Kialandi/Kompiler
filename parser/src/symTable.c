#include "../../kompiler.h"

var * getSymEntry(char * label) {
    //TODO: set up symbol table
    return NULL;

}

void insertSymEntry(char * id, var * var) {
    //TODO: insert to symtab
}

int getType(char * type) {
    if (!strcmp("int", type)) {
        return NUMBERTOK;
    }
    else if (!strcmp("char", type)) {
        return CHARTOKEN;
    }
    else if (!strcmp("float", type)) {
        return FLOATTOK;
    }
    else if (strcmp("String", type)) {
        return STRTOKEN;
    }
    else
        return NOTTYPE;
    
}