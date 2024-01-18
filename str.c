#include "monty.h"
/**
 * print_str - prints the string of list
 * @stack: monty stack
 * @_number: line number to grab
 */
void print_str(stack_t **stack, unsigned int _number)
{
	stack_t *tmp;

	tmp = *stack;
	UNUSED(_number);
	while (tmp != NULL && tmp->n != 0 && isprint(tmp->n))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
