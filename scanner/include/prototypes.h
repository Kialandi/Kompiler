#ifndef PROTO_H
#define PROTO_H

extern  void    printToken(int);

/* **********************************************
 * Transition functions to move between states  *
 * Located in transFunc.c                       *
 * *********************************************/
extern void errFunc();
extern void discard(FILE *);
extern void accumulate(FILE *);
extern void returnTok();

#endif