#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void push(stack_t **stack, int value, unsigned int line_number)
{
    char str_value[20];
    int i;

    sprintf(str_value, "%d", value);

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
