#include "monty.h"

/**
 * performDivision - Divides the second-to-top element by the top element in the stack
 * @queues_stack: Double pointer to the stack
 * @line_number: Current line number in the file
 */
void _div(stack_t **queues_stack, unsigned int line_number)
{
	int value;
	stack_t *temp;

	if (*queues_stack == NULL || (*queues_stack)->next == NULL)
	{
		fprintf(stderr, "L%d: Unable to div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *queues_stack;
	if (temp->h == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = temp->next->h / temp->h;
	temp->next->h = value;
	*queues_stack = temp->next;
	free(temp);
}
