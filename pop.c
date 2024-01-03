#include "main.h"

/**
 * pop - Pops a value from the stack
 *
 * Return: The value popped from the stack
 */

int pop(void)
{
    if (stack_t.sp >= 0)
    {
        return stack_t.array[stack_t.sp--];
    }
    else
    {
        fprintf(stderr, "Error: Can't pop an empty stack\n");
        exit(EXIT_FAILURE);
    }
}
