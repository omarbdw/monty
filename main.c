
#include "monty.h"
char *delim = " \n\t";

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
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
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	while (lineRead > 0)
	{
		lineContent = NULL;
		readLine = getline(&lineContent, lineSize, file);
		if (readLine > 0)
		{
			execute(lineContent, &stack, counter, file);
		}
	}
    fclose(file);
	return(SUCCESS);
}