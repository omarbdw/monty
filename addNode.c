#include "monty.h"

/**
 * addNode - Adds a new node at the beginning of a stack_t list.
 * @head: A pointer to the head of the stack_t list.
 * @value: The value to be added to the new node.
 */
void addNode(stack_t **head, int value)
{
stack_t *newNode;
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
