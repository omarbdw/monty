#include "monty.h"
void pushFunc(stack_t **head, unsigned int counter)
{
    stack_t *newNode;
    int value;
    char *valueArg = global.valueArg;
    int j = 0;
    int error = 0;

    if (valueArg)
    {
        if (valueArg[0] == '-')
            j++;
        for (; valueArg[j] != '\0'; j++)
        {
            if (valueArg[j] > 57 || valueArg[j] < 48)
                error = 1;
        }
        if (error == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(global.file);
            free(global.lineContent);
            while (*head)
            {
                *head = (*head)->next;
                free(*head);
            }
            exit(FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(global.file);
        free(global.lineContent);
        exit(FAILURE);
    }

    value = atoi(valueArg);
    newNode = malloc(sizeof(stack_t));
    if (newNode == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(FAILURE);
    }
    newNode->n = value;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}