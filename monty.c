#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
int STACKQ = 1;
/**
 * main - main function for monty
 * @argc: argument count
 * @argv: array of argument strings
 *
 * Return: exit code
 */

int main(int argc, char **argv)
{
	FILE *file_in;
	unsigned int _number = 0;
	char *line = NULL;
	stack_t *top = NULL;
	instruction_t *instruction = NULL;
	size_t g_size = 0;

	if (argc != 2)
	{
		fprintf(stdout, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_in = fopen(argv[1], "r");
	if (file_in == NULL)
	{
		fprintf(stdout, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &g_size, file_in) != -1)
	{
		_number++;
		instruction = parse_line(line);
		if (!(instruction->opcode) || instruction->opcode[0] == '#')
		{
			free(instruction);
			if (line)
				free(line);
			line = NULL;
			continue;
		}
		if (instruction->f)
			instruction->f(&top, _number);
		else
		{
			fprintf(stdout, "L%d: unknown instruction %s\n",
				_number, instruction->opcode);
			if (line)
				free(line);
			if (top)
				stack__free(top);
			free(instruction);
			fclose(file_in);
			exit(EXIT_FAILURE);
		}
		if (line)
			free(line);
		line = NULL;
		free(instruction);
	}
	if (line)
		free(line);
	stack__free(top);
	fclose(file_in);
	return (0);
}
