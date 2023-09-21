#include "monty.h"

/**
 * mySwap - Swaps
 * @stack: pointer 
 * @line_number: line number
 * Return: func
 */
void mySwap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *temp;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: Unable to swap, stack is too short!!\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (head && head->next)
	{
		temp = h->next;
		if (temp->next)
			temp->next->prev = head;
		head->next = temp->next;
		temp->prev = NULL;
		temp->next = head;
		head->prev = temp;
		*stack = temp;
	}
}

