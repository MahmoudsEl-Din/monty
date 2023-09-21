#include "monty.h"


/**
 * myPint - Prints values
 * @stack: pointer
 * @line_number: line number
 * Return: func
 */
void myPint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: Unable to print, stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);

}
