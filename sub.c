#include "monty.h"
/**
  *sub_s - Carrys out sustration
  *@head: The stack head
  *@counter: The line_number
  *Return: no return
 */
void sub_s(stack_t **head, unsigned int counter)
{
	int sus, nodes;
	stack_t *aux;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free_stacks(*head);
		free(bus.content);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}
