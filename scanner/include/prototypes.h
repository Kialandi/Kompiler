#ifndef PROTO_H
#define PROTO_H

/* **********************************************
 * Transition functions to move between states  *
 * Located in transFunc.c                       *
 * *********************************************/
extern void discard(FILE *);
extern void accumulate(FILE *);
extern token returnTok(int);
extern void errFunc();

//helper functions to get transtion states and functions
extern int getNextSt(int, int);
extern transFunc getTransFunc(int, int);

//function called by parser
extern token getToken();

#endif