#include "monty.h"

/**
 * addnodeint_stack - Adds a new node at the beginning of a stack_t list
 * @queues_stack: Pointer to pointer to linked list (e.g., head of the list)
 * @h: Value to be added to the new node
 *
 * Return: Pointer to the newly added node
 */
stack_t *addnodeint_stack(stack_t **queues_stack, const int h)
{
	stack_t *newnode_stack;

	newnode_stack = malloc(sizeof(stack_t));
	if (newnode_stack == NULL)
	{
		fprintf(stderr, "Error: Usage failed\n");
		free_list(*queues_stack);
		exit(EXIT_FAILURE);
	}

	newnode_stack->h = h;
	newnode_stack->prev = NULL;

	if (*queues_stack == NULL)
		newnode_stack->next = NULL;
	else
	{
		newnode_stack->next = *queues_stack;
		(*queues_stack)->prev = newnode_stack;
	}
	*queues_stack = newnode_stack;

	return (newnode_stack);
}

