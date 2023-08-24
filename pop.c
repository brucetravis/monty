#include "monty.h"

/**
 * pop_s - removes the top element of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pop_s(stack_t **head, unsigned int counter)
{
    stack_t *temp;

    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stacks(*head);
        exit(EXIT_FAILURE);
    }

    temp = *head;
    *head = (*head)->next;
    if (*head)
        (*head)->prev = NULL;
    free(temp);
}

