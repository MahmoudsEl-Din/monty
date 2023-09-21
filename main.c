#include "monty.h"

/**
 * main - Monty interpreter
 * @argc: The number of arguments
 * @argv: The arguments
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	static char *lines[1000] = {NULL};
	int lineCount = 0;
	FILE *file;
	size_t bufferSize = 1000;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file :)\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file :(( %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (lineCount = 0; getline(&lines[lineCount], &bufferSize, file) > 0; lineCount++);

	executeOpCodes(lines, stack);

	for (int i = 0; i < lineCount; i++)
		free(lines[i]);

	fclose(file);
	return (0);
}
