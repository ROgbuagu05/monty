#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * pchar - Prints the char at the top of the stack,
 * followed by a new line.
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number of the opcode in the file
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}
