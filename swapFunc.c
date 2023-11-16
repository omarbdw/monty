#include "monty.h"
void swapFunc(stack_t **stackHead, unsigned int counter)
{
    stack_t *stack;
    int i = -1;
    int addN;
    stack = *stackHead;

    while (stack)
    {
        stack = stack->next;
        i++;
    }

    if (i < 1)
    {
        fprintf(stderr, "L<%d>: can't swap, stack too short", counter);
        free(global.lineContent);
        fclose(global.file);
        free(stack);

        exit(FAILURE);
    }
    stack = *stackHead;
    addN = stack->n;
    stack->n = stack->next->n;
    stack->next->n = addN;

}