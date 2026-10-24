#include <stdio.h>

#include "doubly_linked_list.h"

int main(void)
{
    DoublyLinkedList list;

    list_init(&list);

    list_append(&list, 10);
    list_append(&list, 20);
    list_append(&list, 30);

    list_prepend(&list, 5);

    printf("List size: %d\n", list.size);

    list_print_forward(&list);
    list_print_backward(&list);

    list_free(&list);

    return 0;
}