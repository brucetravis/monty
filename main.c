#include "monty.h"
#include <stdio.h>

/**
 * main - Entry point of the Monty interpreter.
 * @argc: The number of arguments.
 * @argv: The array of arguments.
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
    FILE *bytecode_file;
    char line[1024];
    unsigned int line_number = 1;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return (EXIT_FAILURE);
    }

    bytecode_file = fopen(argv[1], "r");
    if (bytecode_file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), bytecode_file) != NULL)
    {
         if (instruction_t == NULL)
        {
            fprintf(stderr, "Line %u: Invalid instruction\n", line_number);
        }

        line_number++;
    }

    fclose(bytecode_file);

    return (EXIT_SUCCESS);
}
