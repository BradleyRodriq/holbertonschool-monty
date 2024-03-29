#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty file.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - Does nothing.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

