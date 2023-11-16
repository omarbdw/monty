#include "monty.h"

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
    if (operation && operation[0] == '#')
        return (SUCCESS);
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