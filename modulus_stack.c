#include "monty.h"

/**
 * _mod -  modulus of second top element with the top.
 * @queues_stack: pointer to the stack
 * @line_number: line number of the opcode
 */
void _mod(stack_t **queues_stack, unsigned int line_number)
{
	int i, j;

	if (*queues_stack == NULL || (*queues_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: Unable to open, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = (*queues_stack)->h;
	j = (*queues_stack)->next->h;

	if (i == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*queues_stack)->next->h = j % i;
	pop_opcode(queues_stack, line_number);
}
