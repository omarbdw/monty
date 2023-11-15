#include "monty.h"
void pallFunc(stack_t **stackHead, unsigned int counter)
{
    stack_t *stack;
    stack = *stackHead;
    (void)counter;
    if (!stack)
    {
        printf("Stack is empty");
    }
    else
    {
        while (stack)
        {
            printf("%d\n", stack->n);
            stack = stack->next;
        }
        
    }
}
