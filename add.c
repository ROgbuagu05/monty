#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * _add - Adds the top two nodes of the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	(*stack) = (*stack)->next;
	free(*stack);
}
