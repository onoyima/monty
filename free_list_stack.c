#include "monty.h"

/**
 * free_list - frees a stack_t list
 * @queues_stack: pointer to the top of the stack
 */
void free_list(stack_t *queues_stack)
{
	stack_t *current;

	while (queues_stack != NULL)
	{
		current = queues_stack;
		queues_stack = queues_stack->next;
		free(current);
	}
}
