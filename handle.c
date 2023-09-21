#include "monty.h"


/**
 * getIntFromPush - Extracts an integer from a string with 'myPush' opcode
 * @str: The string containing the file content
 * @line_number: Line number
 * Return: The extracted integer
 */
int getIntFromPush(char *str, int line_number)
{
	char *opcode = "push";

	while (*str != '\0')
	{
		if (*opcode == *str)
		{
			opcode++;
			str++;
			if (*opcode == '\0')
				while (*str)
				{
					if ((*str >= '0' && *str <= '9') || *str == '-')
					{
						findNonNumbers(str, line_number);
						return atoi(str);
					}
					else if (*str == ' ')
						str++;
					else
					{
						fprintf(stderr, "L%d: Usage: push integer :))\n", lineNum);
						exit(EXIT_FAILURE);
					}
				}
		}
		else
			str++;
	}
	return (0);
}

/**
 * findNonNumbers - Finds non-numbers and number combinations in a string
 * @str: The string to search
 * @line_number: Line number
 * Return: 1
 */
int findNonNumbers(char *str, int line_number)
{
	int i = 1;

	while (str[i])
	{
		if (str[i] == '\0' || str[i] == '\n')
			break;
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
			i++;
		else
		{
			fprintf(stderr, "L%d: Usage: push integer:))\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}


/**
 * findNewline - Finds a newline character in a string
 * @str: The string to search for '\n'
 * Return: 1 if newline found, otherwise returns 0
 */
int findNewline(char *str)
{
	char *newline = "\n";

	while (*str != '\0')
	{
		if (*newline == *str)
		{
			newline++;
			str++;
			if (*newline == '\0')
				return 1;
		}
		else
			str++;
	}
	return (0);
}
