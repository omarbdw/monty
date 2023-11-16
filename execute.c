#include "monty.h"

/**
 * execute - Executes the opcode passed as argument.
 *
 * @lineContent: The opcode to execute.
 * @stack: A pointer to the top of the stack.
 * @counter: The line number being executed.
 * @file: The file being read from.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute(char *lineContent, stack_t **stack, int counter, FILE *file)
{
instruction_t opDict[] = {
{"pall", pallFunc}, {"push", pushFunc},
{"pint", pintFunc}, {"pop", popFunc},
{"swap", swapFunc}, {"add", addFunc},
{"nop", nopFunc}, {"sub", subFunc},
{NULL, NULL}};
char *delim = " \n\t";
char *operation;
unsigned int i = 0;
operation = strtok(lineContent, delim);
global.valueArg = strtok(NULL, delim);
while (opDict[i].opcode && operation)
{
if ((strcmp(operation, opDict[i].opcode)) == 0)
{
opDict[i].f(stack, counter);
return (SUCCESS);
}
i++;
}

if (operation && opDict[i].opcode == NULL)
{
fprintf(stderr, "L%d: unknown instruction %s\n", counter, operation);
fclose(file);
free(lineContent);
while (*stack)
{
*stack = (*stack)->next;
free(*stack);
}
exit(FAILURE);
}

return (FAILURE);
}
