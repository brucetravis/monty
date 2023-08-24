#include "monty.h"
/**
 * queue_s - It prints the top oof the stack
 * @head: the stack head
 * @counter: the line_number
 * Return: no return
*/
void queue_s(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue_s - Function add node to the tail of the stack
 * @n: The new_value
 * @head: acts as the head of the stack
 * Return: there is no return
*/
void addqueue_s(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
