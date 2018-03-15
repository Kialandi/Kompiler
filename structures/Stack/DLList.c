#include "DLList.h"

/**************************************************************************
 * 
 * Title    : Doubly linked list
 * @author  : Sam Yap
 * @date    : March 15 2018
 * Notes    : Sentinel head with a tail pointer to last element
 * 
 *************************************************************************/

DLList * createList() {
    DLList * list = (DLList *) malloc(sizeof(DLList));
    if (list == NULL) {
        perror("Create list failed.\n");
        return NULL;
    }
    
    list->head = createNode(-1);
    list->tail = NULL;
    list->head->next = list->tail;
    list->count = 0;

    return list;
}

void deleteList(DLList * list) {
    if (list == NULL) {
        perror("Invalid list.\n");
        return;
    }
    int i = 1;
    DLNode * node = list->head->next;
    if (node == NULL) {
        free(list->head);
        free(list);
        printf("Empty list freed\n");
        return;
    }
    DLNode * next = node ->next;

    while (node != list->tail) {
        i++;
        free(node);
        node = next;
        next = node->next;
    }
    free(list->head);
    free(list->tail);
    free(list);
    printf("List freed: %d\n", i);
}

DLNode * createNode(int data) {
    DLNode * node = (DLNode *) malloc(sizeof(DLNode));
    if (node == NULL) {
        perror("Create node failed.\n");
        return NULL;
    }
    node->data = data;

    return node;
}

void deleteNode(DLList * list, DLNode * node) {
    if (node == NULL) {
        perror("Invalid node.\n");
        return;
    }
    if (list->count <= 0) {
        perror("Empty list.\n");
        return;
    }

    if (list->count == 1) {
        list->tail = NULL;
        list->head->next = list->tail;
        free(node);
        list->count--;
        return;
    }

    DLNode * next = node->next;
    DLNode * prev = node->prev;
    prev->next = next;
    next->prev = prev;

    free(node);
    list->count--;
}

void insert(DLList * list, DLNode * entry, DLNode * node) {
    //WARNING: does not update count
    //insert after the entry node
    if (node == NULL || entry == NULL) {
        perror("Invalid node.\n");
        return;
    }

    node->next = entry->next;
    node->prev = entry;

    if (node->next != NULL) //for tail insertion
        node->next->prev = node;

    entry->next = node;
    list->count++;
}

void insertHead(DLList * list, DLNode * node) {
    if (list == NULL) {
        perror("Invalid list.\n");
        return;
    }
    insert(list, list->head, node);

    if (list->tail == NULL)
        list->tail = node;
}

void insertTail(DLList * list, DLNode * node) {
    if (list == NULL) {
        perror("Invalid list.\n");
        return;
    }
    if (list->tail == NULL) {
        insertHead(list, node);
    }
    else {
        insert(list, list->tail, node);
    }

    list->tail = node;
}

void printList(DLList * list) {
    if (list == NULL) {
        perror("Invalid list.\n");
        return;
    }

    printf("===================== List ====================\n");
    DLNode * node = list->head->next;

    while (node != list->tail) {
        printf("Value: %d <->\n", node->data);
        node = node->next;
    }
    if (list->tail != NULL)
        printf("Value: %d", list->tail->data);
    printf("\n================= End of list =================\n");
    printf("Count: %d\n", list->count);
}

int listEmpty(DLList * list) {
    return list->count == 0 ? 1 : 0;
}
