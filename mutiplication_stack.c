#include "monty.h"

/**
 * _mul - multiplies second top element
 * @queues_stack: double pointer to the stack
 * @line_number: The line number in the file
 */
void _mul(stack_t **queues_stack, unsigned int line_number)
{
	int result;
	stack_t *temp;

	if (*queues_stack == NULL || (*queues_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *queues_stack;
	result = temp->next->h * temp->h;
	temp->next->h = result;
	*queues_stack = temp->next;
	free(temp);
}
