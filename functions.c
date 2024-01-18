#include "monty.h"

/**
 * add_ - adds the top two elements of the stack.
 * @stack: the stack
 * @_number: the current line number
 *
 * Return: void
 */

void add_(stack_t **stack, unsigned int _number)
{
	int summ;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't add, stack too short\n", _number);
		exit(EXIT_FAILURE);
	}

	summ = (*stack)->next->n + (*stack)->n;
	pop_(stack, _number);
	(*stack)->n = summ;
}

/**
 * subtract_ - subtracts the top two elements of the stack.
 * @stack: the stack
 * @_number: the current line number
 *
 * Return: void
 */
void subtract_(stack_t **stack, unsigned int _number)
{
	int diff;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't sub, stack too short\n", _number);
		exit(EXIT_FAILURE);
	}

	diff = (*stack)->next->n - (*stack)->n;
	pop_(stack, _number);
	(*stack)->n = diff;
}
