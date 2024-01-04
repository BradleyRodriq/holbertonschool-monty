#include "monty.h"

/**
 * pint - Prints the value at the top of the stack, followed by a new line
 * @stack: Pointer to the top of the stack
 */
void pint(Stack *stack)
{
    if (stack == NULL)
    {
        fprintf(stderr, "Error: can't pint, stack is NULL\n");
        exit(EXIT_FAILURE);
    }
    else if (stack->next == NULL)
    {
        fprintf(stderr, "Error: can't pint, stack empty\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("%d\n", stack->next->n);
    }
}
