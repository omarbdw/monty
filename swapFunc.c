#include "monty.h"
/**
 * swapFunc - Swaps the top two elements of the stack.
 *
 * @stackHead: Double pointer to the head of the stack.
 * @counter: The line number currently being executed.
 */
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
fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
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
