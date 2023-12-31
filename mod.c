#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * mod - Computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int i, j;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	i = (*stack)->n;
	j = (*stack)->next->n;

	if (i == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = j % i;
	(*stack) = (*stack)->next;
	free(*stack);
}
