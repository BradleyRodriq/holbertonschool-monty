#include "monty.h"

/**
 * pint - Prints the value athe the top of the stack, followed by a new line
 */

void pint()
{
    if (sp >= 0) {
        printf("%d\n", stack[sp]);
    } else {
        fprintf(stderr, "Error: can't pint, stack empty\n");
        exit(EXIT_FAILURE);
    }
}
