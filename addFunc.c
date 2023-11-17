#include "monty.h"
/**
 * addFunc - Adds the top two elements of the stack.
 * @stackHead: Double pointer to the head of the stack.
 * @counter: The line number currently being executed.
 */
void addFunc(stack_t **stackHead, unsigned int counter)
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
fprintf(stderr, "L<%d>: can't add, stack too short", counter);
free(global.lineContent);
fclose(global.file);
freeStack(stackHead);
exit(FAILURE);
}
stack = *stackHead;
stack->next->n = (stack->n + stack->next->n);
*stackHead = stack->next;
free(stack);
}
