#include "monty.h"

/**
 * _div - divides first two elements of the stack
 * @stack: the first element of the stack
 * @line_number: the number of the line
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int divisor;
	int dividend;
	int result;

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
	result = dividend / divisor;

	push(stack, result, line_number);
}
