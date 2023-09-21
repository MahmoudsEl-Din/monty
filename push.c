#include "monty.h"

/**
 * myPush - Pushes the element to the stack
 * @stack: just a pointer
 * @line_number: line number
 * @n: just a int
 * Return: address
 */

void myPush(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *newNode, *head = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: Pushing an integer is required", line_number);
		exit(EXIT_FAILURE);
	}
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		exit(EXIT_FAILURE);
	newNode->prev = NULL;
	newNode->n = n;
	newNode->next = *stack;
	if (*stack)
		head->prev = newNode;
	*stack = newNode;
}

