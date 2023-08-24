#include "monty.h"

/**
 * push_function - Pushes a value onto the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Current line number in the file.
 * @arg: Argument associated with the instruction.
 */
void push_function(stack_t **stack, unsigned int line_number, char *arg)
{
    char *c;
    int value;
    stack_t *new_node;

    if (!arg)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    for (c = arg; *c; c++)
    {
        if (*c != '-' && (*c < '0' || *c > '9'))
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }

    value = atoi(arg);
    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

     new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack)
        (*stack)->prev = new_node;
    *stack = new_node;
}

 /**
 * pall_function - Prints all values on the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Current line number in the file.
 */
void pall_function(stack_t **stack, unsigned int line_number)
{
    stack_t *current;

    (void)line_number;

    current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
