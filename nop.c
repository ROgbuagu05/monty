#include <stdio.h>
#include "monty.h"
/**
 * nop - this does nothing for Monty
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
