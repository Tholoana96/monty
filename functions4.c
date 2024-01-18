#include "monty.h"

/**
 * divide_ - divides the top two elements of the stack.
 * @stack: the stack
 * @_number: the current line number
 *
 * Return: void
 */
void divide_(stack_t **stack, unsigned int _number)
{
	int divs;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't div, stack too short\n", _number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stdout, "L%d: division by zero\n", _number);
		exit(EXIT_FAILURE);
	}
	divs = (*stack)->next->n / (*stack)->n;
	pop_(stack, _number);
	(*stack)->n = divs;
}

/**
 * multi_ - multiplies the top two elements of the stack.
 * @stack: the stack
 * @_number: the current line number
 *
 * Return: void
 */

void multi_(stack_t **stack, unsigned int _number)
{
	int mul;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't mul, stack too short\n", _number);
		exit(EXIT_FAILURE);
	}

	mul = (*stack)->next->n * (*stack)->n;
	pop_(stack, _number);
	(*stack)->n = mul;
}
