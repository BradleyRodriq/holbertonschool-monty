#include "monty.h"
#include <stdio.h>
#include <string.h>

/**
 * pall - prints all the values on the stack
 * @stack: the top of the stack
 * @line_number: the line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	stack_t *current = *stack;
	int size = 0;

	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	if (size == 0)
	{
		return;
	}
	current = *stack;
	
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
