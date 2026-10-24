#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} DoublyLinkedList;

/* Initialize the list */
void list_init(DoublyLinkedList *list);

/* Add a node to the end */
void list_append(DoublyLinkedList *list, int data);

/* Add a node to the beginning */
void list_prepend(DoublyLinkedList *list, int data);

/* Print from head to tail */
void list_print_forward(const DoublyLinkedList *list);

/* Print from tail to head */
void list_print_backward(const DoublyLinkedList *list);

/* Free all nodes */
void list_free(DoublyLinkedList *list);

#endif