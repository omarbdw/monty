#include "monty.h"

int execute(char *lineContent, stack_t **stack, int counter, FILE *file)
{

    instruction_t opDict[] = {
        {"pall", pallFunc}, {"push", pushFunc}, {NULL, NULL}};
    char *delim = " \n\t";
    char *operation;
    unsigned int i = 0;
    int check;

    operation = strtok(lineContent, delim);
    if (operation && operation[0] == '#')
        return (SUCCESS);
    global.valueArg = strtok(NULL, delim);

    while (opDict[i].opcode && operation)
    {

        check = strcmp(operation, opDict[i].opcode);
        if (check == 0)
        {
            opDict[i].f(stack, counter);
            return (SUCCESS);
        }
        i++;
    }

    if (opDict[i].opcode && operation == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, operation);
        fclose(file);
        free(lineContent);
        /* TODO: Free Stack */
        exit(FAILURE);
    }

    return (SUCCESS);
}