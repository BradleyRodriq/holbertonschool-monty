#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/**
 * struct stack_t - Stack structure
 * @array: The array representing the stack
 * @sp: The stack pointer pointing to the top of the stack
 */
typedef struct stack_t
{
	int array[STACK_SIZE];
	int sp;
} stack_t;



/**
 * push - Pushes a value onto the stack
 * @value: The value to be pushed onto the stack
 */
void push(int value);

/**
 * pop - Pops a value from the stack
 *
 * Return: The value popped from the stack
 */
int pop(void);

/**
 * pint - Prints the value at the top of the stack, followed by a new line
 * If the stack is empty, prints an error message and exits with EXIT_FAILURE
 */
void pint(void);

#endif

