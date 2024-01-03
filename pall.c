#include "monty.h"
#include <stdio.h>

void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    stack_t *current = *stack;
    while(current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}