#include <stdio.h>
#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number of the opcode in the file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void) line_number;

	if (stack == NULL)
	{
		printf("\n");
		return;
	}
	while (current && current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
