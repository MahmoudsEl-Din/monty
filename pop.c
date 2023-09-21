#include "monty.h"

/**
 * pop - Removes
 * @stack: pointer 
 * @line_number:line number
 * Return: func
 */

void myPop(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: Unable to pop, stack is empty!\n", line_number);
		exit(EXIT_FAILURE);
	}


	if (head)
	{
		*stack = (head)->next;
		free(head);
	}
}
