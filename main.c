#include "monty.h"

/**
 * main - opens the monty file to be interpreted
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	stack_t *stack = NULL;
	unsigned int line_number = 1;
	char line[256];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (is_blank(line))
		{
			line_number++;
			continue;
		}
		process_line(&stack, line, line_number);
		line_number++;
	}

	fclose(file);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
