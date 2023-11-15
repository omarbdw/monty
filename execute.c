#include "monty.h"

int execute(char *lineContent, stack_t **stack, int counter, FILE *file)
{
    char *operation;
    int i = 0;
    instruction_t opDic[] = {
        {"pall", pallFunc}};
    operation = strtok(lineContent, delim);
    while (operation)
    {
        if (strcmp(opDic[i].opcode, operation) == 0)
        {
            opDic[i].f(stack, counter);
            return (SUCCESS);
            i++;
        }
    }

    if (operation == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, operation);
        fclose(file);
        free(lineContent);
        /* TODO: Free Stack */
        exit(EXIT_FAILURE);
    }

    return (SUCCESS);
}