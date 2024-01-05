#include "monty.h"

/**
 * pint - Prints the value at the top of the stack, followed by a new line
 * @stack: Pointer to the top of the stack
 * @line_number: the number of the line
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
