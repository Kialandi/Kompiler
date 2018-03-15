#include "DLList.h"

int main (int argc, char ** argv) {
    DLList * list = createList();
    printf("printing empty\n");
    printList(list);
    DLNode * n = createNode(100);
    insertHead(list, n);
    printf("printing 1 node\n");
    printList(list);
    deleteNode(list, n);
    printf("printing no nodes left\n");
    printList(list);
    deleteList(list);
    // int i;
    // DLList * list = createList();
    // DLNode * del;
    // for (i = 0; i < 20; i++) {
    //     DLNode * n = createNode(i);
    //     insertHead(list, n);
    //     if (i == 5) del = n;
    // }
    // printList(list);
    // insert(list, del, createNode(100));
    // insert(list, del, createNode(100));
    // insert(list, del, createNode(100));
    // insert(list, del, createNode(100));
    // insert(list, del, createNode(100));
    // insert(list, del, createNode(100));
    // insert(list, del, createNode(100));
    // insert(list, del, createNode(100));
    // insert(list, del, createNode(100));
    // deleteNode(list, del);
    // printList(list);
    // deleteList(list);

    return 0;
}