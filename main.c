
#include "monty.h"
global_t global = {NULL, NULL, NULL};
/**
 * main - The main function of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: The exit status of the program.
 */
int main(int argc, char *argv[])
{
FILE *file;
int readLine = 1;
size_t lineSize = 0;
stack_t *stack = NULL;
int counter = 0;
char *lineContent;
if (argc == 1)
{
fprintf(stderr, "USAGE: monty file\n");
exit(FAILURE);
}
file = fopen(argv[1], "r");
global.file = file;
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(FAILURE);
}
while (readLine > 0)
{
lineContent = NULL;
readLine = getline(&lineContent, &lineSize, file);
global.lineContent = lineContent;
counter++;
if (readLine > 0)
{
execute(lineContent, &stack, counter, file);
}
free(lineContent);
}
while (stack)
{
stack = stack->next;
free(stack);
}
fclose(file);
return (SUCCESS);
}
