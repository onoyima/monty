#include "monty.h"

/**
 * executeOpcodesFromFile - Reads and executes opcodes from a file
 * @queues_stack: Pointer to the top of the stack
 */
void process_line(stack_t **queues_stack)
{
	char *opcode = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 0;

	while ((nread = getline(&glob.line, &len, glob.file)) != -1)
	{
		line_number++;
		opcode = strtok(glob.line, " \t\r\n\a");
		glob.arg = strtok(NULL, " \n\t");
		if (opcode == NULL || *opcode == '#')
			continue;
		exec_opcode(opcode, queues_stack, line_number);
	}
}

/**
 * executeOpcode - Executes a single opcode
 * @opcode: Opcode to execute
 * @queues_stack: Pointer to the top of the stack
 * @line_number: Line number of the opcode
 */
void exec_opcode(char *opcode, stack_t **queues_stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push_opcode},
		{"pall", op_pall},
		{"pint", print_int},
		{"pop", pop_opcode},
		{"swap", swap_top},
		{"nop", op_nothing},
		{"add", add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", print_char},
		{"pstr", print_str},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(queues_stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free_list(*queues_stack);
	fclose(glob.file);
	free(glob.line);
	exit(EXIT_FAILURE);
}
