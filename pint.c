#include "monty.h"

/**
 * pint_s - It prints the top
 * @head: The stack head
 * @counter: The line_number
 * Return: no return
*/
void pint_s(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stacks(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
