#include "monty.h"

/**
 * mod_function - Computes the rest of the division of the second top element by the top element.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Current line number in the file.
 */
void mod_function(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n %= (*stack)->n;
    pop_function(stack, line_number);
}
