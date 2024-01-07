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

/**
 * process_line - handles the opcodes
 * @stack: pointer to the first value
 * @line: the line to be read
 * @line_number: the number of the line to be read
 */
void process_line(stack_t **stack, const char *line, unsigned int line_number)
{
	char opcode[256];
	int value;

	if (sscanf(line, "%255s %d", opcode, &value) == 2 ||
			sscanf(line, "%255s", opcode) == 1)
	{
		if (strcmp(opcode, "push") == 0)
		{
			if (sscanf(line, "%*s %d", &value) != 1)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		opcode_exe(stack, opcode, value, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}



