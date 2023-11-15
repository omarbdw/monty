#include "monty.h"

int execute(char *lineContent, stack_t *stack, int counter, FILE *file)
{
    char *operation;
    instruction_t opDic[] = {
        {"pall", pallFunc}
    };
    operation = strtok(lineContent, delim);
    while (operation)
    {
        if (strcmp(opDic[i].op) == 0)
        {

        }
    }
    


}