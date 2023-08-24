#include "monty.h"

/**
 * add_function - Adds the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Current line number in the file.
 */
void add_function(stack_t **stack, unsigned int line_number)
{
    int sum;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    sum = (*stack)->n + (*stack)->next->n;
    pop_function(stack, line_number);
    (*stack)->n = sum;
}
