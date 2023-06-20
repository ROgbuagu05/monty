#include <stdio.h>
#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: Pointer to the head of stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
