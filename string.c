#include "monty.h"

/**
 * compareStrings - Compares two strings
 * @str1: First string to be compared
 * @str2: Second string to be compared
 * Return: 0 if the strings are equal, otherwise returns 1
 */
int compareStrings(char *str1, char *str2)
{
	while (*str2 != '\0')
	{
		if (*str2 == ' ')
			str2++;
		else if (*str1 == *str2)
		{
			str1++;
			str2++;
			if (*str1 == '\0' && (*str2 == ' ' || *str2 == '\n' || *str2 == '\0'))
				return (1);
		}
		else
			return (0);
	}
	return (0);
}
