#include "monty.h"

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

	if (strchr(line, '#') != NULL)
	{
		return;
	}

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

/**
 * opcode_exe - executes specified opcode
 * @stack: pointer to first element
 * @opcode: the specified command
 * @value: the elements value
 * @line_number: the number of the line
 */
void opcode_exe(stack_t **stack, const char *opcode,
		int value, unsigned int line_number)
{
	if (strcmp(opcode, "push") == 0)
		push(stack, value, line_number);

	else if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);

	else if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);

	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);

	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);

	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);

	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);

	else if (strcmp(opcode, "sub") == 0)
		sub(stack, line_number);

	else if (strcmp(opcode, "div") == 0)
		_div(stack, line_number);

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
void free_stack(stack_t *stack)
{
	stack_t *current = stack;

	while (current != NULL)
	{
		stack_t *next = current->next;

		free(current);
		current = next;
	}
}

/**
 * is_blank - checks line for blank content
 * @line: the line to be checked
 * Return: if blank, i < 0
 */
int is_blank(const char *line)
{
	int i = strlen(line) - 1;

	while (i >= 0 && (line[i] == ' ' ||
				line[i] == '\t' || line[i] == '\n' ||
				line[i] == '\r'))
	{
		i--;
	}
	return (i < 0);
}

