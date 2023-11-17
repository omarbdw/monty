#include "monty.h"
/**
 * pushFunc - Adds a new node at the beginning of a stack_t list.
 * @head: A pointer to the head of the stack_t list.
 * @counter: The line number currently being executed.
 */
void pushFunc(stack_t **head, unsigned int counter)
{
char *valueArg = global.valueArg;
int j = 0, error = 0, value;
if (valueArg)
{
for (j = 0; valueArg[j] != '\0'; j++)
{
if (valueArg[j] == '-' || valueArg[j] == '+')
			j++;
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
addNode(head, value);
}
