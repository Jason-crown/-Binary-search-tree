#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void stack_init(Stack *stack)
{
    stack->top = NULL;
    stack->size = 0;
}

int stack_is_empty(const Stack *stack)
{
    return stack->top == NULL;
}

void stack_push(Stack *stack, int data)
{
    StackNode *new_node = malloc(sizeof(StackNode));

    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    new_node->data = data;
    new_node->next = stack->top;

    stack->top = new_node;
    stack->size++;
}

int stack_pop(Stack *stack, int *value)
{
    if (stack_is_empty(stack)) {
        return 0;
    }

    StackNode *temp = stack->top;

    *value = temp->data;

    stack->top = temp->next;

    free(temp);

    stack->size--;

    return 1;
}

int stack_peek(const Stack *stack, int *value)
{
    if (stack_is_empty(stack)) {
        return 0;
    }

    *value = stack->top->data;

    return 1;
}

void stack_print(const Stack *stack)
{
    const StackNode *current = stack->top;

    printf("Stack: TOP -> ");

    while (current != NULL) {
        printf("%d", current->data);

        if (current->next != NULL) {
            printf(" -> ");
        }

        current = current->next;
    }

    printf("\n");
}

void stack_free(Stack *stack)
{
    StackNode *current = stack->top;

    while (current != NULL) {
        StackNode *next = current->next;

        free(current);

        current = next;
    }

    stack->top = NULL;
    stack->size = 0;
}