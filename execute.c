#include "monty.h"

/**
 * execute - Execute Monty bytecode instructions
 * @content: The content of the bytecode instruction line
 * @head: Pointer to the head of the stack
 * @counter: Line number being executed
 * @file: Pointer to the input bytecode file
 *
 * Return: 0 on success, -1 on failure
 */
int execute(char *content, stack_t **head, unsigned int counter, FILE *file)
{
    char *opcode;
    int value;
    stack_t *temp;

    opcode = strtok(content, " \t\n");
    if (opcode == NULL)
    {
        return 0;
    }
     
    if (strcmp(opcode, "push") == 0)
    {
        char *value_str = strtok(NULL, " \t\n");
        if (value_str == NULL)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(file);
            free(bus.content);
            free_stacks(*head);
            exit(EXIT_FAILURE);
        }

        value = atoi(value_str);
        addnode_s(head, value);
    }
    else if (strcmp(opcode, "pop") == 0)
    {
        if (*head == NULL)
        {
            fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
            fclose(file);
            free(bus.content);
            free_stacks(*head);
            exit(EXIT_FAILURE);
        }

        temp = *head;
        *head = (*head)->next;
        if (*head)
        {
            (*head)->prev = NULL;
        }
        free(temp);
    }

    return 0;
}
