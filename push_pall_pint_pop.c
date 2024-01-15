#include "monty.h"

/**
 * push - adds an element to the stack
 * @stack: pointer to the first element in the stack
 * @value: the value to add
 * @line_number: the number of lines
 */
void push(stack_t **stack, int value, unsigned int line_number)
{
	char str_value[20];
	int i;
	stack_t *new_node = malloc(sizeof(stack_t));

		if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		exit(EXIT_FAILURE);
	}
	snprintf(str_value, sizeof(str_value), "%d", value);

	for (i = 0; str_value[i]; i++)
	{
		if (i == 0 && str_value[i] == '-')
		{
			if (str_value[i + 1] == '\0' || !isdigit(str_value[i + 1]))
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
		}
		else if (!isdigit(str_value[i]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: the top of the stack
 * @line_number: the line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int size = 0;

	(void) line_number;

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

/**
 * pop - Pops a value from the stack.
 * @stack: Pointer to the stack.
 * @line_number: the number of the line
 * Return: The value popped from the stack.
 */
int pop(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack != NULL)
	{
		value = (*stack)->n;
		stack_t *temp = *stack;
		*stack = (*stack)->next;
		free(temp);
		return (value);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
