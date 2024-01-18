#include "monty.h"

/**
 * print_char - prints the char at a the top
 * @stack: monty stack
 * @_number: line number to grab
 */

void print_char(stack_t **stack, unsigned int _number)
{
	if ((*stack) == NULL)
	{
		fprintf(stdout, "L%d: can't pchar, stack empty\n", _number);
		exit(EXIT_FAILURE);
	}
	if (!isprint((*stack)->n))
	{
		fprintf(stdout, "L%d: can't pchar, value out of range\n", _number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%c\n", (*stack)->n);
}
