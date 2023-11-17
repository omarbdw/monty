#include "monty.h"
/**
 * subFunc - Description of what the function does
 *
 * @stackHead: Description of parameter stackHead
 * @counter: Description of parameter counter
 *
 * Return: Description of the return value
 */
void subFunc(stack_t **stackHead, unsigned int counter)
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
fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
free(global.lineContent);
fclose(global.file);
freeStack(stackHead);
exit(FAILURE);
}
stack = *stackHead;
stack->next->n = (stack->next->n - stack->n);
*stackHead = stack->next;
free(stack);
}
