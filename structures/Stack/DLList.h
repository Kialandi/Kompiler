#include <stdlib.h>
#include <stdio.h>

typedef struct DLNode {
    //consider using a struct of unions
    int data;
    struct DLNode * next;
    struct DLNode * prev;
} DLNode;

typedef struct DLList {
    DLNode * head;
    DLNode * tail;
    int count;
} DLList;

extern DLList * createList();
extern DLNode * createNode(int data);
extern void deleteNode(DLList * list, DLNode * node);
extern void insert(DLList * list, DLNode * entry, DLNode * node);
extern void insertHead(DLList * list, DLNode * node);
extern void insertTail(DLList * list, DLNode * node);
extern void printList(DLList * list);
extern void deleteList(DLList * list);
extern int listEmpty(DLList * list);