#include "monty.h"

/**
 * push - Pushes a value onto the stack.
 * @stack: Double pointer to the top of the stack.
 * @value: Value to be pushed onto the stack.
 */
void push(stack_t **stack, int value)
{
    stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack != NULL)
        (*stack)->prev = new_node;
    *stack = new_node;
}

/**
 * pop - Pops a value from the stack.
 * @stack: Double pointer to the top of the stack.
 * Return: The popped value.
 */
int pop(stack_t **stack)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "Error: Attempt to pop from an empty stack\n");
        exit(EXIT_FAILURE);
    }
    int value = (*stack)->n;
    stack_t *temp = *stack;
    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(temp);
    return value;
}

/**
 * pall - Prints all values on the stack.
 * @stack: Double pointer to the top of the stack.
 */
void pall(stack_t *stack)
{
    stack_t *current = stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * execute_instruction - Executes a Monty instruction.
 * @instr: Pointer to the instruction structure.
 * @arg: Argument associated with the instruction (if any).
 * @line_number: Current line number in the file.
 */
void execute_instruction(instruction_t *instr, char *arg, unsigned int line_number)
{
    if (strcmp(instr->opcode, "push") == 0)
    {
        if (arg == NULL)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        int value = atoi(arg);
        if (value == 0 && strcmp(arg, "0") != 0)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        push(&stack, value);
    }
    else if (strcmp(instr->opcode, "pall") == 0)
    {
        pall(stack);
    }
    else
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instr->opcode);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    
    while (fgets(line, MAX_LINE_LENGTH, file))
    {
        char *instruction = strtok(line, " \t\n");
        char *arg = strtok(NULL, " \t\n");
        if (instruction != NULL)
        {
            for (unsigned int i = 0; instructions[i].opcode != NULL; i++)
            {
                if (strcmp(instruction, instructions[i].opcode) == 0)
                {
                    execute_instruction(&instructions[i], arg, line_number);
                    break;
                }
            }
        }
        line_number++;
    }

    fclose(file);

    while (stack != NULL)
    {
        pop(&stack);
    }

    return 0;
}
