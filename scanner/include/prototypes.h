#ifndef PROTO_H
#define PROTO_H

extern int scinit();
/* **********************************************
 * Transition functions to move between states  *
 * Located in transFunc.c                       *
 * *********************************************/
extern void discard();
extern void accumulate();
extern token returnTok(int);
extern void errFunc();

//helper functions to get transtion states and functions
extern int getNextSt(int, int);
extern transFunc getTransFunc(int, int);

//function called by parser
extern token getToken();

#endif