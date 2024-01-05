#include "monty.h"

/**
 * sub - Subtracts the top element from the second top element of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty file.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL && (*stack)->next != NULL)
	{
		(*stack)->next->n -= (*stack)->n;
		pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
