#include "../DLList/DLList.h"

extern DLList * stack;

extern void stackInit();
extern void stackDestr();
extern void push(int data);
extern int pop();
extern int peek();
extern int isEmpty();
extern void printStack();