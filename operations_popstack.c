#include "monty.h"

/**
 * pop_opcode - This removes the top element of the stack
 * @queues_stack: pointer to the top of the stack
 * @line_number: line number of the opcode
 **/
void pop_opcode(stack_t **queues_stack, unsigned int line_number)
{
	stack_t *temp;

	if (*queues_stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(glob.line);
		free_list(*queues_stack);
		exit(EXIT_FAILURE);
	}

	temp = (*queues_stack)->next;
	free(*queues_stack);

	*queues_stack = temp;

	if (*queues_stack != NULL)
		(*queues_stack)->prev = NULL;
}
