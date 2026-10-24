#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

void queue_init(Queue *queue);

int queue_is_empty(const Queue *queue);

void queue_enqueue(Queue *queue, int data);

int queue_dequeue(Queue *queue, int *value);

int queue_peek(const Queue *queue, int *value);

void queue_print(const Queue *queue);

void queue_free(Queue *queue);

#endif