#include "monty.h"
/**
 * pallFunc - prints all the values on the stack,
 * starting from the top
 * @stackHead: double pointer to the head of the stack
 * @counter: line number of the opcode being executed
 */
void pallFunc(stack_t **stackHead, __attribute__((unused))\
unsigned int counter)
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
