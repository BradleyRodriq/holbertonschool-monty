#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty file.
 */

void swap(Stack **stack, unsigned int line_number)
{
    int temp;
    Stack *current = *stack;

    if (current == NULL || current->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = current->n;
    current->n = current->next->n;
    current->next->n = temp;
}
