#include "monty.h"

#define STACK_SIZE 100


int stack[STACK_SIZE];
int sp = -1;


void push(int value) {
    if (sp < STACK_SIZE - 1) {
        stack[++sp] = value;
    } else {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}


int pop() {
    if (sp >= 0) {
        return stack[sp--];
    } else {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}


void pint()
{
    if (sp >= 0) {
        printf("%d\n", stack[sp]);
    } else {
        fprintf(stderr, "Error: can't pint, stack empty\n");
        exit(EXIT_FAILURE);
    }
}

int main()
{

    push(42);
    pint();

    sp = -1;
    pint();

    return 0;
}
