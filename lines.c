#include "monty.h"

/**
 * parse_line - parses through a line and returns the proper instruction
 * @line: the line
 *
 * Return: a pointer to the proper instruction
 */
instruction_t *parse_line(char *line)
{
	char *opcode;
	instruction_t *instruction;

	opcode = get_opcode(line);
	instruction = malloc(sizeof(*instruction));
	if (instruction == NULL) {
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE); }
	instruction->opcode = opcode;
	instruction->f = NULL;
	if (instruction->opcode) {
		if (strcmp(instruction->opcode, "push") == 0)
			instruction->f = push_;
		if (strcmp(instruction->opcode, "pall") == 0)
			instruction->f = pall_;
		if (strcmp(instruction->opcode, "pint") == 0)
			instruction->f = pint_;
		if (strcmp(instruction->opcode, "pop") == 0)
			instruction->f = pop_;
		if (strcmp(instruction->opcode, "swap") == 0)
			instruction->f = swap_;
		if (strcmp(instruction->opcode, "add") == 0)
			instruction->f = add_;
		if (strcmp(instruction->opcode, "nop") == 0)
			instruction->f = nop_;
		if (strcmp(instruction->opcode, "sub") == 0)
			instruction->f = subtract_;
		if (strcmp(instruction->opcode, "div") == 0)
			instruction->f = divide_;
		if (strcmp(instruction->opcode, "mul") == 0)
			instruction->f = multi_;
		if (strcmp(instruction->opcode, "mod") == 0)
			instruction->f = mod_;
		if (strcmp(instruction->opcode, "pchar") == 0)
			instruction->f = print_char;
		if (strcmp(instruction->opcode, "pstr") == 0)
			instruction->f = print_str;
		if (strcmp(instruction->opcode, "rotl") == 0)
			instruction->f = rot_l;
		if (strcmp(instruction->opcode, "rotr") == 0)
			instruction->f = rot_r;
		if (strcmp(instruction->opcode, "stack") == 0)
			instruction->f = stack_;
		if (strcmp(instruction->opcode, "queue") == 0)
			instruction->f = queue_;
	}
	return (instruction);
}
