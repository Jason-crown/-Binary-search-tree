#ifndef STACK_H
#define STACK_H

typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
    int size;
} Stack;

void stack_init(Stack *stack);

int stack_is_empty(const Stack *stack);

void stack_push(Stack *stack, int data);

int stack_pop(Stack *stack, int *value);

int stack_peek(const Stack *stack, int *value);

void stack_print(const Stack *stack);

void stack_free(Stack *stack);

#endif