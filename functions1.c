#include "monty.h"

/**
 * push_ - pushes an element to the stack.
 * @stack: the stack
 * @_number: the current line number
 *
 * Return: void
 */
void push_(stack_t **stack, unsigned int _number)
{
	stack_t *new, *tmp;
	char *push_arg = strtok(NULL, "\n \t");
	int pVal;

	if (!_isatoi(push_arg))

	{
		fprintf(stdout, "L%u: usage: push integer\n", _number);
		exit(EXIT_FAILURE);
	}

	pVal = atoi(push_arg);
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = pVal;
	new->prev = NULL;
	new->next = NULL;
	if ((*stack) == NULL)
		*stack = new;
	else if (STACKQ)
	{
		(*stack)->prev = new;
		new->next = *stack;
		*stack = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

#include "monty.h"

/**
 * pall_ - prints all values on the stack, starting from the top of the stack.
 * @stack: the stack
 * @_number: the current line number
 *
 * Return: void
 */
void pall_(stack_t **stack, unsigned int _number)
{
	stack_t *tmp;

	UNUSED(_number);

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
