#include "monty.h"

glob_t glob;

/**
 * main - The Main function for monty program.
 * @argc: arguments count
 * @argv: argument vector
 *
 * Return: 0 on success, non-zero on failure
 */
int main(int argc, char *argv[])
{
	stack_t *queues_stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	glob.file = fopen(argv[1], "r");
	if (glob.file == NULL)
	{
		fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	process_line(&queues_stack);
	fclose(glob.file);
	free(glob.line);
	free_list(queues_stack);
	exit(EXIT_SUCCESS);
}
