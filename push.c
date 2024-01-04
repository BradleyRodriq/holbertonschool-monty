#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
* push - pushes an element to the stack
* @stack: a pointer to the first element
* @value: the value to be added
*/

void push(stack_t **stack, int value, unsigned int line_number)
{
    if (!isdigit(value))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
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
