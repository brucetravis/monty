#include "monty.h"

/**
 * pint_function - Prints the value at the top of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Current line number in the file.
 */
void pint_function(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}
