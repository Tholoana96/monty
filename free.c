#include "monty.h"

/**
 * stack__free - frees a stack_t list.
 * @head: a pointer to the head
 *
 * Return: void
 */

void stack__free(stack_t *head)
{
	stack_t *next;

	if (!head)
		return;

	next = head;
	while (next)
	{
		head = next;
		next = head->next;
		free(head);
	}
}
