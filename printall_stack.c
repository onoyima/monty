#include "monty.h"

/**
 * op_pall - To print all values on the stack
 * @queues_stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 */
void op_pall(stack_t **queues_stack, unsigned int line_number)
{
	stack_t *current = *queues_stack;

	while (current != NULL)
	{
		printf("%d\n", current->h);
		current = current->next;
		(void)line_number;
	}

}
