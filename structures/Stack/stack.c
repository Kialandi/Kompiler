#include "stack.h"

DLList * list;

void stackInit() {
    list = createList();
}

void stackDestr() {
    deleteList(list);
}

void push(int data){
    insertHead(list, createNode(data));
}

int pop(){
    int data = list->head->next->data;
    deleteNode(list, list->head->next);
    return data;
}

int peek(){
    return list->head->next->data;
}

int isEmpty(){
    return listEmpty(list);
}

void printStack() {
    printList(list);
}