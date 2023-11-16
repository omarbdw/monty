
#include "monty.h"


/**
 * The main function of the program.
 * 
 * @param argc The number of command-line arguments.
 * @param argv An array of strings containing the command-line arguments.
 * 
 * @return The exit status of the program.
 */

global_t global = {NULL, NULL, NULL};

int main(int argc, char *argv[])
{
	
	FILE *file;
	int lineRead = 1;
	size_t readLine = 0;
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

	while (lineRead > 0)
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