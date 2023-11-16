#include "monty.h"
void pintFunc(stack_t **stackHead, unsigned int counter)
{
    stack_t *stack;
    stack = *stackHead;
    if (stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", counter);
        fclose(global.file);
        free(global.lineContent);
        exit(FAILURE);
    }
    printf("%d\n", stack->n);
}
