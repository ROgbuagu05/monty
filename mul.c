#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * _mul - Multiplies the second top node of the
 * stack with the top node of the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;
	(*stack) = (*stack)->next;
	free(*stack);
}
