#include "monty.h"
/**
 * divFunc - Divides the second top element of the stack by the top element of
 * the stack.
 * @stackHead: Double pointer to the head of the stack.
 * @counter: The line number currently being run from the script file.
 */
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
if (stack->n == 0)
{
fprintf(stderr, "L<%d>: can't div, division by zero", counter);
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
