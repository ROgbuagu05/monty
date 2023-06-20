#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * pop - removes the top element of the stack.
 * @stack: Double pointer to head of the stack
 * @line_number: Current line number in the Monty file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;

	if (*stack != NULL)
		(*stack)->prev = NULL;
}
