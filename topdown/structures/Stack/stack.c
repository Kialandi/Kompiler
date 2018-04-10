#include "stack.h"

DLList * stack;
int validStack();

void stackInit() {
    stack = createList();
}

void stackDestr() {
    deleteList(stack);
}

void push(int data){
    insertHead(stack, createNode(data));
}

int pop(){
    if (!validStack()) {
        return 0;
    }
    int data = stack->head->next->data;
    deleteNode(stack, stack->head->next);
    return data;
}

int peek(){
    if (!validStack()) {
        return 0;
    }
    return stack->head->next->data;
}

int isEmpty(){
    return listEmpty(stack);
}

void printStack() {
    printf("Printing stack...\n");
    if (!validStack()) {
        return;
    }
    DLNode * iter = stack->head->next;
    
    while (iter != stack->tail) {
        printf("%d\n", iter->data);
        iter = iter->next;
    }

    printf("%d\n", iter->data);
    printf("Done.\n");
}

int validStack() {
    
    if (stack == NULL) {
        perror("validStack: Null stack found\n");
        return 0;
    }
    if (isEmpty()) {
        printf("validStack: Empty stack found\n");
        return 0;
    }

    return 1;
}