#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void queue_init(Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

int queue_is_empty(const Queue *queue)
{
    return queue->front == NULL;
}

void queue_enqueue(Queue *queue, int data)
{
    QueueNode *new_node = malloc(sizeof(QueueNode));

    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (queue_is_empty(queue)) {
        /*
         * First element.
         * Both front and rear point to it.
         */
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        /*
         * Add the new node after the current rear.
         */
        queue->rear->next = new_node;

        /*
         * Move rear to the new node.
         */
        queue->rear = new_node;
    }

    queue->size++;
}

int queue_dequeue(Queue *queue, int *value)
{
    if (queue_is_empty(queue)) {
        return 0;
    }

    QueueNode *temp = queue->front;

    *value = temp->data;

    queue->front = temp->next;

    /*
     * If the queue became empty,
     * rear must also become NULL.
     */
    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);

    queue->size--;

    return 1;
}

int queue_peek(const Queue *queue, int *value)
{
    if (queue_is_empty(queue)) {
        return 0;
    }

    *value = queue->front->data;

    return 1;
}

void queue_print(const Queue *queue)
{
    const QueueNode *current = queue->front;

    printf("Queue: FRONT -> ");

    while (current != NULL) {
        printf("%d", current->data);

        if (current->next != NULL) {
            printf(" -> ");
        }

        current = current->next;
    }

    printf(" <- REAR\n");
}

void queue_free(Queue *queue)
{
    QueueNode *current = queue->front;

    while (current != NULL) {
        QueueNode *next = current->next;

        free(current);

        current = next;
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}