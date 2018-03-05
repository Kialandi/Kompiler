#ifndef SCANNER_H
#define SCANNER_H

#define OK              1
#define MAXTOKBUFLEN    100

#define MAXSTATES       25
#define ASCIIMAX        127 //DEL
#define TOTALMAPS       34

/* States */
#define ERRST           -1
#define DEFAULTST       0
#define DISCARDST       0
#define NUMBERST        1
#define FLOATST         2
#define IDST            3

//States for chars
#define CHARST          4
#define CHARST2         5
#define CHARESCST       6

//States for strings
#define STRINGST        7
#define STRESCST        8

//States for comments
#define SLASHST         9
#define COMMENTST       10
#define LEAVECOMMST     11
#define COMMSLST        12

//States for symbols
#define PLUSST          13
#define MINUSST         14
#define STARST          15
#define MODST           16

#define NOTST           17
#define ANDST           18
#define ORST            19
#define LTST            20
#define GTST            21
#define EQST            22
#define CARETST         23

#define TOKST           99

/* Accepting states */
#define ACCEPTST        100
#define INTACCST        100
#define FLOACCST        100
#define IDACCST         100
#define CHARACCST       100
#define STRACCST        100

/* Tokens */
#define ERRTOKEN        0
#define NUMBERTOK       1
#define FLOATTOK        2
#define IDTOKEN         3
#define CHARTOKEN       4
#define STRTOKEN        5

#define DIVTOK          6
#define DIVEQ           7

#define PLUSTOK         8
#define PLUSPLUS        9
#define PLUSEQ          10

#define MINUSTOK        11
#define MINUSMINUS      12
#define MINUSEQ         13

#define STARTOK         14
#define STAREQ          15

#define MODTOK          16
#define MODEQ           17

#define NOTTOK          18
#define NOTEQ           19

#define ANDTOK          20
#define ANDAND          21
#define ANDEQ           22

#define ORTOK           23
#define OROR            24
#define OREQ            25

#define LTTOK           26
#define LSHIFT          27
#define LTEQ            28

#define GTTOK           29
#define RSHIFT          30
#define GTEQ            31

#define EQTOK           32
#define COMPARE         33

#define XORTOK          34
#define XOREQ           35

#define TILDETOK        100
#define LPARANTOK       101
#define RPARANTOK       102
#define LBRACTOK        103
#define RBRACTOK        104
#define LCURLYTOK       105
#define RCURLYTOK       106
#define COMMATOK        107
#define QUESTIONTOK     108
#define COLONTOK        109
#define SEMICOLTOK      110
#define POUNDTOK        111

/* Typedefs */
typedef int token;
typedef void (*transFunc)();

struct state {
    int nextState;
    transFunc func;
    token tok;
};

extern struct state stMachine[MAXSTATES][TOTALMAPS];
extern int retToken;
extern int prevState;
extern int currState;
extern int tokBufIndex;
extern int currCh;
extern int stashedCh;
extern char tokBuf[MAXTOKBUFLEN + 1];//+1 to enable last \0
extern FILE * fp;

#endif
