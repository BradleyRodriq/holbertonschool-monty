#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pop - Pops a value from the stack.
 * @stack: Pointer to the stack.
 * Return: The value popped from the stack.
 */
int pop(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
	{
		int value = (*stack)->n;
		stack_t *temp = *stack;
		*stack = (*stack)->next;
		free(temp);
		return (value);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
}
