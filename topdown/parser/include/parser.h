#define VALIDEXPR   1
#define NOTTYPE     -1
#define MAXIDLEN    25 //max len of a variable name

extern token currTok;

typedef struct var {
    int type;
    union value {
        int intVal;
        float floatVal;
        char charVal;
        char * string;
        char * hexVal;
        //maybe do strings and pointers
    } value;
    char name[MAXIDLEN];
} var;

var * getSymEntry(char * label);
int getType(char * type);
void insertSymEntry(char * id, var * var);

extern void getTok();
extern int match(int, var *, var *);
extern var * expr();
extern var * doBool();
extern var * rel();
extern var * fact();
extern var * term();