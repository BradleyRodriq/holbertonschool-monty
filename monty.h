#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct StackNode - Structure for a stack node
 * @data: Integer data of the node
 * @next: Pointer to the next node in the stack
 */
typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode;

/**
 * push - Pushes a value onto the stack
 * @top: Pointer to the top of the stack
 * @value: Value to be pushed onto the stack
 */
void push(StackNode **top, int value);

/**
 * pint - Prints the value at the top of the stack
 * @top: Pointer to the top of the stack
 * @line_number: Line number in the file
 */
void pint(StackNode *top, unsigned int line_number);

#endif

