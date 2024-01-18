#include "monty.h"

/**
 * rot_l - rotates to the left
 * @stack: monty stack
 * @_number: line number
 */

void rot_l(stack_t **stack, unsigned int _number)
{
	stack_t *tmp;
	int firstVal;

	UNUSED(_number);
	tmp = *stack;
	if (tmp)
		firstVal = tmp->n;
	while (tmp != NULL)
	{
		if (tmp->next)
			tmp->n = tmp->next->n;
		else
			tmp->n = firstVal;
		tmp = tmp->next;
	}
}

/**
 * rot_r - rotates to the right
 * @stack: monty stack
 * @_number: line number
 */

void rot_r(stack_t **stack, unsigned int _number)
{
	stack_t *tmp;
	int lastVal;

	UNUSED(_number);
	if ((*stack) != NULL)
	{
		tmp = *stack;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		lastVal = tmp->n;
		while (tmp->prev != NULL)
		{
			tmp->n = tmp->prev->n;
			tmp = tmp->prev;
		}
		tmp->n = lastVal;
	}
}
