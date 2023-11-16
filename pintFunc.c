#include "monty.h"
/**
 * pintFunc - Prints the value at the top of the stack, followed by a new line.
 *
 * @stackHead: Double pointer to the head of the stack.
 * @counter: The line number currently being executed in the Monty file.
 */
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
