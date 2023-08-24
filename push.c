#include "monty.h"

/**
 * push_s - This adds node to the stack
 * @head: The stack head
 * @counter: The line_number
 * Return: no return
 */
void push_s(stack_t **head, unsigned int counter)
{
	int i, k = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			k++;
		for (; bus.arg[k] != '\0'; k++)
		{
			if (bus.arg[k] > 57 || bus.arg[k] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stacks(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stacks(*head);
		exit(EXIT_FAILURE);
	}
	i = atoi(bus.arg);
	addnode_s(head, i);
}
