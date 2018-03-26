#define VALIDEXPR   1

extern token currTok;

typedef struct var {
    int type;
    union value {
        int intVal;
        float floatVal;
        char charVal;
        char * string;
        //maybe do strings and pointers
    } value;

} var;

extern void getTok();
extern int match(int, var *, var *);
extern var * expr();
extern var * doBool();
extern var * rel();
extern var * fact();
extern var * term();