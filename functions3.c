#include "monty.h"

/**
 * pint_ - prints the value at the top of the stack, followed by a new line.
 * @stack: the stack
 * @_number: the current line number
 *
 * Return: void
 */
void pint_(stack_t **stack, unsigned int _number)
{
	if (*stack == NULL)
	{
		fprintf(stdout, "L%d: can't pint, stack empty\n", _number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * swap_ - swaps the top two elements of the stack.
 * @stack: the stack
 * @_number: the current line number
 *
 * Return: void
 */
void swap_(stack_t **stack, unsigned int _number)
{
	int swapper;

	if ((*stack) == NULL)
	{
		fprintf(stdout, "L%d: can't swap, stack too short\n", _number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't swap, stack too short\n", _number);
		exit(EXIT_FAILURE);
	}
	swapper = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = swapper;
}
