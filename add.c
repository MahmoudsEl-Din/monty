#include "monty.h"

/**
 * myAdd - Adds
 * @stack: pointer 
 * @line_number: line number
 * Return: func
 */
void myAdd(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *nextNoden;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: Unable to add, stack is too short!!\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (*stack && (*stack)->next)
	{
		nextNode = head->next;
		nextNode->n += head->n;
		free(head);
		*stack = nextNode;
	}
}
