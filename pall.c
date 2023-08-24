#include "monty.h"
/**
 * pall_s - This prints the stack
 * @head: the stack head
 * @counter: It is not used
 * Return: no return
*/
void pall_s(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
