#include "monty.h"

/**
 * pop - Pops a value from the stack.
 * @stack: Pointer to the stack.
 * Return: The value popped from the stack.
 */
int pop(Stack *stack)
{
    if (stack != NULL && stack->next != NULL)
    {
        int value = stack->n;
        Stack *temp = stack;
        stack = stack->next;
        free(temp);
        return value;
    }
    else
    {
        fprintf(stderr, "Error: Can't pop an empty stack\n");
        exit(EXIT_FAILURE);
    }
}
