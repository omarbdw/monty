#include "monty.h"
void freeStack(stack_t **head)
{
stack_t *temp;
while (*head)
{
temp = *head;
*head = (*head)->next;
free(temp);
}
}
