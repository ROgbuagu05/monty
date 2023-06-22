#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * _sub - Subtracts the top node of the stack from
 * the second top node
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the file.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;
	(*stack) = (*stack)->next;
	free(*stack);
}
