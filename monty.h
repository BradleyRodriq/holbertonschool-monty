#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct Stack - Structure to represent the stack.
 * @n: The integer value stored in the stack node.
 * @next: Pointer to the next node in the stack.
 */
typedef struct Stack {
    int n;
    struct Stack *next;
} Stack;

/**
 * initializeStack - Initializes the stack.
 * @stack: Pointer to the stack to be initialized.
 */
void initializeStack(Stack *stack);

/**
 * pop - Pops a value from the stack.
 * @stack: Pointer to the stack.
 * Return: The value popped from the stack.
 */
int pop(Stack *stack);

/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: Pointer to the top of the stack.
 */
void pint(Stack *stack);

/**
 * swap - Swap the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty file.
 */
void swap(Stack **stack, unsigned int line_number);

#endif
