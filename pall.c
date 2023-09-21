#include "monty.h"

/**
 * myPall - Print
 * @stack: pointer
 * @line_number: line number
 * Return: func
 */

void myPall(stack_t **stack, unsigned int line_number)
{
	stack_t *head  = *stack;
	(void)line_number;

	while (head)
	{
		printf("%d\n", head ->n);
		head  = head ->next;
	}
}
