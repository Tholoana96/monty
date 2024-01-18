#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define UNUSED(x) (void)(x)
#define LINE_MAX 1024

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int _number);
} instruction_t;

extern int STACKQ;
instruction_t *parse_line(char *line);
void stack__free(stack_t *head);
char *get_opcode(char *string);
int _isatoi(char *str);
void push_(stack_t **stack, unsigned int _number);
void pall_(stack_t **stack, unsigned int _number);
void pint_(stack_t **stack, unsigned int _number);
void pop_(stack_t **stack, unsigned int _number);
void swap_(stack_t **stack, unsigned int _number);
void add_(stack_t **stack, unsigned int _number);
void nop_(stack_t **stack, unsigned int _number);
void subtract_(stack_t **stack, unsigned int _number);
void divide_(stack_t **stack, unsigned int _number);
void multi_(stack_t **stack, unsigned int _number);
void mod_(stack_t **stack, unsigned int _number);
void print_char(stack_t **stack, unsigned int _number);
void print_str(stack_t **stack, unsigned int _number);
void rot_l(stack_t **stack, unsigned int _number);
void rot_r(stack_t **stack, unsigned int _number);
void stack_(stack_t **stack, unsigned int _number);
void queue_(stack_t **stack, unsigned int _number);

#endif
