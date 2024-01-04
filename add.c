#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty file.
 */
void add(Stack **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(*stack);
}
