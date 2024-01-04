#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void free_stack(stack_t *stack);
void process_line(stack_t **stack, const char *line, unsigned int line_number);

/**
 * main - opens the monty file to be interpreted
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		fclose(file);
		return (EXIT_FAILURE);
	}

	stack_t *stack = NULL;
	unsigned int line_number = 1;

	char line[256];

	while (fgets(line, sizeof(line), file) != NULL)
	{
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

	if (sscanf(line, "%s %d", opcode, &value) == 2 ||
			sscanf(line, "%s", opcode) == 1)
	{
		if (strcmp(opcode, "push") == 0)
		{
			push(stack, value, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_stack - frees a stack
 * @stack: pointer to the stack to be freed
*/
void free_stack(stack_t *stack) {
    stack_t *current = stack;
    while (current != NULL) {
        stack_t *next = current->next;
        free(current);
        current = next;
    }
}