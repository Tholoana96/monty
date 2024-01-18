#include "monty.h"

/**
 * mod_ - mods the top two elements of the stack.
 * @stack: the stack
 * @_number: the current line number
 *
 * Return: void
 */
void mod_(stack_t **stack, unsigned int _number)
{
	int modd;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't mod, stack too short\n", _number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stdout, "L%d: division by zero\n", _number);
		exit(EXIT_FAILURE);
	}

	modd = (*stack)->next->n % (*stack)->n;
	pop_(stack, _number);
	(*stack)->n = modd;
}

/**
 * pop_ - removes the top element of the stack.
 * @stack: the stack
 * @_number: the current line number
 *
 * Return: void
 */
void pop_(stack_t **stack, unsigned int _number)
{
	stack_t *tmp;

	if ((*stack) == NULL)
	{
		fprintf(stdout, "L%d: can't pop an empty stack\n", _number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

/**
 * nop_ - The opcode nop doesn’t do anything.
 * @stack: the stack
 * @_number: the current line number
 *
 * Return: void
 */

void nop_(stack_t **stack, unsigned int _number)
{
	UNUSED(stack);
	UNUSED(_number);
}
