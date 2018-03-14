#ifndef PROTO_H
#define PROTO_H

extern int scinit();
/* **********************************************
 * Transition functions to move between states  *
 * Located in transFunc.c                       *
 * *********************************************/

extern void grabNextCh();
extern void storeAndGrab();
extern void escChar();
extern void storeSlashAccu();
extern void tokFunc();
extern void backToDefault();
extern void discard();
extern void accumulate();
extern void returnTok();
extern void errFunc();
extern void charSTFunc();
extern void strSTFunc();
extern void slashFunc();

//getters for stMachine fields
extern int getNextSt(int, int);
extern transFunc getTransFunc(int, int);
extern int grabRetToken(int, int);

//function called by parser
extern token getToken();

#endif