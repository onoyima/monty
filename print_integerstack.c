#include "monty.h"

/**
 * print_int - prints the value at the top of the stack
 * @queues_stack: pointer to the top of stack
 * @line_number: line number of the opcode
*/
void print_int(stack_t **queues_stack, unsigned int line_number)
{
	if (*queues_stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(glob.line);
		free_list(*queues_stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*queues_stack)->h);
}
