#include "monty.h"

/**
 * free_stacks - Frees all nodes in a stack.
 * @head: Pointer to the head of the stack.
 */
void free_stacks(stack_t *head)
{
    stack_t *current = head;
    stack_t *next;

    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
