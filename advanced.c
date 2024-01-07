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

/**
 * _div - divides first two elements of the stack
 * @stack: the first element of the stack
 * @line_number: the number of the line
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int divisor, dividend;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	divisor = pop(stack, line_number);

	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	dividend = pop(stack, line_number);

	push(stack, dividend / divisor, line_number);
}
