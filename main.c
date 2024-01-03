#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(void)
{
    stack_t *stack = NULL;
    char *opcodes[] = {"push 1", "push 2", "push 3", "pall", NULL};
    unsigned int line_number = 1;


    for (int i = 0; opcodes[i] != NULL; i++)
    {
        char opcode[256];
        int value;
        if (sscanf(opcodes[i], "%s %d", opcode, &value) == 2)
        {
            if (strcmp(opcode, "push") == 0)
                push(&stack, value);
        }
        else
        {
            if (strcmp(opcode, "pall") == 0)
                pall(&stack, line_number);
        }
        line_number++;
    }

    return (0);
}