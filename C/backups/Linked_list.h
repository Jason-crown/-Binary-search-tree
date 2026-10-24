#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} LinkedList;

void list_init(LinkedList *list);
void list_append(LinkedList *list, int data);
void list_prepend(LinkedList *list, int data);
void list_print(const LinkedList *list);
void list_free(LinkedList *list);

#endif