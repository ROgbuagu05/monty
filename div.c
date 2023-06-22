#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * _div - divides the second top node of the
 * stack by the top node of the stack.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = result;
	(*stack) = (*stack)->next;
	free(*stack);
}
