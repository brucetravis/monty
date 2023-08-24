#include "monty.h"

/**
 * pstr_s - It prints the string starting at the top of the stack,
 * followed by a new
 * @head: The stack head
 * @counter: The line_number
 * Return: no return
 */
void pstr_s(stack_t **head, unsigned int counter)
{
    stack_t *h;
    (void)counter;

    h = *head;
    while (h)
    {
        if (h->n > 127 || h->n <= 0)
        {
            break;
        }
        putchar(h->n);
        h = h->next;
    }
    putchar('\n');
}
