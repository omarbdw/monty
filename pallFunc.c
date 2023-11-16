#include "monty.h"
void pallFunc(stack_t **stackHead, __attribute__((unused)) unsigned int counter)
{
    stack_t *stack;
    stack = *stackHead;
    if (stack == NULL)
        return;

    while (stack)
    {
        printf("%d\n", stack->n);
        stack = stack->next;
    }
}
