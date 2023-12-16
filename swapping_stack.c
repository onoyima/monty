#include "monty.h"

/**
 * swap_top - swaps the top two value
 * @queues_stack: pointer to the top of the stack
 * @line_number: line number
*/
void swap_top(stack_t **queues_stack, unsigned int line_number)
{
	stack_t *temp;

	if (*queues_stack == NULL || (*queues_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: Unable to  swap, too short\n", line_number);
		free(glob.line);
		free_list(*queues_stack);
		exit(EXIT_FAILURE);
	}

	temp = (*queues_stack)->next;
	(*queues_stack)->next = temp->next;

	if (temp->next != NULL)

	temp->next->prev = *queues_stack;
	temp->prev = NULL;
	temp->next = *queues_stack;
	(*queues_stack)->prev = temp;
	*queues_stack = temp;
}
