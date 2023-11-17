#include "monty.h"

/**
 * popFunc - Removes the top element of the stack.
 * @stackHead: Double pointer to the head of the stack.
 * @counter: The line number currently being executed.
 */
void popFunc(stack_t **stackHead, unsigned int counter)
{
stack_t *stack;
stack = *stackHead;
if (stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
fclose(global.file);
free(global.lineContent);
freeStack(stackHead);
exit(FAILURE);
}
*stackHead = stack->next;
free(stack);
}
