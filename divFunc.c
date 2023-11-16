#include "monty.h"
void divFunc(stack_t **stackHead, unsigned int counter)
{
    stack_t *stack;
    int i = 0;
    stack = *stackHead;
    while (stack)
    {
        i++;
        stack = stack->next;
    }
    stack = *stackHead;
    if (i < 1)
    {
        fprintf(stderr, "L<%d>: can't div, stack too short", counter);
        free(global.lineContent);
        fclose(global.file);
        while (stack)
        {
            free(stack);
            stack = stack->next;
        }
        exit(FAILURE);
    }
    stack = *stackHead;
    stack->next->n = (stack->next->n / stack->n);
    *stackHead = stack->next;
    free(stack);
}
