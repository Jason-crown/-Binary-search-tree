#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void list_init(LinkedList *list)
{
    list->head = NULL;
    list->size = 0;
}

void list_append(LinkedList *list, int data)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *current = list->head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = new_node;
    }

    list->size++;
}

void list_prepend(LinkedList *list, int data)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    new_node->data = data;
    new_node->next = list->head;

    list->head = new_node;
    list->size++;
}

void list_print(const LinkedList *list)
{
    const Node *current = list->head;

    printf("[");

    while (current != NULL) {
        printf("%d", current->data);

        if (current->next != NULL) {
            printf(" -> ");
        }

        current = current->next;
    }

    printf("]\n");
}

void list_free(LinkedList *list)
{
    Node *current = list->head;

    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->size = 0;
}