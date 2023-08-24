#include "monty.h"

/**
 * addnode_s - Adds a new node at the beginning of a stack_t list
 * @head: Pointer to the head of the stack
 * @n: Value to be stored in the new node
 */
void addnode_s(stack_t **head, int n)
{
    stack_t *new_node;

    if (head == NULL)
        return;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
        return;

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;
}
