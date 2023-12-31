#include "monty.h"
/**
 * mulFunc - Multiplies the second top element of the stack with the top element
 * @stackHead: Double pointer to the head of the stack
 * @counter: The line number currently being executed
 */
void mulFunc(stack_t **stackHead, unsigned int counter)
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
fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
free(global.lineContent);
fclose(global.file);
while (stack)
{
free(stack);
stack = stack->next;
}
exit(EXIT_FAILURE);
}
stack = *stackHead;
stack->next->n = (stack->next->n * stack->n);
*stackHead = stack->next;
free(stack);
}
