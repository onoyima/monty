#include "monty.h"

/**
 * add - This adds the top two elements of the stack
 * @queues_stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 **/
void add(stack_t **queues_stack, unsigned int line_number)
{
	if (*queues_stack == NULL || (*queues_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(glob.line);
		free_list(*queues_stack);
		exit(EXIT_FAILURE);
	}

	(*queues_stack)->next->h += (*queues_stack)->h;
	pop_opcode(queues_stack, line_number);
}
