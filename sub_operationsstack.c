#include "monty.h"

/**
 * _sub - subtracts the top element from the second top
 * @queues_stack: double pointer to the stack
 * @line_number: line number in the file
 */
void _sub(stack_t **queues_stack, unsigned int line_number)
{
	int myvalue;
	stack_t *temp;

	if (*queues_stack == NULL || (*queues_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *queues_stack;
	myvalue = temp->next->h - temp->h;
	temp->next->h = myvalue;
	*queues_stack = temp->next;
	free(temp);
}
